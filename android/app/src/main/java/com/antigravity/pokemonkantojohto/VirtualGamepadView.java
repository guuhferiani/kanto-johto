package com.antigravity.pokemonkantojohto;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.LinearGradient;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RadialGradient;
import android.graphics.Rect;
import android.graphics.RectF;
import android.graphics.Shader;
import android.os.Build;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.view.MotionEvent;
import android.view.View;

/**
 * VirtualGamepadView - Pizza Boy Off-White / Light Gray Console Edition
 * Designed for edge-to-edge vertical handheld gaming with authentic 3D tactile controls.
 */
public class VirtualGamepadView extends View {

    private final Vibrator vibrator;
    private final GBAView gbaView;

    private int activeKeyMask = 0;
    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint textPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint shadowPaint = new Paint(Paint.ANTI_ALIAS_FLAG);

    // Dynamic layout anchors
    private int screenBottom = 0;
    private final RectF chassisRect = new RectF();

    // Button touch boundaries
    private final RectF dpadBounds = new RectF();
    private final RectF btnABounds = new RectF();
    private final RectF btnBBounds = new RectF();
    private final RectF btnLBounds = new RectF();
    private final RectF btnRBounds = new RectF();
    private final RectF btnSelectBounds = new RectF();
    private final RectF btnStartBounds = new RectF();
    private final RectF btnSpeedBounds = new RectF();
    private final RectF btnSaveBounds = new RectF();
    private final RectF abTrayBounds = new RectF();

    public VirtualGamepadView(Context context, GBAView gbaView) {
        super(context);
        this.gbaView = gbaView;
        this.vibrator = (Vibrator) context.getSystemService(Context.VIBRATOR_SERVICE);

        textPaint.setTextAlign(Paint.Align.CENTER);
        textPaint.setFakeBoldText(true);

        shadowPaint.setStyle(Paint.Style.FILL);

        // Listen for GBA viewport calculation to place console body seamlessly
        if (gbaView != null) {
            gbaView.setOnViewportChangedListener(viewport -> {
                if (viewport != null && viewport.bottom > 0) {
                    screenBottom = viewport.bottom;
                    recalculateLayout(getWidth(), getHeight());
                    invalidate();
                }
            });
        }
    }

