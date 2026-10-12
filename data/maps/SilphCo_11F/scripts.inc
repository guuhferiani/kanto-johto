.set LOCALID_GIOVANNI, 1
.set LOCALID_GRUNT1,   4
.set LOCALID_GRUNT2,   5
.set LOCALID_JESSIE,   6
.set LOCALID_JAMES,    7
.set LOCALID_ROCKET_LEADER, 9
.set LOCALID_LOOKER, 10

SilphCo_11F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_ItemZinc::
	finditem ITEM_ZINC, 1
	release
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_LOOKER_POSTGAME_COMPLETED, SilphCo_11F_EventScript_PresidentPostgame
	goto_if_set	FLAG_LOOKER_POSTGAME_STARTED, SilphCo_11F_EventScript_PresidentHostage
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	msgbox SilphCo_11F_Text_ThanksForSavingMe
	checkitemspace ITEM_MASTER_BALL, 1
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message SilphCo_11F_Text_ObtainedMasterBallFromPresident
	additem ITEM_MASTER_BALL, 1
	waitfanfare
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentPostgame::
	goto_if_set FLAG_DAILY_PREZ_BATTLE, SilphCo_11F_EventScript_PresidentPostgamePostBattle
	msgbox SilphCo_11F_Text_PracticeBattling, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_11F_EventScript_DeclinePrezBattle
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 25
	trainerbattle_no_intro TRAINER_SILPH_PREZ, SilphCo_11F_Text_PrezDefeat
	msgbox SilphCo_11F_Text_WhatAGreatBattle, MSGBOX_NPC
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message SilphCo_11F_Text_ObtainedMasterBallFromPresident
	additem ITEM_MASTER_BALL, 1
	waitfanfare
	setflag FLAG_DAILY_PREZ_BATTLE
	release
	end

SilphCo_11F_Text_WhatAGreatBattle::
	.string "Presidente: Vejo que ainda tenho muito\n"
	.string "a melhorar!\p"
	.string "Mas você não precisará mais se preocupar\n"
	.string "em vir me resgatar!\p"
	.string "Por favor, aceite isto como recompensa.$"

SilphCo_11F_Text_PrezDefeat::
	.string "Parece que nem mesmo um Presidente é\n"
	.string "páreo para um Campeão!$"	

SilphCo_11F_Text_PracticeBattling::
	.string "Presidente: Ah, olá, {PLAYER}!\p"
	.string "Veio ver como eu estou?\p"
	.string "Hoho... bem, não se preocupe. Não há\n"
	.string "sinal da Equipe Rocket por aqui.\p"
	.string "Mas todo cuidado é pouco, então comecei\n"
	.string "a treinar meus próprios Pokémon para\l"
	.string "minha proteção!\p"
	.string "Diga... já que veio até aqui, que tal\n"
	.string "uma batalha amistosa?$"

SilphCo_11F_EventScript_DeclinePrezBattle::
	msgbox SilphCo_11F_Text_IUnderstand, MSGBOX_NPC
	release
	end

SilphCo_11F_Text_IUnderstand::
	.string "Eu compreendo. A rotina deve ser bem\n"
	.string "ocupada para um Campeão.$"

SilphCo_11F_EventScript_PresidentPostgamePostBattle::
	msgbox SilphCo_11F_Text_TheseRocketsPunks, MSGBOX_NPC
	end

SilphCo_11F_Text_TheseRocketsPunks::
	.string "Presidente: A Silph S.A. se esforça\n"
	.string "para tornar o mundo melhor para as\l"
	.string "pessoas e para os Pokémon.\p"
	.string "Mas baderneiros como a Equipe Rocket\n"
	.string "nunca entenderão isso.$"

SilphCo_11F_EventScript_PresidentHostage::
	msgbox SilphCo_11F_Text_TheseRockets, MSGBOX_NPC
	end

