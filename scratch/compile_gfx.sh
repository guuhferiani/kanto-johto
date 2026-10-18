#!/bin/bash
for mon in leafeon glaceon sylveon; do
    ./tools/gbagfx/gbagfx graphics/pokemon/$mon/front.png graphics/pokemon/$mon/front.4bpp.lz
    ./tools/gbagfx/gbagfx graphics/pokemon/$mon/back.png graphics/pokemon/$mon/back.4bpp.lz
    ./tools/gbagfx/gbagfx graphics/pokemon/$mon/normal.pal graphics/pokemon/$mon/normal.gbapal.lz
    ./tools/gbagfx/gbagfx graphics/pokemon/$mon/shiny.pal graphics/pokemon/$mon/shiny.gbapal.lz
    ./tools/gbagfx/gbagfx graphics/pokemon/$mon/footprint.png graphics/pokemon/$mon/footprint.1bpp
    ./tools/gbagfx/gbagfx graphics/pokemon/$mon/icon.png graphics/pokemon/$mon/icon.4bpp
    echo "Compiled $mon graphics"
done