    private void vibrate() {
        if (vibrator != null) {
            try {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                    vibrator.vibrate(VibrationEffect.createOneShot(18, VibrationEffect.DEFAULT_AMPLITUDE));
                } else {
                    vibrator.vibrate(18);
                }
            } catch (Exception ignored) {}
        }
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
        if (gbaView != null && gbaView.getDstRect() != null && gbaView.getDstRect().bottom > 0) {
            screenBottom = gbaView.getDstRect().bottom;
        } else if (screenBottom <= 0) {
            screenBottom = (int) (w * 160f / 240f);
        }
        recalculateLayout(w, h);
    }

    private void recalculateLayout(int w, int h) {
        if (w <= 0 || h <= 0) return;

        float padTop = Math.max(screenBottom, (int) (w * 160f / 240f));
        chassisRect.set(0, padTop, w, h);
        float padHeight = h - padTop;

        // Top Utility Toolbar (Power LED, Brand, Speed, Save)
        float topBarY = padTop + (padHeight * 0.035f);
        float topBarBtnH = Math.min(padHeight * 0.08f, 75f);
        float topBarBtnW = w * 0.22f;

        btnSpeedBounds.set(w * 0.50f, topBarY, w * 0.50f + topBarBtnW, topBarY + topBarBtnH);
        btnSaveBounds.set(w * 0.74f, topBarY, w * 0.74f + topBarBtnW, topBarY + topBarBtnH);

        // L and R Triggers at sides of upper chassis
        float lrY = topBarY + topBarBtnH + (padHeight * 0.02f);
        float lrW = w * 0.24f;
        float lrH = Math.min(padHeight * 0.10f, 90f);
        btnLBounds.set(w * 0.05f, lrY, w * 0.05f + lrW, lrY + lrH);
        btnRBounds.set(w * 0.95f - lrW, lrY, w * 0.95f, lrY + lrH);

        // D-Pad on Left side
        float dpadCenterY = padTop + (padHeight * 0.50f);
        float dpadCenterX = w * 0.26f;
        float dpadRadius = Math.min(w * 0.20f, padHeight * 0.21f);
        dpadBounds.set(dpadCenterX - dpadRadius, dpadCenterY - dpadRadius, dpadCenterX + dpadRadius, dpadCenterY + dpadRadius);

        // A / B Action Buttons on Right side (Classic GBA Diagonal)
        float btnRadius = Math.min(w * 0.105f, padHeight * 0.11f);
        float btnAY = padTop + (padHeight * 0.44f);
        float btnAX = w * 0.83f;
        btnABounds.set(btnAX - btnRadius, btnAY - btnRadius, btnAX + btnRadius, btnAY + btnRadius);

        float btnBY = btnAY + (btnRadius * 1.35f);
        float btnBX = btnAX - (btnRadius * 1.55f);
        btnBBounds.set(btnBX - btnRadius, btnBY - btnRadius, btnBX + btnRadius, btnBY + btnRadius);

        // Angled tray behind A/B buttons
        abTrayBounds.set(btnBX - (btnRadius * 1.3f), btnAY - (btnRadius * 1.25f), btnAX + (btnRadius * 1.3f), btnBY + (btnRadius * 1.25f));

        // Select and Start in lower middle
        float ssW = w * 0.18f;
        float ssH = Math.min(padHeight * 0.06f, 50f);
        float ssY = padTop + (padHeight * 0.80f);
        float ssCenterX = w * 0.46f;
        btnSelectBounds.set(ssCenterX - ssW - 12, ssY, ssCenterX - 12, ssY + ssH);
        btnStartBounds.set(ssCenterX + 12, ssY, ssCenterX + ssW + 12, ssY + ssH);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        if (chassisRect.height() <= 0) return;

        // 1. Draw Pizza Boy Off-White Chassis Body
        drawChassis(canvas);

        // 2. Draw Top Toolbar: Power LED, Brand Title, Speed, Save
        drawTopToolbar(canvas);

        // 3. Draw L and R Triggers
        drawShoulderButton(canvas, btnLBounds, "L", (activeKeyMask & (1 << GBAEngine.KEY_L)) != 0);
        drawShoulderButton(canvas, btnRBounds, "R", (activeKeyMask & (1 << GBAEngine.KEY_R)) != 0);

        // 4. Draw D-Pad
        draw3DDpad(canvas);

        // 5. Draw A and B Buttons (in angled tray)
        drawABSection(canvas);

        // 6. Draw Select and Start Pills
        drawSelectStart(canvas);

        // 7. Draw Speaker Grille
        drawSpeakerGrille(canvas);
    }

    private void drawChassis(Canvas canvas) {
        float left = chassisRect.left;
        float top = chassisRect.top;
        float right = chassisRect.right;
        float bottom = chassisRect.bottom;

        // Chassis gradient (light silver off-white)
        LinearGradient grad = new LinearGradient(
                0, top, 0, bottom,
                new int[]{0xFFF2F5F7, 0xFFE9EDF0, 0xFFDFE4E7},
                new float[]{0.0f, 0.5f, 1.0f},
                Shader.TileMode.CLAMP
        );
        paint.setStyle(Paint.Style.FILL);
        paint.setShader(grad);
        canvas.drawRect(chassisRect, paint);
        paint.setShader(null);

        // Dark bezel separator at the top edge
        paint.setColor(0xFF263238);
        canvas.drawRect(left, top - 2, right, top + 2, paint);

        // Inner drop shadow right under the screen bezel
        shadowPaint.setColor(0x30000000);
        canvas.drawRect(left, top + 2, right, top + 8, shadowPaint);
    }

    private void drawTopToolbar(Canvas canvas) {
        float topY = chassisRect.top + (chassisRect.height() * 0.035f);

        // Green Power LED
        float ledX = chassisRect.width() * 0.08f;
        float ledY = topY + 22f;

        // Outer glow
        paint.setColor(0x3300E676);
        canvas.drawCircle(ledX, ledY, 14f, paint);

        // Solid LED
        paint.setColor(0xFF00E676);
        canvas.drawCircle(ledX, ledY, 6f, paint);

        // Center bright highlight
        paint.setColor(0xFFB9F6CA);
        canvas.drawCircle(ledX - 1.5f, ledY - 1.5f, 2.5f, paint);

        // "POWER" label
        textPaint.setColor(0xFF78909C);
        textPaint.setTextSize(18f);
        canvas.drawText("POWER", ledX, ledY + 26f, textPaint);

        // Brand Title "KANTO & JOHTO"
        textPaint.setColor(0xFF90A4AE);
        textPaint.setTextSize(26f);
        canvas.drawText("KANTO & JOHTO", chassisRect.width() * 0.30f, topY + 26f, textPaint);

        // Speed Pill Button
        String speedLabel = gbaView != null ? "⚡ " + gbaView.getSpeedMultiplier() + "x" : "⚡ 1x";
        drawPillButton(canvas, btnSpeedBounds, speedLabel, false, 0xFFECEFF1, 0xFF37474F);

        // Save Pill Button
        drawPillButton(canvas, btnSaveBounds, "💾 Salvar", false, 0xFFECEFF1, 0xFF2E7D32);
    }

    private void drawPillButton(Canvas canvas, RectF r, String label, boolean pressed, int bgColor, int textColor) {
        // Drop shadow
        shadowPaint.setColor(0x22000000);
        canvas.drawRoundRect(new RectF(r.left, r.top + 3, r.right, r.bottom + 3), 16, 16, shadowPaint);

        // Button body
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(pressed ? 0xFFCFD8DC : bgColor);
        canvas.drawRoundRect(r, 16, 16, paint);

        // Subtle stroke
        paint.setStyle(Paint.Style.STROKE);
        paint.setColor(0xFFB0BEC5);
        paint.setStrokeWidth(2f);
        canvas.drawRoundRect(r, 16, 16, paint);
        paint.setStyle(Paint.Style.FILL);

        // Label
        textPaint.setColor(textColor);
        textPaint.setTextSize(r.height() * 0.40f);
        canvas.drawText(label, r.centerX(), r.centerY() + (textPaint.getTextSize() * 0.35f), textPaint);
    }

    private void drawShoulderButton(Canvas canvas, RectF r, String label, boolean pressed) {
        // Drop shadow
        shadowPaint.setColor(0x30000000);
        canvas.drawRoundRect(new RectF(r.left, r.top + 4, r.right, r.bottom + 4), 18, 18, shadowPaint);

        // 3D Metallic Trigger Gradient
        int topCol = pressed ? 0xFF90A4AE : 0xFFCFD8DC;
        int botCol = pressed ? 0xFF78909C : 0xFFB0BEC5;
        LinearGradient grad = new LinearGradient(
                r.left, r.top, r.left, r.bottom,
                new int[]{topCol, botCol},
                null,
                Shader.TileMode.CLAMP
        );
        paint.setShader(grad);
        canvas.drawRoundRect(r, 18, 18, paint);
        paint.setShader(null);

        // Top edge bevel highlight
        paint.setColor(0x60FFFFFF);
        paint.setStrokeWidth(3f);
        paint.setStyle(Paint.Style.STROKE);
        canvas.drawRoundRect(new RectF(r.left + 2, r.top + 2, r.right - 2, r.bottom - 2), 16, 16, paint);
        paint.setStyle(Paint.Style.FILL);

        // Text
        textPaint.setColor(pressed ? 0xFFECEFF1 : 0xFF37474F);
        textPaint.setTextSize(r.height() * 0.45f);
        canvas.drawText(label, r.centerX(), r.centerY() + (textPaint.getTextSize() * 0.35f), textPaint);
    }

    private void draw3DDpad(Canvas canvas) {
        float cx = dpadBounds.centerX();
        float cy = dpadBounds.centerY();
        float w = dpadBounds.width();
        float armW = w * 0.34f;
        float armL = w * 0.50f;

        // Outer circular bezel indentation in chassis
        paint.setColor(0xFFD3D9DE);
        canvas.drawCircle(cx, cy, armL + 10f, paint);

        // Drop shadow
        shadowPaint.setColor(0x40000000);
        canvas.drawRoundRect(new RectF(cx - armL, cy - (armW / 2) + 6, cx + armL, cy + (armW / 2) + 6), 12, 12, shadowPaint);
        canvas.drawRoundRect(new RectF(cx - (armW / 2), cy - armL + 6, cx + (armW / 2), cy + armL + 6), 12, 12, shadowPaint);

        // Matte charcoal body
        paint.setColor(0xFF2C3238);
        canvas.drawRoundRect(new RectF(cx - armL, cy - (armW / 2), cx + armL, cy + (armW / 2)), 12, 12, paint);
        canvas.drawRoundRect(new RectF(cx - (armW / 2), cy - armL, cx + (armW / 2), cy + armL), 12, 12, paint);

        // Center circular concave depression
        paint.setColor(0xFF24282D);
        canvas.drawCircle(cx, cy, armW * 0.52f, paint);

        // Subtle center dot
        paint.setColor(0xFF1E2226);
        canvas.drawCircle(cx, cy, armW * 0.18f, paint);

        // 3D Bevel highlight (top edges)
        paint.setColor(0x28FFFFFF);
        canvas.drawRect(cx - armL + 3, cy - (armW / 2), cx + armL - 3, cy - (armW / 2) + 2, paint);
        canvas.drawRect(cx - (armW / 2), cy - armL + 3, cx + (armW / 2), cy - armL + 5, paint);

        // Arrows (▲, ▼, ◀, ▶)
        textPaint.setColor(0xFF607D8B);
        textPaint.setTextSize(armW * 0.55f);
        canvas.drawText("▲", cx, cy - (armL * 0.52f) + (textPaint.getTextSize() * 0.35f), textPaint);
        canvas.drawText("▼", cx, cy + (armL * 0.52f) + (textPaint.getTextSize() * 0.35f), textPaint);
        canvas.drawText("◀", cx - (armL * 0.52f), cy + (textPaint.getTextSize() * 0.35f), textPaint);
        canvas.drawText("▶", cx + (armL * 0.52f), cy + (textPaint.getTextSize() * 0.35f), textPaint);

        // Touch feedback glow on active arm
        paint.setColor(0x6600E5FF);
        if ((activeKeyMask & (1 << GBAEngine.KEY_UP)) != 0)
            canvas.drawRect(new RectF(cx - (armW / 2), cy - armL, cx + (armW / 2), cy - (armW / 2)), paint);
        if ((activeKeyMask & (1 << GBAEngine.KEY_DOWN)) != 0)
            canvas.drawRect(new RectF(cx - (armW / 2), cy + (armW / 2), cx + (armW / 2), cy + armL), paint);
        if ((activeKeyMask & (1 << GBAEngine.KEY_LEFT)) != 0)
            canvas.drawRect(new RectF(cx - armL, cy - (armW / 2), cx - (armW / 2), cy + (armW / 2)), paint);
        if ((activeKeyMask & (1 << GBAEngine.KEY_RIGHT)) != 0)
            canvas.drawRect(new RectF(cx + (armW / 2), cy - (armW / 2), cx + armL, cy + (armW / 2)), paint);
    }

    private void drawABSection(Canvas canvas) {
        // Angled recessed tray in chassis behind A and B
        paint.setColor(0xFFD6DCE0);
        canvas.drawRoundRect(abTrayBounds, abTrayBounds.height() / 2, abTrayBounds.height() / 2, paint);

        // Inner shadow on the tray
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(3f);
        paint.setColor(0x20000000);
        canvas.drawRoundRect(abTrayBounds, abTrayBounds.height() / 2, abTrayBounds.height() / 2, paint);
        paint.setStyle(Paint.Style.FILL);

        // B Button (Left-Down)
        drawRoundActionButton(canvas, btnBBounds, "B", (activeKeyMask & (1 << GBAEngine.KEY_B)) != 0);

        // A Button (Right-Up)
        drawRoundActionButton(canvas, btnABounds, "A", (activeKeyMask & (1 << GBAEngine.KEY_A)) != 0);
    }

    private void drawRoundActionButton(Canvas canvas, RectF r, String label, boolean pressed) {
        float cx = r.centerX();
        float cy = r.centerY();
        float radius = r.width() / 2f;

        // Button shadow
        shadowPaint.setColor(0x40000000);
        canvas.drawCircle(cx, cy + 6f, radius, shadowPaint);

        // 3D Spherical Radial Gradient (Classic Wine/Ruby Red)
        int centerColor = pressed ? 0xFFE91E63 : 0xFFC2185B;
        int edgeColor = pressed ? 0xFF880E4F : 0xFF880E4F;
        RadialGradient grad = new RadialGradient(
                cx - (radius * 0.3f), cy - (radius * 0.3f), radius * 1.2f,
                new int[]{centerColor, edgeColor},
                new float[]{0.0f, 1.0f},
                Shader.TileMode.CLAMP
        );
        paint.setShader(grad);
        canvas.drawCircle(cx, cy, radius, paint);
        paint.setShader(null);

        // Spherical light reflection highlight
        paint.setColor(0x35FFFFFF);
        canvas.drawCircle(cx - (radius * 0.25f), cy - (radius * 0.25f), radius * 0.55f, paint);

        // Crisp engraved white lettering
        textPaint.setColor(Color.WHITE);
        textPaint.setTextSize(radius * 0.90f);
        canvas.drawText(label, cx, cy + (textPaint.getTextSize() * 0.35f), textPaint);
    }

    private void drawSelectStart(Canvas canvas) {
        drawAngledPill(canvas, btnSelectBounds, "SELECT", (activeKeyMask & (1 << GBAEngine.KEY_SELECT)) != 0);
        drawAngledPill(canvas, btnStartBounds, "START", (activeKeyMask & (1 << GBAEngine.KEY_START)) != 0);
    }

    private void drawAngledPill(Canvas canvas, RectF r, String label, boolean pressed) {
        canvas.save();
        canvas.rotate(-22f, r.centerX(), r.centerY());

        // Shadow
        shadowPaint.setColor(0x30000000);
        canvas.drawRoundRect(new RectF(r.left, r.top + 3, r.right, r.bottom + 3), 10, 10, shadowPaint);

        // Pill body
        paint.setColor(pressed ? 0xFF78909C : 0xFF455A64);
        canvas.drawRoundRect(r, 10, 10, paint);

        canvas.restore();

        // Label below pill
        textPaint.setColor(0xFF78909C);
        textPaint.setTextSize(20f);
        canvas.drawText(label, r.centerX(), r.bottom + 22f, textPaint);
    }

    private void drawSpeakerGrille(Canvas canvas) {
        float startX = chassisRect.width() * 0.76f;
        float startY = chassisRect.bottom - (chassisRect.height() * 0.16f);
        float dotRadius = 4f;
        float spacing = 16f;

        paint.setColor(0xFFB0BEC5);
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (row + col >= 3 && row + col <= 6) {
                    canvas.drawCircle(startX + (col * spacing), startY + (row * spacing), dotRadius, paint);
                }
            }
        }
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
                    float deadzone = dpadBounds.width() * 0.14f;

                    if (dy < -deadzone) newKeyMask |= (1 << GBAEngine.KEY_UP);
                    if (dy > deadzone) newKeyMask |= (1 << GBAEngine.KEY_DOWN);
                    if (dx < -deadzone) newKeyMask |= (1 << GBAEngine.KEY_LEFT);
                    if (dx > deadzone) newKeyMask |= (1 << GBAEngine.KEY_RIGHT);
                }

                // A and B Buttons (with generous touch radius)
                float touchRadiusPad = btnABounds.width() * 0.20f;
                RectF expandedA = new RectF(btnABounds.left - touchRadiusPad, btnABounds.top - touchRadiusPad, btnABounds.right + touchRadiusPad, btnABounds.bottom + touchRadiusPad);
                RectF expandedB = new RectF(btnBBounds.left - touchRadiusPad, btnBBounds.top - touchRadiusPad, btnBBounds.right + touchRadiusPad, btnBBounds.bottom + touchRadiusPad);

                if (expandedA.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_A);
                if (expandedB.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_B);

                // L and R
                if (btnLBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_L);
                if (btnRBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_R);

                // Select and Start
                if (btnSelectBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_SELECT);
                if (btnStartBounds.contains(x, y)) newKeyMask |= (1 << GBAEngine.KEY_START);

                // Quick Tools (Speed & Save)
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
