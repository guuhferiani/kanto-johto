Route18_EastEntrance_2F_MapScripts::
	.byte 0

Route18_EastEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route18_EastEntrance_2F_Text_PalletTownInWest, MSGBOX_SIGN
	end

Route18_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route18_EastEntrance_2F_Text_PeopleSwimming, MSGBOX_SIGN
	end

Route18_EastEntrance_2F_EventScript_LittleGirl::
	lock
	goto_if_set FLAG_GOT_PROTECTIVE_PADS, Route18_EastEntrance_2F_EventScript_LittleGirl2
	msgbox Route18_EastEntrance_2F_Text_TakeThesePads, MSGBOX_NPC
	giveitem ITEM_PROTECTIVE_PADS, 1
	setflag FLAG_GOT_PROTECTIVE_PADS
	release
	end

Route18_EastEntrance_2F_Text_TakeThesePads::
	.string "As pessoas andam muito rápido de bike\n"
	.string "na Rodovia dos Ciclistas.\p"
	.string "Você devia levar isto caso leve\n"
	.string "um tombo!$"

Route18_EastEntrance_2F_EventScript_LittleGirl2::
	msgbox Route18_EastEntrance_2F_Text_Safety, MSGBOX_NPC
	release
	end

Route18_EastEntrance_2F_Text_Safety::
	.string "Segurança é fundamental!$"

Route18_EastEntrance_2F_Text_PalletTownInWest::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "Pallet fica a oeste daqui.$"

Route18_EastEntrance_2F_Text_PeopleSwimming::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "Há pessoas nadando.$"

Route18_EastEntrance_2F_EventScript_Haden::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_LICKITUNG
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_LICKITUNG, Route18_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Route18_EastEntrance_2F_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route18_EastEntrance_2F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route18_EastEntrance_2F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route18_EastEntrance_2F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Route18_EastEntrance_2F_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_LICKITUNG
	release
	end

Route18_EastEntrance_2F_Text_HeyThanks::
	.string "Ei, muito obrigado!$"

Route18_EastEntrance_2F_Text_LookingForMonWannaTradeForMon::
	.string "Oi!\n"
	.string "Você tem um {STR_VAR_1}?\p"
	.string "Quer trocá-lo pelo meu\n"
	.string "{STR_VAR_2}?$"

Route18_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Route18_EastEntrance_2F_Text_DeclinedTrade
	release
	end

Route18_EastEntrance_2F_Text_DeclinedTrade::
	.string "Que pena.$"

Route18_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route18_EastEntrance_2F_Text_WhatThatsNotMon
	release
	end

Route18_EastEntrance_2F_Text_WhatThatsNotMon::
	.string "…Isto não é um {STR_VAR_1}.\p"
	.string "Se conseguir um, por favor, troque\n"
	.string "comigo!$"

Route18_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Route18_EastEntrance_2F_Text_IsntMyOldMonGreat
	release
	end

Route18_EastEntrance_2F_Text_IsntMyOldMonGreat::
	.string "Como está meu antigo {STR_VAR_2}?\n"
	.string "Meu {STR_VAR_1} está indo muito bem!$"
