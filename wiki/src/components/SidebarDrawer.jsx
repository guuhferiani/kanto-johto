import React from 'react';
import { 
  Home, 
  Compass, 
  Sparkles, 
  Trophy, 
  BookOpen, 
  MapPin, 
  Gift, 
  Gamepad2, 
  Search, 
  X, 
  Zap,
  Download,
  Code2,
  Sun,
  Moon
} from 'lucide-react';

export default function SidebarDrawer({ 
  isOpen, 
  onClose, 
  activeTab, 
  onSelectTab, 
  onOpenSearch,
  theme,
  onToggleTheme
}) {
  const navItems = [
    { id: 'home', label: 'Início & Resumo', icon: Home },
    { id: 'kanto', label: 'Detonado Kanto', icon: Compass },
    { id: 'johto', label: 'Detonado Johto', icon: Sparkles },
    { id: 'gyms', label: 'Líderes & Chefes', icon: Trophy },
    { id: 'pokedex', label: 'Pokédex Nacional', icon: BookOpen },
    { id: 'routes', label: 'Rotas & Encontros', icon: MapPin },
    { id: 'items', label: 'TMs, HMs & Itens', icon: Gift },
    { id: 'controls', label: 'Controles & APK', icon: Gamepad2 },
  ];

  const handleItemClick = (id) => {
    onSelectTab(id);
    onClose();
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };

  return (
    <>
      {/* Mobile Backdrop */}
      <div 
        className={`sidebar-backdrop ${isOpen ? 'open' : ''}`}
        onClick={onClose}
        aria-hidden="true"
      />

      {/* Sidebar / Drawer */}
      <aside className={`sidebar ${isOpen ? 'open' : ''}`}>
        {/* Header */}
        <div style={{
          padding: '1.25rem 1.25rem 1rem 1.25rem',
          borderBottom: '1px solid var(--border-color)',
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'space-between'
        }}>
          <div className="brand-title">
            <Zap size={22} color="var(--primary)" fill="var(--primary)" />
            <span>Kanto & Johto</span>
          </div>

          <div style={{ display: 'flex', alignItems: 'center', gap: '0.25rem' }}>
            <button 
              type="button"
              onClick={onClose}
              className="mobile-close-btn"
              aria-label="Fechar menu"
              style={{
                background: 'transparent',
                border: 'none',
                color: 'var(--text-muted)',
                cursor: 'pointer',
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center',
                padding: '4px'
              }}
            >
              <X size={20} />
            </button>
          </div>
        </div>

        {/* Universal Search Bar Trigger in Sidebar */}
        <div style={{ padding: '0.85rem 1rem 0.4rem 1rem' }}>
          <button 
            type="button"
            className="search-trigger-btn"
            style={{ width: '100%', maxWidth: '100%' }}
            onClick={() => {
              onOpenSearch();
              onClose();
            }}
          >
            <Search size={16} />
            <span>Buscar palavras...</span>
            <span className="kbd-shortcut">Ctrl+K</span>
          </button>
        </div>

        {/* Theme Toggle Button in Sidebar */}
        <div style={{ padding: '0.25rem 1rem 0.5rem 1rem' }}>
          <button
            type="button"
            onClick={onToggleTheme}
            className="theme-toggle-btn"
            style={{ width: '100%', justifyContent: 'flex-start', padding: '0.6rem 0.85rem' }}
          >
            {theme === 'dark' ? <Sun size={17} color="var(--accent)" /> : <Moon size={17} color="var(--primary)" />}
            <span>{theme === 'dark' ? 'Alternar para Modo Claro' : 'Alternar para Modo Escuro'}</span>
          </button>
        </div>

        {/* Navigation Links */}
        <nav style={{ padding: '0.5rem 0.75rem', flex: 1, display: 'flex', flexDirection: 'column', gap: '3px' }}>
          {navItems.map((item) => {
            const Icon = item.icon;
            const isActive = activeTab === item.id;
            return (
              <button
                key={item.id}
                type="button"
                className={`nav-link-btn ${isActive ? 'active' : ''}`}
                onClick={() => handleItemClick(item.id)}
              >
                <Icon size={18} color={isActive ? 'var(--primary)' : 'var(--text-muted)'} />
                <span>{item.label}</span>
              </button>
            );
          })}
        </nav>

        {/* Footer Downloads / Links */}
        <div style={{
          padding: '1rem 1.25rem',
          borderTop: '1px solid var(--border-color)',
          display: 'flex',
          flexDirection: 'column',
          gap: '0.5rem'
        }}>
          <a
            href="https://github.com/guuhferiani/kanto-johto/releases/latest"
            target="_blank"
            rel="noopener noreferrer"
            className="btn-primary-red"
            style={{ padding: '0.65rem 1rem', fontSize: '0.86rem' }}
          >
            <Download size={16} />
            <span>Baixar APK Android</span>
          </a>

          <a
            href="https://github.com/guuhferiani/kanto-johto"
            target="_blank"
            rel="noopener noreferrer"
            className="btn-subtle"
            style={{ padding: '0.55rem 1rem', fontSize: '0.82rem' }}
          >
            <Code2 size={15} />
            <span>Repositório GitHub</span>
          </a>
        </div>
      </aside>
    </>
  );
}
