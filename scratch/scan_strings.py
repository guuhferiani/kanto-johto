with open('src/strings.c', 'r', encoding='utf-8') as f:
    lines = f.readlines()

eng_words = [
    'Cancel', 'Select', 'Switch', 'Check', 'Money', 'Time', 'Name:', 'Total', 
    'Items', 'Close', 'Toss', 'Give', 'Soft', 'Hard', 'Spicy', 'Dry', 
    'Sweet', 'Bitter', 'Sour', 'Hall of Fame', 'Link battle', 'Records',
    'Follower', 'None', 'Partner', 'Any', 'Slow', 'Mid', 'Fast', 'Shift', 'Set'
]

for i, line in enumerate(lines):
    if ('const u8 gText_' in line or 'gBerry' in line) and '_("' in line:
        for eng in eng_words:
            if eng in line:
                try:
                    print(f"{i+1}: {line.strip()}")
                except:
                    print(f"{i+1}: {line.strip().encode('ascii', 'replace').decode('ascii')}")
                break

