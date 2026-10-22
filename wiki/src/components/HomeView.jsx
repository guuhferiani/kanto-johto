import React from 'react';
import { Compass, Sparkles, Trophy, BookOpen, MapPin, Gift, Zap, Heart, ShieldCheck, Flame, Search } from 'lucide-react';
import coverImg from '../assets/kanto_johto_cover.jpg';

export default function HomeView({ onSelectTab, onOpenSearch }) {
  return (
    <div style={{ maxWidth: '1100px', margin: '0 auto' }}>
      {/* Hero Welcome Banner */}
      <div 
        className="card"
        style={{
          borderLeft: '4px solid var(--primary)',
          padding: '2rem 1.5rem',
          position: 'relative'
        }}
      >
        <div className="hero-banner-grid">
          {/* Left Column: Info & Action Buttons */}
          <div style={{ flex: 1, minWidth: 0 }}>
            <div style={{
              display: 'inline-flex',
              alignItems: 'center',
              gap: '0.4rem',
              background: 'var(--primary-subtle)',
              border: '1px solid rgba(220, 38, 38, 0.25)',
              color: 'var(--primary)',
              padding: '0.25rem 0.75rem',
              borderRadius: '9999px',
              fontSize: '0.8rem',
              fontWeight: 700,
              marginBottom: '1rem'
            }}>
              <Zap size={14} color="var(--primary)" />
              <span>Versão Fiel a Pokémon Yellow / Let's Go</span>
            </div>

            <h1 style={{ fontSize: 'clamp(1.75rem, 4vw, 2.75rem)', fontWeight: 900, marginBottom: '0.75rem', letterSpacing: '-0.5px' }}>
              Wiki & Detonado Definitivo <br />
              <span style={{ color: 'var(--primary)' }}>
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
                className="btn-primary-red"
              >
                <Compass size={18} />
                <span>Detonado Kanto</span>
              </button>

              <button
                type="button"
                onClick={() => onSelectTab('johto')}
                className="btn-secondary-blue"
              >
                <Sparkles size={18} />
                <span>Detonado Johto</span>
              </button>

              <button
                type="button"
                onClick={onOpenSearch}
                className="btn-subtle"
              >
                <Search size={17} color="var(--primary)" />
                <span>Buscar Palavras (Ctrl+K)</span>
              </button>
            </div>
          </div>

          {/* Right Column: Game Cover Artwork */}
          <div className="hero-cover-wrapper">
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
          <div style={{ fontSize: '2rem', fontWeight: 900, color: 'var(--primary)', fontFamily: 'var(--font-heading)' }}>256</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Pokémon Nacionais</div>
        </div>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: 'var(--accent)', fontFamily: 'var(--font-heading)' }}>16</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Insígnias Oficiais</div>
        </div>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: 'var(--secondary)', fontFamily: 'var(--font-heading)' }}>73</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Rotas & Cavernas</div>
        </div>
        <div className="card" style={{ padding: '1.25rem', textAlign: 'center', margin: 0 }}>
          <div style={{ fontSize: '2rem', fontWeight: 900, color: '#10b981', fontFamily: 'var(--font-heading)' }}>100%</div>
          <div style={{ color: 'var(--text-muted)', fontSize: '0.85rem', fontWeight: 600 }}>Android APK & GBA</div>
        </div>
      </div>

      {/* Yellow / Rom Highlights Banner */}
      <div className="card" style={{ borderLeft: '4px solid var(--accent)' }}>
        <h2 style={{ fontSize: '1.25rem', marginBottom: '1rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
          <Zap size={22} color="var(--accent)" />
          <span>Regras e Mecânicas Especiais desta Rom (Estilo Yellow)</span>
        </h2>

        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(260px, 1fr))', gap: '1rem' }}>
          <div className="feature-subcard">
            <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.5rem', fontWeight: 700, color: 'var(--text-heading)' }}>
              <Heart size={18} color="var(--primary)" fill="var(--primary)" />
              <span>Pikachu Parceiro Seguidor</span>
            </div>
            <p style={{ fontSize: '0.85rem', color: 'var(--text-muted)' }}>
              Seu monstro inicial é obrigatoriamente o Pikachu! Ele anda atrás do seu personagem e possui sistema de felicidade vivo.
            </p>
          </div>

          <div className="feature-subcard">
            <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.5rem', fontWeight: 700, color: 'var(--text-heading)' }}>
              <ShieldCheck size={18} color="var(--secondary)" />
              <span>Os 3 Iniciais por Presente</span>
            </div>
            <p style={{ fontSize: '0.85rem', color: 'var(--text-muted)' }}>
              Bulbasaur em Cerulean (amizade com Pikachu), Charmander na Rota 24 e Squirtle de óculos escuros com a policial em Vermilion!
            </p>
          </div>

          <div className="feature-subcard">
            <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.5rem', fontWeight: 700, color: 'var(--text-heading)' }}>
              <Flame size={18} color="var(--primary)" />
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
          style={{ cursor: 'pointer' }}
          onClick={() => onSelectTab('gyms')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: 'var(--radius-md)', background: 'var(--accent-subtle)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <Trophy size={22} color="var(--accent)" />
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
          style={{ cursor: 'pointer' }}
          onClick={() => onSelectTab('pokedex')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: 'var(--radius-md)', background: 'var(--primary-subtle)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <BookOpen size={22} color="var(--primary)" />
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
          style={{ cursor: 'pointer' }}
          onClick={() => onSelectTab('routes')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: 'var(--radius-md)', background: 'rgba(16, 185, 129, 0.12)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
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
          style={{ cursor: 'pointer' }}
          onClick={() => onSelectTab('items')}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.75rem', marginBottom: '0.75rem' }}>
            <div style={{ width: '42px', height: '42px', borderRadius: 'var(--radius-md)', background: 'var(--bg-subtle)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <Gift size={22} color="var(--primary)" />
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
