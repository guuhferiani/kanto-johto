import os

def update_file(path, old_text, new_text):
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()
    if old_text not in content:
        raise ValueError(f"Target text not found in {path}")
    content = content.replace(old_text, new_text, 1)
    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)
    print(f"Updated {path}")

# 1. include/constants/species.h
update_file(
    "include/constants/species.h",
    """#define SPECIES_MEWTWO_MEGA_Y                FORMS_START + 15

#define SPECIES_EGG SPECIES_MEWTWO_MEGA_Y + 1 
#define NUM_SPECIES SPECIES_EGG""",
    """#define SPECIES_MEWTWO_MEGA_Y                FORMS_START + 15
#define SPECIES_RIOLU                        FORMS_START + 16
#define SPECIES_LUCARIO                      FORMS_START + 17

#define SPECIES_EGG SPECIES_LUCARIO + 1 
#define NUM_SPECIES SPECIES_EGG"""
)

# 2. include/constants/pokedex.h
update_file(
    "include/constants/pokedex.h",
    """    NATIONAL_DEX_PIKACHU_PARTNER,
    NATIONAL_DEX_RIVAL_EEVEE,
    // Old Unown""",
    """    NATIONAL_DEX_PIKACHU_PARTNER,
    NATIONAL_DEX_RIVAL_EEVEE,
    NATIONAL_DEX_RIOLU,
    NATIONAL_DEX_LUCARIO,
    // Old Unown"""
)

update_file(
    "include/constants/pokedex.h",
    "#define NATIONAL_DEX_COUNT  NATIONAL_DEX_RIVAL_EEVEE",
    "#define NATIONAL_DEX_COUNT  NATIONAL_DEX_LUCARIO"
)

# 3. include/graphics.h
update_file(
    "include/graphics.h",
    """extern const u32 gMonFrontPic_MewtwoMegaY[];""",
    """extern const u32 gMonFrontPic_MewtwoMegaY[];
extern const u32 gMonFrontPic_Riolu[];
extern const u32 gMonFrontPic_Lucario[];"""
)

update_file(
    "include/graphics.h",
    """extern const u32 gMonBackPic_MewtwoMegaY[];""",
    """extern const u32 gMonBackPic_MewtwoMegaY[];
extern const u32 gMonBackPic_Riolu[];
extern const u32 gMonBackPic_Lucario[];"""
)

update_file(
    "include/graphics.h",
    """extern const u32 gMonPalette_MewtwoMegaY[];""",
    """extern const u32 gMonPalette_MewtwoMegaY[];
extern const u32 gMonPalette_Riolu[];
extern const u32 gMonPalette_Lucario[];"""
)

update_file(
    "include/graphics.h",
    """extern const u32 gMonShinyPalette_MewtwoMegaY[];""",
    """extern const u32 gMonShinyPalette_MewtwoMegaY[];
extern const u32 gMonShinyPalette_Riolu[];
extern const u32 gMonShinyPalette_Lucario[];"""
)

update_file(
    "include/graphics.h",
    """extern const u8 gMonIcon_MewtwoMegaY[];""",
    """extern const u8 gMonIcon_MewtwoMegaY[];
extern const u8 gMonIcon_Riolu[];
extern const u8 gMonIcon_Lucario[];"""
)

# 4. src/data/text/species_names.h
update_file(
    "src/data/text/species_names.h",
    """    [SPECIES_MEWTWO_MEGA_Y] = _("Mewtwo"),
};""",
    """    [SPECIES_MEWTWO_MEGA_Y] = _("Mewtwo"),
    [SPECIES_RIOLU] = _("Riolu"),
    [SPECIES_LUCARIO] = _("Lucario"),
};"""
)

# 5. src/data/pokemon/base_stats.h
riolu_lucario_stats = """    [SPECIES_RIOLU] =
    {
        .baseHP        = 40,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 40,
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,
        .catchRate = 75,
        .expYield = 57,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .abilities = {ABILITY_STEADFAST, ABILITY_INNER_FOCUS},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_LUCARIO] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 115,
        .baseSpDefense = 70,
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_STEEL,
        .catchRate = 45,
        .expYield = 184,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .abilities = {ABILITY_STEADFAST, ABILITY_INNER_FOCUS},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },
};"""

update_file(
    "src/data/pokemon/base_stats.h",
    """        .abilities = {ABILITY_INSOMNIA, ABILITY_INSOMNIA},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },
};""",
    f"""        .abilities = {{ABILITY_INSOMNIA, ABILITY_INSOMNIA}},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    }},

{riolu_lucario_stats}"""
)

