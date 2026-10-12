PokemonMansion_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	.byte 0

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_Text_LewisIntro::
    .string "Ops...\n"
    .string "Onde é que eu vim parar agora?$"

PokemonMansion_B1F_Text_LewisDefeat::
    .string "Auuu!$"

PokemonMansion_B1F_Text_LewisPostBattle::
    .string "Dá para achar itens jogados por aí.\n"
    .string "Os antigos moradores devem ter deixado.$"

PokemonMansion_B1F_Text_IvanIntro::
    .string "Este lugar é ideal para um laboratório.\n"
    .string "Olhe só todo esse espaço.$"

PokemonMansion_B1F_Text_IvanDefeat::
    .string "Pra que isso?$"

PokemonMansion_B1F_Text_IvanPostBattle::
    .string "Eu gosto daqui.\n"
    .string "É muito propício para os meus estudos.$"

PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful::
    .string "Diário: 1 de Setembro\n"
    .string "Mewtwo é poderoso demais.\p"
    .string "Fracassamos em conter suas tendências\n"
    .string "violentas...$"

PokemonMansion_B1F_EventScript_ItemTM22::
	finditem ITEM_TM22, 1
	release
	end

PokemonMansion_B1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE, 1
	release
	end

PokemonMansion_B1F_EventScript_ItemTM14::
	finditem ITEM_TM14, 1
	release
	end

PokemonMansion_B1F_EventScript_OldSeaMap::
	lock
	msgbox PokemonMansion_B1F_Text_OldMap, MSGBOX_SIGN
	waitmessage
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, PokemonMansion_B1F_EventScript_SkipOldSeaMap
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	msgbox PokemonMansion_B1F_Text_SomethingHidden, MSGBOX_DEFAULT
	finditem ITEM_OLD_SEA_MAP, 1
	setflag FLAG_RECEIVED_OLD_SEA_MAP
PokemonMansion_B1F_EventScript_SkipOldSeaMap::
	release
	end

PokemonMansion_B1F_Text_OldMap::
	.string "É um mapa antigo...\p"
	.string "Há uma ilha que você não\n"
	.string "reconhece nele.$"

PokemonMansion_B1F_Text_SomethingHidden::
	.string "Há algo escondido\n"
	.string "atrás da moldura!$"
