Route11_EastEntrance_2F_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
	msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad
	releaseall
	end

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "Um Pokémon grandalhão está dormindo\n"
    .string "no meio da estrada!$"

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
	msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView
	releaseall
	end

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "Que vista de tirar o fôlego!$"

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "Para ir da Cidade de Cerulean até o\n"
    .string "Vilarejo de Lavender…\p"
    .string "O Túnel de Rocha parece ser um bom\n"
    .string "caminho a seguir.$"

Route11_EastEntrance_2F_EventScript_Turner::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORINA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_NIDORINA, Route11_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Route11_EastEntrance_2F_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route11_EastEntrance_2F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route11_EastEntrance_2F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route11_EastEntrance_2F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Route11_EastEntrance_2F_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_NIDORINA
	release
	end

Route11_EastEntrance_2F_Text_HeyThanks::
	.string "Ei, muito obrigado!$"

Route11_EastEntrance_2F_Text_LookingForMonWannaTradeForMon::
	.string "Oi!\n"
	.string "Você tem um {STR_VAR_1}?\p"
	.string "Quer trocar pelo meu\n"
	.string "{STR_VAR_2}?$"

Route11_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Route11_EastEntrance_2F_Text_DeclinedTrade
	release
	end

Route11_EastEntrance_2F_Text_DeclinedTrade::
	.string "Que pena.$"

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route11_EastEntrance_2F_Text_WhatThatsNotMon
	release
	end

Route11_EastEntrance_2F_Text_WhatThatsNotMon::
	.string "O quê?\n"
	.string "Esse não é um {STR_VAR_1}!$"

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Route11_EastEntrance_2F_Text_IsntMyOldMonGreat
	release
	end

Route11_EastEntrance_2F_Text_IsntMyOldMonGreat::
	.string "Como está o meu antigo {STR_VAR_2}?\n"
	.string "Meu {STR_VAR_1} está indo muito bem!$"

@Aide Gift 3
Route11_EastEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route11_EastEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_ITEMFINDER, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_ITEMFINDER, 1
    waitmessage
    setflag FLAG_RECEIVED_ITEMFINDER
    setflag FLAG_HIDE_AIDE_ROUTE11
    clearflag FLAG_AIDE_LOCATION_3
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route11_EastEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE05_GET, Route11_EastEntrance_2F_EventScript_AideNextLocation
    release
    end

Route11_EastEntrance_2F_Text_GiveReward::
    .string "Olá, {PLAYER}!\p"
    .string "O Prof. Carvalho disse que você está\n"
    .string "indo muito bem, então devo lhe entregar\l"
    .string "esta recompensa.$"

Route11_EastEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route11_EastEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_Text_ExplainReward::
    .string "Há itens no chão que podem estar\n"
    .string "ocultos da sua visão.\p"
    .string "Use o Detector de Itens para encontrar\n"
    .string "itens escondidos perto de você.\p"
    .string "A máquina é um pouco limitada.\n"
    .string "Ela não aponta a localização exata.\p"
    .string "O que ela faz é mostrar a direção\n"
    .string "em que o item está.\p"
    .string "Use-o para se orientar e depois\n"
    .string "procure na área suspeita manualmente.$"

Route11_EastEntrance_2F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_4
    return
