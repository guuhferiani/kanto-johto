import json

def apply_eeveelutions():
    json_path = 'src/data/wild_encounters.json'
    with open(json_path, 'r', encoding='utf-8') as f:
        data = json.load(f)

    for g in data.get('wild_encounter_groups', []):
        for enc in g.get('encounters', []):
            m = enc.get('map', '')
            lbl = enc.get('base_label', '')

            # 1. ROUTE 25 DAY (Espeon + Eevee)
            if m == 'MAP_ROUTE25' and lbl == 'gRoute25_Day':
                # Land mons: slot 3 -> EEVEE, slot 11 -> ESPEON
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][3] = {"min_level": 12, "max_level": 15, "species": "SPECIES_EEVEE"}
                    enc['land_mons']['mons'][11] = {"min_level": 16, "max_level": 18, "species": "SPECIES_ESPEON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][1] = {"min_level": 12, "max_level": 15, "species": "SPECIES_EEVEE"}
                    enc['hidden_mons']['mons'][2] = {"min_level": 16, "max_level": 18, "species": "SPECIES_ESPEON"}

            # 2. ROUTE 25 NIGHT (Umbreon + Eevee)
            elif m == 'MAP_ROUTE25' and lbl == 'gRoute25_Night':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][3] = {"min_level": 12, "max_level": 15, "species": "SPECIES_EEVEE"}
                    enc['land_mons']['mons'][11] = {"min_level": 16, "max_level": 18, "species": "SPECIES_UMBREON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][1] = {"min_level": 12, "max_level": 15, "species": "SPECIES_EEVEE"}
                    enc['hidden_mons']['mons'][2] = {"min_level": 16, "max_level": 18, "species": "SPECIES_UMBREON"}

            # 3. ROUTE 8 DAY (Espeon + Eevee)
            elif m == 'MAP_ROUTE8' and lbl == 'gRoute8_Day':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][8] = {"min_level": 18, "max_level": 22, "species": "SPECIES_EEVEE"}
                    enc['land_mons']['mons'][11] = {"min_level": 22, "max_level": 26, "species": "SPECIES_ESPEON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][1] = {"min_level": 22, "max_level": 26, "species": "SPECIES_ESPEON"}

            # 4. ROUTE 8 NIGHT (Umbreon + Eevee)
            elif m == 'MAP_ROUTE8' and lbl == 'gRoute8_Night':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][8] = {"min_level": 18, "max_level": 22, "species": "SPECIES_EEVEE"}
                    enc['land_mons']['mons'][11] = {"min_level": 22, "max_level": 26, "species": "SPECIES_UMBREON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][1] = {"min_level": 22, "max_level": 26, "species": "SPECIES_UMBREON"}

            # 5. POWER PLANT (Jolteon)
            elif m == 'MAP_POWER_PLANT':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][11] = {"min_level": 34, "max_level": 38, "species": "SPECIES_JOLTEON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][2] = {"min_level": 34, "max_level": 38, "species": "SPECIES_JOLTEON"}

            # 6. POKEMON MANSION 1F (Flareon)
            elif m == 'MAP_POKEMON_MANSION_1F':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][11] = {"min_level": 34, "max_level": 38, "species": "SPECIES_FLAREON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][2] = {"min_level": 34, "max_level": 38, "species": "SPECIES_FLAREON"}

            # 7. SEAFOAM ISLANDS B3F (Vaporeon)
            elif m == 'MAP_SEAFOAM_ISLANDS_B3F':
                if 'water_mons' in enc:
                    enc['water_mons']['mons'][3] = {"min_level": 30, "max_level": 38, "species": "SPECIES_VAPOREON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][0] = {"min_level": 30, "max_level": 38, "species": "SPECIES_VAPOREON"}

            # 8. POKEMON TOWER 3F (Umbreon)
            elif m == 'MAP_POKEMON_TOWER_3F':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][7] = {"min_level": 20, "max_level": 25, "species": "SPECIES_UMBREON"}
                if 'hidden_mons' in enc:
                    enc['hidden_mons']['mons'][1] = {"min_level": 20, "max_level": 25, "species": "SPECIES_UMBREON"}

            # 9. SAFARI ZONE CENTER (Eevee + Vaporeon)
            elif m == 'MAP_SAFARI_ZONE_CENTER':
                if 'land_mons' in enc:
                    enc['land_mons']['mons'][6] = {"min_level": 24, "max_level": 28, "species": "SPECIES_EEVEE"}
                if 'water_mons' in enc:
                    enc['water_mons']['mons'][4] = {"min_level": 25, "max_level": 35, "species": "SPECIES_VAPOREON"}

    with open(json_path, 'w', encoding='utf-8') as f:
        json.dump(data, f, indent=2)

    print("Eeveelutions e Eevee selvagens inseridos com sucesso!")

if __name__ == '__main__':
    apply_eeveelutions()
