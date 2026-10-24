package com.antigravity.pokemonkantojohto;

public class GBAEngine {

    public static final int KEY_B      = 0;
    public static final int KEY_Y      = 1;
    public static final int KEY_SELECT = 2;
    public static final int KEY_START  = 3;
    public static final int KEY_UP     = 4;
    public static final int KEY_DOWN   = 5;
    public static final int KEY_LEFT   = 6;
    public static final int KEY_RIGHT  = 7;
    public static final int KEY_A      = 8;
    public static final int KEY_X      = 9;
    public static final int KEY_L      = 10;
    public static final int KEY_R      = 11;

    static {
        System.loadLibrary("gba-native");
    }

    public static native String nativeInit(byte[] romBytes, String savePath, String nativeLibDir);
    public static native void nativeSetKeys(int keyMask);
    public static native int nativeStepFrame(int[] videoBuffer, short[] audioBuffer);
    public static native void nativeSave();
    public static native void nativeDestroy();
    public static native int nativeGetSampleRate();
}
