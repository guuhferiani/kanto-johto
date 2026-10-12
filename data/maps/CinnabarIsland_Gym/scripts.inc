.set LOCALID_QUINN, 1
.set LOCALID_AVERY, 3
.set LOCALID_RAMON, 4
.set LOCALID_DEREK, 5
.set LOCALID_DUSTY, 6
.set LOCALID_ZAC,   7

CinnabarIsland_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_Gym_OnLoad
	.byte 0

CinnabarIsland_Gym_OnLoad::
	goto_if_set FLAG_BADGE07_GET, CinnabarIsland_Gym_OnLoadOpenAllDoors
	call_if_set FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_OnLoadOpenDoor1
	call_if_set FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_OnLoadOpenDoor2
	call_if_set FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_OnLoadOpenDoor3
	call_if_set FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_OnLoadOpenDoor4
	call_if_set FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_OnLoadOpenDoor5
	call_if_set FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_OnLoadOpenDoor6
	end

CinnabarIsland_Gym_OnLoadOpenAllDoors::
	call CinnabarIsland_Gym_EventScript_OpenDoor1
	call CinnabarIsland_Gym_EventScript_OpenDoor2
	call CinnabarIsland_Gym_EventScript_OpenDoor3
	call CinnabarIsland_Gym_EventScript_OpenDoor4
	call CinnabarIsland_Gym_EventScript_OpenDoor5
	call CinnabarIsland_Gym_EventScript_OpenDoor6
	end

CinnabarIsland_Gym_OnTransition::
	call_if_unset FLAG_DAILY_BLAINE_REMATCH, CinnabarIsland_Gym_ResetRematchFlags
	end

CinnabarIsland_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_BLAINE_ORIGINAL
	cleartrainerflag LEADER_REMATCH_BLAINE_POSTGAME
	return

CinnabarIsland_Gym_EventScript_BlaineFujiPhoto::
	lockall
	msgbox CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji
	releaseall
	end

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
    .string "E uma foto de Blaine e do\n"
    .string "Sr. Fuji.\p"
    .string "Eles estao lado a lado,\n"
    .string "com grandes sorrisos.$"

CinnabarIsland_Gym_OnLoadOpenDoor1::
	call CinnabarIsland_Gym_EventScript_OpenDoor1
	return

CinnabarIsland_Gym_OnLoadOpenDoor2::
	call CinnabarIsland_Gym_EventScript_OpenDoor2
	return

CinnabarIsland_Gym_OnLoadOpenDoor3::
	call CinnabarIsland_Gym_EventScript_OpenDoor3
	return

CinnabarIsland_Gym_OnLoadOpenDoor4::
	call CinnabarIsland_Gym_EventScript_OpenDoor4
	return

CinnabarIsland_Gym_OnLoadOpenDoor5::
	call CinnabarIsland_Gym_EventScript_OpenDoor5
	return

CinnabarIsland_Gym_OnLoadOpenDoor6::
	call CinnabarIsland_Gym_EventScript_OpenDoor6
	return

CinnabarIsland_Gym_EventScript_Erik::
	trainerbattle_single TRAINER_SUPER_NERD_ERIK, CinnabarIsland_Gym_Text_ErikIntro, CinnabarIsland_Gym_Text_ErikDefeat
	msgbox CinnabarIsland_Gym_Text_ErikPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_Text_ErikIntro::
    .string "Voce sabe quao quente o sopro de\n"
    .string "fogo de um Pokemon pode ficar?$"

CinnabarIsland_Gym_Text_ErikDefeat::
    .string "Ui!\n"
    .string "Quente, quente, quente!$"

CinnabarIsland_Gym_Text_ErikPostBattle::
    .string "Fogo, ou para ser mais preciso,\n"
    .string "combustao...\p"
    .string "...Oxigenio no ar...\n"
    .string "Bla, bla, bla, bla...$"

CinnabarIsland_Gym_EventScript_Avery::
	trainerbattle_single TRAINER_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AveryIntro, CinnabarIsland_Gym_Text_AveryDefeat, CinnabarIsland_Gym_EventScript_DefeatedAvery
	msgbox CinnabarIsland_Gym_Text_AveryPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_DefeatedAvery::
	call_if_unset FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_EventScript_Quiz2CompleteTrainer
	release
	end

CinnabarIsland_Gym_EventScript_Quiz2CompleteTrainer::
	call CinnabarIsland_Gym_EventScript_Quiz2Complete
	return

