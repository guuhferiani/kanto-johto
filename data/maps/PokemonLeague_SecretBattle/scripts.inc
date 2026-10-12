.equ LOCALID_PROF_OAK, 1

PokemonLeague_SecretBattle_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_SecretBattle_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_SecretBattle_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_SecretBattle_OnFrame
	.byte 0

PokemonLeague_SecretBattle_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call PokemonLeague_SecretBattle_EventScript_CheckStopTrigger
	end

PokemonLeague_SecretBattle_EventScript_CheckStopTrigger::
	goto_if_defeated SECRET_BATTLE_OAK, PokemonLeague_SecretBattle_EventScript_StopSceneTrigger
	return

PokemonLeague_SecretBattle_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_SecretBattle_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_SecretBattle_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_SecretBattle_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_SecretBattle_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_SecretBattle_EventScript_EnterRoom
	.2byte 0

PokemonLeague_SecretBattle_EventScript_EnterRoom::
	lockall
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_SecretBattle_Movement_PlayerEnter
	waitmovement 0
	delay 20
	turnobject LOCALID_PROF_OAK, DIR_SOUTH
	msgbox PokemonLeague_SecretBattle_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_RG_VICTORY_GYM_LEADER
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 50
	trainerbattle_no_intro SECRET_BATTLE_OAK, PokemonLeague_SecretBattle_Text_Defeat
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_CLEARED_SECRET_BATTLE
	call_if_unset FLAG_REVEALED_MEGA_STONES, Postgame_RevealMegaStones
	setflag FLAG_DEFEATED_SECRET_BATTLE
	setflag FLAG_TEMP_4
	playbgm MUS_RG_SLOW_PALLET, 0
	msgbox PokemonLeague_SecretBattle_Text_PostBattle
	closemessage
	applymovement LOCALID_PROF_OAK, PokemonLeague_SecretBattle_Movement_OakExit
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_SecretBattle_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 255, 5, 12
	waitstate
	releaseall
	end

Postgame_RevealMegaStones::
	clearflag FLAG_HIDE_VENUSAURITE
	clearflag FLAG_HIDE_CHARIZARDITE_X
	clearflag FLAG_HIDE_CHARIZARDITE_Y
	clearflag FLAG_HIDE_BLASTOISINTE
	clearflag FLAG_HIDE_BEEDRILLITE
	clearflag FLAG_HIDE_PIDEGOTITE
	clearflag FLAG_HIDE_ALAKAZITE
	clearflag FLAG_HIDE_SLOWBRONITE
	clearflag FLAG_HIDE_GENGARITE
	clearflag FLAG_HIDE_KANGASKHANITE
	clearflag FLAG_HIDE_PINSIRITE
	clearflag FLAG_HIDE_GYARDOSITE
	clearflag FLAG_HIDE_AERODACTYLITE
	clearflag FLAG_HIDE_MEWTONITE_Y
	clearflag FLAG_HIDE_MEWTONITE_X
	clearflag FLAG_HIDE_PALLET_BILL
	setflag FLAG_REVEALED_MEGA_STONES
	setvar VAR_SECRET_BATTLE_CLEAR, 1
	return

PokemonLeague_SecretBattle_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_SecretBattle_Movement_PlayerExit::
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_SecretBattle_Movement_OakExit::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_SecretBattle_Text_Intro::
    .string "Carvalho: Ola, {PLAYER}!\p"
    .string "Eu estava ansioso para encontrar voce.\p"
    .string "Ha muito tempo atras, eu era um\n"
    .string "treinador como voce e {RIVAL}.\p"
    .string "Ver voce completar a Pokedex me lembrou\n"
    .string "do motivo pelo qual fiquei tao fascinado\l"
    .string "por Pokemon.\p"
    .string "Pude ver voce e {RIVAL} ficarem mais\n"
    .string "fortes e criarem lacos com os Pokemon.\p"
    .string "Voce ate se tornou Campeao da Liga!\p"
    .string "Sabe, Agatha e eu eramos muito parecidos\n"
    .string "com voces na nossa epoca.\p"
    .string "Ja faz muito tempo desde que disse isto\n"
    .string "a alguem...\p"
    .string "Eu desafio voce para uma batalha Pokemon!$"

PokemonLeague_SecretBattle_Text_Defeat::
    .string "Maravilhoso!\p"
    .string "Simplesmente maravilhoso!$"

PokemonLeague_SecretBattle_Text_PostBattle::
    .string "{PLAYER}...\n"
    .string "Voce e realmente impressionante!\p"
    .string "Certamente merece o titulo de\n"
    .string "Campeao da Liga Pokemon!\p"
    .string "Venha comigo!$"
