with open('scratch/translate_match_call.py', 'r', encoding='utf-8') as f:
    content = f.read()

# Notice that in translate_match_call.py, string templates were defined like:
# "Label": """\t.string "..."\n\t.string "..."$ """
# If we change each : """ to : r"""
# and then in the replacement logic, replace literal '\t' with '\t' (tab character),
# then:
# \n inside the string stays as '\' and 'n'
# \p stays as '\' and 'p'
# \l stays as '\' and 'l'
# \t becomes a real tab character!

import re

# Replace : """ with : r"""
fixed = re.sub(r':\s*"""', ': r"""', content)

# And in the replacement section:
# replacement = replacement.replace('\\t', '\t')
old_apply = """count = 0
for label, replacement in translations.items():
    # Regex to find label:: and its following .string lines
    pattern = rf'({re.escape(label)}::?\\s*\\n)((?:\\t\\.string\\s+"[^"]*"\\n)+)'
    match = re.search(pattern, content)
    if match:
        content = content[:match.start(2)] + replacement + "\\n" + content[match.end(2):]
        count += 1
    else:
        print(f"WARN: Label not found: {label}")"""

new_apply = """count = 0
for label, replacement in translations.items():
    # Convert literal \\t to real tab
    replacement = replacement.replace('\\\\t', '\\t')
    # Regex to find label:: and its following .string lines
    pattern = rf'({re.escape(label)}::?\\s*\\n)((?:\\t\\.string\\s+"[^"]*"\\n)+)'
    match = re.search(pattern, content)
    if match:
        content = content[:match.start(2)] + replacement + "\\n" + content[match.end(2):]
        count += 1
    else:
        print(f"WARN: Label not found: {label}")"""

if old_apply in fixed:
    fixed = fixed.replace(old_apply, new_apply)
    print("Replaced apply logic successfully!")
else:
    print("WARNING: old_apply pattern not found!")

with open('scratch/translate_match_call.py', 'w', encoding='utf-8', newline='\n') as f:
    f.write(fixed)

print("Updated scratch/translate_match_call.py successfully!")
