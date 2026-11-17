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
	setflag FLAG_SYS_PC_FROM_DEBUG_MENU
	special ShowPokemonStorageSystemPC
	waitstate
	releaseall
	end

EventScript_PortablePC_Relearn::
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

EventScript_PortablePC_Delete::
	goto PkmnLeague_Services_ChooseMonAndMoveToForget
	end

EventScript_PortablePC_Close::
	playse SE_PC_OFF
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end
