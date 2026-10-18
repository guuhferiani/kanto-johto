import React, { useState, useMemo, useEffect } from 'react';
import { MapPin, Sun, Moon, Waves, Eye, Search, X } from 'lucide-react';
import { routesData } from '../data/routesData';

export default function RoutesView({ searchTargetRoute }) {
  const [filterQuery, setFilterQuery] = useState(searchTargetRoute || '');

  useEffect(() => {
    if (searchTargetRoute) {
      setFilterQuery(searchTargetRoute);
    }
  }, [searchTargetRoute]);

  const filteredRoutes = useMemo(() => {
    const q = filterQuery
      .trim()
      .normalize('NFD')
      .replace(/[\u0300-\u036f]/g, '')
      .toLowerCase();

    if (!q) return routesData;

    return routesData.filter((r) => {
      const cleanName = r.name
        .normalize('NFD')
        .replace(/[\u0300-\u036f]/g, '')
        .toLowerCase();
      const inName = cleanName.includes(q);
      const inDay = r.day?.some((m) =>
        m
          .normalize('NFD')
          .replace(/[\u0300-\u036f]/g, '')
          .toLowerCase()
          .includes(q)
      );
      const inNight = r.night?.some((m) =>
        m
          .normalize('NFD')
          .replace(/[\u0300-\u036f]/g, '')
          .toLowerCase()
          .includes(q)
      );
      const inWater = r.water?.some((m) =>
        m
          .normalize('NFD')
          .replace(/[\u0300-\u036f]/g, '')
          .toLowerCase()
          .includes(q)
      );
      const inHidden = r.hidden?.some((m) =>
        m
          .normalize('NFD')
          .replace(/[\u0300-\u036f]/g, '')
          .toLowerCase()
          .includes(q)
      );
      return inName || inDay || inNight || inWater || inHidden;
    });
  }, [filterQuery]);

  return (
    <div style={{ maxWidth: '1100px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.25rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#10b981', fontWeight: 700, fontSize: '0.9rem', marginBottom: '0.4rem' }}>
          <MapPin size={18} />
          <span>Extraído do Código-Fonte da ROM</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          Enciclopédia de Rotas, Cavernas & Mares
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Consulte onde cada criatura aparece de <strong>Dia</strong>, de <strong>Noite</strong>, no <strong>Surfe/Pesca</strong> e na grama chacoalhante do <strong>DexNav</strong>.
        </p>
      </div>

      {/* Search Input Bar */}
      <div style={{
        position: 'relative',
        maxWidth: '480px',
        background: 'rgba(255, 255, 255, 0.05)',
        border: '1px solid var(--border-color)',
        borderRadius: 'var(--radius-md)',
        display: 'flex',
        alignItems: 'center',
        padding: '0 0.85rem',
        marginBottom: '1.5rem'
      }}>
        <Search size={18} color="var(--text-muted)" />
        <input
          type="text"
          value={filterQuery}
          onChange={(e) => setFilterQuery(e.target.value)}
          placeholder="Buscar rota ou pokémon (ex: Route1 ou Pikachu)..."
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
        {filterQuery && (
          <button
            type="button"
            onClick={() => setFilterQuery('')}
            style={{ background: 'transparent', border: 'none', color: 'var(--text-muted)', cursor: 'pointer' }}
          >
            <X size={16} />
          </button>
        )}
      </div>

      {/* Routes Grid */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(min(100%, 480px), 1fr))', gap: '1.25rem' }}>
        {filteredRoutes.map((rt) => (
          <div
            key={rt.name}
            className="card"
            style={{ padding: '1.25rem', margin: 0, borderLeft: '4px solid #10b981' }}
          >
            <h3 style={{ fontSize: '1.15rem', fontWeight: 800, marginBottom: '0.75rem', color: '#fff', display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
              <MapPin size={18} color="#10b981" />
              <span>{rt.name}</span>
            </h3>

            <div style={{ display: 'flex', flexDirection: 'column', gap: '0.65rem', fontSize: '0.85rem' }}>
              {/* Day */}
              {rt.day && rt.day.length > 0 && (
                <div style={{ display: 'flex', gap: '0.5rem', alignItems: 'flex-start' }}>
                  <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.25rem', color: '#f59e0b', fontWeight: 700, minWidth: '70px', paddingTop: '2px' }}>
                    <Sun size={14} />
                    <span>Dia:</span>
                  </div>
                  <div style={{ color: '#cbd5e1', lineHeight: '1.4' }}>
                    {rt.day.join(', ')}
                  </div>
                </div>
              )}

              {/* Night */}
              {rt.night && rt.night.length > 0 && (
                <div style={{ display: 'flex', gap: '0.5rem', alignItems: 'flex-start' }}>
                  <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.25rem', color: '#818cf8', fontWeight: 700, minWidth: '70px', paddingTop: '2px' }}>
                    <Moon size={14} />
                    <span>Noite:</span>
                  </div>
                  <div style={{ color: '#cbd5e1', lineHeight: '1.4' }}>
                    {rt.night.join(', ')}
                  </div>
                </div>
              )}

              {/* Water */}
              {rt.water && rt.water.length > 0 && (
                <div style={{ display: 'flex', gap: '0.5rem', alignItems: 'flex-start' }}>
                  <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.25rem', color: '#38bdf8', fontWeight: 700, minWidth: '70px', paddingTop: '2px' }}>
                    <Waves size={14} />
                    <span>Água:</span>
                  </div>
                  <div style={{ color: '#cbd5e1', lineHeight: '1.4' }}>
                    {rt.water.join(', ')}
                  </div>
                </div>
              )}

              {/* DexNav */}
              {rt.hidden && rt.hidden.length > 0 && (
                <div style={{ display: 'flex', gap: '0.5rem', alignItems: 'flex-start' }}>
                  <div style={{ display: 'inline-flex', alignItems: 'center', gap: '0.25rem', color: '#ec4899', fontWeight: 700, minWidth: '70px', paddingTop: '2px' }}>
                    <Eye size={14} />
                    <span>DexNav:</span>
                  </div>
                  <div style={{ color: '#cbd5e1', lineHeight: '1.4' }}>
                    {rt.hidden.join(', ')}
                  </div>
                </div>
              )}
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
