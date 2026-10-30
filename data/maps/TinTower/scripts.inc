.set LOCALID_HO_OH, 1

TinTower_MapScripts::
	.byte 0

TinTower_EventScript_HoOh::
	lock
	faceplayer
	goto_if_unset FLAG_CLEARED_GOLDENROD_RADIO_TOWER, TinTower_EventScript_HoOhNeedsBell
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	msgbox TinTower_Text_HoOhAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_HO_OH, 70, ITEM_SACRED_ASH
	dowildbattle
	removeobject LOCALID_HO_OH
	setflag FLAG_CAUGHT_TIN_TOWER_HO_OH
	release
	end

TinTower_EventScript_HoOhNeedsBell::
	msgbox TinTower_Text_HoOhNeedsBell, MSGBOX_DEFAULT
	release
	end

TinTower_EventScript_Elder::
	msgbox TinTower_Text_Elder, MSGBOX_NPC
	end

TinTower_Text_HoOhNeedsBell::
	.string "Uma aura dourada envolve o topo\n"
	.string "da Tin Tower...\p"
	.string "Liberte a Torre de Rádio de\n"
	.string "Goldenrod para provar sua pureza\l"
	.string "perante Ho-Oh!$"

TinTower_Text_HoOhAppeared::
	.string "As penas arco-íris brilham sob o\n"
	.string "sol de Ecruteak!\p"
	.string "O lendário Ho-Oh desceu dos céus\n"
	.string "no topo da Tin Tower!$"

TinTower_Text_Elder::
	.string "Apenas treinadores que salvaram a\n"
	.string "Torre de Rádio de Johto possuem a\l"
	.string "bênção para desafiar Ho-Oh!$"
