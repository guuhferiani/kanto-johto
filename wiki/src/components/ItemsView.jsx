import React from 'react';
import { Gift, Sparkles, Zap, ShieldAlert } from 'lucide-react';
import { hmsData, tmsData, stonesData } from '../data/itemsData';

export default function ItemsView() {
  return (
    <div style={{ maxWidth: '1000px', margin: '0 auto' }}>
      {/* Header */}
      <div style={{ marginBottom: '1.5rem' }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', color: '#8b5cf6', fontWeight: 700, fontSize: '0.9rem', marginBottom: '0.4rem' }}>
          <Gift size={18} />
          <span>Máquinas Técnicas, Ocultas & Pedras</span>
        </div>
        <h1 style={{ fontSize: 'clamp(1.5rem, 3.5vw, 2.25rem)', fontWeight: 800, marginBottom: '0.5rem' }}>
          Localização de TMs, HMs & Itens Especiais
        </h1>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.95rem' }}>
          Nesta ROM, os <strong>TMs são infinitos e reutilizáveis</strong>! Ensine golpes poderosos para quantos Pokémon quiser sem receio de gastar o item.
        </p>
      </div>

      {/* HMs Table Card */}
      <div className="card" style={{ borderTop: '3px solid #3b82f6' }}>
        <h2 style={{ fontSize: '1.25rem', fontWeight: 800, marginBottom: '0.5rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
          <Sparkles size={20} color="#3b82f6" />
          <span>Máquinas Ocultas (HMs)</span>
        </h2>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.88rem', marginBottom: '1rem' }}>
          Para usar Cortar ou Força no mapa, você só precisa da insígnia correspondente e ficar de frente apertando o botão 'A'.
        </p>

        <div className="table-responsive">
          <table className="custom-table">
            <thead>
              <tr>
                <th>HM</th>
                <th>Movimento</th>
                <th>Tipo</th>
                <th>Local de Obtenção</th>
                <th>Insígnia Requerida</th>
              </tr>
            </thead>
            <tbody>
              {hmsData.map((h) => (
                <tr key={h.hm}>
                  <td><strong style={{ color: '#60a5fa' }}>{h.hm}</strong></td>
                  <td><strong>{h.name}</strong></td>
                  <td><span className={`type-badge type-${h.type}`}>{h.type}</span></td>
                  <td>{h.location}</td>
                  <td><span style={{ color: '#f59e0b', fontWeight: 600 }}>{h.badge}</span></td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>

      {/* TMs Table Card */}
      <div className="card" style={{ borderTop: '3px solid #8b5cf6' }}>
        <h2 style={{ fontSize: '1.25rem', fontWeight: 800, marginBottom: '0.5rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
          <Zap size={20} color="#8b5cf6" />
          <span>TMs Essenciais & Melhores Golpes</span>
        </h2>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.88rem', marginBottom: '1rem' }}>
          Os melhores golpes ofensivos de cada tipo para montar seu time competitivo.
        </p>

        <div className="table-responsive">
          <table className="custom-table">
            <thead>
              <tr>
                <th>TM</th>
                <th>Golpe</th>
                <th>Tipo</th>
                <th>Poder / Precisão</th>
                <th>Onde Encontrar</th>
              </tr>
            </thead>
            <tbody>
              {tmsData.map((t) => (
                <tr key={t.tm}>
                  <td><strong style={{ color: '#c084fc' }}>{t.tm}</strong></td>
                  <td><strong>{t.name}</strong></td>
                  <td><span className={`type-badge type-${t.type}`}>{t.type}</span></td>
                  <td>{t.pwr} / {t.acc}</td>
                  <td>{t.location}</td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>

      {/* Evolution Stones Card */}
      <div className="card" style={{ borderTop: '3px solid #f59e0b' }}>
        <h2 style={{ fontSize: '1.25rem', fontWeight: 800, marginBottom: '0.5rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
          <span style={{ fontSize: '1.3rem' }}>🌙</span>
          <span>Pedras Evolutivas</span>
        </h2>
        <p style={{ color: 'var(--text-muted)', fontSize: '0.88rem', marginBottom: '1rem' }}>
          Disponíveis no 4º andar da Loja de Departamentos de Celadon City.
        </p>

        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(min(100%, 280px), 1fr))', gap: '1rem' }}>
          {stonesData.map((s, idx) => (
            <div
              key={idx}
              style={{
                background: 'rgba(255, 255, 255, 0.03)',
                padding: '1rem',
                borderRadius: 'var(--radius-md)',
                border: '1px solid var(--border-color)'
              }}
            >
              <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem', marginBottom: '0.4rem', fontWeight: 700, color: '#fde68a' }}>
                <span style={{ fontSize: '1.2rem' }}>{s.icon}</span>
                <span>{s.name}</span>
              </div>
              <p style={{ fontSize: '0.85rem', color: '#cbd5e1', marginBottom: '0.4rem' }}>
                {s.use}
              </p>
              <div style={{ fontSize: '0.78rem', color: 'var(--text-muted)' }}>
                <strong>Onde achar:</strong> {s.location}
              </div>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}