CinnabarIsland_Gym_EventScript_Derek::
	trainerbattle_single TRAINER_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekIntro, CinnabarIsland_Gym_Text_DerekDefeat, CinnabarIsland_Gym_EventScript_DefeatedDerek
	msgbox CinnabarIsland_Gym_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_DefeatedDerek::
	call_if_unset FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_EventScript_Quiz4CompleteTrainer
	release
	end

CinnabarIsland_Gym_EventScript_Quiz4CompleteTrainer::
	call CinnabarIsland_Gym_EventScript_Quiz4Complete
	return

CinnabarIsland_Gym_EventScript_Zac::
	trainerbattle_single TRAINER_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacIntro, CinnabarIsland_Gym_Text_ZacDefeat, CinnabarIsland_Gym_EventScript_DefeatedZac
	msgbox CinnabarIsland_Gym_Text_ZacPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_DefeatedZac::
	call_if_unset FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_EventScript_Quiz6CompleteTrainer
	release
	end

CinnabarIsland_Gym_EventScript_Quiz6CompleteTrainer::
	call CinnabarIsland_Gym_EventScript_Quiz6Complete
	return

CinnabarIsland_Gym_EventScript_Quinn::
	trainerbattle_single TRAINER_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnIntro, CinnabarIsland_Gym_Text_QuinnDefeat, CinnabarIsland_Gym_EventScript_DefeatedQuinn
	msgbox CinnabarIsland_Gym_Text_QuinnPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_Text_QuinnIntro::
    .string "Eu era um ladrao, mas me endireitei\n"
    .string "como treinador.$"

CinnabarIsland_Gym_Text_QuinnDefeat::
    .string "Eu me rendo!$"

CinnabarIsland_Gym_Text_QuinnPostBattle::
    .string "As vezes sinto essa vontade louca\n"
    .string "de roubar o Pokemon dos outros.$"

CinnabarIsland_Gym_EventScript_DefeatedQuinn::
	call_if_unset FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_EventScript_Quiz1CompleteTrainer
	release
	end

CinnabarIsland_Gym_EventScript_Quiz1CompleteTrainer::
	call CinnabarIsland_Gym_EventScript_Quiz1Complete
	return

CinnabarIsland_Gym_EventScript_Ramon::
	trainerbattle_single TRAINER_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonIntro, CinnabarIsland_Gym_Text_RamonDefeat, CinnabarIsland_Gym_EventScript_DefeatedRamon
	msgbox CinnabarIsland_Gym_Text_RamonPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_Text_RamonIntro::
    .string "Eu gosto de usar Pokemon do tipo\n"
    .string "Fogo. Simplesmente adoro.$"

CinnabarIsland_Gym_Text_RamonDefeat::
    .string "Quente demais para aguentar!$"

CinnabarIsland_Gym_Text_RamonPostBattle::
    .string "Queria que existisse um Pokemon\n"
    .string "ladrao. Eu usaria com certeza!$"

CinnabarIsland_Gym_EventScript_DefeatedRamon::
	call_if_unset FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_EventScript_Quiz3CompleteTrainer
	release
	end

CinnabarIsland_Gym_EventScript_Quiz3CompleteTrainer::
	call CinnabarIsland_Gym_EventScript_Quiz3Complete
	return

CinnabarIsland_Gym_EventScript_Dusty::
	trainerbattle_single TRAINER_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustyIntro, CinnabarIsland_Gym_Text_DustyDefeat, CinnabarIsland_Gym_EventScript_DefeatedDusty
	msgbox CinnabarIsland_Gym_Text_DustyPostBattle, MSGBOX_AUTOCLOSE
	end

CinnabarIsland_Gym_EventScript_DefeatedDusty::
	call_if_unset FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_EventScript_Quiz5CompleteTrainer
	release
	end

CinnabarIsland_Gym_EventScript_Quiz5CompleteTrainer::
	call CinnabarIsland_Gym_EventScript_Quiz5Complete
	return

CinnabarIsland_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, CinnabarIsland_Gym_EventScript_GymGuyPostVictory
	msgbox CinnabarIsland_Gym_Text_GymGuyAdvice
	release
	end

CinnabarIsland_Gym_EventScript_GymGuyPostVictory::
	msgbox CinnabarIsland_Gym_Text_GymGuyPostVictory
	release
	end

