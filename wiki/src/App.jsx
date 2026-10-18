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
import { ArrowUp } from 'lucide-react';

export default function App() {
  const [activeTab, setActiveTab] = useState('home');
  const [isDrawerOpen, setIsDrawerOpen] = useState(false);
  const [isSearchOpen, setIsSearchOpen] = useState(false);
  const [showScrollTop, setShowScrollTop] = useState(false);

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

  // Universal navigation handler (used by search and internal links)
  const handleNavigate = (tab, targetPayload) => {
    if (tab === 'pokedex') {
      setActiveTab('pokedex');
      setTargetMon(targetPayload || '');
    } else if (tab === 'gyms') {
      setActiveTab('gyms');
      setHighlightBoss(targetPayload || null);
    } else if (tab === 'kanto') {
      setActiveTab('kanto');
      setHighlightChapter(targetPayload || null);
    } else if (tab === 'johto') {
      setActiveTab('johto');
      setHighlightChapter(targetPayload || null);
    } else if (tab === 'routes') {
      setActiveTab('routes');
      setTargetRoute(targetPayload || '');
    } else if (tab) {
      setActiveTab(tab);
    }
  };

  const scrollToTop = () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };

  return (
    <div className="app-layout">
      {/* Mobile Top Navbar */}
      <Navbar
        onOpenSearch={() => setIsSearchOpen(true)}
        onToggleDrawer={() => setIsDrawerOpen((prev) => !prev)}
      />

      {/* Desktop Permanent Sidebar / Mobile Slide Drawer */}
      <SidebarDrawer
        isOpen={isDrawerOpen}
        onClose={() => setIsDrawerOpen(false)}
        activeTab={activeTab}
        onSelectTab={(tab) => {
          setActiveTab(tab);
          setHighlightChapter(null);
          setHighlightBoss(null);
          setTargetMon('');
          setTargetRoute('');
        }}
        onOpenSearch={() => setIsSearchOpen(true)}
      />

      {/* Main Content Area */}
      <main className="main-content">
        {activeTab === 'home' && (
          <HomeView
            onSelectTab={(tab) => {
              setActiveTab(tab);
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
      </main>

      {/* Mobile Bottom Fixed Navigation */}
      <BottomNav
        activeTab={activeTab}
        onSelectTab={(tab) => {
          setActiveTab(tab);
          setHighlightChapter(null);
          setHighlightBoss(null);
          setTargetMon('');
          setTargetRoute('');
        }}
      />

      {/* Floating Back to Top Button */}
      {showScrollTop && (
        <button
          type="button"
          onClick={scrollToTop}
          aria-label="Voltar ao topo"
          style={{
            position: 'fixed',
            bottom: '75px',
            right: '16px',
            width: '44px',
            height: '44px',
            borderRadius: '50%',
            background: 'rgba(239, 68, 68, 0.9)',
            color: '#fff',
            border: 'none',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            cursor: 'pointer',
            boxShadow: '0 4px 14px rgba(239, 68, 68, 0.4)',
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
