SafariZone_East_RestHouse_MapScripts::
	.byte 0

SafariZone_East_RestHouse_EventScript_Rocker::
	msgbox SafariZone_East_Text_CaughtChanseyAllWorthwhile, MSGBOX_NPC
	end

SafariZone_East_Text_CaughtChanseyAllWorthwhile::
    .string "Eu capturei uma Chansey!\p"
    .string "Isso faz todo o esforço valer a pena.$"

SafariZone_East_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_HowManyDidYouCatch, MSGBOX_NPC
	end

SafariZone_East_Text_HowManyDidYouCatch::
    .string "Quantos você capturou?\n"
    .string "Estou exausto de tanto tentar!$"

SafariZone_East_RestHouse_EventScript_BaldingMan::
	msgbox SafariZone_East_Text_TiredFromAllTheFun, MSGBOX_NPC
	end

SafariZone_East_Text_TiredFromAllTheFun::
    .string "Ufa!\n"
    .string "Estou cansado de tanta diversão!$"

SafariZone_East_RestHouse_EventScript_RangerM::
	msgbox SafariZone_East_RestHouse_Text_RangerM, MSGBOX_NPC
	end

SafariZone_East_RestHouse_Text_RangerM:
	.string "Se você colocar um {POKEBLOCK} no Alimentador,\n"
	.string "os Pokémon serão atraídos até ele.\p"
	.string "Acho que Pokémon com a mesma natureza\n"
	.string "são atraídos por um tipo específico de {POKEBLOCK}.$"
