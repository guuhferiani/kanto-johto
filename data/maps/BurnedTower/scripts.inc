.set LOCALID_BEASTS, 2

BurnedTower_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BurnedTower_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_OnTransition
	.byte 0

BurnedTower_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BurnedTower_EventScript_TryRemoveSuicune
	end

BurnedTower_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_BEASTS
	return

BurnedTower_OnTransition::
	call_if_unset FLAG_CAUGHT_SUICUNE, BurnedTower_EventScript_TryShowSuicune
	end

BurnedTower_EventScript_TryShowSuicune::
	clearflag FLAG_DAILY_SUICUNE
	return

BurnedTower_EventScript_Eusine::
	lock
	faceplayer
	goto_if_set FLAG_AWAKENED_BURNED_TOWER_BEASTS, BurnedTower_EventScript_EusineAfter
	msgbox BurnedTower_Text_EusineIntro, MSGBOX_DEFAULT
	release
	end

BurnedTower_EventScript_EusineAfter::
	msgbox BurnedTower_Text_EusineAfter, MSGBOX_DEFAULT
	release
	end

BurnedTower_EventScript_BeastsAltar::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_SUICUNE, BurnedTower_EventScript_SuicuneDaily
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	msgbox BurnedTower_Text_BeastsAwaken, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 40, ITEM_MYSTIC_WATER
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_AWAKENED_BURNED_TOWER_BEASTS
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BurnedTower_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BurnedTower_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BurnedTower_EventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	setflag FLAG_DAILY_SUICUNE
	msgbox BurnedTower_Text_RaikouEnteiRoam, MSGBOX_DEFAULT
	release
	end

BurnedTower_EventScript_SuicuneDaily::
	goto_if_set FLAG_DAILY_SUICUNE, BurnedTower_EventScript_SuicuneRestedDaily
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 40, ITEM_MYSTIC_WATER
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_DAILY_SUICUNE
	release
	end

BurnedTower_EventScript_SuicuneRestedDaily::
	msgbox BurnedTower_Text_SuicuneRested, MSGBOX_DEFAULT
	release
	end

BurnedTower_Text_SuicuneRested::
	.string "O altar está sereno com águas límpidas.\n"
	.string "Suicune retornará outro dia!$"

BurnedTower_EventScript_DefeatedSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	msgbox BurnedTower_Text_RaikouEnteiRoam, MSGBOX_DEFAULT
	goto Common_EventScript_LegendaryFlewAway
	end

BurnedTower_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	msgbox BurnedTower_Text_RaikouEnteiRoam, MSGBOX_DEFAULT
	goto Common_EventScript_LegendaryFlewAway
	end

BurnedTower_Text_EusineIntro::
	.string "Eusine: Meu nome é Eusine!\n"
	.string "Estou buscando o lendário Suicune\l"
	.string "por toda Johto!\p"
	.string "Olhe no altar à frente: as três\n"
	.string "Feras Lendárias ressuscitadas por\l"
	.string "Ho-Oh estão prestes a despertar!$"

BurnedTower_Text_BeastsAwaken::
	.string "Raikou e Entei dispararam como\n"
	.string "relâmpago e fogo pelas rotas de\l"
	.string "Johto!\p"
	.string "Mas Suicune permaneceu diante de\n"
	.string "você para testar sua coragem!$"

BurnedTower_Text_RaikouEnteiRoam::
	.string "Raikou e Entei agora percorrem as\n"
	.string "rotas selvagens de Johto (Rota 36\l"
	.string "e Rota 38)!$"

BurnedTower_Text_EusineAfter::
	.string "Eusine: Magnífico! Suicune reconheceu\n"
	.string "seu valor na Burned Tower, e agora\l"
	.string "Raikou e Entei correm livres pelas\l"
	.string "rotas de Johto!$"
