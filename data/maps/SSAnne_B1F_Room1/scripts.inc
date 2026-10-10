SSAnne_B1F_Room1_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_BarnyIntro::
    .string "Olá, forasteiro!\p"
    .string "Não sei se você é do mar ou das\n"
    .string "montanhas, mas pare para conversar.\p"
    .string "Todos os meus Pokémon são do mar.$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
    .string "Droga!\n"
    .string "Deixei aquele escapar!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
    .string "E eu ia te chamar para ser meu\n"
    .string "assistente ainda por cima!$"

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
    .string "Marujo, você vai andar na prancha\n"
    .string "se perder!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
    .string "Argh!\n"
    .string "Derrotado por uma criança!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
    .string "Quando estamos em alto-mar, Pokémon\n"
    .string "águas-vivas às vezes passam boiando.$"
