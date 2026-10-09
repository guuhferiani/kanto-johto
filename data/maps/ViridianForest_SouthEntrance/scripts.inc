ViridianForest_SouthEntrance_MapScripts::
	.byte 0

Route2_ViridianForest_SouthEntrance_EventScript_Woman1::
	msgbox Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze::
    .string "Você está indo para a Floresta\n"
    .string "de Viridian?\l"
    .string "É um labirinto natural lá dentro.\n"
    .string "Tome cuidado para não se perder.$"

Route2_ViridianForest_SouthEntrance_EventScript_Woman2::
	msgbox Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite::
    .string "Rattata pode ser pequeno, mas não\n"
    .string "subestime sua mordida feroz.\p"
    .string "Você já conseguiu capturar um?$"
