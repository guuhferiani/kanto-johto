Route15_WestEntrance_2F_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_CAUGHT_ARTICUNO, Route15_WestEntrance_2F_EventScript_RightBinoculars
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_Text_LargeShiningBird::
    .string "Vejamos o que os binóculos têm\n"
    .string "a mostrar…\p"
    .string "Um grande pássaro brilhante está voando\n"
    .string "em direção ao mar.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
    .string "Vejamos o que os binóculos têm\n"
    .string "a mostrar…\p"
    .string "Parece uma pequena ilha no\n"
    .string "horizonte!$"

@Aide Gift 5
Route15_WestEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_EXP_SHARE, Route15_WestEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route15_WestEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_EXP_SHARE, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_EXP_SHARE, 1
    waitmessage
    setflag FLAG_RECEIVED_EXP_SHARE
    setflag FLAG_HIDE_AIDE_ROUTE15
    clearflag FLAG_AIDE_LOCATION_5
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route15_WestEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    clearflag FLAG_HIDE_AIDE_OAK_LAB
    release
    end

Route15_WestEntrance_2F_Text_GiveReward::
    .string "{PLAYER}!\p"
    .string "Você está com a corda toda!\p"
    .string "Conforme a sua jornada continua,\n"
    .string "treinar Pokémon pode ficar mais difícil,\l"
    .string "especialmente se sua equipe mudar!\p"
    .string "Então criamos um dispositivo que pode\n"
    .string "facilitar o treinamento de Pokémon.$"

Route15_WestEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route15_WestEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route15_WestEntrance_2F_Text_ExplainReward::
    .string "Você pode ativar o Repartir Exp no seu\n"
    .string "bolso de Itens Chave.\p"
    .string "Ele distribui Pontos de EXP para os\n"
    .string "Pokémon da sua equipe, mesmo se eles não\l"
    .string "participarem da batalha.\p"
    .string "Você também pode desativá-lo quando quiser!$"
