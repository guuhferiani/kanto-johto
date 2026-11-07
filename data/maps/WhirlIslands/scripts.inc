.set LOCALID_LUGIA, 1

WhirlIslands_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, WhirlIslands_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, WhirlIslands_OnTransition
	.byte 0

WhirlIslands_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, WhirlIslands_EventScript_TryRemoveLugia
	end

WhirlIslands_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_LUGIA
	return

WhirlIslands_OnTransition::
	call_if_unset FLAG_CAUGHT_WHIRL_ISLANDS_LUGIA, WhirlIslands_EventScript_TryShowLugia
	end

WhirlIslands_EventScript_TryShowLugia::
	clearflag FLAG_DAILY_LUGIA
	return

WhirlIslands_EventScript_Lugia::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_LEADER_CHUCK, WhirlIslands_EventScript_LugiaSleeping
	goto_if_set FLAG_CAUGHT_WHIRL_ISLANDS_LUGIA, WhirlIslands_EventScript_LugiaDaily
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	msgbox WhirlIslands_Text_LugiaAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_LUGIA, 70, ITEM_MYSTIC_WATER
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslands_EventScript_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslands_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, WhirlIslands_EventScript_RanFromLugia
	setflag FLAG_CAUGHT_WHIRL_ISLANDS_LUGIA
	setflag FLAG_DAILY_LUGIA
	release
	end

WhirlIslands_EventScript_LugiaDaily::
	goto_if_set FLAG_DAILY_LUGIA, WhirlIslands_EventScript_LugiaSleepingDaily
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LUGIA, 70, ITEM_MYSTIC_WATER
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_LUGIA
	release
	end

WhirlIslands_EventScript_LugiaSleepingDaily::
	msgbox WhirlIslands_Text_LugiaRested, MSGBOX_DEFAULT
	release
	end

WhirlIslands_Text_LugiaRested::
	.string "Lugia está descansando nas águas profundas.\n"
	.string "Volte outro dia!$"

WhirlIslands_EventScript_DefeatedLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

WhirlIslands_EventScript_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
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
