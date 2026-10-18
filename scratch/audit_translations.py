import os, glob, re

def check_file(path, sample_words):
    if not os.path.exists(path):
        return f"File {path} does not exist"
    with open(path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    eng_matches = 0
    for w in sample_words:
        if re.search(r'\b' + re.escape(w) + r'\b', content, re.IGNORECASE):
            eng_matches += 1
    return len(content), eng_matches

results = {}

# 1. Habilidades (Abilities)
if os.path.exists('src/data/text/abilities.h'):
    with open('src/data/text/abilities.h', 'r', encoding='utf-8', errors='ignore') as f:
        ab = f.read()
    results['abilities'] = ('src/data/text/abilities.h', 'Portuguese' if 'Aumenta' in ab or 'Previne' in ab else 'English')

# 2. Descrições de Golpes (Move descriptions)
if os.path.exists('src/data/text/move_descriptions.h'):
    with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8', errors='ignore') as f:
        md = f.read()
    results['move_descriptions'] = ('src/data/text/move_descriptions.h', 'Portuguese' if 'Aumenta' in md or 'Causa dano' in md or 'ataque' in md else 'English')

# 3. Nomes de Golpes (Move names) - usually kept in English in competitive/custom ROMs or translated?
if os.path.exists('src/data/text/move_names.h'):
    with open('src/data/text/move_names.h', 'r', encoding='utf-8', errors='ignore') as f:
        mn = f.read()
    results['move_names'] = ('src/data/text/move_names.h', 'English' if 'Pound' in mn and 'Thunderbolt' in mn else 'Portuguese')

# 4. Itens (Items)
if os.path.exists('src/data/items.h'):
    with open('src/data/items.h', 'r', encoding='utf-8', errors='ignore') as f:
        it = f.read()
    results['items_desc'] = ('src/data/items.h', 'Portuguese' if 'Restaura' in it or 'capturar' in it else 'English')

# 5. Pokédex Entries
if os.path.exists('src/data/pokemon/pokedex_entries.h'):
    with open('src/data/pokemon/pokedex_entries.h', 'r', encoding='utf-8', errors='ignore') as f:
        pke = f.read()
    results['pokedex_entries'] = ('src/data/pokemon/pokedex_entries.h', 'Portuguese' if 'Pokémon' in pke and ('quando' in pke or 'sua' in pke) else 'English')
elif os.path.exists('src/data/pokedex_entries.h'):
    with open('src/data/pokedex_entries.h', 'r', encoding='utf-8', errors='ignore') as f:
        pke = f.read()
    results['pokedex_entries'] = ('src/data/pokedex_entries.h', 'Portuguese' if 'Pokémon' in pke and ('quando' in pke or 'sua' in pke) else 'English')

# 6. Opções (Option Menu)
if os.path.exists('src/option_menu.c'):
    with open('src/option_menu.c', 'r', encoding='utf-8', errors='ignore') as f:
        op = f.read()
    results['option_menu'] = ('src/option_menu.c', 'Portuguese' if 'VELOCIDADE' in op or 'TEXTO' in op or 'Rápido' in op else 'English')

# 7. Start Menu & Main Strings
with open('src/strings.c', 'r', encoding='utf-8', errors='ignore') as f:
    st = f.read()

# 8. Trainer Card
if os.path.exists('src/trainer_card.c'):
    with open('src/trainer_card.c', 'r', encoding='utf-8', errors='ignore') as f:
        tc = f.read()
    results['trainer_card'] = ('src/trainer_card.c', 'Portuguese' if 'NOME' in tc or 'DINHEIRO' in tc else 'English')

# 9. Johto Maps
johto_scripts = glob.glob('data/maps/*NewBark*/**/*.inc', recursive=True) + glob.glob('data/maps/*Cherrygrove*/**/*.inc', recursive=True) + glob.glob('data/maps/*Violet*/**/*.inc', recursive=True) + glob.glob('data/maps/*Goldenrod*/**/*.inc', recursive=True) + glob.glob('data/maps/*Ecruteak*/**/*.inc', recursive=True)
johto_status = 'None'
if johto_scripts:
    eng_count = 0
    pt_count = 0
    for p in johto_scripts:
        with open(p, 'r', encoding='utf-8', errors='ignore') as f:
            txt = f.read()
        if 'Hello' in txt or 'Trainer' in txt or 'Welcome' in txt:
            eng_count += 1
        if 'Olá' in txt or 'Treinador' in txt or 'Bem-vindo' in txt:
            pt_count += 1
    johto_status = f"{len(johto_scripts)} files found (PT: {pt_count}, EN: {eng_count})"

for k, v in results.items():
    print(f"{k}: {v}")
print(f"Johto maps: {johto_status}")
