from PIL import Image
import os

mons = ['leafeon', 'glaceon', 'sylveon']

for mon in mons:
    anim_path = f'graphics/pokemon/{mon}/anim_front.png'
    front_path = f'graphics/pokemon/{mon}/front.png'
    im = Image.open(anim_path)
    # Primeiro frame 64x64
    w, h = im.size
    frame_h = min(64, h)
    frame = im.crop((0, 0, 64, frame_h))
    frame.save(front_path)
    print(f'Saved {front_path} ({frame.size})')

    # Garantir CRLF nos arquivos .pal
    for pal_name in ['normal.pal', 'shiny.pal']:
        pal_path = f'graphics/pokemon/{mon}/{pal_name}'
        if os.path.exists(pal_path):
            with open(pal_path, 'r', encoding='latin1') as f:
                content = f.read()
            # normalizar
            content = content.replace('\r\n', '\n').replace('\n', '\r\n')
            with open(pal_path, 'w', encoding='latin1', newline='') as f:
                f.write(content)
            print(f'Normalized CRLF for {pal_path}')
