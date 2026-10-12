.set LOCALID_RIVAL,     2
.set LOCALID_WORKER_M2, 6

SilphCo_7F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_LaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_LaprasPC
	goto_if_eq VAR_RESULT, 2, SilphCo_7F_EventScript_NoRoomForLapras
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_LaprasParty::
	call SilphCo_7F_EventScript_GetLapras
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_GotLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_GotLapras
	end

SilphCo_7F_EventScript_GetLapras::
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_EventScript_Text_TakeCareOfLapras
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	return

SilphCo_7F_EventScript_Text_TakeCareOfLapras::
	.string "{PLAYER} recebeu o Lapras do\n"
	.string "cientista da Silph S.A.!$"

SilphCo_7F_EventScript_GotLapras::
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_LaprasPC::
	call SilphCo_7F_EventScript_GetLapras
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_TransferLapras
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_TransferLapras
	end

SilphCo_7F_EventScript_TransferLapras::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_GotLapras
	end

SilphCo_7F_EventScript_NoRoomForLapras::
	msgbox SilphCo_7F_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

SilphCo_7F_Text_NoRoomForMorePokemon::
	.string "Oh! Você não tem espaço para mais\n"
	.string "nenhum Pokémon!"

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 2
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	call_if_eq VAR_RIVAL_WINRATE, 2, SilphCo_7F_EventScript_RivalJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, SilphCo_7F_EventScript_RivalFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, SilphCo_7F_EventScript_RivalVaporeon
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	waitse
	setvar VAR_SILPH_STATE, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 2
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalJolteon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CO_JOLTEON, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalFlareon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CO_FLAREON, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalVaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CO_VAPOREON, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 2
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 2
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end



SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_7F_EventScript_WorkerM1RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsBack::
	msgbox SilphCo_7F_Text_WorkerM1RocketsBack
	release
	end
	
SilphCo_7F_Text_WorkerM1RocketsBack:
	.string "Eles não podem estar atrás da Master\n"
	.string "Ball desta vez, então por que invadir?$"

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_7F_EventScript_WorkerM2RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsBack::
	msgbox SilphCo_7F_Text_WorkerM2RocketsBack
	release
	end

SilphCo_7F_Text_WorkerM2RocketsBack:
	.string "Se isso virar rotina por aqui,\n"
	.string "teremos que nos perguntar por que\l"
	.string "ainda pagamos os Seguranças.$"

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_7F_EventScript_WorkerFRocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsBack::
	msgbox SilphCo_7F_Text_WorkerFRocketsBack
	release
	end

SilphCo_7F_Text_WorkerFRocketsBack:
	.string "Mais um dia no paraíso...$"

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
    .string "Oh! Olá! Você não é da Equipe Rocket!\n"
    .string "Você veio nos salvar?\l"
    .string "Puxa, muito obrigado!\p"
    .string "Quero que fique com este Pokémon\n"
    .string "por ter nos resgatado.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
    .string "{PLAYER} obteve um LAPRAS do\n"
    .string "funcionário da Silph!$"

SilphCo_7F_Text_ExplainLapras::
    .string "É um Lapras.\n"
    .string "É um Pokémon muito inteligente.\p"
    .string "Nós o mantínhamos em nosso laboratório,\n"
    .string "mas ele ficará muito melhor com você.\p"
    .string "Acho que você será um ótimo treinador\n"
    .string "para o Lapras!\p"
    .string "Ele é um excelente nadador.\n"
    .string "Ele pode te levar pelas águas!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
    .string "O Chefe da Equipe Rocket foi para a\n"
    .string "sala da diretoria!\p"
    .string "O Presidente está bem?\n"
    .string "Estou preocupado.$"

SilphCo_7F_Text_RocketsAfterMasterBall::
    .string "A Equipe Rocket estava atrás da Master\n"
    .string "Ball, que captura qualquer Pokémon.$"

SilphCo_7F_Text_CanceledMasterBallProject::
    .string "Nós cancelamos o projeto da Master\n"
    .string "Ball por causa da Equipe Rocket.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
    .string "Seria terrível se a Equipe Rocket\n"
    .string "tomasse a Silph ou nossos Pokémon.$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
    .string "Uau!\p"
    .string "Você expulsou a Equipe Rocket\n"
    .string "completamente sozinho?$"

SilphCo_7F_Text_ReallyDangerousHere::
    .string "Você!\n"
    .string "É muito perigoso aqui!\p"
    .string "Você veio me salvar?\n"
    .string "Não pode ser!$"

SilphCo_7F_Text_ThankYouSoMuch::
    .string "Muito obrigada!$"

