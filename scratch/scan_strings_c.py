import re

with open('src/strings.c', 'r', encoding='utf-8', errors='ignore') as f:
    lines = f.readlines()

eng_words = {'the', 'to', 'and', 'of', 'in', 'is', 'it', 'you', 'that', 'for', 'on', 'are', 'with', 'be', 'this', 'have', 'from', 'or', 'what', 'there', 'use', 'how', 'will', 'up', 'about', 'out', 'them', 'these', 'would', 'make', 'into', 'time', 'more', 'could', 'who', 'turn', 'item', 'bag', 'store', 'box', 'cancel', 'choose', 'battle', 'hall', 'fame', 'mart', 'shop', 'save'}

results = []
for i, line in enumerate(lines):
    m = re.search(r'const\s+u8\s+([A-Za-z0-9_]+)\[\]\s*=\s*_\("([^"]+)"\);', line)
    if m:
        var_name, text = m.group(1), m.group(2)
        words = set(re.findall(r'[a-zA-Z]+', text.lower()))
        matched = words & eng_words
        pt_words = {'de', 'da', 'do', 'em', 'um', 'uma', 'com', 'por', 'para', 'nao', 'voce', 'foi', 'que', 'se', 'sua', 'seu', 'mais', 'como', 'ou', 'ter'}
        if matched - pt_words:
            results.append((i+1, var_name, text))

print(f"Total found: {len(results)}")
for line_no, var_name, text in results[:80]:
    clean_txt = text.replace('\n', '\\n').replace('\\p', '')
    print(f"{line_no:4d} | {var_name}: {clean_txt}")
