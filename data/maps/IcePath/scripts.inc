IcePath_MapScripts::
	.byte 0

IcePath_EventScript_GuideToBlackthorn::
	lock
	faceplayer
	msgbox IcePath_Text_AskBlackthorn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, IcePath_EventScript_Stay
	msgbox IcePath_Text_GoingToBlackthorn, MSGBOX_DEFAULT
	warp MAP_BLACKTHORN_CITY, 22, 22
	waitstate
	release
	end

IcePath_EventScript_Stay::
	msgbox IcePath_Text_Stay, MSGBOX_DEFAULT
	release
	end

IcePath_EventScript_ItemNeverMeltIce::
	finditem ITEM_NEVER_MELT_ICE, 1
	end

IcePath_Text_AskBlackthorn::
	.string "Montanhista: Este é o Caminho de\n"
	.string "Gelo (Ice Path)!\p"
	.string "Deseja atravessar o túnel congelado\n"
	.string "até Blackthorn City agora mesmo?$"

IcePath_Text_GoingToBlackthorn::
	.string "Cuidado para não escorregar no\n"
	.string "gelo! Vamos para Blackthorn City!$"

IcePath_Text_Stay::
	.string "Aproveite para capturar Pokémon\n"
	.string "de Gelo raros nesta caverna!$"
