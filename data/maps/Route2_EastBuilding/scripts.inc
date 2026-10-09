Route2_EastBuilding_MapScripts::
	.byte 0

@Aide Gift 1
Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05, MSGBOX_DEFAULT
	checkitemspace ITEM_HM05, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_HM05, 1
	waitmessage
	setflag FLAG_RECEIVED_HM05
	setflag FLAG_HIDE_AIDE_ROUTE2
	clearflag FLAG_AIDE_LOCATION_1
	clearflag FLAG_QUEUE_AIDE_CALL
	setvar VAR_AIDE_CALL_STEP_COUNTER, 0
	call_if_set FLAG_BADGE03_GET, Route2_EastBuilding_EventScript_AideNextLocation
	msgbox Route2_EastBuilding_Text_ExplainHM05, MSGBOX_DEFAULT
	release
	end

Route2_EastBuilding_Text_GiveHM05::
    .string "Olá! Obrigado por vir me encontrar,\n"
    .string "{PLAYER}.\p"
    .string "Estivemos monitorando o seu\n"
    .string "progresso lá no laboratório!\l"
    .string "Você está indo muito bem!\p"
    .string "Estou aqui para entregar sua\n"
    .string "recompensa.\p"
    .string "O Professor Carvalho me confiou o\n"
    .string "HM05 para você.$"

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05, MSGBOX_DEFAULT
	release
	end

Route2_EastBuilding_Text_ExplainHM05::
    .string "O HM05 contém a técnica secreta\n"
    .string "Flash.\p"
    .string "Flash ilumina até as cavernas mais\n"
    .string "escuras e sombrias.$"

Route2_EastBuilding_EventScript_AideNextLocation::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_2
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
    .string "Depois que um Pokémon aprender\n"
    .string "Flash, você poderá atravessar\l"
    .string "o Túnel de Rocha com facilidade.$"
