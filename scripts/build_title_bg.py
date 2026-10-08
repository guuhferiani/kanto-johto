import struct
from PIL import Image, ImageFilter

def build_title_background():
    # 1. Carregar capa
    cover = Image.open('kanto johto cover.jpg')
    # Framing com Lugia e Charizard
    crop = cover.crop((465, 520, 2040, 1570)).copy()

    # Remover wireless logo no canto inferior direito
    rock_source = crop.crop((1150, 920, 1375, 1050))
    crop.paste(rock_source, (1350, 920))

    # Suavizar o céu no topo (X=0..1575, Y=0..220)
    sky_colors = []
    for x in range(1575):
        c = crop.getpixel((x, 240))
        if sum(c) > 650 or sum(c) < 50:
            c = crop.getpixel((x, 260))
        sky_colors.append(c)

    smooth_colors = []
    w_radius = 25
    for x in range(1575):
        r_sum, g_sum, b_sum, count = 0, 0, 0, 0
        for dx in range(-w_radius, w_radius + 1):
            nx = max(0, min(1574, x + dx))
            sc = sky_colors[nx]
            r_sum += sc[0]
            g_sum += sc[1]
            b_sum += sc[2]
            count += 1
        smooth_colors.append((r_sum // count, g_sum // count, b_sum // count))

    for x in range(1575):
        base_c = smooth_colors[x]
        for y in range(220):
            factor = 0.75 + 0.25 * (y / 220.0)
            c = (int(base_c[0] * factor), int(base_c[1] * factor), int(base_c[2] * factor))
            crop.putpixel((x, y), c)

    blur_band = crop.crop((0, 190, 1575, 240)).filter(ImageFilter.GaussianBlur(radius=4))
    crop.paste(blur_band, (0, 190))

    # Redimensionar para 240x160
    resized = crop.resize((240, 160), Image.Resampling.LANCZOS)
    resized.save('tools/scripts/bg_240x160_preview.png')

    # 2. Quantizar para 15 cores
    quant_15 = resized.quantize(colors=15, method=Image.Resampling.LANCZOS, dither=Image.Dither.FLOYDSTEINBERG)
    q_pal = quant_15.getpalette()[:45] # 15 cores x 3 componentes

    # Paleta completa de 16 cores (Cor 0 = preto 0,0,0)
    pal_16 = [(0, 0, 0)]
    for i in range(15):
        pal_16.append((q_pal[i*3], q_pal[i*3+1], q_pal[i*3+2]))

    # Mapear pixels da imagem para [1..15]
    # No caso de pixels que forem pretos ou muito escuros, podem usar 0 ou a cor mais escura
    img_data = list(quant_15.getdata())
    mapped_pixels = [p + 1 for p in img_data]

    # Imagem indexada 240x160
    flat_pal = []
    for c in pal_16:
        flat_pal.extend(c)
    while len(flat_pal) < 256 * 3:
        flat_pal.extend([0, 0, 0])

    img_indexed = Image.new('P', (240, 160))
    img_indexed.putpalette(flat_pal)
    img_indexed.putdata(mapped_pixels)
    img_indexed.save('tools/scripts/bg_indexed_preview.png')

    # 3. Converter para tiles 8x8 e deduplicar
    # Tilemap GBA text mode é 32x32 tiles
    unique_tiles = []
    tile_dict = {} # tuple -> (tile_index, hflip, vflip)

    # Tile 0 vazio/preto
    blank_tile = tuple([0] * 64)
    unique_tiles.append(blank_tile)
    tile_dict[blank_tile] = (0, False, False)

    def get_tile(tx, ty):
        t = []
        for y in range(8):
            for x in range(8):
                t.append(img_indexed.getpixel((tx * 8 + x, ty * 8 + y)))
        return tuple(t)

    def flip_h(t):
        res = []
        for y in range(8):
            row = t[y*8:(y+1)*8]
            res.extend(row[::-1])
        return tuple(res)

    def flip_v(t):
        res = []
        for y in range(7, -1, -1):
            res.extend(t[y*8:(y+1)*8])
        return tuple(res)

    tilemap = [[0 for _ in range(32)] for _ in range(32)]

    for ty in range(20):
        for tx in range(30):
            t = get_tile(tx, ty)
            t_h = flip_h(t)
            t_v = flip_v(t)
            t_hv = flip_h(t_v)

            found = False
            for cand, hf, vf in [(t, False, False), (t_h, True, False), (t_v, False, True), (t_hv, True, True)]:
                if cand in tile_dict:
                    idx = tile_dict[cand][0]
                    # Encode tilemap entry:
                    # bits 0-9: tile_index
                    # bit 10: hflip
                    # bit 11: vflip
                    # bits 12-15: palette (0)
                    entry = idx | (1024 if hf else 0) | (2048 if vf else 0)
                    tilemap[ty][tx] = entry
                    found = True
                    break
            if not found:
                idx = len(unique_tiles)
                unique_tiles.append(t)
                tile_dict[t] = (idx, False, False)
                tilemap[ty][tx] = idx

    print(f"Total de tiles únicos com flip: {len(unique_tiles)} (limite VRAM = 640 tiles, limite tilemap = 1024)")
    assert len(unique_tiles) <= 640, f"Excedeu o limite de tiles de VRAM: {len(unique_tiles)} > 640!"

    # 4. Gerar rayquaza.png contendo os tiles únicos em grade
    # Grade de 16 tiles de largura (128 pixels)
    tiles_wide = 16
    tiles_high = (len(unique_tiles) + tiles_wide - 1) // tiles_wide
    img_tiles = Image.new('P', (tiles_wide * 8, tiles_high * 8), 0)
    img_tiles.putpalette(flat_pal)

    for i, t in enumerate(unique_tiles):
        gx = (i % tiles_wide) * 8
        gy = (i // tiles_wide) * 8
        for py in range(8):
            for px in range(8):
                img_tiles.putpixel((gx + px, gy + py), t[py * 8 + px])

    img_tiles.save('graphics/title_screen/rayquaza.png')
    print(f"Salvo graphics/title_screen/rayquaza.png ({img_tiles.size})")

    # 5. Gerar rayquaza.bin (tilemap 32x32 = 1024 entries de 16-bit)
    bin_data = bytearray()
    for row in tilemap:
        for entry in row:
            bin_data.extend(struct.pack('<H', entry))

    with open('graphics/title_screen/rayquaza.bin', 'wb') as f:
        f.write(bin_data)
    print(f"Salvo graphics/title_screen/rayquaza.bin ({len(bin_data)} bytes)")

    # 6. Gerar pokeball.pal (paleta JASC-PAL de 16 cores)
    pal_lines = ["JASC-PAL", "0100", "16"]
    for c in pal_16:
        pal_lines.append(f"{c[0]} {c[1]} {c[2]}")
    pal_content = "\r\n".join(pal_lines) + "\r\n"

    with open('graphics/title_screen/pokeball.pal', 'w') as f:
        f.write(pal_content)
    print(f"Salvo graphics/title_screen/pokeball.pal!")

build_title_background()
