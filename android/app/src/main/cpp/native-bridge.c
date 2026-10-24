#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <android/log.h>
#include "libretro.h"

#define LOG_TAG "GBA-Native"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define GBA_WIDTH  240
#define GBA_HEIGHT 160

// Global state
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
    // Polled via sKeyMask updated from Java
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
    void *sram = retro_get_memory_data(RETRO_MEMORY_SAVE_RAM);
    size_t sram_size = retro_get_memory_size(RETRO_MEMORY_SAVE_RAM);
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
    void *sram = retro_get_memory_data(RETRO_MEMORY_SAVE_RAM);
    size_t sram_size = retro_get_memory_size(RETRO_MEMORY_SAVE_RAM);
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
JNIEXPORT jboolean JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeInit(JNIEnv *env, jclass clazz, jbyteArray romBytes, jstring savePath)
{
    if (sInitialized)
    {
        save_sram();
        retro_unload_game();
        retro_deinit();
        sInitialized = false;
    }

    if (savePath)
    {
        const char *path = (*env)->GetStringUTFChars(env, savePath, NULL);
        strncpy(sSavePath, path, sizeof(sSavePath) - 1);
        (*env)->ReleaseStringUTFChars(env, savePath, path);
    }

    retro_set_environment(environment_callback);
    retro_set_video_refresh(video_refresh_callback);
    retro_set_audio_sample(audio_sample_callback);
    retro_set_audio_sample_batch(audio_sample_batch_callback);
    retro_set_input_poll(input_poll_callback);
    retro_set_input_state(input_state_callback);

    retro_init();

    jsize rom_len = (*env)->GetArrayLength(env, romBytes);
    jbyte *rom_data = (*env)->GetByteArrayElements(env, romBytes, NULL);

    struct retro_game_info game_info = {
        .path = "Pokemon_Kanto_Johto.gba",
        .data = rom_data,
        .size = (size_t)rom_len,
        .meta = ""
    };

    bool loaded = retro_load_game(&game_info);
    (*env)->ReleaseByteArrayElements(env, romBytes, rom_data, JNI_ABORT);

    if (!loaded)
    {
        LOGE("Failed to load ROM via retro_load_game!");
        retro_deinit();
        return JNI_FALSE;
    }

    struct retro_system_av_info av_info;
    retro_get_system_av_info(&av_info);
    sSampleRate = av_info.timing.sample_rate;
    LOGI("mGBA initialized successfully! Target FPS: %f, Sample Rate: %f", av_info.timing.fps, sSampleRate);

    load_sram();
    sInitialized = true;
    return JNI_TRUE;
}

JNIEXPORT void JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeSetKeys(JNIEnv *env, jclass clazz, jint keyMask)
{
    sKeyMask = (uint32_t)keyMask;
}

JNIEXPORT jint JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeStepFrame(JNIEnv *env, jclass clazz, jintArray videoBuffer, jshortArray audioBuffer)
{
    if (!sInitialized) return 0;

    sAudioBufferCount = 0;
    retro_run();

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
        retro_unload_game();
        retro_deinit();
        sInitialized = false;
        LOGI("mGBA unloaded cleanly.");
    }
}

JNIEXPORT jint JNICALL
Java_com_antigravity_pokemonkantojohto_GBAEngine_nativeGetSampleRate(JNIEnv *env, jclass clazz)
{
    return (jint)sSampleRate;
}
