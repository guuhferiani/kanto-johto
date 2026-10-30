.set LOCALID_BEASTS, 2

BurnedTower_MapScripts::
	.byte 0

BurnedTower_EventScript_Eusine::
	lock
	faceplayer
	goto_if_set FLAG_AWAKENED_BURNED_TOWER_BEASTS, BurnedTower_EventScript_EusineAfter
	msgbox BurnedTower_Text_EusineIntro, MSGBOX_DEFAULT
	release
	end

BurnedTower_EventScript_EusineAfter::
	msgbox BurnedTower_Text_EusineAfter, MSGBOX_DEFAULT
	release
	end

BurnedTower_EventScript_BeastsAltar::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	msgbox BurnedTower_Text_BeastsAwaken, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 65, ITEM_MYSTIC_WATER
	dowildbattle
	removeobject LOCALID_BEASTS
	setflag FLAG_AWAKENED_BURNED_TOWER_BEASTS
	msgbox BurnedTower_Text_RaikouEnteiRoam, MSGBOX_DEFAULT
	release
	end

BurnedTower_Text_EusineIntro::
	.string "Eusine: Meu nome é Eusine!\n"
	.string "Estou buscando o lendário Suicune\l"
	.string "por toda Johto!\p"
	.string "Olhe no altar à frente: as três\n"
	.string "Feras Lendárias ressuscitadas por\l"
	.string "Ho-Oh estão prestes a despertar!$"

BurnedTower_Text_BeastsAwaken::
	.string "Raikou e Entei dispararam como\n"
	.string "relâmpago e fogo pelas rotas de\l"
	.string "Johto!\p"
	.string "Mas Suicune permaneceu diante de\n"
	.string "você para testar sua coragem!$"

BurnedTower_Text_RaikouEnteiRoam::
	.string "Raikou e Entei agora percorrem as\n"
	.string "rotas selvagens de Johto (Rota 36\l"
	.string "e Rota 38)!$"

BurnedTower_Text_EusineAfter::
	.string "Eusine: Magnífico! Suicune reconheceu\n"
	.string "seu valor na Burned Tower, e agora\l"
	.string "Raikou e Entei correm livres pelas\l"
	.string "rotas de Johto!$"
