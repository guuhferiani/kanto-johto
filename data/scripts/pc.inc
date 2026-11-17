EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_BILL, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_BILL, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_PortablePC::
	lockall
	playse SE_PC_LOGIN
	message gText_WhichPCShouldBeAccessed
	waitmessage
	multichoice 0, 0, MULTI_PORTABLE_PC, FALSE
	switch VAR_RESULT
	case 0, EventScript_PortablePC_Boxes
	case 1, EventScript_PortablePC_Relearn
	case 2, EventScript_PortablePC_Delete
	case 3, EventScript_PortablePC_Close
	case MULTI_B_PRESSED, EventScript_PortablePC_Close
	end

EventScript_PortablePC_Boxes::
	closemessage
	setflag FLAG_SYS_PC_FROM_DEBUG_MENU
	special ShowPokemonStorageSystemPC
	waitstate
	releaseall
	end

EventScript_PortablePC_Relearn::
	msgbox EventScript_Text_PortablePC_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PortablePC_Close
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_PortablePC_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, EventScript_PortablePC_NoMoveToTeach
	msgbox EventScript_Text_PortablePC_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, EventScript_PortablePC_Relearn
	releaseall
	end

EventScript_PortablePC_NoMoveToTeach::
	msgbox EventScript_Text_PortablePC_NoMoveToTeach, MSGBOX_DEFAULT
	goto EventScript_PortablePC_Relearn
	end

EventScript_PortablePC_CantTeachEgg::
	msgbox EventScript_Text_PortablePC_CantTeachEgg, MSGBOX_DEFAULT
	goto EventScript_PortablePC_Relearn
	end

EventScript_PortablePC_Delete::
	msgbox EventScript_Text_PortablePC_WhichMonForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_PortablePC_Close
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_PortablePC_EggCantForget
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, EventScript_PortablePC_OnlyOneMove
	msgbox EventScript_Text_PortablePC_WhichMoveForget, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, EventScript_PortablePC_Delete
	special BufferMoveDeleterNicknameAndMove
	msgbox EventScript_Text_PortablePC_ConfirmForget, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_PortablePC_Close
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, EventScript_PortablePC_CantForgetSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox EventScript_Text_PortablePC_ForgotMove, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EventScript_PortablePC_OnlyOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox EventScript_Text_PortablePC_OnlyOneMove, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EventScript_PortablePC_EggCantForget::
	msgbox EventScript_Text_PortablePC_EggCantForget, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EventScript_PortablePC_CantForgetSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox EventScript_Text_PortablePC_CantForgetSurf, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

EventScript_PortablePC_Close::
	closemessage
	playse SE_PC_OFF
	releaseall
	end

EventScript_Text_PortablePC_TutorWhichMon:
	.string "Qual Pokémon deve lembrar um golpe?$"

EventScript_Text_PortablePC_TeachWhichMove:
	.string "Qual golpe deseja ensinar?$"

EventScript_Text_PortablePC_NoMoveToTeach:
	.string "Este Pokémon não possui nenhum\n"
	.string "golpe disponível para lembrar.$"

EventScript_Text_PortablePC_CantTeachEgg:
	.string "Não é possível ensinar golpes\n"
	.string "para um Ovo Pokémon.$"

EventScript_Text_PortablePC_WhichMonForget:
	.string "Qual Pokémon deve esquecer um golpe?$"

EventScript_Text_PortablePC_WhichMoveForget:
	.string "Qual golpe deve ser esquecido?$"

EventScript_Text_PortablePC_OnlyOneMove:
	.string "{STR_VAR_1} conhece apenas um golpe\n"
	.string "e não pode esquecê-lo.$"

EventScript_Text_PortablePC_ConfirmForget:
	.string "Fazer {STR_VAR_1} esquecer o golpe\n"
	.string "{STR_VAR_2}?$"

EventScript_Text_PortablePC_ForgotMove:
	.string "Pronto! {STR_VAR_1} esqueceu\n"
	.string "{STR_VAR_2} completamente.$"

EventScript_Text_PortablePC_EggCantForget:
	.string "Um Ovo Pokémon não conhece\n"
	.string "nenhum golpe.$"

EventScript_Text_PortablePC_CantForgetSurf:
	.string "{STR_VAR_1} é o único Pokémon que\n"
	.string "sabe Surf e não pode esquecê-lo.$"

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end
