MahoganyTown_MapScripts::
	.byte 0

MahoganyTown_EventScript_Ninja::
	msgbox MahoganyTown_Text_Ninja, MSGBOX_NPC
	end

MahoganyTown_EventScript_RageCandyWoman::
	lock
	faceplayer
	msgbox MahoganyTown_Text_RageCandyWoman, MSGBOX_DEFAULT
	giveitem ITEM_LAVA_COOKIE, 1
	release
	end

MahoganyTown_EventScript_TownSign::
	msgbox MahoganyTown_Text_TownSign, MSGBOX_SIGN
	end

MahoganyTown_EventScript_GymSign::
	msgbox MahoganyTown_Text_GymSign, MSGBOX_SIGN
	end

MahoganyTown_Text_Ninja::
	.string "Bem-vindo a Mahogany Town, o lar\n"
	.string "dos ninjas tradicionais de Johto!\p"
	.string "Ao norte fica o Lago da Fúria,\n"
	.string "onde um Gyarados Vermelho gigante\l"
	.string "foi visto com o Campeão Lance!\p"
	.string "E a noroeste da cidade fica a\n"
	.string "entrada da caverna Ice Path rumo\l"
	.string "a Blackthorn City!$"

MahoganyTown_Text_RageCandyWoman::
	.string "Experimente a famosa iguaria de\n"
	.string "Mahogany Town: a RageCandyBar!\l"
	.string "Cura todos os problemas de status!$"

MahoganyTown_Text_TownSign::
	.string "MAHOGANY TOWN\n"
	.string "O Lar dos Ninjas!\l"
	.string "Norte: Lago da Fúria - Oeste: Ice Path$"

MahoganyTown_Text_GymSign::
	.string "GINÁSIO POKÉMON DE MAHOGANY TOWN\n"
	.string "Líder: Pryce\l"
	.string "O Professor das Tempestades de Inverno!$"
