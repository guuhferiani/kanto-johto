import re

with open('src/data/pokemon/pokedex_entries.h', 'r', encoding='utf-8') as f:
    text = f.read()

entries = re.findall(r'\[(NATIONAL_DEX_[A-Z0-9_]+)\]\s*=\s*\{\s*\.categoryName\s*=\s*_\("([^"]+)"\)', text)

johto_start = False
kanto_cats = []
johto_cats = []

for dex, cat in entries:
    if dex == 'NATIONAL_DEX_CHIKORITA':
        johto_start = True
    if not johto_start:
        kanto_cats.append((dex, cat))
    else:
        johto_cats.append((dex, cat))

print(f"Kanto total: {len(kanto_cats)}")
print(f"Johto total: {len(johto_cats)}")

# Check how many in Johto are English
johto_en = [c for c in johto_cats if not any(w in c[1].lower() for w in ['ão', 'é', 'í', 'ó', 'á', 'ç', 'dor', 'inho'])]
print(f"Johto English categories count: {len(johto_en)}/{len(johto_cats)}")
print("Sample Johto categories:", johto_cats[:10])