CinnabarIsland_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, CinnabarIsland_Gym_EventScript_GymStatuePostVictory
	msgbox CinnabarIsland_Gym_Text_GymStatue
	releaseall
	end

CinnabarIsland_Gym_EventScript_GymStatuePostVictory::
	msgbox CinnabarIsland_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quz1Left::
	lockall
	setvar VAR_TEMP_1, 0
	goto CinnabarIsland_Gym_EventScript_Quiz1
	end

CinnabarIsland_Gym_EventScript_Quz1Right::
	lockall
	setvar VAR_TEMP_1, 1
	goto CinnabarIsland_Gym_EventScript_Quiz1
	end

CinnabarIsland_Gym_EventScript_Quiz1::
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules
	msgbox CinnabarIsland_Gym_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz1Correct
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz1Incorrect
	end

CinnabarIsland_Gym_EventScript_CorrectAnswer::
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox CinnabarIsland_Gym_Text_CorrectGoOnThrough
	return

CinnabarIsland_Gym_EventScript_IncorrectAnswer::
	waitse
	playse SE_BOO
	waitse
	msgbox CinnabarIsland_Gym_Text_SorryBadCall
	closemessage
	return

CinnabarIsland_Gym_EventScript_Quiz1Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz1Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz1Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor1
	special DrawWholeMapView
	setflag FLAG_CINNABAR_GYM_QUIZ_1
	return

CinnabarIsland_Gym_EventScript_DoorAlreadyOpen::
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz1Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_BURGLAR_QUINN, CinnabarIsland_Gym_EventScript_BattleQuinn
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleQuinn::
	call_if_eq VAR_TEMP_1, 0, CinnabarIsland_Gym_EventScript_QuinnApproachLeft
	call_if_eq VAR_TEMP_1, 1, CinnabarIsland_Gym_EventScript_QuinnApproachRight
	msgbox CinnabarIsland_Gym_Text_QuinnIntro
	trainerbattle_no_intro TRAINER_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnDefeat
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_1, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz1Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_QuinnApproachLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_QUINN, CinnabarIsland_Gym_Movement_QuinnApproachLeft
	waitmovement 0
	return

CinnabarIsland_Gym_EventScript_QuinnApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_QUINN, CinnabarIsland_Gym_Movement_QuinnApproachRight
	waitmovement 0
	return

CinnabarIsland_Gym_Movement_QuinnApproachLeft::
	walk_left
	walk_left
	step_end

CinnabarIsland_Gym_Movement_QuinnApproachRight::
	walk_left
	step_end

CinnabarIsland_Gym_EventScript_Quiz2Left::
	lockall
	setvar VAR_TEMP_1, 0
	goto CinnabarIsland_Gym_EventScript_Quiz2
	end

CinnabarIsland_Gym_EventScript_Quiz2Right::
	lockall
	setvar VAR_TEMP_1, 1
	goto CinnabarIsland_Gym_EventScript_Quiz2
	end

CinnabarIsland_Gym_EventScript_Quiz2::
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules
	msgbox CinnabarIsland_Gym_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz2Incorrect
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz2Correct
	end

CinnabarIsland_Gym_EventScript_Quiz2Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz2Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz2Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor2
	special DrawWholeMapView
	setflag FLAG_CINNABAR_GYM_QUIZ_2
	return

CinnabarIsland_Gym_EventScript_Quiz2Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_SUPER_NERD_AVERY, CinnabarIsland_Gym_EventScript_BattleAvery
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleAvery::
	call_if_eq VAR_TEMP_1, 0, CinnabarIsland_Gym_EventScript_AveryApproachLeft
	call_if_eq VAR_TEMP_1, 1, CinnabarIsland_Gym_EventScript_AveryApproachRight
	msgbox CinnabarIsland_Gym_Text_AveryIntro
	trainerbattle_no_intro TRAINER_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AveryDefeat
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_2, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz2Complete
	releaseall
	end

CinnabarIsland_Gym_Text_AveryIntro::
    .string "Eu estudei os Pokemon a fundo.\n"
    .string "Voce nao pode vencer!$"

CinnabarIsland_Gym_Text_AveryDefeat::
    .string "Uaaaah!\n"
    .string "Meus estudos foram insuficientes!$"

CinnabarIsland_Gym_Text_AveryPostBattle::
    .string "Minhas teorias sao complicadas\n"
    .string "demais para voce entender.$"

