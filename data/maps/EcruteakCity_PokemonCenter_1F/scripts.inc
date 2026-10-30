.set LOCALID_NURSE, 1

EcruteakCity_PokemonCenter_1F_MapScripts::
	.byte 0

EcruteakCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

EcruteakCity_PokemonCenter_1F_EventScript_Bill::
	msgbox EcruteakCity_PokemonCenter_1F_Text_Bill, MSGBOX_NPC
	end

EcruteakCity_PokemonCenter_1F_Text_Bill::
	.string "Bill: Olá, {PLAYER}!\n"
	.string "Acabei de concluir a Cápsula do\l"
	.string "Tempo no Centro Pokémon de\l"
	.string "Ecruteak City!$"
