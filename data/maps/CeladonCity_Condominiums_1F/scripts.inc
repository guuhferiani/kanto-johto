CeladonCity_Condominiums_1F_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_POSTGAME, CeladonCity_Condominiums_1F_EventScript_PostgameTeaWoman
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
    .string "Você não deveria gastar todo o seu\n"
    .string "dinheiro com bebidas.\p"
    .string "Experimente isto aqui.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
    .string "Nada mata a sede como um bom\n"
    .string "Chá quente.\p"
    .string "É realmente o melhor que há.$"

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
    .string "Meus queridos Pokémon me fazem companhia.\n"
    .string "Meowth até traz dinheiro para casa!$"

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	setflag FLAG_TALKED_TO_TEA_LADY_POSTGAME
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_PostgameTeaWoman::
	call_if_unset FLAG_DAILY_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_GetDailyTea
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_GetDailyTea::
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_Return
	msgbox CeladonCity_Condominiums_1F_Text_TakeThisDear
	release
	setflag FLAG_DAILY_GOT_TEA
	giveitem ITEM_TEA
	return

CeladonCity_Condominiums_1F_Text_TakeThisDear::
	.string "Veio buscar um pouco de Chá, anjo?$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
    .string "Ah, olá, benzinho.\n"
    .string "Gostou do meu Chá?\p"
    .string "A propósito, anjo. Você é, por acaso,\n"
    .string "do Vilarejo de Pallet?\p"
    .string "Uma garota do Vilarejo de Pallet, Daisy,\n"
    .string "ela adora o meu Chá todos os dias.\p"
    .string "Se algum dia quiser mais chá,\n"
    .string "é só vir me visitar.$"

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Meowth::
    .string "Meowth: Meow!$"

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Clefairy::
    .string "Clefairy: Pi pippippi!$"

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Nidoran::
    .string "Nidoran♀: Kya kyaoo!$"

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_ManagersSuite::
    .string "Mansão Celadon\n"
    .string "Suíte da Gerente$"
