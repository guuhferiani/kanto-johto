.set LOCALID_SCIENTIST1, 1
.set LOCALID_OLD_AMBER,  6

PewterCity_Museum_1F_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain, MSGBOX_DEFAULT
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
    .string "Boas-vindas ao nosso museu!\n"
    .string "O ingresso infantil custa ¥50.\p"
    .string "Você gostaria de entrar?$"

PewterCity_Museum_1F_Text_ComeAgain::
    .string "Volte sempre!$"

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou, MSGBOX_DEFAULT
	setvar VAR_PEWTER_CITY_MUSEUM_STATE, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_Text_Right50YThankYou::
    .string "Certo, ¥50!\n"
    .string "Muito obrigado!$"

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
    .string "Você não tem dinheiro suficiente.$"

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_ne VAR_FACING, DIR_EAST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
    .string "Por favor, aproveite a visita.$"

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap, MSGBOX_DEFAULT
	turnobject LOCALID_SCIENTIST1, DIR_WEST
	waitmovement 1
	release
	end

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
    .string "Não pode entrar pelos fundos!\n"
    .string "Boa tentativa, jovem, mas não.\p"
    .string "Ah, tanto faz!\n"
    .string "Você sabe o que é Âmbar?$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
    .string "O Âmbar é na verdade seiva, aquela\n"
    .string "substância pegajosa que sai de árvores.\p"
    .string "A seiva ancestral se fossilizou com o\n"
    .string "tempo até virar uma pedra de Âmbar.$"

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter, MSGBOX_DEFAULT
	turnobject LOCALID_SCIENTIST1, DIR_WEST
	waitmovement 1
	release
	end

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
    .string "O Âmbar contém o material genético\n"
    .string "de Pokémon ancestrais.\p"
    .string "Há um laboratório por aí tentando\n"
    .string "ressuscitar Pokémon a partir dele.$"

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
    .string "Temos dois fósseis raros de Pokémon\n"
    .string "pré-históricos em exibição.$"

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined, MSGBOX_DEFAULT
	checkitemspace ITEM_OLD_AMBER, 1
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PewterCity_Museum_1F_Text_ReceivedOldAmber
	waitfanfare
	additem ITEM_OLD_AMBER, 1
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	goto_if_set FLAG_GOT_AERODACTYL_REWARD, PewterCity_Museum_1F_EventScript_AlreadyGotReward
	goto_if_set FLAG_RESSURECTED_AERODACTYL, PewterCity_Museum_1F_EventScript_WowThatsAerodactyl
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_GetOldAmberChecked::
    .string "Shiu!\n"
    .string "Vá analisar esse Âmbar Velho!$"

PewterCity_Museum_1F_EventScript_WowThatsAerodactyl::
	msgbox PewterCity_Museum_1F_Text_WowThatsAerodactyl, MSGBOX_DEFAULT
	goto_if_eq VAR_FOSSIL_SELECTION, 1, PewterCity_Museum_1F_EventScript_GiveHelixFossil
	goto_if_eq VAR_FOSSIL_SELECTION, 2, PewterCity_Museum_1F_EventScript_GiveDomeFossil
	end

PewterCity_Museum_1F_EventScript_GiveHelixFossil::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Museum_1F_Text_ObtainedHelixFossil
	waitfanfare
	waitmessage
	additem ITEM_HELIX_FOSSIL, 1
	goto PewterCity_Museum_1F_EventScript_GaveReward
	end

PewterCity_Museum_1F_Text_ObtainedHelixFossil::
    .string "Obteve o Fóssil Helix!$"

PewterCity_Museum_1F_EventScript_GiveDomeFossil::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Museum_1F_Text_ObtainedDomeFossil
	waitfanfare
	waitmessage
	additem ITEM_DOME_FOSSIL, 1
	goto PewterCity_Museum_1F_EventScript_GaveReward
	end

PewterCity_Museum_1F_Text_ObtainedDomeFossil::
    .string "Obteve o Fóssil Domo!$"

PewterCity_Museum_1F_EventScript_GaveReward::
	setflag FLAG_GOT_AERODACTYL_REWARD
	release
	end

PewterCity_Museum_1F_Text_WowThatsAerodactyl::
    .string "Uau!\n"
    .string "Você ressuscitou o Pokémon?\p"
    .string "Eu sabia que ele continha DNA!\p"
    .string "Muito obrigado por me contar.\n"
    .string "Por favor, aceite isto de presente!$"

PewterCity_Museum_1F_EventScript_AlreadyGotReward::
	msgbox PewterCity_Museum_1F_Text_PowerOfScience, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_PowerOfScience::
    .string "É incrível o que podemos fazer\n"
    .string "com o poder da ciência!$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
    .string "Shiu! Ouça, eu preciso contar um\n"
    .string "segredo a alguém.\p"
    .string "Acho que este pedaço de Âmbar\n"
    .string "contém DNA de Pokémon!\p"
    .string "Seria um avanço científico histórico\n"
    .string "se um Pokémon pudesse ser revivido dele.\p"
    .string "Mas meus colegas simplesmente ignoram\n"
    .string "o que eu digo.\p"
    .string "Por isso, peço um favor a você!\p"
    .string "Quero que leve isto para ser analisado\n"
    .string "em um Laboratório Pokémon.$"

PewterCity_Museum_1F_Text_ReceivedOldAmber::
    .string "{PLAYER} recebeu o Âmbar Velho\n"
    .string "do cientista.$"

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
    .string "Você não tem espaço para isso.$"

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
    .string "Há um belo pedaço de âmbar em uma\n"
    .string "cor dourada e translúcida.$"

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
    .string "Devo ser grato pela minha longa vida.\p"
    .string "Nunca imaginei que um dia veria os\n"
    .string "ossos de um dragão!$"

PewterCity_Museum_1F_EventScript_PokemonJournalBrock::
	msgbox PokemonJournal_Text_SpecialFeatureBrock, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureBrock::
	.string "Jornal Pokémon\p"
	.string "Matéria Especial: Brock, o Líder\n"
	.string "do Ginásio de Pewter!\p"
	.string "Brock quase nunca ri, mas dizem que,\n"
	.string "quando começa, não consegue parar.$"


PewterCity_Museum_1F_EventScript_AerodactylFossil::
    lockall
    setvar VAR_0x8004, SPECIES_AERODACTYL
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_AerodactylFossil
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_Text_AerodactylFossil::
    .string "Fóssil de Aerodactyl\n"
    .string "Um Pokémon primitivo e raro.$"

PewterCity_Museum_1F_EventScript_KabutopsFossil::
    lockall
    setvar VAR_0x8004, SPECIES_KABUTOPS
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_KabutopsFossil
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_Text_KabutopsFossil::
    .string "Fóssil de Kabutops\n"
    .string "Um Pokémon primitivo e raro.$"
