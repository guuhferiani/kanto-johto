import os, re

files = [
    'src/party_menu.c',
    'src/item_menu.c',
    'src/trainer_card.c',
    'src/pokemon_summary_screen.c',
    'src/option_menu.c',
    'src/pokedex.c'
]

for fp in files:
    if not os.path.exists(fp):
        continue
    with open(fp, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()
    print(f"=== {fp} ===")
    for i, l in enumerate(lines):
        if '_("' in l:
            # show line
            safe = l.strip().encode('ascii', 'replace').decode('ascii')
            print(f"  {i+1}: {safe}")
