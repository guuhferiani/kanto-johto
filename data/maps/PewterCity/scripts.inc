.set LOCALID_MUSEUM_GUIDE, 2
.set LOCALID_GYM_GUIDE, 5
.set LOCALID_LADY, 14
.set LOCALID_SLOWPOKE, 13
.set LOCALID_FUGITIVE, 15

@VAR_PEWTER_CITY_STATE
@0 = Brock Undefeated
@1 = Brock Defeated

PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PewterCity_OnResume
	.byte 0

PewterCity_OnTransition:
	setflag FLAG_VISITED_PEWTER_CITY
	goto_if_unset FLAG_REGISTERED_AIDE, PewterCity_EventScript_Cedar
	setvar VAR_PEWTER_CITY_MUSEUM_STATE, 0
	call Common_EventScript_GetDayOrNight
	end

PewterCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

PewterCity_EventScript_Cedar::
	setvar VAR_TEMP_0, 255
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PEWTER_CITY_MUSEUM_STATE, 0
	call Common_EventScript_GetDayOrNight
	end

PewterCity_Trigger_RegisterOakAide::
	goto_if_set FLAG_REGISTERED_AIDE, Common_EventScript_End
	lockall
	goto_if_unset FLAG_MET_CEDAR, PewterCity_Trigger_RegisterOakAideAlternate
	pokenavcall MatchCall_Text_AideIntro
	waitmessage
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOaksAide, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_AIDE
	setflag FLAG_HIDE_AIDE_OAK_LAB
	setvar VAR_TEMP_0, 0
	releaseall
	end

PewterCity_Trigger_RegisterOakAideAlternate::
	pokenavcall MatchCall_Text_AideIntro2
	waitmessage
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOaksAide, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_AIDE
	setflag FLAG_HIDE_AIDE_OAK_LAB
	releaseall
	end

PewterCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_BrockOnlySeriousTrainerHere::
    .string "Não há muitos Treinadores Pokémon\n"
    .string "sérios por aqui.\p"
    .string "Eles são todos como Caçadores de Insetos,\n"
    .string "sabe, apenas por passatempo.\p"
    .string "Mas o Brock do Ginásio de Pewter não é\n"
    .string "nada disso, nem um pouco.$"


PewterCity_EventScript_MuseumGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
	msgbox PewterCity_Text_ReallyYouHaveToGo, MSGBOX_DEFAULT
	closemessage
	delay 10
	playbgm MUS_RG_FOLLOW_ME, 0
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
	goto_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
	end

PewterCity_Text_DidYouCheckOutMuseum::
    .string "Você já deu uma olhada no Museu?$"

PewterCity_Text_ReallyYouHaveToGo::
    .string "Sério?\n"
    .string "Você tem que ir lá agora mesmo!$"

PewterCity_EventScript_LeadToMuseumNorth::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumNorth::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumNorth::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_LeadToMuseumSouth::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumSouth::
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumSouth::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_LeadToMuseumWest::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumWest::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumWest::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_LeadToMuseumEast::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumEast::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumEast::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_MuseumGuideFinished::
	msgbox PewterCity_Text_ThisIsTheMuseum, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_MUSEUM_GUIDE
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
	release
	end

PewterCity_Movement_MuseumGuideExit::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Text_ThisIsTheMuseum::
    .string "Aqui está, o Museu.\p"
    .string "Você tem que pagar para entrar, mas\n"
    .string "vale muito a pena. A gente se vê!$"

PewterCity_EventScript_CheckedOutMuseum::
	msgbox PewterCity_Text_WerentThoseFossilsAmazing, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_WerentThoseFossilsAmazing::
    .string "Aqueles fósseis do Monte Moon não são\n"
    .string "simplesmente incríveis?$"

PewterCity_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_DoYouKnowWhatImDoing::
    .string "Psiuuu!\n"
    .string "Você sabe o que eu estou fazendo?$"

PewterCity_Text_SprayingRepelToKeepWildMonsOut::
    .string "Estou borrifando Repelente para manter\n"
    .string "Pokémon selvagens longe do meu jardim!$"

PewterCity_EventScript_KnowWhatTheyreDoing::
	msgbox PewterCity_Text_ThatsRightItsHardWork, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_ThatsRightItsHardWork::
    .string "É isso aí!\n"
    .string "Dá o maior trabalho!$"

PewterCity_EventScript_Lass::
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
	end

PewterCity_Text_ClefairyCameFromMoon::
    .string "Os Clefairy vieram da lua.\n"
    .string "É isso que dizem os boatos.\p"
    .string "Eles surgiram depois que as Pedras\n"
    .string "da Lua caíram no Monte Moon.$"


PewterCity_EventScript_GymGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_FOLLOW_ME, 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWaitForGuideEast::
	delay_16
	delay_16
	delay_4
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

