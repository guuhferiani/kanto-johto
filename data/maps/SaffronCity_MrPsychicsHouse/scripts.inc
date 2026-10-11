SaffronCity_MrPsychicsHouse_MapScripts::
	.byte 0

SaffronCity_MrPsychicsHouse_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_REVEALED_MEGA_STONES, SaffronCity_MrPsychicsHouse_EventScript_GetAlakazite
	goto SaffronCity_MrPsychicsHouse_EventScript_GetPsychic
	end

SaffronCity_MrPsychicsHouse_EventScript_GetPsychic::
	goto_if_set FLAG_GOT_TM29_FROM_MR_PSYCHIC, SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29
	msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis
	checkitemspace ITEM_TM29, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
	giveitem ITEM_TM29, 1
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	setflag FLAG_GOT_TM29_FROM_MR_PSYCHIC
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_GetAlakazite::
	goto_if_set FLAG_HIDE_ALAKAZITE, SaffronCity_MrPsychicsHouse_EventScript_GetPsychic
	msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis
	checkitemspace ITEM_ALAKAZITE, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
	giveitem ITEM_ALAKAZITE, 1
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainAlakazite
	waitmessage
	setflag FLAG_HIDE_ALAKAZITE
	setflag FLAG_GOT_ALAKAZITE
	goto_if_unset FLAG_FIRST_MEGASTONE, SaffronCity_MrPsychicsHouse_EventScript_FoundMegaStone
	release
    end

SaffronCity_MrPsychicsHouse_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end

SaffronCity_MrPsychicsHouse_Text_ExplainAlakazite::
	.string "Você já sabe, não sabe?\n"
    .string "Essa pedra é uma Alakazita.\p"
    .string "Ela desbloqueia o potencial psíquico\n"
    .string "definitivo de um Alakazam!$"

SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_YouveNoRoom
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	release
	end

SaffronCity_MrPsychicsHouse_Text_YouWantedThis::
    .string "...Espere! Não diga uma palavra!\p"
    .string "Você queria isto!$"

SaffronCity_MrPsychicsHouse_Text_ExplainTM29::
    .string "Você já sabe, não sabe?\n"
    .string "A MT29 é Psíquico.\p"
    .string "É um ataque que também pode reduzir\n"
    .string "os atributos especiais do alvo.$"

SaffronCity_MrPsychicsHouse_Text_YouveNoRoom::
    .string "Onde você planeja guardar isso?\n"
    .string "Você está sem espaço.$"
