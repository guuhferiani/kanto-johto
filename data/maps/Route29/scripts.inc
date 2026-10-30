Route29_MapScripts::
	.byte 0

Route29_EventScript_Boy::
	msgbox Route29_Text_Boy, MSGBOX_NPC
	end

Route29_EventScript_Cooltrainer::
	msgbox Route29_Text_Cooltrainer, MSGBOX_NPC
	end

Route29_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

Route29_EventScript_RouteSign::
	msgbox Route29_Text_RouteSign, MSGBOX_SIGN
	end

Route29_Text_Boy:
	.string "Na grama da Rota 29 e 30 vivem muitos\n"
	.string "Pokémon típicos de Johto, como Sentret,\l"
	.string "Hoothoot, Hoppip e Phanpy!$"

Route29_Text_Cooltrainer:
	.string "Logo ao norte fica Violet City!\p"
	.string "Dizem que o Líder Falkner treinou suas\n"
	.string "aves até o nível 60 para enfrentar\l"
	.string "desafiantes de Kanto!$"

Route29_Text_RouteSign:
	.string "ROTA 29 & 30\n"
	.string "Sul: New Bark Town / Norte: Violet City$"
