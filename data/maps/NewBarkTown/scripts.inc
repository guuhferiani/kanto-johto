NewBarkTown_MapScripts::
	.byte 0

NewBarkTown_EventScript_ElmAide::
	lock
	faceplayer
	msgbox NewBarkTown_Text_ElmAide, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox NewBarkTown_Text_ElmAideAfter, MSGBOX_DEFAULT
	release
	end

NewBarkTown_EventScript_Woman::
	msgbox NewBarkTown_Text_Woman, MSGBOX_NPC
	end

NewBarkTown_EventScript_TohjoGuide::
	lock
	faceplayer
	msgbox NewBarkTown_Text_ReturnToTohjoPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_EventScript_WarpToTohjo
	release
	end

NewBarkTown_EventScript_WarpToTohjo::
	warp MAP_TOHJO_FALLS, 18, 15
	waitstate
	release
	end

NewBarkTown_EventScript_TownSign::
	msgbox NewBarkTown_Text_TownSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmLabSign::
	msgbox NewBarkTown_Text_ElmLabSign, MSGBOX_SIGN
	end

NewBarkTown_Text_ElmAide:
	.string "Bem-vindo a New Bark Town, Campeão!\p"
	.string "O Professor Elm está te esperando\n"
	.string "aqui dentro do laboratório com um\l"
	.string "presente especial de Johto!\p"
	.string "Deixe-me curar seus Pokémon primeiro!$"

NewBarkTown_Text_ElmAideAfter:
	.string "Sua equipe está 100% renovada!\p"
	.string "Entre no Laboratório do Prof. Elm ou\n"
	.string "siga ao norte pela Rota 29 até\l"
	.string "Violet City!$"

NewBarkTown_Text_Woman:
	.string "O vento que sopra em New Bark Town\n"
	.string "anuncia o começo de uma nova jornada.\p"
	.string "Ao norte daqui fica a Rota 29, que\n"
	.string "leva direto para Violet City!$"

NewBarkTown_Text_ReturnToTohjoPrompt:
	.string "Deseja retornar para as Tohjo Falls\n"
	.string "em direção à fronteira de Kanto?$"

NewBarkTown_Text_TownSign:
	.string "NEW BARK TOWN\n"
	.string "A Cidade Onde Sopram os Ventos de um\l"
	.string "Novo Começo!$"

NewBarkTown_Text_ElmLabSign:
	.string "LABORATÓRIO DE PESQUISA POKÉMON\n"
	.string "DO PROFESSOR ELM$"
