import React, { useState, useEffect } from 'react';
import { Compass, Sparkles, AlertCircle, ChevronRight, Zap, CheckCircle2 } from 'lucide-react';
import { kantoChapters, johtoChapters } from '../data/walkthroughData';

export default function WalkthroughView({ region = 'kanto', highlightChapterId }) {
  const [selectedRegion, setSelectedRegion] = useState(region);

  useEffect(() => {
    setSelectedRegion(region);
  }, [region]);

  useEffect(() => {
    if (highlightChapterId) {
      setTimeout(() => {
        const el = document.getElementById(highlightChapterId);
        if (el) {
          el.scrollIntoView({ behavior: 'smooth', block: 'start' });
        }
      }, 100);
    }
  }, [highlightChapterId]);

  const chapters = selectedRegion === 'kanto' ? kantoChapters : johtoChapters;

  const scrollToChapter = (id) => {
    const el = document.getElementById(id);
    if (el) {
      el.scrollIntoView({ behavior: 'smooth', block: 'start' });
    }
  };

  return (
    <div style={{ maxWidth: '1000px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.5rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: selectedRegion === 'kanto' ? '#ef4444' : '#3b82f6', fontWeight: 700, fontSize: '0.9rem', marginBottom: '0.4rem' }}>
          {selectedRegion === 'kanto' ? <Compass size={18} /> : <Sparkles size={18} />}
          <span>{selectedRegion === 'kanto' ? 'Jornada Principal — Kanto Clássico' : 'Expansão Pós-Game — Região de Johto'}</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          {selectedRegion === 'kanto' ? 'Detonado Completo de Kanto (Versão Yellow)' : 'Detonado Completo de Johto & Monte Silver'}
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          {selectedRegion === 'kanto'
            ? 'Guia passo a passo 100% atualizado para a nossa ROM! Comece exclusivamente com o Pikachu Parceiro, obtenha os 3 iniciais por presente e vença as 8 insígnias.'
            : 'Atravesse no S.S. Aqua, enfrente os 8 novos ginásios em níveis avançados (55 a 85), desperte os cães lendários e chegue ao cume nevado do Monte Silver para desafiar Red!'}
        </p>
      </div>

      {/* Region Switcher Pills */}
      <div style={{ display: 'flex', gap: '0.5rem', marginBottom: '1.25rem' }}>
        <button
          type="button"
          onClick={() => setSelectedRegion('kanto')}
          className={`filter-pill-btn ${selectedRegion === 'kanto' ? 'active' : ''}`}
          style={{ fontSize: '0.9rem', padding: '0.5rem 1.2rem' }}
        >
          🔴 Kanto (Início com Pikachu)
        </button>
        <button
          type="button"
          onClick={() => setSelectedRegion('johto')}
          className={`filter-pill-btn ${selectedRegion === 'johto' ? 'active' : ''}`}
          style={{ fontSize: '0.9rem', padding: '0.5rem 1.2rem' }}
        >
          🔵 Johto (Pós-Game & Red)
        </button>
      </div>

      {/* Chapter Jump Bar */}
      <div className="pills-scroll-bar">
        {chapters.map((chap) => (
          <button
            key={chap.id}
            type="button"
            className="filter-pill-btn"
            onClick={() => scrollToChapter(chap.id)}
          >
            {selectedRegion === 'kanto' ? `Cap. ${chap.num}` : `Fase ${chap.num}`}: {chap.title.split('&')[0].split(':')[0]}
          </button>
        ))}
      </div>

      {/* Chapters Content */}
      <div style={{ display: 'flex', flexDirection: 'column', gap: '2rem' }}>
        {chapters.map((chap) => (
          <article
            key={chap.id}
            id={chap.id}
            className="card"
            style={{
              padding: '1.5rem',
              borderTop: '3px solid #ef4444',
              scrollMarginTop: '80px'
            }}
          >
            {/* City Hero Banner if present */}
            {chap.banner && (
              <div className="city-hero-box">
                <img
                  src={chap.banner}
                  alt={chap.title}
                  className="city-hero-img"
                  loading="lazy"
                />
                <div className="city-hero-overlay">
                  <div>
                    <span style={{ fontSize: '0.8rem', fontWeight: 800, textTransform: 'uppercase', color: '#fca5a5', letterSpacing: '1px' }}>
                      {selectedRegion === 'kanto' ? `Capítulo ${chap.num}` : `Fase ${chap.num}`}
                    </span>
                    <h2 style={{ fontSize: '1.4rem', fontWeight: 800, color: '#fff', textShadow: '0 2px 4px rgba(0,0,0,0.8)' }}>
                      {chap.title}
                    </h2>
                  </div>
                </div>
              </div>
            )}

            {/* Chapter Header without Banner */}
            {!chap.banner && (
              <div style={{ marginBottom: '1.25rem', borderBottom: '1px solid var(--border-color)', paddingBottom: '0.75rem' }}>
                <span style={{ fontSize: '0.8rem', fontWeight: 800, textTransform: 'uppercase', color: '#ef4444', letterSpacing: '1px' }}>
                  {selectedRegion === 'kanto' ? `Capítulo ${chap.num}` : `Fase ${chap.num}`}
                </span>
                <h2 style={{ fontSize: '1.4rem', fontWeight: 800, marginTop: '2px' }}>
                  {chap.title}
                </h2>
                <p style={{ color: 'var(--text-muted)', fontSize: '0.88rem' }}>
                  {chap.subtitle}
                </p>
              </div>
            )}

            {/* Badges / POI Highlights */}
            {chap.badges && chap.badges.length > 0 && (
              <div style={{ display: 'flex', gap: '0.5rem', flexWrap: 'wrap', marginBottom: '1.25rem' }}>
                {chap.badges.map((b, idx) => (
                  <span key={idx} className="badge-pill">
                    {b.text}
                  </span>
                ))}
              </div>
            )}

            {/* Steps / Subsections */}
            <div style={{ display: 'flex', flexDirection: 'column', gap: '1rem' }}>
              {chap.content.map((item, idx) => (
                <div 
                  key={idx}
                  style={{
                    background: 'rgba(255, 255, 255, 0.02)',
                    padding: '1rem',
                    borderRadius: 'var(--radius-md)',
                    border: '1px solid rgba(255, 255, 255, 0.05)'
                  }}
                >
                  <h3 style={{ fontSize: '1.05rem', fontWeight: 700, color: '#f1f5f9', marginBottom: '0.4rem', display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
                    <CheckCircle2 size={16} color="#10b981" />
                    <span>{item.heading}</span>
                  </h3>
                  <div
                    style={{ color: 'var(--text-muted)', fontSize: '0.92rem', lineHeight: '1.6' }}
                    dangerouslySetInnerHTML={{ __html: item.text }}
                  />
                </div>
              ))}
            </div>

            {/* Pro-Tip Box */}
            {chap.proTip && (
              <div className="pro-tip-box">
                <div style={{ display: 'flex', alignItems: 'center', gap: '0.4rem', fontWeight: 700, color: '#f59e0b', marginBottom: '0.25rem' }}>
                  <AlertCircle size={16} />
                  <span>Dica de Mestre</span>
                </div>
                <div>{chap.proTip}</div>
              </div>
            )}
          </article>
        ))}
      </div>
    </div>
  );
}
