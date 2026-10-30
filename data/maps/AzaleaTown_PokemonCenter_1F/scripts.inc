.set LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_PokemonCenter_1F_OnTransition
	.byte 0

AzaleaTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PALLET_TOWN
	end

AzaleaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

AzaleaTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox AzaleaTown_PokemonCenter_1F_Text_Gentleman, MSGBOX_NPC
	end

AzaleaTown_PokemonCenter_1F_Text_Gentleman::
	.string "Se um Slowpoke segurar uma Pedra\n"
	.string "do Rei (King's Rock), dizem que\l"
	.string "ele pode despertar uma inteligência\l"
	.string "digna de um Slowking!$"
