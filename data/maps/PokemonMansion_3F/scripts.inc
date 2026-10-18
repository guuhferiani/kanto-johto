PokemonMansion_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_SimonIntro::
    .string "Este lugar é simplesmente gigante!$"

PokemonMansion_1F_Text_SimonDefeat::
    .string "Ai ai ai!$"

PokemonMansion_1F_Text_SimonPostBattle::
    .string "Onde será que meu parceiro foi parar?$"

PokemonMansion_1F_Text_BraydonIntro::
    .string "Meu mentor já morou aqui.$"

PokemonMansion_1F_Text_BraydonDefeat::
    .string "Ufa!\n"
    .string "Que poder avassalador!$"

PokemonMansion_1F_Text_BraydonPostBattle::
    .string "Então você ficou preso?\n"
    .string "Tente pular lá daquele lado!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
    .string "Diário: 6 de Fevereiro\n"
    .string "Mew deu à luz.\p"
    .string "Nomeamos o recém-nascido de Mewtwo.$"

PokemonMansion_3F_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION, 1
	release
	end

PokemonMansion_3F_EventScript_ItemIron::
	finditem ITEM_IRON, 1
	release
	end

PokemonMansion_3F_EventScript_ItemCharcoal::
	finditem ITEM_CHARCOAL, 1
	release
	end

PokemonMansion_3F_EventScript_CharizarditeY::
	finditem ITEM_MAX_REVIVE, 1
	setflag FLAG_GOT_CHARIZARDITE_Y
	release
	end