SilphCo_11F_Text_TheseRockets::
	.string "Presidente: Já estou farto desses\n"
	.string "Rockets!$"

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	goto_if_set FLAG_DAILY_PREZ_BATTLE, SilphCo_11F_EventScript_SecretaryPostbattle
	goto_if_set FLAG_LOOKER_POSTGAME_COMPLETED, SilphCo_11F_EventScript_SecretaryPostgame
	goto_if_set	FLAG_LOOKER_POSTGAME_STARTED, SilphCo_11F_EventScript_HappeningAgain
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_SecretaryPostbattle::
	msgbox SilphCo_11F_Text_PrezTeam, MSGBOX_NPC
	end

SilphCo_11F_Text_PrezTeam::
	.string "Depois de ver você batalhar contra a\n"
	.string "Equipe Rocket duas vezes, o Presidente\l"
	.string "ficou obcecado por batalhas Pokémon.\p"
	.string "Ele passa o tempo todo pesquisando novos\n"
	.string "golpes...\p"
	.string "O que significa que eu tenho que responder\n"
	.string "a todos os e-mails dele!$"

SilphCo_11F_EventScript_HappeningAgain::
	msgbox SilphCo_11F_Text_HappeningAgain, MSGBOX_NPC
	end

SilphCo_11F_EventScript_SecretaryPostgame::
	msgbox SilphCo_11F_Text_NotWhatIExpected, MSGBOX_NPC
	end

SilphCo_11F_Text_NotWhatIExpected::
	.string "Este trabalho não é o que eu esperava.\n"
	.string "Sou secretária, não guarda-costas.\p"
	.string "Estou pensando seriamente em pedir\n"
	.string "um aumento!$"

SilphCo_11F_Text_HappeningAgain::
	.string "Aaaai!! Não acredito que isso está\n"
	.string "acontecendo de novo! Nos ajude!$"

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	applymovement LOCALID_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 1
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq  VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_SILPH_STATE, 3
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_ROCKET_BURGLARS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 1
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 1
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fast_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_fast_right
	step_end


SilphCo_11F_EventScript_JessieJames::
	lockall
	setvar VAR_0x8003, 0
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_JESSIE, Movement_JessieJamesApproachPlayer
	applymovement LOCALID_JAMES, Movement_JessieJamesApproachPlayer
	waitmovement 6
	msgbox SilphCo_11F_Text_StopYouOnceAndForAll
	trainerbattle_no_intro TRAINER_SILPH_CO_JESSIE_JAMES, SilphCo_11F_Text_JessieJamesDefeat
	msgbox SilphCo_11F_Text_JessieJamesPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	fadescreen FADE_FROM_BLACK
	delay 10
	setvar VAR_SILPH_STATE, 2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

SilphCo_11F_Text_StopYouOnceAndForAll::
	.string "James: Ora, ora, veja só quem é.\n"
	.string "Jessie: O pirralho chegou bem na hora.\p"
	.string "Jessie: Sabíamos que você viria.\n"
	.string "James: Mas você não passa daqui!\l"
	.string "Jessie: Nosso Chefe está em reunião.\n"
	.string "James: Então terá que lidar conosco!$"

SilphCo_11F_Text_JessieJamesDefeat::
	.string "Jessie: Argh! Eu odeio crianças!\p"
	.string "James: A mesma história de sempre...$"

SilphCo_11F_Text_JessieJamesPostBattle::
	.string "Jessie: Falhamos com o chefe.\n"
	.string "James: Esta era a nossa última chance!\p"
	.string "Jessie & James: Parece que a Equipe\n"
	.string "Rocket está decolando de novo!$"

Movement_JessieJamesApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMe::
    .string "Presidente: Oh, jovem criança!\n"
    .string "Obrigado por salvar a Silph.\p"
    .string "Nunca esquecerei que nos salvou em\n"
    .string "nosso momento de maior aflição.\p"
    .string "Preciso lhe agradecer de alguma forma.\p"
    .string "Como sou muito rico, posso lhe dar\n"
    .string "qualquer coisa.\p"
    .string "Aqui, talvez isto sirva.$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
    .string "{PLAYER} recebeu uma Master Ball\n"
    .string "do Presidente!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
    .string "Presidente: Você não pode comprar isso\n"
    .string "em lugar nenhum.\p"
    .string "É o nosso protótipo secreto da\n"
    .string "Master Ball.\p"
    .string "Ela captura qualquer Pokémon sem\n"
    .string "jamais falhar!\p"
    .string "Mas guarde segredo sobre usá-la,$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
    .string "Você não tem espaço para isso.$"

