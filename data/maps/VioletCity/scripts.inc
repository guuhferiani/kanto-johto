VioletCity_MapScripts::
	.byte 0

VioletCity_EventScript_Elder::
	msgbox VioletCity_Text_Elder, MSGBOX_NPC
	end

VioletCity_EventScript_Woman::
	msgbox VioletCity_Text_Woman, MSGBOX_NPC
	end

VioletCity_EventScript_Youngster::
	msgbox VioletCity_Text_Youngster, MSGBOX_NPC
	end

VioletCity_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

VioletCity_EventScript_CitySign::
	msgbox VioletCity_Text_CitySign, MSGBOX_SIGN
	end

VioletCity_EventScript_GymSign::
	msgbox VioletCity_Text_GymSign, MSGBOX_SIGN
	end

VioletCity_EventScript_SproutTowerSign::
	msgbox VioletCity_Text_SproutTowerSign, MSGBOX_SIGN
	end

VioletCity_Text_Elder:
	.string "A Sprout Tower fica nos prédios\n"
	.string "tradicionais à esquerda da cidade.\p"
	.string "O Ancião Li testa a bondade e a força\n"
	.string "de todos os treinadores que a visitam!$"

VioletCity_Text_Woman:
	.string "Bem-vindo a Violet City, a cidade\n"
	.string "cercada por aromas nostálgicos!$"

VioletCity_Text_Youngster:
	.string "Falkner, o Líder do Ginásio de Violet,\n"
	.string "domina os céus com seus Pokémon Voadores!\p"
	.string "O Ginásio fica logo no prédio do\n"
	.string "canto superior direito!$"

VioletCity_Text_CitySign:
	.string "VIOLET CITY\n"
	.string "A Cidade Cercada por Aromas Nostálgicos$"

VioletCity_Text_GymSign:
	.string "GINÁSIO POKÉMON DE VIOLET CITY\n"
	.string "Líder: Falkner\l"
	.string "O Mestre Elegante dos Pokémon Voadores!$"

VioletCity_Text_SproutTowerSign:
	.string "SPROUT TOWER\n"
	.string "Compreenda o Caminho da Harmonia\l"
	.string "entre Humanos e Pokémon!$"
