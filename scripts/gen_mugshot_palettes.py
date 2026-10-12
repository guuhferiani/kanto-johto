"""Generate JASC palettes for the Gym Leader mugshot banners.

Layout matches the existing Elite Four palettes (e.g. bruno_bg.pal):
  0     : red (unused bg colour)
  1-4   : greys
  5-9   : opponent banner gradient (5 steps, +16 per channel)
  10-15 : overwritten at runtime by the player's palette
"""
import os

OUT_DIR = os.path.join("graphics", "battle_transitions")

# Base (darkest) colour of each leader's banner, themed by gym type.
LEADERS = {
    "brock":    (139, 90, 43),   # Rock   - brown
    "misty":    (0, 115, 197),   # Water  - ocean blue
    "surge":    (213, 164, 0),   # Electric - gold
    "erika":    (49, 139, 49),   # Grass  - leaf green
    "koga":     (106, 32, 148),  # Poison - purple
    "sabrina":  (205, 57, 115),  # Psychic - rose
    "blaine":   (197, 41, 0),    # Fire   - flame red/orange
    "giovanni": (74, 74, 82),    # Ground / Team Rocket - dark steel
}

HEADER = [(172, 49, 49), (115, 115, 115), (148, 148, 148), (180, 180, 180), (213, 213, 213)]


def gradient(base):
    return [tuple(min(255, c + 16 * i) for c in base) for i in range(5)]


for name, base in LEADERS.items():
    colours = HEADER + gradient(base) + [(0, 0, 0)] * 6
    lines = ["JASC-PAL", "0100", "16"] + [f"{r} {g} {b}" for r, g, b in colours]
    path = os.path.join(OUT_DIR, f"{name}_bg.pal")
    with open(path, "w", newline="\r\n") as f:
        f.write("\n".join(lines) + "\n")
    print("wrote", path)
