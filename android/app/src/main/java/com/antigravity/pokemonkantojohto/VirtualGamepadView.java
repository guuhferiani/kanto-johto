package com.antigravity.pokemonkantojohto;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.os.Build;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.view.MotionEvent;
import android.view.View;

public class VirtualGamepadView extends View {

    private final Vibrator vibrator;
    private final GBAView gbaView;

    private int activeKeyMask = 0;
    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);

    // Button boundaries
    private final RectF dpadBounds = new RectF();
    private final RectF btnABounds = new RectF();
    private final RectF btnBBounds = new RectF();
    private final RectF btnLBounds = new RectF();
    private final RectF btnRBounds = new RectF();
    private final RectF btnSelectBounds = new RectF();
    private final RectF btnStartBounds = new RectF();
    private final RectF btnSpeedBounds = new RectF();
    private final RectF btnSaveBounds = new RectF();

    public VirtualGamepadView(Context context, GBAView gbaView) {
        super(context);
        this.gbaView = gbaView;
        vibrator = (Vibrator) context.getSystemService(Context.VIBRATOR_SERVICE);

        textPaint.setColor(Color.WHITE);
        textPaint.setTextAlign(Paint.Align.CENTER);
        textPaint.setFakeBoldText(true);
    }

    private void vibrate() {
        if (vibrator != null) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                vibrator.vibrate(VibrationEffect.createOneShot(15, VibrationEffect.DEFAULT_AMPLITUDE));
            } else {
                vibrator.vibrate(15);
            }
        }
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);

        float padAreaTop = h * 0.52f;
        float padAreaHeight = h - padAreaTop;

        // D-Pad on bottom-left
        float dpadRadius = Math.min(w * 0.22f, padAreaHeight * 0.35f);
        float dpadCenterX = w * 0.25f;
        float dpadCenterY = padAreaTop + (padAreaHeight * 0.52f);
        dpadBounds.set(dpadCenterX - dpadRadius, dpadCenterY - dpadRadius, dpadCenterX + dpadRadius, dpadCenterY + dpadRadius);

        // A and B Buttons on bottom-right
        float btnRadius = Math.min(w * 0.11f, padAreaHeight * 0.18f);
        float btnAY = padAreaTop + (padAreaHeight * 0.45f);
        float btnAX = w * 0.85f;
        btnABounds.set(btnAX - btnRadius, btnAY - btnRadius, btnAX + btnRadius, btnAY + btnRadius);

        float btnBY = btnAY + (btnRadius * 1.35f);
        float btnBX = btnAX - (btnRadius * 1.55f);
        btnBBounds.set(btnBX - btnRadius, btnBY - btnRadius, btnBX + btnRadius, btnBY + btnRadius);

        // L and R Triggers at the upper sides
        float lrHeight = padAreaHeight * 0.14f;
        float lrWidth = w * 0.22f;
        float lrY = padAreaTop + 10;
        btnLBounds.set(w * 0.06f, lrY, w * 0.06f + lrWidth, lrY + lrHeight);
        btnRBounds.set(w * 0.94f - lrWidth, lrY, w * 0.94f, lrY + lrHeight);

        // Select and Start in lower middle
        float ssWidth = w * 0.18f;
        float ssHeight = padAreaHeight * 0.10f;
        float ssY = padAreaTop + (padAreaHeight * 0.82f);
        float ssCenterX = w * 0.5f;
        btnSelectBounds.set(ssCenterX - ssWidth - 10, ssY, ssCenterX - 10, ssY + ssHeight);
        btnStartBounds.set(ssCenterX + 10, ssY, ssCenterX + ssWidth + 10, ssY + ssHeight);

        // Speed and Save in upper middle
        float topBtnWidth = w * 0.16f;
        float topBtnHeight = padAreaHeight * 0.10f;
        btnSpeedBounds.set(ssCenterX - topBtnWidth - 8, lrY, ssCenterX - 8, lrY + topBtnHeight);
        btnSaveBounds.set(ssCenterX + 8, lrY, ssCenterX + topBtnWidth + 8, lrY + topBtnHeight);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        // Draw L and R Triggers
        drawButton(canvas, btnLBounds, "L", (activeKeyMask & (1 << GBAEngine.KEY_L)) != 0, 0x44607D8B);
        drawButton(canvas, btnRBounds, "R", (activeKeyMask & (1 << GBAEngine.KEY_R)) != 0, 0x44607D8B);

        // Draw Quick Tools (Speed & Save)
        String speedText = gbaView != null ? gbaView.getSpeedMultiplier() + "x" : "1x";
        drawButton(canvas, btnSpeedBounds, "⚡ " + speedText, false, 0x55FF9800);
        drawButton(canvas, btnSaveBounds, "💾 Salvar", false, 0x554CAF50);

        // Draw D-Pad
        drawDpad(canvas);

        // Draw A and B
        drawRoundButton(canvas, btnBBounds, "B", (activeKeyMask & (1 << GBAEngine.KEY_B)) != 0, 0xDDCC3333);
        drawRoundButton(canvas, btnABounds, "A", (activeKeyMask & (1 << GBAEngine.KEY_A)) != 0, 0xDDCC3333);

        // Draw Select and Start
        drawButton(canvas, btnSelectBounds, "SELECT", (activeKeyMask & (1 << GBAEngine.KEY_SELECT)) != 0, 0x5578909C);
        drawButton(canvas, btnStartBounds, "START", (activeKeyMask & (1 << GBAEngine.KEY_START)) != 0, 0x5578909C);
    }

    private void drawButton(Canvas canvas, RectF r, String label, boolean pressed, int color) {
        paint.setColor(pressed ? Color.argb(180, 255, 255, 255) : color);
        canvas.drawRoundRect(r, 12, 12, paint);
        textPaint.setTextSize(r.height() * 0.42f);
        canvas.drawText(label, r.centerX(), r.centerY() + (textPaint.getTextSize() * 0.35f), textPaint);
    }

    private void drawRoundButton(Canvas canvas, RectF r, String label, boolean pressed, int color) {
        paint.setColor(pressed ? Color.argb(220, 255, 200, 200) : color);
        canvas.drawCircle(r.centerX(), r.centerY(), r.width() / 2, paint);
        textPaint.setTextSize(r.height() * 0.48f);
        canvas.drawText(label, r.centerX(), r.centerY() + (textPaint.getTextSize() * 0.35f), textPaint);
    }

    private void drawDpad(Canvas canvas) {
        paint.setColor(0x5537474F);
        float cx = dpadBounds.centerX();
        float cy = dpadBounds.centerY();
        float w = dpadBounds.width();
        float armWidth = w * 0.34f;
        float armLength = w * 0.5f;

        // Horizontal cross
        canvas.drawRoundRect(new RectF(cx - armLength, cy - (armWidth / 2), cx + armLength, cy + (armWidth / 2)), 8, 8, paint);
        // Vertical cross
        canvas.drawRoundRect(new RectF(cx - (armWidth / 2), cy - armLength, cx + (armWidth / 2), cy + armLength), 8, 8, paint);

        // Active highlights
        paint.setColor(0x88FFFFFF);
        if ((activeKeyMask & (1 << GBAEngine.KEY_UP)) != 0)
            canvas.drawRect(new RectF(cx - (armWidth / 2), cy - armLength, cx + (armWidth / 2), cy - (armWidth / 2)), paint);
        if ((activeKeyMask & (1 << GBAEngine.KEY_DOWN)) != 0)
            canvas.drawRect(new RectF(cx - (armWidth / 2), cy + (armWidth / 2), cx + (armWidth / 2), cy + armLength), paint);
        if ((activeKeyMask & (1 << GBAEngine.KEY_LEFT)) != 0)
            canvas.drawRect(new RectF(cx - armLength, cy - (armWidth / 2), cx - (armWidth / 2), cy + (armWidth / 2)), paint);
        if ((activeKeyMask & (1 << GBAEngine.KEY_RIGHT)) != 0)
            canvas.drawRect(new RectF(cx + (armWidth / 2), cy - (armWidth / 2), cx + armLength, cy + (armWidth / 2)), paint);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int pointerCount = event.getPointerCount();
        int newKeyMask = 0;
        int action = event.getActionMasked();

        if (action != MotionEvent.ACTION_UP && action != MotionEvent.ACTION_CANCEL) {
            for (int i = 0; i < pointerCount; i++) {
                if (action == MotionEvent.ACTION_POINTER_UP && i == event.getActionIndex())
                    continue;

                float x = event.getX(i);
                float y = event.getY(i);

                // D-Pad
                if (dpadBounds.contains(x, y)) {
                    float dx = x - dpadBounds.centerX();
                    float dy = y - dpadBounds.centerY();
                    float deadzone = dpadBounds.width() * 0.12f;

                    if (dy < -deadzone) newKeyMask |= (1 << GBAEngine.KEY_UP);
                    if (dy > deadzone) newKeyMask |= (1 << GBAEngine.KEY_DOWN);
                    if (dx < -deadzone) newKeyMask |= (1 << GBAEngine.KEY_LEFT);
                    if (dx > deadzone) newKeyMask |= (1 << GBAEngine.KEY_RIGHT);
                }

                // A and B
                if (btnABounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_A);
                if (btnBBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_B);

                // L and R
                if (btnLBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_L);
                if (btnRBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_R);

                // Start and Select
                if (btnSelectBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_SELECT);
                if (btnStartBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_START);

                // Speed toggle (click only on down)
                if (action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_POINTER_DOWN) {
                    if (btnSpeedBounds.contains(x, y) && gbaView != null) {
                        gbaView.cycleSpeed();
                        vibrate();
                    }
                    if (btnSaveBounds.contains(x, y)) {
                        GBAEngine.nativeSave();
                        vibrate();
                    }
                }
            }
        }

        if (newKeyMask != activeKeyMask) {
            if ((newKeyMask & ~activeKeyMask) != 0) {
                vibrate();
            }
            activeKeyMask = newKeyMask;
            GBAEngine.nativeSetKeys(activeKeyMask);
            invalidate();
        }

        return true;
    }
}
