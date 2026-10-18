import json

with open('src/data/wild_encounters.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

for enc in data['wild_encounter_groups'][0]['encounters']:
    label = enc.get('base_label')
    land = enc.get('land_mons', {})
    mons = land.get('mons', [])
    if not mons:
        continue

    if label == 'gRoute1_Day':
        mons[2]['species'] = 'SPECIES_SENTRET'
        mons[4]['species'] = 'SPECIES_SENTRET'
        mons[6]['species'] = 'SPECIES_LEDYBA'
        mons[8]['species'] = 'SPECIES_LEDYBA'
        mons[10]['species'] = 'SPECIES_SENTRET'

    elif label == 'gRoute1_Night':
        mons[1]['species'] = 'SPECIES_HOOTHOOT'
        mons[2]['species'] = 'SPECIES_HOOTHOOT'
        mons[4]['species'] = 'SPECIES_SENTRET'
        mons[6]['species'] = 'SPECIES_HOOTHOOT'
        mons[7]['species'] = 'SPECIES_SENTRET'
        mons[8]['species'] = 'SPECIES_SPINARAK'
        mons[10]['species'] = 'SPECIES_SPINARAK'

    elif label == 'gViridianForest_Day':
        mons[2]['species'] = 'SPECIES_LEDYBA'
        mons[6]['species'] = 'SPECIES_PINECO'

    elif label == 'gViridianForest_Night':
        mons[2]['species'] = 'SPECIES_SPINARAK'
        mons[6]['species'] = 'SPECIES_HOOTHOOT'

    elif label == 'gRoute22_Day':
        mons[3]['species'] = 'SPECIES_HOPPIP'
        mons[8]['species'] = 'SPECIES_MARILL'

    elif label == 'gRoute22_Night':
        mons[2]['species'] = 'SPECIES_WOOPER'
        mons[8]['species'] = 'SPECIES_HOOTHOOT'

    elif label == 'gRoute2_Day':
        mons[5]['species'] = 'SPECIES_MAREEP'
        mons[7]['species'] = 'SPECIES_MAREEP'

    elif label == 'gRoute2_Night':
        mons[2]['species'] = 'SPECIES_HOOTHOOT'
        mons[5]['species'] = 'SPECIES_MAREEP'

    elif label == 'gRoute3_Day':
        mons[1]['species'] = 'SPECIES_SNUBBULL'
        mons[9]['species'] = 'SPECIES_PHANPY'

    elif label == 'gRoute3_NIGHT':
        mons[3]['species'] = 'SPECIES_TEDDIURSA'
        mons[9]['species'] = 'SPECIES_HOOTHOOT'

    elif label == 'gRoute4_Day':
        mons[1]['species'] = 'SPECIES_PHANPY'
        mons[8]['species'] = 'SPECIES_SNUBBULL'

    elif label == 'gRoute4_Night':
        mons[3]['species'] = 'SPECIES_TEDDIURSA'

    elif label in ['gMtMoon_1F', 'gMtMoon_B1F', 'gMtMoon_B2F']:
        mons[3]['species'] = 'SPECIES_DUNSPARCE'

with open('src/data/wild_encounters.json', 'w', encoding='utf-8') as f:
    json.dump(data, f, indent=2)

print("Updated src/data/wild_encounters.json successfully!")
