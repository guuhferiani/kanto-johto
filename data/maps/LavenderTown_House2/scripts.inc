LavenderTown_House2_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_House2_EventScript_ChooseMon
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt LavenderTown_House2_EventScript_CheckCanRateMon
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, IsMonOTNameNotPlayers
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_House2_EventScript_ChooseNewNickname
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_ChangePokemonNickname
	specialvar VAR_RESULT, NameRaterWasNicknameChanged
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
    .string "Olá, olá!\n"
    .string "Eu sou o Avaliador de Nomes oficial!\p"
    .string "Quer que eu avalie os apelidos dos\n"
    .string "seus Pokémon?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
    .string "O apelido de qual Pokémon você quer\n"
    .string "que eu avalie?$"

LavenderTown_House2_Text_GiveItANicerName::
    .string "{STR_VAR_1}, não é?\n"
    .string "Esse é um apelido razoável!\p"
    .string "Mas você gostaria que eu desse a ele\n"
    .string "um nome melhor?\p"
    .string "O que me diz?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
    .string "Ah, muito bem. Então qual será o\n"
    .string "novo apelido?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
    .string "Pronto! De agora em diante, este\n"
    .string "Pokémon será chamado de {STR_VAR_1}!\p"
    .string "Ficou um nome bem melhor do que antes!\n"
    .string "Que sorte a sua!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
    .string "Entendo.\n"
    .string "Volte a me visitar quando quiser.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
    .string "Pronto! De agora em diante, este\n"
    .string "Pokémon será chamado de {STR_VAR_1}!\p"
    .string "Não parece nada diferente de antes,\n"
    .string "e mesmo assim, ficou infinitamente superior!\p"
    .string "Que sorte a sua!$"

LavenderTown_House2_Text_TrulyImpeccableName::
    .string "{STR_VAR_1}, não é?\n"
    .string "Esse é um nome verdadeiramente impecável!\p"
    .string "Cuide muito bem de {STR_VAR_1}!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
    .string "Ora, ora.\n"
    .string "Isto é apenas um ovo!$"

