.set LOCALID_ENTEI, 3

Route38_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route38_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	.byte 0

Route38_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route38_EventScript_TryRemoveEntei
	end

Route38_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_ENTEI
	return

Route38_OnTransition::
	call_if_unset FLAG_CAUGHT_ENTEI, Route38_EventScript_TryShowEntei
	end

Route38_EventScript_TryShowEntei::
	clearflag FLAG_DAILY_ENTEI
	return

Route38_EventScript_Entei::
	lock
	faceplayer
	goto_if_unset FLAG_AWAKENED_BURNED_TOWER_BEASTS, Route38_EventScript_EnteiNotAwakened
	goto_if_set FLAG_CAUGHT_ENTEI, Route38_EventScript_EnteiDaily
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	msgbox Route38_Text_EnteiAppeared, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_ENTEI, 40, ITEM_CHARCOAL
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route38_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route38_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route38_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	setflag FLAG_DAILY_ENTEI
	release
	end

Route38_EventScript_EnteiDaily::
	goto_if_set FLAG_DAILY_ENTEI, Route38_EventScript_EnteiRestedDaily
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_ENTEI, 40, ITEM_CHARCOAL
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_ENTEI
	release
	end

Route38_EventScript_EnteiRestedDaily::
	msgbox Route38_Text_EnteiRested, MSGBOX_DEFAULT
	release
	end

Route38_Text_EnteiRested::
	.string "O calor do vulcão se dissipou.\n"
	.string "Entei retornará outro dia!$"

Route38_EventScript_EnteiNotAwakened::
	msgbox Route38_Text_EnteiNotAwakened, MSGBOX_DEFAULT
	release
	end

Route38_Text_EnteiNotAwakened::
	.string "Um rastro de cinzas quentes cobre o chão...\p"
	.string "Desperte as Feras Lendárias na\n"
	.string "Burned Tower de Ecruteak para\l"
	.string "desafiar Entei!$"

Route38_Text_EnteiAppeared::
	.string "As chamas ardentes de um vulcão\n"
	.string "crepitam no pasto da Rota 38!\p"
	.string "Entei, a Fera de Fogo de Johto,\n"
	.string "ruge ferozmente para você!$"

Route38_EventScript_DefeatedEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end

Route38_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end

Route38_EventScript_MoomooFarmGirl::
	lock
	faceplayer
	msgbox Route38_Text_MoomooFarmGirl, MSGBOX_DEFAULT
	giveitem ITEM_MOOMOO_MILK, 1
	release
	end

Route38_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR, 1
	release
	end

Route38_Text_MoomooFarmGirl::
	.string "Bem-vindo à Fazenda Moomoo na\n"
	.string "Rota 38/39!\p"
	.string "Nossas Miltank produzem o leite\n"
	.string "mais nutritivo de Johto. Experimente\l"
	.string "uma garrafa de Moomoo Milk!\p"
	.string "Continue subindo para chegar ao\n"
	.string "porto de Olivine City!$"
