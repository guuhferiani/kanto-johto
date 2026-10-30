.set LOCALID_LUGIA, 1

WhirlIslands_MapScripts::
	.byte 0

WhirlIslands_EventScript_Lugia::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_LEADER_CHUCK, WhirlIslands_EventScript_LugiaSleeping
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	msgbox WhirlIslands_Text_LugiaAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_LUGIA, 70, ITEM_MYSTIC_WATER
	dowildbattle
	removeobject LOCALID_LUGIA
	setflag FLAG_CAUGHT_WHIRL_ISLANDS_LUGIA
	release
	end

WhirlIslands_EventScript_LugiaSleeping::
	msgbox WhirlIslands_Text_LugiaSleeping, MSGBOX_DEFAULT
	release
	end

WhirlIslands_Text_LugiaSleeping::
	.string "O rugido das cachoeiras submersas\n"
	.string "ecoa pelas Whirl Islands...\p"
	.string "Conquiste a Insígnia da Tempestade\n"
	.string "no Ginásio de Cianwood para\l"
	.string "despertar o guardião dos mares!$"

WhirlIslands_Text_LugiaAppeared::
	.string "As águas abissais das Whirl Islands\n"
	.string "se abrem diante de você!\p"
	.string "Lugia, o Guardião dos Sete Mares,\n"
	.string "emergiu das profundezas!$"
