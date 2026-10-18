import React from 'react';
import { Gamepad2, Download, Smartphone, Monitor, ShieldCheck, Zap } from 'lucide-react';

export default function ControlsView() {
  return (
    <div style={{ maxWidth: '1000px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.5rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#10b981', fontWeight: 700, fontSize: '0.9rem', marginBottom: '0.4rem' }}>
          <Gamepad2 size={18} />
          <span>Jogabilidade & Configurações</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          Controles & Dicas para Android APK e PC
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Saiba como jogar tanto no seu computador com emuladores (mGBA, VisualBoyAdvance) quanto diretamente no seu smartphone Android através do APK compilado nativo.
        </p>
      </div>

      {/* APK Banner */}
      <div className="card" style={{
        background: 'linear-gradient(135deg, rgba(16, 185, 129, 0.15) 0%, rgba(17, 22, 34, 0.9) 100%)',
        borderColor: 'rgba(16, 185, 129, 0.3)',
        display: 'flex',
        flexWrap: 'wrap',
        alignItems: 'center',
        justifyContent: 'space-between',
        gap: '1.25rem'
      }}>
        <div style={{ maxWidth: '600px' }}>
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#6ee7b7', fontWeight: 700, marginBottom: '0.4rem', fontSize: '0.85rem' }}>
            <Smartphone size={18} />
            <span>Versão Nativa Android (APK)</span>
          </div>
          <h2 style={{ fontSize: '1.35rem', fontWeight: 800, marginBottom: '0.5rem' }}>
            Jogue Pokémon Kanto & Johto no seu Celular!
          </h2>
          <p style={{ fontSize: '0.88rem', color: 'var(--text-muted)', lineHeight: '1.5' }}>
            Nosso APK nativo vem com controles de toque transparentes na tela, suporte a áudio estéreo, carregamento instantâneo via WASM/GBA e salvamento persistente.
          </p>
        </div>

        <a
          href="https://github.com/guuhferiani/kanto-johto/releases/latest"
          target="_blank"
          rel="noopener noreferrer"
          style={{
            display: 'inline-flex',
            alignItems: 'center',
            gap: '0.5rem',
            background: 'linear-gradient(135deg, #10b981, #059669)',
            color: '#fff',
            textDecoration: 'none',
            borderRadius: 'var(--radius-md)',
            padding: '0.8rem 1.5rem',
            fontWeight: 700,
            fontSize: '0.95rem',
            boxShadow: '0 4px 14px rgba(16, 185, 129, 0.35)',
            whiteSpace: 'nowrap'
          }}
        >
          <Download size={18} />
          <span>Baixar APK (GitHub Releases)</span>
        </a>
      </div>

      {/* Controls Grid */}
      <div className="grid-responsive-2">
        {/* PC Keyboard Controls */}
        <div className="card">
          <h3 style={{ fontSize: '1.15rem', fontWeight: 800, marginBottom: '0.75rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
            <Monitor size={18} color="#3b82f6" />
            <span>Controles no Teclado (PC)</span>
          </h3>

          <div className="table-responsive" style={{ border: 'none', margin: 0 }}>
            <table className="custom-table">
              <tbody>
                <tr>
                  <td><strong>Direcionais (D-Pad)</strong></td>
                  <td>Setas do Teclado (Cima, Baixo, Esquerda, Direita)</td>
                </tr>
                <tr>
                  <td><strong>Botão A</strong></td>
                  <td>Tecla <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>Z</code> (Confirmar / Falar)</td>
                </tr>
                <tr>
                  <td><strong>Botão B</strong></td>
                  <td>Tecla <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>X</code> (Cancelar / Correr)</td>
                </tr>
                <tr>
                  <td><strong>START</strong></td>
                  <td>Tecla <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>ENTER</code> (Menu do Jogo)</td>
                </tr>
                <tr>
                  <td><strong>SELECT</strong></td>
                  <td>Tecla <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>SHIFT</code> ou <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>BACKSPACE</code></td>
                </tr>
                <tr>
                  <td><strong>Gatilhos L / R</strong></td>
                  <td>Teclas <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>A</code> e <code style={{ background: 'rgba(255,255,255,0.1)', padding: '2px 6px', borderRadius: '4px' }}>S</code></td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>

        {/* Android Best Practices */}
        <div className="card">
          <h3 style={{ fontSize: '1.15rem', fontWeight: 800, marginBottom: '0.75rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
            <ShieldCheck size={18} color="#10b981" />
            <span>Boas Práticas no Android APK</span>
          </h3>

          <div style={{ display: 'flex', flexDirection: 'column', gap: '0.75rem', fontSize: '0.88rem', color: 'var(--text-muted)' }}>
            <p>
              <strong style={{ color: '#fff' }}>1. Salvamento Seguro:</strong> Salve seu progresso sempre pelo menu nativo do jogo (<code style={{ color: '#f59e0b' }}>START -&gt; SAVE</code>). Isso grava um arquivo <code style={{ color: '#f59e0b' }}>.sav</code> padrão de 128KB, permitindo que você copie o save para o PC a qualquer hora!
            </p>
            <p>
              <strong style={{ color: '#fff' }}>2. Interação Rápida no Mapa:</strong> Para usar Cortar em um arbusto ou Força em uma rocha, você não precisa abrir o menu de Pokémon! Apenas fique de frente para o obstáculo e aperte <code style={{ color: '#f59e0b' }}>A</code>.
            </p>
            <p>
              <strong style={{ color: '#fff' }}>3. Modo Tela Cheia:</strong> O APK foi desenhado para se adaptar a proporções 16:9, 18:9 e 20:9 dos celulares modernos, sem distorcer os pixels da imagem.
            </p>
          </div>
        </div>
      </div>
    </div>
  );
}
