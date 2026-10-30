Route34_MapScripts::
	.byte 0

Route34_EventScript_DayCareLady::
	msgbox Route34_Text_DayCareLady, MSGBOX_NPC
	end

Route34_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

Route34_EventScript_RouteSign::
	msgbox Route34_Text_RouteSign, MSGBOX_SIGN
	end

Route34_Text_DayCareLady::
	.string "Bem-vindo à Rota 34!\n"
	.string "Muitos Ditto, Snubbull e Abra vivem\l"
	.string "na grama alta desta rota.\p"
	.string "Siga para a esquerda para entrar\n"
	.string "na metrópole de Goldenrod City!$"

Route34_Text_RouteSign::
	.string "ROTA 34\n"
	.string "Oeste: Goldenrod City\l"
	.string "Portão Leste: Floresta Ilex$"
