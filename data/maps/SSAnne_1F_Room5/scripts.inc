SSAnne_1F_Room5_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
    .string "Seu pirralho insolente!\n"
    .string "Como ousa entrar sem bater?!$"

SSAnne_1F_Room5_Text_ArthurDefeat::
    .string "Humph! Criança mal-educada!\n"
    .string "Não tem o menor senso de cortesia!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
    .string "Quero ficar sozinho!\n"
    .string "Dê o fora!$"
