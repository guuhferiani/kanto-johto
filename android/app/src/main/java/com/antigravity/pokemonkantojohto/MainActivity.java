package com.antigravity.pokemonkantojohto;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.FrameLayout;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.InputStream;

public class MainActivity extends Activity {

    private GBAView gbaView;
    private VirtualGamepadView gamepadView;
    private int hardwareKeyMask = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        try {
            requestWindowFeature(Window.FEATURE_NO_TITLE);
            getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
            getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
            setImmersiveMode();

            // 1. Load ROM from internal assets
            byte[] romBytes = loadRomFromAssets();
            if (romBytes == null || romBytes.length == 0) {
                Toast.makeText(this, "Erro: Arquivo do jogo não encontrado!", Toast.LENGTH_LONG).show();
                finish();
                return;
            }

            // 2. Setup internal save path
            File saveFile = new File(getFilesDir(), "Pokemon_Kanto_Johto.sav");
            String savePath = saveFile.getAbsolutePath();
            String nativeLibDir = getApplicationInfo().nativeLibraryDir;

            // 3. Initialize native mGBA engine
            String initError = GBAEngine.nativeInit(romBytes, savePath, nativeLibDir);
            if (initError != null) {
                new android.app.AlertDialog.Builder(this)
                        .setTitle("Erro")
                        .setMessage("Falha ao iniciar motor nativo:\n" + initError)
                        .setPositiveButton("Fechar", (dialog, which) -> finish())
                        .setCancelable(false)
                        .show();
                return;
            }

            // 4. Setup Native UI layout
            FrameLayout rootLayout = new FrameLayout(this);
            rootLayout.setBackgroundColor(0xFF000000);

            gbaView = new GBAView(this);
            gamepadView = new VirtualGamepadView(this, gbaView);

            rootLayout.addView(gbaView, new FrameLayout.LayoutParams(
                    FrameLayout.LayoutParams.MATCH_PARENT,
                    FrameLayout.LayoutParams.MATCH_PARENT
            ));

            rootLayout.addView(gamepadView, new FrameLayout.LayoutParams(
                    FrameLayout.LayoutParams.MATCH_PARENT,
                    FrameLayout.LayoutParams.MATCH_PARENT
            ));

            setContentView(rootLayout);
        } catch (Throwable t) {
            android.util.Log.e("MainActivity", "Fatal initialization error: " + t.getMessage(), t);
            new android.app.AlertDialog.Builder(this)
                    .setTitle("Erro")
                    .setMessage("Não foi possível iniciar o jogo:\n" + t.toString())
                    .setPositiveButton("Fechar", (dialog, which) -> finish())
                    .setCancelable(false)
                    .show();
        }
    }

    private byte[] loadRomFromAssets() {
        try {
            InputStream is = getAssets().open("game.gba");
            int size = is.available();
            byte[] buffer = new byte[size];
            int offset = 0;
            while (offset < size) {
                int read = is.read(buffer, offset, size - offset);
                if (read <= 0) break;
                offset += read;
            }
            is.close();
            return buffer;
        } catch (Exception e) {
            android.util.Log.e("MainActivity", "Error reading ROM asset: " + e.getMessage(), e);
            return null;
        }
    }

    private void setImmersiveMode() {
        View decorView = getWindow().getDecorView();
        decorView.setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                        | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                        | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                        | View.SYSTEM_UI_FLAG_FULLSCREEN
                        | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
        );
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            setImmersiveMode();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        GBAEngine.nativeSave();
    }

    @Override
    protected void onStop() {
        super.onStop();
        GBAEngine.nativeSave();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        GBAEngine.nativeDestroy();
    }

    // Hardware Gamepad support (Bluetooth / USB controllers)
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        int keyBit = translateKeyCode(keyCode);
        if (keyBit >= 0) {
            hardwareKeyMask |= (1 << keyBit);
            GBAEngine.nativeSetKeys(hardwareKeyMask);
            return true;
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
        int keyBit = translateKeyCode(keyCode);
        if (keyBit >= 0) {
            hardwareKeyMask &= ~(1 << keyBit);
            GBAEngine.nativeSetKeys(hardwareKeyMask);
            return true;
        }
        return super.onKeyUp(keyCode, event);
    }

    private int translateKeyCode(int keyCode) {
        switch (keyCode) {
            case KeyEvent.KEYCODE_DPAD_UP: return GBAEngine.KEY_UP;
            case KeyEvent.KEYCODE_DPAD_DOWN: return GBAEngine.KEY_DOWN;
            case KeyEvent.KEYCODE_DPAD_LEFT: return GBAEngine.KEY_LEFT;
            case KeyEvent.KEYCODE_DPAD_RIGHT: return GBAEngine.KEY_RIGHT;
            case KeyEvent.KEYCODE_BUTTON_A:
            case KeyEvent.KEYCODE_Z: return GBAEngine.KEY_A;
            case KeyEvent.KEYCODE_BUTTON_B:
            case KeyEvent.KEYCODE_X: return GBAEngine.KEY_B;
            case KeyEvent.KEYCODE_BUTTON_START:
            case KeyEvent.KEYCODE_ENTER: return GBAEngine.KEY_START;
            case KeyEvent.KEYCODE_BUTTON_SELECT:
            case KeyEvent.KEYCODE_SHIFT_LEFT: return GBAEngine.KEY_SELECT;
            case KeyEvent.KEYCODE_BUTTON_L1: return GBAEngine.KEY_L;
            case KeyEvent.KEYCODE_BUTTON_R1: return GBAEngine.KEY_R;
            default: return -1;
        }
    }
}
