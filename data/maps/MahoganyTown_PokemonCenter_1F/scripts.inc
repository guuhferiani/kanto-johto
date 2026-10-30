.set LOCALID_NURSE, 1

MahoganyTown_PokemonCenter_1F_MapScripts::
	.byte 0

MahoganyTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MahoganyTown_PokemonCenter_1F_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_1F_Text_Hiker, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_1F_Text_Hiker::
	.string "A caverna Ice Path a oeste da\n"
	.string "cidade abriga Pokémon de Gelo\l"
	.string "raros como Sneasel, Swinub e\l"
	.string "Jynx, e leva direto a Blackthorn!$"
