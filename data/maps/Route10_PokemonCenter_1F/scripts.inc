.set LOCALID_NURSE, 1

Route10_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
    .string "Uma pepita de ouro não serve para nada.\n"
    .string "Então eu vendi por ¥5000.$"

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
    .string "Os tipos de Pokémon se combinam\n"
    .string "de maneiras diferentes entre si.\p"
    .string "Cada tipo é mais forte que alguns tipos\n"
    .string "e mais fraco que outros.$"

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
    .string "Ouvi dizer que fantasmas assombram o\n"
    .string "Vilarejo de Lavender.$"

@Aide Gift 2
Route10_PokemonCenter_1F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_AIDE_EVERSTONE, Route10_PokemonCenter_1F_EventScript_AlreadyGotReward
    msgbox Route10_PokemonCenter_1F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_EVERSTONE, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_EVERSTONE, 1
    waitmessage
    setflag FLAG_RECEIVED_AIDE_EVERSTONE
    setflag FLAG_HIDE_AIDE_ROUTE10
    clearflag FLAG_AIDE_LOCATION_2
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route10_PokemonCenter_1F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE04_GET, Route10_PokemonCenter_1F_EventScript_AideNextLocation
    release
    end

Route10_PokemonCenter_1F_Text_GiveReward::
    .string "Oh… {PLAYER}!\n"
    .string "Estava procurando por você!\p"
    .string "Sou eu, Cedar, o dedicado assistente\n"
    .string "do Prof. Carvalho.\p"
    .string "Como anda a sua Pokédex?\p"
    .string "Ligue para o Prof. Carvalho qualquer hora\n"
    .string "para avaliar o seu progresso!\p"
    .string "De qualquer forma, ele me confiou esta\n"
    .string "Pedra Eterna.\p"
    .string "Então, {PLAYER}, aqui está!$"

Route10_PokemonCenter_1F_EventScript_AlreadyGotReward::
    msgbox Route10_PokemonCenter_1F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route10_PokemonCenter_1F_Text_ExplainReward::
    .string "Fazer Pokémon evoluírem com certeza\n"
    .string "ajuda a completar a Pokédex.\p"
    .string "Porém, às vezes, você pode não querer\n"
    .string "que certo Pokémon evolua.\p"
    .string "Nesse caso, dê a Pedra Eterna\n"
    .string "para esse Pokémon segurar.\p"
    .string "Ela impedirá a evolução, de acordo\n"
    .string "com o Professor.$"

Route10_PokemonCenter_1F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_3
    return
