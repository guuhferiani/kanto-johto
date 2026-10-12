import urllib.request
import os
import sys
from PIL import Image
from concurrent.futures import ThreadPoolExecutor

with open('include/constants/species.h') as f:
    lines = f.readlines()

gen2_species = []
for line in lines:
    line = line.strip()
    if line.startswith('#define SPECIES_') and not line.startswith('#define SPECIES_NONE'):
        parts = line.split()
        if len(parts) >= 3 and parts[2].isdigit():
            idx = int(parts[2])
            sp = parts[1].replace('SPECIES_', '').lower()
            if 152 <= idx <= 251 and sp != 'unown':
                gen2_species.append(sp)

print(f'Starting update for {len(gen2_species)} Johto Pokémon...')

BASE_URL = 'https://raw.githubusercontent.com/rh-hideout/pokeemerald-expansion/master/graphics/pokemon/'

def process_species(sp):
    folder = os.path.join('graphics', 'pokemon', sp)
    os.makedirs(folder, exist_ok=True)
    files = ['anim_front.png', 'back.png', 'normal.pal', 'shiny.pal']
    for f in files:
        url = BASE_URL + sp + '/' + f
        target = os.path.join(folder, f)
        resp = urllib.request.urlopen(url)
        content = resp.read()
        if f.endswith('.pal'):
            text = content.decode('utf-8', errors='ignore').replace('\r\n', '\n').replace('\n', '\r\n')
            with open(target, 'wb') as out:
                out.write(text.encode('utf-8'))
        else:
            with open(target, 'wb') as out:
                out.write(content)
                
    anim = Image.open(os.path.join(folder, 'anim_front.png'))
    front = anim.crop((0, 0, 64, 64))
    front.save(os.path.join(folder, 'front.png'))
    return sp

with ThreadPoolExecutor(max_workers=10) as ex:
    completed = 0
    for sp in ex.map(process_species, gen2_species):
        completed += 1
        if completed % 20 == 0 or completed == len(gen2_species):
            print(f'Progress: {completed}/{len(gen2_species)} done ({sp})')

print(f'Successfully updated all {len(gen2_species)} Johto Pokémon!')
