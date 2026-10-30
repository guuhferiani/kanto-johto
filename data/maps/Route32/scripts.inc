Route32_MapScripts::
	.byte 0

Route32_EventScript_Fisherman::
	msgbox Route32_Text_Fisherman, MSGBOX_NPC
	end

Route32_EventScript_Camper::
	msgbox Route32_Text_Camper, MSGBOX_NPC
	end

Route32_EventScript_ItemShellBell::
	finditem ITEM_SHELL_BELL, 1
	release
	end

Route32_EventScript_RouteSign::
	msgbox Route32_Text_RouteSign, MSGBOX_SIGN
	end

Route32_Text_Fisherman::
	.string "As águas e campos da Rota 32 são\n"
	.string "famosos por abrigar Mareep, Wooper\l"
	.string "e até mesmo raros Ampharos!$"

Route32_Text_Camper::
	.string "Logo ao norte fica Azalea Town!\p"
	.string "Mas ouvi boatos de que homens de\n"
	.string "uniforme preto invadiram o Poço\l"
	.string "dos Slowpoke da cidade...$"

Route32_Text_RouteSign::
	.string "ROTA 32 & 33\n"
	.string "Sul: Violet City\l"
	.string "Norte: Azalea Town & Poço Slowpoke$"