CinnabarIsland_Gym_EventScript_AveryApproachLeft::
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Gym_Movement_PlayerFaceAvery
	applymovement LOCALID_AVERY, CinnabarIsland_Gym_Movement_AveryApproachLeft
	waitmovement 0
	return

CinnabarIsland_Gym_EventScript_AveryApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Gym_Movement_PlayerFaceAvery
	applymovement LOCALID_AVERY, CinnabarIsland_Gym_Movement_AveryApproachRight
	waitmovement 0
	return

CinnabarIsland_Gym_Movement_AveryApproachLeft::
	walk_up
	walk_up
	walk_left
	step_end

CinnabarIsland_Gym_Movement_AveryApproachRight::
	walk_up
	walk_up
	walk_in_place_fast_left
	step_end

CinnabarIsland_Gym_Movement_PlayerFaceAvery::
	delay_16
	delay_16
	walk_in_place_fast_right
	step_end

CinnabarIsland_Gym_EventScript_Quiz3Left::
	lockall
	setvar VAR_TEMP_1, 0
	goto CinnabarIsland_Gym_EventScript_Quiz3
	end

CinnabarIsland_Gym_EventScript_Quiz3Right::
	lockall
	setvar VAR_TEMP_1, 1
	goto CinnabarIsland_Gym_EventScript_Quiz3
	end

CinnabarIsland_Gym_EventScript_Quiz3::
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules
	msgbox CinnabarIsland_Gym_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz3Incorrect
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz3Correct
	end

CinnabarIsland_Gym_EventScript_Quiz3Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz3Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz3Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor3
	special DrawWholeMapView
	setflag FLAG_CINNABAR_GYM_QUIZ_3
	return

CinnabarIsland_Gym_EventScript_Quiz3Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_BURGLAR_RAMON, CinnabarIsland_Gym_EventScript_BattleRamon
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleRamon::
	call_if_eq VAR_TEMP_1, 0, CinnabarIsland_Gym_EventScript_RamonApproachLeft
	call_if_eq VAR_TEMP_1, 1, CinnabarIsland_Gym_EventScript_RamonApproachRight
	msgbox CinnabarIsland_Gym_Text_RamonIntro
	trainerbattle_no_intro TRAINER_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonDefeat
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_3, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz3Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_RamonApproachLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RAMON, CinnabarIsland_Gym_Movement_RamonApproachLeft
	waitmovement 0
	return

CinnabarIsland_Gym_EventScript_RamonApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RAMON, CinnabarIsland_Gym_Movement_RamonApproachRight
	waitmovement 0
	return

CinnabarIsland_Gym_Movement_RamonApproachLeft::
	walk_left
	walk_left
	step_end

CinnabarIsland_Gym_Movement_RamonApproachRight::
	walk_left
	step_end

CinnabarIsland_Gym_EventScript_Quiz4Left::
	lockall
	setvar VAR_TEMP_1, 0
	goto CinnabarIsland_Gym_EventScript_Quiz4
	end

CinnabarIsland_Gym_EventScript_Quiz4Right::
	lockall
	setvar VAR_TEMP_1, 1
	goto CinnabarIsland_Gym_EventScript_Quiz4
	end

CinnabarIsland_Gym_EventScript_Quiz4::
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules
	msgbox CinnabarIsland_Gym_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz4Incorrect
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz4Correct
	end

CinnabarIsland_Gym_EventScript_Quiz4Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz4Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz4Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor4
	special DrawWholeMapView
	setflag FLAG_CINNABAR_GYM_QUIZ_4
	return

CinnabarIsland_Gym_EventScript_Quiz4Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_SUPER_NERD_DEREK, CinnabarIsland_Gym_EventScript_BattleDerek
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleDerek::
	call_if_eq VAR_TEMP_1, 0, CinnabarIsland_Gym_EventScript_DerekApproachLeft
	call_if_eq VAR_TEMP_1, 1, CinnabarIsland_Gym_EventScript_DerekApproachRight
	msgbox CinnabarIsland_Gym_Text_DerekIntro
	trainerbattle_no_intro TRAINER_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekDefeat
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_4, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz4Complete
	releaseall
	end

CinnabarIsland_Gym_Text_DerekIntro::
    .string "Eu sei por que o Blaine se tornou\n"
    .string "um treinador.$"

CinnabarIsland_Gym_Text_DerekDefeat::
    .string "Ai!$"

