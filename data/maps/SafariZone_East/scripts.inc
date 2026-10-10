SafariZone_East_MapScripts::
	.byte 0

SafariZone_East_EventScript_RestHouseSign::
	msgbox SafariZone_East_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_East_Text_RestHouse::
    .string "Casa de Repouso$"

SafariZone_East_EventScript_TrainerTips::
	msgbox SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk, MSGBOX_SIGN
	end

SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk::
    .string "Dicas para Treinadores:\p"
    .string "O tempo restante só diminui\n"
    .string "enquanto você caminha.$"

SafariZone_East_EventScript_AreaSign::
	msgbox SafariZone_East_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_East_Text_AreaSign::
    .string "Área 1\n"
    .string "Oeste: Área Central$"

SafariZone_East_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION, 1
	release
	end

SafariZone_East_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE, 1
	release
	end

SafariZone_East_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE, 1
	release
	end

SafariZone_East_EventScript_ItemTM11::
	finditem ITEM_TM11, 1
	release
	end

SafariZone_East_EventScript_Kangaskhanite::
	finditem ITEM_KANGASKHANITE, 1
	setflag FLAG_GOT_KANGASKHANITE
	goto_if_unset FLAG_FIRST_MEGASTONE, SafariZone_East_EventScript_FoundMegaStone
    end

SafariZone_East_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
