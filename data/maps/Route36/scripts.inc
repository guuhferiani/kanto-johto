.set LOCALID_SUDOWOODO, 1
.set LOCALID_RAIKOU, 3

Route36_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route36_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	.byte 0

Route36_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route36_EventScript_TryRemoveMon
	end

Route36_EventScript_TryRemoveMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Route36_OnTransition::
	call_if_unset FLAG_CAUGHT_ROUTE36_SUDOWOODO, Route36_EventScript_TryShowSudowoodo
	call_if_unset FLAG_CAUGHT_RAIKOU, Route36_EventScript_TryShowRaikou
	end

Route36_EventScript_TryShowSudowoodo::
	clearflag FLAG_DAILY_SUDOWOODO
	return

Route36_EventScript_TryShowRaikou::
	clearflag FLAG_DAILY_RAIKOU
	return

Route36_EventScript_Raikou::
	lock
	faceplayer
	goto_if_unset FLAG_AWAKENED_BURNED_TOWER_BEASTS, Route36_EventScript_RaikouNotAwakened
	goto_if_set FLAG_CAUGHT_RAIKOU, Route36_EventScript_RaikouDaily
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	msgbox Route36_Text_RaikouAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 40, ITEM_MAGNET
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_DefeatedRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanFromRaikou
	setflag FLAG_CAUGHT_RAIKOU
	setflag FLAG_DAILY_RAIKOU
	release
	end

Route36_EventScript_RaikouDaily::
	goto_if_set FLAG_DAILY_RAIKOU, Route36_EventScript_RaikouRestedDaily
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 40, ITEM_MAGNET
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_RAIKOU
	release
	end

Route36_EventScript_RaikouRestedDaily::
	msgbox Route36_Text_RaikouRested, MSGBOX_DEFAULT
	release
	end

Route36_Text_RaikouRested::
	.string "Raikou correu como um relâmpago.\n"
	.string "Ele retornará outro dia!$"

Route36_EventScript_RaikouNotAwakened::
	msgbox Route36_Text_RaikouNotAwakened, MSGBOX_DEFAULT
	release
	end

Route36_Text_RaikouNotAwakened::
	.string "O trovão ruge ao longe nas colinas\n"
	.string "de Johto...\p"
	.string "Desperte as Feras Lendárias na\n"
	.string "Burned Tower de Ecruteak para\l"
	.string "enfrentar Raikou!$"

Route36_Text_RaikouAppeared::
	.string "Trovões ensurdecedores cortam o céu\n"
	.string "da Rota 36!\p"
	.string "Raikou, a Fera do Trovão de Johto,\n"
	.string "surgiu diante de você!$"

Route36_EventScript_DefeatedRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end

Route36_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end

Route36_EventScript_Sudowoodo::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_LEADER_WHITNEY, Route36_EventScript_WeirdTree
	goto_if_set FLAG_CAUGHT_ROUTE36_SUDOWOODO, Route36_EventScript_SudowoodoDaily
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	msgbox Route36_Text_SudowoodoAttacked, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_SUDOWOODO, 40, ITEM_HARD_STONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanFromSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanFromSudowoodo
	setflag FLAG_CAUGHT_ROUTE36_SUDOWOODO
	setflag FLAG_DAILY_SUDOWOODO
	release
	end

Route36_EventScript_SudowoodoDaily::
	goto_if_set FLAG_DAILY_SUDOWOODO, Route36_EventScript_SudowoodoRestedDaily
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_SUDOWOODO, 40, ITEM_HARD_STONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_SUDOWOODO
	release
	end

Route36_EventScript_SudowoodoRestedDaily::
	msgbox Route36_Text_SudowoodoRested, MSGBOX_DEFAULT
	release
	end

Route36_Text_SudowoodoRested::
	.string "A árvore está imóvel se camuflando.\n"
	.string "Volte outro dia!$"

Route36_EventScript_DefeatedSudowoodo::
	setvar VAR_0x8004, SPECIES_SUDOWOODO
	goto Common_EventScript_LegendaryFlewAway
	end

Route36_EventScript_RanFromSudowoodo::
	setvar VAR_0x8004, SPECIES_SUDOWOODO
	goto Common_EventScript_LegendaryFlewAway
	end

Route36_EventScript_WeirdTree::
	msgbox Route36_Text_WeirdTree, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_Florist::
	msgbox Route36_Text_Florist, MSGBOX_NPC
	end

Route36_EventScript_RouteSign::
	msgbox Route36_Text_RouteSign, MSGBOX_SIGN
	end

Route36_Text_WeirdTree::
	.string "Uma árvore estranha bloqueia a\n"
	.string "passagem para Ecruteak City!\p"
	.string "Conquiste a Insígnia da Planície\n"
	.string "no Ginásio de Whitney para ganhar\l"
	.string "o regador e despertá-la!$"

Route36_Text_SudowoodoAttacked::
	.string "Você borrifou água na árvore\n"
	.string "estranha!\p"
	.string "A árvore se contorceu furiosa!\n"
	.string "É um Sudowoodo selvagem!$"

Route36_Text_Florist::
	.string "Aquela árvore esquisita na verdade\n"
	.string "é um Pokémon do tipo Pedra que\l"
	.string "detesta água!\p"
	.string "Depois de passar por ela, atravesse\n"
	.string "o portão para chegar à histórica\l"
	.string "Ecruteak City!$"

Route36_Text_RouteSign::
	.string "ROTA 36 & 37\n"
	.string "Leste: Goldenrod City\l"
	.string "Portão Oeste: Ecruteak City$"
