import React from 'react';
import { Menu, Search, Zap, Sun, Moon } from 'lucide-react';

export default function Navbar({ onOpenSearch, onToggleDrawer, theme, onToggleTheme }) {
  return (
    <header className="top-navbar">
      <div style={{ display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
        <button 
          type="button"
          onClick={onToggleDrawer}
          aria-label="Abrir menu de navegação"
          style={{
            background: 'var(--bg-subtle)',
            border: '1px solid var(--border-color)',
            color: 'var(--text-heading)',
            borderRadius: 'var(--radius-md)',
            width: '38px',
            height: '38px',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            cursor: 'pointer'
          }}
        >
          <Menu size={20} />
        </button>

        <div className="brand-title">
          <Zap size={18} color="var(--primary)" fill="var(--primary)" />
          <span>Kanto & Johto</span>
        </div>
      </div>

      <div style={{ display: 'flex', alignItems: 'center', gap: '0.4rem' }}>
        <button
          type="button"
          onClick={onToggleTheme}
          aria-label={theme === 'dark' ? 'Ativar modo claro' : 'Ativar modo escuro'}
          title={theme === 'dark' ? 'Modo Claro' : 'Modo Escuro'}
          style={{
            background: 'var(--bg-subtle)',
            border: '1px solid var(--border-color)',
            color: 'var(--text-heading)',
            borderRadius: 'var(--radius-md)',
            width: '38px',
            height: '38px',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            cursor: 'pointer'
          }}
        >
          {theme === 'dark' ? <Sun size={18} /> : <Moon size={18} />}
        </button>

        <button
          type="button"
          onClick={onOpenSearch}
          aria-label="Buscar na Wiki"
          style={{
            background: 'var(--primary-subtle)',
            border: '1px solid rgba(220, 38, 38, 0.25)',
            color: 'var(--primary)',
            borderRadius: 'var(--radius-md)',
            width: '38px',
            height: '38px',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            cursor: 'pointer'
          }}
        >
          <Search size={18} />
        </button>
      </div>
    </header>
  );
}
