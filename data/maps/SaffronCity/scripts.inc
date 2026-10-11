.set LOCALID_DOOR_GUARD, 1
.set LOCALID_LOOKER, 16

SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setflag FLAG_VISITED_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	call_if_set FLAG_LOOKER_POSTGAME_STARTED, CheckLookerPostgame
	end

CheckLookerPostgame::
	call_if_unset FLAG_LOOKER_POSTGAME_COMPLETED, ShowPostGameRockets
	return

ShowPostGameRockets::
	clearflag FLAG_HIDE_SILPH_POSTGAME_ROCKET
	return

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_DOOR_GUARD, 33, 31
	return

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	faceplayer
	msgbox SaffronCity_Text_ImASecurityGuard
	turnobject LOCALID_DOOR_GUARD, DIR_SOUTH
	release
	end

SaffronCity_Text_ImASecurityGuard::
    .string "Eu sou um guarda de segurança.\p"
    .string "Crianças suspeitas não passam por\n"
    .string "mim!$"

SaffronCity_EventScript_DoorGuardAsleep::
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_Text_HesTakingASnooze::
    .string "...\n"
    .string "Ronque...\p"
    .string "Haha! Ele está tirando uma soneca!$"

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_Text_WhatDoYouWantGetLost::
    .string "O que você quer?\n"
    .string "Dá o fora daqui!$"

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_BossTakeTownForTeamRocket::
    .string "O Chefe disse que vai tomar esta\n"
    .string "cidade em nome da Equipe Rocket!$"

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
    .string "Não banque o engraçadinho!\n"
    .string "Ou eu vou ter que te machucar!$"

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_SaffronBelongsToTeamRocket::
    .string "Saffron agora pertence à\n"
    .string "Equipe Rocket!$"

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
    .string "A vida no crime me faz sentir\n"
    .string "tão vivo!$"

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_Text_WatchWhereYoureWalking::
    .string "Ai!\n"
    .string "Olhe por onde anda!$"

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_Text_WeCanExploitMonsAroundWorld::
    .string "Com a Silph sob controle, podemos\n"
    .string "explorar Pokémon pelo mundo todo!\p"
    .string "Vamos ficar podres de ricos, hahah!$"


SaffronCity_EventScript_BattleGirl::
	msgbox SaffronCity_Text_HowCanClubNotRecognizeLance, MSGBOX_NPC
	release
	end

SaffronCity_Text_HowCanClubNotRecognizeLance::
    .string "Este Fã-Clube...\n"
    .string "Ninguém aqui entende nada!\p"
    .string "Como eles podem não reconhecer\n"
    .string "o brilhantismo que é o Lance?\p"
    .string "Ele luta pela justiça!\n"
    .string "Ele é maneiro e tão apaixonado!\l"
    .string "O Lance é simplesmente o maior!$"

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_YouBeatTeamRocket::
    .string "Você derrotou a Equipe Rocket\n"
    .string "completamente sozinho?\l"
    .string "Isso é impressionante!$"

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_Text_SafeToGoOutAgain::
    .string "Viva! A Equipe Rocket se foi!\n"
    .string "Já é seguro sair de novo!$"

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_Text_PeopleComingBackToSaffron::
    .string "As pessoas fugiram em massa daqui\n"
    .string "quando aqueles Rockets chegaram.\p"
    .string "Agora todos devem estar voltando\n"
    .string "para Saffron.$"

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_Text_FlewHereOnPidgeot::
    .string "Voei até aqui no meu Pidgeot assim\n"
    .string "que li as notícias sobre a Silph.\p"
    .string "Já acabou tudo?\n"
    .string "Perdi toda a comoção da mídia...$"

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_Text_Pidgeot::
    .string "Pidgeot: Bi bibii!$"

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_Text_SawRocketBossEscaping::
    .string "Eu vi o Chefe Rocket escapando\n"
    .string "do prédio da Silph.$"

SaffronCity_EventScript_GymSign::
	lockall
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_Text_GymSign::
    .string "Ginásio Pokémon de Saffron City\n"
    .string "Líder: Sabrina\l"
    .string "A Mestra dos Pokémon Psíquicos!$"

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_Text_CitySign::
    .string "Saffron City\n"
    .string "A Reluzente e Dourada Terra do Comércio$"

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Text_FightingDojo::
    .string "Dojo de Luta$"

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_TrainerFanClubSign::
    .string "Fã-Clube de Treinadores Pokémon\p"
    .string "Vários treinadores rabiscaram seus\n"
    .string "nomes nesta placa.$"

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_Text_FullHealCuresStatus::
    .string "Dicas para Treinadores:\p"
    .string "A Cura Total cura todas as condições,\n"
    .string "como queimadura, paralisia, veneno,\l"
    .string "congelamento e sono.\p"
    .string "Custa um pouco mais, mas é mais\n"
    .string "prático do que comprar vários itens.$"

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_Text_GreatBallImprovedCatchRate::
    .string "Dicas para Treinadores:\p"
    .string "A nova Grande Bola oferece uma taxa\n"
    .string "de captura aprimorada.\p"
    .string "Experimente usá-la naqueles Pokémon\n"
    .string "mais difíceis de pegar.$"

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_Text_SilphCoSign::
    .string "Sede da Silph S.A.$"

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_Text_MrPsychicsHouse::
    .string "Casa do Sr. Psíquico$"

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_Text_SilphsLatestProduct::
    .string "O mais novo produto da Silph!\n"
    .string "Lançamento a ser definido...$"

