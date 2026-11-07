.set LOCALID_HO_OH, 1

TinTower_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TinTower_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TinTower_EventScript_TryRemoveHoOh
	end

TinTower_EventScript_TryRemoveHoOh::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_HO_OH
	return

TinTower_OnTransition::
	call_if_unset FLAG_CAUGHT_TIN_TOWER_HO_OH, TinTower_EventScript_TryShowHoOh
	end

TinTower_EventScript_TryShowHoOh::
	clearflag FLAG_DAILY_HO_OH
	return

TinTower_EventScript_HoOh::
	lock
	faceplayer
	goto_if_unset FLAG_CLEARED_GOLDENROD_RADIO_TOWER, TinTower_EventScript_HoOhNeedsBell
	goto_if_set FLAG_CAUGHT_TIN_TOWER_HO_OH, TinTower_EventScript_HoOhDaily
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	msgbox TinTower_Text_HoOhAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_HO_OH, 70, ITEM_SACRED_ASH
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TinTower_EventScript_DefeatedHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TinTower_EventScript_RanFromHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TinTower_EventScript_RanFromHoOh
	setflag FLAG_CAUGHT_TIN_TOWER_HO_OH
	setflag FLAG_DAILY_HO_OH
	release
	end

TinTower_EventScript_HoOhDaily::
	goto_if_set FLAG_DAILY_HO_OH, TinTower_EventScript_HoOhRestedDaily
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HO_OH, 70, ITEM_SACRED_ASH
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_HO_OH
	release
	end

TinTower_EventScript_HoOhRestedDaily::
	msgbox TinTower_Text_HoOhRested, MSGBOX_DEFAULT
	release
	end

TinTower_Text_HoOhRested::
	.string "Ho-Oh repousa sob a luz do céu.\n"
	.string "Volte outro dia!$"

TinTower_EventScript_DefeatedHoOh::
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
	end

TinTower_EventScript_RanFromHoOh::
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
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
