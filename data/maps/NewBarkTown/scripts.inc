NewBarkTown_MapScripts::
	.byte 0

NewBarkTown_EventScript_TownSign::
	msgbox NewBarkTown_Text_TownSign, MSGBOX_SIGN
	end

NewBarkTown_Text_TownSign::
	.string "New Bark Town\n"
	.string "A cidade onde os ventos de um novo\n"
	.string "comeco sopram suavemente!$"

NewBarkTown_EventScript_LabSign::
	msgbox NewBarkTown_Text_LabSign, MSGBOX_SIGN
	end

NewBarkTown_Text_LabSign::
	.string "Laboratorio de Pesquisas Pokemon\n"
	.string "do Professor Elm$"

NewBarkTown_EventScript_Girl::
	msgbox NewBarkTown_Text_Girl, MSGBOX_NPC
	end

NewBarkTown_Text_Girl::
	.string "Ola! Voce e novo por aqui?\p"
	.string "Voce veio de Kanto pelas montanhas?\n"
	.string "Que incrivel! O Pikachu que anda ao\l"
	.string "seu lado parece muito feliz!$"

NewBarkTown_EventScript_ElmAssistant::
	msgbox NewBarkTown_Text_ElmAssistant, MSGBOX_NPC
	end

NewBarkTown_Text_ElmAssistant::
	.string "Voce e o Campeao {PLAYER}?\p"
	.string "O Professor Elm estava ansioso pela\n"
	.string "sua chegada! Ele esta pesquisando\l"
	.string "os misterios do nascimento dos Pokemon\l"
	.string "e o potencial dos ovos raros!$"