SaffronCity_EventScript_SkippedLookerScene::
	setvar VAR_SILPH_STATE, 4
	end

SaffronCity_EventScript_LookerTriggerL1::
	setobjectxyperm LOCALID_LOOKER, 24, 32
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerL2::
	setobjectxyperm LOCALID_LOOKER, 24, 33
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerL3::
	setobjectxyperm LOCALID_LOOKER, 24, 34
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR1::
	setobjectxyperm LOCALID_LOOKER, 42, 32
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR2::
	setobjectxyperm LOCALID_LOOKER, 42, 33
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR3::
	setobjectxyperm LOCALID_LOOKER, 42, 34
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_Looker::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	clearflag FLAG_HIDE_SAFFRON_CITY_LOOKER
	addobject LOCALID_LOOKER
	call_if_eq VAR_TEMP_1, 1, SaffronCity_EventScript_MoveLookerLeft
	call_if_eq VAR_TEMP_1, 2, SaffronCity_EventScript_MoveLookerRight
	waitmovement 16
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitse
	waitmovement 16
	msgbox SaffronCity_Text_ShouldntBeSurprised, MSGBOX_DEFAULT
	waitmessage
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitse
	waitmovement 16
	msgbox SaffronCity_Text_RocketBurgalars, MSGBOX_DEFAULT
	waitmessage
	call_if_eq VAR_TEMP_1, 1, SaffronCity_EventScript_MoveLookerRight
	call_if_eq VAR_TEMP_1, 2, SaffronCity_EventScript_MoveLookerLeft
	waitmovement 16
	removeobject LOCALID_LOOKER
	fadedefaultbgm
	setvar VAR_SILPH_STATE, 4
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

SaffronCity_EventScript_MoveLookerLeft::
	applymovement LOCALID_LOOKER, Movement_LookerWalksRight
	return

Movement_LookerWalksRight::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SaffronCity_EventScript_MoveLookerRight::
	applymovement LOCALID_LOOKER, Movement_LookerWalksLeft
	return

Movement_LookerWalksLeft::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SaffronCity_Text_ShouldntBeSurprised::
	.string "Looker: Muito bem, vamos estabelecer\n"
	.string "um perímetro... Ah! {PLAYER}!\p"
	.string "Acabamos de encurralar os recrutas\n"
	.string "da Equipe Rocket que aterrorizavam os\l"
	.string "cidadãos. É hora de invadir o prédio\l"
	.string "da Silph S.A. e deter o Chefe deles!\p"
	.string "Aqueles Planos Rocket que você trouxe\n"
	.string "foram muito úteis, mas preciso que\l"
	.string "você se afaste agora e deixe os\l"
	.string "adultos cuidarem disso!\p"
	.string "...\p"
	.string "Você o quê?!\p"
	.string "Você já derrotou os Rockets dentro da\n"
	.string "Silph S.A. e resgatou o Presidente?\p"
	.string "Isso é incrível, mas muito imprudente!\p"
	.string "Espere...\n"
	.string "E quanto ao Chefe da Equipe Rocket?\p"
	.string "Ele fugiu? De novo? Droga!\p"
	.string "Derrubamos todas as bases Rocket que\n"
	.string "encontramos e o perseguimos por Kanto.\p"
	.string "Não devem restar muitos esconderijos\n"
	.string "para ele.\p"
	.string "Mas ainda não temos pistas!\n"
	.string "Terei que continuar minha investigação.$"

SaffronCity_Text_RocketBurgalars:
	.string "Looker: Desculpe, {PLAYER}.\n"
	.string "Acabei de ser informado de que havia\l"
	.string "alguns sujeitos suspeitos tentando\l"
	.string "invadir o Esconderijo Rocket agora\l"
	.string "abandonado sob o Cassino.\p"
	.string "Por mais que eu adorasse averiguar,\n"
	.string "não vejo por que um Rocket precisaria\l"
	.string "arrombar o seu próprio esconderijo.\p"
	.string "...\p"
	.string "Você é um treinador e tanto.\n"
	.string "Apenas tome muito cuidado se for dar\l"
	.string "uma olhada por lá, por favor.$"
