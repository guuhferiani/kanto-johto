import json

with open('src/data/wild_encounters.json', 'r') as f:
    data = json.load(f)

maps_target = [
    'MAP_ROUTE1',
    'MAP_ROUTE2',
    'MAP_VIRIDIAN_FOREST',
    'MAP_ROUTE22',
    'MAP_ROUTE3',
    'MAP_ROUTE4',
    'MAP_MT_MOON_1F',
    'MAP_MT_MOON_B1F',
    'MAP_MT_MOON_B2F'
]

for enc in data['wild_encounter_groups'][0]['encounters']:
    if enc.get('map') in maps_target:
        print(f"Map: {enc.get('map')} | Label: {enc.get('base_label')}")
        land = enc.get('land_mons', {})
        for i, m in enumerate(land.get('mons', [])):
            print(f"  [{i:2d}] {m['species']} (lv {m['min_level']}-{m['max_level']})")
