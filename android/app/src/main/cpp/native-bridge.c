#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <android/log.h>
#include "libretro.h"

#define LOG_TAG "GBA-Native"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define GBA_WIDTH  240
#define GBA_HEIGHT 160

// Dynamic libretro function pointers
typedef void (*retro_init_t)(void);
typedef void (*retro_deinit_t)(void);
typedef void (*retro_set_environment_t)(retro_environment_t);
typedef void (*retro_set_video_refresh_t)(retro_video_refresh_t);
typedef void (*retro_set_audio_sample_t)(retro_audio_sample_t);
typedef void (*retro_set_audio_sample_batch_t)(retro_audio_sample_batch_t);
typedef void (*retro_set_input_poll_t)(retro_input_poll_t);
typedef void (*retro_set_input_state_t)(retro_input_state_t);
typedef bool (*retro_load_game_t)(const struct retro_game_info *);
typedef void (*retro_unload_game_t)(void);
typedef void (*retro_get_system_av_info_t)(struct retro_system_av_info *);
typedef void (*retro_run_t)(void);
typedef void *(*retro_get_memory_data_t)(unsigned);
typedef size_t (*retro_get_memory_size_t)(unsigned);

static void *sCoreHandle = NULL;
static retro_init_t p_retro_init = NULL;
static retro_deinit_t p_retro_deinit = NULL;
static retro_set_environment_t p_retro_set_environment = NULL;
static retro_set_video_refresh_t p_retro_set_video_refresh = NULL;
static retro_set_audio_sample_t p_retro_set_audio_sample = NULL;
static retro_set_audio_sample_batch_t p_retro_set_audio_sample_batch = NULL;
static retro_set_input_poll_t p_retro_set_input_poll = NULL;
static retro_set_input_state_t p_retro_set_input_state = NULL;
static retro_load_game_t p_retro_load_game = NULL;
static retro_unload_game_t p_retro_unload_game = NULL;
static retro_get_system_av_info_t p_retro_get_system_av_info = NULL;
static retro_run_t p_retro_run = NULL;
static retro_get_memory_data_t p_retro_get_memory_data = NULL;
static retro_get_memory_size_t p_retro_get_memory_size = NULL;

// Global engine state
static uint32_t sVideoBuffer[GBA_WIDTH * GBA_HEIGHT];
static int16_t sAudioBuffer[4096 * 2];
static size_t sAudioBufferCount = 0;
static uint32_t sKeyMask = 0;
static char sSavePath[1024] = {0};
static enum retro_pixel_format sPixelFormat = RETRO_PIXEL_FORMAT_0RGB1555;
static double sSampleRate = 32768.0;
static bool sInitialized = false;

// Libretro callbacks
static void video_refresh_callback(const void *data, unsigned width, unsigned height, size_t pitch)
{
    if (!data) return;

    if (sPixelFormat == RETRO_PIXEL_FORMAT_XRGB8888)
    {
        const uint32_t *src = (const uint32_t *)data;
        size_t src_stride = pitch / sizeof(uint32_t);
        for (unsigned y = 0; y < height && y < GBA_HEIGHT; y++)
        {
            for (unsigned x = 0; x < width && x < GBA_WIDTH; x++)
            {
                sVideoBuffer[y * GBA_WIDTH + x] = 0xFF000000 | src[y * src_stride + x];
            }
        }
    }
    else if (sPixelFormat == RETRO_PIXEL_FORMAT_RGB565)
    {
        const uint16_t *src = (const uint16_t *)data;
        size_t src_stride = pitch / sizeof(uint16_t);
        for (unsigned y = 0; y < height && y < GBA_HEIGHT; y++)
        {
            for (unsigned x = 0; x < width && x < GBA_WIDTH; x++)
            {
                uint16_t c = src[y * src_stride + x];
                uint32_t r = ((c >> 11) & 0x1F) * 255 / 31;
                uint32_t g = ((c >> 5) & 0x3F) * 255 / 63;
                uint32_t b = (c & 0x1F) * 255 / 31;
                sVideoBuffer[y * GBA_WIDTH + x] = 0xFF000000 | (r << 16) | (g << 8) | b;
            }
        }
    }
    else // RETRO_PIXEL_FORMAT_0RGB1555
    {
        const uint16_t *src = (const uint16_t *)data;
        size_t src_stride = pitch / sizeof(uint16_t);
        for (unsigned y = 0; y < height && y < GBA_HEIGHT; y++)
        {
            for (unsigned x = 0; x < width && x < GBA_WIDTH; x++)
            {
                uint16_t c = src[y * src_stride + x];
                uint32_t r = ((c >> 10) & 0x1F) * 255 / 31;
                uint32_t g = ((c >> 5) & 0x1F) * 255 / 31;
                uint32_t b = (c & 0x1F) * 255 / 31;
                sVideoBuffer[y * GBA_WIDTH + x] = 0xFF000000 | (r << 16) | (g << 8) | b;
            }
        }
    }
}

