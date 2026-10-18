import os, re
from scan_translation import english_patterns

targets = ['data/scripts', 'src/strings.c', 'src/data/text']

for t in targets:
    if os.path.isfile(t):
        files = [t]
    else:
        files = [os.path.join(t, f) for f in os.listdir(t) if f.endswith('.inc') or f.endswith('.h') or f.endswith('.c')]
    
    for p in files:
        with open(p, 'r', encoding='utf-8', errors='ignore') as fp:
            lines = fp.readlines()
        matches = []
        for idx, line in enumerate(lines):
            s = line.strip()
            if s.startswith('@') or s.startswith('//') or s.startswith('/*') or s.startswith('*'):
                continue
            for pat in english_patterns:
                if pat.search(s):
                    matches.append((idx+1, s))
                    break
        if matches:
            print(f"{p}: {len(matches)} matches")
            for m in matches[:5]:
                print(f"   L{m[0]}: {m[1]}")
