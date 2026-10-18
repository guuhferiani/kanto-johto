# -*- coding: utf-8 -*-
"""
Script gerador da Wiki & Pokédex Oficial Interativa de Pokémon Kanto & Johto.
Gera Wiki_Pokemon_Kanto_Johto.html e Detonado_Interativo_Pokemon_Kanto_Johto.html.
"""

import json
import os
import re

print("Carregando banco de dados para a Wiki Interativa...")

# 1. Carregar encontros de wild_encounters.json
with open('src/data/wild_encounters.json', 'r', encoding='utf-8') as f:
    wild_json = json.load(f)

encounters = wild_json.get('wild_encounter_groups', [{}])[0].get('encounters', [])

routes_map = {}
for enc in encounters:
    map_raw = enc.get('map', '').replace('MAP_', '')
    label = enc.get('base_label', '')
    is_night = 'Night' in label
    
    clean_name = map_raw.replace('_', ' ').title()
    if clean_name not in routes_map:
        routes_map[clean_name] = {
            'day': set(),
            'night': set(),
            'water': set(),
            'hidden': set()
        }
    
    # Land
    land = enc.get('land_mons', {}).get('mons', [])
    for m in land:
        sp = m.get('species', '').replace('SPECIES_', '').replace('_', ' ').title()
        lvl = f"{m.get('min_level')}-{m.get('max_level')}"
        val = f"{sp} (Lv {lvl})"
        if is_night:
            routes_map[clean_name]['night'].add(val)
        else:
            routes_map[clean_name]['day'].add(val)
            
    # Water
    water = enc.get('water_mons', {}).get('mons', [])
    for m in water:
        sp = m.get('species', '').replace('SPECIES_', '').replace('_', ' ').title()
        lvl = f"{m.get('min_level')}-{m.get('max_level')}"
        routes_map[clean_name]['water'].add(f"{sp} (Lv {lvl})")
        
    # Hidden (DexNav)
    hidden = enc.get('hidden_mons', {}).get('mons', [])
    for m in hidden:
        sp = m.get('species', '').replace('SPECIES_', '').replace('_', ' ').title()
        lvl = f"{m.get('min_level')}-{m.get('max_level')}"
        routes_map[clean_name]['hidden'].add(f"{sp} (Lv {lvl})")