# 6. src/data/pokemon/level_up_learnsets.h
riolu_lucario_learnsets = """static const struct LevelUpMove sRioluLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE( 1, MOVE_FORESIGHT),
    LEVEL_UP_MOVE( 1, MOVE_ENDURE),
    LEVEL_UP_MOVE( 6, MOVE_COUNTER),
    LEVEL_UP_MOVE(11, MOVE_FEINT),
    LEVEL_UP_MOVE(15, MOVE_FORCE_PALM),
    LEVEL_UP_MOVE(19, MOVE_COPYCAT),
    LEVEL_UP_MOVE(24, MOVE_SCREECH),
    LEVEL_UP_MOVE(29, MOVE_REVERSAL),
    LEVEL_UP_END
};

static const struct LevelUpMove sLucarioLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_AURA_SPHERE),
    LEVEL_UP_MOVE( 1, MOVE_DARK_PULSE),
    LEVEL_UP_MOVE( 1, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE( 1, MOVE_FORESIGHT),
    LEVEL_UP_MOVE( 1, MOVE_DETECT),
    LEVEL_UP_MOVE( 1, MOVE_METAL_CLAW),
    LEVEL_UP_MOVE( 6, MOVE_COUNTER),
    LEVEL_UP_MOVE(11, MOVE_FEINT),
    LEVEL_UP_MOVE(15, MOVE_FORCE_PALM),
    LEVEL_UP_MOVE(19, MOVE_SWORDS_DANCE),
    LEVEL_UP_MOVE(24, MOVE_METAL_SOUND),
    LEVEL_UP_MOVE(29, MOVE_BONE_RUSH),
    LEVEL_UP_MOVE(33, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE(37, MOVE_CLOSE_COMBAT),
    LEVEL_UP_MOVE(42, MOVE_DRAGON_PULSE),
    LEVEL_UP_MOVE(47, MOVE_EXTREMESPEED),
    LEVEL_UP_MOVE(51, MOVE_AURA_SPHERE),
    LEVEL_UP_END
};
"""

update_file(
    "src/data/pokemon/level_up_learnsets.h",
    """	LEVEL_UP_MOVE(57, MOVE_HEALING_WISH),
	LEVEL_UP_END
};""",
    f"""	LEVEL_UP_MOVE(57, MOVE_HEALING_WISH),
	LEVEL_UP_END
}};

{riolu_lucario_learnsets}"""
)

# 7. src/data/pokemon/level_up_learnset_pointers.h
update_file(
    "src/data/pokemon/level_up_learnset_pointers.h",
    """    [SPECIES_MEWTWO_MEGA_Y] = sMewtwoLevelUpLearnset,
};""",
    """    [SPECIES_MEWTWO_MEGA_Y] = sMewtwoLevelUpLearnset,
    [SPECIES_RIOLU] = sRioluLevelUpLearnset,
    [SPECIES_LUCARIO] = sLucarioLevelUpLearnset,
};"""
)

# 8. src/data/pokemon/evolution.h (com Eevee completo + Riolu)
update_file(
    "src/data/pokemon/evolution.h",
    """    [SPECIES_EEVEE]      = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_JOLTEON},
                            {EVO_ITEM, ITEM_WATER_STONE, SPECIES_VAPOREON},
                            {EVO_ITEM, ITEM_FIRE_STONE, SPECIES_FLAREON}},
                            //{EVO_FRIENDSHIP_DAY, 0, SPECIES_ESPEON},
                            //{EVO_FRIENDSHIP_NIGHT, 0, SPECIES_UMBREON}},""",
    """    [SPECIES_EEVEE]      = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_JOLTEON},
                            {EVO_ITEM, ITEM_WATER_STONE, SPECIES_VAPOREON},
                            {EVO_ITEM, ITEM_FIRE_STONE, SPECIES_FLAREON},
                            {EVO_FRIENDSHIP_DAY, 0, SPECIES_ESPEON},
                            {EVO_FRIENDSHIP_NIGHT, 0, SPECIES_UMBREON},
                            {EVO_ITEM, ITEM_SUN_STONE, SPECIES_ESPEON},
                            {EVO_ITEM, ITEM_MOON_STONE, SPECIES_UMBREON}},"""
)

