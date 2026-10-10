.set LOCALID_EXPERT, 1
.set LOCALID_LASS, 2
.set LOCALID_YOUNGSTER, 3
.set LOCALID_DAISY, 4

.set NUM_OPPONENTS, VAR_0x8009

FuchsiaCity_House3_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, BerryHouse_OnTransition
	.byte 0

BerryHouse_OnTransition::
    call_if_unset FLAG_DAILY_BERRY_BLEND_OPPONENTS, BerryHouse_SetTodaysOpponents
    call BerryHouse_SetPositions
    end

BerryHouse_SetTodaysOpponents::
    setflag FLAG_DAILY_BERRY_BLEND_OPPONENTS
    random 3
    addvar VAR_RESULT, 1
    copyvar VAR_BERRY_HOUSE_VISITORS, VAR_RESULT
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 1, BerryHouse_CheckForDaisy
    return


BerryHouse_CheckForDaisy::
    random 10
    goto_if_ne VAR_RESULT, 9, Common_EventScript_Return
    setvar VAR_BERRY_HOUSE_VISITORS, 4
    return


BerryHouse_SetPositions::
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 4, BerryHouse_DaisyVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 3, BerryHouse_LassAndYoungsterVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 2, BerryHouse_LassVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 1, BerryHouse_NoOneVisiting
    return

BerryHouse_DaisyVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_DAISY
    addobject LOCALID_DAISY
    setobjectxyperm LOCALID_EXPERT, 4, 5
    removeobject LOCALID_LASS
    setflag FLAG_HIDE_BERRY_HOUSE_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    return

BerryHouse_LassAndYoungsterVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    addobject LOCALID_YOUNGSTER
    clearflag FLAG_HIDE_BERRY_HOUSE_LASS
    addobject LOCALID_LASS
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    return

BerryHouse_LassVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_LASS
    addobject LOCALID_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    return

BerryHouse_NoOneVisiting::
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    removeobject LOCALID_LASS
    setflag FLAG_HIDE_BERRY_HOUSE_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    return

FuchsiaCity_House3_EventScript_Grandfather::
    lock
    faceplayer
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 4, FuchsiaCity_House3_EventScript_DaisyVisits
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 3, FuchsiaCity_House3_EventScript_WholeFamily
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 2, FuchsiaCity_House3_EventScript_OldestGrandhchild
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 1, FuchsiaCity_House3_EventScript_NoVisitors
    end

FuchsiaCity_House3_EventScript_DaisyVisits::
    msgbox FuchsiaCity_House3_Text_DaisyVisits, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_DaisyVisits:
    .string "Ah, você também conhece a Daisy?\p"
    .string "Ela nos visita de vez em quando.\n"
    .string "Ela é muito gentil conosco.\p"
    .string "Minha esposa ensinou a ela tudo o\n"
    .string "que sabe sobre Mistura de Frutas!\p"
    .string "Ela pode até estar melhor do que ela!\p"
    .string "Mas não conte à minha esposa que eu\n"
    .string "disse isso!$"

FuchsiaCity_House3_EventScript_WholeFamily::
    msgbox FuchsiaCity_House3_Text_WarmsMyHeart, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_WarmsMyHeart:
    .string "Aquece o meu coração ver toda a minha\n"
    .string "família passando um tempo junta!$"

FuchsiaCity_House3_EventScript_OldestGrandhchild::
    msgbox FuchsiaCity_House3_Text_OldestGrandhchild, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_OldestGrandhchild:
    .string "Minha neta mais velha está nos\n"
    .string "visitando hoje!\p"
    .string "Ela é uma Treinadora igual a você!$"

FuchsiaCity_House3_EventScript_NoVisitors::
    msgbox FuchsiaCity_House3_Text_NoVisitors, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_NoVisitors:
    .string "Envelhecer pode ser difícil.\p"
    .string "Especialmente em dias como hoje, quando\n"
    .string "não recebemos nenhuma visita…\p"
    .string "Mas aí você veio, e isso alegrou\n"
    .string "o nosso dia!$"

FuchsiaCity_House3_EventScript_BerryBlenderSpeedRecords::
    lockall
    special ShowBerryBlenderRecordWindow
    waitbuttonpress
    special RemoveRecordsWindow
    releaseall
    end

FuchsiaCity_House3_EventScript_Picture::
    msgbox FuchsiaCity_House3_Text_Picture, MSGBOX_SIGN
    release
    end

FuchsiaCity_House3_Text_Picture::
    .string "É uma foto do casal de idosos\n"
    .string "quando eles eram mais jovens…\p"
    .string "Há um grande pomar de Árvores de Frutas!$"

FuchsiaCity_House3_EventScript_Lass::
    msgbox FuchsiaCity_House3_Text_Lass, MSGBOX_NPC
    turnobject LOCALID_LASS, DIR_EAST
    release
    end

