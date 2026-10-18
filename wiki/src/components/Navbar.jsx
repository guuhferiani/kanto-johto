import React from 'react';
import { Menu, Search, Zap } from 'lucide-react';

export default function Navbar({ onOpenSearch, onToggleDrawer }) {
  return (
    <header className="top-navbar">
      <button 
        type="button"
        onClick={onToggleDrawer}
        aria-label="Abrir menu de navegação"
        style={{
          background: 'rgba(255, 255, 255, 0.06)',
          border: '1px solid var(--border-color)',
          color: '#fff',
          borderRadius: '10px',
          width: '40px',
          height: '40px',
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'center',
          cursor: 'pointer'
        }}
      >
        <Menu size={20} />
      </button>

      <div className="brand-title">
        <Zap size={18} color="#ef4444" fill="#ef4444" />
        <span>Kanto & Johto</span>
      </div>

      <button
        type="button"
        onClick={onOpenSearch}
        aria-label="Buscar na Wiki"
        style={{
          background: 'rgba(239, 68, 68, 0.12)',
          border: '1px solid rgba(239, 68, 68, 0.3)',
          color: '#ef4444',
          borderRadius: '10px',
          width: '40px',
          height: '40px',
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'center',
          cursor: 'pointer'
        }}
      >
        <Search size={18} />
      </button>
    </header>
  );
}
