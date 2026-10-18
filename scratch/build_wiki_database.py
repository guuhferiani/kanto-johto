# -*- coding: utf-8 -*-
import json
import os
import re

print("Construindo Wiki e Pokédex Interativa Completa...")

# 1. Carregar encontros de wild_encounters.json
with open('src/data/wild_encounters.json', 'r', encoding='utf-8') as f:
    wild_json = json.load(f)

encounters = wild_json.get('wild_encounter_groups', [{}])[0].get('encounters', [])

routes_map = {}
for enc in encounters:
    map_raw = enc.get('map', '').replace('MAP_', '')
    label = enc.get('base_label', '')
    is_night = 'Night' in label
    
    # Formatar nome amigável
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

# 2. Dados dos 251 Pokémon (Gen 1 & Gen 2) com métodos de evolução personalizados
pokedex_data = [
    {"num": 1, "name": "Bulbasaur", "type": ["Planta", "Veneno"], "evo": "Lv 16 -> Ivysaur"},
    {"num": 2, "name": "Ivysaur", "type": ["Planta", "Veneno"], "evo": "Lv 32 -> Venusaur"},
    {"num": 3, "name": "Venusaur", "type": ["Planta", "Veneno"], "evo": "Forma Final"},
    {"num": 4, "name": "Charmander", "type": ["Fogo"], "evo": "Lv 16 -> Charmeleon"},
    {"num": 5, "name": "Charmeleon", "type": ["Fogo"], "evo": "Lv 36 -> Charizard"},
    {"num": 6, "name": "Charizard", "type": ["Fogo", "Voador"], "evo": "Forma Final"},
    {"num": 7, "name": "Squirtle", "type": ["Água"], "evo": "Lv 16 -> Wartortle"},
    {"num": 8, "name": "Wartortle", "type": ["Água"], "evo": "Lv 36 -> Blastoise"},
    {"num": 9, "name": "Blastoise", "type": ["Água"], "evo": "Forma Final"},
    {"num": 10, "name": "Caterpie", "type": ["Inseto"], "evo": "Lv 7 -> Metapod"},
    {"num": 11, "name": "Metapod", "type": ["Inseto"], "evo": "Lv 10 -> Butterfree"},
    {"num": 12, "name": "Butterfree", "type": ["Inseto", "Voador"], "evo": "Forma Final"},
    {"num": 13, "name": "Weedle", "type": ["Inseto", "Veneno"], "evo": "Lv 7 -> Kakuna"},
    {"num": 14, "name": "Kakuna", "type": ["Inseto", "Veneno"], "evo": "Lv 10 -> Beedrill"},
    {"num": 15, "name": "Beedrill", "type": ["Inseto", "Veneno"], "evo": "Forma Final"},
    {"num": 16, "name": "Pidgey", "type": ["Normal", "Voador"], "evo": "Lv 18 -> Pidgeotto"},
    {"num": 17, "name": "Pidgeotto", "type": ["Normal", "Voador"], "evo": "Lv 36 -> Pidgeot"},
    {"num": 18, "name": "Pidgeot", "type": ["Normal", "Voador"], "evo": "Forma Final"},
    {"num": 19, "name": "Rattata", "type": ["Normal"], "evo": "Lv 20 -> Raticate"},
    {"num": 20, "name": "Raticate", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 21, "name": "Spearow", "type": ["Normal", "Voador"], "evo": "Lv 20 -> Fearow"},
    {"num": 22, "name": "Fearow", "type": ["Normal", "Voador"], "evo": "Forma Final"},
    {"num": 23, "name": "Ekans", "type": ["Veneno"], "evo": "Lv 22 -> Arbok"},
    {"num": 24, "name": "Arbok", "type": ["Veneno"], "evo": "Forma Final"},
    {"num": 25, "name": "Pikachu", "type": ["Elétrico"], "evo": "Pedra do Trovão -> Raichu"},
    {"num": 26, "name": "Raichu", "type": ["Elétrico"], "evo": "Forma Final"},
    {"num": 27, "name": "Sandshrew", "type": ["Terra"], "evo": "Lv 22 -> Sandslash"},
    {"num": 28, "name": "Sandslash", "type": ["Terra"], "evo": "Forma Final"},
    {"num": 29, "name": "Nidoran♀", "type": ["Veneno"], "evo": "Lv 16 -> Nidorina"},
    {"num": 30, "name": "Nidorina", "type": ["Veneno"], "evo": "Pedra da Lua -> Nidoqueen"},
    {"num": 31, "name": "Nidoqueen", "type": ["Veneno", "Terra"], "evo": "Forma Final"},
    {"num": 32, "name": "Nidoran♂", "type": ["Veneno"], "evo": "Lv 16 -> Nidorino"},
    {"num": 33, "name": "Nidorino", "type": ["Veneno"], "evo": "Pedra da Lua -> Nidoking"},
    {"num": 34, "name": "Nidoking", "type": ["Veneno", "Terra"], "evo": "Forma Final"},
    {"num": 35, "name": "Clefairy", "type": ["Fada"], "evo": "Pedra da Lua -> Clefable"},
    {"num": 36, "name": "Clefable", "type": ["Fada"], "evo": "Forma Final"},
    {"num": 37, "name": "Vulpix", "type": ["Fogo"], "evo": "Pedra de Fogo -> Ninetales"},
    {"num": 38, "name": "Ninetales", "type": ["Fogo"], "evo": "Forma Final"},
    {"num": 39, "name": "Jigglypuff", "type": ["Normal", "Fada"], "evo": "Pedra da Lua -> Wigglytuff"},
    {"num": 40, "name": "Wigglytuff", "type": ["Normal", "Fada"], "evo": "Forma Final"},
    {"num": 41, "name": "Zubat", "type": ["Veneno", "Voador"], "evo": "Lv 22 -> Golbat"},
    {"num": 42, "name": "Golbat", "type": ["Veneno", "Voador"], "evo": "Felicidade Máxima -> Crobat"},
    {"num": 43, "name": "Oddish", "type": ["Planta", "Veneno"], "evo": "Lv 21 -> Gloom"},
    {"num": 44, "name": "Gloom", "type": ["Planta", "Veneno"], "evo": "Pedra Folha (Vileplume) ou Pedra Solar (Bellossom)"},
    {"num": 45, "name": "Vileplume", "type": ["Planta", "Veneno"], "evo": "Forma Final"},
    {"num": 46, "name": "Paras", "type": ["Inseto", "Planta"], "evo": "Lv 24 -> Parasect"},
    {"num": 47, "name": "Parasect", "type": ["Inseto", "Planta"], "evo": "Forma Final"},
    {"num": 48, "name": "Venonat", "type": ["Inseto", "Veneno"], "evo": "Lv 31 -> Venomoth"},
    {"num": 49, "name": "Venomoth", "type": ["Inseto", "Veneno"], "evo": "Forma Final"},
    {"num": 50, "name": "Diglett", "type": ["Terra"], "evo": "Lv 26 -> Dugtrio"},
    {"num": 51, "name": "Dugtrio", "type": ["Terra"], "evo": "Forma Final"},
    {"num": 52, "name": "Meowth", "type": ["Normal"], "evo": "Lv 28 -> Persian"},
    {"num": 53, "name": "Persian", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 54, "name": "Psyduck", "type": ["Água"], "evo": "Lv 33 -> Golduck"},
    {"num": 55, "name": "Golduck", "type": ["Água"], "evo": "Forma Final"},
    {"num": 56, "name": "Mankey", "type": ["Lutador"], "evo": "Lv 28 -> Primeape"},
    {"num": 57, "name": "Primeape", "type": ["Lutador"], "evo": "Forma Final"},
    {"num": 58, "name": "Growlithe", "type": ["Fogo"], "evo": "Pedra de Fogo -> Arcanine"},
    {"num": 59, "name": "Arcanine", "type": ["Fogo"], "evo": "Forma Final"},
    {"num": 60, "name": "Poliwag", "type": ["Água"], "evo": "Lv 25 -> Poliwhirl"},
    {"num": 61, "name": "Poliwhirl", "type": ["Água"], "evo": "Pedra da Água (Poliwrath) ou King's Rock (Politoed)"},
    {"num": 62, "name": "Poliwrath", "type": ["Água", "Lutador"], "evo": "Forma Final"},
    {"num": 63, "name": "Abra", "type": ["Psíquico"], "evo": "Lv 16 -> Kadabra"},
    {"num": 64, "name": "Kadabra", "type": ["Psíquico"], "evo": "Lv 37, Pedra do Poder ou Troca -> Alakazam"},
    {"num": 65, "name": "Alakazam", "type": ["Psíquico"], "evo": "Forma Final"},
    {"num": 66, "name": "Machop", "type": ["Lutador"], "evo": "Lv 28 -> Machoke"},
    {"num": 67, "name": "Machoke", "type": ["Lutador"], "evo": "Lv 37, Pedra do Poder ou Troca -> Machamp"},
    {"num": 68, "name": "Machamp", "type": ["Lutador"], "evo": "Forma Final"},
    {"num": 69, "name": "Bellsprout", "type": ["Planta", "Veneno"], "evo": "Lv 21 -> Weepinbell"},
    {"num": 70, "name": "Weepinbell", "type": ["Planta", "Veneno"], "evo": "Pedra Folha -> Victreebel"},
    {"num": 71, "name": "Victreebel", "type": ["Planta", "Veneno"], "evo": "Forma Final"},
    {"num": 72, "name": "Tentacool", "type": ["Água", "Veneno"], "evo": "Lv 30 -> Tentacruel"},
    {"num": 73, "name": "Tentacruel", "type": ["Água", "Veneno"], "evo": "Forma Final"},
    {"num": 74, "name": "Geodude", "type": ["Pedra", "Terra"], "evo": "Lv 25 -> Graveler"},
    {"num": 75, "name": "Graveler", "type": ["Pedra", "Terra"], "evo": "Lv 37, Pedra do Poder ou Troca -> Golem"},
    {"num": 76, "name": "Golem", "type": ["Pedra", "Terra"], "evo": "Forma Final"},
    {"num": 77, "name": "Ponyta", "type": ["Fogo"], "evo": "Lv 40 -> Rapidash"},
    {"num": 78, "name": "Rapidash", "type": ["Fogo"], "evo": "Forma Final"},
    {"num": 79, "name": "Slowpoke", "type": ["Água", "Psíquico"], "evo": "Lv 37 -> Slowbro (ou King's Rock -> Slowking)"},
    {"num": 80, "name": "Slowbro", "type": ["Água", "Psíquico"], "evo": "Forma Final"},
    {"num": 81, "name": "Magnemite", "type": ["Elétrico", "Aço"], "evo": "Lv 30 -> Magneton"},
    {"num": 82, "name": "Magneton", "type": ["Elétrico", "Aço"], "evo": "Forma Final"},
    {"num": 83, "name": "Farfetch'd", "type": ["Normal", "Voador"], "evo": "Não evolui"},
    {"num": 84, "name": "Doduo", "type": ["Normal", "Voador"], "evo": "Lv 31 -> Dodrio"},
    {"num": 85, "name": "Dodrio", "type": ["Normal", "Voador"], "evo": "Forma Final"},
    {"num": 86, "name": "Seel", "type": ["Água"], "evo": "Lv 34 -> Dewgong"},
    {"num": 87, "name": "Dewgong", "type": ["Água", "Gelo"], "evo": "Forma Final"},
    {"num": 88, "name": "Grimer", "type": ["Veneno"], "evo": "Lv 38 -> Muk"},
    {"num": 89, "name": "Muk", "type": ["Veneno"], "evo": "Forma Final"},
    {"num": 90, "name": "Shellder", "type": ["Água"], "evo": "Pedra da Água -> Cloyster"},
    {"num": 91, "name": "Cloyster", "type": ["Água", "Gelo"], "evo": "Forma Final"},
    {"num": 92, "name": "Gastly", "type": ["Fantasma", "Veneno"], "evo": "Lv 25 -> Haunter"},
    {"num": 93, "name": "Haunter", "type": ["Fantasma", "Veneno"], "evo": "Lv 37, Pedra do Poder ou Troca -> Gengar"},
    {"num": 94, "name": "Gengar", "type": ["Fantasma", "Veneno"], "evo": "Forma Final"},
    {"num": 95, "name": "Onix", "type": ["Pedra", "Terra"], "evo": "Revestimento Metálico (Metal Coat) -> Steelix"},
    {"num": 96, "name": "Drowzee", "type": ["Psíquico"], "evo": "Lv 26 -> Hypno"},
    {"num": 97, "name": "Hypno", "type": ["Psíquico"], "evo": "Forma Final"},
    {"num": 98, "name": "Krabby", "type": ["Água"], "evo": "Lv 28 -> Kingler"},
    {"num": 99, "name": "Kingler", "type": ["Água"], "evo": "Forma Final"},
    {"num": 100, "name": "Voltorb", "type": ["Elétrico"], "evo": "Lv 30 -> Electrode"},
    {"num": 101, "name": "Electrode", "type": ["Elétrico"], "evo": "Forma Final"},
    {"num": 102, "name": "Exeggcute", "type": ["Planta", "Psíquico"], "evo": "Pedra Folha -> Exeggutor"},
    {"num": 103, "name": "Exeggutor", "type": ["Planta", "Psíquico"], "evo": "Forma Final"},
    {"num": 104, "name": "Cubone", "type": ["Terra"], "evo": "Lv 28 -> Marowak"},
    {"num": 105, "name": "Marowak", "type": ["Terra"], "evo": "Forma Final"},
    {"num": 106, "name": "Hitmonlee", "type": ["Lutador"], "evo": "Forma Final"},
    {"num": 107, "name": "Hitmonchan", "type": ["Lutador"], "evo": "Forma Final"},
    {"num": 108, "name": "Lickitung", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 109, "name": "Koffing", "type": ["Veneno"], "evo": "Lv 35 -> Weezing"},
    {"num": 110, "name": "Weezing", "type": ["Veneno"], "evo": "Forma Final"},
    {"num": 111, "name": "Rhyhorn", "type": ["Terra", "Pedra"], "evo": "Lv 42 -> Rhydon"},
    {"num": 112, "name": "Rhydon", "type": ["Terra", "Pedra"], "evo": "Forma Final"},
    {"num": 113, "name": "Chansey", "type": ["Normal"], "evo": "Felicidade Máxima -> Blissey"},
    {"num": 114, "name": "Tangela", "type": ["Planta"], "evo": "Não evolui"},
    {"num": 115, "name": "Kangaskhan", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 116, "name": "Horsea", "type": ["Água"], "evo": "Lv 32 -> Seadra"},
    {"num": 117, "name": "Seadra", "type": ["Água"], "evo": "Escama de Dragão (Dragon Scale) -> Kingdra"},
    {"num": 118, "name": "Goldeen", "type": ["Água"], "evo": "Lv 33 -> Seaking"},
    {"num": 119, "name": "Seaking", "type": ["Água"], "evo": "Forma Final"},
    {"num": 120, "name": "Staryu", "type": ["Água"], "evo": "Pedra da Água -> Starmie"},
    {"num": 121, "name": "Starmie", "type": ["Água", "Psíquico"], "evo": "Forma Final"},
    {"num": 122, "name": "Mr. Mime", "type": ["Psíquico", "Fada"], "evo": "Não evolui"},
    {"num": 123, "name": "Scyther", "type": ["Inseto", "Voador"], "evo": "Revestimento Metálico (Metal Coat) -> Scizor"},
    {"num": 124, "name": "Jynx", "type": ["Gelo", "Psíquico"], "evo": "Forma Final"},
    {"num": 125, "name": "Electabuzz", "type": ["Elétrico"], "evo": "Forma Final"},
    {"num": 126, "name": "Magmar", "type": ["Fogo"], "evo": "Forma Final"},
    {"num": 127, "name": "Pinsir", "type": ["Inseto"], "evo": "Não evolui"},
    {"num": 128, "name": "Tauros", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 129, "name": "Magikarp", "type": ["Água"], "evo": "Lv 20 -> Gyarados"},
    {"num": 130, "name": "Gyarados", "type": ["Água", "Voador"], "evo": "Forma Final"},
    {"num": 131, "name": "Lapras", "type": ["Água", "Gelo"], "evo": "Não evolui"},
    {"num": 132, "name": "Ditto", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 133, "name": "Eevee", "type": ["Normal"], "evo": "Pedras (Vaporeon/Jolteon/Flareon/Espeon/Umbreon/Leafeon), Gelo Eterno (Glaceon) ou Golpe Fada (Sylveon)"},
    {"num": 134, "name": "Vaporeon", "type": ["Água"], "evo": "Forma Final"},
    {"num": 135, "name": "Jolteon", "type": ["Elétrico"], "evo": "Forma Final"},
    {"num": 136, "name": "Flareon", "type": ["Fogo"], "evo": "Forma Final"},
    {"num": 137, "name": "Porygon", "type": ["Normal"], "evo": "Up-Grade -> Porygon2"},
    {"num": 138, "name": "Omanyte", "type": ["Pedra", "Água"], "evo": "Lv 40 -> Omastar"},
    {"num": 139, "name": "Omastar", "type": ["Pedra", "Água"], "evo": "Forma Final"},
    {"num": 140, "name": "Kabuto", "type": ["Pedra", "Água"], "evo": "Lv 40 -> Kabutops"},
    {"num": 141, "name": "Kabutops", "type": ["Pedra", "Água"], "evo": "Forma Final"},
    {"num": 142, "name": "Aerodactyl", "type": ["Pedra", "Voador"], "evo": "Não evolui"},
    {"num": 143, "name": "Snorlax", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 144, "name": "Articuno", "type": ["Gelo", "Voador"], "evo": "Lendário (Seafoam Islands)"},
    {"num": 145, "name": "Zapdos", "type": ["Elétrico", "Voador"], "evo": "Lendário (Power Plant)"},
    {"num": 146, "name": "Moltres", "type": ["Fogo", "Voador"], "evo": "Lendário (Victory Road)"},
    {"num": 147, "name": "Dratini", "type": ["Dragão"], "evo": "Lv 30 -> Dragonair"},
    {"num": 148, "name": "Dragonair", "type": ["Dragão"], "evo": "Lv 55 -> Dragonite"},
    {"num": 149, "name": "Dragonite", "type": ["Dragão", "Voador"], "evo": "Forma Final"},
    {"num": 150, "name": "Mewtwo", "type": ["Psíquico"], "evo": "Lendário (Cerulean Cave Lv 70)"},
    {"num": 151, "name": "Mew", "type": ["Psíquico"], "evo": "Mítico (Faraway Island Lv 30)"},
    # Gen 2
    {"num": 152, "name": "Chikorita", "type": ["Planta"], "evo": "Lv 16 -> Bayleef"},
    {"num": 153, "name": "Bayleef", "type": ["Planta"], "evo": "Lv 32 -> Meganium"},
    {"num": 154, "name": "Meganium", "type": ["Planta"], "evo": "Forma Final"},
    {"num": 155, "name": "Cyndaquil", "type": ["Fogo"], "evo": "Lv 14 -> Quilava"},
    {"num": 156, "name": "Quilava", "type": ["Fogo"], "evo": "Lv 36 -> Typhlosion"},
    {"num": 157, "name": "Typhlosion", "type": ["Fogo"], "evo": "Forma Final"},
    {"num": 158, "name": "Totodile", "type": ["Água"], "evo": "Lv 18 -> Croconaw"},
    {"num": 159, "name": "Croconaw", "type": ["Água"], "evo": "Lv 30 -> Feraligatr"},
    {"num": 160, "name": "Feraligatr", "type": ["Água"], "evo": "Forma Final"},
    {"num": 161, "name": "Sentret", "type": ["Normal"], "evo": "Lv 15 -> Furret"},
    {"num": 162, "name": "Furret", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 163, "name": "Hoothoot", "type": ["Normal", "Voador"], "evo": "Lv 20 -> Noctowl"},
    {"num": 164, "name": "Noctowl", "type": ["Normal", "Voador"], "evo": "Forma Final"},
    {"num": 165, "name": "Ledyba", "type": ["Inseto", "Voador"], "evo": "Lv 18 -> Ledian"},
    {"num": 166, "name": "Ledian", "type": ["Inseto", "Voador"], "evo": "Forma Final"},
    {"num": 167, "name": "Spinarak", "type": ["Inseto", "Veneno"], "evo": "Lv 22 -> Ariados"},
    {"num": 168, "name": "Ariados", "type": ["Inseto", "Veneno"], "evo": "Forma Final"},
    {"num": 169, "name": "Crobat", "type": ["Veneno", "Voador"], "evo": "Forma Final"},
    {"num": 170, "name": "Chinchou", "type": ["Água", "Elétrico"], "evo": "Lv 27 -> Lanturn"},
    {"num": 171, "name": "Lanturn", "type": ["Água", "Elétrico"], "evo": "Forma Final"},
    {"num": 172, "name": "Pichu", "type": ["Elétrico"], "evo": "Felicidade Máxima -> Pikachu"},
    {"num": 173, "name": "Cleffa", "type": ["Fada"], "evo": "Felicidade Máxima -> Clefairy"},
    {"num": 174, "name": "Igglybuff", "type": ["Normal", "Fada"], "evo": "Felicidade Máxima -> Jigglypuff"},
    {"num": 175, "name": "Togepi", "type": ["Fada"], "evo": "Felicidade Máxima -> Togetic"},
    {"num": 176, "name": "Togetic", "type": ["Fada", "Voador"], "evo": "Forma Final"},
    {"num": 177, "name": "Natu", "type": ["Psíquico", "Voador"], "evo": "Lv 25 -> Xatu"},
    {"num": 178, "name": "Xatu", "type": ["Psíquico", "Voador"], "evo": "Forma Final"},
    {"num": 179, "name": "Mareep", "type": ["Elétrico"], "evo": "Lv 15 -> Flaaffy"},
    {"num": 180, "name": "Flaaffy", "type": ["Elétrico"], "evo": "Lv 30 -> Ampharos"},
    {"num": 181, "name": "Ampharos", "type": ["Elétrico"], "evo": "Forma Final"},
    {"num": 182, "name": "Bellossom", "type": ["Planta"], "evo": "Forma Final"},
    {"num": 183, "name": "Marill", "type": ["Água", "Fada"], "evo": "Lv 18 -> Azumarill"},
    {"num": 184, "name": "Azumarill", "type": ["Água", "Fada"], "evo": "Forma Final"},
    {"num": 185, "name": "Sudowoodo", "type": ["Pedra"], "evo": "Não evolui"},
    {"num": 186, "name": "Politoed", "type": ["Água"], "evo": "Forma Final"},
    {"num": 187, "name": "Hoppip", "type": ["Planta", "Voador"], "evo": "Lv 18 -> Skiploom"},
    {"num": 188, "name": "Skiploom", "type": ["Planta", "Voador"], "evo": "Lv 27 -> Jumpluff"},
    {"num": 189, "name": "Jumpluff", "type": ["Planta", "Voador"], "evo": "Forma Final"},
    {"num": 190, "name": "Aipom", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 191, "name": "Sunkern", "type": ["Planta"], "evo": "Pedra Solar -> Sunflora"},
    {"num": 192, "name": "Sunflora", "type": ["Planta"], "evo": "Forma Final"},
    {"num": 193, "name": "Yanma", "type": ["Inseto", "Voador"], "evo": "Não evolui"},
    {"num": 194, "name": "Wooper", "type": ["Água", "Terra"], "evo": "Lv 20 -> Quagsire"},
    {"num": 195, "name": "Quagsire", "type": ["Água", "Terra"], "evo": "Forma Final"},
    {"num": 196, "name": "Espeon", "type": ["Psíquico"], "evo": "Pedra Solar ou Felicidade (Dia) -> Espeon"},
    {"num": 197, "name": "Umbreon", "type": ["Sombrio"], "evo": "Pedra da Lua ou Felicidade (Noite) -> Umbreon"},
    {"num": 198, "name": "Murkrow", "type": ["Sombrio", "Voador"], "evo": "Não evolui"},
    {"num": 199, "name": "Slowking", "type": ["Água", "Psíquico"], "evo": "Forma Final"},
    {"num": 200, "name": "Misdreavus", "type": ["Fantasma"], "evo": "Não evolui"},
    {"num": 201, "name": "Unown", "type": ["Psíquico"], "evo": "Não evolui"},
    {"num": 202, "name": "Wobbuffet", "type": ["Psíquico"], "evo": "Forma Final"},
    {"num": 203, "name": "Girafarig", "type": ["Normal", "Psíquico"], "evo": "Não evolui"},
    {"num": 204, "name": "Pineco", "type": ["Inseto"], "evo": "Lv 31 -> Forretress"},
    {"num": 205, "name": "Forretress", "type": ["Inseto", "Aço"], "evo": "Forma Final"},
    {"num": 206, "name": "Dunsparce", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 207, "name": "Gligar", "type": ["Terra", "Voador"], "evo": "Não evolui"},
    {"num": 208, "name": "Steelix", "type": ["Aço", "Terra"], "evo": "Forma Final"},
    {"num": 209, "name": "Snubbull", "type": ["Fada"], "evo": "Lv 23 -> Granbull"},
    {"num": 210, "name": "Granbull", "type": ["Fada"], "evo": "Forma Final"},
    {"num": 211, "name": "Qwilfish", "type": ["Água", "Veneno"], "evo": "Não evolui"},
    {"num": 212, "name": "Scizor", "type": ["Inseto", "Aço"], "evo": "Forma Final"},
    {"num": 213, "name": "Shuckle", "type": ["Inseto", "Pedra"], "evo": "Não evolui"},
    {"num": 214, "name": "Heracross", "type": ["Inseto", "Lutador"], "evo": "Não evolui"},
    {"num": 215, "name": "Sneasel", "type": ["Sombrio", "Gelo"], "evo": "Não evolui"},
    {"num": 216, "name": "Teddiursa", "type": ["Normal"], "evo": "Lv 30 -> Ursaring"},
    {"num": 217, "name": "Ursaring", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 218, "name": "Slugma", "type": ["Fogo"], "evo": "Lv 38 -> Magcargo"},
    {"num": 219, "name": "Magcargo", "type": ["Fogo", "Pedra"], "evo": "Forma Final"},
    {"num": 220, "name": "Swinub", "type": ["Gelo", "Terra"], "evo": "Lv 33 -> Piloswine"},
    {"num": 221, "name": "Piloswine", "type": ["Gelo", "Terra"], "evo": "Forma Final"},
    {"num": 222, "name": "Corsola", "type": ["Água", "Pedra"], "evo": "Não evolui"},
    {"num": 223, "name": "Remoraid", "type": ["Água"], "evo": "Lv 25 -> Octillery"},
    {"num": 224, "name": "Octillery", "type": ["Água"], "evo": "Forma Final"},
    {"num": 225, "name": "Delibird", "type": ["Gelo", "Voador"], "evo": "Não evolui"},
    {"num": 226, "name": "Mantine", "type": ["Água", "Voador"], "evo": "Não evolui"},
    {"num": 227, "name": "Skarmory", "type": ["Aço", "Voador"], "evo": "Não evolui"},
    {"num": 228, "name": "Houndour", "type": ["Sombrio", "Fogo"], "evo": "Lv 24 -> Houndoom"},
    {"num": 229, "name": "Houndoom", "type": ["Sombrio", "Fogo"], "evo": "Forma Final"},
    {"num": 230, "name": "Kingdra", "type": ["Água", "Dragão"], "evo": "Forma Final"},
    {"num": 231, "name": "Phanpy", "type": ["Terra"], "evo": "Lv 25 -> Donphan"},
    {"num": 232, "name": "Donphan", "type": ["Terra"], "evo": "Forma Final"},
    {"num": 233, "name": "Porygon2", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 234, "name": "Stantler", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 235, "name": "Smeargle", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 236, "name": "Tyrogue", "type": ["Lutador"], "evo": "Lv 20 -> Hitmonlee (Atk > Def), Hitmonchan (Def > Atk) ou Hitmontop (Atk == Def)"},
    {"num": 237, "name": "Hitmontop", "type": ["Lutador"], "evo": "Forma Final"},
    {"num": 238, "name": "Smoochum", "type": ["Gelo", "Psíquico"], "evo": "Lv 30 -> Jynx"},
    {"num": 239, "name": "Elekid", "type": ["Elétrico"], "evo": "Lv 30 -> Electabuzz"},
    {"num": 240, "name": "Magby", "type": ["Fogo"], "evo": "Lv 30 -> Magmar"},
    {"num": 241, "name": "Miltank", "type": ["Normal"], "evo": "Não evolui"},
    {"num": 242, "name": "Blissey", "type": ["Normal"], "evo": "Forma Final"},
    {"num": 243, "name": "Raikou", "type": ["Elétrico"], "evo": "Cão Lendário (Burned Tower)"},
    {"num": 244, "name": "Entei", "type": ["Fogo"], "evo": "Cão Lendário (Burned Tower)"},
    {"num": 245, "name": "Suicune", "type": ["Água"], "evo": "Cão Lendário (Burned Tower)"},
    {"num": 246, "name": "Larvitar", "type": ["Pedra", "Terra"], "evo": "Lv 30 -> Pupitar"},
    {"num": 247, "name": "Pupitar", "type": ["Pedra", "Terra"], "evo": "Lv 55 -> Tyranitar"},
    {"num": 248, "name": "Tyranitar", "type": ["Pedra", "Sombrio"], "evo": "Forma Final"},
    {"num": 249, "name": "Lugia", "type": ["Psíquico", "Voador"], "evo": "Lendário Guardião (Navel Rock Lv 70)"},
    {"num": 250, "name": "Ho-Oh", "type": ["Fogo", "Voador"], "evo": "Lendário Sagrado (Navel Rock Lv 70)"},
    {"num": 251, "name": "Celebi", "type": ["Psíquico", "Planta"], "evo": "Mítico Viajante do Tempo (Ilex Forest)"}
]

