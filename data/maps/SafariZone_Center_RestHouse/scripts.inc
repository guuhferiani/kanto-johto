SafariZone_Center_RestHouse_MapScripts::
	.byte 0

SafariZone_Center_RestHouse_EventScript_Sara::
	msgbox SafariZone_Center_Text_WhereDidErikGo, MSGBOX_NPC
	end

SafariZone_Center_Text_WhereDidErikGo::
    .string "Sara: Para onde foi o meu namorado,\n"
    .string "o Erik?$"

SafariZone_Center_RestHouse_EventScript_Scientist::
	msgbox SafariZone_Center_Text_CatchingMonsAsGifts, MSGBOX_NPC
	end

SafariZone_Center_Text_CatchingMonsAsGifts::
    .string "Estou capturando Pokémon para levar\n"
    .string "para casa de presente.$"


SafariZone_Center_RestHouse_EventScript_RangerF::
	msgbox SafariZone_Center_RestHouse_Text_RangerF, MSGBOX_NPC
	end

SafariZone_Center_RestHouse_Text_RangerF:
	.string "Se você usar {POKEBLOCK}s, os Pokémon selvagens\n"
	.string "não vão fugir tão rápido.\p"
	.string "Mas não adianta muito dar {POKEBLOCK}s para\n"
	.string "Pokémon que não fogem com facilidade.$"