FuchsiaCity_House3_Text_Lass:
    .string "Estou tentando melhorar nos Concursos,\n"
    .string "então estou aprendendo a Misturar Frutas\l"
    .string "com a minha avó!$"

FuchsiaCity_House3_EventScript_Youngster::
    msgbox FuchsiaCity_House3_Text_Youngster, MSGBOX_NPC
    turnobject LOCALID_YOUNGSTER, DIR_WEST
    release
    end

FuchsiaCity_House3_Text_Youngster:
    .string "Eu preferia estar lá fora batalhando.\n"
    .string "Mas minha irmã diz que é legal visitar\l"
    .string "a vovó e o vovô.\p"
    .string "Pelo menos Misturar Frutas é até\n"
    .string "divertido, se você curte isso.$"

FuchsiaCity_House3_EventScript_Daisy::
    msgbox FuchsiaCity_House3_Text_Daisy, MSGBOX_NPC
    turnobject LOCALID_DAISY, DIR_SOUTH
    release
    end

FuchsiaCity_House3_Text_Daisy:
    .string "Oh! Olá, {PLAYER}!\p"
    .string "Eu não sabia que você também conhecia\n"
    .string "os mestres das Frutas!\p"
    .string "Eu os conheci quando viajava para\n"
    .string "participar de Concursos.\p"
    .string "Eles me ensinaram tudo o que sei sobre\n"
    .string "Mistura de Frutas.\p"
    .string "Eu ainda tento visitá-los de vez em quando.\n"
    .string "E não faz mal praticar um pouco, né?$"

FuchsiaCity_House3_EventScript_Expert::
    msgbox FuchsiaCity_House3_Text_Expert, MSGBOX_NPC
    turnobject LOCALID_EXPERT, DIR_SOUTH
    release
    end

FuchsiaCity_House3_Text_Expert:
    .string "Meu marido e eu nos mudamos para Kanto\n"
    .string "há muito tempo, mas ninguém aqui sabia\l"
    .string "sobre Mistura de Frutas…\p"
    .string "Era muito popular na nossa terra natal,\n"
    .string "então tentamos manter a tradição viva.\p"
    .string "Sempre que alguém nos visita,\n"
    .string "nós Misturamos Frutas juntos!$"


BerryHouse_EventScript_BerryBlender::
    lockall
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 4 BerryHouse_EventScript_VsDaisy
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 3 BerryHouse_EventScript_ThreeOpponents
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 2 BerryHouse_EventScript_TwoOpponents
    setvar NUM_OPPONENTS, 1
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_TwoOpponents::
    setvar NUM_OPPONENTS, 2
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterRight
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_ThreeOpponents::
    setvar NUM_OPPONENTS, 3
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_VsDaisy::
    setvar NUM_OPPONENTS, 1
    applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterDown
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocksDaisy, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlenderDaisy
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_Text_WantToMakePokeblocks:
    .string "Oh? Você gostaria de fazer alguns {POKEBLOCK}s?$"

BerryHouse_Text_WantToMakePokeblocksDaisy:
    .string "Oh? Você gostaria de fazer alguns {POKEBLOCK}s\n"
    .string "comigo, {PLAYER}?$"

BerryHouse_EventScript_DeclineBlender:
    msgbox BerryHouse_Text_MadeOldTimerSad, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_MadeOldTimerSad:
    .string "Oh…\n"
    .string "Talvez em uma outra hora, então…$"

BerryHouse_EventScript_TryUseBerryBlender:
    checkitem ITEM_POKEBLOCK_CASE
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoCase
    specialvar VAR_RESULT, GetFirstFreePokeblockSlot
    goto_if_eq VAR_RESULT, 65535, BerryHouse_EventScript_BlenderCaseFull
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoBerries
    msgbox BerryHouse_Text_Excellent, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_UseBerryBlender
    end

BerryHouse_Text_Excellent:
    .string "Excelente!$"

BerryHouse_EventScript_TryUseBerryBlenderDaisy:
    checkitem ITEM_POKEBLOCK_CASE
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoCaseDaisy
    specialvar VAR_RESULT, GetFirstFreePokeblockSlot
    goto_if_eq VAR_RESULT, 65535, BerryHouse_EventScript_BlenderCaseFull
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoBerriesDaisy
    msgbox BerryHouse_Text_Excellent, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_UseBerryBlender
    end

BerryHouse_EventScript_BlenderNoCase:
    msgbox BerryHouse_Text_DontHavePokeblockCase, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHavePokeblockCase:
    .string "Mas você não tem um Porta-{POKEBLOCK}s.\p"
    .string "Você deveria conseguir um\n"
    .string "Porta-{POKEBLOCK}s primeiro.$"

BerryHouse_EventScript_BlenderNoCaseDaisy:
    msgbox BerryHouse_Text_DontHavePokeblockCaseDaisy, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHavePokeblockCaseDaisy:
    .string "Oh? Você não tem um Porta-{POKEBLOCK}s?\p"
    .string "O {RIVAL} não te deu um?$"