update_file(
    "src/data/pokemon/evolution.h",
    """    [SPECIES_MEWTWO]     = {{EVO_MEGA_EVOLUTION, ITEM_MEWTWONITE_X, SPECIES_MEWTWO_MEGA_X},
                            {EVO_MEGA_EVOLUTION, ITEM_MEWTWONITE_Y, SPECIES_MEWTWO_MEGA_Y}},""",
    """    [SPECIES_MEWTWO]     = {{EVO_MEGA_EVOLUTION, ITEM_MEWTWONITE_X, SPECIES_MEWTWO_MEGA_X},
                            {EVO_MEGA_EVOLUTION, ITEM_MEWTWONITE_Y, SPECIES_MEWTWO_MEGA_Y}},
    [SPECIES_RIOLU]      = {{EVO_FRIENDSHIP_DAY, 0, SPECIES_LUCARIO},
                            {EVO_LEVEL, 30, SPECIES_LUCARIO}},"""
)

# 9. src/data/graphics/pokemon.h
graphics_pokemon_entries = """
const u32 gMonFrontPic_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/front.4bpp.lz");
const u32 gMonPalette_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/normal.gbapal.lz");
const u32 gMonBackPic_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/back.4bpp.lz");
const u32 gMonShinyPalette_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/shiny.gbapal.lz");
const u8 gMonIcon_Riolu[] = INCBIN_U8("graphics/pokemon/riolu/icon.4bpp");
const u8 gMonFootprint_Riolu[] = INCBIN_U8("graphics/pokemon/riolu/footprint.1bpp");

const u32 gMonFrontPic_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/front.4bpp.lz");
const u32 gMonPalette_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/normal.gbapal.lz");
const u32 gMonBackPic_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/back.4bpp.lz");
const u32 gMonShinyPalette_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/shiny.gbapal.lz");
const u8 gMonIcon_Lucario[] = INCBIN_U8("graphics/pokemon/lucario/icon.4bpp");
const u8 gMonFootprint_Lucario[] = INCBIN_U8("graphics/pokemon/lucario/footprint.1bpp");
"""

with open("src/data/graphics/pokemon.h", "r", encoding="utf-8") as f:
    c = f.read()
c = c + graphics_pokemon_entries
with open("src/data/graphics/pokemon.h", "w", encoding="utf-8") as f:
    f.write(c)
print("Updated src/data/graphics/pokemon.h")

# 10. src/data/pokemon_graphics/front_pic_table.h
update_file(
    "src/data/pokemon_graphics/front_pic_table.h",
    """    SPECIES_SPRITE(MEWTWO_MEGA_Y, gMonFrontPic_MewtwoMegaY),
};""",
    """    SPECIES_SPRITE(MEWTWO_MEGA_Y, gMonFrontPic_MewtwoMegaY),
    SPECIES_SPRITE(RIOLU, gMonFrontPic_Riolu),
    SPECIES_SPRITE(LUCARIO, gMonFrontPic_Lucario),
};"""
)

# 11. src/data/pokemon_graphics/back_pic_table.h
update_file(
    "src/data/pokemon_graphics/back_pic_table.h",
    """    SPECIES_SPRITE(MEWTWO_MEGA_Y, gMonBackPic_MewtwoMegaY),
};""",
    """    SPECIES_SPRITE(MEWTWO_MEGA_Y, gMonBackPic_MewtwoMegaY),
    SPECIES_SPRITE(RIOLU, gMonBackPic_Riolu),
    SPECIES_SPRITE(LUCARIO, gMonBackPic_Lucario),
};"""
)

# 12. src/data/pokemon_graphics/palette_table.h
update_file(
    "src/data/pokemon_graphics/palette_table.h",
    """    SPECIES_PAL(MEWTWO_MEGA_Y, gMonPalette_MewtwoMegaY),
};""",
    """    SPECIES_PAL(MEWTWO_MEGA_Y, gMonPalette_MewtwoMegaY),
    SPECIES_PAL(RIOLU, gMonPalette_Riolu),
    SPECIES_PAL(LUCARIO, gMonPalette_Lucario),
};"""
)

# 13. src/data/pokemon_graphics/shiny_palette_table.h
update_file(
    "src/data/pokemon_graphics/shiny_palette_table.h",
    """    SPECIES_SHINY_PAL(MEWTWO_MEGA_Y, gMonShinyPalette_MewtwoMegaY),
};""",
    """    SPECIES_SHINY_PAL(MEWTWO_MEGA_Y, gMonShinyPalette_MewtwoMegaY),
    SPECIES_SHINY_PAL(RIOLU, gMonShinyPalette_Riolu),
    SPECIES_SHINY_PAL(LUCARIO, gMonShinyPalette_Lucario),
};"""
)

