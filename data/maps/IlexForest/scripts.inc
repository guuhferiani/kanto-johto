.set LOCALID_CELEBI, 1

IlexForest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IlexForest_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
	.byte 0

IlexForest_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IlexForest_EventScript_TryRemoveCelebi
	end

IlexForest_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_CELEBI
	return

IlexForest_OnTransition::
	call_if_unset FLAG_CAUGHT_ILEX_CELEBI, IlexForest_EventScript_TryShowCelebi
	end

IlexForest_EventScript_TryShowCelebi::
	clearflag FLAG_DAILY_CELEBI
	return

IlexForest_EventScript_CelebiShrine::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_LEADER_BUGSY, IlexForest_EventScript_ShrineQuiet
	goto_if_set FLAG_CAUGHT_ILEX_CELEBI, IlexForest_EventScript_CelebiDaily
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	msgbox IlexForest_Text_CelebiAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_CELEBI, 50, ITEM_MIRACLE_SEED
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IlexForest_EventScript_DefeatedCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IlexForest_EventScript_RanFromCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IlexForest_EventScript_RanFromCelebi
	setflag FLAG_CAUGHT_ILEX_CELEBI
	setflag FLAG_DAILY_CELEBI
	release
	end

IlexForest_EventScript_CelebiDaily::
	goto_if_set FLAG_DAILY_CELEBI, IlexForest_EventScript_CelebiRestedDaily
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_CELEBI, 50, ITEM_MIRACLE_SEED
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_CELEBI
	release
	end

IlexForest_EventScript_CelebiRestedDaily::
	msgbox IlexForest_Text_CelebiRested, MSGBOX_DEFAULT
	release
	end

IlexForest_Text_CelebiRested::
	.string "O Santuário está silencioso.\n"
	.string "Celebi está viajando pelas eras do tempo!$"

IlexForest_EventScript_DefeatedCelebi::
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end

IlexForest_EventScript_RanFromCelebi::
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end

IlexForest_EventScript_ShrineQuiet::
	msgbox IlexForest_Text_ShrineQuiet, MSGBOX_DEFAULT
	release
	end

IlexForest_EventScript_CharcoalApprentice::
	msgbox IlexForest_Text_CharcoalApprentice, MSGBOX_NPC
	end

IlexForest_EventScript_ForestGuide::
	msgbox IlexForest_Text_ForestGuide, MSGBOX_NPC
	end

IlexForest_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

IlexForest_EventScript_SouthSign::
	msgbox IlexForest_Text_SouthSign, MSGBOX_SIGN
	end

IlexForest_EventScript_ShrineSign::
	msgbox IlexForest_Text_ShrineSign, MSGBOX_SIGN
	end

IlexForest_EventScript_NorthSign::
	msgbox IlexForest_Text_NorthSign, MSGBOX_SIGN
	end

IlexForest_Text_ShrineQuiet::
	.string "É o antigo Santuário da Floresta\n"
	.string "Ilex...\p"
	.string "Uma presença mística observa você.\n"
	.string "Conquiste a Insígnia da Colmeia em\l"
	.string "Azalea Town para provar seu valor!$"

IlexForest_Text_CelebiAppeared::
	.string "O Santuário da Floresta Ilex brilha\n"
	.string "com uma luz esmeralda atemporal!\p"
	.string "Celebi, o Guardião da Floresta,\n"
	.string "viajou através do tempo para\l"
	.string "testar sua força!$"

IlexForest_Text_CharcoalApprentice::
	.string "As árvores da Floresta Ilex são tão\n"
	.string "densas que mal deixam a luz do sol\l"
	.string "passar.\p"
	.string "No centro da mata fica o Santuário\n"
	.string "do Guardião Celebi!$"

IlexForest_Text_ForestGuide::
	.string "Esta saída ao norte leva direto\n"
	.string "para a Rota 34 e Goldenrod City!$"

IlexForest_Text_SouthSign::
	.string "FLORESTA ILEX\n"
	.string "Sul: Azalea Town\l"
	.string "Norte: Rota 34 & Goldenrod City$"

IlexForest_Text_ShrineSign::
	.string "SANTUÁRIO DA FLORESTA ILEX\n"
	.string "Erguido em honra ao Guardião do\l"
	.string "Tempo e protetor das matas.$"

IlexForest_Text_NorthSign::
	.string "SAÍDA NORTE DA FLORESTA ILEX\n"
	.string "Siga em frente para a Rota 34 e\l"
	.string "Goldenrod City.$"