PewterCity_Movement_GuideMoveToLeadEast::
	walk_down
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_up
	walk_in_place_up
	step_end

PewterCity_Movement_GuideWalkToGymEast::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_Movement_PlayerWalkToGymEast::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_EventScript_GymGuideTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTrigger::
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_FOLLOW_ME, 0
	goto_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
	goto_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
	goto_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
	end

PewterCity_EventScript_WalkToGymTop::
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWalkToGymTop::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_GuideMoveToLeadTop::
	walk_left
	walk_down
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_right
	walk_in_place_right
	step_end

PewterCity_Movement_GuideWalkToGymTop::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_EventScript_WalkToGymMid::
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWalkToGymMid::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_GuideMoveToLeadMid::
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideWalkToGymMid::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_EventScript_WalkToGymBottom::
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWalkToGymBottom::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_GuideMoveToLeadBottom::
	walk_down
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideWalkToGymBottom::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_EventScript_GymGuideFinish::
	msgbox PewterCity_Text_GoTakeOnBrock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GymGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	release
	end

PewterCity_Movement_GymGuideExit::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Text_GoTakeOnBrock::
    .string "Se você tem o que é preciso,\n"
    .string "vá desafiar o Brock!$"

PewterCity_Text_BrocksLookingForChallengersFollowMe::
    .string "Você é um Treinador, certo?\p"
    .string "Brock está procurando novos\n"
    .string "desafiantes. Siga-me!$"

PewterCity_EventScript_TrainerTips::
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
	end

PewterCity_Text_TrainerTipsEarningEXP::
    .string "Dicas para Treinadores:\p"
    .string "Todos os Pokémon que entram em batalha,\n"
    .string "mesmo que brevemente, ganham Pontos de Exp.$"


PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
	end

PewterCity_Text_CitySign::
    .string "Cidade de Pewter\n"
    .string "A Cidade Cinzenta como Pedra$"

PewterCity_EventScript_PoliceNotice::
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
	end

PewterCity_Text_CallPoliceIfInfoOnThieves::
    .string "AVISO!\p"
    .string "Ladrões têm roubado fósseis de\n"
    .string "Pokémon no Monte Moon.\p"
    .string "Por favor, acione a Polícia de Pewter\n"
    .string "se tiver qualquer informação.$"

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
	end

PewterCity_Text_MuseumOfScience::
    .string "Museu de Ciências da Cidade de Pewter$"

PewterCity_EventScript_GymSign::
	lockall
	msgbox PewterCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

PewterCity_Text_GymSign::
    .string "Ginásio Pokémon da Cidade de Pewter\n"
    .string "Líder: Brock\l"
    .string "O Treinador Sólido como Rocha!$"


PewterCity_EventScript_SlowpokeLady::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_MIXING_BERRY, PewterCity_EventScript_WatchedSlowpoke
	msgbox PewterCity_Text_RunAnErrand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_WatchSlowpoke
	msgbox PewterCity_Text_MaybeLater, MSGBOX_NPC
	release
	end

PewterCity_Text_RunAnErrand::
	.string "Oh, olá.\p"
	.string "Meu Slowpoke adora vir aqui para ver\n"
	.string "as Frutas comigo.\p"
	.string "Normalmente é uma delícia, mas preciso\n"
	.string "resolver um compromisso hoje...\p"
	.string "Poderia ficar aqui com o Slowpoke por um\n"
	.string "momento para que eu possa sair?$"

PewterCity_Text_MaybeLater::
	.string "Ah, acho que posso resolver isso mais\n"
	.string "tarde, então...$"


