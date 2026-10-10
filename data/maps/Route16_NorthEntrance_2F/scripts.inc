Route16_NorthEntrance_2F_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
    .string "Estou em um passeio relaxante de\n"
    .string "bicicleta com minha namorada.$"

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
    .string "Estamos pedalando juntos em nossas\n"
    .string "bicicletas novas.$"

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "É a Loja de Departamentos de Celadon!$"

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_Text_LongPathOverWater::
    .string "Vejamos o que os binóculos mostram…\p"
    .string "Há um longo caminho sobre a água\n"
    .string "ao longe.$"


@Aide Gift 4
Route16_NorthEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_AIDE_AMULET_COIN, Route16_NorthEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route16_NorthEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_AMULET_COIN, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_AMULET_COIN, 1
    waitmessage
    setflag FLAG_RECEIVED_AIDE_AMULET_COIN
    setflag FLAG_HIDE_AIDE_ROUTE16
    clearflag FLAG_AIDE_LOCATION_4
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route16_NorthEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE06_GET, Route16_NorthEntrance_2F_EventScript_AideNextLocation
    release
    end

Route16_NorthEntrance_2F_Text_GiveReward::
    .string "Oh… {PLAYER}!\p"
    .string "Fico feliz que tenha conseguido\n"
    .string "me encontrar!\p"
    .string "Entre o Snorlax adormecido e os\n"
    .string "Motoqueiros assustadores, eu nem sabia\l"
    .string "se conseguiríamos nos encontrar!\p"
    .string "A vida de Treinador deve ser difícil,\n"
    .string "então espero que isto ajude a aliviar\l"
    .string "um pouco as suas dificuldades.$"

Route16_NorthEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route16_NorthEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route16_NorthEntrance_2F_Text_ExplainReward::
	.string "Você sabia que Pokémon podem segurar itens?\p"
    .string "A Moeda Amuleto é um item para ser\n"
    .string "segurado por um Pokémon.\p"
    .string "Se o Pokémon estiver na sua equipe\n"
    .string "atual, você ganhará mais dinheiro.$"

Route16_NorthEntrance_2F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_5
    return
