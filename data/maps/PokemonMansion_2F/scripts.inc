PokemonMansion_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
    .string "Um botão secreto!\p"
    .string "Apertar?$"

PokemonMansion_Text_WhoWouldnt::
    .string "Quem não apertaria?$"

PokemonMansion_Text_NotQuiteYet::
    .string "Ainda não!$"

PokemonMansion_1F_Text_ArnieIntro::
    .string "Não consigo sair!\n"
    .string "Este lugar velho é um quebra-cabeça só.$"

PokemonMansion_1F_Text_ArnieDefeat::
    .string "Oh, não!\n"
    .string "Minha sacola de tesouros!$"

PokemonMansion_1F_Text_ArniePostBattle::
    .string "Os botões aqui abrem e fecham grupos\n"
    .string "alternados de portas.$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
    .string "Diário: 5 de Julho\n"
    .string "Guiana, América do Sul\p"
    .string "Um novo Pokémon foi descoberto nas\n"
    .string "profundezas da selva.$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
    .string "Diário: 10 de Julho\n"
    .string "Batizamos o Pokémon recém-descoberto\l"
    .string "de Mew.$"

PokemonMansion_2F_EventScript_ItemZinc::
	finditem ITEM_ZINC, 1
	release
	end

PokemonMansion_2F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP, 1
	release
	end

PokemonMansion_2F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

PokemonMansion_2F_EventScript_CharizarditeX::
	finditem ITEM_CHARIZARDITE_X, 1
	setflag FLAG_GOT_CHARIZARDITE_X
	goto_if_unset FLAG_FIRST_MEGASTONE, PokemonMansion_2F_EventScript_FoundMegaStone
    end

PokemonMansion_2F_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