# 2. Dados dos 251 Pokémon com métodos de evolução e pasta local
pokedex_data = [
    {"num": 1, "name": "Bulbasaur", "type": ["Planta", "Veneno"], "evo": "Lv 16 -> Ivysaur", "folder": "bulbasaur"},
    {"num": 2, "name": "Ivysaur", "type": ["Planta", "Veneno"], "evo": "Lv 32 -> Venusaur", "folder": "ivysaur"},
    {"num": 3, "name": "Venusaur", "type": ["Planta", "Veneno"], "evo": "Forma Final", "folder": "venusaur"},
    {"num": 4, "name": "Charmander", "type": ["Fogo"], "evo": "Lv 16 -> Charmeleon", "folder": "charmander"},
    {"num": 5, "name": "Charmeleon", "type": ["Fogo"], "evo": "Lv 36 -> Charizard", "folder": "charmeleon"},
    {"num": 6, "name": "Charizard", "type": ["Fogo", "Voador"], "evo": "Forma Final", "folder": "charizard"},
    {"num": 7, "name": "Squirtle", "type": ["Água"], "evo": "Lv 16 -> Wartortle", "folder": "squirtle"},
    {"num": 8, "name": "Wartortle", "type": ["Água"], "evo": "Lv 36 -> Blastoise", "folder": "wartortle"},
    {"num": 9, "name": "Blastoise", "type": ["Água"], "evo": "Forma Final", "folder": "blastoise"},
    {"num": 10, "name": "Caterpie", "type": ["Inseto"], "evo": "Lv 7 -> Metapod", "folder": "caterpie"},
    {"num": 11, "name": "Metapod", "type": ["Inseto"], "evo": "Lv 10 -> Butterfree", "folder": "metapod"},
    {"num": 12, "name": "Butterfree", "type": ["Inseto", "Voador"], "evo": "Forma Final", "folder": "butterfree"},
    {"num": 13, "name": "Weedle", "type": ["Inseto", "Veneno"], "evo": "Lv 7 -> Kakuna", "folder": "weedle"},
    {"num": 14, "name": "Kakuna", "type": ["Inseto", "Veneno"], "evo": "Lv 10 -> Beedrill", "folder": "kakuna"},
    {"num": 15, "name": "Beedrill", "type": ["Inseto", "Veneno"], "evo": "Forma Final", "folder": "beedrill"},
    {"num": 16, "name": "Pidgey", "type": ["Normal", "Voador"], "evo": "Lv 18 -> Pidgeotto", "folder": "pidgey"},
    {"num": 17, "name": "Pidgeotto", "type": ["Normal", "Voador"], "evo": "Lv 36 -> Pidgeot", "folder": "pidgeotto"},
    {"num": 18, "name": "Pidgeot", "type": ["Normal", "Voador"], "evo": "Forma Final", "folder": "pidgeot"},
    {"num": 19, "name": "Rattata", "type": ["Normal"], "evo": "Lv 20 -> Raticate", "folder": "rattata"},
    {"num": 20, "name": "Raticate", "type": ["Normal"], "evo": "Forma Final", "folder": "raticate"},
    {"num": 21, "name": "Spearow", "type": ["Normal", "Voador"], "evo": "Lv 20 -> Fearow", "folder": "spearow"},
    {"num": 22, "name": "Fearow", "type": ["Normal", "Voador"], "evo": "Forma Final", "folder": "fearow"},
    {"num": 23, "name": "Ekans", "type": ["Veneno"], "evo": "Lv 22 -> Arbok", "folder": "ekans"},
    {"num": 24, "name": "Arbok", "type": ["Veneno"], "evo": "Forma Final", "folder": "arbok"},
    {"num": 25, "name": "Pikachu", "type": ["Elétrico"], "evo": "Pedra do Trovão -> Raichu", "folder": "pikachu"},
    {"num": 26, "name": "Raichu", "type": ["Elétrico"], "evo": "Forma Final", "folder": "raichu"},
    {"num": 27, "name": "Sandshrew", "type": ["Terra"], "evo": "Lv 22 -> Sandslash", "folder": "sandshrew"},
    {"num": 28, "name": "Sandslash", "type": ["Terra"], "evo": "Forma Final", "folder": "sandslash"},
    {"num": 29, "name": "Nidoran♀", "type": ["Veneno"], "evo": "Lv 16 -> Nidorina", "folder": "nidoran_f"},
    {"num": 30, "name": "Nidorina", "type": ["Veneno"], "evo": "Pedra da Lua -> Nidoqueen", "folder": "nidorina"},
    {"num": 31, "name": "Nidoqueen", "type": ["Veneno", "Terra"], "evo": "Forma Final", "folder": "nidoqueen"},
    {"num": 32, "name": "Nidoran♂", "type": ["Veneno"], "evo": "Lv 16 -> Nidorino", "folder": "nidoran_m"},
    {"num": 33, "name": "Nidorino", "type": ["Veneno"], "evo": "Pedra da Lua -> Nidoking", "folder": "nidorino"},
    {"num": 34, "name": "Nidoking", "type": ["Veneno", "Terra"], "evo": "Forma Final", "folder": "nidoking"},
    {"num": 35, "name": "Clefairy", "type": ["Fada"], "evo": "Pedra da Lua -> Clefable", "folder": "clefairy"},
    {"num": 36, "name": "Clefable", "type": ["Fada"], "evo": "Forma Final", "folder": "clefable"},
    {"num": 37, "name": "Vulpix", "type": ["Fogo"], "evo": "Pedra de Fogo -> Ninetales", "folder": "vulpix"},
    {"num": 38, "name": "Ninetales", "type": ["Fogo"], "evo": "Forma Final", "folder": "ninetales"},
    {"num": 39, "name": "Jigglypuff", "type": ["Normal", "Fada"], "evo": "Pedra da Lua -> Wigglytuff", "folder": "jigglypuff"},
    {"num": 40, "name": "Wigglytuff", "type": ["Normal", "Fada"], "evo": "Forma Final", "folder": "wigglytuff"},
    {"num": 41, "name": "Zubat", "type": ["Veneno", "Voador"], "evo": "Lv 22 -> Golbat", "folder": "zubat"},
    {"num": 42, "name": "Golbat", "type": ["Veneno", "Voador"], "evo": "Felicidade Máxima -> Crobat", "folder": "golbat"},
    {"num": 43, "name": "Oddish", "type": ["Planta", "Veneno"], "evo": "Lv 21 -> Gloom", "folder": "oddish"},
    {"num": 44, "name": "Gloom", "type": ["Planta", "Veneno"], "evo": "Pedra Folha (Vileplume) ou Pedra Solar (Bellossom)", "folder": "gloom"},
    {"num": 45, "name": "Vileplume", "type": ["Planta", "Veneno"], "evo": "Forma Final", "folder": "vileplume"},
    {"num": 46, "name": "Paras", "type": ["Inseto", "Planta"], "evo": "Lv 24 -> Parasect", "folder": "paras"},
    {"num": 47, "name": "Parasect", "type": ["Inseto", "Planta"], "evo": "Forma Final", "folder": "parasect"},
    {"num": 48, "name": "Venonat", "type": ["Inseto", "Veneno"], "evo": "Lv 31 -> Venomoth", "folder": "venonat"},
    {"num": 49, "name": "Venomoth", "type": ["Inseto", "Veneno"], "evo": "Forma Final", "folder": "venomoth"},
    {"num": 50, "name": "Diglett", "type": ["Terra"], "evo": "Lv 26 -> Dugtrio", "folder": "diglett"},
    {"num": 51, "name": "Dugtrio", "type": ["Terra"], "evo": "Forma Final", "folder": "dugtrio"},
    {"num": 52, "name": "Meowth", "type": ["Normal"], "evo": "Lv 28 -> Persian", "folder": "meowth"},
    {"num": 53, "name": "Persian", "type": ["Normal"], "evo": "Forma Final", "folder": "persian"},
    {"num": 54, "name": "Psyduck", "type": ["Água"], "evo": "Lv 33 -> Golduck", "folder": "psyduck"},
    {"num": 55, "name": "Golduck", "type": ["Água"], "evo": "Forma Final", "folder": "golduck"},
    {"num": 56, "name": "Mankey", "type": ["Lutador"], "evo": "Lv 28 -> Primeape", "folder": "mankey"},
    {"num": 57, "name": "Primeape", "type": ["Lutador"], "evo": "Forma Final", "folder": "primeape"},
    {"num": 58, "name": "Growlithe", "type": ["Fogo"], "evo": "Pedra de Fogo -> Arcanine", "folder": "growlithe"},
    {"num": 59, "name": "Arcanine", "type": ["Fogo"], "evo": "Forma Final", "folder": "arcanine"},
    {"num": 60, "name": "Poliwag", "type": ["Água"], "evo": "Lv 25 -> Poliwhirl", "folder": "poliwag"},
    {"num": 61, "name": "Poliwhirl", "type": ["Água"], "evo": "Pedra da Água (Poliwrath) ou King's Rock (Politoed)", "folder": "poliwhirl"},
    {"num": 62, "name": "Poliwrath", "type": ["Água", "Lutador"], "evo": "Forma Final", "folder": "poliwrath"},
    {"num": 63, "name": "Abra", "type": ["Psíquico"], "evo": "Lv 16 -> Kadabra", "folder": "abra"},
    {"num": 64, "name": "Kadabra", "type": ["Psíquico"], "evo": "Lv 37, Pedra do Poder ou Troca -> Alakazam", "folder": "kadabra"},
    {"num": 65, "name": "Alakazam", "type": ["Psíquico"], "evo": "Forma Final", "folder": "alakazam"},
    {"num": 66, "name": "Machop", "type": ["Lutador"], "evo": "Lv 28 -> Machoke", "folder": "machop"},
    {"num": 67, "name": "Machoke", "type": ["Lutador"], "evo": "Lv 37, Pedra do Poder ou Troca -> Machamp", "folder": "machoke"},
    {"num": 68, "name": "Machamp", "type": ["Lutador"], "evo": "Forma Final", "folder": "machamp"},
    {"num": 69, "name": "Bellsprout", "type": ["Planta", "Veneno"], "evo": "Lv 21 -> Weepinbell", "folder": "bellsprout"},
    {"num": 70, "name": "Weepinbell", "type": ["Planta", "Veneno"], "evo": "Pedra Folha -> Victreebel", "folder": "weepinbell"},
    {"num": 71, "name": "Victreebel", "type": ["Planta", "Veneno"], "evo": "Forma Final", "folder": "victreebel"},
    {"num": 72, "name": "Tentacool", "type": ["Água", "Veneno"], "evo": "Lv 30 -> Tentacruel", "folder": "tentacool"},
    {"num": 73, "name": "Tentacruel", "type": ["Água", "Veneno"], "evo": "Forma Final", "folder": "tentacruel"},
    {"num": 74, "name": "Geodude", "type": ["Pedra", "Terra"], "evo": "Lv 25 -> Graveler", "folder": "geodude"},
    {"num": 75, "name": "Graveler", "type": ["Pedra", "Terra"], "evo": "Lv 37, Pedra do Poder ou Troca -> Golem", "folder": "graveler"},
    {"num": 76, "name": "Golem", "type": ["Pedra", "Terra"], "evo": "Forma Final", "folder": "golem"},
    {"num": 77, "name": "Ponyta", "type": ["Fogo"], "evo": "Lv 40 -> Rapidash", "folder": "ponyta"},
    {"num": 78, "name": "Rapidash", "type": ["Fogo"], "evo": "Forma Final", "folder": "rapidash"},
    {"num": 79, "name": "Slowpoke", "type": ["Água", "Psíquico"], "evo": "Lv 37 (Slowbro) ou King's Rock (Slowking)", "folder": "slowpoke"},
    {"num": 80, "name": "Slowbro", "type": ["Água", "Psíquico"], "evo": "Forma Final", "folder": "slowbro"},
    {"num": 81, "name": "Magnemite", "type": ["Elétrico", "Aço"], "evo": "Lv 30 -> Magneton", "folder": "magnemite"},
    {"num": 82, "name": "Magneton", "type": ["Elétrico", "Aço"], "evo": "Forma Final", "folder": "magneton"},
    {"num": 83, "name": "Farfetch'd", "type": ["Normal", "Voador"], "evo": "Não evolui", "folder": "farfetchd"},
    {"num": 84, "name": "Doduo", "type": ["Normal", "Voador"], "evo": "Lv 31 -> Dodrio", "folder": "doduo"},
    {"num": 85, "name": "Dodrio", "type": ["Normal", "Voador"], "evo": "Forma Final", "folder": "dodrio"},
    {"num": 86, "name": "Seel", "type": ["Água"], "evo": "Lv 34 -> Dewgong", "folder": "seel"},
    {"num": 87, "name": "Dewgong", "type": ["Água", "Gelo"], "evo": "Forma Final", "folder": "dewgong"},
    {"num": 88, "name": "Grimer", "type": ["Veneno"], "evo": "Lv 38 -> Muk", "folder": "grimer"},
    {"num": 89, "name": "Muk", "type": ["Veneno"], "evo": "Forma Final", "folder": "muk"},
    {"num": 90, "name": "Shellder", "type": ["Água"], "evo": "Pedra da Água -> Cloyster", "folder": "shellder"},
    {"num": 91, "name": "Cloyster", "type": ["Água", "Gelo"], "evo": "Forma Final", "folder": "cloyster"},
    {"num": 92, "name": "Gastly", "type": ["Fantasma", "Veneno"], "evo": "Lv 25 -> Haunter", "folder": "gastly"},
    {"num": 93, "name": "Haunter", "type": ["Fantasma", "Veneno"], "evo": "Lv 37, Pedra da Noite ou Troca -> Gengar", "folder": "haunter"},
    {"num": 94, "name": "Gengar", "type": ["Fantasma", "Veneno"], "evo": "Forma Final", "folder": "gengar"},
    {"num": 95, "name": "Onix", "type": ["Pedra", "Terra"], "evo": "Metal Coat -> Steelix", "folder": "onix"},
    {"num": 96, "name": "Drowzee", "type": ["Psíquico"], "evo": "Lv 26 -> Hypno", "folder": "drowzee"},
    {"num": 97, "name": "Hypno", "type": ["Psíquico"], "evo": "Forma Final", "folder": "hypno"},
    {"num": 98, "name": "Krabby", "type": ["Água"], "evo": "Lv 28 -> Kingler", "folder": "krabby"},
    {"num": 99, "name": "Kingler", "type": ["Água"], "evo": "Forma Final", "folder": "kingler"},
    {"num": 100, "name": "Voltorb", "type": ["Elétrico"], "evo": "Lv 30 -> Electrode", "folder": "voltorb"},
    {"num": 101, "name": "Electrode", "type": ["Elétrico"], "evo": "Forma Final", "folder": "electrode"},
    {"num": 102, "name": "Exeggcute", "type": ["Planta", "Psíquico"], "evo": "Pedra Folha -> Exeggutor", "folder": "exeggcute"},
    {"num": 103, "name": "Exeggutor", "type": ["Planta", "Psíquico"], "evo": "Forma Final", "folder": "exeggutor"},
    {"num": 104, "name": "Cubone", "type": ["Terra"], "evo": "Lv 28 -> Marowak", "folder": "cubone"},
    {"num": 105, "name": "Marowak", "type": ["Terra"], "evo": "Forma Final", "folder": "marowak"},
    {"num": 106, "name": "Hitmonlee", "type": ["Lutador"], "evo": "Tyrogue (Atk > Def)", "folder": "hitmonlee"},
    {"num": 107, "name": "Hitmonchan", "type": ["Lutador"], "evo": "Tyrogue (Def > Atk)", "folder": "hitmonchan"},
    {"num": 108, "name": "Lickitung", "type": ["Normal"], "evo": "Aprender Rollout -> Lickilicky", "folder": "lickitung"},
    {"num": 109, "name": "Koffing", "type": ["Veneno"], "evo": "Lv 35 -> Weezing", "folder": "koffing"},
    {"num": 110, "name": "Weezing", "type": ["Veneno"], "evo": "Forma Final", "folder": "weezing"},
    {"num": 111, "name": "Rhyhorn", "type": ["Terra", "Pedra"], "evo": "Lv 42 -> Rhydon", "folder": "rhyhorn"},
    {"num": 112, "name": "Rhydon", "type": ["Terra", "Pedra"], "evo": "Protector -> Rhyperior", "folder": "rhydon"},
    {"num": 113, "name": "Chansey", "type": ["Normal"], "evo": "Felicidade Máxima -> Blissey", "folder": "chansey"},
    {"num": 114, "name": "Tangela", "type": ["Planta"], "evo": "Aprender Ancient Power -> Tangrowth", "folder": "tangela"},
    {"num": 115, "name": "Kangaskhan", "type": ["Normal"], "evo": "Não evolui", "folder": "kangaskhan"},
    {"num": 116, "name": "Horsea", "type": ["Água"], "evo": "Lv 32 -> Seadra", "folder": "horsea"},
    {"num": 117, "name": "Seadra", "type": ["Água"], "evo": "Dragon Scale -> Kingdra", "folder": "seadra"},
    {"num": 118, "name": "Goldeen", "type": ["Água"], "evo": "Lv 33 -> Seaking", "folder": "goldeen"},
    {"num": 119, "name": "Seaking", "type": ["Água"], "evo": "Forma Final", "folder": "seaking"},
    {"num": 120, "name": "Staryu", "type": ["Água"], "evo": "Pedra da Água -> Starmie", "folder": "staryu"},
    {"num": 121, "name": "Starmie", "type": ["Água", "Psíquico"], "evo": "Forma Final", "folder": "starmie"},
    {"num": 122, "name": "Mr. Mime", "type": ["Psíquico", "Fada"], "evo": "Não evolui", "folder": "mr_mime"},
    {"num": 123, "name": "Scyther", "type": ["Inseto", "Voador"], "evo": "Metal Coat -> Scizor", "folder": "scyther"},
    {"num": 124, "name": "Jynx", "type": ["Gelo", "Psíquico"], "evo": "Smoochum Lv 30", "folder": "jynx"},
    {"num": 125, "name": "Electabuzz", "type": ["Elétrico"], "evo": "Elekid Lv 30 / Electirizer", "folder": "electabuzz"},
    {"num": 126, "name": "Magmar", "type": ["Fogo"], "evo": "Magby Lv 30 / Magmarizer", "folder": "magmar"},
    {"num": 127, "name": "Pinsir", "type": ["Inseto"], "evo": "Não evolui", "folder": "pinsir"},
    {"num": 128, "name": "Tauros", "type": ["Normal"], "evo": "Não evolui", "folder": "tauros"},
    {"num": 129, "name": "Magikarp", "type": ["Água"], "evo": "Lv 20 -> Gyarados", "folder": "magikarp"},
    {"num": 130, "name": "Gyarados", "type": ["Água", "Voador"], "evo": "Forma Final", "folder": "gyarados"},
    {"num": 131, "name": "Lapras", "type": ["Água", "Gelo"], "evo": "Não evolui", "folder": "lapras"},
    {"num": 132, "name": "Ditto", "type": ["Normal"], "evo": "Não evolui (Transform)", "folder": "ditto"},
    {"num": 133, "name": "Eevee", "type": ["Normal"], "evo": "Água, Trovão, Fogo, Sol, Noite...", "folder": "eevee"},
    {"num": 134, "name": "Vaporeon", "type": ["Água"], "evo": "Forma Final", "folder": "vaporeon"},
    {"num": 135, "name": "Jolteon", "type": ["Elétrico"], "evo": "Forma Final", "folder": "jolteon"},
    {"num": 136, "name": "Flareon", "type": ["Fogo"], "evo": "Forma Final", "folder": "flareon"},
    {"num": 137, "name": "Porygon", "type": ["Normal"], "evo": "Up-Grade -> Porygon2", "folder": "porygon"},
    {"num": 138, "name": "Omanyte", "type": ["Pedra", "Água"], "evo": "Lv 40 -> Omastar", "folder": "omanyte"},
    {"num": 139, "name": "Omastar", "type": ["Pedra", "Água"], "evo": "Forma Final", "folder": "omastar"},
    {"num": 140, "name": "Kabuto", "type": ["Pedra", "Água"], "evo": "Lv 40 -> Kabutops", "folder": "kabuto"},
    {"num": 141, "name": "Kabutops", "type": ["Pedra", "Água"], "evo": "Forma Final", "folder": "kabutops"},
    {"num": 142, "name": "Aerodactyl", "type": ["Pedra", "Voador"], "evo": "Não evolui (Old Amber)", "folder": "aerodactyl"},
    {"num": 143, "name": "Snorlax", "type": ["Normal"], "evo": "Acordado com Poké Flute", "folder": "snorlax"},
    {"num": 144, "name": "Articuno", "type": ["Gelo", "Voador"], "evo": "Lendário (Seafoam Islands)", "folder": "articuno"},
    {"num": 145, "name": "Zapdos", "type": ["Elétrico", "Voador"], "evo": "Lendário (Power Plant)", "folder": "zapdos"},
    {"num": 146, "name": "Moltres", "type": ["Fogo", "Voador"], "evo": "Lendário (Mt. Ember / Victory Road)", "folder": "moltres"},
    {"num": 147, "name": "Dratini", "type": ["Dragão"], "evo": "Lv 30 -> Dragonair", "folder": "dratini"},
    {"num": 148, "name": "Dragonair", "type": ["Dragão"], "evo": "Lv 55 -> Dragonite", "folder": "dragonair"},
    {"num": 149, "name": "Dragonite", "type": ["Dragão", "Voador"], "evo": "Forma Final", "folder": "dragonite"},
    {"num": 150, "name": "Mewtwo", "type": ["Psíquico"], "evo": "Lendário (Cerulean Cave Lv 70)", "folder": "mewtwo"},
    {"num": 151, "name": "Mew", "type": ["Psíquico"], "evo": "Mítico Ancestral", "folder": "mew"},
    {"num": 152, "name": "Chikorita", "type": ["Planta"], "evo": "Lv 16 -> Bayleef", "folder": "chikorita"},
    {"num": 153, "name": "Bayleef", "type": ["Planta"], "evo": "Lv 32 -> Meganium", "folder": "bayleef"},
    {"num": 154, "name": "Meganium", "type": ["Planta"], "evo": "Forma Final", "folder": "meganium"},
    {"num": 155, "name": "Cyndaquil", "type": ["Fogo"], "evo": "Lv 14 -> Quilava", "folder": "cyndaquil"},
    {"num": 156, "name": "Quilava", "type": ["Fogo"], "evo": "Lv 36 -> Typhlosion", "folder": "quilava"},
    {"num": 157, "name": "Typhlosion", "type": ["Fogo"], "evo": "Forma Final", "folder": "typhlosion"},
    {"num": 158, "name": "Totodile", "type": ["Água"], "evo": "Lv 18 -> Croconaw", "folder": "totodile"},
    {"num": 159, "name": "Croconaw", "type": ["Água"], "evo": "Lv 30 -> Feraligatr", "folder": "croconaw"},
    {"num": 160, "name": "Feraligatr", "type": ["Água"], "evo": "Forma Final", "folder": "feraligatr"},
    {"num": 161, "name": "Sentret", "type": ["Normal"], "evo": "Lv 15 -> Furret", "folder": "sentret"},
    {"num": 162, "name": "Furret", "type": ["Normal"], "evo": "Forma Final", "folder": "furret"},
    {"num": 163, "name": "Hoothoot", "type": ["Normal", "Voador"], "evo": "Lv 20 -> Noctowl", "folder": "hoothoot"},
    {"num": 164, "name": "Noctowl", "type": ["Normal", "Voador"], "evo": "Forma Final", "folder": "noctowl"},
    {"num": 165, "name": "Ledyba", "type": ["Inseto", "Voador"], "evo": "Lv 18 -> Ledian", "folder": "ledyba"},
    {"num": 166, "name": "Ledian", "type": ["Inseto", "Voador"], "evo": "Forma Final", "folder": "ledian"},
    {"num": 167, "name": "Spinarak", "type": ["Inseto", "Veneno"], "evo": "Lv 22 -> Ariados", "folder": "spinarak"},
    {"num": 168, "name": "Ariados", "type": ["Inseto", "Veneno"], "evo": "Forma Final", "folder": "ariados"},
    {"num": 169, "name": "Crobat", "type": ["Veneno", "Voador"], "evo": "Forma Final", "folder": "crobat"},
    {"num": 170, "name": "Chinchou", "type": ["Água", "Elétrico"], "evo": "Lv 27 -> Lanturn", "folder": "chinchou"},
    {"num": 171, "name": "Lanturn", "type": ["Água", "Elétrico"], "evo": "Forma Final", "folder": "lanturn"},
    {"num": 172, "name": "Pichu", "type": ["Elétrico"], "evo": "Felicidade -> Pikachu", "folder": "pichu"},
    {"num": 173, "name": "Cleffa", "type": ["Fada"], "evo": "Felicidade -> Clefairy", "folder": "cleffa"},
    {"num": 174, "name": "Igglybuff", "type": ["Normal", "Fada"], "evo": "Felicidade -> Jigglypuff", "folder": "igglybuff"},
    {"num": 175, "name": "Togepi", "type": ["Fada"], "evo": "Felicidade -> Togetic", "folder": "togepi"},
    {"num": 176, "name": "Togetic", "type": ["Fada", "Voador"], "evo": "Pedra do Brilho -> Togekiss", "folder": "togetic"},
    {"num": 177, "name": "Natu", "type": ["Psíquico", "Voador"], "evo": "Lv 25 -> Xatu", "folder": "natu"},
    {"num": 178, "name": "Xatu", "type": ["Psíquico", "Voador"], "evo": "Forma Final", "folder": "xatu"},
    {"num": 179, "name": "Mareep", "type": ["Elétrico"], "evo": "Lv 15 -> Flaaffy", "folder": "mareep"},
    {"num": 180, "name": "Flaaffy", "type": ["Elétrico"], "evo": "Lv 30 -> Ampharos", "folder": "flaaffy"},
    {"num": 181, "name": "Ampharos", "type": ["Elétrico"], "evo": "Forma Final", "folder": "ampharos"},
    {"num": 182, "name": "Bellossom", "type": ["Planta"], "evo": "Pedra Solar de Gloom", "folder": "bellossom"},
    {"num": 183, "name": "Marill", "type": ["Água", "Fada"], "evo": "Lv 18 -> Azumarill", "folder": "marill"},
    {"num": 184, "name": "Azumarill", "type": ["Água", "Fada"], "evo": "Forma Final", "folder": "azumarill"},
    {"num": 185, "name": "Sudowoodo", "type": ["Pedra"], "evo": "SquirtBottle na Rota 36", "folder": "sudowoodo"},
    {"num": 186, "name": "Politoed", "type": ["Água"], "evo": "King's Rock + Lv up de Poliwhirl", "folder": "politoed"},
    {"num": 187, "name": "Hoppip", "type": ["Planta", "Voador"], "evo": "Lv 18 -> Skiploom", "folder": "hoppip"},
    {"num": 188, "name": "Skiploom", "type": ["Planta", "Voador"], "evo": "Lv 27 -> Jumpluff", "folder": "skiploom"},
    {"num": 189, "name": "Jumpluff", "type": ["Planta", "Voador"], "evo": "Forma Final", "folder": "jumpluff"},
    {"num": 190, "name": "Aipom", "type": ["Normal"], "evo": "Double Hit -> Ambipom", "folder": "aipom"},
    {"num": 191, "name": "Sunkern", "type": ["Planta"], "evo": "Pedra Solar -> Sunflora", "folder": "sunkern"},
    {"num": 192, "name": "Sunflora", "type": ["Planta"], "evo": "Forma Final", "folder": "sunflora"},
    {"num": 193, "name": "Yanma", "type": ["Inseto", "Voador"], "evo": "Ancient Power -> Yanmega", "folder": "yanma"},
    {"num": 194, "name": "Wooper", "type": ["Água", "Terra"], "evo": "Lv 20 -> Quagsire", "folder": "wooper"},
    {"num": 195, "name": "Quagsire", "type": ["Água", "Terra"], "evo": "Forma Final", "folder": "quagsire"},
    {"num": 196, "name": "Espeon", "type": ["Psíquico"], "evo": "Eevee + Felicidade (Dia)", "folder": "espeon"},
    {"num": 197, "name": "Umbreon", "type": ["Sombrio"], "evo": "Eevee + Felicidade (Noite)", "folder": "umbreon"},
    {"num": 198, "name": "Murkrow", "type": ["Sombrio", "Voador"], "evo": "Pedra da Noite -> Honchkrow", "folder": "murkrow"},
    {"num": 199, "name": "Slowking", "type": ["Água", "Psíquico"], "evo": "King's Rock + Lv up de Slowpoke", "folder": "slowking"},
    {"num": 200, "name": "Misdreavus", "type": ["Fantasma"], "evo": "Pedra da Noite -> Mismagius", "folder": "misdreavus"},
    {"num": 201, "name": "Unown", "type": ["Psíquico"], "evo": "Ruínas de Alph", "folder": "unown"},
    {"num": 202, "name": "Wobbuffet", "type": ["Psíquico"], "evo": "Wynaut Lv 15", "folder": "wobbuffet"},
    {"num": 203, "name": "Girafarig", "type": ["Normal", "Psíquico"], "evo": "Twin Beam -> Farigiraf", "folder": "girafarig"},
    {"num": 204, "name": "Pineco", "type": ["Inseto"], "evo": "Lv 31 -> Forretress", "folder": "pineco"},
    {"num": 205, "name": "Forretress", "type": ["Inseto", "Aço"], "evo": "Forma Final", "folder": "forretress"},
    {"num": 206, "name": "Dunsparce", "type": ["Normal"], "evo": "Dark Cave", "folder": "dunsparce"},
    {"num": 207, "name": "Gligar", "type": ["Terra", "Voador"], "evo": "Razor Fang (Noite) -> Gliscor", "folder": "gligar"},
    {"num": 208, "name": "Steelix", "type": ["Aço", "Terra"], "evo": "Metal Coat de Onix", "folder": "steelix"},
    {"num": 209, "name": "Snubbull", "type": ["Fada"], "evo": "Lv 23 -> Granbull", "folder": "snubbull"},
    {"num": 210, "name": "Granbull", "type": ["Fada"], "evo": "Forma Final", "folder": "granbull"},
    {"num": 211, "name": "Qwilfish", "type": ["Água", "Veneno"], "evo": "Não evolui", "folder": "qwilfish"},
    {"num": 212, "name": "Scizor", "type": ["Inseto", "Aço"], "evo": "Metal Coat de Scyther", "folder": "scizor"},
    {"num": 213, "name": "Shuckle", "type": ["Inseto", "Pedra"], "evo": "Não evolui", "folder": "shuckle"},
    {"num": 214, "name": "Heracross", "type": ["Inseto", "Lutador"], "evo": "Não evolui (Árvores de Mel)", "folder": "heracross"},
    {"num": 215, "name": "Sneasel", "type": ["Sombrio", "Gelo"], "evo": "Razor Claw (Noite) -> Weavile", "folder": "sneasel"},
    {"num": 216, "name": "Teddiursa", "type": ["Normal"], "evo": "Lv 30 -> Ursaring", "folder": "teddiursa"},
    {"num": 217, "name": "Ursaring", "type": ["Normal"], "evo": "Forma Final", "folder": "ursaring"},
    {"num": 218, "name": "Slugma", "type": ["Fogo"], "evo": "Lv 38 -> Magcargo", "folder": "slugma"},
    {"num": 219, "name": "Magcargo", "type": ["Fogo", "Pedra"], "evo": "Forma Final", "folder": "magcargo"},
    {"num": 220, "name": "Swinub", "type": ["Gelo", "Terra"], "evo": "Lv 33 -> Piloswine", "folder": "swinub"},
    {"num": 221, "name": "Piloswine", "type": ["Gelo", "Terra"], "evo": "Ancient Power -> Mamoswine", "folder": "piloswine"},
    {"num": 222, "name": "Corsola", "type": ["Água", "Pedra"], "evo": "Não evolui", "folder": "corsola"},
    {"num": 223, "name": "Remoraid", "type": ["Água"], "evo": "Lv 25 -> Octillery", "folder": "remoraid"},
    {"num": 224, "name": "Octillery", "type": ["Água"], "evo": "Forma Final", "folder": "octillery"},
    {"num": 225, "name": "Delibird", "type": ["Gelo", "Voador"], "evo": "Ice Path", "folder": "delibird"},
    {"num": 226, "name": "Mantine", "type": ["Água", "Voador"], "evo": "Mantyke + Remoraid", "folder": "mantine"},
    {"num": 227, "name": "Skarmory", "type": ["Aço", "Voador"], "evo": "Não evolui", "folder": "skarmory"},
    {"num": 228, "name": "Houndour", "type": ["Sombrio", "Fogo"], "evo": "Lv 24 -> Houndoom", "folder": "houndour"},
    {"num": 229, "name": "Houndoom", "type": ["Sombrio", "Fogo"], "evo": "Forma Final", "folder": "houndoom"},
    {"num": 230, "name": "Kingdra", "type": ["Água", "Dragão"], "evo": "Dragon Scale de Seadra", "folder": "kingdra"},
    {"num": 231, "name": "Phanpy", "type": ["Terra"], "evo": "Lv 25 -> Donphan", "folder": "phanpy"},
    {"num": 232, "name": "Donphan", "type": ["Terra"], "evo": "Forma Final", "folder": "donphan"},
    {"num": 233, "name": "Porygon2", "type": ["Normal"], "evo": "Dubious Disc -> Porygon-Z", "folder": "porygon2"},
    {"num": 234, "name": "Stantler", "type": ["Normal"], "evo": "Shield Bash -> Wyrdeer", "folder": "stantler"},
    {"num": 235, "name": "Smeargle", "type": ["Normal"], "evo": "Ruínas de Alph", "folder": "smeargle"},
    {"num": 236, "name": "Tyrogue", "type": ["Lutador"], "evo": "Lv 20 -> Hitmonlee / Chan / Top", "folder": "tyrogue"},
    {"num": 237, "name": "Hitmontop", "type": ["Lutador"], "evo": "Tyrogue (Atk == Def)", "folder": "hitmontop"},
    {"num": 238, "name": "Smoochum", "type": ["Gelo", "Psíquico"], "evo": "Lv 30 -> Jynx", "folder": "smoochum"},
    {"num": 239, "name": "Elekid", "type": ["Elétrico"], "evo": "Lv 30 -> Electabuzz", "folder": "elekid"},
    {"num": 240, "name": "Magby", "type": ["Fogo"], "evo": "Lv 30 -> Magmar", "folder": "magby"},
    {"num": 241, "name": "Miltank", "type": ["Normal"], "evo": "Não evolui (Whitney Boss)", "folder": "miltank"},
    {"num": 242, "name": "Blissey", "type": ["Normal"], "evo": "Chansey + Felicidade Máxima", "folder": "blissey"},
    {"num": 243, "name": "Raikou", "type": ["Elétrico"], "evo": "Cão Lendário (Burned Tower)", "folder": "raikou"},
    {"num": 244, "name": "Entei", "type": ["Fogo"], "evo": "Cão Lendário (Burned Tower)", "folder": "entei"},
    {"num": 245, "name": "Suicune", "type": ["Água"], "evo": "Cão Lendário (Burned Tower)", "folder": "suicune"},
    {"num": 246, "name": "Larvitar", "type": ["Pedra", "Terra"], "evo": "Lv 30 -> Pupitar", "folder": "larvitar"},
    {"num": 247, "name": "Pupitar", "type": ["Pedra", "Terra"], "evo": "Lv 55 -> Tyranitar", "folder": "pupitar"},
    {"num": 248, "name": "Tyranitar", "type": ["Pedra", "Sombrio"], "evo": "Forma Final", "folder": "tyranitar"},
    {"num": 249, "name": "Lugia", "type": ["Psíquico", "Voador"], "evo": "Lendário Guardião (Navel Rock Lv 70)", "folder": "lugia"},
    {"num": 250, "name": "Ho-Oh", "type": ["Fogo", "Voador"], "evo": "Lendário Sagrado (Navel Rock Lv 70)", "folder": "ho_oh"},
    {"num": 251, "name": "Celebi", "type": ["Psíquico", "Planta"], "evo": "Mítico Viajante do Tempo (Ilex Forest)", "folder": "celebi"}
]

