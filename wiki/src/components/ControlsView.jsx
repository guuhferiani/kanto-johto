import React from 'react';
import { Gamepad2, Smartphone, Monitor, ShieldCheck, Download, Award, MapPin, Zap, Heart, Sparkles } from 'lucide-react';

export default function ControlsView() {
  return (
    <div style={{ maxWidth: '1000px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.75rem' }}>
        <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.4rem', color: '#10b981', fontWeight: 700, fontSize: '0.85rem', textTransform: 'uppercase', letterSpacing: '1px', marginBottom: '0.25rem' }}>
          <Gamepad2 size={16} />
          <span>Guia de Plataformas</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.2rem)', fontWeight: 800, marginBottom: '0.4rem' }}>
          Controles de Jogo & Instalação do APK
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Saiba como jogar tanto no seu computador com emuladores (mGBA, VisualBoyAdvance) quanto diretamente no seu smartphone Android através do APK compilado nativo.
        </p>
      </div>

      {/* APK Banner */}
      <div className="card" style={{
        borderLeft: '4px solid #10b981',
        display: 'flex',
        flexWrap: 'wrap',
        alignItems: 'center',
        justifyContent: 'space-between',
        gap: '1.25rem'
      }}>
        <div style={{ maxWidth: '600px' }}>
          <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.4rem', background: 'rgba(16, 185, 129, 0.12)', border: '1px solid rgba(16, 185, 129, 0.25)', color: '#10b981', padding: '0.2rem 0.6rem', borderRadius: '9999px', fontWeight: 700, marginBottom: '0.6rem', fontSize: '0.8rem' }}>
            <Smartphone size={15} />
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
          className="btn-primary-red"
          style={{ background: '#059669', borderColor: '#047857' }}
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
            <Monitor size={18} color="var(--secondary)" />
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
                  <td>Tecla <span className="kbd-shortcut">Z</span> (Confirmar / Falar)</td>
                </tr>
                <tr>
                  <td><strong>Botão B</strong></td>
                  <td>Tecla <span className="kbd-shortcut">X</span> (Cancelar / Correr)</td>
                </tr>
                <tr>
                  <td><strong>START</strong></td>
                  <td>Tecla <span className="kbd-shortcut">ENTER</span> (Menu do Jogo)</td>
                </tr>
                <tr>
                  <td><strong>SELECT</strong></td>
                  <td>Tecla <span className="kbd-shortcut">SHIFT</span> ou <span className="kbd-shortcut">BACKSPACE</span></td>
                </tr>
                <tr>
                  <td><strong>Gatilhos L / R</strong></td>
                  <td>Teclas <span className="kbd-shortcut">A</span> e <span className="kbd-shortcut">S</span></td>
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
              <strong style={{ color: 'var(--text-heading)' }}>1. Salvamento Seguro:</strong> Salve seu progresso sempre pelo menu nativo do jogo (<span className="kbd-shortcut">START -&gt; SAVE</span>). Isso grava um arquivo <code style={{ color: 'var(--accent)' }}>.sav</code> padrão de 128KB, permitindo que você copie o save para o PC a qualquer hora!
            </p>
            <p>
              <strong style={{ color: 'var(--text-heading)' }}>2. Interação Rápida no Mapa:</strong> Para usar Cortar em um arbusto ou Força em uma rocha, você não precisa abrir o menu de Pokémon! Apenas fique de frente para o obstáculo e aperte <span className="kbd-shortcut">A</span>.
            </p>
            <p>
              <strong style={{ color: 'var(--text-heading)' }}>3. Modo Tela Cheia:</strong> O APK foi desenhado para se adaptar a proporções 16:9, 18:9 e 20:9 dos celulares modernos, sem distorcer os pixels da imagem.
            </p>
          </div>
        </div>
      </div>

      {/* Special Shortcuts & QoL */}
      <div className="card" style={{ marginTop: '1.25rem', borderLeft: '4px solid var(--primary)' }}>
        <h3 style={{ fontSize: '1.15rem', fontWeight: 800, marginBottom: '0.75rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
          <Zap size={18} color="var(--primary)" />
          <span>Atalhos Rápidos & Recursos Especiais</span>
        </h3>
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(280px, 1fr))', gap: '1rem', fontSize: '0.88rem' }}>
          <div className="feature-subcard">
            <div style={{ fontWeight: 700, color: 'var(--text-heading)', marginBottom: '0.35rem', display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
              <Award size={16} color="var(--accent)" />
              <span>Alternar Insígnias (Kanto / Johto)</span>
            </div>
            <p style={{ color: 'var(--text-muted)' }}>
              No <strong>Cartão de Treinador</strong> (Trainer Card), pressione <span className="kbd-shortcut">L</span>, <span className="kbd-shortcut">R</span> ou <span className="kbd-shortcut">SELECT</span> para alternar instantaneamente entre suas 8 insígnias de Kanto e 8 insígnias de Johto!
            </p>
          </div>
          <div className="feature-subcard">
            <div style={{ fontWeight: 700, color: 'var(--text-heading)', marginBottom: '0.35rem', display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
              <MapPin size={16} color="#10b981" />
              <span>Fly & Mapa Multi-Região</span>
            </div>
            <p style={{ color: 'var(--text-muted)' }}>
              Ao usar a <strong>HM02 Voar (Fly)</strong> ou o <strong>Town Map</strong> (PokeNav), pressione <span className="kbd-shortcut">L</span>, <span className="kbd-shortcut">R</span> ou <span className="kbd-shortcut">SELECT</span> para transitar entre os mapas completos de Kanto e Johto e voar para qualquer cidade visitada!
            </p>
          </div>
          <div className="feature-subcard">
            <div style={{ fontWeight: 700, color: 'var(--text-heading)', marginBottom: '0.35rem', display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
              <Heart size={16} color="var(--primary)" fill="var(--primary)" />
              <span>Medidor de Amizade no Sumário</span>
            </div>
            <p style={{ color: 'var(--text-muted)' }}>
              No <strong>Sumário do Pokémon</strong>, abra a aba de <strong>Perícias (Skills)</strong> e aperte <span className="kbd-shortcut">A</span> para exibir a tela de Felicidade com barra gráfica e pontuação numérica (0 a 255 pts), perfeita para monitorar evoluções como Sylveon, Espeon, Umbreon e Lucario!
            </p>
          </div>
          <div className="feature-subcard">
            <div style={{ fontWeight: 700, color: 'var(--text-heading)', marginBottom: '0.35rem', display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
              <Sparkles size={16} color="var(--secondary)" />
              <span>Interface de Batalha Clean Gen 5</span>
            </div>
            <p style={{ color: 'var(--text-muted)' }}>
              A interface de batalha conta com o visual minimalista e chanfrado de Pokémon Black & White para <strong>Singles e Doubles</strong>, com barras de vida de alto contraste e atributos traduzidos em batalha (<code style={{ color: 'var(--primary)' }}>POD:</code> Poder, <code style={{ color: 'var(--secondary)' }}>PRE:</code> Precisão, <code style={{ color: 'var(--accent)' }}>PRI:</code> Prioridade).
            </p>
          </div>
        </div>
      </div>

    </div>
  );
}
