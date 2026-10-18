# -*- coding: utf-8 -*-
with open('src/battle_message.c', 'r', encoding='utf-8', errors='ignore') as f:
    lines = f.readlines()

targets = [
    'STRINGID_PKMNLEARNEDMOVE',
    'STRINGID_TRYTOLEARNMOVE1',
    'STRINGID_TRYTOLEARNMOVE2',
    'STRINGID_TRYTOLEARNMOVE3',
    'STRINGID_STOPLEARNINGMOVE',
    'STRINGID_DIDNOTLEARNMOVE',
    'STRINGID_123POOF',
    'STRINGID_PKMNFORGOTMOVE',
    'STRINGID_ANDELLIPSIS',
    'STRINGID_HMMOVESCANTBEFORGOTTEN'
]

var_names = {}
for i, line in enumerate(lines):
    for t in targets:
        if f'[{t} - BATTLESTRINGS_TABLE_START]' in line:
            var_names[t] = line.strip().split('=')[-1].strip().rstrip(',')

print("Variables mapped in table:")
for k, v in var_names.items():
    print(f"{k} => {v}")

print("\nSearching definitions of these variables:")
for i, line in enumerate(lines):
    for k, v in var_names.items():
        if f'const u8 {v}[]' in line:
            print(f"Line {i+1} | {v}: {line.strip()[:80]}")
