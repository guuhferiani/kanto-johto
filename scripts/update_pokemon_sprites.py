import urllib.request
import os
import sys
from PIL import Image
from concurrent.futures import ThreadPoolExecutor

with open('include/constants/species.h') as f:
    lines = f.readlines()

gen1_species = []
for line in lines:
    line = line.strip()
    if line.startswith('#define SPECIES_') and not line.startswith('#define SPECIES_NONE'):
        parts = line.split()
        if len(parts) >= 3 and parts[2].isdigit():
            idx = int(parts[2])
            sp = parts[1].replace('SPECIES_', '').lower()
            if 1 <= idx <= 151:
                gen1_species.append(sp)

# Filter out the 47 already updated
ALREADY_UPDATED = {
    'bulbasaur', 'ivysaur', 'venusaur',
    'charmander', 'charmeleon', 'charizard',
    'squirtle', 'wartortle', 'blastoise',
    'pikachu', 'raichu',
    'eevee', 'vaporeon', 'jolteon', 'flareon',
    'gastly', 'haunter', 'gengar',
    'magikarp', 'gyarados',
    'dratini', 'dragonair', 'dragonite',
    'snorlax',
    'mewtwo', 'mew', 'articuno', 'zapdos', 'moltres',
    'pidgey', 'pidgeotto', 'pidgeot',
    'abra', 'kadabra', 'alakazam',
    'machop', 'machoke', 'machamp',
    'geodude', 'graveler', 'golem',
    'lapras', 'arcanine', 'growlithe',
    'scyther', 'pinsir', 'tauros'
}

to_update = [sp for sp in gen1_species if sp not in ALREADY_UPDATED]
print(f'Updating remaining {len(to_update)} Gen 1 species...')

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
    for sp in ex.map(process_species, to_update):
        completed += 1
        if completed % 20 == 0 or completed == len(to_update):
            print(f'Progress: {completed}/{len(to_update)} done ({sp})')

print('All 104 remaining Gen 1 species updated successfully!')
