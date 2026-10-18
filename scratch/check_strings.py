import re

with open('src/strings.c', 'r', encoding='utf-8', errors='ignore') as f:
    lines = f.readlines()

english_words = ['the', 'you', 'your', 'with', 'from', 'have', 'this', 'that', 'they', 'will', 'are', 'was', 'were']
pat = re.compile(r'\b(' + '|'.join(english_words) + r')\b', re.IGNORECASE)

untranslated = []
for idx, line in enumerate(lines):
    line_s = line.strip()
    if line_s.startswith('//') or line_s.startswith('/*') or line_s.startswith('*'):
        continue
    if '_(' in line_s:
        m = re.search(r'_\("([^"]+)"\)', line_s)
        if m:
            text = m.group(1)
            if pat.search(text):
                untranslated.append((idx+1, line_s))

print(f"Total English strings in src/strings.c: {len(untranslated)}")
for u in untranslated[:30]:
    print(f"L{u[0]}: {u[1]}")