SilphCo_11F_Text_ThanksForRescuingUs::
    .string "Secretária: Obrigada por resgatar a\n"
    .string "todos nós.\p"
    .string "Nós, desde o Presidente até o menor\n"
    .string "dos funcionários, estamos em dívida.$"

SilphCo_11F_Text_GiovanniIntro::
    .string "Ah, {PLAYER}!\n"
    .string "Nos encontramos de novo!\p"
    .string "O Presidente e eu estamos debatendo\n"
    .string "uma proposta de negócios vital.\p"
    .string "Não meta o nariz em assuntos de gente\n"
    .string "grande...\p"
    .string "Ou sofrerá as duras consequências!$"

SilphCo_11F_Text_GiovanniDefeat::
    .string "Arrgh!!\n"
    .string "Eu perdi de novo!?$"

SilphCo_11F_Text_GiovanniPostBattle::
    .string "Maldito seja!\n"
    .string "Você arruinou nossos planos na Silph!\p"
    .string "Mas a Equipe Rocket nunca cairá!\p"
    .string "{PLAYER}! Jamais se esqueça de que\n"
    .string "todos os Pokémon existem para a\l"
    .string "Equipe Rocket!\p"
    .string "Eu devo partir, mas eu voltarei!$"

SilphCo_11F_Text_Grunt2Intro::
    .string "Parado aí mesmo!\n"
    .string "Não se mexa!$"

SilphCo_11F_Text_Grunt2Defeat::
    .string "Não...\n"
    .string "Por favor!$"

SilphCo_11F_Text_Grunt2PostBattle::
    .string "Então você quer ver o meu Chefe?$"

SilphCo_11F_Text_Grunt1Intro::
    .string "Alto lá! Você tem hora marcada com\n"
    .string "o meu Chefe?$"

SilphCo_11F_Text_Grunt1Defeat::
    .string "Gaah!\n"
    .string "Fui demolido!$"

SilphCo_11F_Text_Grunt1PostBattle::
    .string "Cuidado por onde anda...\n"
    .string "Meu Chefe só usa Pokémon durões!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
    .string "O monitor exibe dados de Pokémon!$"

SilphCo_11F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "11º Andar$"


@Postgame
SilphCo_11F_EventScript_PostgameRocket::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_ROCKET_LEADER, Common_Movement_ExclamationMark
	waitse
	msgbox SilphCo_11F_Text_GiovanniWasWeak, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_POSTGAME_ROCKET_LEADER, SilphCo_11F_Text_RocketLeaderDefeat
	playse SE_PIN
	applymovement LOCALID_ROCKET_LEADER, Common_Movement_ExclamationMark
	waitse
	msgbox SilphCo_11F_Text_HowCouldThisHappen, MSGBOX_NPC
	clearflag FLAG_HIDE_SILPH_POSTGAME_LOOKER
	addobject LOCALID_LOOKER
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	call_if_eq VAR_FACING, DIR_EAST, SilphCo_11F_EventScript_LookerMovement1
	call_if_eq VAR_FACING, DIR_WEST, SilphCo_11F_EventScript_LookerMovement2
	msgbox SilphCo_11F_Text_ThatsEnoughFromYou, MSGBOX_NPC
	waitmessage
	closemessage
	msgbox SilphCo_11F_Text_RocketWellNeverStop, MSGBOX_NPC
	waitmessage
	closemessage
	msgbox SilphCo_11F_Text_TakingYouIn, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_EAST, SilphCo_11F_EventScript_LookerMovement3
	call_if_eq VAR_FACING, DIR_WEST, SilphCo_11F_EventScript_LookerMovement4
	waitmovement 10
	setflag	FLAG_HIDE_SILPH_POSTGAME_ROCKET
	clearflag FLAG_SILPH_INVASION_ACTIVE
	setflag	FLAG_HIDE_SILPH_POSTGAME_LOOKER
	setflag FLAG_LOOKER_POSTGAME_COMPLETED
	clearflag FLAG_HIDE_LOOKER_CELADON
	removeobject LOCALID_LOOKER
	removeobject LOCALID_ROCKET_LEADER
	fadedefaultbgm
	release
	end

