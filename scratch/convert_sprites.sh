#!/bin/bash
set -e
for name in lucario riolu; do
    d="graphics/pokemon/$name"
    ./tools/gbagfx/gbagfx "$d/front.png" "$d/front.4bpp"
    ./tools/gbagfx/gbagfx "$d/front.4bpp" "$d/front.4bpp.lz"
    ./tools/gbagfx/gbagfx "$d/back.png" "$d/back.4bpp"
    ./tools/gbagfx/gbagfx "$d/back.4bpp" "$d/back.4bpp.lz"
    ./tools/gbagfx/gbagfx "$d/normal.pal" "$d/normal.gbapal"
    ./tools/gbagfx/gbagfx "$d/normal.gbapal" "$d/normal.gbapal.lz"
    ./tools/gbagfx/gbagfx "$d/shiny.pal" "$d/shiny.gbapal"
    ./tools/gbagfx/gbagfx "$d/shiny.gbapal" "$d/shiny.gbapal.lz"
    ./tools/gbagfx/gbagfx "$d/icon.png" "$d/icon.4bpp"
    ./tools/gbagfx/gbagfx "$d/footprint.png" "$d/footprint.1bpp"
    echo "Converted $name successfully!"
done