CinnabarIsland_Gym_Text_DerekPostBattle::
    .string "Nosso Lider, Blaine, se perdeu feio\n"
    .string "nas montanhas certa vez.\p"
    .string "A noite caiu quando um Pokemon\n"
    .string "passaro de fogo apareceu.\p"
    .string "Sua luz permitiu que Blaine achasse\n"
    .string "o caminho de descida com seguranca.$"

CinnabarIsland_Gym_EventScript_DerekApproachLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_DEREK, CinnabarIsland_Gym_Movement_DerekApproachLeft
	waitmovement 0
	return

CinnabarIsland_Gym_EventScript_DerekApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_DEREK, CinnabarIsland_Gym_Movement_DerekApproachRight
	waitmovement 0
	return

CinnabarIsland_Gym_Movement_DerekApproachLeft::
	walk_left
	walk_left
	step_end

CinnabarIsland_Gym_Movement_DerekApproachRight::
	walk_left
	step_end

CinnabarIsland_Gym_EventScript_Quiz5Left::
	lockall
	setvar VAR_TEMP_1, 0
	goto CinnabarIsland_Gym_EventScript_Quiz5
	end

CinnabarIsland_Gym_EventScript_Quiz5Right::
	lockall
	setvar VAR_TEMP_1, 1
	goto CinnabarIsland_Gym_EventScript_Quiz5
	end

CinnabarIsland_Gym_EventScript_Quiz5::
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules
	msgbox CinnabarIsland_Gym_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz5Correct
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz5Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz5Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz5Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz5Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor5
	special DrawWholeMapView
	setflag FLAG_CINNABAR_GYM_QUIZ_5
	return

CinnabarIsland_Gym_EventScript_Quiz5Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_BURGLAR_DUSTY, CinnabarIsland_Gym_EventScript_BattleDusty
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleDusty::
	call_if_eq VAR_TEMP_1, 0, CinnabarIsland_Gym_EventScript_DustyApproachLeft
	call_if_eq VAR_TEMP_1, 1, CinnabarIsland_Gym_EventScript_DustyApproachRight
	msgbox CinnabarIsland_Gym_Text_DustyIntro
	trainerbattle_no_intro TRAINER_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustyDefeat
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_5, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz5Complete
	releaseall
	end

CinnabarIsland_Gym_Text_DustyIntro::
    .string "Ja visitei muitos Ginasios, mas este\n"
    .string "e o que mais combina com meu estilo.$"

CinnabarIsland_Gym_Text_DustyDefeat::
    .string "Nossa!\n"
    .string "Quente demais!$"

CinnabarIsland_Gym_Text_DustyPostBattle::
    .string "Ponyta, Ninetales...\n"
    .string "Sao Pokemon de Fogo bem populares.$"

CinnabarIsland_Gym_EventScript_DustyApproachLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_DUSTY, CinnabarIsland_Gym_Movement_DustyApproachLeft
	waitmovement 0
	return

CinnabarIsland_Gym_EventScript_DustyApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_DUSTY, CinnabarIsland_Gym_Movement_DustyApproachRight
	waitmovement 0
	return

CinnabarIsland_Gym_Movement_DustyApproachLeft::
	walk_left
	walk_left
	step_end

CinnabarIsland_Gym_Movement_DustyApproachRight::
	walk_left
	step_end

CinnabarIsland_Gym_EventScript_Quiz6Left::
	lockall
	setvar VAR_TEMP_1, 0
	goto CinnabarIsland_Gym_EventScript_Quiz6
	end

CinnabarIsland_Gym_EventScript_Quiz6Right::
	lockall
	setvar VAR_TEMP_1, 1
	goto CinnabarIsland_Gym_EventScript_Quiz6
	end

CinnabarIsland_Gym_EventScript_Quiz6::
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules
	msgbox CinnabarIsland_Gym_Text_QuizQuestion6, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz6Incorrect
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz6Correct
	end

CinnabarIsland_Gym_EventScript_Quiz6Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz6Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz6Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor6
	special DrawWholeMapView
	setflag FLAG_CINNABAR_GYM_QUIZ_6
	return

