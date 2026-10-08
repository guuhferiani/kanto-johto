.set LOCALID_OFFICER, 1
.set LOCALID_OLD_MAN, 2

ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianCity_OnResume
	.byte 0

ViridianCity_OnTransition:
	setflag FLAG_VISITED_VIRIDIAN_CITY
	call ViridianCity_CheckGymStatus
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_CheckGymStatus::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_Return
	setvar VAR_VIRIDIAN_CITY_GYM, 1
	return

ViridianCity_EventScripts_TeamRocketRumor1::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	applymovement LOCALID_OFFICER, Movement_OfficerBlockPath1
	waitmovement 1
	goto ViridianCity_EventScripts_TeamRocketRumor

Movement_OfficerBlockPath1:
	walk_left
	face_down
	step_end

ViridianCity_EventScripts_TeamRocketRumor2::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	goto ViridianCity_EventScripts_TeamRocketRumor

ViridianCity_EventScripts_TeamRocketRumor3::
	lockall
	setvar VAR_TEMP_1, 3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	applymovement LOCALID_OFFICER, Movement_OfficerBlockPath3
	waitmovement 1
	goto ViridianCity_EventScripts_TeamRocketRumor

Movement_OfficerBlockPath3:
	walk_right
	face_down
	step_end

Movement_PlayerApproachJenny:
	walk_up
	face_up
	step_end

ViridianCity_EventScripts_TeamRocketRumor::
	turnobject LOCALID_OFFICER, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_OFFICER, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OFFICER, Common_Movement_Delay48
	waitmovement 1
	msgbox ViridianCity_Text_InvestigatingTeamRocket, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 1, ViridianCity_EventScripts_ReturnJennyToPosition1
	call_if_eq VAR_TEMP_1, 3, ViridianCity_EventScripts_ReturnJennyToPosition2
	turnobject LOCALID_OFFICER, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepsBack
	waitmovement 0
	releaseall
	end

ViridianCity_Text_InvestigatingTeamRocket:
	.string "Policial: Estamos investigando o\n"
	.string "rumor de que a Equipe Rocket foi vista\l"
	.string "por esta área.\p"
	.string "Não podemos deixar ninguém passar até\n"
	.string "concluirmos nossa busca.$"

ViridianCity_EventScripts_ReturnJennyToPosition1::
	applymovement LOCALID_OFFICER, Movement_JennyStepsRight
	waitmovement 1
	return

Movement_JennyStepsRight:
	walk_right
	face_up
	step_end

ViridianCity_EventScripts_ReturnJennyToPosition2::
	applymovement LOCALID_OFFICER, Movement_JennyStepsLeft
	waitmovement 1
	return

Movement_JennyStepsLeft:
	walk_left
	face_up
	step_end

Movement_PlayerStepsBack:
	walk_down
	walk_down
	step_end


ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_Text_CitySign::
    .string "Viridian City\n"
    .string "O Paraíso Eternamente Verde$"

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_GymSign::
    .string "Ginásio Pokémon de Viridian City$"

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_Text_CatchMonsForEasierBattles::
    .string "Dicas para Treinadores:\p"
    .string "Capture Pokémon e amplie a\n"
    .string "sua coleção.\p"
    .string "Quanto mais você tiver, mais fácil\n"
    .string "será vencer batalhas.$"

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_Text_MovesLimitedByPP::
    .string "Dicas para Treinadores:\p"
    .string "Os golpes dos Pokémon são limitados\n"
    .string "pelos seus Pontos de Poder (PP).\p"
    .string "Para restaurar os PP, descanse seus\n"
    .string "Pokémon em um Centro Pokémon.$"

ViridianCity_EventScript_GymDoorLocked::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_StepAside
	waitmovement 0
	releaseall
	end

ViridianCity_Text_GymDoorsAreLocked::
    .string "As portas do Ginásio de Viridian\n"
    .string "estão trancadas…$"

ViridianCity_Movement_StepAside::
	walk_right
	step_end

ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_VIRIDIAN_CITY_GYM, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs, MSGBOX_DEFAULT
	turnobject LOCALID_OLD_MAN, DIR_NORTH
	waitmovement 2
	release
	end

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
    .string "Este Ginásio Pokémon está sempre fechado.\p"
    .string "Quem será o Líder daqui?$"

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_ViridiansGymLeaderReturned::
    .string "O Líder do Ginásio de Viridian voltou!$"

ViridianCity_EventScript_Boy::
	lock
	faceplayer
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_CanCarryMonsAnywhere::
    .string "Essas Pokébolas na sua cintura!\n"
    .string "Você tem Pokémon, não tem?\p"
    .string "É ótimo poder levar e usar seus\n"
    .string "Pokémon a qualquer hora, em qualquer lugar.$"

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_GoShoppingInPewterOccasionally::
    .string "De vez em quando vou fazer compras\n"
    .string "em Pewter City.\p"
    .string "Preciso atravessar a trilha sinuosa\n"
    .string "da Floresta de Viridian quando vou.$"

ViridianCity_EventScript_OldMan2::
	lock
	faceplayer
	msgbox ViridianCity_Text_UsedToGetGrumpy, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_UsedToGetGrumpy:
	.string "Eu costumava ficar muito ranzinza\n"
	.string "quando não tomava o meu café.\p"
	.string "Eu bloqueava a estrada e tudo mais!\p"
	.string "Era uma confusão daquelas...\p"
	.string "Por isso, minha neta me fez largar o café.\p"
	.string "Agora eu me sinto renovado fazendo caminhadas!$"

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ViridianCity_EventScript_YoungsterExplainCaterpillars
	compare VAR_RESULT, NO
	goto_if_eq ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
    .string "Quer saber sobre os dois tipos de\n"
    .string "Pokémon lagarta?$"

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	lock
	faceplayer
	msgbox ViridianCity_Text_ExplainCaterpieWeedle, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_ExplainCaterpieWeedle::
    .string "Caterpie não tem veneno,\n"
    .string "mas o Weedle tem.\p"
    .string "Cuidado para seu Pokémon não ser ferroado\n"
    .string "pela Picada Venenosa do Weedle.$"

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_OhOkayThen::
    .string "Ah, tudo bem então!$"

ViridianCity_FindItem_Potion::
	finditem ITEM_POTION, 1
	end

ViridianCity_EventScript_BerryTreeGuy::
	lock
	faceplayer
	msgbox ViridianCity_Text_PlantingBerries, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_PlantingBerries::
	.string "Parece que um Pokémon andou cavando\n"
	.string "na terra por aqui.\p"
	.string "O solo está bem fofinho...\n"
	.string "Eu devia plantar alguma Fruta aqui!$"

