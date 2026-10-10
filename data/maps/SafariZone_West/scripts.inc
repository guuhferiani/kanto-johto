SafariZone_West_MapScripts::
	.byte 0

SafariZone_West_EventScript_ItemTM32::
	finditem ITEM_TM32, 1
	release
	end

SafariZone_West_EventScript_ItemGoldTeeth::
	finditem ITEM_GOLD_TEETH, 1
	release
	end

SafariZone_West_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

SafariZone_West_EventScript_RestHouseSign::
	msgbox SafariZone_West_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_West_Text_RestHouse::
    .string "Casa de Repouso$"

SafariZone_West_EventScript_LostTeethNotice::
	msgbox SafariZone_West_Text_PleaseFindWardensLostTeeth, MSGBOX_SIGN
	end

SafariZone_West_Text_PleaseFindWardensLostTeeth::
    .string "Aviso de Procura\p"
    .string "Por favor, encontre os Dentes de Ouro\n"
    .string "perdidos do Guarda do Safári.\l"
    .string "Eles estão por aqui em algum lugar.\p"
    .string "Recompensa oferecida!\n"
    .string "Contato: Guarda$"

SafariZone_West_EventScript_TrainerTips::
	msgbox SafariZone_West_Text_SearchForSecretHouse, MSGBOX_SIGN
	end

SafariZone_West_Text_SearchForSecretHouse::
    .string "Dicas para Treinadores:\p"
    .string "Campanha de Exploração da Zona!\n"
    .string "Em Busca da Casa Secreta!$"

SafariZone_West_EventScript_AreaSign::
	msgbox SafariZone_West_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_West_Text_AreaSign::
    .string "Área 3\n"
    .string "Leste: Área Central$"
