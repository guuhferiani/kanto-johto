.set LOCALID_RIVAL, 2

SSAnne_2F_Corridor_MapScripts::
	.byte 0

SSAnne_2F_Corridor_EventScript_Sailor::
	msgbox SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner, MSGBOX_NPC
	end

SSAnne_2F_Corridor_Text_ThisShipIsLuxuryLiner::
    .string "Este navio é um transatlântico de luxo\n"
    .string "para treinadores de todo o mundo!\p"
    .string "A cada porto, damos festas com\n"
    .string "treinadores convidados.$"

SSAnne_2F_Corridor_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto SSAnne_2F_Corridor_EventScript_RivalTrigger
	end

SSAnne_2F_Corridor_EventScript_RivalTrigger::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_EXIT
	delay 5
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_RIVAL
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 2
	delay 20
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalApproachLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalApproachMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalApproachRight
	msgbox SSAnne_2F_Corridor_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	trainerbattle_no_intro TRAINER_RIVAL_SS_ANNE, SSAnne_2F_Corridor_Text_RivalDefeat
	msgbox SSAnne_2F_Corridor_Text_RivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SSAnne_2F_Corridor_EventScript_RivalExitLeft
	call_if_eq VAR_TEMP_1, 1, SSAnne_2F_Corridor_EventScript_RivalExitMid
	call_if_eq VAR_TEMP_1, 2, SSAnne_2F_Corridor_EventScript_RivalExitRight
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setvar VAR_SS_ANNE_STATE, 1
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

SSAnne_2F_Corridor_Text_RivalIntro::
    .string "{RIVAL}: Bonjour!\n"
    .string "{PLAYER}!\p"
    .string "Quem diria te ver por aqui!\n"
    .string "{PLAYER}, você foi mesmo convidado?\p"
    .string "E como vai a sua Pokédex?\p"
    .string "Eu já peguei 40 espécies, amigão.\n"
    .string "Há tipos diferentes por toda parte.\p"
    .string "Fique rastejando pela grama alta e\n"
    .string "procure bem por eles.$"

SSAnne_2F_Corridor_Text_RivalDefeat::
    .string "Humph!\p"
    .string "Pelo menos você anda treinando\n"
    .string "seus Pokémon!$"

SSAnne_2F_Corridor_Text_RivalPostBattle::
    .string "{RIVAL}: Ouvi falar que havia um\n"
    .string "mestre do Cortar a bordo.\p"
    .string "Mas não passava de um velho enjoado!\p"
    .string "Mas o Cortar em si é muito útil.\n"
    .string "É, vai quebrar um galho danado.\p"
    .string "Você deveria ir vê-lo também.\n"
    .string "Fui nessa!$"

SSAnne_2F_Corridor_EventScript_RivalApproachLeft::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachLeft
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalApproachLeft::
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_RivalApproachMid::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachMid
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalApproachMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalMid::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

SSAnne_2F_Corridor_EventScript_RivalApproachRight::
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalApproachRight
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalApproachRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_4
	step_end

SSAnne_2F_Corridor_Movement_PlayerFaceRivalRight::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

SSAnne_2F_Corridor_EventScript_RivalExitLeft::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitLeft
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_RivalExitMid::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitMid
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalExitMid::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SSAnne_2F_Corridor_EventScript_RivalExitRight::
	applymovement LOCALID_RIVAL, SSAnne_2F_Corridor_Movement_RivalExitRight
	waitmovement 2
	return

SSAnne_2F_Corridor_Movement_RivalExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