CinnabarIsland_Gym_EventScript_Quiz6Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_SUPER_NERD_ZAC, CinnabarIsland_Gym_EventScript_BattleZac
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleZac::
	call_if_eq VAR_TEMP_1, 0, CinnabarIsland_Gym_EventScript_ZacApproachLeft
	call_if_eq VAR_TEMP_1, 1, CinnabarIsland_Gym_EventScript_ZacApproachRight
	msgbox CinnabarIsland_Gym_Text_ZacIntro
	trainerbattle_no_intro TRAINER_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacDefeat
	goto_if_set FLAG_CINNABAR_GYM_QUIZ_6, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz6Complete
	releaseall
	end

CinnabarIsland_Gym_Text_ZacIntro::
    .string "O fogo e fraco contra H2O.$"

CinnabarIsland_Gym_Text_ZacDefeat::
    .string "Oh!\n"
    .string "Fui apagado!$"

CinnabarIsland_Gym_Text_ZacPostBattle::
    .string "Agua vence fogo, com certeza.\p"
    .string "Mas fogo derrete gelo, entao o tipo\n"
    .string "Fogo vence Pokemon do tipo Gelo.$"

CinnabarIsland_Gym_EventScript_ZacApproachLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_ZAC, CinnabarIsland_Gym_Movement_ZacApproachLeft
	waitmovement 0
	return

CinnabarIsland_Gym_EventScript_ZacApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_ZAC, CinnabarIsland_Gym_Movement_ZacApproachRight
	waitmovement 0
	return

CinnabarIsland_Gym_Movement_ZacApproachLeft::
	walk_left
	walk_left
	step_end

CinnabarIsland_Gym_Movement_ZacApproachRight::
	walk_left
	step_end

CinnabarIsland_Gym_EventScript_OpenDoor1::
	setmetatile 26,  8, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
	setmetatile 27,  8, METATILE_CinnabarGym_Floor_WallRightCorner, 0
	setmetatile 26,  9, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
	setmetatile 27,  9, METATILE_CinnabarGym_Floor_WallRightEdge, 0
	setmetatile 26, 10, METATILE_CinnabarGym_Floor_ShadeFull, 0
	setmetatile 27, 10, METATILE_CinnabarGym_Floor, 0
	setmetatile 28, 10, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor2::
	setmetatile 17,  8, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
	setmetatile 18,  8, METATILE_CinnabarGym_Floor_WallRightCorner, 0
	setmetatile 17,  9, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
	setmetatile 18,  9, METATILE_CinnabarGym_Floor_WallRightEdge, 0
	setmetatile 17, 10, METATILE_CinnabarGym_Floor_ShadeFull, 0
	setmetatile 18, 10, METATILE_CinnabarGym_Floor, 0
	setmetatile 19, 10, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor3::
	setmetatile 17, 15, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
	setmetatile 18, 15, METATILE_CinnabarGym_Floor_WallRightCorner, 0
	setmetatile 17, 16, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
	setmetatile 18, 16, METATILE_CinnabarGym_Floor_WallRightEdge, 0
	setmetatile 17, 17, METATILE_CinnabarGym_Floor_ShadeFull, 0
	setmetatile 18, 17, METATILE_CinnabarGym_Floor, 0
	setmetatile 19, 17, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor4::
	setmetatile 11, 21, METATILE_CinnabarGym_Wall_RetractedBarrier, 1
	setmetatile 11, 22, METATILE_CinnabarGym_Floor_ShadeFull, 0
	setmetatile 11, 23, METATILE_CinnabarGym_Floor, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor5::
	setmetatile  5, 16, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
	setmetatile  6, 16, METATILE_CinnabarGym_Floor_WallRightCorner, 0
	setmetatile  5, 17, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
	setmetatile  6, 17, METATILE_CinnabarGym_Floor_WallRightEdge, 0
	setmetatile  5, 18, METATILE_CinnabarGym_Floor_ShadeFull, 0
	setmetatile  6, 18, METATILE_CinnabarGym_Floor, 0
	setmetatile  7, 18, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor6::
	setmetatile  5,  8, METATILE_CinnabarGym_Floor_WallLeftCorner, 0
	setmetatile  6,  8, METATILE_CinnabarGym_Floor_WallRightCorner, 0
	setmetatile  5,  9, METATILE_CinnabarGym_Floor_WallLeftEdge, 0
	setmetatile  6,  9, METATILE_CinnabarGym_Floor_WallRightEdge, 0
	setmetatile  5, 10, METATILE_CinnabarGym_Floor_ShadeFull, 0
	setmetatile  6, 10, METATILE_CinnabarGym_Floor, 0
	setmetatile  7, 10, METATILE_CinnabarGym_Floor_ShadeDiagonal, 0
	return