static void audio_sample_callback(int16_t left, int16_t right)
{
    if (sAudioBufferCount + 2 <= sizeof(sAudioBuffer) / sizeof(sAudioBuffer[0]))
    {
        sAudioBuffer[sAudioBufferCount++] = left;
        sAudioBuffer[sAudioBufferCount++] = right;
    }
}

static size_t audio_sample_batch_callback(const int16_t *data, size_t frames)
{
    size_t samples = frames * 2;
    size_t maxSamples = sizeof(sAudioBuffer) / sizeof(sAudioBuffer[0]) - sAudioBufferCount;
    if (samples > maxSamples)
        samples = maxSamples;

    memcpy(&sAudioBuffer[sAudioBufferCount], data, samples * sizeof(int16_t));
    sAudioBufferCount += samples;
    return frames;
}

static void input_poll_callback(void)
{
}

static int16_t input_state_callback(unsigned port, unsigned device, unsigned index, unsigned id)
{
    if (port == 0 && device == RETRO_DEVICE_JOYPAD)
    {
        if (sKeyMask & (1 << id))
            return 1;
    }
    return 0;
}

static bool environment_callback(unsigned cmd, void *data)
{
    switch (cmd)
    {
        case RETRO_ENVIRONMENT_SET_PIXEL_FORMAT:
        {
            const enum retro_pixel_format *fmt = (const enum retro_pixel_format *)data;
            if (*fmt == RETRO_PIXEL_FORMAT_RGB565 || *fmt == RETRO_PIXEL_FORMAT_XRGB8888 || *fmt == RETRO_PIXEL_FORMAT_0RGB1555)
            {
                sPixelFormat = *fmt;
                return true;
            }
            return false;
        }
        case RETRO_ENVIRONMENT_GET_CAN_DUPE:
            *(bool *)data = true;
            return true;
        case RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY:
        case RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY:
            *(const char **)data = "/data/data/com.antigravity.pokemonkantojohto/files";
            return true;
        default:
            return false;
    }
}

static void load_sram(void)
{
    if (!p_retro_get_memory_data || !p_retro_get_memory_size) return;
    void *sram = p_retro_get_memory_data(RETRO_MEMORY_SAVE_RAM);
    size_t sram_size = p_retro_get_memory_size(RETRO_MEMORY_SAVE_RAM);
    if (!sram || sram_size == 0 || sSavePath[0] == '\0')
        return;

    FILE *f = fopen(sSavePath, "rb");
    if (f)
    {
        fread(sram, 1, sram_size, f);
        fclose(f);
        LOGI("Save file loaded from %s (size %zu)", sSavePath, sram_size);
    }
}

static void save_sram(void)
{
    if (!p_retro_get_memory_data || !p_retro_get_memory_size) return;
    void *sram = p_retro_get_memory_data(RETRO_MEMORY_SAVE_RAM);
    size_t sram_size = p_retro_get_memory_size(RETRO_MEMORY_SAVE_RAM);
    if (!sram || sram_size == 0 || sSavePath[0] == '\0')
        return;

    FILE *f = fopen(sSavePath, "wb");
    if (f)
    {
        fwrite(sram, 1, sram_size, f);
        fclose(f);
        LOGI("Save file saved to %s (size %zu)", sSavePath, sram_size);
    }
}

