import re

with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8') as f:
    text = f.read()

# Pattern for static const u8 s...Description[] = _("..."); or with multi-line string literals
# In C, multi-line string literals are often:
# static const u8 sPoundDescription[] = _(
#     "Pounds the foe with\n"
#     "forelegs or tail.");

# Let's find all variable names and their bodies
pattern = re.compile(r'static const u8 (s[A-Za-z0-9_]+)\[\] = _\((.*?)\);', re.DOTALL)
matches = pattern.findall(text)
print(f"Total description variables: {len(matches)}")

two_line_vars = [m for m in matches if not m[0].startswith('sMoveFourLineDescription_')]
four_line_vars = [m for m in matches if m[0].startswith('sMoveFourLineDescription_')]

print(f"Two-line variables: {len(two_line_vars)}")
print(f"Four-line variables: {len(four_line_vars)}")
print("First 5 two-line:", [m[0] for m in two_line_vars[:5]])
print("First 5 four-line:", [m[0] for m in four_line_vars[:5]])
