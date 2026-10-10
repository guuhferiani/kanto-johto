FuchsiaCity_WardensHouse_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
    .string "Warden: Hif fuff hefifoo!\p"
    .string "Ha lof ha feef ee hafahi ho.\n"
    .string "Heff hee fwee!$"

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	checkplayergender
	msgbox FuchsiaCity_WardensHouse_Text_ThanksGiveYouSomething
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden
	waitfanfare
	additem ITEM_HM04, 1
	setflag FLAG_RECEIVED_HM04
	removeitem ITEM_GOLD_TEETH, 1
	release
	end

FuchsiaCity_WardensHouse_Text_ThanksGiveYouSomething::
    .string "Guarda: Obrigado!\n"
    .string "Você salvou a minha vida!\p"
    .string "Ninguém conseguia entender uma única\n"
    .string "palavra do que eu dizia, ninguém!\p"
    .string "Eu estava com tanta vergonha que nem\n"
    .string "pisava no Escritório.\p"
    .string "Deixe-me te dar algo pelo seu\n"
    .string "trabalho.$"

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
    .string "Ah howhee ho hoo!\n"
    .string "Eef ee hafahi ho!$"

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
    .string "Ha?\n"
    .string "He ohay heh ha hoo ee haheh!$"

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_Text_ExplainStrength::
    .string "Guarda: Dentro do MO04 você encontrará\n"
    .string "a Força.\p"
    .string "Ela permite aos Pokémon moverem pedregulhos\n"
    .string "quando estiver fora de batalha.\p"
    .string "Ah, sim, você encontrou a Casa Secreta\n"
    .string "na Zona do Safári?$"

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
    .string "{PLAYER} entregou os Dentes de Ouro\n"
    .string "para o Guarda.$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
    .string "O Guarda colocou seus dentes no lugar!$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
    .string "{PLAYER} recebeu o MO04\n"
    .string "do Guarda.$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
    .string "Fotos e fósseis de Pokémon estão em\n"
    .string "exibição.$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
    .string "Produtos antigos de Pokémon estão em\n"
    .string "exibição.$"

FuchsiaCity_WardensHouse_EventScript_PokemonJournalKoga::
	msgbox PokemonJournal_Text_SpecialFeatureKoga, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureKoga::
	.string "Revista Pokémon:\p"
	.string "Edição Especial: Líder de Ginásio\n"
	.string "de Fuchsia, Koga!\p"
	.string "Dizem que Koga tem um conhecimento\n"
	.string "profundo de medicina.\p"
	.string "Ele até fabrica remédios para cuidar da\n"
	.string "saúde de seus Pokémon.$"

FuchsiaCity_WardensHouse_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

