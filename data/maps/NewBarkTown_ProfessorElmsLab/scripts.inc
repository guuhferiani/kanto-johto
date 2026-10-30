NewBarkTown_ProfessorElmsLab_MapScripts::
	.byte 0

NewBarkTown_ProfessorElmsLab_EventScript_ProfElm::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_JOHTO_STARTER, NewBarkTown_ProfessorElmsLab_EventScript_ElmAfterStarter
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmIntro, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_ElmAfterStarter::
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmAfterStarter, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_ChikoritaBall::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_JOHTO_STARTER, NewBarkTown_ProfessorElmsLab_EventScript_AlreadyChose
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox NewBarkTown_ProfessorElmsLab_Text_ChooseChikorita, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, NewBarkTown_ProfessorElmsLab_EventScript_DeclineStarter
	givemon SPECIES_CHIKORITA, 5, ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_ProfessorElmsLab_Text_ReceivedChikorita, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_RECEIVED_JOHTO_STARTER
	removeobject 2
	removeobject 3
	removeobject 4
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_CyndaquilBall::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_JOHTO_STARTER, NewBarkTown_ProfessorElmsLab_EventScript_AlreadyChose
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox NewBarkTown_ProfessorElmsLab_Text_ChooseCyndaquil, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, NewBarkTown_ProfessorElmsLab_EventScript_DeclineStarter
	givemon SPECIES_CYNDAQUIL, 5, ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_ProfessorElmsLab_Text_ReceivedCyndaquil, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_RECEIVED_JOHTO_STARTER
	removeobject 2
	removeobject 3
	removeobject 4
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_TotodileBall::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_JOHTO_STARTER, NewBarkTown_ProfessorElmsLab_EventScript_AlreadyChose
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox NewBarkTown_ProfessorElmsLab_Text_ChooseTotodile, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, NewBarkTown_ProfessorElmsLab_EventScript_DeclineStarter
	givemon SPECIES_TOTODILE, 5, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBarkTown_ProfessorElmsLab_Text_ReceivedTotodile, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_RECEIVED_JOHTO_STARTER
	removeobject 2
	removeobject 3
	removeobject 4
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_DeclineStarter::
	msgbox NewBarkTown_ProfessorElmsLab_Text_TakeYourTime, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_AlreadyChose::
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmAfterStarter, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Aide::
	msgbox NewBarkTown_ProfessorElmsLab_Text_Aide, MSGBOX_NPC
	end

NewBarkTown_ProfessorElmsLab_Text_ElmIntro:
	.string "Prof. Elm: Olá, {PLAYER}!\n"
	.string "O Prof. Carvalho me ligou falando\l"
	.string "sobre a sua vitória na Liga Kanto!\p"
	.string "Aqui em Johto eu pesquiso os laços\n"
	.string "e evoluções raras dos Pokémon.\p"
	.string "Para celebrar sua chegada a Johto,\n"
	.string "quero que escolha um dos 3 Pokémon\l"
	.string "iniciais sobre a mesa ao lado!\p"
	.string "Da esquerda para a direita estão:\n"
	.string "Chikorita, Cyndaquil e Totodile!$"

NewBarkTown_ProfessorElmsLab_Text_ChooseChikorita:
	.string "Prof. Elm: Você quer escolher\n"
	.string "CHIKORITA, o Pokémon de Planta?$"

NewBarkTown_ProfessorElmsLab_Text_ReceivedChikorita:
	.string "{PLAYER} recebeu CHIKORITA\n"
	.string "do Professor Elm!$"

NewBarkTown_ProfessorElmsLab_Text_ChooseCyndaquil:
	.string "Prof. Elm: Você quer escolher\n"
	.string "CYNDAQUIL, o Pokémon de Fogo?$"

NewBarkTown_ProfessorElmsLab_Text_ReceivedCyndaquil:
	.string "{PLAYER} recebeu CYNDAQUIL\n"
	.string "do Professor Elm!$"

NewBarkTown_ProfessorElmsLab_Text_ChooseTotodile:
	.string "Prof. Elm: Você quer escolher\n"
	.string "TOTODILE, o Pokémon de Água?$"

NewBarkTown_ProfessorElmsLab_Text_ReceivedTotodile:
	.string "{PLAYER} recebeu TOTODILE\n"
	.string "do Professor Elm!$"

NewBarkTown_ProfessorElmsLab_Text_TakeYourTime:
	.string "Prof. Elm: Pense com calma! Escolha\n"
	.string "aquele que mais tocar o seu coração.$"

NewBarkTown_ProfessorElmsLab_Text_ElmAfterStarter:
	.string "Prof. Elm: Cuide muito bem do seu\n"
	.string "novo parceiro de Johto, {PLAYER}!\p"
	.string "Seu primeiro grande desafio está em\n"
	.string "Violet City, ao norte pela Rota 29.\p"
	.string "Visite a tradicional Sprout Tower e\n"
	.string "desafie o Líder de Ginásio Falkner!$"

NewBarkTown_ProfessorElmsLab_Text_Aide:
	.string "O Professor Elm admirava muito as\n"
	.string "pesquisas do Professor Carvalho.\p"
	.string "É uma honra receber o Campeão de\n"
	.string "Kanto em nosso laboratório!$"