PewterCity_EventScript_WatchSlowpoke::
	msgbox PewterCity_Text_WatchSlowpoke, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LadyLeave1
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LadyLeave2
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LadyLeave3
	waitmovement 14
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE, Common_Movement_QuestionMark
	waitse
	waitmovement 13
	fadescreen FADE_TO_BLACK
	delay 48
	delay 48
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	waitmoncry
	delay 48
	delay 48
	fadescreen FADE_FROM_BLACK
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE, Common_Movement_QuestionMark
	waitse
	waitmovement 13
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LadyReturn1
	call_if_eq VAR_FACING, DIR_EAST,	PewterCity_EventScript_LadyReturn2
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LadyReturn3
	waitmovement 14
	msgbox PewterCity_Text_ThankYouForWatchingSlowpoke, MSGBOX_NPC
	random 14
	call_if_eq VAR_RESULT, 0, PewterCity_EventScript_GiveBelueBerry
	call_if_eq VAR_RESULT, 1, PewterCity_EventScript_GiveDurinBerry
	call_if_eq VAR_RESULT, 2, PewterCity_EventScript_GiveWatmelBerry
	call_if_eq VAR_RESULT, 3, PewterCity_EventScript_GivePamtreBerry
	call_if_eq VAR_RESULT, 4, PewterCity_EventScript_GiveSpelonBerry
	call_if_eq VAR_RESULT, 5, PewterCity_EventScript_GiveNomelBerry
	call_if_eq VAR_RESULT, 6, PewterCity_EventScript_GiveRabutaBerry
	call_if_eq VAR_RESULT, 7, PewterCity_EventScript_GiveMagostBerry
	call_if_eq VAR_RESULT, 8, PewterCity_EventScript_GiveCornnBerry
	call_if_eq VAR_RESULT, 9, PewterCity_EventScript_GivePinapBerry
	call_if_eq VAR_RESULT, 10, PewterCity_EventScript_GiveWepearBerry
	call_if_eq VAR_RESULT, 11, PewterCity_EventScript_GiveNanabBerry
	call_if_eq VAR_RESULT, 12, PewterCity_EventScript_GiveBlukBerry
	call_if_eq VAR_RESULT, 13, PewterCity_EventScript_GiveRazzBerry
	setflag FLAG_DAILY_MIXING_BERRY
	goto PewterCity_EventScript_WatchedSlowpoke
	end

PewterCity_EventScript_WatchedSlowpoke::
	msgbox PewterCity_Text_SlowpokeLovesPokeblocks, MSGBOX_NPC
	release
	end

PewterCity_Text_SlowpokeLovesPokeblocks::
	.string "Meu Slowpoke aqui adora os Pokéblocos\n"
	.string "que são feitos com essas Frutas.\p"
	.string "Quem me dera poder fazer os meus\n"
	.string "próprios em casa!$"

PewterCity_EventScript_GiveBelueBerry::
	giveitem ITEM_BELUE_BERRY, 1
	return

PewterCity_EventScript_GiveDurinBerry::
	giveitem ITEM_DURIN_BERRY, 1
	return

PewterCity_EventScript_GiveWatmelBerry::
	giveitem ITEM_WATMEL_BERRY, 1
	return

PewterCity_EventScript_GivePamtreBerry::
	giveitem ITEM_PAMTRE_BERRY, 1
	return

PewterCity_EventScript_GiveSpelonBerry::
	giveitem ITEM_SPELON_BERRY, 1
	return

PewterCity_EventScript_GiveNomelBerry::
	giveitem ITEM_NOMEL_BERRY, 1
	return

PewterCity_EventScript_GiveRabutaBerry::
	giveitem ITEM_RABUTA_BERRY, 1
	return

PewterCity_EventScript_GiveMagostBerry::
	giveitem ITEM_MAGOST_BERRY, 1
	return

PewterCity_EventScript_GiveCornnBerry::
	giveitem ITEM_CORNN_BERRY, 1
	return

PewterCity_EventScript_GivePinapBerry::
	giveitem ITEM_PINAP_BERRY, 1
	return

PewterCity_EventScript_GiveWepearBerry::
	giveitem ITEM_WEPEAR_BERRY, 1
	return

PewterCity_EventScript_GiveNanabBerry::
	giveitem ITEM_NANAB_BERRY, 1
	return

PewterCity_EventScript_GiveBlukBerry::
	giveitem ITEM_BLUK_BERRY, 1
	return

PewterCity_EventScript_GiveRazzBerry::
	giveitem ITEM_RAZZ_BERRY, 1
	return

PewterCity_Text_ThankYouForWatchingSlowpoke::
	.string "Desculpe pela demora!\p"
	.string "Deixe-me dar isto a você por ter\n"
	.string "me ajudado.$"

PewterCity_Text_WatchSlowpoke::
	.string "Oh, muito obrigada!\n"
	.string "Não vou demorar quase nada!$"


PewterCity_EventScript_LadyLeave1:
	applymovement LOCALID_LADY, Movement_LadyLeave1
	return

PewterCity_EventScript_LadyLeave2:
	applymovement LOCALID_LADY, Movement_LadyLeave2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

PewterCity_EventScript_LadyLeave3:
	applymovement LOCALID_LADY, Movement_LadyLeave1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

Movement_LadyLeave1:
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

Movement_LadyLeave2:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PewterCity_EventScript_LadyReturn1::
	applymovement LOCALID_LADY, Movement_LadyReturn1
	return

PewterCity_EventScript_LadyReturn2::
	applymovement LOCALID_LADY, Movement_LadyReturn2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

PewterCity_EventScript_LadyReturn3::
	applymovement LOCALID_LADY, Movement_LadyReturn1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Movement_LadyReturn1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Movement_LadyReturn2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PewterCity_EventScript_Slowpoke::
	lock
	faceplayer
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE, Common_Movement_QuestionMark
	waitse
	waitmovement 13
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end
	end

PewterCity_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