# 14. src/pokemon_icon.c
update_file(
    "src/pokemon_icon.c",
    """    [SPECIES_MEWTWO_MEGA_Y] = gMonIcon_MewtwoMegaY,
};""",
    """    [SPECIES_MEWTWO_MEGA_Y] = gMonIcon_MewtwoMegaY,
    [SPECIES_RIOLU] = gMonIcon_Riolu,
    [SPECIES_LUCARIO] = gMonIcon_Lucario,
};"""
)

update_file(
    "src/pokemon_icon.c",
    """    [SPECIES_MEWTWO_MEGA_Y] = 2,
};""",
    """    [SPECIES_MEWTWO_MEGA_Y] = 2,
    [SPECIES_RIOLU] = 0,
    [SPECIES_LUCARIO] = 0,
};"""
)

# 15. src/data/pokemon_graphics/front_pic_coordinates.h
update_file(
    "src/data/pokemon_graphics/front_pic_coordinates.h",
    """    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 0,
    },
};""",
    """    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 0,
    },
    [SPECIES_RIOLU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 10,
    },
    [SPECIES_LUCARIO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
};"""
)

# 16. src/data/pokemon_graphics/back_pic_coordinates.h
update_file(
    "src/data/pokemon_graphics/back_pic_coordinates.h",
    """    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
};""",
    """    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_RIOLU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 10,
    },
    [SPECIES_LUCARIO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
};"""
)

# 17. src/pokemon.c
update_file(
    "src/pokemon.c",
    """    [SPECIES_MEWTWO_MEGA_Y - 1] = NATIONAL_DEX_MEWTWO,
};

// Assigns all species to the National Dex Index""",
    """    [SPECIES_MEWTWO_MEGA_Y - 1] = NATIONAL_DEX_MEWTWO,
    [SPECIES_RIOLU - 1] = 0,
    [SPECIES_LUCARIO - 1] = 0,
};

// Assigns all species to the National Dex Index"""
)

update_file(
    "src/pokemon.c",
    """    [SPECIES_MEWTWO_MEGA_Y - 1] = NATIONAL_DEX_MEWTWO,
};

// Assigns all Hoenn Dex Indexes to a National Dex Index""",
    """    [SPECIES_MEWTWO_MEGA_Y - 1] = NATIONAL_DEX_MEWTWO,
    [SPECIES_RIOLU - 1] = NATIONAL_DEX_RIOLU,
    [SPECIES_LUCARIO - 1] = NATIONAL_DEX_LUCARIO,
};

// Assigns all Hoenn Dex Indexes to a National Dex Index"""
)

# 18. src/data/pokemon/cry_ids.h
update_file(
    "src/data/pokemon/cry_ids.h",
    """    [SPECIES_RIVAL_EEVEE - 277] = 389,
};""",
    """    [SPECIES_RIVAL_EEVEE - 277] = 389,
    [SPECIES_RIOLU - 277] = 296,
    [SPECIES_LUCARIO - 277] = 287,
};"""
)

# 19. src/data/pokemon/tmhm_learnsets.h
riolu_lucario_tmhm = """    [SPECIES_RIOLU]       = TMHM_LEARNSET(TMHM(TM01_FOCUS_PUNCH)
                                        | TMHM(TM06_TOXIC)
                                        | TMHM(TM08_BULK_UP)
                                        | TMHM(TM10_HIDDEN_POWER)
                                        | TMHM(TM11_SUNNY_DAY)
                                        | TMHM(TM17_PROTECT)
                                        | TMHM(TM18_RAIN_DANCE)
                                        | TMHM(TM21_FRUSTRATION)
                                        | TMHM(TM23_IRON_TAIL)
                                        | TMHM(TM26_EARTHQUAKE)
                                        | TMHM(TM27_RETURN)
                                        | TMHM(TM28_DIG)
                                        | TMHM(TM31_BRICK_BREAK)
                                        | TMHM(TM32_DOUBLE_TEAM)
                                        | TMHM(TM39_ROCK_TOMB)
                                        | TMHM(TM42_FACADE)
                                        | TMHM(TM43_SECRET_POWER)
                                        | TMHM(TM44_REST)
                                        | TMHM(TM45_ATTRACT)
                                        | TMHM(HM04_STRENGTH)
                                        | TMHM(HM06_ROCK_SMASH)),

    [SPECIES_LUCARIO]     = TMHM_LEARNSET(TMHM(TM01_FOCUS_PUNCH)
                                        | TMHM(TM03_WATER_PULSE)
                                        | TMHM(TM04_CALM_MIND)
                                        | TMHM(TM05_ROAR)
                                        | TMHM(TM06_TOXIC)
                                        | TMHM(TM08_BULK_UP)
                                        | TMHM(TM10_HIDDEN_POWER)
                                        | TMHM(TM11_SUNNY_DAY)
                                        | TMHM(TM15_HYPER_BEAM)
                                        | TMHM(TM17_PROTECT)
                                        | TMHM(TM18_RAIN_DANCE)
                                        | TMHM(TM21_FRUSTRATION)
                                        | TMHM(TM23_IRON_TAIL)
                                        | TMHM(TM26_EARTHQUAKE)
                                        | TMHM(TM27_RETURN)
                                        | TMHM(TM28_DIG)
                                        | TMHM(TM29_PSYCHIC)
                                        | TMHM(TM30_SHADOW_BALL)
                                        | TMHM(TM31_BRICK_BREAK)
                                        | TMHM(TM32_DOUBLE_TEAM)
                                        | TMHM(TM39_ROCK_TOMB)
                                        | TMHM(TM42_FACADE)
                                        | TMHM(TM43_SECRET_POWER)
                                        | TMHM(TM44_REST)
                                        | TMHM(TM45_ATTRACT)
                                        | TMHM(HM04_STRENGTH)
                                        | TMHM(HM06_ROCK_SMASH)),
};"""

