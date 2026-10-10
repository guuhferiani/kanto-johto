SafariZone_Center_MapScripts::
	.byte 0

SafariZone_Center_EventScript_RestHouseSign::
	msgbox SafariZone_Center_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_Center_Text_RestHouse::
    .string "Casa de Repouso$"

SafariZone_Center_EventScript_TrainerTips::
	msgbox SafariZone_Center_Text_PressStartToCheckTime, MSGBOX_SIGN
	end

SafariZone_Center_Text_PressStartToCheckTime::
    .string "Dicas para Treinadores:\p"
	.string "Se você colocar um {POKEBLOCK} em um Alimentador,\n"
	.string "os Pokémon vão se reunir ao redor.$"

SafariZone_Center_EventScript_AreaSign::
	msgbox SafariZone_Center_Text_CenterArea, MSGBOX_SIGN
	end

SafariZone_Center_Text_CenterArea::
    .string "Área Central$"


SafariZone_Center_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

SafariZone_Center_EventScript_Pinsirte::
	finditem ITEM_PINSIRITE, 1
	setflag FLAG_GOT_PINSIRITE
	goto_if_unset FLAG_FIRST_MEGASTONE, SafariZone_Center_EventScript_FoundMegaStone
    end

SafariZone_Center_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
