.set LOCALID_SCOTT, 3

PewterCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Gym_OnTransition
	.byte 0

PewterCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_BROCK_REMATCH, PewterCity_Gym_ResetRematchFlags
	end

PewterCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_BROCK_ORIGINAL
	cleartrainerflag LEADER_REMATCH_BROCK_POSTGAME
	return

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE01_GET, PewterCity_Gym_EventScript_ChallengeBrock
	goto_if_unset FLAG_GOT_BROCK_REWARD, PewterCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_BROCK_REMATCH, PewterCity_Gym_EventScript_RematchLeader
	goto PewterCity_Gym_EventScript_LeaderPostBattle
	end

PewterCity_Gym_EventScript_ChallengeBrock::
	msgbox PewterCity_Gym_Text_BrockSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrockGetBadge
	end

PewterCity_Gym_Text_BrockSpeech::
	.string "Então você chegou. Eu sou Brock.\n"
    .string "Sou o Líder do Ginásio de Pewter.\p"
    .string "Minha força de vontade dura como rocha\n"
    .string "é evidente até nos meus Pokémon.\p"
    .string "Meus Pokémon são todos duros como pedra,\n"
    .string "e têm determinação de ferro.\p"
    .string "É isso mesmo - meus Pokémon são todos\n"
    .string "do tipo Pedra!\p"
    .string "Fuhaha! Você vai me desafiar sabendo\n"
    .string "que vai perder?\p"
    .string "Essa é a honra de um treinador,\n"
    .string "que te move a me desafiar.$"

PewterCity_Gym_Text_BrockIntro::
    .string "Muito bem, então!\n"
    .string "Mostre-me o seu melhor!$"

PewterCity_Gym_Text_BrockDefeat::
    .string "Eu subestimei você, e por isso\n"
    .string "eu perdi.$"

PewterCity_Gym_EventScript_DefeatedBrockGetBadge::
	msgbox PewterCity_Gym_Text_GetBadgeFromBrock, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message PewterCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox PewterCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DAILY_BROCK_REMATCH
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	settrainerflag TRAINER_CAMPER_LIAM
	setvar VAR_PEWTER_CITY_STATE, 1
	goto PewterCity_Gym_EventScript_GetTM
	end

PewterCity_Gym_Text_GetBadgeFromBrock::
	.string "Como prova da sua vitória, eu lhe\n"
    .string "concedo isto… a Insígnia da Rocha,\l"
    .string "oficial da Liga Pokémon.$"

PewterCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insígnia\n"
    .string "da Rocha de Brock!$"

PewterCity_Gym_Text_ExplainBadge::
	.string "Apenas ter a Insígnia da Rocha torna\n"
    .string "seus Pokémon mais poderosos.\p"
    .string "Ela também permite o uso do golpe\n"
    .string "Flash fora das batalhas.\p"
    .string "Claro, um Pokémon precisa saber o\n"
    .string "golpe Flash para poder usá-lo.$"

PewterCity_Gym_EventScript_GetTM::
	msgbox PewterCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM39, 1
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox PewterCity_Gym_Text_ReceivedTMFromBrock, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM39, 1
	setflag FLAG_GOT_BROCK_REWARD
	msgbox PewterCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_TakeThisWithYou::
    .string "Espere!\n"
    .string "Leve isto com você.$"

PewterCity_Gym_Text_ReceivedTMFromBrock::
    .string "{PLAYER} recebeu a TM39\n"
    .string "de Brock.$"

PewterCity_Gym_Text_ExplainTM::
    .string "Uma TM, Máquina Técnica, contém uma\n"
    .string "técnica para Pokémon.\p"
    .string "Usar uma TM ensina o golpe que ela\n"
    .string "contém ao seu Pokémon.\p"
    .string "A TM39 contém Rocha Tumbal.\p"
    .string "Ela atira rochas no adversário e\n"
    .string "reduz a velocidade dele.$"

PewterCity_Gym_EventScript_NoRoomForTM::
	msgbox PewterCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_NoRoomForTM::
    .string "Você não tem espaço para isso.$"

PewterCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, PewterCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox PewterCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_LeaderPostBattle::
    .string "Existem todos os tipos de treinadores\n"
    .string "neste nosso vasto mundo.\p"
    .string "Você parece ter um dom natural como\n"
    .string "Treinador Pokémon.\p"
    .string "Então permita-me uma sugestão.\p"
    .string "Vá até o Ginásio em Cerulean e teste\n"
    .string "as suas habilidades.$"

PewterCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox PewterCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_PostBattleGameClear::
	.string "Você foi muito longe desde que ganhou\n"
	.string "a sua Insígnia da Rocha, {PLAYER}!$"

PewterCity_Gym_EventScript_RematchLeader::
	msgbox PewterCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, PewterCity_Gym_EventScript_PostgameRematch
	goto PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

