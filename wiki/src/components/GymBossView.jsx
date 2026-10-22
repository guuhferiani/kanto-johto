import React, { useState, useEffect } from 'react';
import { Trophy, Swords } from 'lucide-react';
import { gymBossesData } from '../data/gymBossesData';

export default function GymBossView({ highlightBossId }) {
  const [activeTab, setActiveTab] = useState('all');

  useEffect(() => {
    if (highlightBossId) {
      setTimeout(() => {
        const el = document.getElementById(`boss-${highlightBossId}`);
        if (el) {
          el.scrollIntoView({ behavior: 'smooth', block: 'start' });
        }
      }, 100);
    }
  }, [highlightBossId]);

  const filteredBosses = gymBossesData.filter((boss) => {
    if (activeTab === 'all') return true;
    return boss.region === activeTab;
  });

  return (
    <div style={{ maxWidth: '1100px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.5rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#f59e0b', fontWeight: 700, fontSize: '0.9rem', marginBottom: '0.4rem' }}>
          <Trophy size={18} />
          <span>Mural de Líderes, Insígnias & Estratégias</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          Chefes de Ginásio & Desafios Lendários
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Consulte as equipes completas, portraits originais dos líderes, níveis exatos e táticas recomendadas para superar cada ginásio de Kanto, Johto e o confronto supremo contra Red no Monte Silver.
        </p>
      </div>

      {/* Filter Tabs */}
      <div className="pills-scroll-bar">
        <button
          type="button"
          className={`filter-pill-btn ${activeTab === 'all' ? 'active' : ''}`}
          onClick={() => setActiveTab('all')}
        >
          Todos os 22 Chefes
        </button>
        <button
          type="button"
          className={`filter-pill-btn ${activeTab === 'kanto' ? 'active' : ''}`}
          onClick={() => setActiveTab('kanto')}
        >
          🔴 Kanto (8 Ginásios)
        </button>
        <button
          type="button"
          className={`filter-pill-btn ${activeTab === 'elite' ? 'active' : ''}`}
          onClick={() => setActiveTab('elite')}
        >
          ⭐ Elite dos Quatro & Campeão
        </button>
        <button
          type="button"
          className={`filter-pill-btn ${activeTab === 'johto' ? 'active' : ''}`}
          onClick={() => setActiveTab('johto')}
        >
          🔵 Johto (8 Ginásios)
        </button>
        <button
          type="button"
          className={`filter-pill-btn ${activeTab === 'red' ? 'active' : ''}`}
          onClick={() => setActiveTab('red')}
        >
          🏆 Monte Silver (Campeão Red)
        </button>
      </div>

      {/* Boss Cards Grid */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(min(100%, 450px), 1fr))', gap: '1.5rem' }}>
        {filteredBosses.map((boss) => (
          <div
            key={boss.id}
            id={`boss-${boss.id}`}
            className="card"
            style={{
              padding: '1.25rem',
              margin: 0,
              display: 'flex',
              flexDirection: 'column',
              scrollMarginTop: '80px',
              borderTop: boss.region === 'red' ? '3px solid #ef4444' : '3px solid #f59e0b'
            }}
          >
            {/* Top Info Header */}
            <div style={{ display: 'flex', gap: '1rem', alignItems: 'center', marginBottom: '1rem' }}>
              <div style={{
                width: '74px',
                height: '74px',
                borderRadius: 'var(--radius-md)',
                background: 'var(--bg-subtle)',
                border: '1px solid var(--border-color)',
                overflow: 'hidden',
                flexShrink: 0,
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center'
              }}>
                <img
                  src={boss.pic}
                  alt={boss.name}
                  style={{ width: '100%', height: '100%', objectFit: 'contain', imageRendering: 'pixelated' }}
                  onError={(e) => {
                    e.currentTarget.style.display = 'none';
                    e.currentTarget.parentElement.innerHTML = `<span style="font-size:2rem">${boss.badge_icon || '🥊'}</span>`;
                  }}
                  loading="lazy"
                />
              </div>

              <div style={{ flex: 1, minWidth: 0 }}>
                <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', flexWrap: 'wrap' }}>
                  <h3 style={{ fontSize: '1.25rem', fontWeight: 800 }}>{boss.name}</h3>
                  <span className="badge-pill" style={{ background: 'var(--accent-subtle)', color: 'var(--accent)', borderColor: 'rgba(245, 158, 11, 0.3)' }}>
                    {boss.badge_icon} {boss.badge}
                  </span>
                </div>
                <div style={{ fontSize: '0.85rem', color: 'var(--text-muted)', marginTop: '2px' }}>
                  {boss.city} • Tipo: <strong style={{ color: 'var(--text-heading)' }}>{boss.type}</strong>
                </div>
                <div style={{ fontSize: '0.78rem', color: 'var(--text-muted)', fontStyle: 'italic', marginTop: '2px' }}>
                  "{boss.title}"
                </div>
              </div>
            </div>

            {/* Team Showcase */}
            <div style={{
              background: 'var(--bg-subtle)',
              borderRadius: 'var(--radius-md)',
              padding: '0.75rem',
              marginBottom: '1rem',
              border: '1px solid var(--border-color)'
            }}>
              <div style={{ fontSize: '0.75rem', fontWeight: 700, textTransform: 'uppercase', color: 'var(--text-muted)', marginBottom: '0.5rem', display: 'flex', alignItems: 'center', gap: '0.3rem' }}>
                <Swords size={14} />
                <span>Formação da Equipe</span>
              </div>

              <div style={{ display: 'flex', gap: '0.5rem', flexWrap: 'wrap' }}>
                {boss.team.map((mon, idx) => (
                  <div
                    key={idx}
                    style={{
                      display: 'flex',
                      alignItems: 'center',
                      gap: '0.4rem',
                      background: 'var(--bg-card)',
                      padding: '4px 8px',
                      borderRadius: 'var(--radius-sm)',
                      border: '1px solid var(--border-color)'
                    }}
                  >
                    <img
                      src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${mon.num}.png`}
                      alt={mon.name}
                      style={{ width: '28px', height: '28px', imageRendering: 'pixelated' }}
                      loading="lazy"
                    />
                    <span style={{ fontSize: '0.82rem', fontWeight: 600, color: 'var(--text-heading)' }}>{mon.name}</span>
                    <span style={{ fontSize: '0.75rem', color: 'var(--accent)', fontWeight: 700 }}>Lv {mon.lvl}</span>
                  </div>
                ))}
              </div>
            </div>

            {/* Strategy */}
            <div style={{
              background: 'var(--bg-subtle)',
              borderLeft: '3px solid var(--secondary)',
              padding: '0.75rem 0.85rem',
              borderRadius: '0 var(--radius-sm) var(--radius-sm) 0',
              fontSize: '0.85rem',
              color: 'var(--text-main)',
              lineHeight: '1.5',
              marginTop: 'auto'
            }}>
              <strong style={{ color: 'var(--secondary)' }}>Estratégia Recomendada: </strong>
              {boss.strategy}
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
