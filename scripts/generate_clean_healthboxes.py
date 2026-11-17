import os
from PIL import Image

# 1. Definir paleta calibrada moderna Gen 5 (BW Style)
# 16 cores
PALETTE = [
    0, 0, 0,        # 0: Transparent
    40, 40, 40,     # 1: Dark Charcoal Font
    252, 252, 252,  # 2: Pure Clean White Body
    224, 228, 232,  # 3: Light Cool Grey Body / Highlight
    184, 190, 196,  # 4: Mid Grey Border
    108, 114, 120,  # 5: Dark Frame Border
    56, 60, 66,     # 6: Deep Shadow / Outline
    24, 26, 28,     # 7: Outer Accent
    144, 150, 158,  # 8: Divider / HP bar groove
    248, 212, 0,    # 9: Yellow (HP tag)
    248, 116, 132,  # 10: Pink/Red (Female)
    64, 144, 248,   # 11: Blue (Male)
    0, 0, 255,      # 12: Ball blue
    0, 220, 0,      # 13: Ball green
    220, 0, 0,      # 14: Ball red
    106, 148, 255   # 15: Ball status
]

while len(PALETTE) < 256 * 3:
    PALETTE.extend([0, 0, 0])

def create_opponent_healthbox(is_doubles=False):
    # Assembled: 128 x 32
    # Opponent box:
    # Left at x=8, top at y=4, right angled from x=96..112, bottom at y=27
    im = Image.new('P', (128, 32), 0)
    im.putpalette(PALETTE)
    px = im.load()

    # Draw BW Opponent Healthbox
    # Shape:
    # Top edge: y=4, x=10..98
    # Angled right edge: slopes from (98, 4) down-right to (114, 20), then down-left to (108, 27)
    # Bottom edge: y=27, x=10..108
    # Left edge: x=8, y=6..25
    
    for y in range(4, 28):
        # Calculate left and right bounds for each y
        # Left edge
        if y == 4 or y == 27:
            x_start = 10
        elif y == 5 or y == 26:
            x_start = 9
        else:
            x_start = 8

        # Right edge (angled 45 degrees)
        if y <= 20:
            x_end = 98 + (y - 4)  # 98 at y=4 -> 114 at y=20
        else:
            x_end = 114 - (y - 20) # 114 at y=20 -> 107 at y=27

        for x in range(x_start, x_end + 1):
            # Borders
            is_border = (x == x_start or x == x_end or y == 4 or y == 27)
            is_inner_border = (x == x_start + 1 or x == x_end - 1 or y == 5 or y == 26)
            
            if is_border:
                px[x, y] = 6 # Deep dark outline
            elif is_inner_border:
                px[x, y] = 5 # Frame border
            else:
                # Interior clean white so engine text, HP bar and status sprites never clash
                px[x, y] = 2 # White

    # Return as 64x64 image (left 64x32 at top, right 64x32 at bottom)
    out = Image.new('P', (64, 64), 0)
    out.putpalette(PALETTE)
    out.paste(im.crop((0, 0, 64, 32)), (0, 0))
    out.paste(im.crop((64, 0, 128, 32)), (0, 32))
    return out

def create_player_singles_healthbox():
    # Assembled: 128 x 64
    # Player box:
    # Left edge angled from (24, 4) down-left to (7, 38)
    # Top edge: y=4, x=24..116
    # Right edge: x=116, y=4..38
    # Bottom edge: y=38, x=7..116 (leaves room for EXP bar at y=34..36)
    im = Image.new('P', (128, 64), 0)
    im.putpalette(PALETTE)
    px = im.load()

    for y in range(4, 39):
        # Angled left edge: from (24, 4) to (7, 38)
        x_start = int(24 - (y - 4) * 0.5)
        x_end = 116

        for x in range(x_start, x_end + 1):
            is_border = (x == x_start or x == x_end or y == 4 or y == 38)
            is_inner_border = (x == x_start + 1 or x == x_end - 1 or y == 5 or y == 37)

            if is_border:
                px[x, y] = 6
            elif is_inner_border:
                px[x, y] = 5
            else:
                # Keep interior clean white where engine draws nickname, HP bar, and HP numbers
                if y <= 32:
                    px[x, y] = 2
                elif y == 33:
                    px[x, y] = 4
                else:
                    px[x, y] = 3

    # Return as 64x128 image (left 64x64 at top, right 64x64 at bottom)
    out = Image.new('P', (64, 128), 0)
    out.putpalette(PALETTE)
    out.paste(im.crop((0, 0, 64, 64)), (0, 0))
    out.paste(im.crop((64, 0, 128, 64)), (0, 64))
    return out

def create_player_doubles_healthbox():
    # Assembled: 128 x 32
    # Compact player box for doubles (no numeric HP)
    # Left edge angled from (24, 4) down-left to (12, 27)
    im = Image.new('P', (128, 32), 0)
    im.putpalette(PALETTE)
    px = im.load()

    for y in range(4, 28):
        x_start = int(24 - (y - 4) * 0.52)
        x_end = 116

        for x in range(x_start, x_end + 1):
            is_border = (x == x_start or x == x_end or y == 4 or y == 27)
            is_inner_border = (x == x_start + 1 or x == x_end - 1 or y == 5 or y == 26)

            if is_border:
                px[x, y] = 6
            elif is_inner_border:
                px[x, y] = 5
            else:
                px[x, y] = 2

    out = Image.new('P', (64, 64), 0)
    out.putpalette(PALETTE)
    out.paste(im.crop((0, 0, 64, 32)), (0, 0))
    out.paste(im.crop((64, 0, 128, 32)), (0, 32))
    return out

# Generate all 4
singles_player = create_player_singles_healthbox()
singles_opponent = create_opponent_healthbox(is_doubles=False)
doubles_player = create_player_doubles_healthbox()
doubles_opponent = create_opponent_healthbox(is_doubles=True)

singles_player.save('graphics/battle_interface/healthbox_singles_player.png')
singles_opponent.save('graphics/battle_interface/healthbox_singles_opponent.png')
doubles_player.save('graphics/battle_interface/healthbox_doubles_player.png')
doubles_opponent.save('graphics/battle_interface/healthbox_doubles_opponent.png')

# Update ball_status_bar.png palette
bsb = Image.open('graphics/battle_interface/ball_status_bar.png')
bsb_new = Image.new('P', bsb.size)
bsb_new.putpalette(PALETTE)
bsb_new.paste(bsb, (0, 0))
bsb_new.save('graphics/battle_interface/ball_status_bar.png')

print('All 4 healthbox images and ball_status_bar updated with Gen 5 Clean style!')

