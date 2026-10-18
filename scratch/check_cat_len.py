import re

with open('src/data/pokemon/pokedex_entries.h', 'r', encoding='utf-8') as f:
    text = f.read()

cats = re.findall(r'\.categoryName\s*=\s*_\("([^"]+)"\)', text)
max_len = 0
for c in cats[:151]:
    b = len(c.encode('utf-8'))
    if b > max_len:
        max_len = b
print(f"Max byte length in Kanto categories: {max_len}")
for c in cats[:151]:
    # In C charmap, accented chars map to single bytes 0xXX in the charmap!
    # But before charmap processing, the C string literal is parsed by the C compiler (agbcc)!
    # In agbcc, u8 categoryName[12] is initialized with a string literal!
    # In UTF-8 source code, 'ã' is TWO bytes in the C string literal!
    # So if the literal has more than 11 characters/bytes in C, agbcc throws:
    # warning: excess elements in array initializer!
    print(c, len(c), len(c.encode('utf-8'))) if len(c) > 10 else None
