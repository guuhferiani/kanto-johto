.set LOCALID_SS_ANNE, 1
.set LOCALID_MEW, 2
.set LOCALID_SAILOR, 3
.set LOCALID_FUGITIVE, 4

SSAnne_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SSAnne_Exterior_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SSAnne_Exterior_OnResume
	.byte 0

SSAnne_Exterior_OnTransition:
	call Common_EventScript_GetDayOrNight
	goto_if_set FLAG_SYS_GAME_CLEAR, SSAnne_Exterior_EventScript_SetupSSAqua
	end

SSAnne_Exterior_EventScript_SetupSSAqua::
	clearflag FLAG_HIDE_SS_ANNE
	clearflag FLAG_HIDE_VERMILION_HARBOR_SAILOR
	end

SSAnne_Exterior_OnWarp::
	map_script_2 VAR_SS_ANNE_STATE, 2, SSAnne_Exterior_BlockDock
	map_script_2 VAR_SS_ANNE_STATE, 3, SSAnne_Exterior_BlockDock
	.2byte 0

SSAnne_Exterior_OnResume:
	call Common_EventScript_GetDayOrNight
	goto_if_set FLAG_SYS_GAME_CLEAR, SSAnne_Exterior_EventScript_SetupSSAqua
	end

SSAnne_Exterior_BlockDock::
	setmetatile 32, 14, 0x31D, 1
	special DrawWholeMapView
	end

SSAnne_Exterior_SSAnneDeparts::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_Delay48
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	fadenewbgm MUS_SURF
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	special DoSSAnneDepartureCutscene
	waitstate
	delay 10
	setobjectxyperm LOCALID_SAILOR, 31,5
	clearflag FLAG_HIDE_VERMILION_HARBOR_SAILOR
	addobject LOCALID_SAILOR
	applymovement LOCALID_SAILOR, Movement_MissedBoat
	waitmovement 5
	playse SE_PIN
	applymovement LOCALID_SAILOR, Common_Movement_ExclamationMark
	waitse
	removeobject LOCALID_SS_ANNE
	setvar VAR_SS_ANNE_STATE, 3
	setvar VAR_SS_TICKET_CHECK, 2
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	releaseall
	end

Movement_MissedBoat:
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	step_end

SSAnne_Exterior_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SSAnne_Exterior_EventScript_SSAquaBoarding
	msgbox SSAnne_Exterior_Text_SSAquaPreparing, MSGBOX_DEFAULT
	release
	end

SSAnne_Exterior_EventScript_SSAquaBoarding::
	msgbox SSAnne_Exterior_Text_SSAquaWelcome, MSGBOX_DEFAULT
	message SSAnne_Exterior_Text_WhereToSail
	waitmessage
	multichoice 18, 6, MULTI_SS_AQUA_VERMILION, FALSE
	switch VAR_RESULT
	case 0, SSAnne_Exterior_EventScript_SailToJohto
	case 1, SSAnne_Exterior_EventScript_SailToFarawayIsland
	case 2, SSAnne_Exterior_EventScript_CancelSail
	case MULTI_B_PRESSED, SSAnne_Exterior_EventScript_CancelSail
	end

SSAnne_Exterior_EventScript_SailToJohto::
	msgbox SSAnne_Exterior_Text_ConfirmJohto, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_Exterior_EventScript_CancelSail
	msgbox SSAnne_Exterior_Text_DepartingToJohto, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	fadenewbgm MUS_SURF
	playse SE_SHIP
	delay 60
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 70
	waitstate
	release
	end

SSAnne_Exterior_EventScript_SailToFarawayIsland::
	msgbox SSAnne_Exterior_Text_ConfirmFaraway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_Exterior_EventScript_CancelSail
	msgbox SSAnne_Exterior_Text_DepartingToFaraway, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	fadenewbgm MUS_SURF
	playse SE_SHIP
	delay 60
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

SSAnne_Exterior_EventScript_CancelSail::
	msgbox SSAnne_Exterior_Text_ComeBackAnytime, MSGBOX_DEFAULT
	release
	end

SSAnne_Exterior_Text_SSAquaPreparing::
	.string "O S.S. Anne já zarpou em sua viagem anual.\p"
	.string "Estamos nos preparativos do navio S.S. Aqua\n"
	.string "para a conexão oceânica com Johto!\p"
	.string "O serviço será inaugurado assim que você\n"
	.string "conquistar a Liga Pokémon e se tornar Campeão!$"

SSAnne_Exterior_Text_SSAquaWelcome::
	.string "Marinheiro: Ahoy, Campeão {PLAYER}!\p"
	.string "Bem-vindo a bordo do transatlântico S.S. Aqua!\n"
	.string "Fazemos a travessia direta entre o Porto\n"
	.string "de Vermilion (Kanto) e o litoral de Johto!$"

SSAnne_Exterior_Text_WhereToSail::
	.string "Para onde gostaria de navegar hoje?$"

SSAnne_Exterior_Text_ConfirmJohto::
	.string "Rumo ao Porto de Johto, onde treinadores\n"
	.string "de elite e grandes desafios te aguardam!\p"
	.string "Podemos partir agora?$"