# Serializar encontros para JSON seguro em JS
routes_data_clean = []
for rname, rdata in sorted(routes_map.items()):
    # Priorizar rotas relevantes
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
            font-size: 0.9rem;
            font-weight: 600;
            cursor: pointer;
            border: none;
            background: none;
            text-align: left;
            width: 100%;
            transition: all 0.15s;
        }}

        .nav-item:hover {{
            color: white;
            background: rgba(255, 255, 255, 0.05);
        }}

        .nav-item.active {{
            color: white;
            background: var(--primary);
            box-shadow: 0 4px 12px rgba(239, 68, 68, 0.35);
        }}

        /* ====================
           MAIN CONTENT AREA
           ==================== */
        #content-area {{
            margin-left: 280px;
            flex: 1;
            padding: 2rem 2.5rem;
            max-width: 1300px;
        }}

        .mobile-header {{
            display: none;
            justify-content: space-between;
            align-items: center;
            padding: 1rem;
            background: var(--bg-sidebar);
            border-bottom: 1px solid var(--border-color);
            position: sticky;
            top: 0;
            z-index: 90;
        }}

        .btn-hamburger {{
            background: none;
            border: none;
            color: white;
            font-size: 1.5rem;
            cursor: pointer;
        }}

        .section-pane {{
            display: none;
            animation: fadeIn 0.25s ease-out;
        }}

        .section-pane.active {{
            display: block;
        }}

        @keyframes fadeIn {{
            from {{ opacity: 0; transform: translateY(4px); }}
            to {{ opacity: 1; transform: translateY(0); }}
        }}

        .pane-header {{
            margin-bottom: 2rem;
            padding-bottom: 1rem;
            border-bottom: 1px solid var(--border-color);
        }}

        .pane-header h1 {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.85rem;
            font-weight: 800;
            color: #ffffff;
            margin-bottom: 0.25rem;
        }}

        .pane-header p {{
            color: var(--text-muted);
            font-size: 0.95rem;
        }}

        /* Cards & Grid */
        .card-grid-2 {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(320px, 1fr));
            gap: 1.5rem;
            margin-bottom: 2rem;
        }}

        .wiki-card {{
            background: var(--bg-card);
            border: 1px solid var(--border-color);
            border-radius: 14px;
            padding: 1.5rem;
            box-shadow: 0 8px 24px rgba(0, 0, 0, 0.4);
            backdrop-filter: blur(8px);
        }}

        .wiki-card-header {{
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 1rem;
            padding-bottom: 0.75rem;
            border-bottom: 1px solid var(--border-color);
        }}

        .wiki-card-header h2, .wiki-card-header h3 {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.25rem;
            font-weight: 700;
        }}

        .tag-pill {{
            background: rgba(239, 68, 68, 0.15);
            color: #f87171;
            border: 1px solid rgba(239, 68, 68, 0.35);
            padding: 0.2rem 0.6rem;
            border-radius: 9999px;
            font-size: 0.75rem;
            font-weight: 700;
        }}

        .info-box {{
            background: rgba(59, 130, 246, 0.1);
            border-left: 4px solid var(--secondary);
            border-radius: 0 8px 8px 0;
            padding: 0.85rem 1rem;
            margin: 1rem 0;
            font-size: 0.9rem;
            color: #bfdbfe;
        }}

        .info-box.success {{
            background: rgba(34, 197, 94, 0.1);
            border-left-color: #22c55e;
            color: #bbf7d0;
        }}

        .info-box.warn {{
            background: rgba(245, 158, 11, 0.1);
            border-left-color: var(--accent);
            color: #fde68a;
        }}

        /* Data Tables */
        .data-table {{
            width: 100%;
            border-collapse: collapse;
            font-size: 0.9rem;
            margin-top: 1rem;
            border-radius: 8px;
            overflow: hidden;
        }}

        .data-table th {{
            background: rgba(15, 23, 42, 0.95);
            color: var(--text-muted);
            text-align: left;
            padding: 0.75rem 1rem;
            font-weight: 700;
            border-bottom: 1px solid var(--border-color);
        }}

        .data-table td {{
            padding: 0.75rem 1rem;
            border-bottom: 1px solid rgba(255, 255, 255, 0.05);
            vertical-align: middle;
        }}

        .data-table tr:hover {{
            background: rgba(255, 255, 255, 0.03);
        }}

        /* Pokédex Cards Grid */
        .pokedex-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(260px, 1fr));
            gap: 1rem;
            margin-top: 1.5rem;
        }}

        .mon-card {{
            background: rgba(17, 24, 39, 0.8);
            border: 1px solid var(--border-color);
            border-radius: 12px;
            padding: 1rem;
            display: flex;
            flex-direction: column;
            gap: 0.5rem;
            transition: transform 0.15s, border-color 0.15s;
        }}

        .mon-card:hover {{
            transform: translateY(-2px);
            border-color: rgba(255, 255, 255, 0.25);
            box-shadow: 0 6px 18px rgba(0, 0, 0, 0.5);
        }}

        .mon-card-header {{
            display: flex;
            justify-content: space-between;
            align-items: center;
        }}

        .mon-number {{
            font-size: 0.8rem;
            font-weight: 800;
            color: var(--text-muted);
        }}

        .mon-name {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.1rem;
            font-weight: 800;
            color: white;
        }}

        .type-badge {{
            display: inline-block;
            font-size: 0.7rem;
            font-weight: 800;
            padding: 0.2rem 0.55rem;
            border-radius: 9999px;
            text-transform: uppercase;
            margin-right: 4px;
        }}

        .type-Fogo {{ background: #ef4444; color: white; }}
        .type-Água {{ background: #3b82f6; color: white; }}
        .type-Planta {{ background: #22c55e; color: white; }}
        .type-Elétrico {{ background: #facc15; color: #1e293b; }}
        .type-Gelo {{ background: #67e8f9; color: #082f49; }}
        .type-Lutador {{ background: #b91c1c; color: white; }}
        .type-Veneno {{ background: #a855f7; color: white; }}
        .type-Terra {{ background: #d97706; color: white; }}
        .type-Voador {{ background: #818cf8; color: white; }}
        .type-Psíquico {{ background: #ec4899; color: white; }}
        .type-Inseto {{ background: #84cc16; color: #1e293b; }}
        .type-Pedra {{ background: #78716c; color: white; }}
        .type-Fantasma {{ background: #6366f1; color: white; }}
        .type-Dragão {{ background: #7c3aed; color: white; }}
        .type-Aço {{ background: #94a3b8; color: #0f172a; }}
        .type-Fada {{ background: #f472b6; color: white; }}
        .type-Sombrio {{ background: #334155; color: white; }}
        .type-Normal {{ background: #64748b; color: white; }}

        .mon-evo-note {{
            font-size: 0.8rem;
            color: #cbd5e1;
            background: rgba(255, 255, 255, 0.04);
            padding: 0.4rem 0.6rem;
            border-radius: 6px;
            margin-top: 0.25rem;
        }}

        .type-filter-bar {{
            display: flex;
            gap: 0.4rem;
            flex-wrap: wrap;
            margin: 1rem 0;
        }}

        .type-filter-btn {{
            border: 1px solid var(--border-color);
            background: rgba(255, 255, 255, 0.05);
            color: var(--text-muted);
            padding: 0.35rem 0.75rem;
            border-radius: 9999px;
            font-size: 0.8rem;
            font-weight: 700;
            cursor: pointer;
            transition: all 0.15s;
        }}

        .type-filter-btn.active, .type-filter-btn:hover {{
            background: var(--primary);
            color: white;
            border-color: var(--primary);
        }}

        /* Encounters Display */
        .encounter-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(320px, 1fr));
            gap: 1.25rem;
            margin-top: 1rem;
        }}

        .encounter-card {{
            background: rgba(17, 24, 39, 0.7);
            border: 1px solid var(--border-color);
            border-radius: 12px;
            padding: 1.25rem;
        }}

        .encounter-card h3 {{
            font-family: 'Outfit', sans-serif;
            font-size: 1.15rem;
            margin-bottom: 0.75rem;
            color: #ffffff;
            border-bottom: 1px solid rgba(255, 255, 255, 0.08);
            padding-bottom: 0.4rem;
        }}

        .mon-tag {{
            display: inline-block;
            background: rgba(255, 255, 255, 0.06);
            border: 1px solid rgba(255, 255, 255, 0.1);
            padding: 0.25rem 0.5rem;
            border-radius: 6px;
            font-size: 0.8rem;
            margin: 0.15rem;
        }}

        .mon-tag.day {{ border-color: rgba(245, 158, 11, 0.4); background: rgba(245, 158, 11, 0.1); color: #fde68a; }}
        .mon-tag.night {{ border-color: rgba(99, 102, 241, 0.4); background: rgba(99, 102, 241, 0.1); color: #c7d2fe; }}
        .mon-tag.water {{ border-color: rgba(59, 130, 246, 0.4); background: rgba(59, 130, 246, 0.1); color: #bfdbfe; }}
        .mon-tag.hidden {{ border-color: rgba(34, 197, 94, 0.4); background: rgba(34, 197, 94, 0.1); color: #bbf7d0; }}

        /* Responsive */
        @media (max-width: 900px) {{
            #sidebar {{
                transform: translateX(-100%);
            }}
            #sidebar.open {{
                transform: translateX(0);
            }}
            #content-area {{
                margin-left: 0;
                padding: 1.25rem;
            }}
            .mobile-header {{
                display: flex;
            }}
        }}
    </style>
</head>
<body>

    <!-- Mobile Header -->
    <div class="mobile-header">
        <span class="brand-title">🔴⚪ Kanto & Johto Wiki</span>
        <button class="btn-hamburger" onclick="toggleSidebar()">☰</button>
    </div>

    <!-- Sidebar -->
    <aside id="sidebar">
        <div class="sidebar-brand">
            <div class="brand-title">🔴⚪ Kanto & Johto</div>
            <div class="brand-sub">Wiki & Enciclopédia Oficial do Jogo</div>
        </div>

        <div class="search-area">
            <div class="search-wrap">
                <input type="text" id="wikiGlobalSearch" class="global-search-input" placeholder="Buscar rota, Pokémon, item..." oninput="handleGlobalSearch(this.value)">
            </div>
        </div>

        <nav class="nav-menu">
            <button class="nav-item active" onclick="showPane('qol')">⭐ Visão Geral & QoL</button>
            <button class="nav-item" onclick="showPane('walkthrough-kanto')">🗺️ Detonado: Kanto</button>
            <button class="nav-item" onclick="showPane('walkthrough-johto')">🚄 Detonado: Johto</button>
            <button class="nav-item" onclick="showPane('encounters')">🧭 Rotas & Encontros</button>
            <button class="nav-item" onclick="showPane('pokedex')">📖 Pokédex Regional 251</button>
            <button class="nav-item" onclick="showPane('gyms')">🥊 Ginásios & Chefes</button>
            <button class="nav-item" onclick="showPane('items')">🎁 TMs, HMs & Itens</button>
            <button class="nav-item" onclick="showPane('legendaries')">🦅 Guia dos Lendários</button>
        </nav>
    </aside>

    <!-- Main Content -->
    <main id="content-area">

        <!-- 1. VISÃO GERAL & QOL -->
        <section id="pane-qol" class="section-pane active">
            <div class="pane-header">
                <h1>⭐ Guia Oficial de Qualidade de Vida (QoL)</h1>
                <p>Todas as mecânicas modernas implementadas para transformar a experiência clássica de Kanto e Johto.</p>
            </div>

            <div class="card-grid-2">
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>🌳 HMs Sem "Escravo de HM"</h3>
                        <span class="tag-pill">Ativo</span>
                    </div>
                    <p>Você <b>nunca mais precisa ensinar</b> <i>Cut, Rock Smash, Strength, Surf, Waterfall, Dive ou Flash</i> para nenhum Pokémon da sua equipe! Não é necessário carregar um monstro fraco ocupando vaga na equipe.</p>
                    <div class="info-box success">
                        <strong>Como Usar:</strong> Basta ter a <b>HM na Bolsa</b> e a <b>Insígnia necessária</b>. Aperte <b>A</b> diretamente na árvore, pedra, rocha de força ou na água para usar o movimento!
                    </div>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>🎯 Ganho de EXP ao Capturar</h3>
                        <span class="tag-pill">Gen 6+</span>
                    </div>
                    <p>Ao jogar uma Pokébola e capturar qualquer monstro selvagem, todos os membros da sua equipe que participaram da batalha recebem <b>Pontos de Experiência (EXP)</b> automaticamente.</p>
                    <div class="info-box success">
                        Incentiva a captura de novos Pokémon para completar a Pokédex sem atrasar o treinamento da sua equipe!
                    </div>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>🌓 Ciclo Dinâmico de Dia e Noite</h3>
                        <span class="tag-pill">Tempo Real</span>
                    </div>
                    <p>O jogo lê o relógio do seu dispositivo (RTC) e reproduz iluminação dinâmica suave:</p>
                    <ul style="padding-left: 1.25rem; font-size: 0.9rem; margin-top: 0.5rem; color: #cbd5e1;">
                        <li><b>04:00 às 10:00:</b> Alvorecer com tom dourado suave.</li>
                        <li><b>10:00 às 18:00:</b> Luz solar nítida do dia.</li>
                        <li><b>18:00 às 22:00:</b> Entardecer e crepúsculo.</li>
                        <li><b>22:00 às 04:00:</b> Noite profunda enluarada com encontros noturnos!</li>
                    </ul>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>📱 Handheld APK com Controles Touch & Filtros</h3>
                        <span class="tag-pill">Mobile</span>
                    </div>
                    <p>O aplicativo para celular conta com chassis autêntico de Game Boy Advance, layout sem sobreposição de botões e menu <b>⚙️</b> para regular:</p>
                    <ul style="padding-left: 1.25rem; font-size: 0.9rem; margin-top: 0.5rem; color: #cbd5e1;">
                        <li><b>Transparência e Tamanho:</b> Reduza a opacidade dos botões para ver toda a tela.</li>
                        <li><b>Filtros Gráficos:</b> Pixel Art Nítido 1:1, Matriz LCD Retrô GBA, CRT Scanlines ou Suavizado HQ.</li>
                    </ul>
                </div>
            </div>
        </section>

        <!-- 2. DETONADO KANTO -->
        <section id="pane-walkthrough-kanto" class="section-pane">
            <div class="pane-header">
                <h1>🗺️ Detonado Passo a Passo: Região de Kanto</h1>
                <p>Roteiro completo do início em Pallet Town até a consagração como Campeão no Indigo Plateau.</p>
            </div>

            <div class="card-grid-2">
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 1: O Começo & Insígnia Rocha</h3>
                        <span class="tag-pill">Pallet a Pewter</span>
                    </div>
                    <p>1. Inicie em <b>Pallet Town</b> e receba seu Inicial com o Prof. Carvalho.<br>
                    2. Vá até a <b>Viridian City</b>, pegue a encomenda no Mart e volte a Pallet para receber sua <b>Pokédex</b> e o <b>DexNav</b> com radar de encontros visíveis no mapa.<br>
                    3. Atravesse a <b>Viridian Forest</b> (ótimo para capturar Pikachu na grama).<br>
                    4. Em <b>Pewter City</b>, desafie Brock no Ginásio. Use Bulbasaur, Squirtle ou o Mankey capturado na Rota 22 com Chute Duplo.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 2: Monte Moon & Insígnia Cascata</h3>
                        <span class="tag-pill">Mt. Moon a Cerulean</span>
                    </div>
                    <p>1. Na Rota 3, compre a Magikarp ou treine contra os ornitólogos.<br>
                    2. No <b>Mt. Moon</b>, enfrente os capangas da Equipe Rocket e escolha entre o <i>Helix Fossil</i> (Omanyte) ou <i>Dome Fossil</i> (Kabuto).<br>
                    3. Em <b>Cerulean City</b>, vença o Rival, atravesse a <b>Nugget Bridge</b> até a casa de Bill e ganhe o <b>S.S. Ticket</b>.<br>
                    4. <b>Ginásio de Cerulean:</b> Derrote Misty usando Elétrico (Pikachu) ou Planta (Oddish/Bellsprout).</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 3: S.S. Anne & Insígnia Trovão</h3>
                        <span class="tag-pill">Vermilion City</span>
                    </div>
                    <p>1. Siga pela Rota 5/6 até <b>Vermilion City</b>.<br>
                    2. Embarque no transatlântico <b>S.S. Anne</b>, vença os marinheiros e fale com o Capitão para receber a <b>HM01 Corte</b>.<br>
                    3. Na Caverna dos Diglett, capture um Diglett com Terra.<br>
                    4. <b>Ginásio de Vermilion:</b> Corte o arbusto na entrada com o botão A. Resolva os cestos de lixo e derrote o <b>Lt. Surge</b> facilmente com ataques de Terra!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 4: Rock Tunnel & Lavender Town</h3>
                        <span class="tag-pill">Caverna Escura</span>
                    </div>
                    <p>1. Pegue a <b>HM05 Clarão</b> na Rota 2 com o assistente de Carvalho.<br>
                    2. Atravesse o <b>Rock Tunnel</b> (a caverna se ilumina automaticamente tendo a HM na bolsa!).<br>
                    3. Chegue em <b>Lavender Town</b>. A Torre Pokémon está assombrada por um espírito fantasma que você ainda não consegue identificar; prossiga a oeste pela Rota 8 até Celadon.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 5: Celadon City & Erika</h3>
                        <span class="tag-pill">Insígnia Arco-Íris</span>
                    </div>
                    <p>1. Na Mansão de Celadon, pegue o <b>Eevee</b> gratuito no terraço.<br>
                    2. No <b>Rocket Game Corner</b>, aperte o botão secreto atrás do pôster e derrote Giovanni no esconderijo para pegar o <b>Silph Scope</b>!<br>
                    3. Volte à Torre de Lavender, revele o fantasma da Marowak e salve o Sr. Fuji para ganhar a <b>Poké Flute</b>.<br>
                    4. <b>Ginásio de Celadon:</b> Derrote Erika usando golpes de Fogo, Voador ou Gelo.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 6: Silph Co. & Sabrina</h3>
                        <span class="tag-pill">Saffron City</span>
                    </div>
                    <p>1. Entre na metrópole de <b>Saffron City</b> e invada o arranha-céu da <b>Silph Co.</b>.<br>
                    2. No 5º andar, pegue o <b>Card Key</b> para abrir todas as portas trancadas.<br>
                    3. No 7º andar, vença o Rival e ganhe um <b>Lapras</b> de presente. No 11º andar, derrote Giovanni e ganhe a <b>Master Ball</b> do presidente!<br>
                    4. <b>Ginásio de Saffron:</b> Sabrina usa Alakazam muito rápido. Ataques Físicos e do tipo Sombrio vencem!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 7: Safari Zone, Fuchsia & Koga</h3>
                        <span class="tag-pill">Insígnia Alma</span>
                    </div>
                    <p>1. Acorde o Snorlax adormecido com a Poké Flute e desça a Ciclovia.<br>
                    2. Na <b>Safari Zone</b> de Fuchsia, chegue à cabana secreta na Área 3 para ganhar a <b>HM03 Surfe</b> e pegue os Dentes de Ouro para trocar pela <b>HM04 Força</b>!<br>
                    3. <b>Ginásio de Fuchsia:</b> Koga usa paredes invisíveis. Psíquico e Terra destroem seus venenos.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Capítulo 8: Cinnabar, Viridian & Giovanni</h3>
                        <span class="tag-pill">8 Insígnias Conquistadas!</span>
                    </div>
                    <p>1. Surfe pelas rotas do sul até a <b>Pokémon Mansion</b> em Cinnabar para pegar a chave do ginásio.<br>
                    2. <b>Ginásio de Cinnabar:</b> Blaine usa Fogo. Água e Pedra vencem facilmente.<br>
                    3. Volte a <b>Viridian City</b>: o líder misterioso é <b>Giovanni</b>! Use Água, Planta e Gelo contra seus tipos Terra para garantir as 8 Insígnias de Kanto!</p>
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
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 1: Travessia para Johto & Falkner</h3>
                        <span class="tag-pill">Nível 55 a 62</span>
                    </div>
                    <p>1. Vá ao porto de Vermilion e embarque no luxuoso <b>S.S. Aqua</b> com o passe concedido por Carvalho.<br>
                    2. Desembarque em <b>New Bark Town</b> e explore a Rota 29 até Violet City.<br>
                    3. Suba a <b>Sprout Tower</b> e vença os monges de Bellsprout.<br>
                    4. <b>Ginásio de Violet:</b> Falkner usa Pidgeot e Noctowl de nível 58+. Golpes Elétricos e de Gelo derrubam sua revoada.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 2: Azalea Town & Bugsy</h3>
                        <span class="tag-pill">Poço Slowpoke</span>
                    </div>
                    <p>1. Atravesse a Union Cave até <b>Azalea Town</b>.<br>
                    2. Fale com Kurt e expulse a Equipe Rocket do <b>Slowpoke Well</b>.<br>
                    3. <b>Ginásio de Azalea:</b> Bugsy usa Scizor e Heracross em nível 62+. Golpes do tipo Fogo causam dano quadruplicado e vencem na hora!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 3: Goldenrod City & Whitney</h3>
                        <span class="tag-pill">A Metrópole</span>
                    </div>
                    <p>1. Atravesse a Ilex Forest até a capital comercial de <b>Goldenrod City</b>.<br>
                    2. Conheça a Estação do Trem Magnético e a Torre de Rádio.<br>
                    3. <b>Ginásio de Goldenrod:</b> Whitney possui Miltank com Rollout e Milk Drink em nível 66+. Use monstros de Pedra com alta defesa ou golpes do tipo Lutador!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 4: Ecruteak City & Morty</h3>
                        <span class="tag-pill">Torre Queimada</span>
                    </div>
                    <p>1. Siga pela Rota 35/36 e use o regador SquirtBottle para enfrentar o <b>Sudowoodo</b> que bloqueia a passagem.<br>
                    2. Na <b>Burned Tower</b> de Ecruteak, liberte os cães lendários <i>Raikou, Entei e Suicune</i>!<br>
                    3. <b>Ginásio de Ecruteak:</b> Morty usa Gengar e fantasmas no chão invisível. Golpes Sombrios e Psíquicos garantem a Insígnia da Neblina.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 5: Cianwood, Olivine & Jasmine</h3>
                        <span class="tag-pill">Insígnia Mineral</span>
                    </div>
                    <p>1. Surfe pelo mar até <b>Cianwood City</b>. Derrote Chuck (Lutador) com voadores/psíquicos e pegue o Remédio Secreto na farmácia.<br>
                    2. Volte a <b>Olivine City</b>, suba o Farol e cure o Ampharos.<br>
                    3. <b>Ginásio de Olivine:</b> Jasmine usa Steelix e Magnemite. Golpes de Fogo e Terremoto derretem sua armadura de ferro!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Fase 6: Lago da Fúria, Pryce & Clair</h3>
                        <span class="tag-pill">Gyarados Vermelho</span>
                    </div>
                    <p>1. Em <b>Mahogany Town</b>, suba até o Lago da Fúria e capture o famoso <b>Gyarados Vermelho (Shiny)</b>!<br>
                    2. Vencendo o ginásio de Gelo de Pryce, atravesse a caverna de gelo até <b>Blackthorn City</b>.<br>
                    3. <b>Ginásio de Blackthorn:</b> Clair usa Kingdra e Dragonites em nível 83+. Ataques de Fada e Dragão são fundamentais!</p>
                </div>

                <div class="wiki-card" style="grid-column: 1 / -1; border-color: rgba(239, 68, 68, 0.4);">
                    <div class="wiki-card-header">
                        <h3>O Clímax Supremo: O Cume do Monte Silver & Red</h3>
                        <span class="tag-pill" style="background: rgba(239, 68, 68, 0.3);">Nível 95 a 100</span>
                    </div>
                    <p>Com as 16 insígnias em mãos, o Prof. Carvalho concede permissão para entrar na montanha mais desafiadora do mundo Pokémon: o <b>Monte Silver</b>.<br><br>
                    Atravesse a caverna escura com Surfe e Cachoeira até o cume onde cai <b>neve constante</b>. Lá em cima, em silêncio absoluto, está o Campeão <b>Red</b>:</p>
                    <div class="info-box warn">
                        <strong>Equipe de Red:</strong> Pikachu (Lv 100 com Light Ball), Charizard (Lv 98), Blastoise (Lv 98), Venusaur (Lv 98), Snorlax (Lv 97) e Lapras (Lv 96).<br>
                        O granizo cairá a cada turno diminuindo a vida de ambos os lados! Traga poções máximas, Revives e uma equipe balanceada no nível 95+!
                    </div>
                </div>
            </div>
        </section>

        <!-- 4. ROTAS & ENCONTROS (DIA E NOITE) -->
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

        <!-- 6. GINÁSIOS & CHEFES -->
        <section id="pane-gyms" class="section-pane">
            <div class="pane-header">
                <h1>🥊 Tabela de Líderes, Níveis & Fraquezas</h1>
                <p>Estratégia completa para derrotar os 8 líderes de Kanto, os 8 de Johto, a Elite Four e o Campeão Red.</p>
            </div>

            <div class="wiki-card" style="margin-bottom: 2rem;">
                <h3 style="margin-bottom: 0.5rem; color: #ef4444;">Região de Kanto (Níveis 12 a 55)</h3>
                <table class="data-table">
                    <thead>
                        <tr>
                            <th>Líder</th>
                            <th>Cidade</th>
                            <th>Tipo Principal</th>
                            <th>Equipe Destaque</th>
                            <th>Fraquezas Recomendadas</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr><td><b>Brock</b></td><td>Pewter</td><td>Pedra / Terra</td><td>Geodude (Lv 12), Onix (Lv 14)</td><td>Água, Planta, Lutador</td></tr>
                        <tr><td><b>Misty</b></td><td>Cerulean</td><td>Água</td><td>Staryu (Lv 18), Starmie (Lv 21)</td><td>Elétrico, Planta</td></tr>
                        <tr><td><b>Lt. Surge</b></td><td>Vermilion</td><td>Elétrico</td><td>Voltorb (Lv 21), Pikachu (Lv 18), Raichu (Lv 24)</td><td>Terra (Diglett/Dugtrio)</td></tr>
                        <tr><td><b>Erika</b></td><td>Celadon</td><td>Planta / Veneno</td><td>Victreebel (Lv 29), Tangela (Lv 24), Vileplume (Lv 29)</td><td>Fogo, Voador, Gelo, Psíquico</td></tr>
                        <tr><td><b>Sabrina</b></td><td>Saffron</td><td>Psíquico</td><td>Kadabra (Lv 38), Mr. Mime (Lv 37), Venomoth (Lv 38), Alakazam (Lv 43)</td><td>Sombrio, Fantasma, Ataque Físico</td></tr>
                        <tr><td><b>Koga</b></td><td>Fuchsia</td><td>Veneno</td><td>Koffing (Lv 37), Muk (Lv 39), Weezing (Lv 43)</td><td>Psíquico, Terra</td></tr>
                        <tr><td><b>Blaine</b></td><td>Cinnabar</td><td>Fogo</td><td>Growlithe (Lv 42), Ponyta (Lv 40), Rapidash (Lv 42), Arcanine (Lv 47)</td><td>Água, Terra, Pedra</td></tr>
                        <tr><td><b>Giovanni</b></td><td>Viridian</td><td>Terra</td><td>Rhyhorn (Lv 45), Dugtrio (Lv 42), Nidoqueen (Lv 44), Nidoking (Lv 45), Rhydon (Lv 50)</td><td>Água, Planta, Gelo</td></tr>
                    </tbody>
                </table>
            </div>

            <div class="wiki-card">
                <h3 style="margin-bottom: 0.5rem; color: #3b82f6;">Região de Johto (Níveis 58 a 85+)</h3>
                <table class="data-table">
                    <thead>
                        <tr>
                            <th>Líder</th>
                            <th>Cidade</th>
                            <th>Tipo Principal</th>
                            <th>Equipe Destaque</th>
                            <th>Fraquezas Recomendadas</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr><td><b>Falkner</b></td><td>Violet</td><td>Voador</td><td>Pidgeot (Lv 58), Noctowl (Lv 60)</td><td>Elétrico, Gelo, Pedra</td></tr>
                        <tr><td><b>Bugsy</b></td><td>Azalea</td><td>Inseto</td><td>Scizor (Lv 62), Heracross (Lv 63)</td><td>Fogo (4x em Scizor!), Voador</td></tr>
                        <tr><td><b>Whitney</b></td><td>Goldenrod</td><td>Normal / Fada</td><td>Clefable (Lv 65), Miltank (Lv 67)</td><td>Lutador, Aço</td></tr>
                        <tr><td><b>Morty</b></td><td>Ecruteak</td><td>Fantasma</td><td>Haunter (Lv 70), Gengar (Lv 72)</td><td>Sombrio, Psíquico, Fantasma</td></tr>
                        <tr><td><b>Chuck</b></td><td>Cianwood</td><td>Lutador</td><td>Primeape (Lv 72), Poliwrath (Lv 74)</td><td>Psíquico, Voador, Fada</td></tr>
                        <tr><td><b>Jasmine</b></td><td>Olivine</td><td>Aço</td><td>Magnemite (Lv 75), Steelix (Lv 77)</td><td>Fogo, Terra, Lutador</td></tr>
                        <tr><td><b>Pryce</b></td><td>Mahogany</td><td>Gelo</td><td>Dewgong (Lv 78), Piloswine (Lv 80)</td><td>Fogo, Lutador, Elétrico</td></tr>
                        <tr><td><b>Clair</b></td><td>Blackthorn</td><td>Dragão</td><td>Dragonair (Lv 82), Kingdra (Lv 85)</td><td>Fada, Dragão</td></tr>
                    </tbody>
                </table>
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
                            <th>Golpe</th>
                            <th>Local de Obtenção</th>
                            <th>Insígnia Requerida</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr><td><b>HM01</b></td><td>Corte (Cut)</td><td>Navio S.S. Anne (Falar com Capitão)</td><td>Insígnia da Cascata (Misty)</td></tr>
                        <tr><td><b>HM02</b></td><td>Voar (Fly)</td><td>Rota 16 (Casa secreta a oeste de Celadon)</td><td>Insígnia do Trovão (Surge)</td></tr>
                        <tr><td><b>HM03</b></td><td>Surfe (Surf)</td><td>Safari Zone (Cabana secreta na Área 3)</td><td>Insígnia da Alma (Koga)</td></tr>
                        <tr><td><b>HM04</b></td><td>Força (Strength)</td><td>Fuchsia City (Entregar Dentadura ao Guarda)</td><td>Insígnia Arco-Íris (Erika)</td></tr>
                        <tr><td><b>HM05</b></td><td>Clarão (Flash)</td><td>Rota 2 (Assistente do Prof. Carvalho)</td><td>Insígnia da Rocha (Brock)</td></tr>
                        <tr><td><b>HM06</b></td><td>Quebra-Pedra (Rock Smash)</td><td>Ilha 1 / Ilha Seafoam</td><td>Insígnia do Pântano (Sabrina)</td></tr>
                        <tr><td><b>HM07</b></td><td>Cachoeira (Waterfall)</td><td>Ice Path / Tohjo Falls</td><td>Insígnia do Vulcão (Blaine)</td></tr>
                        <tr><td><b>HM08</b></td><td>Mergulho (Dive)</td><td>Costa de Johto / Ilhas do Sul</td><td>Insígnia da Terra (Giovanni)</td></tr>
                    </tbody>
                </table>
            </div>
        </section>

        <!-- 8. LENDÁRIOS -->
        <section id="pane-legendaries" class="section-pane">
            <div class="pane-header">
                <h1>🦅 Guia de Captura de Lendários & Míticos</h1>
                <p>Onde encontrar e como capturar todos os monstros sagrados de Kanto e Johto.</p>
            </div>

            <div class="card-grid-2">
                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Zapdos (Pássaro do Trovão)</h3>
                        <span class="tag-pill">Lv 50</span>
                    </div>
                    <p><b>Local:</b> Usina Elétrica Abandonada (Power Plant).<br>
                    <b>Acesso:</b> Surfe pelo rio que corre na Rota 10 ao norte de Lavender Town.<br>
                    <b>Dica:</b> Traga monstro imune a elétrico (Ground) e guarde Ultra Balls.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Articuno (Pássaro do Gelo)</h3>
                        <span class="tag-pill">Lv 50</span>
                    </div>
                    <p><b>Local:</b> Ilhas Seafoam (B4F).<br>
                    <b>Acesso:</b> Empurre as grandes pedras pelos buracos com Força para bloquear a forte correnteza marinha subterrânea.<br>
                    <b>Dica:</b> Cuidado com ataques de Gelo e o golpe Blizzard!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Moltres (Pássaro de Fogo)</h3>
                        <span class="tag-pill">Lv 50</span>
                    </div>
                    <p><b>Local:</b> Victory Road (Rota da Vitória).<br>
                    <b>Acesso:</b> Encontrado na câmara norte da caverna empurrando as pedras sobre os interruptores.<br>
                    <b>Dica:</b> Monstro do tipo Água com alta defesa neutraliza seu fogo.</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Mewtwo (O Clone Supremo)</h3>
                        <span class="tag-pill">Lv 70</span>
                    </div>
                    <p><b>Local:</b> Cerulean Cave (Caverna de Cerulean).<br>
                    <b>Acesso:</b> Liberada após derrotar o Campeão da Liga Pokémon.<br>
                    <b>Dica:</b> Mewtwo possui Psychic, Recover e Swift em nível 70. Recomenda-se usar a <b>Master Ball</b> recebida na Silph Co.!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Mew (O Ancestral Genético)</h3>
                        <span class="tag-pill">Lv 30</span>
                    </div>
                    <p><b>Local:</b> Faraway Island (Ilha Distante).<br>
                    <b>Acesso:</b> Embarque no porto marítimo com o Old Sea Map.<br>
                    <b>Dica:</b> Brinque de esconde-esconde no bosque de árvores e encoste nele para iniciar a batalha de captura!</p>
                </div>

                <div class="wiki-card">
                    <div class="wiki-card-header">
                        <h3>Lugia & Ho-Oh</h3>
                        <span class="tag-pill">Lv 70</span>
                    </div>
                    <p><b>Local:</b> Navel Rock.<br>
                    <b>Acesso:</b> Através do porto com o Mystic Ticket.<br>
                    <b>Suba o topo:</b> Encontre <b>Ho-Oh</b> com Sacred Fire.<br>
                    <b>Desça o abismo:</b> Encontre <b>Lugia</b> com Aeroblast.</p>
                </div>
            </div>
        </section>

    </main>

    <!-- Scripts e Dados Embutidos -->
    <script>
        const pokedexData = {pokedex_json};
        const routesData = {routes_json};

        function showPane(paneId) {{
            document.querySelectorAll('.section-pane').forEach(p => p.classList.remove('active'));
            document.querySelectorAll('.nav-item').forEach(btn => btn.classList.remove('active'));

            const targetPane = document.getElementById(`pane-${{paneId}}`);
            if (targetPane) targetPane.classList.add('active');

            if (event && event.currentTarget) {{
                event.currentTarget.classList.add('active');
            }}

            // Fechar sidebar mobile ao navegar
            const sidebar = document.getElementById('sidebar');
            if (sidebar.classList.contains('open')) {{
                sidebar.classList.remove('open');
            }}
            window.scrollTo(0, 0);
        }}

        function toggleSidebar() {{
            document.getElementById('sidebar').classList.toggle('open');
        }}

        // Renderizar Pokédex
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
                <div class="mon-card">
                    <div class="mon-card-header">
                        <span class="mon-number">#${{mon.num.toString().padStart(3, '0')}}</span>
                        <div class="mon-types">
                            ${{mon.type.map(t => `<span class="type-badge type-${{t}}">${{t}}</span>`).join('')}}
                        </div>
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

        // Renderizar Rotas
        function renderRoutes(filterQuery = '') {{
            const container = document.getElementById('routesContainer');
            const query = filterQuery.toLowerCase();

            const filtered = routesData.filter(r => r.name.toLowerCase().includes(query));

            container.innerHTML = filtered.map(r => `
                <div class="encounter-card">
                    <h3>📍 ${{r.name}}</h3>
                    
                    ${{r.day.length ? `
                        <div style="margin-bottom: 0.5rem;">
                            <strong style="font-size:0.8rem; color:#f59e0b;">☀️ Dia:</strong><br>
                            ${{r.day.map(m => `<span class="mon-tag day">${{m}}</span>`).join('')}}
                        </div>
                    ` : ''}}

                    ${{r.night.length ? `
                        <div style="margin-bottom: 0.5rem;">
                            <strong style="font-size:0.8rem; color:#818cf8;">🌙 Noite:</strong><br>
                            ${{r.night.map(m => `<span class="mon-tag night">${{m}}</span>`).join('')}}
                        </div>
                    ` : ''}}

                    ${{r.water.length ? `
                        <div style="margin-bottom: 0.5rem;">
                            <strong style="font-size:0.8rem; color:#60a5fa;">🌊 Água / Pesca:</strong><br>
                            ${{r.water.map(m => `<span class="mon-tag water">${{m}}</span>`).join('')}}
                        </div>
                    ` : ''}}

                    ${{r.hidden.length ? `
                        <div>
                            <strong style="font-size:0.8rem; color:#4ade80;">🔍 DexNav (Visível):</strong><br>
                            ${{r.hidden.map(m => `<span class="mon-tag hidden">${{m}}</span>`).join('')}}
                        </div>
                    ` : ''}}
                </div>
            `).join('');
        }}

        function filterRoutes(val) {{
            renderRoutes(val);
        }}

        // Busca Global
        function handleGlobalSearch(query) {{
            if (!query.trim()) return;
            const q = query.toLowerCase();

            // Se for número ou nome de mon, vai pra pokedex
            const monMatch = pokedexData.some(m => m.name.toLowerCase().includes(q) || m.num.toString() === q);
            if (monMatch) {{
                showPane('pokedex');
                const pInput = document.getElementById('pokedexFilterInput');
                if (pInput) {{
                    pInput.value = query;
                    renderPokedex();
                }}
                return;
            }}

            // Se for rota
            const routeMatch = routesData.some(r => r.name.toLowerCase().includes(q));
            if (routeMatch) {{
                showPane('encounters');
                const rInput = document.getElementById('routeFilterInput');
                if (rInput) {{
                    rInput.value = query;
                    renderRoutes(query);
                }}
                return;
            }}

            // Se for líder
            if (['brock', 'misty', 'surge', 'erika', 'sabrina', 'koga', 'blaine', 'giovanni', 'falkner', 'bugsy', 'whitney', 'morty', 'chuck', 'jasmine', 'pryce', 'clair', 'red'].some(l => q.includes(l))) {{
                showPane('gyms');
                return;
            }}

            // Se for lendário
            if (['mewtwo', 'mew', 'articuno', 'zapdos', 'moltres', 'lugia', 'ho-oh'].some(l => q.includes(l))) {{
                showPane('legendaries');
                return;
            }}
        }}

        window.addEventListener('DOMContentLoaded', () => {{
            renderPokedex();
            renderRoutes();
        }});
    </script>
</body>
</html>
"""

output_path = "Wiki_Pokemon_Kanto_Johto.html"
with open(output_path, "w", encoding="utf-8") as out:
    out.write(html_template)

# Atualizar também Detonado_Interativo_Pokemon_Kanto_Johto.html
with open("Detonado_Interativo_Pokemon_Kanto_Johto.html", "w", encoding="utf-8") as out:
    out.write(html_template)

print(f"Sucesso! Gerado arquivo '{output_path}' com sucesso ({len(html_template)} bytes)!")
