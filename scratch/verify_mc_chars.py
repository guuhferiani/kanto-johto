import re

with open('charmap.txt', 'r', encoding='utf-8') as f:
    cm_text = f.read()

# Build set of all characters defined in charmap.txt
valid_chars = set()
for line in cm_text.splitlines():
    line = line.strip()
    if not line or line.startswith('@'):
        continue
    # Format is usually 'char' = 0xXX or similar
    # or character directly
    for c in line:
        valid_chars.add(c)

with open('scratch/translate_match_call.py', 'r', encoding='utf-8') as f:
    code = f.read()

strings = re.findall(r'"""(.*?)"""', code, re.DOTALL)
bad = set()
for s in strings:
    for c in s:
        if c not in valid_chars and c not in '\t\n\r ':
            bad.add((hex(ord(c)), c))

print('Bad chars in strings:', bad)
