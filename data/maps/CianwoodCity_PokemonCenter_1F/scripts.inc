.set LOCALID_NURSE, 1

CianwoodCity_PokemonCenter_1F_MapScripts::
	.byte 0

CianwoodCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end
