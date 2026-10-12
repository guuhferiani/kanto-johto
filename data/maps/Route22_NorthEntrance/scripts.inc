.set LOCALID_GUARD, 1

Route22_NorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_NorthEntrance_OnTransition
	.byte 0

Route22_NorthEntrance_OnTransition::
	goto_if_set FLAG_BADGE08_GET, Route22_NorthEntrance_MoveGateGuard
	end

Route22_NorthEntrance_MoveGateGuard::
	setobjectxyperm LOCALID_GUARD, 8, 2
	end

Route22_NorthEntrance_EventScript_GateGuard::
	goto_if_set FLAG_BADGE08_GET,  Route22_NorthEntrance_HeadToVictoryRoad
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_GUARD, Common_Movement_QuestionMark
	waitmovement 1
	waitse
	msgbox Route22_NorthEntrance_Text_Collect8Badges, MSGBOX_NPC
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

Route22_NorthEntrance_Text_Collect8Badges::
	.string "Oh? Voce quer ir para o Indigo\n"
	.string "Plateau?\p"
	.string "Sinto muito, nao posso deixar passar\n"
	.string "a menos que tenha conquistado todas\l"
	.string "as 8 Insignias de Ginasio.$"

Route22_NorthEntrance_HeadToVictoryRoad::
	msgbox Route22_NorthEntrance_Text_HeadToVictoryRoad, MSGBOX_NPC
	release
	end

Route22_NorthEntrance_Text_HeadToVictoryRoad::
	.string "Voce encontrara a Victory Road no fim\n"
	.string "da Rota 23.\p"
	.string "Ela esta repleta de treinadores de\n"
	.string "elite e Pokemon fortes.\p"
	.string "E o seu teste final antes de enfrentar\n"
	.string "a Elite dos Quatro!$"

