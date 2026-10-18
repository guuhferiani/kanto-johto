import json

with open('src/data/wild_encounters.json', 'r') as f:
    data = json.load(f)

for e in data['wild_encounter_groups'][0]['encounters']:
    m = e.get('map', '')
    if m in ['MAP_ROUTE1', 'MAP_ROUTE2', 'MAP_ROUTE3', 'MAP_ROUTE4']:
        print('===', e.get('base_label'), '===')
        land = e.get('land_mons', {})
        for idx, mon in enumerate(land.get('mons', [])):
            print(f"  slot {idx:2d}: {mon['species']} (lv {mon['min_level']}-{mon['max_level']})")
