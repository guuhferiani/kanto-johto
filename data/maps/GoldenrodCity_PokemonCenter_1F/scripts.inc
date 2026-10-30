.set LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_1F_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PALLET_TOWN
	end

GoldenrodCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

GoldenrodCity_PokemonCenter_1F_EventScript_Pokefan::
	msgbox GoldenrodCity_PokemonCenter_1F_Text_Pokefan, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_1F_Text_Pokefan::
	.string "O Diretor da Torre de Rádio guarda\n"
	.string "relíquias sagradas de Johto no\l"
	.string "andar principal da Torre!$"
