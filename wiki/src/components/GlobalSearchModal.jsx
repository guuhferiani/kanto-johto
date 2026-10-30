import React, { useState, useEffect, useRef, useMemo } from 'react';
import { Search, X, BookOpen, Trophy, Compass, MapPin, Gift, ChevronRight, Zap } from 'lucide-react';
import { pokedexData } from '../data/pokedexData';
import { gymBossesData } from '../data/gymBossesData';
import { kantoChapters, johtoChapters } from '../data/walkthroughData';
import { routesData } from '../data/routesData';
import { hmsData, tmsData, stonesData } from '../data/itemsData';
import chele3DImg from '../assets/chele/chele_3d.png';

function cleanStr(s) {
  if (!s) return '';
  return s
    .toString()
    .normalize('NFD')
    .replace(/[\u0300-\u036f]/g, '')
    .toLowerCase();
}

export default function GlobalSearchModal({ isOpen, onClose, onNavigate }) {
  const [query, setQuery] = useState('');
  const inputRef = useRef(null);

  useEffect(() => {
    if (isOpen) {
      setTimeout(() => {
        inputRef.current?.focus();
      }, 50);
    } else {
      setQuery('');
    }
  }, [isOpen]);

  // Handle Escape key
  useEffect(() => {
    const handleKeyDown = (e) => {
      if (e.key === 'Escape' && isOpen) {
        onClose();
      }
      if ((e.ctrlKey || e.metaKey) && e.key === 'k') {
        e.preventDefault();
        if (isOpen) onClose();
        else onNavigate(null);
      }
    };
    window.addEventListener('keydown', handleKeyDown);
    return () => window.removeEventListener('keydown', handleKeyDown);
  }, [isOpen, onClose, onNavigate]);

  const results = useMemo(() => {
    const q = cleanStr(query.trim());
    if (!q || q.length < 2) return null;

    // 1. Pokédex Matches
    const pokemon = pokedexData
      .filter((p) => {
        return (
          cleanStr(p.name).includes(q) ||
          p.num.toString() === q ||
          p.type.some((t) => cleanStr(t).includes(q)) ||
          cleanStr(p.evo).includes(q)
        );
      })
      .slice(0, 6);

    // 2. Bosses Matches
    const bosses = gymBossesData
      .filter((b) => {
        return (
          cleanStr(b.name).includes(q) ||
          cleanStr(b.city).includes(q) ||
          cleanStr(b.badge).includes(q) ||
          cleanStr(b.type).includes(q) ||
          cleanStr(b.strategy).includes(q) ||
          b.team.some((t) => cleanStr(t.name).includes(q))
        );
      })
      .slice(0, 5);

    // 3. Walkthrough Chapters (Kanto & Johto)
    const kanto = kantoChapters
      .filter((c) => {
        const inTitle = cleanStr(c.title).includes(q);
        const inSub = cleanStr(c.subtitle).includes(q);
        const inBadges = c.badges.some((b) => cleanStr(b.text).includes(q));
        const inContent = c.content.some(
          (item) => cleanStr(item.heading).includes(q) || cleanStr(item.text).includes(q)
        );
        const inProTip = cleanStr(c.proTip).includes(q);
        return inTitle || inSub || inBadges || inContent || inProTip;
      })
      .map((c) => ({ ...c, region: 'kanto' }));

    const johto = johtoChapters
      .filter((c) => {
        const inTitle = cleanStr(c.title).includes(q);
        const inSub = cleanStr(c.subtitle).includes(q);
        const inBadges = c.badges.some((b) => cleanStr(b.text).includes(q));
        const inContent = c.content.some(
          (item) => cleanStr(item.heading).includes(q) || cleanStr(item.text).includes(q)
        );
        return inTitle || inSub || inBadges || inContent;
      })
      .map((c) => ({ ...c, region: 'johto' }));

    const chapters = [...kanto, ...johto].slice(0, 5);

    // 4. Routes Matches
    const routes = routesData
      .filter((r) => {
        const inName = cleanStr(r.name).includes(q);
        const inDay = r.day?.some((m) => cleanStr(m).includes(q));
        const inNight = r.night?.some((m) => cleanStr(m).includes(q));
        const inWater = r.water?.some((m) => cleanStr(m).includes(q));
        const inHidden = r.hidden?.some((m) => cleanStr(m).includes(q));
        return inName || inDay || inNight || inWater || inHidden;
      })
      .slice(0, 5);

    // 5. Items / TMs Matches
    const items = [
      ...hmsData.filter((h) => cleanStr(h.hm).includes(q) || cleanStr(h.name).includes(q) || cleanStr(h.location).includes(q)),
      ...tmsData.filter((t) => cleanStr(t.tm).includes(q) || cleanStr(t.name).includes(q) || cleanStr(t.location).includes(q)),
      ...stonesData.filter((s) => cleanStr(s.name).includes(q) || cleanStr(s.use).includes(q))
    ].slice(0, 5);

    return { pokemon, bosses, chapters, routes, items };
  }, [query]);

  if (!isOpen) return null;

  const totalResults = results
    ? results.pokemon.length +
      results.bosses.length +
      results.chapters.length +
      results.routes.length +
      results.items.length
    : 0;

  return (
    <div 
      className="spotlight-overlay"
      onClick={(e) => {
        if (e.target === e.currentTarget) onClose();
      }}
    >
      <div className="spotlight-modal">
        {/* Search Input Bar */}
        <div style={{
          display: 'flex',
          alignItems: 'center',
          gap: '0.75rem',
          padding: '1rem 1.25rem',
          borderBottom: '1px solid var(--border-color)',
          background: 'var(--bg-subtle)'
        }}>
          <Search size={20} color="var(--primary)" />
          <input
            ref={inputRef}
            type="text"
            value={query}
            onChange={(e) => setQuery(e.target.value)}
            placeholder="Pesquise por Pokémon, Líder, Rota, TM, Pikachu..."
            style={{
              flex: 1,
              background: 'transparent',
              border: 'none',
              outline: 'none',
              color: 'var(--text-heading)',
              fontSize: '1rem',
              fontFamily: 'inherit'
            }}
          />
          {query && (
            <button
              type="button"
              onClick={() => setQuery('')}
              style={{
                background: 'transparent',
                border: 'none',
                color: 'var(--text-muted)',
                cursor: 'pointer',
                padding: '4px'
              }}
            >
              <X size={18} />
            </button>
          )}
          <button
            type="button"
            onClick={onClose}
            className="kbd-shortcut"
            style={{
              border: '1px solid var(--border-color)',
              cursor: 'pointer'
            }}
          >
            ESC
          </button>
        </div>

        {/* Results Container */}
        <div style={{ maxHeight: '65vh', overflowY: 'auto', padding: '1rem' }}>
          {!query.trim() && (
            <div style={{ textAlign: 'center', padding: '2rem 1rem', color: 'var(--text-muted)' }}>
              <Zap size={30} color="var(--accent)" style={{ margin: '0 auto 0.75rem auto', opacity: 0.9 }} />
              <p style={{ fontWeight: 700, color: 'var(--text-heading)', marginBottom: '0.25rem' }}>
                Filtro Global Inteligente em Tempo Real
              </p>
              <p style={{ fontSize: '0.85rem' }}>
                Digite o nome de qualquer Pokémon, Chefe de Ginásio, Capítulo do Detonado, Rota ou TM!
              </p>
              <div style={{ display: 'flex', gap: '0.5rem', justifyContent: 'center', flexWrap: 'wrap', marginTop: '1rem' }}>
                {['Chele', 'Pikachu', 'Bulbasaur', 'Brock', 'Squirtle', 'Misty', 'Surge', 'Monte Silver'].map((sug) => (
                  <button
                    key={sug}
                    type="button"
                    onClick={() => setQuery(sug)}
                    className="filter-pill-btn"
                  >
                    {sug}
                  </button>
                ))}
              </div>
            </div>
          )}

          {query.trim().length > 0 && query.trim().length < 2 && (
            <div style={{ textAlign: 'center', padding: '2rem 1rem', color: 'var(--text-muted)', fontSize: '0.9rem' }}>
              Digite ao menos 2 caracteres para iniciar a busca...
            </div>
          )}

          {results && totalResults === 0 && (
            <div style={{ textAlign: 'center', padding: '2.5rem 1rem', color: 'var(--text-muted)' }}>
              <p style={{ fontSize: '1rem', fontWeight: 600, color: 'var(--text-heading)', marginBottom: '0.25rem' }}>
                Nenhum resultado encontrado para "{query}"
              </p>
              <p style={{ fontSize: '0.85rem' }}>
                Verifique se digitou o nome correto ou tente termos mais curtos.
              </p>
            </div>
          )}

          {results && totalResults > 0 && (
            <div style={{ display: 'flex', flexDirection: 'column', gap: '1.25rem' }}>
              {/* Pokemon Results */}
              {results.pokemon.length > 0 && (
                <div>
                  <div style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: '0.5rem',
                    fontSize: '0.8rem',
                    fontWeight: 700,
                    textTransform: 'uppercase',
                    color: 'var(--primary)',
                    marginBottom: '0.5rem'
                  }}>
                    <BookOpen size={14} />
                    <span>Pokédex ({results.pokemon.length})</span>
                  </div>
                  <div style={{ display: 'flex', flexDirection: 'column', gap: '4px' }}>
                    {results.pokemon.map((mon) => (
                      <div
                        key={mon.num}
                        onClick={() => {
                          onNavigate('pokedex', mon.name);
                          onClose();
                        }}
                        className="search-modal-item"
                      >
                        <img
                          src={mon.customSprite ? chele3DImg : `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${mon.num}.png`}
                          alt={mon.name}
                          style={{ width: '38px', height: '38px', imageRendering: 'pixelated' }}
                          loading="lazy"
                        />
                        <div style={{ flex: 1, minWidth: 0 }}>
                          <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
                            <span className="search-modal-item-title">
                              #{mon.num.toString().padStart(3, '0')} {mon.name}
                            </span>
                            <div style={{ display: 'flex', gap: '4px' }}>
                              {mon.type.map((t) => (
                                <span key={t} className={`type-badge type-${t}`} style={{ fontSize: '0.65rem', padding: '1px 5px' }}>
                                  {t}
                                </span>
                              ))}
                            </div>
                          </div>
                          <span style={{ fontSize: '0.75rem', color: 'var(--text-muted)' }}>
                            {mon.evo}
                          </span>
                        </div>
                        <ChevronRight size={16} color="var(--text-muted)" />
                      </div>
                    ))}
                  </div>
                </div>
              )}

              {/* Bosses Results */}
              {results.bosses.length > 0 && (
                <div>
                  <div style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: '0.5rem',
                    fontSize: '0.8rem',
                    fontWeight: 700,
                    textTransform: 'uppercase',
                    color: 'var(--accent)',
                    marginBottom: '0.5rem'
                  }}>
                    <Trophy size={14} />
                    <span>Líderes de Ginásio & Chefes ({results.bosses.length})</span>
                  </div>
                  <div style={{ display: 'flex', flexDirection: 'column', gap: '4px' }}>
                    {results.bosses.map((boss) => (
                      <div
                        key={boss.id}
                        onClick={() => {
                          onNavigate('gyms', boss.id);
                          onClose();
                        }}
                        className="search-modal-item"
                      >
                        <div style={{
                          width: '38px',
                          height: '38px',
                          borderRadius: '8px',
                          background: 'var(--bg-card)',
                          display: 'flex',
                          alignItems: 'center',
                          justifyContent: 'center',
                          fontSize: '1.2rem',
                          border: '1px solid var(--border-color)'
                        }}>
                          {boss.badge_icon || '🥊'}
                        </div>
                        <div style={{ flex: 1, minWidth: 0 }}>
                          <div style={{ display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
                            <span className="search-modal-item-title">
                              {boss.name}
                            </span>
                            <span style={{ fontSize: '0.75rem', color: 'var(--accent)', fontWeight: 600 }}>
                              • {boss.city} ({boss.badge})
                            </span>
                          </div>
                          <span style={{ fontSize: '0.75rem', color: 'var(--text-muted)' }}>
                            Time: {boss.team.map((t) => `${t.name} (Lv ${t.lvl})`).join(', ')}
                          </span>
                        </div>
                        <ChevronRight size={16} color="var(--text-muted)" />
                      </div>
                    ))}
                  </div>
                </div>
              )}

              {/* Detonado Chapters */}
              {results.chapters.length > 0 && (
                <div>
                  <div style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: '0.5rem',
                    fontSize: '0.8rem',
                    fontWeight: 700,
                    textTransform: 'uppercase',
                    color: 'var(--secondary)',
                    marginBottom: '0.5rem'
                  }}>
                    <Compass size={14} />
                    <span>Detonado & História ({results.chapters.length})</span>
                  </div>
                  <div style={{ display: 'flex', flexDirection: 'column', gap: '4px' }}>
                    {results.chapters.map((chap) => (
                      <div
                        key={chap.id}
                        onClick={() => {
                          onNavigate(chap.region, chap.id);
                          onClose();
                        }}
                        className="search-modal-item"
                      >
                        <div style={{
                          width: '38px',
                          height: '38px',
                          borderRadius: '8px',
                          background: chap.region === 'kanto' ? 'var(--primary-subtle)' : 'rgba(37, 99, 235, 0.12)',
                          color: chap.region === 'kanto' ? 'var(--primary)' : 'var(--secondary)',
                          display: 'flex',
                          alignItems: 'center',
                          justifyContent: 'center',
                          fontWeight: 800,
                          fontSize: '0.85rem',
                          border: '1px solid var(--border-color)'
                        }}>
                          {chap.region === 'kanto' ? `K${chap.num}` : `J${chap.num}`}
                        </div>
                        <div style={{ flex: 1, minWidth: 0 }}>
                          <span className="search-modal-item-title" style={{ display: 'block' }}>
                            {chap.title}
                          </span>
                          <span style={{ fontSize: '0.75rem', color: 'var(--text-muted)' }}>
                            {chap.subtitle}
                          </span>
                        </div>
                        <ChevronRight size={16} color="var(--text-muted)" />
                      </div>
                    ))}
                  </div>
                </div>
              )}

              {/* Routes & Encounters */}
              {results.routes.length > 0 && (
                <div>
                  <div style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: '0.5rem',
                    fontSize: '0.8rem',
                    fontWeight: 700,
                    textTransform: 'uppercase',
                    color: '#10b981',
                    marginBottom: '0.5rem'
                  }}>
                    <MapPin size={14} />
                    <span>Rotas & Encontros ({results.routes.length})</span>
                  </div>
                  <div style={{ display: 'flex', flexDirection: 'column', gap: '4px' }}>
                    {results.routes.map((rt) => (
                      <div
                        key={rt.name}
                        onClick={() => {
                          onNavigate('routes', rt.name);
                          onClose();
                        }}
                        className="search-modal-item"
                      >
                        <div style={{ flex: 1, minWidth: 0 }}>
                          <span className="search-modal-item-title" style={{ display: 'block' }}>
                            {rt.name}
                          </span>
                          <span style={{ fontSize: '0.75rem', color: 'var(--text-muted)' }}>
                            Dia: {rt.day?.slice(0, 3).join(', ') || 'Nenhum'} | Água: {rt.water?.slice(0, 2).join(', ') || 'Nenhum'}
                          </span>
                        </div>
                        <ChevronRight size={16} color="var(--text-muted)" />
                      </div>
                    ))}
                  </div>
                </div>
              )}

              {/* Items & TMs */}
              {results.items.length > 0 && (
                <div>
                  <div style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: '0.5rem',
                    fontSize: '0.8rem',
                    fontWeight: 700,
                    textTransform: 'uppercase',
                    color: 'var(--primary)',
                    marginBottom: '0.5rem'
                  }}>
                    <Gift size={14} />
                    <span>TMs, HMs & Itens ({results.items.length})</span>
                  </div>
                  <div style={{ display: 'flex', flexDirection: 'column', gap: '4px' }}>
                    {results.items.map((item, idx) => (
                      <div
                        key={idx}
                        onClick={() => {
                          onNavigate('items');
                          onClose();
                        }}
                        className="search-modal-item"
                      >
                        <div style={{ flex: 1, minWidth: 0 }}>
                          <span className="search-modal-item-title" style={{ display: 'block' }}>
                            {item.hm || item.tm || item.icon} {item.name}
                          </span>
                          <span style={{ fontSize: '0.75rem', color: 'var(--text-muted)' }}>
                            {item.location || item.use}
                          </span>
                        </div>
                        <ChevronRight size={16} color="var(--text-muted)" />
                      </div>
                    ))}
                  </div>
                </div>
              )}
            </div>
          )}
        </div>
      </div>
    </div>
  );
}
