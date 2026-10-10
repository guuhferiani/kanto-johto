VermilionCity_House3_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
    .string "Estou fazendo meu Pidgey levar uma\n"
    .string "carta voando para Saffron, ao norte.$"

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
    .string "A maioria das pessoas prefere e-mail,\n"
    .string "mas eu prefiro uma carta à moda antiga!\p"
    .string "Treinei meu Pidgey para entregar cartas!$"

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_Text_Pidgey::
    .string "Pidgey: Kurukkoo!$"

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_DearPippiLetter::
    .string "Querida Pippi,\n"
    .string "Espero ver você em breve.\p"
    .string "Ouvi um boato de que a Equipe Rocket\n"
    .string "estava indo para a Cidade de Saffron.\p"
    .string "Vermilion parece estar segura.$"