CinnabarIsland_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE07_GET, CinnabarIsland_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_BLAINE_REWARD, CinnabarIsland_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_BLAINE_REMATCH, CinnabarIsland_Gym_EventScript_RematchLeader
	goto CinnabarIsland_Gym_EventScript_LeaderPostBattle
	end

CinnabarIsland_Gym_EventScript_ChallengeLeader::
	msgbox CinnabarIsland_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_BLAINE, CinnabarIsland_Gym_Text_LeaderIntro, CinnabarIsland_Gym_Text_LeaderDefeat, CinnabarIsland_Gym_EventScript_DefeatedLeaderGetBadge
	end

CinnabarIsland_Gym_Text_LeaderSpeech::
    .string "Hah!\p"
    .string "Eu sou Blaine, o ardente Lider\n"
    .string "do Ginasio de Cinnabar!\p"
    .string "Meus Pokemon de fogo estao prontos\n"
    .string "com um calor intenso!\p"
    .string "Eles incineram qualquer desafiante!$"

CinnabarIsland_Gym_Text_LeaderIntro::
    .string "Hah!\n"
    .string "E bom ter um Burn Heal com voce!$"

CinnabarIsland_Gym_Text_LeaderDefeat::
    .string "Fui reduzido a cinzas!$"

CinnabarIsland_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox CinnabarIsland_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CinnabarIsland_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	setflag FLAG_BADGE07_GET
	setflag FLAG_DAILY_BLAINE_REMATCH
	settrainerflag	TRAINER_SUPER_NERD_ERIK						
	settrainerflag	TRAINER_SUPER_NERD_AVERY					
	settrainerflag	TRAINER_SUPER_NERD_DEREK					
	settrainerflag	TRAINER_SUPER_NERD_ZAC						
	settrainerflag	TRAINER_BURGLAR_QUINN						
	settrainerflag	TRAINER_BURGLAR_RAMON						
	settrainerflag	TRAINER_BURGLAR_DUSTY						
	goto CinnabarIsland_Gym_EventScript_GetTM
	end

CinnabarIsland_Gym_Text_GetBadge::
    .string "Nem cinzas sobraram!\p"
    .string "Voce conquistou a Insignia do Vulcao.$"

CinnabarIsland_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insignia do\n"
    .string "Vulcao de Blaine!$"

CinnabarIsland_Gym_EventScript_GetTM::
	msgbox CinnabarIsland_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM38, 1
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CinnabarIsland_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM38, 1
	setflag FLAG_GOT_BLAINE_REWARD
	msgbox CinnabarIsland_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_Text_TakeThisWithYou::
    .string "Tome, fique com isto tambem!$"

CinnabarIsland_Gym_Text_ReceivedTM::
    .string "{PLAYER} recebeu o TM38\n"
    .string "de Blaine.$"

CinnabarIsland_Gym_Text_ExplainTM::
    .string "O TM38 contem Fire Blast.\n"
    .string "Ensine para Pokemon do tipo Fogo.\p"
    .string "Vulpix ou Charmeleon seriam ideais\n"
    .string "para esse golpe.$"

CinnabarIsland_Gym_EventScript_NoRoomForTM::
	msgbox CinnabarIsland_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_Text_NoRoomForTM::
    .string "Abra espaco na mochila, jovem!$"

CinnabarIsland_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CinnabarIsland_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CinnabarIsland_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_Text_LeaderPostBattle::
    .string "Fire Blast e a tecnica definitiva de\n"
    .string "fogo.\p"
    .string "Nao a desperdice em Pokemon de Agua.$"

CinnabarIsland_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CinnabarIsland_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_Text_PostBattleGameClear::
	.string "Hah! Estou pegando fogo!$"

CinnabarIsland_Gym_EventScript_RematchLeader::
	msgbox CinnabarIsland_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CinnabarIsland_Gym_EventScript_PostgameRematch
	goto CinnabarIsland_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CinnabarIsland_Gym_Text_RematchLeader::
	.string "Hah! Muito bem, voltando ao meu Ginasio!\p"
	.string "Voce ja explorou a Mansao Pokemon?\p"
	.string "Viu algo interessante por la?\p"
	.string "Aquele lugar ainda guarda restos das\n"
	.string "pesquisas do meu velho amigo!\p"
	.string "Mais importante: ja que veio de tao\n"
	.string "longe, devemos batalhar! Hah!$"

