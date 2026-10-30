.set LOCALID_NURSE, 1

BlackthornCity_PokemonCenter_1F_MapScripts::
	.byte 0

BlackthornCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BlackthornCity_PokemonCenter_1F_EventScript_Cooltrainer::
	msgbox BlackthornCity_PokemonCenter_1F_Text_Cooltrainer, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_1F_Text_Cooltrainer::
	.string "Clair é prima de Lance, o Campeão\n"
	.string "dos Dragões!\p"
	.string "Depois de vencê-la, não deixe de\n"
	.string "visitar o Mestre Ancião no Dragon's\l"
	.string "Den para receber um Dratini raro!$"