BerryHouse_EventScript_BlenderCaseFull:
    msgbox BerryHouse_Text_PokeblockCaseIsFull, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_PokeblockCaseIsFull:
    .string "Parece que o seu Porta-{POKEBLOCK}s\n"
    .string "está cheio.\p"
    .string "Você deveria usar alguns {POKEBLOCK}s\n"
    .string "e depois voltar.$"

BerryHouse_EventScript_BlenderNoBerries:
    msgbox BerryHouse_Text_DontHaveAnyBerries, MSGBOX_DEFAULT
    call_if_unset FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_HusbandGiveYouBerry
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerries:
    .string "Você não tem nenhuma Fruta,\n"
    .string "não é?\p"
    .string "Se não tiver Frutas,\n"
    .string "não dá para fazer {POKEBLOCK}s.\p"
    .string "Nós sempre estaremos fazendo {POKEBLOCK}s aqui,\n"
    .string "então vamos fazer juntos quando você\l"
    .string "conseguir uma ou duas Frutas.$"

BerryHouse_EventScript_HusbandGiveYouBerry::
    msgbox BerryHouse_Text_HusbandGiveYouBerry, MSGBOX_DEFAULT
    return

BerryHouse_Text_HusbandGiveYouBerry:
    .string "Se você pedir com jeitinho, meu marido\n"
    .string "pode ter uma Fruta sobrando para te dar.$"

BerryHouse_EventScript_BlenderNoBerriesDaisy:
    msgbox BerryHouse_Text_DontHaveAnyBerriesDaisy, MSGBOX_DEFAULT
    call_if_unset FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_OldManGiveYouBerry
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesDaisy:
    .string "Oh! Você não tem nenhuma Fruta?\n"
    .string "Se não tiver Frutas,\n"
    .string "não dá para fazer {POKEBLOCK}s.$"

BerryHouse_EventScript_OldManGiveYouBerry::
    msgbox BerryHouse_Text_OldManGiveYouBerry, MSGBOX_DEFAULT
    return

BerryHouse_Text_OldManGiveYouBerry:
    .string "Sabe, se você pedir com jeitinho, o velhinho\n"
    .string "pode ter uma Fruta sobrando para te dar.$"

BerryHouse_EventScript_GetDailyBerry::
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, TRUE, Common_EventScript_Return
    dotimebasedevents
    goto_if_set FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_BlenderNoSpareBerries
    goto BerryHouse_EventScript_GiveSpareBerry
    end

BerryHouse_EventScript_BlenderNoSpareBerries::
    msgbox BerryHouse_Text_DontHaveAnyBerriesToSpare, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesToSpare:
    .string "Se eu tivesse algumas Frutas sobrando,\n"
    .string "te daria uma com prazer…\p"
    .string "Mas hoje não tenho nenhuma sobrando.\n"
    .string "Teremos que deixar para outra hora.$"

BerryHouse_EventScript_GiveSpareBerry:
    msgbox BerryHouse_Text_DontHaveAnyBerriesHaveOne, MSGBOX_DEFAULT
    giveitem ITEM_PECHA_BERRY
    setflag FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesHaveOne:
    .string "Oh?\n"
    .string "Você não tem nenhuma Fruta?\p"
    .string "Bem, isso não pode ficar assim, pode?\p"
    .string "Se você não se importar com as sobras,\n"
    .string "pode ficar com uma das minhas Frutas.$"


BerryHouse_EventScript_UseBerryBlender:
    msgbox BerryHouse_Text_KnowHowToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_StartBlender
    goto BerryHouse_EventScript_ExplainBlending
    end

BerryHouse_Text_KnowHowToMakePokeblocks:
    .string "Você sabe como fazer um {POKEBLOCK}?$"

BerryHouse_EventScript_ExplainBlending:
    msgbox BerryHouse_Text_ExplainBerryBlending, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_StartBlender
    end

BerryHouse_Text_ExplainBerryBlending:
    .string "Certo, então aqui vai uma explicação rápida.\p"
    .string "Oh, não se preocupe, é bem simples.\p"
    .string "Quando a seta do Misturador apontar\n"
    .string "para o seu marcador, aperte o Botão A.\p"
    .string "É só isso que você precisa fazer.\n"
    .string "Você vai ver como é fácil quando tentar.$"

BerryHouse_EventScript_StartBlender:
    msgbox BerryHouse_Text_LetsBerryBlender, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_DoBerryBlending
    end

BerryHouse_Text_LetsBerryBlender:
    .string "Vamos começar, então!\p"
    .string "Hora de Misturar Frutas!$"

BerryHouse_EventScript_DoBerryBlending:
    @callnative RemoveFollowingPokemon
    copyvar VAR_0x8004, NUM_OPPONENTS
    fadescreen FADE_TO_BLACK
    special DoBerryBlending
    waitstate
    @callnative UpdateFollowingPokemon
    releaseall
    end




