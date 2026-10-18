import React from 'react';
import { Home, Compass, Trophy, BookOpen, MapPin, Sparkles } from 'lucide-react';

export default function BottomNav({ activeTab, onSelectTab }) {
  const tabs = [
    { id: 'home', label: 'Início', icon: Home },
    { id: 'kanto', label: 'Kanto', icon: Compass },
    { id: 'johto', label: 'Johto', icon: Sparkles },
    { id: 'gyms', label: 'Chefes', icon: Trophy },
    { id: 'pokedex', label: 'Pokédex', icon: BookOpen },
    { id: 'routes', label: 'Rotas', icon: MapPin },
  ];

  return (
    <nav className="bottom-nav">
      {tabs.map((tab) => {
        const IconComponent = tab.icon;
        const isActive = activeTab === tab.id;
        return (
          <button
            key={tab.id}
            type="button"
            className={`bottom-nav-item ${isActive ? 'active' : ''}`}
            onClick={() => {
              onSelectTab(tab.id);
              window.scrollTo({ top: 0, behavior: 'smooth' });
            }}
          >
            <IconComponent size={20} color={isActive ? '#ef4444' : '#94a3b8'} />
            <span>{tab.label}</span>
          </button>
        );
      })}
    </nav>
  );
}
