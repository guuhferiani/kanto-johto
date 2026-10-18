let emulator = null;
let isTurbo = false;
let isMuted = false;

// Default User Settings
let userSettings = {
    opacity: 80,
    scale: 1.0,
    position: 'normal',
    haptic: true,
    filter: 'pixel'
};

// RetroArch / GBA Key mapping
const KEY_MAP = {
    'ArrowUp': 'ArrowUp',
    'ArrowDown': 'ArrowDown',
    'ArrowLeft': 'ArrowLeft',
    'ArrowRight': 'ArrowRight',
    'KeyZ': 'z',       // A button
    'KeyX': 'x',       // B button
    'KeyA': 'a',       // L shoulder
    'KeyS': 's',       // R shoulder
    'Enter': 'Enter',   // Start
    'ShiftRight': 'Shift' // Select
};

function triggerVibration(duration = 18) {
    if (!userSettings.haptic) return;
    try {
        if (window.AndroidBridge && typeof window.AndroidBridge.vibrate === 'function') {
            window.AndroidBridge.vibrate(duration);
        } else if (navigator.vibrate) {
            navigator.vibrate(duration);
        }
    } catch (e) {
        // Ignore vibration errors
    }
}

function sendKeyEvent(type, code) {
    const key = KEY_MAP[code] || code;
    const event = new KeyboardEvent(type, {
        code: code,
        key: key,
        bubbles: true,
        cancelable: true
    });
    window.dispatchEvent(event);
    const canvas = document.querySelector('canvas');
    if (canvas) {
        canvas.dispatchEvent(event);
    }
}

function setupTouchControls() {
    const buttons = document.querySelectorAll('[data-key]');

    buttons.forEach(btn => {
        const key = btn.getAttribute('data-key');

        const press = (e) => {
            e.preventDefault();
            btn.classList.add('active');
            triggerVibration(16);
            sendKeyEvent('keydown', key);
        };

        const release = (e) => {
            e.preventDefault();
            btn.classList.remove('active');
            sendKeyEvent('keyup', key);
        };

        btn.addEventListener('touchstart', press, { passive: false });
        btn.addEventListener('touchend', release, { passive: false });
        btn.addEventListener('touchcancel', release, { passive: false });

        btn.addEventListener('mousedown', press);
        btn.addEventListener('mouseup', release);
        btn.addEventListener('mouseleave', release);
    });
}

async function initEmulator() {
    const target = document.getElementById('emulator-target');
    const overlay = document.getElementById('loading-overlay');

    try {
        console.log('Iniciando emulador mGBA offline...');
        
        emulator = await Nostalgist.launch({
            core: 'mgba',
            rom: '../game.gba',
            element: target,
            resolveCoreJs: () => 'core/mgba_libretro.js',
            resolveCoreWasm: () => 'core/mgba_libretro.wasm',
            retroarchConfig: {
                audio_volume: 0,
                video_vsync: true,
                video_smooth: false
            }
        });

        console.log('Emulador iniciado com sucesso!');
        if (overlay) {
            overlay.style.opacity = '0';
            setTimeout(() => {
                overlay.style.display = 'none';
            }, 400);
        }
    } catch (err) {
        console.error('Erro ao inicializar emulador:', err);
        if (overlay) {
            overlay.innerHTML = `
                <div class="loader-content">
                    <img src="icon.png" style="width:80px;border-radius:18px;">
                    <h2 style="color:#ef4444;margin:12px 0;">Erro ao iniciar jogo</h2>
                    <p style="font-size:12px;color:#94a3b8;max-width:280px;">${err.message || err}</p>
                </div>
            `;
        }
    }
}

function setupToolbar() {
    const btnTurbo = document.getElementById('btn-turbo');
    const btnSave = document.getElementById('btn-save-state');
    const btnLoad = document.getElementById('btn-load-state');
    const btnMute = document.getElementById('btn-mute');

    if (btnTurbo) {
        btnTurbo.addEventListener('click', async () => {
            triggerVibration(25);
            if (!emulator) return;
            isTurbo = !isTurbo;
            btnTurbo.innerText = isTurbo ? '⚡ 2.5x' : '⚡ 1x';
            btnTurbo.style.background = isTurbo ? '#ef4444' : '';
            try {
                await emulator.sendCommand('FAST_FORWARD');
            } catch (e) {
                console.log(e);
            }
        });
    }

    if (btnSave) {
        btnSave.addEventListener('click', async () => {
            triggerVibration(30);
            if (!emulator) return;
            try {
                const state = await emulator.saveState();
                localStorage.setItem('pkmn_save_state', JSON.stringify(Array.from(new Uint8Array(state.state))));
                alert('Jogo salvo com sucesso!');
            } catch (e) {
                console.error('Erro ao salvar estado:', e);
            }
        });
    }

    if (btnLoad) {
        btnLoad.addEventListener('click', async () => {
            triggerVibration(30);
            if (!emulator) return;
            try {
                const raw = localStorage.getItem('pkmn_save_state');
                if (raw) {
                    const data = new Uint8Array(JSON.parse(raw));
                    await emulator.loadState(data);
                    alert('Jogo restaurado com sucesso!');
                } else {
                    alert('Nenhum estado salvo encontrado.');
                }
            } catch (e) {
                console.error('Erro ao carregar estado:', e);
            }
        });
    }

    if (btnMute) {
        btnMute.addEventListener('click', async () => {
            triggerVibration(20);
            if (!emulator) return;
            isMuted = !isMuted;
            btnMute.innerText = isMuted ? '🔇' : '🔊';
            try {
                await emulator.sendCommand('MUTE');
            } catch (e) {
                console.log(e);
            }
        });
    }

    const btnSettings = document.getElementById('btn-settings');
    const modalSettings = document.getElementById('settings-modal');
    const btnCloseSettings = document.getElementById('btn-close-settings');

    if (btnSettings && modalSettings) {
        btnSettings.addEventListener('click', () => {
            triggerVibration(20);
            modalSettings.style.display = 'flex';
        });
    }

    if (btnCloseSettings && modalSettings) {
        btnCloseSettings.addEventListener('click', () => {
            triggerVibration(20);
            modalSettings.style.display = 'none';
        });
    }

    if (modalSettings) {
        modalSettings.addEventListener('click', (e) => {
            if (e.target === modalSettings) {
                modalSettings.style.display = 'none';
            }
        });
    }
}

