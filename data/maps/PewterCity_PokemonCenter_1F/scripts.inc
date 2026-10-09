.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_1F_OnTransition
	.byte 0

PewterCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone::
    .string "O quê!?\p"
    .string "A Equipe Rocket está no Monte Moon?\n"
    .string "Hã?\p"
    .string "Eu estou no telefone!\n"
    .string "Cai fora!$"

PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_RG_JIGGLYPUFF, 0
	message PewterCity_PokemonCenter_1F_Text_Jigglypuff
	waitmessage
	delay 455
	playbgm MUS_RG_POKE_CENTER, 1
	closemessage
	release
	end

PewterCity_PokemonCenter_1F_Text_Jigglypuff::
    .string "Jigglypuff: Puu pupuu!$"

PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy::
    .string "Bocejo…\p"
    .string "Quando Jigglypuff canta, os Pokémon\n"
    .string "ficam cheios de sono…\p"
    .string "…Eu também…\n"
    .string "Zzzzz…$"

PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	lock
	msgbox PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu
	release
	end

PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu::
    .string "Eu queria muito um Pikachu, então\n"
    .string "estou trocando meu Clefairy por um.$"

PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid::
    .string "Estou trocando Pokémon com aquele\n"
    .string "garoto ali.\p"
    .string "Eu tinha dois Pikachu, então achei\n"
    .string "que valia a pena trocar um.$"
