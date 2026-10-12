.set LOCALID_BOAT, 4 
.set LOCALID_CAPTAIN, 5 

CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CinnabarIsland_OnResume
	.byte 0

CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	call Common_EventScript_GetDayOrNight
	end

CinnabarIsland_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CinnabarIsland_EventScript_Woman::
	lock
	faceplayer
	msgbox CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab
	release
	end

CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab::
    .string "Blaine, do Ginásio de Cinnabar, é um\n"
    .string "sujeito bastante excêntrico.\p"
    .string "Ele mora na ilha desde muito antes\n"
    .string "do Laboratório ser construído.$"

CinnabarIsland_EventScript_OldMan::
	msgbox CinnabarIsland_Text_ScientistsExperimentInMansion, MSGBOX_NPC
	end

CinnabarIsland_Text_ScientistsExperimentInMansion::
    .string "Cientistas realizam experimentos no\n"
    .string "edifício queimado.\p"
    .string "Sabe, aquele que todo mundo chama de\n"
    .string "Mansão Pokémon.$"

CinnabarIsland_EventScript_Kid::
	msgbox CinnabarIsland_Text_GhostStory, MSGBOX_NPC
	end

CinnabarIsland_Text_GhostStory::
	.string "As crianças daqui gostam de inventar\n"
	.string "histórias sobre a Mansão Pokémon.\p"
	.string "Minha favorita é a que diz que há um\n"
	.string "Mapa do Tesouro Antigo escondido em\l"
	.string "algum lugar lá dentro!$"

CinnabarIsland_EventScript_IslandSign::
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_IslandSign::
    .string "Ilha de Cinnabar\n"
    .string "A Cidade Ardente do Desejo Fervoroso$"

CinnabarIsland_EventScript_PokemonLabSign::
	msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
	end

CinnabarIsland_Text_PokemonLab::
    .string "Laboratório Pokémon$"

CinnabarIsland_EventScript_PokemonMansionSign::
	msgbox CinnabarIsland_Text_PokemonMansion, MSGBOX_SIGN
	end

CinnabarIsland_Text_PokemonMansion::
    .string "Mansão Pokémon\n"
    .string "AVISO: CONDENADA$"

CinnabarIsland_EventScript_GymSign::
	lockall
	msgbox CinnabarIsland_Text_GymSign
	releaseall
	end

CinnabarIsland_Text_GymSign::
    .string "Ginásio Pokémon da Ilha de Cinnabar\n"
    .string "Líder: Blaine\l"
    .string "O Mestre dos Enigmas Ardentes!$"

CinnabarIsland_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL, 1
	release
	end

CinnabarIsland_EventScript_LightClay::
	finditem ITEM_LIGHT_CLAY, 1
	release
	end

CinnabarIsland_EventScript_Depart::
	lock
	faceplayer
	msgbox CinnabarIsland_EventScript_Text_ReadyToSail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_EventScript_NotSail
	msgbox CinnabarIsland_EventScript_Text_LetsSail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPTAIN, Movement_CaptainEnterShip
	waitmovement 5
	call_if_eq VAR_FACING, DIR_NORTH, CinnabarIsland_EventScript_PlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, CinnabarIsland_EventScript_PlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, CinnabarIsland_EventScript_PlayerEast
	call_if_eq VAR_FACING, DIR_WEST, CinnabarIsland_EventScript_PlayerWest
	waitmovement 0
	setvar VAR_0x8004, LOCALID_BOAT
	call Common_EventScript_FerryDepart
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 15, 39
	waitstate
	release
	end

CinnabarIsland_EventScript_Text_ReadyToSail::
	.string "Pronto para uma aventura?$"

CinnabarIsland_EventScript_NotSail::
	msgbox CinnabarIsland_EventScript_Text_ReadyWhenYouAre, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_EventScript_Text_ReadyWhenYouAre:
	.string "Zarparemos assim que você\n"
	.string "estiver pronto!$"

CinnabarIsland_EventScript_Text_LetsSail:
	.string "Excelente! Vamos zarpar agora mesmo!\p"
	.string "Vamos encontrar a ilha indicada neste\n"
	.string "Mapa do Mar Antigo!$"

Movement_CaptainEnterShip::
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

CinnabarIsland_EventScript_PlayerNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipNorth
	return

CinnabarIsland_EventScript_PlayerSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipSouth
	return

CinnabarIsland_EventScript_PlayerEast::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipEast
	return

CinnabarIsland_EventScript_PlayerWest::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipWest
	return

Movement_PlayerEnterShipNorth::
	walk_up
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

Movement_PlayerEnterShipSouth::
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

Movement_PlayerEnterShipEast::
	walk_right
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

Movement_PlayerEnterShipWest::
	walk_left
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

CinnabarIsland_EventScript_GamblerRyan::
	trainerbattle_single TRAINER_GAMBLER_RYAN, CinnabarIsland_3F_Text_RyanIntro, CinnabarIsland_3F_Text_RyanDefeat
	msgbox CinnabarIsland_3F_Text_RyanPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

CinnabarIsland_3F_Text_RyanIntro:
	.string "Nunca esperei que alguém viria surfando\n"
	.string "e me encontraria aqui.$"

CinnabarIsland_3F_Text_RyanDefeat:
	.string "Ha ha ha, adeus ao meu descanso!$"

CinnabarIsland_3F_Text_RyanPostBattle:
	.string "Vim até aqui segurando meu Tentacool\n"
	.string "em busca de paz e sossego nas férias.\p"
	.string "Obrigado pela batalha!$"