CinnabarIsland_Gym_EventScript_DeclineRematch::
	msgbox CinnabarIsland_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_Text_DeclineRematch::
	.string "Que decepcao!$"

CinnabarIsland_Gym_EventScript_PostgameRematch::
	msgbox CinnabarIsland_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CinnabarIsland_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CinnabarIsland_Gym_Text_RematchMode::
	.string "Agora que e o campeao,\n"
	.string "gostaria de ir com forca total?$"

CinnabarIsland_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_BLAINE_ORIGINAL, CinnabarIsland_Gym_Text_RematchOriginal, CinnabarIsland_Gym_Text_RematchDefeat, CinnabarIsland_Gym_EventScript_DefeatedLeaderRematch
	end

CinnabarIsland_Gym_Text_RematchOriginal::
	.string "Nossa primeira batalha esta gravada a\n"
	.string "fogo na minha memoria! Vamos la!$" 

CinnabarIsland_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single LEADER_REMATCH_BLAINE_POSTGAME, CinnabarIsland_Gym_Text_RematchPostgame, CinnabarIsland_Gym_Text_RematchDefeat, CinnabarIsland_Gym_EventScript_DefeatedLeaderRematch
	end

CinnabarIsland_Gym_Text_RematchPostgame::
	.string "O vulcao da Ilha de Cinnabar parece\n"
	.string "bastante ativo hoje!\p"
	.string "O que significa que meus Pokemon de\n"
	.string "Fogo estarao em plena forma tambem!\l"
	.string "Vamos la! Hah!$"

CinnabarIsland_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_BLAINE_REMATCH
	goto CinnabarIsland_Gym_EventScript_LeaderPostBattle
	end

CinnabarIsland_Gym_Text_RematchDefeat::
	.string "Hah! Estou pegando fogo!$"

CinnabarIsland_Gym_Text_GymGuyAdvice::
    .string "E ai!\n"
    .string "Futuro campeao!\p"
    .string "O esquentadinho do Blaine e fera\n"
    .string "com Pokemon de Fogo.\p"
    .string "Apague o fogo dele com agua!\p"
    .string "E bom levar alguns Burn Heals\n"
    .string "tambem.$"

CinnabarIsland_Gym_Text_GymGuyPostVictory::
    .string "{PLAYER}!\n"
    .string "Voce derrotou aquele esquentadinho!$"

CinnabarIsland_Gym_Text_GymStatue::
    .string "Ginasio Pokemon de Cinnabar\n"
    .string "Lider: Blaine\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

CinnabarIsland_Gym_Text_GymStatuePlayerWon::
    .string "Ginasio Pokemon de Cinnabar\n"
    .string "Lider: Blaine\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"

CinnabarIsland_Gym_Text_PokemonQuizRules::
    .string "Quiz Pokemon!\p"
    .string "Acerte e a porta se abre para a\n"
    .string "proxima sala.\p"
    .string "Erre e enfrente um treinador!\p"
    .string "Se quiser poupar seus Pokemon para\n"
    .string "o Lider do Ginasio...\p"
    .string "E melhor acertar!\n"
    .string "Aqui vamos nos!$"

CinnabarIsland_Gym_Text_QuizQuestion1::
    .string "Caterpie evolui para Metapod?$"

CinnabarIsland_Gym_Text_QuizQuestion2::
    .string "Existem 9 Insignias certificadas da\n"
    .string "Liga Pokemon?$"

CinnabarIsland_Gym_Text_QuizQuestion3::
    .string "Poliwag evolui 3 vezes?$"

CinnabarIsland_Gym_Text_QuizQuestion4::
    .string "Golpes Eletricos sao eficazes contra\n"
    .string "Pokemon do tipo Terrestre?$"

CinnabarIsland_Gym_Text_QuizQuestion5::
    .string "Pokemon da mesma especie e nivel\n"
    .string "nao sao identicos?$"

CinnabarIsland_Gym_Text_QuizQuestion6::
    .string "O TM28 contem Tombstony?$"

CinnabarIsland_Gym_Text_CorrectGoOnThrough::
    .string "Resposta certissima!\p"
    .string "Pode passar!$"

CinnabarIsland_Gym_Text_SorryBadCall::
    .string "Sinto muito!\n"
    .string "Resposta errada!$"
