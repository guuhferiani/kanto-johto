# -*- coding: utf-8 -*-
with open('src/data/pokemon/evolution.h', 'r', encoding='utf-8', errors='ignore') as f:
    text = f.read()

import re
matches = re.findall(r'(\[SPECIES_[A-Z0-9_]+\]\s*=\s*\{[^\}]+\}\},)', text)
for m in matches:
    if 'EVO_TRADE' in m or 'EVO_ITEM' in m or 'ALAKAZAM' in m or 'MACHAMP' in m or 'GENGAR' in m or 'GOLEM' in m or 'STEELIX' in m or 'SCIZOR' in m or 'KINGDRA' in m or 'POLITOED' in m or 'SLOWKING' in m or 'PORYGON2' in m:
        lines = [l.strip() for l in m.strip().split('\n')]
        print(' '.join(lines))