# Serializar encontros para JSON seguro em JS
routes_data_clean = []
for rname, rdata in sorted(routes_map.items()):
    if not (rdata['day'] or rdata['night'] or rdata['water'] or rdata['hidden']):
        continue
    routes_data_clean.append({
        'name': rname,
        'day': sorted(list(rdata['day'])),
        'night': sorted(list(rdata['night'])),
        'water': sorted(list(rdata['water'])),
        'hidden': sorted(list(rdata['hidden']))
    })

routes_json = json.dumps(routes_data_clean, ensure_ascii=False)
pokedex_json = json.dumps(pokedex_data, ensure_ascii=False)

# Dados estruturados dos Líderes de Ginásio e Chefes de Kanto e Johto
gym_bosses = [
    # KANTO
    {
        "id": "brock",
        "region": "kanto",
        "name": "Brock",
        "title": "O Treinador de Pedra Inabalável",
        "city": "Pewter City",
        "badge": "Insígnia Rocha",
        "badge_icon": "🪨",
        "type": "Pedra / Terra",
        "pic": "graphics/trainers/front_pics/leader_brock_front_pic.png",
        "team": [
            {"num": 74, "name": "Geodude", "lvl": 12},
            {"num": 95, "name": "Onix", "lvl": 14}
        ],
        "strategy": "Vulnerável a Água, Planta e Lutador. Bulbasaur (Vine Whip) e Squirtle (Bubble) vencem em um único golpe. Com Charmander, use Metal Claw ou capture Mankey (Low Kick) na Rota 22."
    },
    {
        "id": "misty",
        "region": "kanto",
        "name": "Misty",
        "title": "A Garota Moleca Sereia",
        "city": "Cerulean City",
        "badge": "Insígnia Cascata",
        "badge_icon": "💧",
        "type": "Água",
        "pic": "graphics/trainers/front_pics/leader_misty_front_pic.png",
        "team": [
            {"num": 120, "name": "Staryu", "lvl": 18},
            {"num": 121, "name": "Starmie", "lvl": 21}
        ],
        "strategy": "Starmie tem alta velocidade e usa Water Pulse com chance de confusão. Use Pikachu da Floresta de Viridian ou Bellsprout/Oddish da Rota 24. Golpes elétricos e de planta são essenciais."
    },
    {
        "id": "surge",
        "region": "kanto",
        "name": "Lt. Surge",
        "title": "O Relâmpago Americano",
        "city": "Vermilion City",
        "badge": "Insígnia Trovão",
        "badge_icon": "⚡",
        "type": "Elétrico",
        "pic": "graphics/trainers/front_pics/leader_lt_surge_front_pic.png",
        "team": [
            {"num": 100, "name": "Voltorb", "lvl": 21},
            {"num": 25, "name": "Pikachu", "lvl": 18},
            {"num": 26, "name": "Raichu", "lvl": 24}
        ],
        "strategy": "Capture um Diglett ou Dugtrio na Diglett's Cave ao lado de Vermilion. O tipo Terra é 100% imune aos choques de Raichu e o golpe Magnitude/Dig nocauteia sua equipe rapidamente."
    },
    {
        "id": "erika",
        "region": "kanto",
        "name": "Erika",
        "title": "A Princesa Apaixonada pela Natureza",
        "city": "Celadon City",
        "badge": "Insígnia Arco-Íris",
        "badge_icon": "🌸",
        "type": "Planta / Veneno",
        "pic": "graphics/trainers/front_pics/leader_erika_front_pic.png",
        "team": [
            {"num": 71, "name": "Victreebel", "lvl": 29},
            {"num": 114, "name": "Tangela", "lvl": 24},
            {"num": 45, "name": "Vileplume", "lvl": 29}
        ],
        "strategy": "Sua equipe usa pós de sono e paralisia. Traga Awakening/Cheri Berries. Use ataques de Fogo (Charizard, Flareon, Vulpix/Growlithe), Voador (Pidgeot) ou Psíquico (Kadabra/Alakazam)."
    },
    {
        "id": "koga",
        "region": "kanto",
        "name": "Koga",
        "title": "O Mestre Ninja Tóxico",
        "city": "Fuchsia City",
        "badge": "Insígnia Alma",
        "badge_icon": "☠️",
        "type": "Veneno",
        "pic": "graphics/trainers/front_pics/leader_koga_front_pic.png",
        "team": [
            {"num": 109, "name": "Koffing", "lvl": 37},
            {"num": 89, "name": "Muk", "lvl": 39},
            {"num": 109, "name": "Koffing", "lvl": 37},
            {"num": 110, "name": "Weezing", "lvl": 43}
        ],
        "strategy": "Cuidado com paredes invisíveis no ginásio. Muk usa Minimize e Toxic; Koffing/Weezing têm habilidade Levitate (imunes a Terremoto!). Golpes Psíquicos de Alakazam ou Kadabra liquidam sua equipe sem risco."
    },
    {
        "id": "sabrina",
        "region": "kanto",
        "name": "Sabrina",
        "title": "A Senhora dos Poderes Psíquicos",
        "city": "Saffron City",
        "badge": "Insígnia Pântano",
        "badge_icon": "🔮",
        "type": "Psíquico",
        "pic": "graphics/trainers/front_pics/leader_sabrina_front_pic.png",
        "team": [
            {"num": 64, "name": "Kadabra", "lvl": 38},
            {"num": 122, "name": "Mr. Mime", "lvl": 37},
            {"num": 49, "name": "Venomoth", "lvl": 38},
            {"num": 65, "name": "Alakazam", "lvl": 43}
        ],
        "strategy": "Alakazam tem velocidade avassaladora e alto Ataque Especial, mas Defesa Física de papel. Use golpes físicos potentes, ataques do tipo Sombrio (Bite/Crunch de Gyarados/Arcanine) ou Fantasma (Shadow Ball)."
    },
    {
        "id": "blaine",
        "region": "kanto",
        "name": "Blaine",
        "title": "O Mestre das Charadas Incandescentes",
        "city": "Cinnabar Island",
        "badge": "Insígnia Vulcão",
        "badge_icon": "🔥",
        "type": "Fogo",
        "pic": "graphics/trainers/front_pics/leader_blaine_front_pic.png",
        "team": [
            {"num": 58, "name": "Growlithe", "lvl": 42},
            {"num": 77, "name": "Ponyta", "lvl": 40},
            {"num": 78, "name": "Rapidash", "lvl": 42},
            {"num": 59, "name": "Arcanine", "lvl": 47}
        ],
        "strategy": "Pegue a Chave Secreta na Mansão Pokémon antes de entrar. Blaine depende de golpes de Fogo poderosos como Fire Blast. Use Pokémon de Água (Surfe de Blastoise, Lapras, Vaporeon) ou Terra/Pedra."
    },
    {
        "id": "giovanni",
        "region": "kanto",
        "name": "Giovanni",
        "title": "O Líder da Equipe Rocket",
        "city": "Viridian City",
        "badge": "Insígnia Terra",
        "badge_icon": "🌍",
        "type": "Terra",
        "pic": "graphics/trainers/front_pics/leader_giovanni_front_pic.png",
        "team": [
            {"num": 111, "name": "Rhyhorn", "lvl": 45},
            {"num": 51, "name": "Dugtrio", "lvl": 42},
            {"num": 31, "name": "Nidoqueen", "lvl": 44},
            {"num": 34, "name": "Nidoking", "lvl": 45},
            {"num": 112, "name": "Rhydon", "lvl": 50}
        ],
        "strategy": "O chefe final dos 8 ginásios de Kanto! Seus tipos Terra/Pedra sofrem fraqueza quádrupla para Água e Planta. Golpes como Surfe e Raio Solar / Giga Drain limpam sua equipe com facilidade."
    },
    # ELITE FOUR & RIVAL
    {
        "id": "lorelei",
        "region": "elite",
        "name": "Lorelei",
        "title": "Elite Four #1 — A Rainha do Gelo",
        "city": "Indigo Plateau",
        "badge": "Elite dos Quatro",
        "badge_icon": "🧊",
        "type": "Gelo / Água",
        "pic": "graphics/trainers/front_pics/elite_four_lorelei_front_pic.png",
        "team": [
            {"num": 87, "name": "Dewgong", "lvl": 54},
            {"num": 91, "name": "Cloyster", "lvl": 53},
            {"num": 80, "name": "Slowbro", "lvl": 54},
            {"num": 124, "name": "Jynx", "lvl": 56},
            {"num": 131, "name": "Lapras", "lvl": 56}
        ],
        "strategy": "Quase todos seus monstros combinam Gelo com Água. Use Pokémon Elétricos para Dewgong, Cloyster e Lapras, e golpes de Fogo/Sombrio contra Jynx. Cuidado com o Blizzard de Lapras!"
    },
    {
        "id": "bruno",
        "region": "elite",
        "name": "Bruno",
        "title": "Elite Four #2 — O Guerreiro dos Punhos de Ferro",
        "city": "Indigo Plateau",
        "badge": "Elite dos Quatro",
        "badge_icon": "🥋",
        "type": "Lutador / Pedra",
        "pic": "graphics/trainers/front_pics/elite_four_bruno_front_pic.png",
        "team": [
            {"num": 95, "name": "Onix", "lvl": 53},
            {"num": 107, "name": "Hitmonchan", "lvl": 55},
            {"num": 106, "name": "Hitmonlee", "lvl": 55},
            {"num": 95, "name": "Onix", "lvl": 56},
            {"num": 68, "name": "Machamp", "lvl": 58}
        ],
        "strategy": "Derrote os dois Onix com qualquer golpe de Água ou Planta (4x de dano). Para Hitmonlee, Hitmonchan e Machamp, golpes Psíquicos (Psychic) ou Voadores (Wing Attack/Fly) neutralizam seus contra-ataques."
    },
    {
        "id": "agatha",
        "region": "elite",
        "name": "Agatha",
        "title": "Elite Four #3 — A Sacerdotisa dos Espíritos",
        "city": "Indigo Plateau",
        "badge": "Elite dos Quatro",
        "badge_icon": "👻",
        "type": "Fantasma / Veneno",
        "pic": "graphics/trainers/front_pics/elite_four_agatha_front_pic.png",
        "team": [
            {"num": 94, "name": "Gengar", "lvl": 56},
            {"num": 42, "name": "Golbat", "lvl": 56},
            {"num": 93, "name": "Haunter", "lvl": 55},
            {"num": 24, "name": "Arbok", "lvl": 58},
            {"num": 94, "name": "Gengar", "lvl": 60}
        ],
        "strategy": "Todos os seus Pokémon possuem o tipo Veneno secundário! Um bom monstro Psíquico como Alakazam derruba quase toda a sua equipe. Cuidado com Confuse Ray e Hypnosis."
    },
    {
        "id": "lance",
        "region": "elite",
        "name": "Lance",
        "title": "Elite Four #4 — O Domador dos Dragões",
        "city": "Indigo Plateau",
        "badge": "Líder da Elite Four",
        "badge_icon": "🐲",
        "type": "Dragão / Voador",
        "pic": "graphics/trainers/front_pics/elite_four_lance_front_pic.png",
        "team": [
            {"num": 130, "name": "Gyarados", "lvl": 58},
            {"num": 148, "name": "Dragonair", "lvl": 56},
            {"num": 148, "name": "Dragonair", "lvl": 56},
            {"num": 142, "name": "Aerodactyl", "lvl": 60},
            {"num": 149, "name": "Dragonite", "lvl": 62}
        ],
        "strategy": "Gyarados cai com 1 golpe Elétrico (4x dano). Aerodactyl é fraco contra Água, Elétrico e Gelo. Contra Dragonite e os Dragonairs, golpes de Gelo (Ice Beam / Blizzard) causam dano quadruplicado devastador!"
    },
    {
        "id": "blue",
        "region": "elite",
        "name": "Blue (Rival)",
        "title": "O Novo Campeão de Kanto",
        "city": "Indigo Plateau",
        "badge": "Campeão da Liga",
        "badge_icon": "👑",
        "type": "Equipe Balanceada",
        "pic": "graphics/trainers/front_pics/champion_rival_front_pic.png",
        "team": [
            {"num": 18, "name": "Pidgeot", "lvl": 61},
            {"num": 65, "name": "Alakazam", "lvl": 59},
            {"num": 112, "name": "Rhydon", "lvl": 61},
            {"num": 103, "name": "Exeggutor", "lvl": 61},
            {"num": 130, "name": "Gyarados", "lvl": 63},
            {"num": 6, "name": "Charizard", "lvl": 65}
        ],
        "strategy": "Equipe altamente equilibrada e veloz. Alterne seus Pokémon para explorar cada fraqueza: Elétrico para Pidgeot e Gyarados; Água/Gelo para Rhydon; Fogo/Gelo para Exeggutor; Sombrio para Alakazam."
    },
    # JOHTO (NÍVEIS 58 A 85+)
    {
        "id": "falkner",
        "region": "johto",
        "name": "Falkner",
        "title": "O Mestre dos Céus de Johto",
        "city": "Violet City",
        "badge": "Insígnia Asas",
        "badge_icon": "🪶",
        "type": "Voador",
        "pic": "graphics/trainers/johto/falkner.png",
        "team": [
            {"num": 18, "name": "Pidgeot", "lvl": 58},
            {"num": 164, "name": "Noctowl", "lvl": 60}
        ],
        "strategy": "Nível 58+. O primeiro ginásio de Johto já exige uma equipe pós-Liga! Pidgeot e Noctowl caem facilmente com ataques Elétricos (Thunderbolt), de Gelo (Ice Beam) ou Pedra."
    },
    {
        "id": "bugsy",
        "region": "johto",
        "name": "Bugsy",
        "title": "A Enciclopédia Ambulante de Insetos",
        "city": "Azalea Town",
        "badge": "Insígnia Colmeia",
        "badge_icon": "🪲",
        "type": "Inseto",
        "pic": "graphics/trainers/johto/bugsy.png",
        "team": [
            {"num": 212, "name": "Scizor", "lvl": 62},
            {"num": 214, "name": "Heracross", "lvl": 63}
        ],
        "strategy": "Scizor possui o tipo Inseto/Aço: imune a quase tudo, exceto FOGO (que causa 4x de dano letal!). Heracross sofre 4x para golpes Voadores e também é fraco a Fogo e Psíquico."
    },
    {
        "id": "whitney",
        "region": "johto",
        "name": "Whitney",
        "title": "A Doce e Temível Menina Prodígio",
        "city": "Goldenrod City",
        "badge": "Insígnia Planície",
        "badge_icon": "⭐",
        "type": "Normal / Fada",
        "pic": "graphics/trainers/johto/whitney.png",
        "team": [
            {"num": 36, "name": "Clefable", "lvl": 65},
            {"num": 241, "name": "Miltank", "lvl": 67}
        ],
        "strategy": "O terror dos jogadores! Miltank usa Rollout e Milk Drink em nível 67+. Use um monstro de Pedra resistente (Rhydon, Golem, Tyranitar) ou um tipo Lutador forte (Machamp, Heracross) para nocauteá-la antes do Rollout acumular."
    },
    {
        "id": "morty",
        "region": "johto",
        "name": "Morty",
        "title": "O Místico Iluminado de Ecruteak",
        "city": "Ecruteak City",
        "badge": "Insígnia Névoa",
        "badge_icon": "👻",
        "type": "Fantasma",
        "pic": "graphics/trainers/johto/morty.png",
        "team": [
            {"num": 93, "name": "Haunter", "lvl": 70},
            {"num": 94, "name": "Gengar", "lvl": 72}
        ],
        "strategy": "Gengar possui Shadow Ball e Spite em altíssimo nível. Ataques do tipo Sombrio (Houndoom, Umbreon, Tyranitar) ou Psíquico (Alakazam, Espeon) vencem a partida sem dificuldade."
    },
    {
        "id": "chuck",
        "region": "johto",
        "name": "Chuck",
        "title": "O Rugido Furioso dos Mares",
        "city": "Cianwood City",
        "badge": "Insígnia Tempestade",
        "badge_icon": "🥊",
        "type": "Lutador",
        "pic": "graphics/trainers/johto/chuck.png",
        "team": [
            {"num": 57, "name": "Primeape", "lvl": 72},
            {"num": 62, "name": "Poliwrath", "lvl": 74}
        ],
        "strategy": "Primeape bate forte e Poliwrath usa golpes aquáticos e de submissão. Voadores (Pidgeot, Lugia, Crobat) ou Psíquicos (Alakazam) são imbatíveis contra sua formação."
    },
    {
        "id": "jasmine",
        "region": "johto",
        "name": "Jasmine",
        "title": "A Garota com a Vontade de Aço",
        "city": "Olivine City",
        "badge": "Insígnia Mineral",
        "badge_icon": "⚙️",
        "type": "Aço",
        "pic": "graphics/trainers/johto/jasmine.png",
        "team": [
            {"num": 81, "name": "Magnemite", "lvl": 75},
            {"num": 208, "name": "Steelix", "lvl": 77}
        ],
        "strategy": "Após curar o Ampharos no Farol de Olivine, enfrente Jasmine. Steelix possui defesa física monumental. Golpes Especiais de Fogo (Flamethrower) ou Terremoto derretem seu corpo de aço."
    },
    {
        "id": "pryce",
        "region": "johto",
        "name": "Pryce",
        "title": "O Mestre do Inverno Eterno",
        "city": "Mahogany Town",
        "badge": "Insígnia Glaciar",
        "badge_icon": "❄️",
        "type": "Gelo",
        "pic": "graphics/trainers/johto/pryce.png",
        "team": [
            {"num": 87, "name": "Dewgong", "lvl": 78},
            {"num": 221, "name": "Piloswine", "lvl": 80}
        ],
        "strategy": "Piloswine (Gelo/Terra) sofre dano severo de Água, Planta, Fogo e Lutador. Dewgong é vulnerável a Elétrico e Planta. Traga monstro com boa velocidade para não levar Blizzard."
    },
    {
        "id": "clair",
        "region": "johto",
        "name": "Clair",
        "title": "A Donzela Bendita dos Dragões",
        "city": "Blackthorn City",
        "badge": "Insígnia Ascensão",
        "badge_icon": "🐉",
        "type": "Dragão",
        "pic": "graphics/trainers/johto/clair.png",
        "team": [
            {"num": 148, "name": "Dragonair", "lvl": 82},
            {"num": 230, "name": "Kingdra", "lvl": 85}
        ],
        "strategy": "O ginásio mais difícil de Johto! Kingdra é Água/Dragão: imune a fraquezas comuns de água e dragão, sofrendo dano dobrado APENAS para golpes de Dragão e Fada! Use Togekiss, Clefable ou Dragonite veloz com Outrage."
    },
    # FINAL BOSS: RED
    {
        "id": "red",
        "region": "red",
        "name": "Red (Campeão Lendário)",
        "title": "O Maior Treinador de Todos os Tempos",
        "city": "Cume do Monte Silver",
        "badge": "O Mestre Supremo",
        "badge_icon": "🏆",
        "type": "Equipe Lendária Nível 95-100",
        "pic": "graphics/trainers/front_pics/red_front_pic.png",
        "team": [
            {"num": 25, "name": "Pikachu", "lvl": 100},
            {"num": 6, "name": "Charizard", "lvl": 98},
            {"num": 9, "name": "Blastoise", "lvl": 98},
            {"num": 3, "name": "Venusaur", "lvl": 98},
            {"num": 143, "name": "Snorlax", "lvl": 97},
            {"num": 131, "name": "Lapras", "lvl": 96}
        ],
        "strategy": "A batalha definitiva! O clima de Nevasca/Granizo causará dano a cada turno. Pikachu carrega Light Ball (dobro de ataque) e deve ser derrubado com Terremoto antes de agir. Snorlax usa Rest/Body Slam e exige ataques potentes do tipo Lutador. Tenha uma equipe balanceada com nível 95+!"
    }
]

