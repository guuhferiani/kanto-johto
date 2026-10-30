.set LOCALID_PROTON, 1

SlowpokeWell_MapScripts::
	.byte 0

SlowpokeWell_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_Text_ProtonIntro, MSGBOX_DEFAULT
	setwildbattle SPECIES_HOUNDOOM, 58, ITEM_NONE
	dowildbattle
	msgbox SlowpokeWell_Text_ProtonDefeat, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK, 1
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_PROTON
	setflag FLAG_CLEARED_SLOWPOKE_WELL
	fadescreen FADE_FROM_BLACK
	msgbox SlowpokeWell_Text_SlowpokesSaved, MSGBOX_DEFAULT
	release
	end

SlowpokeWell_EventScript_Slowpoke1::
	lock
	faceplayer
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	msgbox SlowpokeWell_Text_SlowpokeJoy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlowpokeWell_EventScript_Slowbro::
	lock
	faceplayer
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox SlowpokeWell_Text_SlowbroJoy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlowpokeWell_Text_ProtonIntro::
	.string "Executivo Proton: Hehehe!\n"
	.string "Mesmo após a queda de Giovanni em\l"
	.string "Kanto, a Equipe Rocket renascerá\l"
	.string "aqui em Johto!\p"
	.string "Você acha que pode impedir nossa\n"
	.string "operação no Poço dos Slowpoke?\l"
	.string "Enfrente a fúria do meu Houndoom!$"

SlowpokeWell_Text_ProtonDefeat::
	.string "Proton: Grrr! Então você é o\n"
	.string "Campeão que destruiu nossos planos\l"
	.string "em Kanto?!\p"
	.string "Não importa! Nossa verdadeira base\n"
	.string "já tomou a Torre de Rádio em\l"
	.string "Goldenrod City!\p"
	.string "Tome esta Pedra do Rei e saia do\n"
	.string "meu caminho!$"

SlowpokeWell_Text_SlowpokesSaved::
	.string "A Equipe Rocket fugiu do Poço!\n"
	.string "Os Slowpoke estão salvos!\p"
	.string "Visite a casa do Kurt em Azalea\n"
	.string "Town para contar a boa notícia!$"

SlowpokeWell_Text_SlowpokeJoy::
	.string "Slowpoke: Slooow!\n"
	.string "(Ele parece aliviado e feliz!)$"

SlowpokeWell_Text_SlowbroJoy::
	.string "Slowbro: Broooo!\n"
	.string "(Ele agradece por proteger o poço!)$"