function loadSettings() {
    try {
        const raw = localStorage.getItem('pkmn_user_settings');
        if (raw) {
            userSettings = Object.assign(userSettings, JSON.parse(raw));
        }
    } catch (e) {
        console.error('Erro ao ler configurações salvas:', e);
    }
    applySettings();
}

function saveSettings() {
    try {
        localStorage.setItem('pkmn_user_settings', JSON.stringify(userSettings));
    } catch (e) {
        console.error('Erro ao salvar configurações:', e);
    }
}

function applySettings() {
    const root = document.documentElement;
    const target = document.getElementById('emulator-target');

    // Apply Controls Opacity
    root.style.setProperty('--controls-opacity', (userSettings.opacity / 100).toString());
    const valOpacity = document.getElementById('val-opacity');
    if (valOpacity) valOpacity.textContent = userSettings.opacity + '%';
    const sliderOpacity = document.getElementById('slider-opacity');
    if (sliderOpacity) sliderOpacity.value = userSettings.opacity;

    // Apply Controls Scale
    root.style.setProperty('--controls-scale', userSettings.scale.toString());
    document.querySelectorAll('#control-scale-group .segment-btn').forEach(btn => {
        btn.classList.toggle('active', parseFloat(btn.getAttribute('data-scale')) === userSettings.scale);
    });

    // Apply Controls Position
    let offset = '0px';
    if (userSettings.position === 'low') offset = '-14px';
    if (userSettings.position === 'high') offset = '24px';
    root.style.setProperty('--controls-bottom-offset', offset);
    document.querySelectorAll('#control-pos-group .segment-btn').forEach(btn => {
        btn.classList.toggle('active', btn.getAttribute('data-pos') === userSettings.position);
    });

    // Apply Haptic Toggle
    const toggleHaptic = document.getElementById('toggle-haptic');
    if (toggleHaptic) toggleHaptic.checked = userSettings.haptic;

    // Apply Graphic Filters
    if (target) {
        target.classList.remove('filter-pixel', 'filter-lcd', 'filter-crt', 'filter-smooth');
        target.classList.add(`filter-${userSettings.filter}`);
    }
    document.querySelectorAll('#filter-group .segment-btn').forEach(btn => {
        btn.classList.toggle('active', btn.getAttribute('data-filter') === userSettings.filter);
    });
}

function setupSettingsModal() {
    // Opacity Slider
    const sliderOpacity = document.getElementById('slider-opacity');
    if (sliderOpacity) {
        sliderOpacity.addEventListener('input', (e) => {
            userSettings.opacity = parseInt(e.target.value, 10);
            applySettings();
            saveSettings();
        });
    }

    // Scale Selector
    document.querySelectorAll('#control-scale-group .segment-btn').forEach(btn => {
        btn.addEventListener('click', () => {
            triggerVibration(20);
            userSettings.scale = parseFloat(btn.getAttribute('data-scale'));
            applySettings();
            saveSettings();
        });
    });

    // Position Selector
    document.querySelectorAll('#control-pos-group .segment-btn').forEach(btn => {
        btn.addEventListener('click', () => {
            triggerVibration(20);
            userSettings.position = btn.getAttribute('data-pos');
            applySettings();
            saveSettings();
        });
    });

    // Haptic Checkbox
    const toggleHaptic = document.getElementById('toggle-haptic');
    if (toggleHaptic) {
        toggleHaptic.addEventListener('change', (e) => {
            userSettings.haptic = e.target.checked;
            triggerVibration(25);
            saveSettings();
        });
    }

    // Graphic Filter Selector
    document.querySelectorAll('#filter-group .segment-btn').forEach(btn => {
        btn.addEventListener('click', () => {
            triggerVibration(20);
            userSettings.filter = btn.getAttribute('data-filter');
            applySettings();
            saveSettings();
        });
    });
}

// Android Activity lifecycle hooks
window.onAppPause = function() {
    if (emulator && typeof emulator.pause === 'function') {
        emulator.pause();
    }
};

window.onAppResume = function() {
    if (emulator && typeof emulator.resume === 'function') {
        emulator.resume();
    }
};

window.addEventListener('DOMContentLoaded', () => {
    loadSettings();
    setupTouchControls();
    setupToolbar();
    setupSettingsModal();
    initEmulator();
});
