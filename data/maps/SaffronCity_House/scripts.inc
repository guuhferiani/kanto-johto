SaffronCity_House_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
    .string "...Obrigada por me escrever.\n"
    .string "Espero te ver em breve!\p"
    .string "...Ei!\n"
    .string "Não fique lendo a minha carta!$"

SaffronCity_House_Text_Pidgey::
    .string "Pidgey: Kurukkoo!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
    .string "A Copiona é tão fofa!\n"
    .string "Vou levar uma Boneca Pokémon pra ela.$"

SaffronCity_House_Text_ExplainPPUp::
    .string "Ganhei um PP UP de presente.\p"
    .string "Ele serve para aumentar o PP de um\n"
    .string "golpe de um Pokémon.\p"
    .string "Devo usá-lo em um golpe poderoso\n"
    .string "que tenha poucos PP.$"
