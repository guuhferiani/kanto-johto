.set LOCALID_ARCHER, 1

GoldenrodCity_RadioTower_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_Text_ArcherIntro, MSGBOX_DEFAULT
	setwildbattle SPECIES_TYRANITAR, 65, ITEM_NONE
	dowildbattle
	msgbox GoldenrodCity_RadioTower_Text_ArcherDefeat, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_ARCHER
	setflag FLAG_CLEARED_GOLDENROD_RADIO_TOWER
	fadescreen FADE_FROM_BLACK
	msgbox GoldenrodCity_RadioTower_Text_DirectorReward, MSGBOX_DEFAULT
	giveitem ITEM_SCOPE_LENS, 1
	giveitem ITEM_SACRED_ASH, 1
	release
	end

GoldenrodCity_RadioTower_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_GOLDENROD_RADIO_TOWER, GoldenrodCity_RadioTower_EventScript_DirectorSaved
	msgbox GoldenrodCity_RadioTower_Text_DirectorHelp, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_EventScript_DirectorSaved::
	msgbox GoldenrodCity_RadioTower_Text_DirectorSaved, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_EventScript_Mary::
	msgbox GoldenrodCity_RadioTower_Text_Mary, MSGBOX_NPC
	end

GoldenrodCity_RadioTower_Text_ArcherIntro::
	.string "Executivo Archer: Então você chegou\n"
	.string "até o topo da Torre de Rádio!\p"
	.string "Estamos usando as antenas de\n"
	.string "Goldenrod para transmitir nosso\l"
	.string "chamado ao chefe Giovanni!\p"
	.string "Não permitirei que você interfira\n"
	.string "mais uma vez! Sinta o poder do\l"
	.string "meu Tyranitar!$"

GoldenrodCity_RadioTower_Text_ArcherDefeat::
	.string "Archer: Impossível...!\n"
	.string "Você derrotou a elite da Equipe\l"
	.string "Rocket sozinho novamente?!\p"
	.string "Está acabado... A Equipe Rocket\n"
	.string "está oficialmente dissolvida para\l"
	.string "sempre!$"

GoldenrodCity_RadioTower_Text_DirectorReward::
	.string "Diretor: Oh, muito obrigado,\n"
	.string "{PLAYER}!\p"
	.string "Você salvou a Torre de Rádio e\n"
	.string "protegeu todas as cidades de Johto!\p"
	.string "Por favor, aceite estas relíquias\n"
	.string "sagradas de Johto como nossa\l"
	.string "eterna gratidão!$"

GoldenrodCity_RadioTower_Text_DirectorHelp::
	.string "Diretor: Por favor, detenha o\n"
	.string "Executivo Archer antes que ele\l"
	.string "controle todas as transmissões!$"

GoldenrodCity_RadioTower_Text_DirectorSaved::
	.string "Diretor: Graças à sua coragem,\n"
	.string "o Programa de Rádio do Prof. Carvalho\l"
	.string "e da DJ Mary voltou ao ar em toda\l"
	.string "a região de Johto!$"

GoldenrodCity_RadioTower_Text_Mary::
	.string "DJ Mary: Olá, ouvintes! Aqui é a\n"
	.string "Torre de Rádio de Goldenrod\l"
	.string "transmitindo música e alegria!$"
