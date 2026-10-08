import re

with open('src/data/trainers.h', 'r') as f:
    text = f.read()

trainers_entries = """
    [TRAINER_LEADER_FALKNER] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BIRD_KEEPER,
        .trainerName = _("Falkner"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderFalkner),
        .party = {.NoItemCustomMoves = sParty_LeaderFalkner}
    },
    [TRAINER_LEADER_BUGSY] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Bugsy"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderBugsy),
        .party = {.NoItemCustomMoves = sParty_LeaderBugsy}
    },
    [TRAINER_LEADER_WHITNEY] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Whitney"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderWhitney),
        .party = {.NoItemCustomMoves = sParty_LeaderWhitney}
    },
    [TRAINER_LEADER_MORTY] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PSYCHIC_M,
        .trainerName = _("Morty"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderMorty),
        .party = {.NoItemCustomMoves = sParty_LeaderMorty}
    },
    [TRAINER_LEADER_CHUCK] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BLACK_BELT,
        .trainerName = _("Chuck"),
        .items = {ITEM_HYPER_POTION, ITEM_HYPER_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderChuck),
        .party = {.NoItemCustomMoves = sParty_LeaderChuck}
    },
    [TRAINER_LEADER_JASMINE] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_BEAUTY,
        .trainerName = _("Jasmine"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderJasmine),
        .party = {.NoItemCustomMoves = sParty_LeaderJasmine}
    },
    [TRAINER_LEADER_PRYCE] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_GENTLEMAN,
        .trainerName = _("Pryce"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderPryce),
        .party = {.NoItemCustomMoves = sParty_LeaderPryce}
    },
    [TRAINER_LEADER_CLAIR] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .trainerPic = TRAINER_PIC_COOLTRAINER_F,
        .trainerName = _("Clair"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_LeaderClair),
        .party = {.NoItemCustomMoves = sParty_LeaderClair}
    },
    [TRAINER_CHAMPION_RED] = {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_CHAMPION,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_RED,
        .trainerName = _("Red"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SETUP_FIRST_TURN | AI_FLAG_HP_AWARE | AI_FLAG_SMART_SWITCHING,
        .partySize = ARRAY_COUNT(sParty_ChampionRed),
        .party = {.ItemCustomMoves = sParty_ChampionRed}
    },
"""

last_brace = text.rfind('};')
if last_brace != -1:
    new_text = text[:last_brace] + trainers_entries + text[last_brace:]
    with open('src/data/trainers.h', 'w') as f:
        f.write(new_text)
    print('Updated trainers.h successfully!')
else:
    print('Error: Could not find closing brace!')