SilphCo_7F_Text_Grunt3Intro::
    .string "Opa!\n"
    .string "Sinto cheiro de um ratinho!$"

SilphCo_7F_Text_Grunt3Defeat::
    .string "Apagaram minhas luzes!$"

SilphCo_7F_Text_Grunt3PostBattle::
    .string "Você não vai achar meu Chefe apenas\n"
    .string "correndo por aí feito barata tonta!$"

SilphCo_7F_Text_JoshuaIntro::
    .string "Heheh!\p"
    .string "Você me confundiu com um funcionário?$"

SilphCo_7F_Text_JoshuaDefeat::
    .string "Já era!$"

SilphCo_7F_Text_JoshuaPostBattle::
    .string "Apesar da sua idade, você é um\n"
    .string "treinador muito habilidoso!$"

SilphCo_7F_Text_Grunt1Intro::
    .string "Eu sou um dos quatro Irmãos Rocket!$"

SilphCo_7F_Text_Grunt1Defeat::
    .string "Aaargh!\n"
    .string "Irmãos, eu perdi!$"

SilphCo_7F_Text_Grunt1PostBattle::
    .string "Não importa.\n"
    .string "Meus irmãos vão retribuir o favor!$"

SilphCo_7F_Text_Grunt2Intro::
    .string "Uma criança invasora?\n"
    .string "Só pode ser você!$"

SilphCo_7F_Text_Grunt2Defeat::
    .string "Está bem!\n"
    .string "Eu perdi!$"

SilphCo_7F_Text_Grunt2PostBattle::
    .string "Vá para casa antes que o meu Chefe\n"
    .string "fique furioso!$"

SilphCo_7F_Text_RivalWhatKeptYou::
    .string "{RIVAL}: O que te atrasou, {PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
    .string "{RIVAL}: Hahaha! Eu sabia que você\n"
    .string "apareceria se eu esperasse aqui!\p"
    .string "Parece que a Equipe Rocket te atrasou!\n"
    .string "Não que eu me importe!\p"
    .string "Eu te vi em Saffron, então decidi ver\n"
    .string "se você melhorou alguma coisa!$"

SilphCo_7F_Text_RivalDefeat::
    .string "Caramba!\n"
    .string "Parece que você está pronto para\l"
    .string "o Chefe da Equipe Rocket!$"

SilphCo_7F_Text_RivalPostBattle::
    .string "Bem, {PLAYER}!\n"
    .string "Eu estou seguindo em frente!\p"
    .string "Consultando a minha Pokédex, comecei\n"
    .string "a entender quem é forte e como eles\l"
    .string "evoluem!\p"
    .string "Eu sou um gênio ou não sou?\p"
    .string "Estou indo para a Liga Pokémon para\n"
    .string "derrotar a Elite dos Quatro.\p"
    .string "Eu vou me tornar o Treinador mais\n"
    .string "poderoso do mundo!\p"
    .string "{PLAYER}, boa sorte para você!\n"
    .string "Não esquenta a cabeça!\l"
    .string "Até nunca mais!$"

SilphCo_7F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "7º Andar$"


SilphCo_7F_EventScript_PostgameGrunt5::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_5, SilphCo_7F_Text_PostgameGrunt5Intro, SilphCo_7F_Text_PostgameGrunt5Defeat
	msgbox SilphCo_7F_Text_PostgameGrunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_PostgameGrunt5Intro::
    .string "Você não vai humilhar a Equipe\n"
    .string "Rocket de novo, pivete!$"

SilphCo_7F_Text_PostgameGrunt5Defeat::
    .string "Isso não pode estar acontecendo!$"

SilphCo_7F_Text_PostgameGrunt5PostBattle::
    .string "Nosso Chefe é o mais forte de todos\n"
    .string "os Recrutas.$"

SilphCo_7F_EventScript_PostgameGrunt6::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_6, SilphCo_7F_Text_PostgameGrunt6Intro, SilphCo_7F_Text_PostgameGrunt6Defeat
	msgbox SilphCo_7F_Text_PostgameGrunt6PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_PostgameGrunt6Intro::
    .string "Apenas os Recrutas mais leais foram\n"
    .string "escolhidos para esta missão.$"

SilphCo_7F_Text_PostgameGrunt6Defeat::
    .string "Equipe Rocket até o fim!$"

SilphCo_7F_Text_PostgameGrunt6PostBattle::
    .string "Ainda restam muitos de nós por aí.$"

SilphCo_7F_EventScript_ItemTM08::
	finditem ITEM_TM08, 1
	release
	end
