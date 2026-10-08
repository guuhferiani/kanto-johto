.set LOCALID_DAISY, 1

PalletTown_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	goto_if_le VAR_OAK_LAB_STATE, 7, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
    .string "É um grande mapa da região de Kanto.\p"
    .string "Não é bem mais fácil usar o mapa\n"
    .string "do seu PokéGear?!$"

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
    .string "As estantes estão cheias de livros\n"
    .string "sobre Pokémon.$"

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	goto_if_le VAR_OAK_LAB_STATE, 3, PalletTown_RivalsHouse_EventScript_Daisy1
	goto_if_le VAR_OAK_LAB_STATE, 4, PalletTown_RivalsHouse_EventScript_Daisy2
	goto_if_unset FLAG_REGISTERED_RIVAL, PalletTown_RivalsHouse_EventScript_Daisy3
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
    .string "Daisy: Assim como nós, os Pokémon\n"
    .string "são seres vivos.\p"
    .string "Quando ficarem cansados, por favor,\n"
    .string "dê um descanso a eles.$"

PalletTown_RivalsHouse_EventScript_Daisy1::
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab, MSGBOX_DEFAULT
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
    .string "Daisy: Olá, {PLAYER}!\p"
    .string "Meu irmão, {RIVAL}, está no\n"
    .string "laboratório do Vovô.$"

PalletTown_RivalsHouse_EventScript_Daisy2::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival, MSGBOX_DEFAULT
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
    .string "Daisy: {PLAYER}, soube que você teve\n"
    .string "uma batalha contra {RIVAL}.\p"
    .string "Queria ter visto isso!$"

PalletTown_RivalsHouse_EventScript_Daisy3::
	goto_if_le VAR_OAK_LAB_STATE, 7, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	msgbox PalletTown_RivalsHouse_Text_GetRivalNumber, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredRival, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_RIVAL
	setflag FLAG_REGISTERED_DAISY
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_GetRivalNumber::
    .string "O Vovô te pediu um favor?\p"
    .string "E o {RIVAL} nem quis te passar\n"
    .string "o número dele?\p"
    .string "Nossa, que falta de educação a dele.\n"
    .string "Aqui, deixa eu te ajudar.$"

PalletTown_RivalsHouse_EventScript_GroomMon:: @TODO
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_DAISY, Common_Movement_Heart
	applymovement LOCALID_DAISY, Common_Movement_Delay48
	waitmovement 1
	release
	end

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
    .string "Daisy: Olá, {PLAYER}!\n"
    .string "Chegou na hora certa.\p"
    .string "Estou prestes a tomar um chá.\n"
    .string "Gostaria de me acompanhar?\p"
    .string "Ah, mas veja só.\n"
    .string "Seus Pokémon estão meio sujinhos.\p"
    .string "Quer que eu cuide de um deles?$"

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
    .string "Não precisa de cuidados agora?\n"
    .string "Tudo bem, vamos apenas tomar um chá.$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
    .string "De qual deles devo cuidar?$"

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
    .string "Ah, desculpe. Eu realmente não posso\n"
    .string "escovar um Ovo.$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
    .string "Daisy: Certo, vai ficar impecável\n"
    .string "num instante.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
    .string "{STR_VAR_1} parece muito satisfeito…\p"
    .string "Daisy: Prontinho! Terminei.\n"
    .string "Viu? Não ficou lindo?\p"
    .string "Risinhos…\n"
    .string "É um Pokémon tão adorável.$"


PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
    .string "Daisy: Seus Pokémon passam a te amar\n"
    .string "se você criá-los com carinho.\p"
    .string "Por exemplo, {PLAYER}, posso dar uma olhada\n"
    .string "no seu primeiro Pokémon?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
    .string "…Hum, não é fácil dizer isso, mas…\p"
    .string "Há algum motivo para o seu Pokémon\n"
    .string "te odiar tanto assim?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
    .string "{PLAYER}, não gosto do jeito que ele\n"
    .string "olha bravo para você.\p"
    .string "Você poderia tentar ser um pouco\n"
    .string "mais gentil com ele?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
    .string "Ele ainda não está muito acostumado\n"
    .string "com você.\p"
    .string "Pokémon costumam ser receosos quando\n"
    .string "acabamos de conhecê-los.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
    .string "Ele está começando a gostar de você.\n"
    .string "A confiança entre vocês deve estar crescendo.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
    .string "Ele é bastante apegado a você.\n"
    .string "Continue cuidando bem dele!$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
    .string "Ele parece muito feliz.\p"
    .string "Queria que o {RIVAL} visse isso e\n"
    .string "aprendesse algo com você.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
    .string "Ele não poderia te amar mais do que\n"
    .string "já ama agora.\p"
    .string "Seu Pokémon está incrivelmente feliz!$"



