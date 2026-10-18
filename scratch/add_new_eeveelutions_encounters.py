import json

def apply_new_eeveelutions():
    path = 'src/data/wild_encounters.json'
    with open(path, 'r', encoding='utf-8') as f:
        data = json.load(f)

    for g in data.get('wild_encounter_groups', []):
        for enc in g.get('encounters', []):
            m = enc.get('map', '')
            lbl = enc.get('base_label', '')

            # 1. LEAFEON em Viridian Forest
            if m == 'MAP_VIRIDIAN_FOREST' and lbl == 'gViridianForest_Day':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][7] = {"min_level": 10, "max_level": 14, "species": "SPECIES_LEAFEON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][0] = {"min_level": 10, "max_level": 14, "species": "SPECIES_LEAFEON"}

            # 2. GLACEON em Seafoam Islands B4F
            elif m == 'MAP_SEAFOAM_ISLANDS_B4F':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][11] = {"min_level": 32, "max_level": 38, "species": "SPECIES_GLACEON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][0] = {"min_level": 32, "max_level": 38, "species": "SPECIES_GLACEON"}

            # 3. SYLVEON em Route 25 (Day) e Safari Zone
            elif m == 'MAP_ROUTE25' and lbl == 'gRoute25_Day':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][6] = {"min_level": 16, "max_level": 18, "species": "SPECIES_SYLVEON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][0] = {"min_level": 16, "max_level": 18, "species": "SPECIES_SYLVEON"}

            elif m == 'MAP_SAFARI_ZONE_CENTER':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][10] = {"min_level": 25, "max_level": 30, "species": "SPECIES_SYLVEON"}

    with open(path, 'w', encoding='utf-8') as f:
        json.dump(data, f, indent=2)

    print("Leafeon, Glaceon e Sylveon adicionados aos encontros com sucesso!")

if __name__ == '__main__':
    apply_new_eeveelutions()
