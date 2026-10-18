# -*- coding: utf-8 -*-
from PIL import Image
import os

def prepare_sprite(pokemon_name, out_path, size=(64, 64)):
    src = f"graphics/pokemon/{pokemon_name}/front.png"
    if not os.path.exists(src):
        print(f"Sprite not found: {src}")
        return False
    im = Image.open(src).convert("RGBA")
    # create background with slight border or clean transparent
    # upscale nearest-neighbor for crisp pixel art
    im_resized = im.resize(size, Image.Resampling.NEAREST)
    im_resized.save(out_path, format="PNG")
    return True

os.makedirs("scratch/guide_sprites", exist_ok=True)
test_list = ["sentret", "hoothoot", "mareep", "spinarak", "dunsparce", "mewtwo", "lugia", "pikachu", "scizor"]
for p in test_list:
    prepare_sprite(p, f"scratch/guide_sprites/{p}.png", size=(80, 80))
print("Prepared sprites successfully!")