SSAnne_Exterior_Text_DepartingToJohto::
	.string "Marinheiro: Perfeito! Todos a bordo!\n"
	.string "Próxima parada: Costa de Johto!$"

SSAnne_Exterior_Text_ConfirmFaraway::
	.string "Rumo à misteriosa Ilha Distante em alto-mar!\n"
	.string "Podemos partir agora?$"

SSAnne_Exterior_Text_DepartingToFaraway::
	.string "Marinheiro: Levantando âncora!\n"
	.string "Destino: Ilha Distante!$"

SSAnne_Exterior_Text_ComeBackAnytime::
	.string "Estaremos a postos quando quiser navegar!$"

SSAnne_Exterior_EventScript_MewUnderTruck::
	goto_if_set FLAG_CHECKED_UNDER_TRUCK, SSAnne_Exterior_EventScript_MewNotUnderTruck
	goto_if_set FLAG_CAUGHT_MEW, SSAnne_Exterior_EventScript_MewNotUnderTruck
	goto_if_set FLAG_DEFEATED_MEW, SSAnne_Exterior_EventScript_MewNotUnderTruck
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadeoutbgm 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement 0
	clearflag FLAG_HIDE_MEW_UNDER_TRUCK
	addobject LOCALID_MEW
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitmoncry
	applymovement LOCALID_MEW, Movement_MewFlees
	waitmovement 3
	removeobject LOCALID_MEW
	setflag FLAG_CHECKED_UNDER_TRUCK
	delay 10
	fadeinbgm 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

Movement_MewFlees::
	delay_16
	delay_16
	emote_exclamation_mark
	face_right
	delay_16
	face_left
	delay_16
	walk_up
	walk_up
	walk_up
	set_invisible
	delay_16
	step_end

SSAnne_Exterior_EventScript_MewNotUnderTruck::
	lock
	msgbox SSAnne_Exterior_Text_MewNotUnderTruck, MSGBOX_DEFAULT
	release
	end

SSAnne_Exterior_Text_MewNotUnderTruck::
	.string "Não há nada aqui...$"

SSAnneExterior_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

SSAnneExterior_EventScript_Slowbro::
	lock
	faceplayer
    playmoncry SPECIES_SLOWBRO, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_DIAMOND, SSAnneExterior_EventScript_SlowbroDefeated
	msgbox SSAnneExterior_Text_Slowbro MSGBOX_DEFAULT
	release
	end

SSAnneExterior_Text_Slowbro:
	.string "SSSSSSSSSSSSSLLLLLLLLLOOOOOOOOOO\n"
	.string "OOOOOOOOOOOOOOOOOOOOOOWWWWWWWWWW$"

SSAnneExterior_EventScript_GentlemanDiamond::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DIAMOND, SSAnneExterior_EventScript_MegaHintSlowbro
	trainerbattle_single TRAINER_GENTLEMAN_DIAMOND, SSAnneExterior_Text_DiamondIntro, SSAnneExterior_Text_DiamondDefeat
	setflag FLAG_DEFEATED_DIAMOND
	msgbox SSAnneExterior_Text_DiamondPostBattle MSGBOX_AUTOCLOSE
	release
	end

SSAnneExterior_Text_DiamondIntro:
	.string "Ah, olá. Estou de férias com\n"
	.string "meu Slowbro e outros amigos.\p"
	.string "Gostaria de uma batalha Pokémon?$"

SSAnneExterior_Text_DiamondDefeat:
	.string "Estou impressionado!$"

SSAnneExterior_Text_DiamondPostBattle:
	.string "Muito obrigado pela boa batalha!\p"
	.string "Acho que vamos contemplar o oceano mais\n"
	.string "um pouco antes de surfar de volta para casa.$"

SSAnneExterior_EventScript_MegaHintSlowbro::    
    goto_if_set FLAG_GOT_SLOWBRONITE, SSAnneExterior_EventScript_DiamondDefeated
    msgbox SSAnneExterior_Text_SlowbroMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
SSAnneExterior_Text_SlowbroMegaHint:
    .string "Há ótimas ondas para surfar\n"
	.string "na sua Rota 20.\p"
	.string "Pensando bem, foi lá também que\n"
	.string "eu encontrei a nossa Slowbronite!$"

SSAnneExterior_EventScript_DiamondDefeated::
    msgbox DiamondDefeated_Text MSGBOX_DEFAULT
	release
	end

DiamondDefeated_Text:	
	.string "Você só tem uma vida e ninguém pode\n"
	.string "vivê-la por você.\p"
	.string "Não há problema em dar duro, mas você\n"
	.string "precisa tirar um tempo para brincar e descansar.$"

SSAnneExterior_EventScript_SlowbroDefeated::
	msgbox SlowbroDefeated MSGBOX_DEFAULT
	release
	end

SlowbroDefeated:	
	.string "BBBBRRRRRRRRRRRRRRRRRRRRRRRRRROOOO\n"
	.string "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO$"
