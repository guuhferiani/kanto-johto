import re

with open('src/data/pokemon/pokedex_text.h', 'r', encoding='utf-8') as f:
    text = f.read()

pattern = re.compile(r'const u8 (g[A-Za-z0-9_]+PokedexText)\[\] = _\((.*?)\);', re.DOTALL)
entries = pattern.findall(text)
print(f"Total entries in pokedex_text.h: {len(entries)}")

pt_entries = []
en_entries = []

for name, body in entries:
    if name == 'gDummyPokedexText':
        continue
    # check if Portuguese words present
    if any(w in body.lower() for w in [' de ', ' em ', ' para ', ' com ', ' um ', ' uma ', ' seu ', ' sua ', ' não ', ' que ', ' sob ', ' pelas ']):
        pt_entries.append((name, body[:60].replace('\n', ' ')))
    else:
        en_entries.append((name, body[:60].replace('\n', ' ')))

print(f"Portuguese entries count: {len(pt_entries)}")
print(f"English entries count: {len(en_entries)}")

if pt_entries:
    print(f"Sample PT ({len(pt_entries)}):", pt_entries[:5])
if en_entries:
    print(f"Sample EN ({len(en_entries)}):", en_entries[:10])

# Also check pokedex_entries.h (category names, e.g. "SEED POKéMON" -> "POKéMON SEMENTE")
with open('src/data/pokemon/pokedex_entries.h', 'r', encoding='utf-8') as f:
    entries_h = f.read()

categories = re.findall(r'\.categoryName = _\("([^"]+)"\)', entries_h)
print(f"Categories found in pokedex_entries.h: {len(categories)}")
sample_cat = categories[:10]
print("Sample categories:", sample_cat)