gym_bosses_json = json.dumps(gym_bosses, ensure_ascii=False)

html_template = f"""<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wiki & Pokédex Oficial — Pokémon Kanto & Johto</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Outfit:wght@500;600;700;800;900&family=Inter:wght@400;500;600;700&display=swap" rel="stylesheet">
    <style>
        :root {{
            --bg-body: #0b0e14;
            --bg-sidebar: #111622;
            --bg-card: rgba(23, 29, 43, 0.75);
            --border-color: rgba(255, 255, 255, 0.08);
            --primary: #ef4444;
            --secondary: #3b82f6;
            --accent: #f59e0b;
            --text-main: #f1f5f9;
            --text-muted: #94a3b8;
        }}

        * {{
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }}

        body {{
            font-family: 'Inter', sans-serif;
            background-color: var(--bg-body);
            color: var(--text-main);
            display: flex;
            min-height: 100vh;
            line-height: 1.6;
        }}

        /* ====================
           SIDEBAR DE NAVEGAÇÃO
           ==================== */
        #sidebar {{
            width: 280px;
            background-color: var(--bg-sidebar);
            border-right: 1px solid var(--border-color);
            position: fixed;
            top: 0;
            bottom: 0;
            left: 0;
            display: flex;
            flex-direction: column;
            z-index: 100;
            transition: transform 0.3s ease;
        }}

        .sidebar-brand {{
            padding: 1.25rem 1.25rem 0.75rem;
            border-bottom: 1px solid var(--border-color);
        }}

        .brand-title {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.2rem;
            font-weight: 900;
            background: linear-gradient(135deg, #f87171, #ef4444, #fbbf24);
            -webkit-background-clip: text;
            -webkit-text-fill-color: transparent;
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }}

        .brand-sub {{
            font-size: 0.75rem;
            color: var(--text-muted);
            margin-top: 2px;
        }}

        .search-area {{
            padding: 0.75rem 1.25rem;
            border-bottom: 1px solid var(--border-color);
        }}

        .global-search-input {{
            width: 100%;
            background: rgba(15, 20, 31, 0.8);
            border: 1px solid var(--border-color);
            border-radius: 8px;
            padding: 0.6rem 0.8rem 0.6rem 2rem;
            color: white;
            font-size: 0.85rem;
            outline: none;
            transition: all 0.2s;
        }}

        .global-search-input:focus {{
            border-color: var(--primary);
            box-shadow: 0 0 10px rgba(239, 68, 68, 0.3);
        }}

        .search-wrap {{
            position: relative;
        }}

        .search-wrap::before {{
            content: "🔍";
            position: absolute;
            left: 0.65rem;
            top: 50%;
            transform: translateY(-50%);
            font-size: 0.75rem;
            opacity: 0.6;
        }}

        .nav-menu {{
            flex: 1;
            overflow-y: auto;
            padding: 0.75rem;
            display: flex;
            flex-direction: column;
            gap: 0.25rem;
        }}

        .nav-item {{
            display: flex;
            align-items: center;
            gap: 0.75rem;
            padding: 0.7rem 0.9rem;
            border-radius: 8px;
            color: var(--text-muted);
            text-decoration: none;
            font-size: 0.85rem;
            font-weight: 600;
            transition: all 0.2s;
            cursor: pointer;
            border: 1px solid transparent;
        }}

        .nav-item:hover {{
            background: rgba(255, 255, 255, 0.05);
            color: white;
        }}

        .nav-item.active {{
            background: rgba(239, 68, 68, 0.12);
            color: #f87171;
            border-color: rgba(239, 68, 68, 0.3);
        }}

        .sidebar-footer {{
            padding: 1rem 1.25rem;
            border-top: 1px solid var(--border-color);
            font-size: 0.75rem;
            color: var(--text-muted);
            display: flex;
            justify-content: space-between;
            align-items: center;
        }}

        /* ====================
           CONTEÚDO PRINCIPAL
           ==================== */
        #content {{
            margin-left: 280px;
            flex: 1;
            padding: 2.5rem 3rem;
            max-width: 1350px;
        }}

        .section-pane {{
            display: none;
            animation: fadeIn 0.3s ease;
        }}

        .section-pane.active {{
            display: block;
        }}

        @keyframes fadeIn {{
            from {{ opacity: 0; transform: translateY(6px); }}
            to {{ opacity: 1; transform: translateY(0); }}
        }}

        .pane-header {{
            margin-bottom: 2rem;
            border-bottom: 1px solid var(--border-color);
            padding-bottom: 1.25rem;
        }}

        .pane-header h1 {{
            font-family: 'Outfit', sans-serif;
            font-size: 2.2rem;
            font-weight: 800;
            margin-bottom: 0.4rem;
        }}

        .pane-header p {{
            color: var(--text-muted);
            font-size: 0.95rem;
        }}

        /* ====================
           CARDS & COMPONENTES
           ==================== */
        .wiki-card {{
            background: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 14px;
            padding: 1.5rem;
            margin-bottom: 1.5rem;
            backdrop-filter: blur(12px);
            box-shadow: 0 4px 20px rgba(0, 0, 0, 0.2);
            transition: all 0.25s ease;
        }}

        .wiki-card:hover {{
            border-color: rgba(255, 255, 255, 0.18);
            transform: translateY(-2px);
        }}

        .wiki-card-header {{
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 1rem;
        }}

        .wiki-card-header h3 {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.3rem;
            color: white;
        }}

        .tag-pill {{
            font-size: 0.75rem;
            padding: 0.2rem 0.6rem;
            border-radius: 9999px;
            background: rgba(255, 255, 255, 0.08);
            color: var(--text-muted);
            font-weight: 600;
        }}

        .card-grid-2 {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(420px, 1fr));
            gap: 1.5rem;
        }}

        .card-grid-3 {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
            gap: 1.25rem;
        }}

        /* ====================
           BANNERS DE CIDADES
           ==================== */
        .city-banner-box {{
            width: 100%;
            height: 190px;
            border-radius: 12px;
            overflow: hidden;
            position: relative;
            margin-bottom: 1.25rem;
            box-shadow: 0 8px 24px rgba(0, 0, 0, 0.4);
            border: 1px solid rgba(255, 255, 255, 0.1);
        }}

        .city-banner-img {{
            width: 100%;
            height: 100%;
            object-fit: cover;
            transition: transform 0.45s ease;
        }}

        .city-banner-box:hover .city-banner-img {{
            transform: scale(1.05);
        }}

        .city-banner-overlay {{
            position: absolute;
            inset: 0;
            background: linear-gradient(180deg, rgba(0,0,0,0.1) 0%, rgba(11, 14, 20, 0.88) 95%);
            display: flex;
            flex-direction: column;
            justify-content: flex-end;
            padding: 1.25rem;
        }}

        .city-banner-title {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.4rem;
            font-weight: 900;
            color: white;
            text-shadow: 0 2px 10px rgba(0,0,0,0.9);
            display: flex;
            align-items: center;
            gap: 0.6rem;
        }}

        .city-poi-bar {{
            display: flex;
            flex-wrap: wrap;
            gap: 0.5rem;
            margin-top: 0.4rem;
        }}

        .city-poi-badge {{
            background: rgba(15, 23, 42, 0.75);
            backdrop-filter: blur(8px);
            border: 1px solid rgba(255, 255, 255, 0.15);
            border-radius: 6px;
            padding: 0.2rem 0.6rem;
            font-size: 0.75rem;
            color: #e2e8f0;
            font-weight: 500;
        }}

        /* ====================
           POKÉDEX INTERATIVA
           ==================== */
        .pokedex-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(210px, 1fr));
            gap: 1.25rem;
        }}

        .mon-card {{
            background: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 16px;
            padding: 1rem;
            display: flex;
            flex-direction: column;
            align-items: center;
            position: relative;
            overflow: hidden;
            transition: all 0.25s cubic-bezier(0.4, 0, 0.2, 1);
            box-shadow: 0 4px 14px rgba(0, 0, 0, 0.25);
            backdrop-filter: blur(12px);
            cursor: pointer;
        }}

        .mon-card:hover {{
            transform: translateY(-5px);
            box-shadow: 0 12px 28px rgba(0, 0, 0, 0.5);
            border-color: rgba(255, 255, 255, 0.25);
        }}

        .mon-card-header {{
            width: 100%;
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 0.25rem;
        }}

        .mon-number {{
            font-family: 'Outfit', sans-serif;
            font-size: 0.85rem;
            font-weight: 800;
            color: var(--text-muted);
            letter-spacing: 0.5px;
        }}

        .mon-sprite-box {{
            width: 100px;
            height: 100px;
            display: flex;
            align-items: center;
            justify-content: center;
            margin: 0.25rem 0 0.5rem;
            position: relative;
        }}

        .mon-sprite-box::after {{
            content: '';
            position: absolute;
            width: 75px;
            height: 18px;
            background: radial-gradient(ellipse, rgba(0,0,0,0.45) 0%, transparent 70%);
            bottom: 4px;
            z-index: 1;
        }}

        .mon-sprite {{
            width: 84px;
            height: 84px;
            object-fit: contain;
            image-rendering: pixelated;
            z-index: 2;
            transition: transform 0.25s ease;
            filter: drop-shadow(0 4px 8px rgba(0,0,0,0.4));
        }}

        .mon-card:hover .mon-sprite {{
            transform: scale(1.15);
        }}

        .mon-name {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.05rem;
            font-weight: 800;
            color: white;
            margin-bottom: 0.35rem;
            text-align: center;
        }}

        .mon-types {{
            display: flex;
            gap: 0.3rem;
            margin-bottom: 0.6rem;
        }}

        .type-badge {{
            font-size: 0.68rem;
            font-weight: 700;
            padding: 0.2rem 0.5rem;
            border-radius: 6px;
            text-transform: uppercase;
            letter-spacing: 0.5px;
            color: white;
        }}

        .type-Planta {{ background: linear-gradient(135deg, #16a34a, #15803d); }}
        .type-Veneno {{ background: linear-gradient(135deg, #9333ea, #7e22ce); }}
        .type-Fogo {{ background: linear-gradient(135deg, #ea580c, #c2410c); }}
        .type-Água {{ background: linear-gradient(135deg, #0284c7, #0369a1); }}
        .type-Inseto {{ background: linear-gradient(135deg, #65a30d, #4d7c0f); }}
        .type-Normal {{ background: linear-gradient(135deg, #78716c, #57534e); }}
        .type-Elétrico {{ background: linear-gradient(135deg, #eab308, #ca8a04); color: #000; }}
        .type-Terra {{ background: linear-gradient(135deg, #d97706, #b45309); }}
        .type-Fada {{ background: linear-gradient(135deg, #f472b6, #db2777); }}
        .type-Lutador {{ background: linear-gradient(135deg, #b91c1c, #991b1b); }}
        .type-Psíquico {{ background: linear-gradient(135deg, #ec4899, #be185d); }}
        .type-Pedra {{ background: linear-gradient(135deg, #a16207, #854d0e); }}
        .type-Fantasma {{ background: linear-gradient(135deg, #6b21a8, #581c87); }}
        .type-Gelo {{ background: linear-gradient(135deg, #06b6d4, #0891b2); }}
        .type-Dragão {{ background: linear-gradient(135deg, #4f46e5, #3730a3); }}
        .type-Aço {{ background: linear-gradient(135deg, #64748b, #475569); }}
        .type-Sombrio {{ background: linear-gradient(135deg, #334155, #1e293b); }}
        .type-Voador {{ background: linear-gradient(135deg, #38bdf8, #0284c7); }}

        .mon-evo-note {{
            font-size: 0.72rem;
            color: var(--text-muted);
            text-align: center;
            background: rgba(0, 0, 0, 0.3);
            border-radius: 6px;
            padding: 0.3rem 0.5rem;
            width: 100%;
            border: 1px solid rgba(255, 255, 255, 0.05);
        }}

        /* Filtro de Tipos */
        .type-filter-bar {{
            display: flex;
            flex-wrap: wrap;
            gap: 0.5rem;
            margin-bottom: 1.5rem;
        }}

        .type-filter-btn {{
            background: rgba(255, 255, 255, 0.05);
            border: 1px solid var(--border-color);
            color: var(--text-muted);
            padding: 0.4rem 0.8rem;
            border-radius: 8px;
            font-size: 0.8rem;
            font-weight: 600;
            cursor: pointer;
            transition: all 0.2s;
        }}

        .type-filter-btn:hover, .type-filter-btn.active {{
            background: var(--primary);
            color: white;
            border-color: var(--primary);
        }}

        /* ====================
           LÍDERES DE GINÁSIO & CHEFES
           ==================== */
        .boss-tab-bar {{
            display: flex;
            gap: 0.75rem;
            margin-bottom: 1.5rem;
            border-bottom: 1px solid var(--border-color);
            padding-bottom: 0.75rem;
        }}

        .boss-tab-btn {{
            background: rgba(255, 255, 255, 0.05);
            border: 1px solid var(--border-color);
            color: var(--text-muted);
            padding: 0.5rem 1rem;
            border-radius: 8px;
            font-size: 0.85rem;
            font-weight: 700;
            cursor: pointer;
            transition: all 0.2s;
        }}

        .boss-tab-btn.active {{
            background: rgba(239, 68, 68, 0.2);
            color: #f87171;
            border-color: var(--primary);
        }}

        .gym-boss-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(380px, 1fr));
            gap: 1.5rem;
            margin-bottom: 2rem;
        }}

        .gym-boss-card {{
            background: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 16px;
            padding: 1.35rem;
            display: flex;
            flex-direction: column;
            gap: 1rem;
            position: relative;
            overflow: hidden;
            backdrop-filter: blur(12px);
            box-shadow: 0 4px 18px rgba(0, 0, 0, 0.25);
            transition: all 0.25s ease;
        }}

        .gym-boss-card:hover {{
            border-color: rgba(239, 68, 68, 0.4);
            box-shadow: 0 8px 26px rgba(239, 68, 68, 0.18);
            transform: translateY(-3px);
        }}

        .gym-boss-header {{
            display: flex;
            align-items: center;
            gap: 1rem;
            border-bottom: 1px solid var(--border-color);
            padding-bottom: 0.85rem;
        }}

        .gym-boss-pic {{
            width: 74px;
            height: 74px;
            border-radius: 12px;
            background: rgba(0, 0, 0, 0.4);
            border: 1px solid var(--border-color);
            object-fit: contain;
            image-rendering: pixelated;
            padding: 4px;
            box-shadow: inset 0 2px 6px rgba(0,0,0,0.5);
        }}

        .gym-boss-info {{
            flex: 1;
        }}

        .gym-boss-name {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.25rem;
            font-weight: 800;
            color: #fff;
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }}

        .gym-badge-tag {{
            font-size: 0.8rem;
            color: var(--accent);
            font-weight: 700;
            margin-top: 0.15rem;
        }}

        .gym-loc-type {{
            font-size: 0.75rem;
            color: var(--text-muted);
            margin-top: 0.2rem;
        }}

        .gym-team-box {{
            display: flex;
            flex-direction: column;
            gap: 0.4rem;
        }}

        .gym-team-label {{
            font-size: 0.75rem;
            color: var(--text-muted);
            text-transform: uppercase;
            font-weight: 700;
            letter-spacing: 0.5px;
        }}

        .gym-mon-list {{
            display: flex;
            flex-wrap: wrap;
            gap: 0.5rem;
        }}

        .gym-mon-chip {{
            display: flex;
            align-items: center;
            gap: 0.4rem;
            background: rgba(0, 0, 0, 0.35);
            border: 1px solid rgba(255, 255, 255, 0.08);
            border-radius: 8px;
            padding: 0.3rem 0.6rem;
            font-size: 0.8rem;
        }}

        .gym-mon-sprite {{
            width: 32px;
            height: 32px;
            image-rendering: pixelated;
            filter: drop-shadow(0 2px 4px rgba(0,0,0,0.5));
        }}

        .gym-strategy-box {{
            background: rgba(239, 68, 68, 0.08);
            border-left: 3px solid var(--primary);
            padding: 0.65rem 0.85rem;
            border-radius: 0 8px 8px 0;
            font-size: 0.82rem;
            line-height: 1.5;
            color: #cbd5e1;
        }}

        /* ====================
           ROTAS E ENCONTROS
           ==================== */
        .encounter-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(360px, 1fr));
            gap: 1.25rem;
        }}

        .route-card {{
            background: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 12px;
            padding: 1.25rem;
        }}

        .route-title {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.15rem;
            font-weight: 700;
            color: white;
            border-bottom: 1px solid var(--border-color);
            padding-bottom: 0.5rem;
            margin-bottom: 0.75rem;
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }}

        .enc-group {{
            margin-bottom: 0.6rem;
        }}

        .enc-group-title {{
            font-size: 0.75rem;
            font-weight: 700;
            text-transform: uppercase;
            letter-spacing: 0.5px;
            margin-bottom: 0.3rem;
            display: flex;
            align-items: center;
            gap: 0.3rem;
        }}

        .enc-group-title.day {{ color: #fbbf24; }}
        .enc-group-title.night {{ color: #a78bfa; }}
        .enc-group-title.water {{ color: #38bdf8; }}
        .enc-group-title.hidden {{ color: #4ade80; }}

        .mon-tag-list {{
            display: flex;
            flex-wrap: wrap;
            gap: 0.35rem;
        }}

        .mon-tag {{
            font-size: 0.75rem;
            background: rgba(0, 0, 0, 0.35);
            padding: 0.2rem 0.5rem;
            border-radius: 6px;
            border: 1px solid rgba(255, 255, 255, 0.05);
        }}

        /* ====================
           TABELAS DE DADOS
           ==================== */
        .data-table {{
            width: 100%;
            border-collapse: collapse;
            font-size: 0.85rem;
            margin-top: 0.5rem;
        }}

        .data-table th, .data-table td {{
            padding: 0.75rem 1rem;
            text-align: left;
            border-bottom: 1px solid var(--border-color);
        }}

        .data-table th {{
            background: rgba(255, 255, 255, 0.03);
            color: var(--text-muted);
            font-weight: 700;
            text-transform: uppercase;
            font-size: 0.75rem;
            letter-spacing: 0.5px;
        }}

        .data-table tr:hover {{
            background: rgba(255, 255, 255, 0.02);
        }}

        .info-box {{
            background: rgba(59, 130, 246, 0.1);
            border-left: 4px solid var(--secondary);
            padding: 1rem;
            border-radius: 0 8px 8px 0;
            margin: 1rem 0;
            font-size: 0.88rem;
        }}

        .info-box.warn {{
            background: rgba(245, 158, 11, 0.1);
            border-color: var(--accent);
        }}

        /* Responsividade */
        @media (max-width: 900px) {{
            #sidebar {{
                transform: translateX(-100%);
            }}
            #sidebar.open {{
                transform: translateX(0);
            }}
            #content {{
                margin-left: 0;
                padding: 1.5rem;
            }}
            .card-grid-2, .gym-boss-grid {{
                grid-template-columns: 1fr;
            }}
        }}
    </style>
</head>
<body>

    <!-- SIDEBAR -->
    <aside id="sidebar">
        <div class="sidebar-brand">
            <div class="brand-title">
                <span>🔥</span> POKÉMON KANTO & JOHTO
            </div>
            <div class="brand-sub">Wiki & Pokédex Oficial v2.0</div>
        </div>

        <div class="search-area">
            <div class="search-wrap">
                <input type="text" id="globalSearch" class="global-search-input" placeholder="Buscar em todo o guia..." oninput="handleGlobalSearch(this.value)">
            </div>
        </div>

        <nav class="nav-menu">
            <a class="nav-item active" onclick="switchPane('pane-home')">
                <span>🏠</span> Visão Geral & Recursos
            </a>
            <a class="nav-item" onclick="switchPane('pane-walkthrough-kanto')">
                <span>🗾</span> Detonado: Kanto (8 Badges)
            </a>
            <a class="nav-item" onclick="switchPane('pane-walkthrough-johto')">
                <span>🚄</span> Detonado: Johto & Red
            </a>
            <a class="nav-item" onclick="switchPane('pane-gyms')">
                <span>🥊</span> Ginásios & Chefes
            </a>
            <a class="nav-item" onclick="switchPane('pane-pokedex')">
                <span>📖</span> Pokédex Completa (251)
            </a>
            <a class="nav-item" onclick="switchPane('pane-encounters')">
                <span>🧭</span> Rotas & Encontros (Dia/Noite)
            </a>
            <a class="nav-item" onclick="switchPane('pane-items')">
                <span>🎁</span> TMs, HMs & Itens Raros
            </a>
            <a class="nav-item" onclick="switchPane('pane-controls')">
                <span>🎮</span> Controles & Dicas APK
            </a>
        </nav>

        <div class="sidebar-footer">
            <span>Criado com ❤️ para GBA & APK</span>
            <span>2026</span>
        </div>
    </aside>

    <!-- MAIN CONTENT -->
    <main id="content">

        <!-- 1. HOME / VISÃO GERAL -->
        <section id="pane-home" class="section-pane active">
            <div class="pane-header">
                <h1>Bem-vindo à Enciclopédia Definitiva</h1>
                <p>Guia interativo oficial da hack rom Pokémon Kanto & Johto. Explore as duas regiões, consulte encontros em tempo real, estratégias de chefes e muito mais.</p>
            </div>

            <div class="card-grid-2">
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>⭐ Destaques desta Versão</h3>
                        <span class="tag-pill">QoL & Novidades</span>
                    </div>
                    <ul style="padding-left: 1.25rem; display: flex; flex-direction: column; gap: 0.5rem; font-size: 0.9rem;">
                        <li><b>HMs sem Escravo de HM:</b> Use Cortar, Surfe, Força, Flash e Quebrar Rocha direto no mapa se você tiver a insígnia correspondente!</li>
                        <li><b>EXP ao Capturar:</b> Ganhe 100% dos pontos de experiência mesmo ao capturar o monstro.</li>
                        <li><b>Ciclo de Dia e Noite Dinâmico:</b> Cores e encontros mudam de acordo com o horário real (Manhã, Dia, Tarde e Noite).</li>
                        <li><b>Pokédex Expandida com Tipo Fada:</b> 251 Pokémon com evoluções por troca convertidas para nível ou pedras.</li>
                        <li><b>Johto Completo de Alto Nível:</b> Enfrente os 8 Líderes de Johto dos níveis 58 a 85 e enfrente Red (Lv 100) no cume do Monte Silver!</li>
                    </ul>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>⚡ Acesso Rápido</h3>
                        <span class="tag-pill">Atalhos</span>
                    </div>
                    <div class="card-grid-2" style="gap: 0.75rem;">
                        <button class="type-filter-btn" style="text-align: left; padding: 0.8rem;" onclick="switchPane('pane-pokedex')">
                            <b>📖 Pokédex 251</b><br><small>Sprites, evoluções e tipos</small>
                        </button>
                        <button class="type-filter-btn" style="text-align: left; padding: 0.8rem;" onclick="switchPane('pane-gyms')">
                            <b>🥊 Mural dos Chefes</b><br><small>Fraquezas e equipes</small>
                        </button>
                        <button class="type-filter-btn" style="text-align: left; padding: 0.8rem;" onclick="switchPane('pane-encounters')">
                            <b>🧭 Mapa de Rotas</b><br><small>Onde capturar Dia & Noite</small>
                        </button>
                        <button class="type-filter-btn" style="text-align: left; padding: 0.8rem;" onclick="switchPane('pane-items')">
                            <b>🎁 Onde achar TMs & HMs</b><br><small>Localização de máquinas</small>
                        </button>
                    </div>
                </div>
            </div>
        </section>

        <!-- 2. DETONADO KANTO -->
        <section id="pane-walkthrough-kanto" class="section-pane">
            <div class="pane-header">
                <h1>🗾 Detonado Passo a Passo: Região de Kanto</h1>
                <p>O roteiro otimizado para conquistar as 8 insígnias, derrotar a Equipe Rocket e vencer a Liga Pokémon no Planalto Índigo.</p>
            </div>

            <div class="card-grid-2">
                <!-- Pallet Town -->
                <div class="wiki-card">
                    <div class="city-banner-box">
                        <img class="city-banner-img" src="graphics/cities/pallet_town_banner.jpg" alt="Pallet Town">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">🏡 Pallet Town & O Início</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🔬 Laboratório do Carvalho</span>
                        <span class="city-poi-badge">🎁 Iniciais: Bulbasaur, Charmander, Squirtle</span>
                        <span class="city-poi-badge">📦 Encomenda do Carvalho</span>
                    </div>
                    <p>1. Desça até a grama alta ao norte para ser interceptado pelo Prof. Carvalho.<br>
                    2. Escolha seu parceiro inicial e vença a primeira batalha contra o Rival Blue.<br>
                    3. Suba a <b>Rota 1</b> até Viridian City, pegue o Pacote do Carvalho no Poké Mart e entregue em Pallet para desbloquear a <b>Pokédex</b> e 5 Poké Balls!</p>
                </div>

                <!-- Viridian Forest & Pewter -->
                <div class="wiki-card">
                    <div class="city-banner-box">
                        <img class="city-banner-img" src="graphics/cities/viridian_forest_banner.jpg" alt="Viridian Forest">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">🌲 Viridian Forest & Pewter City</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">⚡ Pikachu (5% na Floresta)</span>
                        <span class="city-poi-badge">🪨 Ginásio de Pewter (Brock)</span>
                        <span class="city-poi-badge">🏆 Insígnia Rocha</span>
                    </div>
                    <p>1. Na Floresta de Viridian, capture <b>Caterpie</b> (evoluir para Butterfree com Confusion no Lv 10) ou <b>Pikachu</b>.<br>
                    2. Chegue a Pewter City e desafie o primeiro Líder de Ginásio: <b>Brock</b>.<br>
                    3. Se começou com Charmander, capture <b>Mankey</b> na Rota 22 à esquerda de Viridian (Low Kick vence Onix em dois turnos!).</p>
                </div>

                <!-- Cerulean & Ponte Pepita -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 3: Mt. Moon, Cerulean & Misty</h3>
                        <span class="tag-pill">Insígnia Cascata</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🌙 Pedra da Lua</span>
                        <span class="city-poi-badge">🦴 Fósseis (Helix ou Dome)</span>
                        <span class="city-poi-badge">💧 Ginásio de Misty</span>
                    </div>
                    <p>1. Atravesse o <b>Mt. Moon</b>, derrote os membros da Equipe Rocket e escolha seu fóssil (Omanyte ou Kabuto).<br>
                    2. Ao chegar em Cerulean, suba a <b>Ponte Pepita</b>, vença os 5 treinadores para ganhar a Pepita e visite Bill na Casa do Mar para receber o <b>S.S. Ticket</b>.<br>
                    3. <b>Ginásio de Cerulean:</b> Misty usa Starmie rápida com Water Pulse. Use golpes Elétricos ou de Planta!</p>
                </div>

                <!-- Vermilion & S.S. Anne -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 4: Vermilion, Navio S.S. Anne & Surge</h3>
                        <span class="tag-pill">Insígnia Trovão</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🚢 S.S. Anne</span>
                        <span class="city-poi-badge">✂️ HM01 Cortar</span>
                        <span class="city-poi-badge">⚡ Ginásio de Lt. Surge</span>
                    </div>
                    <p>1. Desça pela Rota 5 (use a Passagem Subterrânea) até a cidade portuária de <b>Vermilion City</b>.<br>
                    2. Embarque no navio <b>S.S. Anne</b>, cure o Capitão no convés superior e receba a <b>HM01 Cortar</b>!<br>
                    3. Na <b>Diglett's Cave</b>, capture um Diglett/Dugtrio para vencer facilmente o ginásio elétrico de <b>Lt. Surge</b>.</p>
                </div>

                <!-- Lavender Town -->
                <div class="wiki-card">
                    <div class="city-banner-box">
                        <img class="city-banner-img" src="graphics/cities/lavender_town_banner.jpg" alt="Lavender Town">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">👻 Lavender Town & Torre Pokémon</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">👁️ Silph Scope</span>
                        <span class="city-poi-badge">🎵 Poké Flute</span>
                        <span class="city-poi-badge">😴 Despertar Snorlax</span>
                    </div>
                    <p>1. Atravesse o <b>Rock Tunnel</b> (com Flash) até o vilarejo sombrio de <b>Lavender Town</b>.<br>
                    2. Vá a Celadon City, invada o cassino Rocket para derrotar Giovanni e pegar o <b>Silph Scope</b>!<br>
                    3. Retorne à Torre Pokémon, identifique o fantasma de Marowak e salve o Sr. Fuji para ganhar a <b>Poké Flute</b>!</p>
                </div>

                <!-- Celadon & Saffron -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 6: Celadon, Silph Co. & Sabrina</h3>
                        <span class="tag-pill">Insígnias Arco-Íris & Pântano</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🦊 Eevee Gratuito</span>
                        <span class="city-poi-badge">🏢 Silph Co. & Card Key</span>
                        <span class="city-poi-badge">🟣 Master Ball</span>
                    </div>
                    <p>1. Na Mansão de Celadon, pegue <b>Eevee</b> no terraço e vença Erika no ginásio com Fogo/Voador.<br>
                    2. Em <b>Saffron City</b>, liberte o prédio de 11 andares da <b>Silph Co.</b>, vença o Rival no 7º andar (ganhe Lapras) e pegue a <b>Master Ball</b> do Presidente!<br>
                    3. Derrote Sabrina explorando sua baixa defesa física com golpes do tipo Sombrio/Fantasma.</p>
                </div>

                <!-- Fuchsia & Cinnabar -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 7: Safari Zone, Fuchsia & Cinnabar</h3>
                        <span class="tag-pill">Insígnias Alma & Vulcão</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🏄 HM03 Surfe & HM04 Força</span>
                        <span class="city-poi-badge">🔑 Chave da Mansão</span>
                        <span class="city-poi-badge">🔥 Ginásio de Blaine</span>
                    </div>
                    <p>1. Acorde o Snorlax com a Poké Flute e desça a Ciclovia até <b>Fuchsia City</b>.<br>
                    2. Na <b>Safari Zone</b> (Área 3), pegue a <b>HM03 Surfe</b> na cabana e os Dentes de Ouro para ganhar <b>HM04 Força</b>. Derrote Koga no ginásio.<br>
                    3. Surfe até a <b>Ilha de Cinnabar</b>, explore a Mansão para achar a chave secreta e derrote Blaine com Surfe.</p>
                </div>

                <!-- Viridian & Indigo Plateau -->
                <div class="wiki-card">
                    <div class="city-banner-box">
                        <img class="city-banner-img" src="graphics/cities/indigo_plateau_banner.jpg" alt="Indigo Plateau">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">🏛️ O Ginásio Final & O Planalto Índigo</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🌍 Giovanni (Viridian)</span>
                        <span class="city-poi-badge">🧗 Victory Road</span>
                        <span class="city-poi-badge">👑 Elite Four & Campeão</span>
                    </div>
                    <p>1. Volte ao 8º ginásio em Viridian: o líder é <b>Giovanni</b>! Use Água e Planta contra seus monstros tipo Terra para conquistar todas as 8 insígnias!<br>
                    2. Atravesse a <b>Victory Road</b> (capture Moltres Lv 50) e alcance o <b>Planalto Índigo</b>.<br>
                    3. Vença a Elite dos Quatro (Lorelei, Bruno, Agatha, Lance) e derrote o Rival Blue para se consagrar <b>Campeão de Kanto</b>!</p>
                </div>
            </div>
        </section>

        <!-- 3. DETONADO JOHTO -->
        <section id="pane-walkthrough-johto" class="section-pane">
            <div class="pane-header">
                <h1>🚄 Detonado Passo a Passo: Região de Johto</h1>
                <p>A expansão completa: desbloqueie a fronteira oeste, vença os 8 novos ginásios e enfrente Red no cume nevado do Monte Silver!</p>
            </div>

            <div class="card-grid-2">
                <!-- New Bark & Violet -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 1: Travessia para Johto & Falkner</h3>
                        <span class="tag-pill">Nível 55 a 62</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🚢 S.S. Aqua de Vermilion</span>
                        <span class="city-poi-badge">🔔 Sprout Tower</span>
                        <span class="city-poi-badge">🪶 Ginásio de Falkner</span>
                    </div>
                    <p>1. Vá ao porto de Vermilion e embarque no luxuoso navio <b>S.S. Aqua</b> com o passe de Carvalho.<br>
                    2. Desembarque em <b>New Bark Town</b> e explore a Rota 29 até Violet City.<br>
                    3. Suba a <b>Sprout Tower</b> e vença os monges para receber Flash.<br>
                    4. <b>Ginásio de Violet:</b> Falkner usa Pidgeot e Noctowl de nível 58+. Golpes Elétricos e de Gelo derrubam sua revoada.</p>
                </div>

                <!-- Azalea & Bugsy -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 2: Azalea Town & Bugsy</h3>
                        <span class="tag-pill">Poço Slowpoke</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🦛 Slowpoke Well</span>
                        <span class="city-poi-badge">🏹 Kurt & Apricorn Balls</span>
                        <span class="city-poi-badge">🪲 Ginásio de Bugsy</span>
                    </div>
                    <p>1. Atravesse a Union Cave até <b>Azalea Town</b>.<br>
                    2. Fale com Kurt e expulse a Equipe Rocket do <b>Slowpoke Well</b>.<br>
                    3. <b>Ginásio de Azalea:</b> Bugsy usa Scizor e Heracross em nível 62+. Golpes do tipo Fogo causam dano quadruplicado e vencem na hora!</p>
                </div>

                <!-- Goldenrod & Whitney -->
                <div class="wiki-card">
                    <div class="city-banner-box">
                        <img class="city-banner-img" src="graphics/cities/goldenrod_city_banner.jpg" alt="Goldenrod City">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">🏙️ Goldenrod City & Whitney</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">📻 Torre de Rádio</span>
                        <span class="city-poi-badge">🚆 Trem Magnético</span>
                        <span class="city-poi-badge">⭐ Ginásio de Whitney (Miltank)</span>
                    </div>
                    <p>1. Atravesse a Ilex Forest até a capital comercial de <b>Goldenrod City</b>.<br>
                    2. Conheça a Estação do Trem Magnético, a Loja de Departamentos e a Torre de Rádio.<br>
                    3. <b>Ginásio de Goldenrod:</b> Whitney possui Miltank com Rollout e Milk Drink em nível 67+. Use monstros de Pedra resistentes ou golpes do tipo Lutador!</p>
                </div>

                <!-- Ecruteak & Morty -->
                <div class="wiki-card">
                    <div class="city-banner-box">
                        <img class="city-banner-img" src="graphics/cities/ecruteak_city_banner.jpg" alt="Ecruteak City">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">⛩️ Ecruteak City & A Torre Queimada</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">⚡ Cães Lendários (Raikou, Entei, Suicune)</span>
                        <span class="city-poi-badge">🌊 SquirtBottle (Sudowoodo)</span>
                        <span class="city-poi-badge">👻 Ginásio de Morty</span>
                    </div>
                    <p>1. Siga pela Rota 36 e use o regador SquirtBottle para enfrentar o <b>Sudowoodo</b> que bloqueia a passagem.<br>
                    2. Na <b>Burned Tower</b> de Ecruteak, liberte os cães lendários <i>Raikou, Entei e Suicune</i>!<br>
                    3. <b>Ginásio de Ecruteak:</b> Morty usa Gengar e fantasmas no chão invisível. Golpes Sombrios e Psíquicos garantem a vitória.</p>
                </div>

                <!-- Cianwood & Olivine -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 5: Cianwood, Olivine & Jasmine</h3>
                        <span class="tag-pill">Insígnia Mineral</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">💊 Remédio Secreto</span>
                        <span class="city-poi-badge">💡 Farol de Olivine (Ampharos)</span>
                        <span class="city-poi-badge">⚙️ Ginásio de Jasmine</span>
                    </div>
                    <p>1. Surfe pelo mar até <b>Cianwood City</b>. Derrote Chuck (Lutador) com voadores/psíquicos e pegue o Remédio Secreto na farmácia.<br>
                    2. Volte a <b>Olivine City</b>, suba o Farol e cure o Ampharos.<br>
                    3. <b>Ginásio de Olivine:</b> Jasmine usa Steelix e Magnemite. Golpes de Fogo e Terremoto derretem sua armadura de ferro!</p>
                </div>

                <!-- Mahogany & Blackthorn -->
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 6: Lago da Fúria, Pryce & Clair</h3>
                        <span class="tag-pill">Gyarados Vermelho</span>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🔴 Gyarados Vermelho (Shiny)</span>
                        <span class="city-poi-badge">❄️ Ginásio de Pryce</span>
                        <span class="city-poi-badge">🐉 Ginásio de Clair (Kingdra)</span>
                    </div>
                    <p>1. Em <b>Mahogany Town</b>, suba até o Lago da Fúria e capture o famoso <b>Gyarados Vermelho (Shiny)</b>!<br>
                    2. Vencendo o ginásio de Gelo de Pryce, atravesse a caverna de gelo até <b>Blackthorn City</b>.<br>
                    3. <b>Ginásio de Blackthorn:</b> Clair usa Kingdra em nível 85. Ataques de Fada e Dragão são fundamentais!</p>
                </div>

                <!-- Mount Silver -->
                <div class="wiki-card" style="grid-column: 1 / -1; border-color: rgba(239, 68, 68, 0.4);">
                    <div class="city-banner-box" style="height: 250px;">
                        <img class="city-banner-img" src="graphics/cities/mt_silver_banner.jpg" alt="Mount Silver">
                        <div class="city-banner-overlay">
                            <div class="city-banner-title">❄️ O Cume do Monte Silver: O Desafio Contra Red</div>
                        </div>
                    </div>
                    <div class="city-poi-bar">
                        <span class="city-poi-badge">🏆 16 Insígnias Conquistadas</span>
                        <span class="city-poi-badge">🌨️ Granizo Contínuo</span>
                        <span class="city-poi-badge">👑 Red (Nível 95 a 100)</span>
                    </div>
                    <p style="margin-top: 0.75rem;">Com as 16 insígnias de Kanto e Johto em mãos, o Prof. Carvalho concede autorização oficial para entrar no <b>Monte Silver</b>.<br>
                    Atravesse a caverna profunda com Surfe e Cachoeira até o cume onde cai <b>neve constante</b>. Lá em cima, isolado do mundo, está o lendário Campeão <b>Red</b>!</p>
                    <div class="info-box warn">
                        <strong>Equipe de Red:</strong> Pikachu (Lv 100 com Light Ball), Charizard (Lv 98), Blastoise (Lv 98), Venusaur (Lv 98), Snorlax (Lv 97) e Lapras (Lv 96).<br>
                        O granizo causará dano no final de cada turno. Use golpes de Terra em Pikachu, Lutador em Snorlax e traga poções máximas e Revives!
                    </div>
                </div>
            </div>
        </section>

        <!-- 4. GINÁSIOS & CHEFES (COM IMAGENS) -->
        <section id="pane-gyms" class="section-pane">
            <div class="pane-header">
                <h1>🥊 Mural de Líderes, Insígnias & Chefes</h1>
                <p>Consulte portraits oficiais, equipes completas com mini-sprites, níveis exatos e estratégias para vencer cada duelo em Kanto e Johto.</p>
            </div>

            <div class="boss-tab-bar">
                <button class="boss-tab-btn active" onclick="filterBossTab('all')">Todos os Chefes</button>
                <button class="boss-tab-btn" onclick="filterBossTab('kanto')">🔴 Kanto (8 Ginásios)</button>
                <button class="boss-tab-btn" onclick="filterBossTab('elite')">⭐ Elite 4 & Rival</button>
                <button class="boss-tab-btn" onclick="filterBossTab('johto')">🔵 Johto (8 Ginásios)</button>
                <button class="boss-tab-btn" onclick="filterBossTab('red')">🏆 Monte Silver (Red)</button>
            </div>

            <div class="gym-boss-grid" id="gymBossContainer">
                <!-- Preenchido via JavaScript -->
            </div>
        </section>

        <!-- 5. POKÉDEX REGIONAL 251 -->
        <section id="pane-pokedex" class="section-pane">
            <div class="pane-header">
                <h1>📖 Pokédex Completa Kanto & Johto (#001 a #251)</h1>
                <p>Consulte todos os Pokémon, tipos atualizados (incluindo Tipo Fada) e seus métodos de evolução exclusivos nesta hack!</p>
            </div>

            <div class="search-wrap" style="max-width: 400px; margin-bottom: 1rem;">
                <input type="text" id="pokedexFilterInput" class="global-search-input" placeholder="Buscar por nome ou número..." oninput="filterPokedex()">
            </div>

            <div class="type-filter-bar" id="typeFilterContainer">
                <button class="type-filter-btn active" onclick="filterByType('TODOS')">TODOS</button>
                <button class="type-filter-btn" onclick="filterByType('Fogo')">Fogo</button>
                <button class="type-filter-btn" onclick="filterByType('Água')">Água</button>
                <button class="type-filter-btn" onclick="filterByType('Planta')">Planta</button>
                <button class="type-filter-btn" onclick="filterByType('Elétrico')">Elétrico</button>
                <button class="type-filter-btn" onclick="filterByType('Fada')">Fada</button>
                <button class="type-filter-btn" onclick="filterByType('Psíquico')">Psíquico</button>
                <button class="type-filter-btn" onclick="filterByType('Fantasma')">Fantasma</button>
                <button class="type-filter-btn" onclick="filterByType('Dragão')">Dragão</button>
                <button class="type-filter-btn" onclick="filterByType('Sombrio')">Sombrio</button>
                <button class="type-filter-btn" onclick="filterByType('Aço')">Aço</button>
            </div>

            <div class="pokedex-grid" id="pokedexContainer">
                <!-- Preenchido dinamicamente via JS -->
            </div>
        </section>

        <!-- 6. ROTAS & ENCONTROS (DIA E NOITE) -->
        <section id="pane-encounters" class="section-pane">
            <div class="pane-header">
                <h1>🧭 Enciclopédia de Rotas & Encontros</h1>
                <p>Tabela viva extraída diretamente do código do jogo. Mostra onde cada Pokémon aparece de Dia, de Noite, na Água e no DexNav!</p>
            </div>

            <div class="search-wrap" style="margin-bottom: 1.5rem; max-width: 400px;">
                <input type="text" id="routeFilterInput" class="global-search-input" placeholder="Filtrar por nome de rota..." oninput="filterRoutes(this.value)">
            </div>

            <div class="encounter-grid" id="routesContainer">
                <!-- Preenchido dinamicamente via JS -->
            </div>
        </section>

        <!-- 7. TMS, HMS & ITENS -->
        <section id="pane-items" class="section-pane">
            <div class="pane-header">
                <h1>🎁 Localização dos TMs, HMs & Itens Raros</h1>
                <p>Nesta hack, os TMs são infinitos e reutilizáveis como nas gerações modernas!</p>
            </div>

            <div class="wiki-card">
                <h3 style="margin-bottom: 0.75rem;">Máquinas Ocultas (HMs)</h3>
                <table class="data-table">
                    <thead>
                        <tr>
                            <th>HM</th>
                            <th>Movimento</th>
                            <th>Local de Obtenção</th>
                            <th>Insígnia Necessária</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr><td><b>HM01</b></td><td>Cortar (Cut)</td><td>Vermilion City (Navio S.S. Anne com o Capitão)</td><td>Insígnia Cascata (Misty)</td></tr>
                        <tr><td><b>HM02</b></td><td>Voar (Fly)</td><td>Rota 16 (Casa da mulher reclusa atrás da árvore de cortar)</td><td>Insígnia Trovão (Lt. Surge)</td></tr>
                        <tr><td><b>HM03</b></td><td>Surfe (Surf)</td><td>Fuchsia City (Cabana secreta na Área 3 da Safari Zone)</td><td>Insígnia Alma (Koga)</td></tr>
                        <tr><td><b>HM04</b></td><td>Força (Strength)</td><td>Fuchsia City (Troque os Dentes de Ouro com o Guarda)</td><td>Insígnia Arco-Íris (Erika)</td></tr>
                        <tr><td><b>HM05</b></td><td>Flash</td><td>Rota 2 (Ajudante do Prof. Carvalho se tiver 10 Pokémon capturados)</td><td>Insígnia Rocha (Brock)</td></tr>
                        <tr><td><b>HM06</b></td><td>Quebrar Rocha (Rock Smash)</td><td>Rota 12 / Ilha 1</td><td>Insígnia Pântano (Sabrina)</td></tr>
                        <tr><td><b>HM07</b></td><td>Cachoeira (Waterfall)</td><td>Icefall Cave / Johto</td><td>Insígnia Vulcão (Blaine)</td></tr>
                    </tbody>
                </table>
            </div>

            <div class="wiki-card">
                <h3 style="margin-bottom: 0.75rem;">TMs Essenciais & Localização</h3>
                <table class="data-table">
                    <thead>
                        <tr>
                            <th>TM</th>
                            <th>Golpe</th>
                            <th>Tipo</th>
                            <th>Onde Encontrar</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr><td><b>TM13</b></td><td>Raio de Gelo (Ice Beam)</td><td>Gelo</td><td>Celadon Game Corner (Cassino) / Rooftop de Celadon</td></tr>
                        <tr><td><b>TM24</b></td><td>Raio (Thunderbolt)</td><td>Elétrico</td><td>Celadon Game Corner / Power Plant</td></tr>
                        <tr><td><b>TM26</b></td><td>Terremoto (Earthquake)</td><td>Terra</td><td>Recompensa de Giovanni (Ginásio de Viridian) / Silph Co.</td></tr>
                        <tr><td><b>TM29</b></td><td>Psíquico (Psychic)</td><td>Psíquico</td><td>Saffron City (Casa do Sr. Psíquico no sudeste da cidade)</td></tr>
                        <tr><td><b>TM30</b></td><td>Bola Sombria (Shadow Ball)</td><td>Fantasma</td><td>Celadon Game Corner / Lavender Town</td></tr>
                        <tr><td><b>TM35</b></td><td>Lança-Chamas (Flamethrower)</td><td>Fogo</td><td>Celadon Game Corner / Cinnabar Island</td></tr>
                    </tbody>
                </table>
            </div>
        </section>

        <!-- 8. CONTROLES & APK -->
        <section id="pane-controls" class="section-pane">
            <div class="pane-header">
                <h1>🎮 Controles & Configurações</h1>
                <p>Dicas de jogabilidade tanto no emulador Android (APK) quanto no teclado para PC.</p>
            </div>

            <div class="card-grid-2">
                <div class="wiki-card">
                    <h3 style="margin-bottom: 0.75rem;">Controles no Teclado (PC)</h3>
                    <table class="data-table">
                        <tr><td><b>Direcionais (D-Pad)</b></td><td>Setas do Teclado (Cima, Baixo, Esquerda, Direita)</td></tr>
                        <tr><td><b>Botão A</b></td><td>Tecla <code>Z</code> (Confirmar / Interagir / Falar)</td></tr>
                        <tr><td><b>Botão B</b></td><td>Tecla <code>X</code> (Cancelar / Correr)</td></tr>
                        <tr><td><b>Botão START</b></td><td>Tecla <code>ENTER</code> (Abrir Menu do Jogo)</td></tr>
                        <tr><td><b>Botão SELECT</b></td><td>Tecla <code>BACKSPACE</code> ou <code>SHIFT</code> (Registrar Item)</td></tr>
                        <tr><td><b>Gatilho L / R</b></td><td>Teclas <code>A</code> e <code>S</code></td></tr>
                    </table>
                </div>

                <div class="wiki-card">
                    <h3 style="margin-bottom: 0.75rem;">Dicas para a Versão APK (Android)</h3>
                    <p>1. <b>HMs no Mapa:</b> Para usar Cortar ou Força, basta ficar de frente para a árvore ou pedra e apertar <b>A</b>.<br><br>
                    2. <b>Salvamento Duplo:</b> Salve sempre pelo menu nativo do jogo (<i>START -> SAVE</i>) para garantir que seu save continue compatível com emuladores de PC!<br><br>
                    3. <b>Troca de Golpes:</b> Graças aos TMs infinitos, você pode testar novos golpes na sua equipe a qualquer momento sem medo de gastar itens raros.</p>
                </div>
            </div>
        </section>

    </main>

    <!-- BANCO DE DADOS & SCRIPTS -->
    <script>
        const routesData = {routes_json};
        const pokedexData = {pokedex_json};
        const gymBossesData = {gym_bosses_json};

        // Troca de Telas
        function switchPane(paneId) {{
            document.querySelectorAll('.section-pane').forEach(p => p.classList.remove('active'));
            document.querySelectorAll('.nav-item').forEach(n => n.classList.remove('active'));

            const target = document.getElementById(paneId);
            if (target) {{
                target.classList.add('active');
                window.scrollTo({{ top: 0, behavior: 'smooth' }});
            }}

            // Destacar botão da sidebar
            const navItems = document.querySelectorAll('.nav-item');
            navItems.forEach(item => {{
                if (item.getAttribute('onclick') && item.getAttribute('onclick').includes(paneId)) {{
                    item.classList.add('active');
                }}
            }});
        }}

        // Renderizar Pokédex com Imagens e Efeitos
        let currentTypeFilter = 'TODOS';
        function renderPokedex() {{
            const container = document.getElementById('pokedexContainer');
            const searchVal = (document.getElementById('pokedexFilterInput')?.value || '').toLowerCase();

            const filtered = pokedexData.filter(mon => {{
                const matchesName = mon.name.toLowerCase().includes(searchVal) || mon.num.toString().includes(searchVal);
                const matchesType = currentTypeFilter === 'TODOS' || mon.type.includes(currentTypeFilter);
                return matchesName && matchesType;
            }});

            container.innerHTML = filtered.map(mon => `
                <div class="mon-card" onclick="alert('#${{mon.num}} ${{mon.name}} — Tipo: ${{mon.type.join('/')}} | ${{mon.evo}}')">
                    <div class="mon-card-header">
                        <span class="mon-number">#${{mon.num.toString().padStart(3, '0')}}</span>
                        <div class="mon-types">
                            ${{mon.type.map(t => `<span class="type-badge type-${{t}}">${{t}}</span>`).join('')}}
                        </div>
                    </div>
                    <div class="mon-sprite-box">
                        <img class="mon-sprite" 
                             src="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${{mon.num}}.png" 
                             data-animated="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/other/showdown/${{mon.num}}.gif"
                             onerror="this.onerror=null; this.src='graphics/pokemon/${{mon.folder}}/front.png';"
                             onmouseover="if(this.dataset.animated) this.src=this.dataset.animated"
                             onmouseout="this.src='https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${{mon.num}}.png'"
                             alt="${{mon.name}}" 
                             loading="lazy">
                    </div>
                    <h3 class="mon-name">${{mon.name}}</h3>
                    <div class="mon-evo-note">
                        <strong>Evolução:</strong> ${{mon.evo}}
                    </div>
                </div>
            `).join('');
        }}

        function filterByType(type) {{
            currentTypeFilter = type;
            document.querySelectorAll('.type-filter-btn').forEach(btn => {{
                btn.classList.toggle('active', btn.textContent === type);
            }});
            renderPokedex();
        }}

        function filterPokedex() {{
            renderPokedex();
        }}

        // Renderizar Chefes de Ginásio com Portraits e Equipes
        let currentBossTab = 'all';
        function renderGymBosses() {{
            const container = document.getElementById('gymBossContainer');
            const filtered = gymBossesData.filter(boss => {{
                if (currentBossTab === 'all') return true;
                return boss.region === currentBossTab;
            }});

            container.innerHTML = filtered.map(boss => `
                <div class="gym-boss-card">
                    <div class="gym-boss-header">
                        <img class="gym-boss-pic" 
                             src="${{boss.pic}}" 
                             onerror="this.onerror=null; this.src='graphics/trainers/front_pics/leader_brock_front_pic.png';" 
                             alt="${{boss.name}}">
                        <div class="gym-boss-info">
                            <h3 class="gym-boss-name">${{boss.badge_icon}} ${{boss.name}}</h3>
                            <div class="gym-badge-tag">${{boss.badge}}</div>
                            <div class="gym-loc-type">📍 ${{boss.city}} • Tipo: <b>${{boss.type}}</b></div>
                        </div>
                    </div>

                    <div class="gym-team-box">
                        <div class="gym-team-label">Equipe Destaque:</div>
                        <div class="gym-mon-list">
                            ${{boss.team.map(m => `
                                <div class="gym-mon-chip">
                                    <img class="gym-mon-sprite" 
                                         src="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${{m.num}}.png" 
                                         alt="${{m.name}}">
                                    <span><b>${{m.name}}</b> (Lv ${{m.lvl}})</span>
                                </div>
                            `).join('')}}
                        </div>
                    </div>

                    <div class="gym-strategy-box">
                        <b>Estratégia Recomendada:</b><br>${{boss.strategy}}
                    </div>
                </div>
            `).join('');
        }}

        function filterBossTab(tab) {{
            currentBossTab = tab;
            document.querySelectorAll('.boss-tab-btn').forEach(btn => {{
                btn.classList.toggle('active', btn.getAttribute('onclick').includes(tab));
            }});
            renderGymBosses();
        }}

        // Renderizar Rotas
        function renderRoutes(filter = '') {{
            const container = document.getElementById('routesContainer');
            const term = filter.toLowerCase();

            const filtered = routesData.filter(r => {{
                const matchesRoute = r.name.toLowerCase().includes(term);
                const matchesMon = (
                    r.day.some(m => m.toLowerCase().includes(term)) ||
                    r.night.some(m => m.toLowerCase().includes(term)) ||
                    r.water.some(m => m.toLowerCase().includes(term)) ||
                    r.hidden.some(m => m.toLowerCase().includes(term))
                );
                return matchesRoute || matchesMon;
            }});

            container.innerHTML = filtered.map(r => `
                <div class="route-card">
                    <div class="route-title">
                        <span>📍</span> ${{r.name}}
                    </div>

                    ${{r.day.length ? `
                        <div class="enc-group">
                            <div class="enc-group-title day">☀️ Dia</div>
                            <div class="mon-tag-list">
                                ${{r.day.map(m => `<span class="mon-tag">${{m}}</span>`).join('')}}
                            </div>
                        </div>
                    ` : ''}}

                    ${{r.night.length ? `
                        <div class="enc-group">
                            <div class="enc-group-title night">🌙 Noite</div>
                            <div class="mon-tag-list">
                                ${{r.night.map(m => `<span class="mon-tag">${{m}}</span>`).join('')}}
                            </div>
                        </div>
                    ` : ''}}

                    ${{r.water.length ? `
                        <div class="enc-group">
                            <div class="enc-group-title water">💧 Água / Pesca</div>
                            <div class="mon-tag-list">
                                ${{r.water.map(m => `<span class="mon-tag">${{m}}</span>`).join('')}}
                            </div>
                        </div>
                    ` : ''}}

                    ${{r.hidden.length ? `
                        <div class="enc-group">
                            <div class="enc-group-title hidden">✨ DexNav / Especial</div>
                            <div class="mon-tag-list">
                                ${{r.hidden.map(m => `<span class="mon-tag">${{m}}</span>`).join('')}}
                            </div>
                        </div>
                    ` : ''}}
                </div>
            `).join('');
        }}

        function filterRoutes(val) {{
            renderRoutes(val);
        }}

        // Busca Global Inteligente
        function handleGlobalSearch(term) {{
            const q = term.trim().toLowerCase();
            if (!q) return;

            // Se for nome de Pokémon
            const monFound = pokedexData.find(m => m.name.toLowerCase().includes(q) || m.num.toString() === q);
            if (monFound) {{
                switchPane('pane-pokedex');
                const inp = document.getElementById('pokedexFilterInput');
                if (inp) {{
                    inp.value = q;
                    renderPokedex();
                }}
                return;
            }}

            // Se for Líder de Ginásio
            if (['brock', 'misty', 'surge', 'erika', 'sabrina', 'koga', 'blaine', 'giovanni', 'falkner', 'bugsy', 'whitney', 'morty', 'chuck', 'jasmine', 'pryce', 'clair', 'red', 'lance', 'lorelei', 'bruno', 'agatha', 'blue'].some(l => q.includes(l))) {{
                switchPane('pane-gyms');
                return;
            }}

            // Se for rota
            if (q.includes('rota') || q.includes('route') || q.includes('cave') || q.includes('floresta') || q.includes('tower')) {{
                switchPane('pane-encounters');
                const inp = document.getElementById('routeFilterInput');
                if (inp) {{
                    inp.value = q;
                    renderRoutes(q);
                }}
                return;
            }}

            // Se for TM ou HM
            if (q.includes('hm') || q.includes('tm') || q.includes('surfe') || q.includes('cortar') || q.includes('voar')) {{
                switchPane('pane-items');
                return;
            }}
        }}

        // Inicialização
        document.addEventListener('DOMContentLoaded', () => {{
            renderPokedex();
            renderGymBosses();
            renderRoutes();
        }});
    </script>
</body>
</html>
"""

# Salvar Wiki_Pokemon_Kanto_Johto.html e Detonado_Interativo_Pokemon_Kanto_Johto.html
with open('Wiki_Pokemon_Kanto_Johto.html', 'w', encoding='utf-8') as f:
    f.write(html_template)

with open('Detonado_Interativo_Pokemon_Kanto_Johto.html', 'w', encoding='utf-8') as f:
    f.write(html_template)

print(f"Sucesso! Gerados Wiki_Pokemon_Kanto_Johto.html e Detonado_Interativo_Pokemon_Kanto_Johto.html com {len(pokedex_data)} Pokémon, {len(routes_data_clean)} rotas e {len(gym_bosses)} cards de chefes.")