SilphCo_11F_Text_ThatsEnoughFromYou::
	.string "Looker: Já chega!\p"
	.string "Já ouvimos essa história antes.\p"
	.string "Esse é o problema de vocês da Equipe\n"
	.string "Rocket. Só se importam com uma única\l"
	.string "coisa... poder!\p"
	.string "É por isso que vocês sempre perderão\n"
	.string "para alguém como {PLAYER}.\p"
	.string "Eles sabem o que realmente significa\n"
	.string "viver ao lado dos Pokémon.\p"
	.string "...\p"
	.string "Você chamou Giovanni de fraco, mas\n"
	.string "acho que até ele percebeu isso no final.$"

SilphCo_11F_Text_RocketWellNeverStop::
	.string "Rocket: ...\p"
	.string "Pode até ser...\p"
	.string "Mas nós nunca vamos parar!\p"
	.string "A Equipe Rocket vai se erguer de novo!$"

SilphCo_11F_Text_TakingYouIn::
	.string "Looker: É o que veremos.\p"
	.string "{PLAYER}! Vou levar este Rocket preso.\n"
	.string "Obrigado por toda a sua ajuda aqui.\p"
	.string "Venha me visitar na próxima vez em que\n"
	.string "estiver na Cidade de Celadon.$"

SilphCo_11F_EventScript_LookerMovement1::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Approach1
	waitmovement 10
	turnobject LOCALID_ROCKET_LEADER, DIR_EAST
	return

SilphCo_11F_EventScript_LookerMovement2::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Approach2
	waitmovement 10
	turnobject LOCALID_ROCKET_LEADER, DIR_WEST
	return

SilphCo_11F_LookerMovement_Approach1::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

SilphCo_11F_LookerMovement_Approach2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

SilphCo_11F_EventScript_LookerMovement3::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Exit1
	applymovement LOCALID_ROCKET_LEADER, SilphCo_11F_RocketMovement_Exit1
	return

SilphCo_11F_RocketMovement_Exit1::
	walk_right
SilphCo_11F_LookerMovement_Exit1::
	walk_right	
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_RocketMovement_Exit2::
	walk_left
SilphCo_11F_LookerMovement_Exit2::
	walk_left	
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_EventScript_LookerMovement4::
	applymovement LOCALID_LOOKER, SilphCo_11F_RocketMovement_Exit2
	applymovement LOCALID_ROCKET_LEADER, SilphCo_11F_RocketMovement_Exit2
	return


SilphCo_11F_Text_GiovanniWasWeak::
	.string "Rocket: Há! Você veio mesmo?\p"
	.string "O que foi? O todo-poderoso campeão\n"
	.string "de Kanto acha que vai me derrubar?\p"
	.string "Pois escute aqui, pivete.\p"
	.string "Giovanni era fraco!\p"
	.string "Ele deixou um pirralho como você\n"
	.string "passar por cima dele!\p"
	.string "Sob a minha liderança, a Equipe Rocket\n"
	.string "não vai se curvar só porque uma criança\l"
	.string "está no nosso caminho!\p"
	.string "Diga olá para a nova Equipe Rocket!$"

SilphCo_11F_Text_RocketLeaderDefeat::
	.string "O quê?! Eu sou mais fraco que Giovanni?$"

SilphCo_11F_Text_HowCouldThisHappen:
	.string "Não consigo acreditar...\p"
	.string "Este era para ser o nosso grande\n"
	.string "retorno!\p"
	.string "Achamos que Giovanni era fraco...\n"
	.string "mas você é bom demais!$"