// JNI exports
JNIEXPORT jstring JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeInit(JNIEnv *env, jclass clazz, jbyteArray romBytes, jstring savePath, jstring nativeLibDir)
{
    if (sInitialized)
    {
        save_sram();
        if (p_retro_unload_game) p_retro_unload_game();
        if (p_retro_deinit) p_retro_deinit();
        sInitialized = false;
    }

    if (savePath)
    {
        const char *path = (*env)->GetStringUTFChars(env, savePath, NULL);
        strncpy(sSavePath, path, sizeof(sSavePath) - 1);
        (*env)->ReleaseStringUTFChars(env, savePath, path);
    }

    // 1. Dynamically load libmgba_libretro.so via dlopen
    if (!sCoreHandle)
    {
        char candidate_path[1024] = {0};
        if (nativeLibDir)
        {
            const char *dir = (*env)->GetStringUTFChars(env, nativeLibDir, NULL);
            snprintf(candidate_path, sizeof(candidate_path), "%s/libmgba_libretro.so", dir);
            (*env)->ReleaseStringUTFChars(env, nativeLibDir, dir);
            sCoreHandle = dlopen(candidate_path, RTLD_NOW);
            LOGI("dlopen candidate '%s' result: %p", candidate_path, sCoreHandle);
        }

        if (!sCoreHandle)
        {
            sCoreHandle = dlopen("libmgba_libretro.so", RTLD_NOW);
            LOGI("dlopen default 'libmgba_libretro.so' result: %p", sCoreHandle);
        }

        if (!sCoreHandle)
        {
            const char *err = dlerror();
            LOGE("Failed to dlopen libmgba_libretro.so: %s", err ? err : "unknown error");
            char msg[512];
            snprintf(msg, sizeof(msg), "dlopen falhou ao carregar libmgba_libretro.so: %s", err ? err : "não encontrado");
            return (*env)->NewStringUTF(env, msg);
        }

        #define LOAD_SYM(name) \
            p_##name = (name##_t)dlsym(sCoreHandle, #name); \
            if (!p_##name) { \
                char err_buf[256]; \
                snprintf(err_buf, sizeof(err_buf), "Simbolo nao encontrado no core: %s", #name); \
                return (*env)->NewStringUTF(env, err_buf); \
            }

        LOAD_SYM(retro_init);
        LOAD_SYM(retro_deinit);
        LOAD_SYM(retro_set_environment);
        LOAD_SYM(retro_set_video_refresh);
        LOAD_SYM(retro_set_audio_sample);
        LOAD_SYM(retro_set_audio_sample_batch);
        LOAD_SYM(retro_set_input_poll);
        LOAD_SYM(retro_set_input_state);
        LOAD_SYM(retro_load_game);
        LOAD_SYM(retro_unload_game);
        LOAD_SYM(retro_get_system_av_info);
        LOAD_SYM(retro_run);
        LOAD_SYM(retro_get_memory_data);
        LOAD_SYM(retro_get_memory_size);
        #undef LOAD_SYM
    }

    p_retro_set_environment(environment_callback);
    p_retro_set_video_refresh(video_refresh_callback);
    p_retro_set_audio_sample(audio_sample_callback);
    p_retro_set_audio_sample_batch(audio_sample_batch_callback);
    p_retro_set_input_poll(input_poll_callback);
    p_retro_set_input_state(input_state_callback);

    p_retro_init();

    jsize rom_len = (*env)->GetArrayLength(env, romBytes);
    jbyte *rom_data = (*env)->GetByteArrayElements(env, romBytes, NULL);

    struct retro_game_info game_info = {
        .path = "Pokemon_Kanto_Johto.gba",
        .data = rom_data,
        .size = (size_t)rom_len,
        .meta = ""
    };

    bool loaded = p_retro_load_game(&game_info);
    (*env)->ReleaseByteArrayElements(env, romBytes, rom_data, JNI_ABORT);

    if (!loaded)
    {
        LOGE("Failed to load ROM via retro_load_game!");
        p_retro_deinit();
        return (*env)->NewStringUTF(env, "retro_load_game falhou ao inicializar a ROM.");
    }

    struct retro_system_av_info av_info;
    p_retro_get_system_av_info(&av_info);
    sSampleRate = av_info.timing.sample_rate;
    LOGI("mGBA initialized successfully! Target FPS: %f, Sample Rate: %f", av_info.timing.fps, sSampleRate);

    load_sram();
    sInitialized = true;
    return NULL; // Success!
}

JNIEXPORT void JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeSetKeys(JNIEnv *env, jclass clazz, jint keyMask)
{
    sKeyMask = (uint32_t)keyMask;
}

JNIEXPORT jint JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeStepFrame(JNIEnv *env, jclass clazz, jintArray videoBuffer, jshortArray audioBuffer)
{
    if (!sInitialized || !p_retro_run) return 0;

    sAudioBufferCount = 0;
    p_retro_run();

    if (videoBuffer)
    {
        (*env)->SetIntArrayRegion(env, videoBuffer, 0, GBA_WIDTH * GBA_HEIGHT, (const jint *)sVideoBuffer);
    }

    if (audioBuffer && sAudioBufferCount > 0)
    {
        jsize maxLen = (*env)->GetArrayLength(env, audioBuffer);
        jsize toCopy = (jsize)sAudioBufferCount;
        if (toCopy > maxLen) toCopy = maxLen;
        (*env)->SetShortArrayRegion(env, audioBuffer, 0, toCopy, (const jshort *)sAudioBuffer);
        return toCopy;
    }

    return 0;
}

JNIEXPORT void JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeSave(JNIEnv *env, jclass clazz)
{
    if (sInitialized)
    {
        save_sram();
    }
}

JNIEXPORT void JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeDestroy(JNIEnv *env, jclass clazz)
{
    if (sInitialized)
    {
        save_sram();
        if (p_retro_unload_game) p_retro_unload_game();
        if (p_retro_deinit) p_retro_deinit();
        sInitialized = false;
        LOGI("mGBA unloaded cleanly.");
    }
}

JNIEXPORT jint JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeGetSampleRate(JNIEnv *env, jclass clazz)
{
    return (jint)sSampleRate;
}
