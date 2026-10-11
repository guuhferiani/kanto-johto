SaffronCity_CopycatsHouse_2F_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_Text_Doduo::
    .string "Doduo: Giiih!\p"
    .string "Espelho lindo, olhe para mim,\n"
    .string "viu como posso ser bela assim?$"

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
    .string "Este é um Pokémon raro!\n"
    .string "Ué? É só uma boneca!$"

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL, 1
	goto_if_eq VAR_RESULT, TRUE, MoveTutor_Mimic
	random 2
	call_if_eq VAR_RESULT, 0, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, 1, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
    .string "{PLAYER}: Oi!\n"
    .string "Você gosta de Pokémon?\p"
    .string "{PLAYER}: Hã, não, eu te perguntei.\p"
    .string "{PLAYER}: Hein?\n"
    .string "Você é muito estranha!\p"
    .string "Copiona: Hmm? Parar de imitar?\n"
    .string "Mas esse é o meu passatempo favorito!$"

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
    .string "{PLAYER}: Olá.\n"
    .string "Você deve gostar de Pokémon.\p"
    .string "{PLAYER}: Não, eu não.\n"
    .string "Eu perguntei pra você.\p"
    .string "{PLAYER}: Como é que é?\n"
    .string "Você é muito esquisita!\l"
    .string " \l"
    .string "Copiona: Hmm? Parar de imitar?\l"
    .string "Mas esse é o meu passatempo favorito!$"

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
    .string "...\p"
    .string "Meus Segredos!\p"
    .string "Habilidade: Imitação!\n"
    .string "Passatempo: Colecionar bonecas!\l"
    .string "Pokémon favorito: Clefairy!$"

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
    .string "Um jogo do Mario usando um balde\n"
    .string "na cabeça!$"
