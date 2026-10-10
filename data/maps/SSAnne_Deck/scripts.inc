SSAnne_Deck_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_Text_ShipDepartingSoon::
    .string "A festa acabou.\n"
    .string "O navio vai zarpar em breve.$"

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_Text_FeelSeasick::
    .string "Urgh… Não estou me sentindo bem…\p"
    .string "Fiquei enjoado com o mar, então saí\n"
    .string "para tomar um ar fresco…$"

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_Text_ScrubbingDecksHardWork::
    .string "Ufa!\n"
    .string "Esfregar o convés dá um trabalhão!$"

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_EdmondIntro::
    .string "Ei, marujo!\p"
    .string "Vamos dançar um pouco!$"

SSAnne_Deck_Text_EdmondDefeat::
    .string "Você é impressionante!$"

SSAnne_Deck_Text_EdmondPostBattle::
    .string "Quantos tipos de Pokémon você acha\n"
    .string "que existem neste mundão?$"

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_TrevorIntro::
    .string "Ahoy!\n"
    .string "Está enjoado com o mar?$"

SSAnne_Deck_Text_TrevorDefeat::
    .string "Eu só me descuidei!$"

SSAnne_Deck_Text_TrevorPostBattle::
    .string "Meu pai dizia que existem 100 espécies de\n"
    .string "Pokémon. Eu acho que existem mais.$"
