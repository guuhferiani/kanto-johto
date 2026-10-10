Route12_NorthEntrance_2F_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_Text_TheresManFishing::
    .string "Vejamos o que os binóculos têm\n"
    .string "a mostrar…\p"
    .string "Há um homem pescando!$"

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
    .string "Vejamos o que os binóculos têm\n"
    .string "a mostrar…\p"
    .string "É a Torre Pokémon!$"

Route12_NorthEntrance_2F_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymore
	checkitemspace ITEM_TM27, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
	playfanfare MUS_OBTAIN_TMHM
	message Route12_NorthEntrance_2F_Text_ReceivedTM27
	waitfanfare
	waitmessage
	additem ITEM_TM27, 1
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	setflag FLAG_GOT_TM27
	release
	end

Route12_NorthEntrance_2F_Text_ReceivedTM27::
    .string "{PLAYER} recebeu o MT27\n"
    .string "da garota de luto.$"

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymore::
    .string "As cinzas do meu Pokémon estão guardadas\n"
    .string "na Torre Pokémon.\p"
    .string "Você pode ficar com este MT.\n"
    .string "Eu não preciso mais dele…$"

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
    msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
    release
    end

Route12_NorthEntrance_2F_Text_ExplainTM27::
    .string "O MT27 é um golpe chamado Retribuição…\p"
    .string "Se você tratar bem seu Pokémon, ele\n"
    .string "retribuirá seu amor dando o melhor de si\l"
    .string "na batalha.$"

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
    msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis
    release
    end
    
Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
    .string "Você não tem espaço para isto.$"
