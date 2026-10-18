import os, re

english_patterns = [
    re.compile(r'\.string\s+"[^"]*\b(is|are|the|you|your|have|with|this|that|from|they|will|about|would|there|their|which)\b', re.IGNORECASE),
    re.compile(r'_\("[^"]*\b(is|are|the|you|your|have|with|this|that|from|they|will|about|would|there|their|which)\b', re.IGNORECASE)
]

untranslated = {}
for root, dirs, files in os.walk('data/maps'):
    for f in files:
        if f.endswith('.inc'):
            p = os.path.join(root, f)
            with open(p, 'r', encoding='utf-8', errors='ignore') as fp:
                lines = fp.readlines()
            for idx, line in enumerate(lines):
                s = line.strip()
                if s.startswith('@') or s.startswith('//'):
                    continue
                for pat in english_patterns:
                    if pat.search(s):
                        untranslated.setdefault(p, []).append((idx+1, s))
                        break

print(f"Total files with potential English: {len(untranslated)}")
for k in sorted(untranslated.keys(), key=lambda x: len(untranslated[x]), reverse=True)[:25]:
    print(f"{k}: {len(untranslated[k])} lines")
