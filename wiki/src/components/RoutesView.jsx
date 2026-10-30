import React, { useState, useMemo, useEffect } from 'react';
import { MapPin, Sun, Moon, Waves, Eye, Search, X, Sparkles, Filter, Compass } from 'lucide-react';
import { routesData } from '../data/routesData';
import chele3DImg from '../assets/chele/chele_3d.png';
import cheleFrontImg from '../assets/chele/front_transparent.png';

export default function RoutesView({ searchTargetRoute }) {
  const [filterQuery, setFilterQuery] = useState(searchTargetRoute || '');
  const [selectedRegion, setSelectedRegion] = useState('ALL'); // 'ALL' | 'Kanto' | 'Johto'
  const [selectedTime, setSelectedTime] = useState('ALL'); // 'ALL' | 'day' | 'night' | 'water' | 'hidden'

  useEffect(() => {
    if (searchTargetRoute) {
      setFilterQuery(searchTargetRoute);
    }
  }, [searchTargetRoute]);

  const cleanStr = (s) =>
    (s || '')
      .normalize('NFD')
      .replace(/[\u0300-\u036f]/g, '')
      .toLowerCase();

  const filteredRoutes = useMemo(() => {
    const q = cleanStr(filterQuery.trim());

    return routesData.filter((r) => {
      // 1. Region filter
      if (selectedRegion !== 'ALL' && r.region !== selectedRegion) {
        return false;
      }

      // 2. Time/Environment filter
      if (selectedTime === 'day' && (!r.day || r.day.length === 0)) return false;
      if (selectedTime === 'night' && (!r.night || r.night.length === 0)) return false;
      if (selectedTime === 'water' && (!r.water || r.water.length === 0)) return false;
      if (selectedTime === 'hidden' && (!r.hidden || r.hidden.length === 0)) return false;

      // 3. Search query
      if (!q) return true;

      const inName = cleanStr(r.name).includes(q);
      const inType = cleanStr(r.type).includes(q);
      const inRegion = cleanStr(r.region).includes(q);

      const monMatches = (m) => {
        const monName = typeof m === 'string' ? m : m.name;
        return cleanStr(monName).includes(q);
      };

      const inDay = r.day?.some(monMatches);
      const inNight = r.night?.some(monMatches);
      const inWater = r.water?.some(monMatches);
      const inHidden = r.hidden?.some(monMatches);

      return inName || inType || inRegion || inDay || inNight || inWater || inHidden;
    });
  }, [filterQuery, selectedRegion, selectedTime]);

  // Counts for tabs
  const kantoCount = useMemo(() => routesData.filter((r) => r.region === 'Kanto').length, []);
  const johtoCount = useMemo(() => routesData.filter((r) => r.region === 'Johto').length, []);

  // Helper component to render a Pokemon badge/chip
  const renderMonChip = (mon) => {
    const isObject = typeof mon === 'object' && mon !== null;
    const name = isObject ? mon.name : mon;
    const minLv = isObject ? mon.minLv : null;
    const maxLv = isObject ? mon.maxLv : null;
    const dexNum = isObject ? mon.dexNum : null;
    const isChele = isObject ? mon.isChele : (name.toLowerCase() === 'chele');

    const spriteSrc = isChele
      ? cheleFrontImg
      : (dexNum ? `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${dexNum}.png` : null);

    const lvText = minLv !== null
      ? (minLv === maxLv ? `Lv ${minLv}` : `Lv ${minLv}-${maxLv}`)
      : null;

    return (
      <div
        key={`${name}-${lvText}`}
        className="mon-chip"
        style={{
          display: 'inline-flex',
          alignItems: 'center',
          gap: '5px',
          background: isChele ? 'rgba(168, 85, 247, 0.15)' : 'rgba(255, 255, 255, 0.05)',
          border: isChele ? '1px solid rgba(168, 85, 247, 0.5)' : '1px solid var(--border-color)',
          borderRadius: '20px',
          padding: '2px 8px 2px 4px',
          fontSize: '0.8rem',
          boxShadow: isChele ? '0 0 10px rgba(168, 85, 247, 0.25)' : 'none',
          transition: 'transform 0.15s ease, background 0.15s ease'
        }}
      >
        {spriteSrc ? (
          <img
            src={spriteSrc}
            alt={name}
            style={{ width: '22px', height: '22px', objectFit: 'contain', imageRendering: 'pixelated' }}
            onError={(e) => {
              e.currentTarget.style.display = 'none';
            }}
          />
        ) : (
          <span style={{ width: '8px' }} />
        )}
        <span style={{ fontWeight: 600, color: isChele ? '#c084fc' : 'var(--text-heading)' }}>
          {name}
        </span>
        {isChele && <Sparkles size={12} color="#f59e0b" />}
        {lvText && (
          <span style={{
            fontSize: '0.7rem',
            color: 'var(--text-muted)',
            background: 'rgba(0, 0, 0, 0.25)',
            padding: '1px 5px',
            borderRadius: '6px'
          }}>
            {lvText}
          </span>
        )}
      </div>
    );
  };

  return (
    <div style={{ maxWidth: '1150px', margin: '0 auto', paddingBottom: '3rem' }}>
      {/* Header Banner */}
      <div style={{ marginBottom: '1.5rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#10b981', fontWeight: 700, fontSize: '0.85rem', marginBottom: '0.35rem' }}>
          <MapPin size={17} />
          <span>Enciclopédia Oficial de Rotas & Habitats Selvagens</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.6rem, 3.5vw, 2.3rem)', fontWeight: 800, marginBottom: '0.5rem', color: 'var(--text-heading)' }}>
          Rotas, Cavernas & Mares
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem', maxWidth: '850px' }}>
          Consulte com precisão matemática onde cada criatura aparece de <strong>Dia</strong>, de <strong>Noite</strong>, no <strong>Surfe / Pesca</strong> e na grama chacoalhante do <strong>DexNav</strong> com seus níveis e sprites.
        </p>
      </div>

      {/* Filter and Search Bar */}
      <div style={{
        background: 'var(--bg-card)',
        border: '1px solid var(--border-color)',
        borderRadius: 'var(--radius-lg)',
        padding: '1.25rem',
        marginBottom: '2rem',
        boxShadow: 'var(--shadow-sm)'
      }}>
        {/* Top line: Search and Clear */}
        <div style={{ display: 'flex', gap: '1rem', flexWrap: 'wrap', alignItems: 'center', marginBottom: '1rem' }}>
          <div style={{
            flex: '1 1 300px',
            position: 'relative',
            background: 'var(--bg-card-subtle)',
            border: '1px solid var(--border-color)',
            borderRadius: 'var(--radius-md)',
            display: 'flex',
            alignItems: 'center',
            padding: '0 0.85rem'
          }}>
            <Search size={18} color="var(--text-muted)" />
            <input
              type="text"
              value={filterQuery}
              onChange={(e) => setFilterQuery(e.target.value)}
              placeholder="Buscar por rota, cidade ou pokémon (ex: Rota 1, Pikachu, Chele, Dratini)..."
              style={{
                width: '100%',
                padding: '0.75rem 0.5rem',
                background: 'transparent',
                border: 'none',
                outline: 'none',
                color: 'var(--text-heading)',
                fontSize: '0.95rem',
                fontFamily: 'inherit'
              }}
            />
            {filterQuery && (
              <button
                type="button"
                onClick={() => setFilterQuery('')}
                style={{ background: 'transparent', border: 'none', color: 'var(--text-muted)', cursor: 'pointer', padding: '4px' }}
                title="Limpar busca"
              >
                <X size={16} />
              </button>
            )}
          </div>

          {(filterQuery || selectedRegion !== 'ALL' || selectedTime !== 'ALL') && (
            <button
              onClick={() => {
                setFilterQuery('');
                setSelectedRegion('ALL');
                setSelectedTime('ALL');
              }}
              className="btn btn-secondary"
              style={{ padding: '0.65rem 1rem', fontSize: '0.85rem' }}
            >
              Limpar Filtros
            </button>
          )}
        </div>

        {/* Second line: Region Tabs & Time Filters */}
        <div style={{ display: 'flex', gap: '1.25rem', flexWrap: 'wrap', alignItems: 'center', paddingTop: '0.5rem', borderTop: '1px solid rgba(255, 255, 255, 0.05)' }}>
          {/* Region Selector */}
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
            <span style={{ fontSize: '0.8rem', fontWeight: 700, color: 'var(--text-muted)', textTransform: 'uppercase' }}>
              Região:
            </span>
            <div style={{ display: 'inline-flex', background: 'rgba(0,0,0,0.2)', padding: '3px', borderRadius: '10px', gap: '3px' }}>
              <button
                onClick={() => setSelectedRegion('ALL')}
                style={{
                  padding: '4px 12px',
                  borderRadius: '7px',
                  border: 'none',
                  fontSize: '0.82rem',
                  fontWeight: 700,
                  cursor: 'pointer',
                  background: selectedRegion === 'ALL' ? 'var(--primary)' : 'transparent',
                  color: selectedRegion === 'ALL' ? '#fff' : 'var(--text-muted)'
                }}
              >
                Todas ({routesData.length})
              </button>
              <button
                onClick={() => setSelectedRegion('Kanto')}
                style={{
                  padding: '4px 12px',
                  borderRadius: '7px',
                  border: 'none',
                  fontSize: '0.82rem',
                  fontWeight: 700,
                  cursor: 'pointer',
                  background: selectedRegion === 'Kanto' ? '#ef4444' : 'transparent',
                  color: selectedRegion === 'Kanto' ? '#fff' : 'var(--text-muted)'
                }}
              >
                🔴 Kanto ({kantoCount})
              </button>
              <button
                onClick={() => setSelectedRegion('Johto')}
                style={{
                  padding: '4px 12px',
                  borderRadius: '7px',
                  border: 'none',
                  fontSize: '0.82rem',
                  fontWeight: 700,
                  cursor: 'pointer',
                  background: selectedRegion === 'Johto' ? '#3b82f6' : 'transparent',
                  color: selectedRegion === 'Johto' ? '#fff' : 'var(--text-muted)'
                }}
              >
                🔵 Johto ({johtoCount})
              </button>
            </div>
          </div>

          {/* Time/Environment Selector */}
          <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
            <span style={{ fontSize: '0.8rem', fontWeight: 700, color: 'var(--text-muted)', textTransform: 'uppercase' }}>
              Ambiente:
            </span>
            <div style={{ display: 'inline-flex', flexWrap: 'wrap', gap: '4px' }}>
              {[
                { id: 'ALL', label: 'Todos', icon: null },
                { id: 'day', label: 'Dia', icon: <Sun size={13} color="#f59e0b" /> },
                { id: 'night', label: 'Noite', icon: <Moon size={13} color="#818cf8" /> },
                { id: 'water', label: 'Surfe / Pesca', icon: <Waves size={13} color="#38bdf8" /> },
                { id: 'hidden', label: 'DexNav', icon: <Eye size={13} color="#ec4899" /> }
              ].map((t) => (
                <button
                  key={t.id}
                  onClick={() => setSelectedTime(t.id)}
                  style={{
                    display: 'inline-flex',
                    alignItems: 'center',
                    gap: '4px',
                    padding: '4px 10px',
                    borderRadius: '8px',
                    border: '1px solid var(--border-color)',
                    fontSize: '0.8rem',
                    fontWeight: 600,
                    cursor: 'pointer',
                    background: selectedTime === t.id ? 'rgba(255, 255, 255, 0.12)' : 'transparent',
                    color: selectedTime === t.id ? 'var(--text-heading)' : 'var(--text-muted)'
                  }}
                >
                  {t.icon}
                  <span>{t.label}</span>
                </button>
              ))}
            </div>
          </div>
        </div>
      </div>

      {/* Results Count and Empty State */}
      {filteredRoutes.length === 0 ? (
        <div style={{
          textAlign: 'center',
          padding: '4rem 1.5rem',
          background: 'var(--bg-card)',
          borderRadius: 'var(--radius-lg)',
          border: '1px dashed var(--border-color)'
        }}>
          <Compass size={40} color="var(--text-muted)" style={{ margin: '0 auto 1rem auto', opacity: 0.5 }} />
          <h3 style={{ fontSize: '1.2rem', fontWeight: 700, color: 'var(--text-heading)', marginBottom: '0.5rem' }}>
            Nenhuma rota ou pokémon encontrado!
          </h3>
          <p style={{ color: 'var(--text-muted)', fontSize: '0.9rem', marginBottom: '1.25rem' }}>
            Tente ajustar o termo digitado ou alternar os filtros de região e ambiente.
          </p>
          <button
            onClick={() => {
              setFilterQuery('');
              setSelectedRegion('ALL');
              setSelectedTime('ALL');
            }}
            className="btn btn-primary"
            style={{ padding: '0.6rem 1.25rem' }}
          >
            Ver Todas as 76 Rotas
          </button>
        </div>
      ) : (
        <>
          <div style={{ fontSize: '0.85rem', color: 'var(--text-muted)', marginBottom: '1rem', fontWeight: 600 }}>
            Exibindo <strong>{filteredRoutes.length}</strong> {filteredRoutes.length === 1 ? 'local' : 'locais de encontro'}:
          </div>

          {/* Routes Grid */}
          <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(min(100%, 520px), 1fr))', gap: '1.25rem' }}>
            {filteredRoutes.map((rt) => {
              const isKanto = rt.region === 'Kanto';

              return (
                <div
                  key={rt.mapId || rt.name}
                  className="card"
                  style={{
                    padding: '1.25rem',
                    margin: 0,
                    borderLeft: isKanto ? '4px solid #ef4444' : '4px solid #3b82f6',
                    display: 'flex',
                    flexDirection: 'column',
                    gap: '0.9rem'
                  }}
                >
                  {/* Card Header */}
                  <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'flex-start', gap: '0.5rem' }}>
                    <div>
                      <h3 style={{
                        fontSize: '1.15rem',
                        fontWeight: 800,
                        color: 'var(--text-heading)',
                        display: 'flex',
                        alignItems: 'center',
                        gap: '0.4rem',
                        marginBottom: '0.35rem'
                      }}>
                        <MapPin size={18} color={isKanto ? '#ef4444' : '#3b82f6'} />
                        <span>{rt.name}</span>
                      </h3>
                    </div>
                    <div style={{ display: 'flex', gap: '4px', flexWrap: 'wrap', justifyContent: 'flex-end' }}>
                      <span style={{
                        fontSize: '0.7rem',
                        fontWeight: 800,
                        padding: '2px 8px',
                        borderRadius: '6px',
                        background: isKanto ? 'rgba(239, 68, 68, 0.15)' : 'rgba(59, 130, 246, 0.15)',
                        color: isKanto ? '#f87171' : '#60a5fa',
                        border: isKanto ? '1px solid rgba(239, 68, 68, 0.3)' : '1px solid rgba(59, 130, 246, 0.3)'
                      }}>
                        {rt.region}
                      </span>
                      {rt.type && (
                        <span style={{
                          fontSize: '0.7rem',
                          fontWeight: 600,
                          padding: '2px 8px',
                          borderRadius: '6px',
                          background: 'rgba(255, 255, 255, 0.05)',
                          color: 'var(--text-muted)',
                          border: '1px solid var(--border-color)'
                        }}>
                          {rt.type}
                        </span>
                      )}
                    </div>
                  </div>

                  {/* Encounter Categories */}
                  <div style={{ display: 'flex', flexDirection: 'column', gap: '0.75rem', fontSize: '0.85rem' }}>
                    {/* Day */}
                    {rt.day && rt.day.length > 0 && (selectedTime === 'ALL' || selectedTime === 'day') && (
                      <div>
                        <div style={{ display: 'flex', alignItems: 'center', gap: '0.35rem', color: '#f59e0b', fontWeight: 700, fontSize: '0.8rem', marginBottom: '0.4rem' }}>
                          <Sun size={14} />
                          <span>DE DIA ({rt.day.length}):</span>
                        </div>
                        <div style={{ display: 'flex', flexWrap: 'wrap', gap: '6px' }}>
                          {rt.day.map((m) => renderMonChip(m))}
                        </div>
                      </div>
                    )}

                    {/* Night */}
                    {rt.night && rt.night.length > 0 && (selectedTime === 'ALL' || selectedTime === 'night') && (
                      <div>
                        <div style={{ display: 'flex', alignItems: 'center', gap: '0.35rem', color: '#818cf8', fontWeight: 700, fontSize: '0.8rem', marginBottom: '0.4rem' }}>
                          <Moon size={14} />
                          <span>DE NOITE ({rt.night.length}):</span>
                        </div>
                        <div style={{ display: 'flex', flexWrap: 'wrap', gap: '6px' }}>
                          {rt.night.map((m) => renderMonChip(m))}
                        </div>
                      </div>
                    )}

                    {/* Water / Fishing */}
                    {rt.water && rt.water.length > 0 && (selectedTime === 'ALL' || selectedTime === 'water') && (
                      <div>
                        <div style={{ display: 'flex', alignItems: 'center', gap: '0.35rem', color: '#38bdf8', fontWeight: 700, fontSize: '0.8rem', marginBottom: '0.4rem' }}>
                          <Waves size={14} />
                          <span>SURFE & PESCA ({rt.water.length}):</span>
                        </div>
                        <div style={{ display: 'flex', flexWrap: 'wrap', gap: '6px' }}>
                          {rt.water.map((m) => renderMonChip(m))}
                        </div>
                      </div>
                    )}

                    {/* DexNav */}
                    {rt.hidden && rt.hidden.length > 0 && (selectedTime === 'ALL' || selectedTime === 'hidden') && (
                      <div>
                        <div style={{ display: 'flex', alignItems: 'center', gap: '0.35rem', color: '#ec4899', fontWeight: 700, fontSize: '0.8rem', marginBottom: '0.4rem' }}>
                          <Eye size={14} />
                          <span>DEXNAV EXCLUSIVO ({rt.hidden.length}):</span>
                        </div>
                        <div style={{ display: 'flex', flexWrap: 'wrap', gap: '6px' }}>
                          {rt.hidden.map((m) => renderMonChip(m))}
                        </div>
                      </div>
                    )}
                  </div>
                </div>
              );
            })}
          </div>
        </>
      )}
    </div>
  );
}