PewterCity_Gym_Text_RematchLeader::
	.string "...Você parece bem diferente de quando\n" 
	.string "nos conhecemos pela primeira vez!\p" 
	.string "...Por favor, conceda-me o privilégio de\n" 
	.string "enfrentar você em batalha mais uma vez!$" 

PewterCity_Gym_EventScript_DeclineRematch::
	msgbox PewterCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_DeclineRematch::
	.string "Entendo...$"

PewterCity_Gym_EventScript_PostgameRematch::
	msgbox PewterCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, PewterCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

PewterCity_Gym_Text_RematchMode::
	.string "Agora que você é o Campeão,\n"
	.string "gostaria de lutar com força total?$"

PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_BROCK_ORIGINAL, PewterCity_Gym_Text_RematchOriginal, PewterCity_Gym_Text_RematchDefeat, PewterCity_Gym_EventScript_DefeatedLeaderRematch
	end

PewterCity_Gym_Text_RematchOriginal::
	.string "Certo, {PLAYER}!\n"
	.string "Vamos reviver nossa primeira batalha!$"

PewterCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single LEADER_REMATCH_BROCK_POSTGAME, PewterCity_Gym_Text_RematchPostgame, PewterCity_Gym_Text_RematchDefeat, PewterCity_Gym_EventScript_DefeatedLeaderRematch
	end

PewterCity_Gym_Text_RematchPostgame::
	.string "Permita-me mostrar a verdadeira força\n" 
	.string "dura como pedra dos meus Pokémon!$"

PewterCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_BROCK_REMATCH
	goto PewterCity_Gym_EventScript_LeaderPostBattle
	end

PewterCity_Gym_Text_RematchDefeat::
	.string "Eu sabia que você era forte, mas isso...$"

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_Text_LiamIntro::
    .string "Pare bem aí, pivete!\p"
    .string "Você está a dez mil anos-luz\n"
    .string "de enfrentar o Brock!$"

PewterCity_Gym_Text_LiamDefeat::
    .string "Droga!\p"
    .string "Anos-luz não é tempo…\n"
    .string "É uma medida de distância!$"

PewterCity_Gym_Text_LiamPostBattle::
    .string "Você manda muito bem.\n"
    .string "…Mas não tão bem quanto o Brock!$"

PewterCity_Gym_EventScript_ScottTrigger1::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott1
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_WEST
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott1:
	walk_up
	walk_up
	walk_right
	step_end

PewterCity_Gym_EventScript_ScottTrigger2::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott2
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_WEST
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott2:
	walk_up
	face_right
	step_end

PewterCity_Gym_EventScript_ScottTrigger3::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott3
	waitmovement 0
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott3:
	walk_up
	step_end

PewterCity_Gym_EventScript_ScottTriggered::
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox PewterCity_Gym_Text_HeyWaitUp, MSGBOX_DEFAULT
	return

PewterCity_Gym_Text_HeyWaitUp::
	.string "Ei, jovem! Espere aí!$"

PewterCity_Gym_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_REGISTERED_SCOTT, PewterCity_Gym_EventScript_GymGuyPostVictory
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_ThatWasReallySomething
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
    .string "Olá!\n"
    .string "Você quer sonhar alto?\p"
    .string "Você ousa sonhar em se tornar o\n"
    .string "Campeão Pokémon?\p"
    .string "Eu não sou um treinador, mas posso\n"
    .string "te dar dicas de como vencer.\p"
    .string "Deixe-me guiar você até o topo!$"

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_Text_LetsGetHappening::
    .string "Muito bem!\n"
    .string "Vamos nessa!$"

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
    .string "É um serviço totalmente gratuito!\n"
    .string "Vamos nessa!$"

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_TryDifferentPartyOrders::
    .string "O primeiro Pokémon na batalha é aquele\n"
    .string "que está no topo da sua lista.\p"
    .string "Ao mudar a ordem dos seus Pokémon,\n"
    .string "você pode conseguir grande vantagem.\p"
    .string "Experimente ordens diferentes para\n"
    .string "lidar com a equipe do seu oponente.$"


PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_YoureChampMaterial::
    .string "Você tem fibra de campeão Pokémon!$"

PewterCity_Gym_EventScript_ThatWasReallySomething::
	msgbox PewterCity_Gym_Text_ThatWasReallySomething, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_SCOTT
	setvar VAR_PEWTER_CITY_STATE, 2
	release
	end

PewterCity_Gym_Text_ThatWasReallySomething::
    .string "Uau, isso foi espetacular!\p"
    .string "Pode ter sido apenas a sua primeira\n"
    .string "Insígnia de Ginásio, mas eu tenho um\l"
    .string "faro afiado para essas coisas.\p"
    .string "Você tem o que é preciso!\p"
    .string "Escute, estou viajando por Kanto em\n"
    .string "busca de treinadores talentosos.\p"
    .string "Deixe-me te dar o meu número.\n"
    .string "Pode ser muito útil!$"

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "Ginásio Pokémon de Pewter\n"
    .string "Líder: Brock\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginásio Pokémon de Pewter\n"
    .string "Líder: Brock\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"
