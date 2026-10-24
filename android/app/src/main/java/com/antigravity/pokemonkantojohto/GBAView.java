package com.antigravity.pokemonkantojohto;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class GBAView extends SurfaceView implements SurfaceHolder.Callback, Runnable {

    public static final int GBA_WIDTH = 240;
    public static final int GBA_HEIGHT = 160;

    private final SurfaceHolder holder;
    private Thread renderThread = null;
    private volatile boolean isRunning = false;

    private final Bitmap frameBitmap;
    private final int[] videoBuffer = new int[GBA_WIDTH * GBA_HEIGHT];
    private final short[] audioBuffer = new short[4096];
    private AudioTrack audioTrack;

    private final Rect srcRect = new Rect(0, 0, GBA_WIDTH, GBA_HEIGHT);
    private final Rect dstRect = new Rect();
    private final Paint paint = new Paint();

    private volatile int speedMultiplier = 1; // 1x, 2x, 4x

    public GBAView(Context context) {
        super(context);
        holder = getHolder();
        holder.addCallback(this);
        frameBitmap = Bitmap.createBitmap(GBA_WIDTH, GBA_HEIGHT, Bitmap.Config.ARGB_8888);
        paint.setFilterBitmap(false); // Nearest-neighbor for crisp pixel art
    }

    public void setSpeedMultiplier(int speed) {
        this.speedMultiplier = Math.max(1, Math.min(speed, 4));
    }

    public int getSpeedMultiplier() {
        return speedMultiplier;
    }

    public void cycleSpeed() {
        if (speedMultiplier == 1) speedMultiplier = 2;
        else if (speedMultiplier == 2) speedMultiplier = 4;
        else speedMultiplier = 1;
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        int sampleRate = GBAEngine.nativeGetSampleRate();
        if (sampleRate <= 0) sampleRate = 32768;

        try {
            int minBufferSize = AudioTrack.getMinBufferSize(
                    sampleRate,
                    AudioFormat.CHANNEL_OUT_STEREO,
                    AudioFormat.ENCODING_PCM_16BIT
            );

            if (minBufferSize <= 0) {
                sampleRate = 44100;
                minBufferSize = AudioTrack.getMinBufferSize(
                        sampleRate,
                        AudioFormat.CHANNEL_OUT_STEREO,
                        AudioFormat.ENCODING_PCM_16BIT
                );
            }

            audioTrack = new AudioTrack(
                    AudioManager.STREAM_MUSIC,
                    sampleRate,
                    AudioFormat.CHANNEL_OUT_STEREO,
                    AudioFormat.ENCODING_PCM_16BIT,
                    Math.max(minBufferSize, 4096 * 4),
                    AudioTrack.MODE_STREAM
            );
            audioTrack.play();
        } catch (Throwable t) {
            android.util.Log.e("GBAView", "AudioTrack failed to initialize: " + t.getMessage(), t);
            audioTrack = null;
        }

        isRunning = true;
        renderThread = new Thread(this, "GBA-RenderThread");
        renderThread.setPriority(Thread.MAX_PRIORITY);
        renderThread.start();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        // Calculate 3:2 aspect ratio viewport placed in upper portion of screen (above touch controls)
        int gameAreaHeight = (int) (height * 0.52f);
        int targetWidth = width;
        int targetHeight = (width * GBA_HEIGHT) / GBA_WIDTH;

        if (targetHeight > gameAreaHeight) {
            targetHeight = gameAreaHeight;
            targetWidth = (gameAreaHeight * GBA_WIDTH) / GBA_HEIGHT;
        }

        int left = (width - targetWidth) / 2;
        int top = 20; // Slight top margin
        dstRect.set(left, top, left + targetWidth, top + targetHeight);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        isRunning = false;
        if (renderThread != null) {
            try {
                renderThread.join();
            } catch (InterruptedException ignored) {}
            renderThread = null;
        }
        if (audioTrack != null) {
            try {
                audioTrack.stop();
                audioTrack.release();
            } catch (Exception ignored) {}
            audioTrack = null;
        }
    }

    @Override
    public void run() {
        long frameIntervalNs = 16666667L; // ~60 FPS (16.66ms per frame)

        while (isRunning) {
            long startTime = System.nanoTime();

            int framesToStep = speedMultiplier;
            for (int f = 0; f < framesToStep; f++) {
                int samples = GBAEngine.nativeStepFrame(videoBuffer, audioBuffer);
                if (audioTrack != null && samples > 0 && f == 0) {
                    audioTrack.write(audioBuffer, 0, samples);
                }
            }

            frameBitmap.setPixels(videoBuffer, 0, GBA_WIDTH, 0, 0, GBA_WIDTH, GBA_HEIGHT);

            Canvas canvas = null;
            try {
                canvas = holder.lockCanvas();
                if (canvas != null) {
                    canvas.drawColor(Color.BLACK);
                    canvas.drawBitmap(frameBitmap, srcRect, dstRect, paint);
                }
            } finally {
                if (canvas != null) {
                    holder.unlockCanvasAndPost(canvas);
                }
            }

            long elapsedNs = System.nanoTime() - startTime;
            long sleepNs = (frameIntervalNs / speedMultiplier) - elapsedNs;
            if (sleepNs > 1000000L) { // > 1ms
                try {
                    Thread.sleep(sleepNs / 1000000L, (int) (sleepNs % 1000000L));
                } catch (InterruptedException ignored) {}
            }
        }
    }
}
