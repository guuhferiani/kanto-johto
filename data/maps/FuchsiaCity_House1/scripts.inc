FuchsiaCity_House1_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
    .string "O Guarda da Zona do Safári é velho,\n"
    .string "mas ainda é muito ativo.\p"
    .string "No entanto, todos os dentes dele\n"
    .string "são postiços.$"

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_Text_BillIsMyGrandson::
    .string "Hmm?\n"
    .string "Você conheceu o Bill?\p"
    .string "Ele é meu neto!\p"
    .string "Ele sempre gostou de colecionar coisas,\n"
    .string "mesmo quando era criança!$"

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
    .string "O Bill arquiva seus próprios dados\n"
    .string "de Pokémon no PC dele.\p"
    .string "Ele mostrou para você?$"
