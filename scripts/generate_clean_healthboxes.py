import os
from PIL import Image

# Paleta Sword / Shield (Sw/Sh Clean White Style) - 16 cores
PALETTE = [
    0, 0, 0,        # 0: Transparent
    40, 40, 40,     # 1: Dark Charcoal Font
    252, 252, 252,  # 2: Pure Clean White Body
    236, 240, 244,  # 3: Subtle Cool Highlight / Shadow
    184, 190, 196,  # 4: Soft Grey Accent
    120, 126, 134,  # 5: Mid-Dark Border
    56, 60, 66,     # 6: Crisp Outer Outline
    24, 26, 28,     # 7: Deep Accent
    144, 150, 158,  # 8: Divider
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
    # Assembled: 128 x 32 (Sw/Sh clean parallelogram, straight left, slanted right)
    im = Image.new('P', (128, 32), 0)
    im.putpalette(PALETTE)
    px = im.load()

    for y in range(3, 27):
        x_start = 6
        # Diagonal slant on right edge from (112, 3) down-left to (100, 26)
        x_end = int(112 - (y - 3) * 0.5)

        for x in range(x_start, x_end + 1):
            is_outer = (x == x_start or x == x_end or y == 3 or y == 26)
            is_inner = (y == 4 or y == 25)
            if is_outer:
                px[x, y] = 5
            elif is_inner:
                px[x, y] = 3
            else:
                px[x, y] = 2

    out = Image.new('P', (64, 64), 0)
    out.putpalette(PALETTE)
    out.paste(im.crop((0, 0, 64, 32)), (0, 0))
    out.paste(im.crop((64, 0, 128, 32)), (0, 32))
    return out


def create_player_singles_healthbox():
    # Assembled: 128 x 64 (Sw/Sh clean parallelogram, slanted left, room for EXP at y=34..36)
    im = Image.new('P', (128, 64), 0)
    im.putpalette(PALETTE)
    px = im.load()

    for y in range(3, 39):
        # Diagonal slant on left edge from (22, 3) down-left to (5, 38)
        x_start = int(22 - (y - 3) * 0.5)
        x_end = 116

        for x in range(x_start, x_end + 1):
            is_outer = (x == x_start or x == x_end or y == 3 or y == 38)
            is_inner = (y == 4 or y == 37)
            if is_outer:
                px[x, y] = 5
            elif is_inner:
                px[x, y] = 3
            else:
                px[x, y] = 2

    out = Image.new('P', (64, 128), 0)
    out.putpalette(PALETTE)
    out.paste(im.crop((0, 0, 64, 64)), (0, 0))
    out.paste(im.crop((64, 0, 128, 64)), (0, 64))
    return out


def create_player_doubles_healthbox():
    # Assembled: 128 x 32 (Sw/Sh compact player box for doubles)
    im = Image.new('P', (128, 32), 0)
    im.putpalette(PALETTE)
    px = im.load()

    for y in range(3, 27):
        x_start = int(20 - (y - 3) * 0.5)
        x_end = 116

        for x in range(x_start, x_end + 1):
            is_outer = (x == x_start or x == x_end or y == 3 or y == 26)
            is_inner = (y == 4 or y == 25)
            if is_outer:
                px[x, y] = 5
            elif is_inner:
                px[x, y] = 3
            else:
                px[x, y] = 2

    out = Image.new('P', (64, 64), 0)
    out.putpalette(PALETTE)
    out.paste(im.crop((0, 0, 64, 32)), (0, 0))
    out.paste(im.crop((64, 0, 128, 32)), (0, 32))
    return out


singles_player = create_player_singles_healthbox()
singles_opponent = create_opponent_healthbox(is_doubles=False)
doubles_player = create_player_doubles_healthbox()
doubles_opponent = create_opponent_healthbox(is_doubles=True)

singles_player.save('graphics/battle_interface/healthbox_singles_player.png')
singles_opponent.save('graphics/battle_interface/healthbox_singles_opponent.png')
doubles_player.save('graphics/battle_interface/healthbox_doubles_player.png')
doubles_opponent.save('graphics/battle_interface/healthbox_doubles_opponent.png')

bsb = Image.open('graphics/battle_interface/ball_status_bar.png')
bsb_new = Image.new('P', bsb.size)
bsb_new.putpalette(PALETTE)
bsb_new.paste(bsb, (0, 0))
bsb_new.save('graphics/battle_interface/ball_status_bar.png')

print('All 4 healthbox images and ball_status_bar updated with Sword/Shield (Sw/Sh) style!')
