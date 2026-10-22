import React, { useState, useEffect } from 'react';
import Navbar from './components/Navbar';
import BottomNav from './components/BottomNav';
import SidebarDrawer from './components/SidebarDrawer';
import GlobalSearchModal from './components/GlobalSearchModal';
import HomeView from './components/HomeView';
import WalkthroughView from './components/WalkthroughView';
import GymBossView from './components/GymBossView';
import PokedexView from './components/PokedexView';
import RoutesView from './components/RoutesView';
import ItemsView from './components/ItemsView';
import ControlsView from './components/ControlsView';
import Footer from './components/Footer';
import { ArrowUp } from 'lucide-react';

export default function App() {
  const [activeTab, setActiveTab] = useState('home');
  const [isDrawerOpen, setIsDrawerOpen] = useState(false);
  const [isSearchOpen, setIsSearchOpen] = useState(false);
  const [showScrollTop, setShowScrollTop] = useState(false);

  // Theme state: dark (default) or light
  const [theme, setTheme] = useState(() => {
    return localStorage.getItem('wiki_theme') || 'dark';
  });

  useEffect(() => {
    document.documentElement.setAttribute('data-theme', theme);
    localStorage.setItem('wiki_theme', theme);
  }, [theme]);

  const toggleTheme = () => {
    setTheme((prev) => (prev === 'dark' ? 'light' : 'dark'));
  };

  // Navigation targets from search
  const [highlightChapter, setHighlightChapter] = useState(null);
  const [highlightBoss, setHighlightBoss] = useState(null);
  const [targetMon, setTargetMon] = useState('');
  const [targetRoute, setTargetRoute] = useState('');

  // Scroll listener for back-to-top button
  useEffect(() => {
    const handleScroll = () => {
      if (window.scrollY > 300) {
        setShowScrollTop(true);
      } else {
        setShowScrollTop(false);
      }
    };
    window.addEventListener('scroll', handleScroll, { passive: true });
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  // Hash router helper to allow direct links: #detonado, #kanto, #johto, #pokedex, #gyms, etc.
  // Also supports clean pathnames (e.g. /detonado, /pokedex) when hosted on Vercel
  const resolveHash = (hashStr) => {
    let raw = (hashStr || window.location.hash || '').replace(/^#\/?/, '').toLowerCase().trim();
    if (!raw) {
      const pathname = window.location.pathname
        .replace(/^\/kanto-johto\/?/, '')
        .replace(/^\//, '')
        .replace(/\/$/, '')
        .toLowerCase()
        .trim();
      raw = pathname;
    }
    if (!raw) return { tab: 'home' };

    if (raw === 'detonado' || raw === 'detonado-kanto' || raw === 'kanto' || raw === 'walkthrough') {
      return { tab: 'kanto' };
    }
    if (raw === 'detonado-johto' || raw === 'johto') {
      return { tab: 'johto' };
    }
    if (raw.startsWith('kanto-cap')) {
      return { tab: 'kanto', chapter: raw };
    }
    if (raw.startsWith('johto-fase')) {
      return { tab: 'johto', chapter: raw };
    }
    if (raw === 'pokedex' || raw === 'dex') {
      return { tab: 'pokedex' };
    }
    if (raw === 'gyms' || raw === 'chefes' || raw === 'ginasios' || raw === 'bosses') {
      return { tab: 'gyms' };
    }
    if (raw === 'routes' || raw === 'rotas') {
      return { tab: 'routes' };
    }
    if (raw === 'items' || raw === 'itens' || raw === 'tms') {
      return { tab: 'items' };
    }
    if (raw === 'controls' || raw === 'controles') {
      return { tab: 'controls' };
    }
    return { tab: raw };
  };

  // Sync state with URL hash on mount and hash changes
  useEffect(() => {
    const handleHashChange = () => {
      const { tab, chapter } = resolveHash();
      if (tab) {
        setActiveTab(tab);
        if (chapter) setHighlightChapter(chapter);
      }
    };
    handleHashChange();
    window.addEventListener('hashchange', handleHashChange);
    return () => window.removeEventListener('hashchange', handleHashChange);
  }, []);

  // Function to switch tab and update browser URL hash without full reload
  const changeTab = (tab, targetPayload = null) => {
    setActiveTab(tab);
    setHighlightChapter(null);
    setHighlightBoss(null);
    setTargetMon('');
    setTargetRoute('');

    if (tab === 'home') {
      if (window.location.hash) {
        history.replaceState(null, '', window.location.pathname + window.location.search);
      }
    } else {
      window.location.hash = tab;
    }

    if (targetPayload) {
      if (tab === 'pokedex') setTargetMon(targetPayload);
      else if (tab === 'gyms') setHighlightBoss(targetPayload);
      else if (tab === 'kanto' || tab === 'johto') setHighlightChapter(targetPayload);
      else if (tab === 'routes') setTargetRoute(targetPayload);
    }
  };

  // Universal navigation handler (used by search and internal links)
  const handleNavigate = (tab, targetPayload) => {
    changeTab(tab, targetPayload);
  };

  const scrollToTop = () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };

  return (
    <div className="app-layout">
      {/* Mobile Top Navbar */}
      <Navbar
        theme={theme}
        onToggleTheme={toggleTheme}
        onOpenSearch={() => setIsSearchOpen(true)}
        onToggleDrawer={() => setIsDrawerOpen((prev) => !prev)}
      />

      {/* Desktop Permanent Sidebar / Mobile Slide Drawer */}
      <SidebarDrawer
        theme={theme}
        onToggleTheme={toggleTheme}
        isOpen={isDrawerOpen}
        onClose={() => setIsDrawerOpen(false)}
        activeTab={activeTab}
        onSelectTab={(tab) => changeTab(tab)}
        onOpenSearch={() => setIsSearchOpen(true)}
      />

      {/* Main Content Area */}
      <main className="main-content">
        {activeTab === 'home' && (
          <HomeView
            onSelectTab={(tab) => {
              changeTab(tab);
              window.scrollTo({ top: 0, behavior: 'smooth' });
            }}
            onOpenSearch={() => setIsSearchOpen(true)}
          />
        )}

        {activeTab === 'kanto' && (
          <WalkthroughView
            region="kanto"
            highlightChapterId={highlightChapter}
          />
        )}

        {activeTab === 'johto' && (
          <WalkthroughView
            region="johto"
            highlightChapterId={highlightChapter}
          />
        )}

        {activeTab === 'gyms' && (
          <GymBossView highlightBossId={highlightBoss} />
        )}

        {activeTab === 'pokedex' && (
          <PokedexView searchTargetMon={targetMon} />
        )}

        {activeTab === 'routes' && (
          <RoutesView searchTargetRoute={targetRoute} />
        )}

        {activeTab === 'items' && <ItemsView />}

        {activeTab === 'controls' && <ControlsView />}

        {/* Bottom Page Footer with Rights and Links */}
        <Footer />
      </main>

      {/* Mobile Bottom Fixed Navigation */}
      <BottomNav
        activeTab={activeTab}
        onSelectTab={(tab) => changeTab(tab)}
      />

      {/* Floating Back to Top Button */}
      {showScrollTop && (
        <button
          type="button"
          onClick={scrollToTop}
          aria-label="Voltar ao topo"
          style={{
            position: 'fixed',
            bottom: 'calc(68px + env(safe-area-inset-bottom, 0px))',
            right: '16px',
            width: '42px',
            height: '42px',
            borderRadius: '50%',
            background: 'var(--primary)',
            color: '#fff',
            border: 'none',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            cursor: 'pointer',
            boxShadow: 'var(--shadow-card)',
            zIndex: 80,
            transition: 'transform 0.15s ease'
          }}
        >
          <ArrowUp size={20} />
        </button>
      )}

      {/* Global Universal Search Modal */}
      <GlobalSearchModal
        isOpen={isSearchOpen}
        onClose={() => setIsSearchOpen(false)}
        onNavigate={handleNavigate}
      />
    </div>
  );
}
