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
	goto_if_set FLAG_UNLOCKED_JOHTO_JOURNEY, Route22_NorthEntrance_JohtoAuthorized
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

Route22_NorthEntrance_JohtoAuthorized::
	msgbox Route22_NorthEntrance_Text_JohtoAuthorized, MSGBOX_NPC
	release
	end

Route22_NorthEntrance_Text_JohtoAuthorized::
	.string "Saudacoes, Campeao {PLAYER}!\p"
	.string "O Professor Carvalho enviou a sua\n"
	.string "autorizacao oficial para Johto!\p"
	.string "A rota ao sul pela Rota 26 e Rota 27\n"
	.string "(Cachoeiras de Tohjo) esta liberada.\p"
	.string "Tenha uma viagem triunfal rumo a\n"
	.string "regiao de Johto!$"

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

Route22_NorthEntrance_EventScript_JohtoGuard::
	lock
	faceplayer
	goto_if_set FLAG_UNLOCKED_JOHTO_JOURNEY, Route22_NorthEntrance_JohtoGuardAuthorized
	msgbox Route22_NorthEntrance_Text_JohtoGuardLocked, MSGBOX_DEFAULT
	release
	end

Route22_NorthEntrance_JohtoGuardAuthorized::
	msgbox Route22_NorthEntrance_Text_JohtoGuardAskTravel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route22_NorthEntrance_WarpToRoute27
	msgbox Route22_NorthEntrance_Text_JohtoGuardDecline, MSGBOX_DEFAULT
	release
	end

Route22_NorthEntrance_WarpToRoute27::
	msgbox Route22_NorthEntrance_Text_JohtoGuardDepart, MSGBOX_DEFAULT
	closemessage
	warp MAP_ROUTE27, 16, 6
	waitstate
	release
	end

Route22_NorthEntrance_Text_JohtoGuardLocked::
	.string "Ola, treinador!\p"
	.string "Este posto alfandegario controla o acesso\n"
	.string "a fronteira com a regiao de Johto\l"
	.string "(Rota 27 e Cachoeiras de Tohjo).\p"
	.string "A passagem so e permitida a treinadores\n"
	.string "que venceram a Liga Pokemon e possuem\l"
	.string "o passe oficial do Professor Carvalho!$"

Route22_NorthEntrance_Text_JohtoGuardAskTravel::
	.string "Saudacoes, Campeao {PLAYER}!\p"
	.string "Seu passe de fronteira do Professor\n"
	.string "Carvalho foi confirmado no sistema!\p"
	.string "A Rota 27 e o caminho de Johto estao\n"
	.string "totalmente abertos para voce.\p"
	.string "Deseja atravessar os portoes para a\n"
	.string "Rota 27 agora?$"

Route22_NorthEntrance_Text_JohtoGuardDepart::
	.string "Excelente! Boa jornada na regiao de Johto,\n"
	.string "Campeao {PLAYER}!$"

Route22_NorthEntrance_Text_JohtoGuardDecline::
	.string "Muito bem! O portao permanecera aberto\n"
	.string "quando estiver pronto.$"


