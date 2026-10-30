.set LOCALID_NURSE, 1

VioletCity_PokemonCenter_1F_MapScripts::
	.byte 0

VioletCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

VioletCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VioletCity_PokemonCenter_1F_Text_Gentleman, MSGBOX_NPC
	end

VioletCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VioletCity_PokemonCenter_1F_Text_Youngster, MSGBOX_NPC
	end

VioletCity_PokemonCenter_1F_Text_Gentleman:
	.string "Os Centros Pokémon de Johto também\n"
	.string "estão integrados ao sistema de PC\l"
	.string "do Bill em Kanto!$"

VioletCity_PokemonCenter_1F_Text_Youngster:
	.string "Se você tiver um Pikachu forte, o\n"
	.string "Ginásio de Falkner será uma ótima\l"
	.string "oportunidade para brilhar!$"
