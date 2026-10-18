with open('data/text/match_call.inc', 'r', encoding='utf-8', errors='ignore') as f:
    text = f.read()

import re
matches = re.findall(r'([A-Za-z0-9_]+)::\s*\n((?:\t\.string\s+"[^"]*"\n)+)', text)
names = {}
for m in matches:
    name = m[0]
    names[name] = m[1].strip()

print(f"Total entries: {len(names)}")
for i, k in enumerate(names.keys()):
    print(f"{i+1}: {k}")
