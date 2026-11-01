.set LOCALID_NURSE, 1

OlivineCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_1F_OnTransition
	.byte 0

OlivineCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end


OlivineCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end
