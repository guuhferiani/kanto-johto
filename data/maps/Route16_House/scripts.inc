Route16_House_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route16_House_EventScript_NoRoomForHM02
	playfanfare MUS_OBTAIN_TMHM
	message Route16_House_Text_ReceivedHM02FromGirl
	waitfanfare
	waitmessage
	closemessage 
	additem ITEM_HM02, 1
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_RECEIVED_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Pidgeot
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
    .string "Oh, céus.\n"
    .string "Você descobriu meu refúgio secreto.\p"
    .string "Por favor, não conte a ninguém que estou aqui.\n"
    .string "Vou compensar você com isto!$"

Route16_House_Text_ReceivedHM02FromGirl::
    .string "{PLAYER} recebeu a MO02\n"
    .string "da garota.$"

Route16_House_Text_ExplainHM02::
    .string "A MO02 é o Voar.\n"
    .string "É um movimento incrivelmente útil.\p"
    .string "Por favor, faça bom uso dele.$"

Route16_House_Text_DontHaveAnyRoomForThis::
    .string "Você não tem espaço para isto.$"

Route16_House_Text_Pidgeot::
    .string "Pidgeot: Kyueen!$"