update_file(
    "src/data/pokemon/tmhm_learnsets.h",
    """    [SPECIES_CHIMECHO]         = TMHM_LEARNSET(TMHM(TM04_CALM_MIND)
                                        | TMHM(TM06_TOXIC)
                                        | TMHM(TM10_HIDDEN_POWER)
                                        | TMHM(TM11_SUNNY_DAY)
                                        | TMHM(TM12_TAUNT)
                                        | TMHM(TM17_PROTECT)
                                        | TMHM(TM18_RAIN_DANCE)
                                        | TMHM(TM20_SAFEGUARD)
                                        | TMHM(TM21_FRUSTRATION)
                                        | TMHM(TM23_IRON_TAIL)
                                        | TMHM(TM27_RETURN)
                                        | TMHM(TM29_PSYCHIC)
                                        | TMHM(TM30_SHADOW_BALL)
                                        | TMHM(TM32_DOUBLE_TEAM)
                                        | TMHM(TM33_REFLECT)
                                        | TMHM(TM34_SHOCK_WAVE)
                                        | TMHM(TM41_TORMENT)
                                        | TMHM(TM42_FACADE)
                                        | TMHM(TM43_SECRET_POWER)
                                        | TMHM(TM44_REST)
                                        | TMHM(TM45_ATTRACT)
                                        | TMHM(TM46_THIEF)
                                        | TMHM(TM48_SKILL_SWAP)
                                        | TMHM(TM49_SNATCH)
                                        | TMHM(HM05_FLASH)),
};""",
    f"""    [SPECIES_CHIMECHO]         = TMHM_LEARNSET(TMHM(TM04_CALM_MIND)
                                        | TMHM(TM06_TOXIC)
                                        | TMHM(TM10_HIDDEN_POWER)
                                        | TMHM(TM11_SUNNY_DAY)
                                        | TMHM(TM12_TAUNT)
                                        | TMHM(TM17_PROTECT)
                                        | TMHM(TM18_RAIN_DANCE)
                                        | TMHM(TM20_SAFEGUARD)
                                        | TMHM(TM21_FRUSTRATION)
                                        | TMHM(TM23_IRON_TAIL)
                                        | TMHM(TM27_RETURN)
                                        | TMHM(TM29_PSYCHIC)
                                        | TMHM(TM30_SHADOW_BALL)
                                        | TMHM(TM32_DOUBLE_TEAM)
                                        | TMHM(TM33_REFLECT)
                                        | TMHM(TM34_SHOCK_WAVE)
                                        | TMHM(TM41_TORMENT)
                                        | TMHM(TM42_FACADE)
                                        | TMHM(TM43_SECRET_POWER)
                                        | TMHM(TM44_REST)
                                        | TMHM(TM45_ATTRACT)
                                        | TMHM(TM46_THIEF)
                                        | TMHM(TM48_SKILL_SWAP)
                                        | TMHM(TM49_SNATCH)
                                        | TMHM(HM05_FLASH)),

{riolu_lucario_tmhm}"""
)

print("ALL RIOLU AND LUCARIO CODE INJECTIONS COMPLETED SUCCESSFULLY!")
