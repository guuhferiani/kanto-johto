import React from 'react';
import { Compass, Sparkles, Trophy, BookOpen, MapPin, Gift, Download, Zap, Heart, ShieldCheck, Flame } from 'lucide-react';
import coverImg from '../assets/kanto_johto_cover.jpg';

export default function HomeView({ onSelectTab, onOpenSearch }) {
  return (
    <div style={{ maxWidth: '1100px', margin: '0 auto' }}>
      {/* Hero Welcome Banner */}
      <div 
        className="card"
        style={{
          background: 'linear-gradient(135deg, rgba(239, 68, 68, 0.16) 0%, rgba(245, 158, 11, 0.1) 45%, rgba(17, 22, 34, 0.95) 100%)',
          borderColor: 'rgba(239, 68, 68, 0.3)',
          padding: '2rem 1.5rem',
          position: 'relative',
          overflow: 'hidden'
        }}
      >
        <div className="hero-banner-grid">
          {/* Left Column: Info & Action Buttons */}
          <div style={{ flex: 1, minWidth: 0 }}>
            <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.4rem', background: 'rgba(239, 68, 68, 0.2)', border: '1px solid rgba(239, 68, 68, 0.4)', color: '#fca5a5', padding: '0.25rem 0.75rem', borderRadius: '9999px', fontSize: '0.8rem', fontWeight: 700, marginBottom: '1rem' }}>
              <Zap size={14} color="#fca5a5" />
              <span>Versão Fiel a Pokémon Yellow / Let's Go</span>
            </div>

            <h1 style={{ fontSize: 'clamp(1.75rem, 4vw, 2.75rem)', fontWeight: 900, marginBottom: '0.75rem', letterSpacing: '-0.5px' }}>
              Wiki & Detonado Definitivo <br />
              <span style={{
                background: 'linear-gradient(135deg, #f87171, #ef4444, #fbbf24)',
                WebkitBackgroundClip: 'text',
                WebkitTextFillColor: 'transparent'
              }}>
                Pokémon Kanto & Johto
              </span>
            </h1>

            <p style={{ color: 'var(--text-muted)', fontSize: '0.98rem', lineHeight: '1.6', marginBottom: '1.5rem' }}>
              Nesta ROM exclusiva, você começa sua jornada com o <strong>Pikachu Parceiro</strong> que anda fora da Pokébola, enquanto o rival Blue fica com o <strong>Eevee</strong>. Resgate Bulbasaur em Cerulean, Charmander na Rota 24, Squirtle de óculos em Vermilion, derrote os 16 ginásios de Kanto e Johto e desafie o lendário Red no Monte Silver!
            </p>

            <div style={{ display: 'flex', gap: '0.75rem', flexWrap: 'wrap' }}>
              <button
                type="button"
                onClick={() => onSelectTab('kanto')}
                style={{
                  display: 'inline-flex',
                  alignItems: 'center',
                  gap: '0.5rem',
                  background: 'linear-gradient(135deg, #ef4444, #dc2626)',
                  color: '#fff',
                  border: 'none',
                  borderRadius: 'var(--radius-md)',
                  padding: '0.75rem 1.4rem',
                  fontSize: '0.95rem',
                  fontWeight: 700,
                  cursor: 'pointer',
                  boxShadow: '0 4px 14px rgba(239, 68, 68, 0.35)',
                  transition: 'transform 0.15s ease'
                }}
              >
                <Compass size={18} />
                <span>Detonado Kanto</span>
              </button>

              <button
                type="button"
                onClick={() => onSelectTab('johto')}
                style={{
                  display: 'inline-flex',
                  alignItems: 'center',
                  gap: '0.5rem',
                  background: 'linear-gradient(135deg, #3b82f6, #2563eb)',
                  color: '#fff',
                  border: 'none',
                  borderRadius: 'var(--radius-md)',
                  padding: '0.75rem 1.4rem',
                  fontSize: '0.95rem',
                  fontWeight: 700,
                  cursor: 'pointer',
                  boxShadow: '0 4px 14px rgba(59, 130, 246, 0.35)',
                  transition: 'transform 0.15s ease'
                }}
              >
                <Sparkles size={18} />
                <span>Detonado Johto</span>
              </button>

              <button
                type="button"
                onClick={onOpenSearch}
                style={{
                  display: 'inline-flex',
                  alignItems: 'center',
                  gap: '0.5rem',
                  background: 'rgba(255, 255, 255, 0.08)',
                  color: '#f1f5f9',
                  border: '1px solid var(--border-color)',
                  borderRadius: 'var(--radius-md)',
                  padding: '0.75rem 1.25rem',
                  fontSize: '0.95rem',
                  fontWeight: 600,
                  cursor: 'pointer'
                }}
              >
                <Zap size={18} color="#f59e0b" />
                <span>Buscar Palavras (Ctrl+K)</span>
              </button>
            </div>
          </div>

          {/* Right Column: Game Cover Artwork */}
          <div className="hero-cover-wrapper">
            <div className="hero-cover-glow" />
            <img 
              src={coverImg} 
              alt="Capa Oficial Pokémon Kanto & Johto" 
              className="hero-cover-img"
              loading="eager"
            />
          </div>
        </div>
      </div>

      {/* Quick Stats Grid */}
      <div style={{
        display: 'grid',
        gridTemplateColumns: 'repeat(auto-fit, minmax(180px, 1fr))',
        gap: '1rem',
        marginBottom: '1.5rem'
      }}>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: '#ef4444', fontFamily: 'var(--font-heading)' }}>256</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Pokémon Nacionais</div>
        </div>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: '#f59e0b', fontFamily: 'var(--font-heading)' }}>16</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Insígnias Oficiais</div>
        </div>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: '#3b82f6', fontFamily: 'var(--font-heading)' }}>73</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Rotas & Cavernas</div>
        </div>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: '#10b981', fontFamily: 'var(--font-heading)' }}>100%</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Android APK & GBA</div>
        </div>
      </div>

      {/* Yellow / Rom Highlights Banner */}
      <div className="card" style={{ borderColor: 'rgba(245, 158, 11, 0.3)' }}>
        <h2 style={{ fontSize: '1.25rem', marginBottom: '1rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
          <Zap size={22} color="#f59e0b" />
          <span>Regras e Mecânicas Especiais desta Rom (Estilo Yellow)</span>
        </h2>

        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(260px, 1fr))', gap: '1rem' }}>
          <div style={{ background: 'rgba(255, 255, 255, 0.03)', padding: '1rem', borderRadius: 'var(--radius-md)', border: '1px solid var(--border-color)' }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.5rem', fontWeight: 700, color: '#fde68a' }}>
              <Heart size={18} color="#ef4444" fill="#ef4444" />
              <span>Pikachu Parceiro Seguidor</span>
            </div>
            <p style={{ fontSize: '0.85rem', color: 'var(--text-muted)' }}>
              Seu monstro inicial é obrigatoriamente o Pikachu! Ele anda atrás do seu personagem e possui sistema de felicidade vivo.
            </p>
          </div>

          <div style={{ background: 'rgba(255, 255, 255, 0.03)', padding: '1rem', borderRadius: 'var(--radius-md)', border: '1px solid var(--border-color)' }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.5rem', fontWeight: 700, color: '#93c5fd' }}>
              <ShieldCheck size={18} color="#3b82f6" />
              <span>Os 3 Iniciais por Presente</span>
            </div>
            <p style={{ fontSize: '0.85rem', color: 'var(--text-muted)' }}>
              Bulbasaur em Cerulean (amizade com Pikachu), Charmander na Rota 24 e Squirtle de óculos escuros com a policial em Vermilion!
            </p>
          </div>

          <div style={{ background: 'rgba(255, 255, 255, 0.03)', padding: '1rem', borderRadius: 'var(--radius-md)', border: '1px solid var(--border-color)' }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.5rem', fontWeight: 700, color: '#fca5a5' }}>
              <Flame size={18} color="#ef4444" />
              <span>TMs Infinitos & HMs Rápidas</span>
            </div>
            <p style={{ fontSize: '0.85rem', color: 'var(--text-muted)' }}>
              Os TMs nunca quebram e você pode usá-los quantas vezes quiser! HMs como Cortar ativam com toque de botão 'A' direto no mapa.
            </p>
          </div>
        </div>
      </div>

      {/* Feature Navigation Cards */}
      <div className="grid-responsive-2">
        <div 
          className="card"
          style={{ cursor: 'pointer', transition: 'all 0.2s ease' }}
          onClick={() => onSelectTab('gyms')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: '10px', background: 'rgba(245, 158, 11, 0.15)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <Trophy size={22} color="#f59e0b" />
            </div>
            <div>
              <h3 style={{ fontSize: '1.15rem' }}>Mural de Chefes & Insígnias</h3>
              <span style={{ fontSize: '0.8rem', color: 'var(--text-muted)' }}>22 Batalhas Épicas com Portraits</span>
            </div>
          </div>
          <p style={{ fontSize: '0.88rem', color: 'var(--text-muted)' }}>
            Confira a equipe completa, níveis, fraquezas e a estratégia ideal para derrotar Brock, Misty, Surge, a Elite 4 e Red no cume do Monte Silver.
          </p>
        </div>

        <div 
          className="card"
          style={{ cursor: 'pointer', transition: 'all 0.2s ease' }}
          onClick={() => onSelectTab('pokedex')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: '10px', background: 'rgba(239, 68, 68, 0.15)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <BookOpen size={22} color="#ef4444" />
            </div>
            <div>
              <h3 style={{ fontSize: '1.15rem' }}>Pokédex Nacional Interativa</h3>
              <span style={{ fontSize: '0.8rem', color: 'var(--text-muted)' }}>251 Criaturas com Sprites Animados</span>
            </div>
          </div>
          <p style={{ fontSize: '0.88rem', color: 'var(--text-muted)' }}>
            Filtre por tipo (Fogo, Água, Planta, Elétrico...), consulte métodos de evolução e veja sprites clássicos e modernos em altíssima definição.
          </p>
        </div>

        <div 
          className="card"
          style={{ cursor: 'pointer', transition: 'all 0.2s ease' }}
          onClick={() => onSelectTab('routes')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: '10px', background: 'rgba(16, 185, 129, 0.15)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <MapPin size={22} color="#10b981" />
            </div>
            <div>
              <h3 style={{ fontSize: '1.15rem' }}>Enciclopédia de Rotas</h3>
              <span style={{ fontSize: '0.8rem', color: 'var(--text-muted)' }}>73 Mapas com Encontros de Dia e Noite</span>
            </div>
          </div>
          <p style={{ fontSize: '0.88rem', color: 'var(--text-muted)' }}>
            Descubra em quais rotas, cavernas e mares cada Pokémon aparece durante o Dia, Noite, na Pesca/Surfe ou no radar DexNav.
          </p>
        </div>

        <div 
          className="card"
          style={{ cursor: 'pointer', transition: 'all 0.2s ease' }}
          onClick={() => onSelectTab('items')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: '10px', background: 'rgba(139, 92, 246, 0.15)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <Gift size={22} color="#8b5cf6" />
            </div>
            <div>
              <h3 style={{ fontSize: '1.15rem' }}>Localização de TMs & HMs</h3>
              <span style={{ fontSize: '0.8rem', color: 'var(--text-muted)' }}>Máquinas Ocultas e Golpes Poderosos</span>
            </div>
          </div>
          <p style={{ fontSize: '0.88rem', color: 'var(--text-muted)' }}>
            Onde encontrar HM01 Cortar, HM03 Surfe, HM02 Voar, além dos poderosos TM24 Raio, TM13 Raio de Gelo e TM26 Terremoto.
          </p>
        </div>
      </div>
    </div>
  );
}
