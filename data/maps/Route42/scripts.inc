Route42_MapScripts::
	.byte 0

Route42_EventScript_Hiker::
	msgbox Route42_Text_Hiker, MSGBOX_NPC
	end

Route42_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	end

Route42_EventScript_RouteSign::
	msgbox Route42_Text_RouteSign, MSGBOX_SIGN
	end

Route42_Text_Hiker::
	.string "Esta é a montanhosa Rota 42, ao\n"
	.string "pé do Monte Mortar!\p"
	.string "Siga para o oeste ou atravesse o\n"
	.string "portão para chegar a Mahogany Town\l"
	.string "e ao famoso Lago da Fúria!$"

Route42_Text_RouteSign::
	.string "ROTA 42 (Monte Mortar)\n"
	.string "Leste: Ecruteak City\l"
	.string "Oeste: Mahogany Town$"
