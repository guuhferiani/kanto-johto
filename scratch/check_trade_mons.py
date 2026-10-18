# -*- coding: utf-8 -*-
with open('src/data/pokemon/evolution.h', 'r', encoding='utf-8', errors='ignore') as f:
    lines = f.readlines()

pokemon_check = [
    'KADABRA', 'MACHOKE', 'GRAVELER', 'HAUNTER',
    'ONIX', 'SCYTHER', 'SEADRA', 'POLIWHIRL',
    'SLOWPOKE', 'PORYGON', 'PORYGON2', 'CLAMPERL'
]

cur_block = []
cur_species = None
for line in lines:
    for p in pokemon_check:
        if f'[SPECIES_{p}]' in line:
            cur_species = p
            cur_block = [line.strip()]
            break
    else:
        if cur_species:
            cur_block.append(line.strip())
            if '},' in line and (line.strip().endswith('}},') or line.strip().endswith('},')):
                print(' '.join(cur_block))
                cur_species = None
                cur_block = []
