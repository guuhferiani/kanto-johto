SSAnne_B1F_Room4_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
    .string "Você sabe o que dizem sobre marinheiros\n"
    .string "e batalhas!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
    .string "Isso aí!\n"
    .string "Bela batalha, marujo!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
    .string "Hahaha!\n"
    .string "Quer virar um marinheiro, marujo?$"

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_DuncanIntro::
    .string "Venha com tudo, então!\n"
    .string "Meu orgulho de marinheiro está em jogo!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
    .string "Sua garra afundou o meu navio!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
    .string "Você viu o Guru da Pesca na\n"
    .string "Cidade de Vermilion?$"
