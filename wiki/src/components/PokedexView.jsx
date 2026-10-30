import React, { useState, useMemo, useEffect } from 'react';
import { Search, BookOpen, X, Sparkles } from 'lucide-react';
import { pokedexData } from '../data/pokedexData';
import chele3DImg from '../assets/chele/chele_3d.png';
import cheleFrontImg from '../assets/chele/front_transparent.png';
import cheleAnimGif from '../assets/chele/anim.gif';

const ALL_TYPES = [
  'TODOS',
  'Planta',
  'Fogo',
  'Água',
  'Elétrico',
  'Inseto',
  'Normal',
  'Voador',
  'Veneno',
  'Terra',
  'Fada',
  'Lutador',
  'Psíquico',
  'Pedra',
  'Fantasma',
  'Aço',
  'Gelo',
  'Dragão',
  'Sombrio'
];

export default function PokedexView({ searchTargetMon }) {
  const [searchVal, setSearchVal] = useState(searchTargetMon || '');
  const [selectedType, setSelectedType] = useState('TODOS');
  const [selectedMonModal, setSelectedMonModal] = useState(null);
  const [cheleModalMode, setCheleModalMode] = useState('3d');

  useEffect(() => {
    if (searchTargetMon) {
      setSearchVal(searchTargetMon);
      setSelectedType('TODOS');
    }
  }, [searchTargetMon]);

  const filteredMonList = useMemo(() => {
    const q = searchVal
      .trim()
      .normalize('NFD')
      .replace(/[\u0300-\u036f]/g, '')
      .toLowerCase();

    return pokedexData.filter((mon) => { 
      const cleanName = mon.name
        .normalize('NFD')
        .replace(/[\u0300-\u036f]/g, '')
        .toLowerCase();
      const matchesSearch = !q || cleanName.includes(q) || mon.num.toString() === q;
      const matchesType = selectedType === 'TODOS' || mon.type.includes(selectedType);
      return matchesSearch && matchesType;
    });
  }, [searchVal, selectedType]);

  return (
    <div style={{ maxWidth: '1200px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.25rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#ef4444', fontWeight: 700, fontSize: '0.9rem', marginBottom: '0.4rem' }}>
          <BookOpen size={18} />
          <span>Enciclopédia Completa dos {pokedexData.length} Monstros</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          Pokédex Nacional de Kanto & Johto
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Passe o mouse ou toque nos Pokémon para ver seus sprites animados e modelos 3D! Filtre por tipo elemental ou busque pelo nome ou número da criatura.
        </p>
      </div>

      {/* Search Input Bar */}
      <div style={{ display: 'flex', gap: '0.75rem', marginBottom: '1rem', flexWrap: 'wrap' }}>
        <div style={{
          position: 'relative',
          flex: 1,
          minWidth: '240px',
          background: 'var(--bg-card)',
          border: '1px solid var(--border-color)',
          borderRadius: 'var(--radius-md)',
          display: 'flex',
          alignItems: 'center',
          padding: '0 0.85rem'
        }}>
          <Search size={18} color="var(--text-muted)" />
          <input
            type="text"
            value={searchVal}
            onChange={(e) => setSearchVal(e.target.value)}
            placeholder="Buscar por nome ou número (ex: 25, Pikachu ou Chele)..."
            style={{
              width: '100%',
              padding: '0.7rem 0.5rem',
              background: 'transparent',
              border: 'none',
              outline: 'none',
              color: 'var(--text-heading)',
              fontSize: '0.95rem',
              fontFamily: 'inherit'
            }}
          />
          {searchVal && (
            <button
              type="button"
              onClick={() => setSearchVal('')}
              style={{ background: 'transparent', border: 'none', color: 'var(--text-muted)', cursor: 'pointer' }}
            >
              <X size={16} />
            </button>
          )}
        </div>

        <div style={{ display: 'flex', alignItems: 'center', gap: '0.4rem', color: 'var(--text-muted)', fontSize: '0.85rem', padding: '0.5rem' }}>
          <span>Exibindo:</span>
          <strong style={{ color: '#ef4444' }}>{filteredMonList.length}</strong>
          <span>de {pokedexData.length}</span>
        </div>
      </div>

      {/* Type Filter Chips (Horizontal Touch Scroll) */}
      <div className="pills-scroll-bar" style={{ marginBottom: '1.5rem' }}>
        {ALL_TYPES.map((type) => {
          const isActive = selectedType === type;
          return (
            <button
              key={type}
              type="button"
              className={`filter-pill-btn ${isActive ? 'active' : ''}`}
              onClick={() => setSelectedType(type)}
            >
              {type}
            </button>
          );
        })}
      </div>

      {/* Grid of Pokemon */}
      {filteredMonList.length === 0 ? (
        <div style={{ textAlign: 'center', padding: '3rem 1rem', color: 'var(--text-muted)' }}>
          <p style={{ fontSize: '1.1rem', color: '#fff', marginBottom: '0.5rem' }}>Nenhum Pokémon encontrado!</p>
          <p style={{ fontSize: '0.85rem' }}>Tente limpar o filtro de busca ou selecionar outro tipo elementar.</p>
        </div>
      ) : (
        <div className="grid-pokedex">
          {filteredMonList.map((mon) => {
            const isChele = Boolean(mon.customSprite);
            const defaultSpriteSrc = isChele
              ? chele3DImg
              : `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${mon.num}.png`;
            const hoverSpriteSrc = isChele
              ? cheleAnimGif
              : `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/showdown/${mon.num}.gif`;

            return (
              <div
                key={mon.num}
                className="mon-card"
                onClick={() => {
                  setCheleModalMode('3d');
                  setSelectedMonModal(mon);
                }}
                style={isChele ? { border: '1px solid rgba(168, 85, 247, 0.45)', boxShadow: '0 0 18px rgba(168, 85, 247, 0.14)' } : undefined}
              >
                {/* Card Top: Number & Types */}
                <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', width: '100%', marginBottom: '0.25rem' }}>
                  <span style={{ fontSize: '0.8rem', fontWeight: 800, color: 'var(--text-muted)' }}>
                    #{mon.num.toString().padStart(3, '0')}
                  </span>
                  <div style={{ display: 'flex', gap: '3px' }}>
                    {mon.type.map((t) => (
                      <span key={t} className={`type-badge type-${t}`} style={{ fontSize: '0.65rem', padding: '1px 5px' }}>
                        {t}
                      </span>
                    ))}
                  </div>
                </div>

                {/* Sprite Image with 3D / animated hover */}
                <div className="mon-sprite-box">
                  <img
                    className="mon-sprite"
                    src={defaultSpriteSrc}
                    alt={mon.name}
                    loading="lazy"
                    style={isChele ? { width: '84px', height: '84px', objectFit: 'contain', imageRendering: 'auto', filter: 'drop-shadow(0 4px 10px rgba(168, 85, 247, 0.35))' } : undefined}
                    onMouseEnter={(e) => {
                      e.currentTarget.src = hoverSpriteSrc;
                      if (isChele) e.currentTarget.style.imageRendering = 'pixelated';
                    }}
                    onMouseLeave={(e) => {
                      e.currentTarget.src = defaultSpriteSrc;
                      if (isChele) e.currentTarget.style.imageRendering = 'auto';
                    }}
                    onError={(e) => {
                      e.currentTarget.onerror = null;
                      e.currentTarget.src = isChele ? cheleFrontImg : `graphics/pokemon/${mon.folder}/front.png`;
                    }}
                  />
                </div>

                {/* Name */}
                <h3 style={{ fontSize: '1rem', fontWeight: 800, textAlign: 'center', color: 'var(--text-heading)', marginBottom: '0.25rem', display: 'flex', alignItems: 'center', justifyContent: 'center', gap: '4px' }}>
                  <span>{mon.name}</span>
                  {isChele && <Sparkles size={14} color="#f59e0b" />}
                </h3>

                {/* Evolution Details */}
                <div style={{
                  fontSize: '0.72rem',
                  color: 'var(--text-muted)',
                  textAlign: 'center',
                  lineHeight: '1.3',
                  background: 'var(--bg-subtle)',
                  width: '100%',
                  padding: '4px 6px',
                  borderRadius: '6px',
                  marginTop: 'auto'
                }}>
                  {mon.evo}
                </div>
              </div>
            );
          })}
        </div>
      )}

      {/* Mon Modal Details */}
      {selectedMonModal && (
        <div
          className="spotlight-overlay"
          onClick={(e) => {
            if (e.target === e.currentTarget) setSelectedMonModal(null);
          }}
        >
          <div className="spotlight-modal" style={{ maxWidth: '440px', padding: '1.5rem', textAlign: 'center' }}>
            <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: '0.5rem' }}>
              <span style={{ fontSize: '0.9rem', fontWeight: 800, color: 'var(--text-muted)' }}>
                Nº {selectedMonModal.num.toString().padStart(3, '0')}
              </span>
              <button
                type="button"
                onClick={() => setSelectedMonModal(null)}
                style={{ background: 'transparent', border: 'none', color: 'var(--text-heading)', cursor: 'pointer' }}
              >
                <X size={20} />
              </button>
            </div>

            {selectedMonModal.customSprite && (
              <div style={{ display: 'flex', justifyContent: 'center', gap: '0.4rem', marginBottom: '0.75rem' }}>
                <button
                  type="button"
                  onClick={() => setCheleModalMode('3d')}
                  className={`filter-pill-btn ${cheleModalMode === '3d' ? 'active' : ''}`}
                  style={{ fontSize: '0.75rem', padding: '3px 10px' }}
                >
                  ✨ Modelo 3D Oficial
                </button>
                <button
                  type="button"
                  onClick={() => setCheleModalMode('anim')}
                  className={`filter-pill-btn ${cheleModalMode === 'anim' ? 'active' : ''}`}
                  style={{ fontSize: '0.75rem', padding: '3px 10px' }}
                >
                  🎮 Sprite GBA Animado
                </button>
              </div>
            )}

            <div style={{ width: '165px', height: '165px', margin: '0 auto 1rem auto', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <img
                src={
                  selectedMonModal.customSprite
                    ? (cheleModalMode === '3d' ? chele3DImg : cheleAnimGif)
                    : `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/official-artwork/${selectedMonModal.num}.png`
                }
                alt={selectedMonModal.name}
                style={{
                  maxWidth: '100%',
                  maxHeight: '100%',
                  width: selectedMonModal.customSprite ? (cheleModalMode === '3d' ? '160px' : '118px') : undefined,
                  height: selectedMonModal.customSprite ? (cheleModalMode === '3d' ? '160px' : '118px') : undefined,
                  imageRendering: selectedMonModal.customSprite && cheleModalMode === 'anim' ? 'pixelated' : 'auto',
                  filter: 'drop-shadow(0 8px 16px rgba(0,0,0,0.55))'
                }}
                onError={(e) => {
                  e.currentTarget.src = selectedMonModal.customSprite ? cheleFrontImg : `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${selectedMonModal.num}.png`;
                }}
              />
            </div>

            <h2 style={{ fontSize: '1.5rem', fontWeight: 900, marginBottom: '0.5rem', color: 'var(--text-heading)' }}>{selectedMonModal.name}</h2>

            <div style={{ display: 'flex', gap: '0.5rem', justifyContent: 'center', marginBottom: '1.25rem' }}>
              {selectedMonModal.type.map((t) => (
                <span key={t} className={`type-badge type-${t}`} style={{ fontSize: '0.8rem', padding: '4px 10px' }}>
                  {t}
                </span>
              ))}
            </div>

            <div style={{
              background: 'var(--bg-subtle)',
              borderRadius: 'var(--radius-md)',
              padding: '1rem',
              textAlign: 'left',
              fontSize: '0.88rem',
              border: '1px solid var(--border-color)',
              marginBottom: '1rem'
            }}>
              <strong style={{ color: 'var(--primary)' }}>Método de Evolução / Origem: </strong>
              <div style={{ marginTop: '0.25rem', color: 'var(--text-main)' }}>{selectedMonModal.evo}</div>
              {selectedMonModal.customSprite && (
                <div style={{ marginTop: '0.65rem', paddingTop: '0.65rem', borderTop: '1px solid var(--border-color)', fontSize: '0.82rem', color: 'var(--text-muted)', lineHeight: '1.45' }}>
                  <div><strong style={{ color: 'var(--text-heading)' }}>Habilidades:</strong> Super Luck / Infiltrator • <strong style={{ color: 'var(--text-heading)' }}>BST:</strong> 515 (Sp. Atk 115 / Speed 125)</div>
                  <div style={{ marginTop: '0.25rem' }}><strong style={{ color: 'var(--text-heading)' }}>Locais:</strong> Rota 2 (Noite), Rota 10, Pokémon Tower, Pokémon Mansion e Rota 29/30 (Johto).</div>
                </div>
              )}
            </div>

            <button
              type="button"
              onClick={() => setSelectedMonModal(null)}
              className="btn-primary-red"
              style={{ width: '100%' }}
            >
              Fechar
            </button>
          </div>
        </div>
      )}
    </div>
  );
}
