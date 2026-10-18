import React, { useState, useMemo, useEffect } from 'react';
import { Search, BookOpen, Sparkles, Filter, X } from 'lucide-react';
import { pokedexData } from '../data/pokedexData';

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
          <span>Enciclopédia Completa dos 251 Monstros</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          Pokédex Nacional de Kanto & Johto
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Passe o mouse ou toque nos Pokémon para ver seus sprites animados! Filtre por tipo elemental ou busque pelo nome ou número da criatura.
        </p>
      </div>

      {/* Search Input Bar */}
      <div style={{ display: 'flex', gap: '0.75rem', marginBottom: '1rem', flexWrap: 'wrap' }}>
        <div style={{
          position: 'relative',
          flex: 1,
          minWidth: '240px',
          background: 'rgba(255, 255, 255, 0.05)',
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
            placeholder="Buscar por nome ou número (ex: 25 ou Pikachu)..."
            style={{
              width: '100%',
              padding: '0.7rem 0.5rem',
              background: 'transparent',
              border: 'none',
              outline: 'none',
              color: '#fff',
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
          <span>de 251</span>
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
          {filteredMonList.map((mon) => (
            <div
              key={mon.num}
              className="mon-card"
              onClick={() => setSelectedMonModal(mon)}
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

              {/* Sprite Image with animated hover */}
              <div className="mon-sprite-box">
                <img
                  className="mon-sprite"
                  src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${mon.num}.png`}
                  alt={mon.name}
                  loading="lazy"
                  onMouseEnter={(e) => {
                    e.currentTarget.src = `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/showdown/${mon.num}.gif`;
                  }}
                  onMouseLeave={(e) => {
                    e.currentTarget.src = `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${mon.num}.png`;
                  }}
                  onError={(e) => {
                    e.currentTarget.onerror = null;
                    e.currentTarget.src = `graphics/pokemon/${mon.folder}/front.png`;
                  }}
                />
              </div>

              {/* Name */}
              <h3 style={{ fontSize: '1rem', fontWeight: 800, textAlign: 'center', color: '#fff', marginBottom: '0.25rem' }}>
                {mon.name}
              </h3>

              {/* Evolution Details */}
              <div style={{
                fontSize: '0.72rem',
                color: 'var(--text-muted)',
                textAlign: 'center',
                lineHeight: '1.3',
                background: 'rgba(255, 255, 255, 0.03)',
                width: '100%',
                padding: '4px 6px',
                borderRadius: '6px',
                marginTop: 'auto'
              }}>
                {mon.evo}
              </div>
            </div>
          ))}
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
          <div className="spotlight-modal" style={{ maxWidth: '420px', padding: '1.5rem', textAlign: 'center' }}>
            <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: '0.5rem' }}>
              <span style={{ fontSize: '0.9rem', fontWeight: 800, color: 'var(--text-muted)' }}>
                Nº {selectedMonModal.num.toString().padStart(3, '0')}
              </span>
              <button
                type="button"
                onClick={() => setSelectedMonModal(null)}
                style={{ background: 'transparent', border: 'none', color: '#fff', cursor: 'pointer' }}
              >
                <X size={20} />
              </button>
            </div>

            <div style={{ width: '130px', height: '130px', margin: '0 auto 1rem auto', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
              <img
                src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/official-artwork/${selectedMonModal.num}.png`}
                alt={selectedMonModal.name}
                style={{ maxWidth: '100%', maxHeight: '100%', filter: 'drop-shadow(0 6px 12px rgba(0,0,0,0.5))' }}
                onError={(e) => {
                  e.currentTarget.src = `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${selectedMonModal.num}.png`;
                }}
              />
            </div>

            <h2 style={{ fontSize: '1.5rem', fontWeight: 900, marginBottom: '0.5rem' }}>{selectedMonModal.name}</h2>

            <div style={{ display: 'flex', gap: '0.5rem', justifyContent: 'center', marginBottom: '1.25rem' }}>
              {selectedMonModal.type.map((t) => (
                <span key={t} className={`type-badge type-${t}`} style={{ fontSize: '0.8rem', padding: '4px 10px' }}>
                  {t}
                </span>
              ))}
            </div>

            <div style={{
              background: 'rgba(255, 255, 255, 0.04)',
              borderRadius: 'var(--radius-md)',
              padding: '1rem',
              textAlign: 'left',
              fontSize: '0.88rem',
              border: '1px solid var(--border-color)',
              marginBottom: '1rem'
            }}>
              <strong style={{ color: '#ef4444' }}>Método de Evolução: </strong>
              <div style={{ marginTop: '0.25rem', color: '#cbd5e1' }}>{selectedMonModal.evo}</div>
            </div>

            <button
              type="button"
              onClick={() => setSelectedMonModal(null)}
              style={{
                width: '100%',
                background: '#ef4444',
                color: '#fff',
                border: 'none',
                borderRadius: 'var(--radius-md)',
                padding: '0.75rem',
                fontWeight: 700,
                cursor: 'pointer'
              }}
            >
              Fechar
            </button>
          </div>
        </div>
      )}
    </div>
  );
}
