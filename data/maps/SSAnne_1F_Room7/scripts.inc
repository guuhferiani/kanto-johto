SSAnne_1F_Room7_MapScripts::
	.byte 0


SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
    .string "Não passo de um viajante solitário…\p"
    .string "Meus únicos companheiros e amigos são\n"
    .string "os Pokémon que capturei nas minhas viagens…$"

SSAnne_1F_Room7_Text_ThomasDefeat::
    .string "Meus… meus amigos…$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
    .string "Você deveria ser mais gentil com amigos!$"
