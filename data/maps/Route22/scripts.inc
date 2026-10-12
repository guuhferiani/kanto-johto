.set LOCALID_RIVAL, 1
.set LOCALID_FUGITIVE, 2

Route22_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, Route22_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route22_OnResume
	.byte 0

Route22_OnReturnToField:
	call_if_eq VAR_ROUTE_22_RIVAL_STATE, 2, Route22_EventScript_HealAfterRivalBattle
	end

Route22_EventScript_HealAfterRivalBattle::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	setvar VAR_ROUTE_22_RIVAL_STATE, 3
	end

Route22_OnTransition:
	goto_if_unset FLAG_BADGE08_GET, Route22_HideMandatory
	call Common_EventScript_GetDayOrNight
	end

Route22_HideMandatory:
	removeobject 3
	call Common_EventScript_GetDayOrNight
	end

Route22_OnResume:
	goto_if_unset FLAG_BADGE08_GET, Route22_HideMandatory
	call Common_EventScript_GetDayOrNight
	end

Route22_EventScript_EarlyRivalTriggerTop::
	setobjectxyperm LOCALID_RIVAL, 33, 4
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerMiddle::
	setobjectxyperm LOCALID_RIVAL, 33, 5
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerBottom::
	setobjectxyperm LOCALID_RIVAL, 33, 6
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRival::
	setvar VAR_ROUTE_22_RIVAL_STATE, 2
	clearflag FLAG_HIDE_RIVAL_ROUTE_22
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Movement_RivalApproach
	waitmovement 1
	delay 6
	trainerbattle_no_whiteout_continue_script TRAINER_RIVAL_OPTIONAL_BATTLE, Route22_Text_EarlyRivalIntro, Route22_Text_EarlyRivalDefeated, Route22_EventScript_RivalBattleOutcome
	end

Route22_Text_EarlyRivalIntro::
	.string "{RIVAL}: Ei! {PLAYER}!\p"
	.string "Esta indo para a Liga Pokemon?\n"
	.string "Pode esquecer!\p"
	.string "Voce provavelmente nao tem nenhuma\n"
	.string "Insignia, tem?\p"
	.string "O guarda nao vai te deixar passar\n"
	.string "sem elas.\p"
	.string "A proposito, seus Pokemon ficaram\n"
	.string "mais fortes?$"

Route22_Text_EarlyRivalDefeated::
	.string "Ahhh!\n"
	.string "Voce so deu sorte!$"

Route22_EventScript_RivalBattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route22_EventScript_EarlyRivalBattleWon
	goto Route22_EventScript_EarlyRivalBattleLost

Route22_EventScript_EarlyRivalBattleWon::
	addvar VAR_RIVAL_WINRATE, 1
	goto Route22_EventScript_EarlyRivalPostBattle
	
Route22_EventScript_EarlyRivalBattleLost::
	msgbox Route22_Text_EarlyRivalVictory, MSGBOX_DEFAULT
	goto Route22_EventScript_EarlyRivalPostBattle

Route22_Text_EarlyRivalVictory:
	.string "{RIVAL}: Hahaha! {PLAYER}!\p"
	.string "Esse e o seu melhor? Voce nem chega\n"
	.string "perto do meu nivel, amigo!\p"
	.string "Va treinar mais! Seu perdedor!$"

Route22_EventScript_EarlyRivalPostBattle::
	msgbox Route22_Text_EarlyRivalPostBattle, MSGBOX_DEFAULT
	playbgm MUS_RG_RIVAL_EXIT, 0
	applymovement LOCALID_RIVAL, Movement_RivalExit
	waitmovement 1
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RIVAL_ROUTE_22
	releaseall
	end

Route22_Text_EarlyRivalPostBattle::
	.string "Ouvi dizer que a Liga Pokemon esta\n"
	.string "cheia de Treinadores cascas-grossas.\p"
	.string "Tenho que descobrir como passar\n"
	.string "por eles.\p"
	.string "Voce devia parar de enrolar e se\n"
	.string "mexer!$"

Movement_RivalApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_RivalExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route22_EventScript_MandatoryRival::
	lock
	faceplayer
	goto_if_eq VAR_RIVAL_WINRATE, 2, Route22_EventScript_LateRival_Jolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, Route22_EventScript_LateRival_Flareon
	goto Route22_EventScript_LateRival_Vaporeon
	end

Route22_EventScript_LateRival_Jolteon::
	trainerbattle_single TRAINER_RIVAL_ROUTE22_JOLTEON, Route22_Text_LateRivalIntro, Route22_Text_LateRivalDefeat
	goto Route22_EventScript_LateRivalPostBattle

Route22_EventScript_LateRival_Flareon::
	trainerbattle_single TRAINER_RIVAL_ROUTE22_FLAREON, Route22_Text_LateRivalIntro, Route22_Text_LateRivalDefeat
	goto Route22_EventScript_LateRivalPostBattle

Route22_EventScript_LateRival_Vaporeon::
	trainerbattle_single TRAINER_RIVAL_ROUTE22_VAPOREON, Route22_Text_LateRivalIntro, Route22_Text_LateRivalDefeat
	goto Route22_EventScript_LateRivalPostBattle

Route22_Text_LateRivalIntro::
	.string "{RIVAL}: Ei! {PLAYER}!\p"
	.string "Que surpresa ver voce por aqui!\p"
	.string "Entao esta a caminho da Liga Pokemon?\p"
	.string "Conseguiu todas as Insignias tambem?\n"
	.string "Que legal!\p"
	.string "Entao vou te dar uma surra, {PLAYER},\n"
	.string "como aquecimento para a Liga! Vamos la!$" 

Route22_Text_LateRivalDefeat::
	.string "O que!?\p"
	.string "Eu fui apenas descuidado!$"

Route22_EventScript_LateRivalPostBattle::
	playbgm MUS_RG_RIVAL_EXIT, 0
	msgbox Route22_Text_LateRivalPostBattle, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject 3
	setflag FLAG_HIDE_RIVAL22_MANDATORY
	setvar VAR_ROUTE_22_RIVAL_STATE, 5
	fadescreen FADE_FROM_BLACK
	goto_if_set FLAG_BILL4CALLED, Common_EventScript_End
	pokenavcall MatchCall_Text_Bill4
	waitmessage
	setflag FLAG_BILL4CALLED
	release
	end

Route22_Text_LateRivalPostBattle::
	.string "Isso serviu para me aquecer.\n"
	.string "Estou pronto para a Liga Pokemon!\p"
	.string "{PLAYER}, voce precisa praticar mais.\p"
	.string "Mas ei, voce sabe disso!\n"
	.string "Fui nessa. Ate mais, perdedor!$"

Route22_EventScript_LeagueGateSign::
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
	end

Route22_Text_LeagueGateSign::
	.string "Liga Pokemon\n"
	.string "Portao Principal$"

Route22_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end

Movement_MandatoryExit:
	walk_up
	step_end
