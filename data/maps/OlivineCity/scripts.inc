OlivineCity_MapScripts::
	.byte 0

OlivineCity_EventScript_Sailor::
	msgbox OlivineCity_Text_Sailor, MSGBOX_NPC
	end

OlivineCity_EventScript_ItemMetalCoat::
	finditem ITEM_METAL_COAT, 1
	release
	end

OlivineCity_EventScript_LighthouseSign::
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CitySign::
	msgbox OlivineCity_Text_CitySign, MSGBOX_SIGN
	end

OlivineCity_Text_Sailor::
	.string "Bem-vindo ao porto de Olivine City!\p"
	.string "O Farol cintilante fica a sudeste,\n"
	.string "o Ginásio de Jasmine a sudoeste,\l"
	.string "e nadando pelo canal marítimo ao\l"
	.string "norte (Rota 40/41) você chegará\l"
	.string "à ilha de Cianwood City!$"

OlivineCity_Text_LighthouseSign::
	.string "FAROL DE OLIVINE (GLITTER LIGHTHOUSE)\n"
	.string "A Luz Guia dos Mares de Johto$"

OlivineCity_Text_GymSign::
	.string "GINÁSIO POKÉMON DE OLIVINE CITY\n"
	.string "Líder: Jasmine\l"
	.string "A Garota com Defesa de Aço Puro!$"

OlivineCity_Text_CitySign::
	.string "OLIVINE CITY\n"
	.string "O Porto Onde se Ouvem as Melodias\l"
	.string "do Mar\p"
	.string "Norte: Canal Marítimo Rota 40 &\n"
	.string "Cianwood City$"
