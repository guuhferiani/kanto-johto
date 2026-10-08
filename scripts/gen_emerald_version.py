from PIL import Image, ImageDraw, ImageFont

# 128x32 canvas for the banner
banner = Image.new('RGBA', (128, 32), (0, 0, 0, 0))
draw = ImageDraw.Draw(banner)

text = "KANTO & JOHTO"
font = ImageFont.truetype('C:/Windows/Fonts/arialbd.ttf', 13)

bbox = draw.textbbox((0, 0), text, font=font)
tw = bbox[2] - bbox[0]
th = bbox[3] - bbox[1]
x = (128 - tw) // 2
y = (32 - th) // 2 - 1

# Draw 1px border all around
for dx in [-1, 0, 1]:
    for dy in [-1, 0, 1]:
        if dx != 0 or dy != 0:
            draw.text((x + dx, y + dy), text, font=font, fill=(0, 0, 0, 255))

# Draw white text
draw.text((x, y), text, font=font, fill=(255, 255, 255, 255))

# Convert to indexed 64x64 image
# Split into left (0..64) and right (64..128)
left = banner.crop((0, 0, 64, 32))
right = banner.crop((64, 0, 64, 32)) # wait! crop args are (left, top, right, bottom)!
# right half is from X=64 to X=128:
right = banner.crop((64, 0, 128, 32))

final_img = Image.new('P', (64, 64), 0)
# Setup palette:
# Index 0: magenta (255, 74, 238)
# Index 1: black (0, 0, 0)
# Index 2: white (255, 255, 255)
pal = [255, 74, 238,  0, 0, 0,  255, 255, 255]
while len(pal) < 256 * 3:
    pal.extend([0, 0, 0])
final_img.putpalette(pal)

# Paste pixels
for py in range(32):
    for px in range(64):
        # Left half -> top (0..32)
        r, g, b, a = left.getpixel((px, py))
        if a > 128:
            if r > 128:
                final_img.putpixel((px, py), 2)
            else:
                final_img.putpixel((px, py), 1)
        else:
            final_img.putpixel((px, py), 0)

        # Right half -> bottom (32..64)
        r, g, b, a = right.getpixel((px, py))
        if a > 128:
            if r > 128:
                final_img.putpixel((px, py + 32), 2)
            else:
                final_img.putpixel((px, py + 32), 1)
        else:
            final_img.putpixel((px, py + 32), 0)

final_img.save('graphics/title_screen/emerald_version.png')
print("Successfully generated graphics/title_screen/emerald_version.png!")
