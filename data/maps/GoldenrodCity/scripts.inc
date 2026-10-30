GoldenrodCity_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Beauty::
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RadioGuard::
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_GOLDENROD_RADIO_TOWER, GoldenrodCity_EventScript_RadioGuardSaved
	msgbox GoldenrodCity_Text_RadioGuardDanger, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_RadioGuardSaved::
	msgbox GoldenrodCity_Text_RadioGuardSaved, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_GymFan::
	msgbox GoldenrodCity_Text_GymFan, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CitySign::
	msgbox GoldenrodCity_Text_CitySign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GymSign::
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RadioTowerSign::
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_DeptStoreSign::
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

GoldenrodCity_Text_Beauty::
	.string "Goldenrod City é a maior e mais\n"
	.string "vibrante metrópole de toda Johto!\p"
	.string "A Loja de Departamentos a noroeste\n"
	.string "vende todas as Pedras Evolutivas!$"

GoldenrodCity_Text_RadioGuardDanger::
	.string "Socorro! Executivos da Equipe Rocket\n"
	.string "tomaram a Torre de Rádio logo aqui\l"
	.string "atrás e fizeram o Diretor refém!$"

GoldenrodCity_Text_RadioGuardSaved::
	.string "Você libertou a Torre de Rádio de\n"
	.string "Goldenrod! As transmissões de Johto\l"
	.string "voltaram ao normal!$"

GoldenrodCity_Text_GymFan::
	.string "Whitney é super popular, mas o\n"
	.string "Rollout e o Milk Drink da Miltank\l"
	.string "dela já fizeram muitos treinadores\l"
	.string "chorarem!$"

GoldenrodCity_Text_CitySign::
	.string "GOLDENROD CITY\n"
	.string "A Festiva Cidade do Charme Opulento$"

GoldenrodCity_Text_GymSign::
	.string "GINÁSIO POKÉMON DE GOLDENROD CITY\n"
	.string "Líder: Whitney\l"
	.string "A Garota Incrivelmente Bonita!$"

GoldenrodCity_Text_RadioTowerSign::
	.string "TORRE DE RÁDIO DE GOLDENROD\n"
	.string "Sintonize a Voz de Johto!$"

GoldenrodCity_Text_DeptStoreSign::
	.string "CENTRO COMERCIAL DE GOLDENROD\n"
	.string "Suprimentos de Elite & Pedras de\l"
	.string "Evolução!$"
