PokemonLeague_AgathasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_AgathasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
	.byte 0

PokemonLeague_AgathasRoom_OnResume::
	setvar VAR_0x8004, 2
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_AgathasRoom_OnLoad::
	call_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 3
	call_if_eq PokemonLeague_AgathasRoom_EventScript_CloseEntry
	end

PokemonLeague_AgathasRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_AgathasRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_AgathasRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_AgathasRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 2, PokemonLeague_AgathasRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

PokemonLeague_AgathasRoom_EventScript_Agatha::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_AgathaPostgame
	msgbox PokemonLeague_AgathasRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_AgathaPostgame::
	msgbox PokemonLeague_AgathasRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha::
	setflag FLAG_DEFEATED_AGATHA
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_PostBattle2
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_PostBattle2
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle2
	release
	end

PokemonLeague_AgathasRoom_Text_Intro::
    .string "Eu sou Agatha, da Elite dos Quatro.\p"
    .string "Soube que Carvalho tem muito interesse\n"
    .string "em voce, crianca.\p"
    .string "Aquele velho tolo ja foi durão e\n"
    .string "bonitao no passado.\p"
    .string "Mas isso foi ha decadas.\n"
    .string "Ele e so uma sombra do que ja foi.\p"
    .string "Agora ele so quer ficar mexendo na\n"
    .string "sua Pokedex.\p"
    .string "Ele esta errado.\n"
    .string "Pokemon servem para lutar!\p"
    .string "{PLAYER}! Vou te mostrar como luta um\n"
    .string "verdadeiro treinador!$"

PokemonLeague_AgathasRoom_Text_Intro2::
    .string "Entao voce veio!\p"
    .string "Nao faz parte do meu feitio perder\n"
    .string "repetidas vezes.\p"
    .string "De tudo de si nesta batalha!$"

PokemonLeague_AgathasRoom_Text_Defeat::
    .string "Ora, ora!\n"
    .string "Voce e mesmo especial, crianca!$"

PokemonLeague_AgathasRoom_Text_Defeat2::
    .string "Nada mal!$"

PokemonLeague_AgathasRoom_Text_PostBattle::
    .string "Voce venceu!\p"
    .string "Agora vejo o que aquele velho tolo\n"
    .string "enxergou em voce.\p"
    .string "Nao tenho mais nada a dizer.\n"
    .string "Pode ir agora, crianca!$"

PokemonLeague_AgathasRoom_Text_PostBattle2::
    .string "Nao e de admirar que aquele velho\n"
    .string "tenha tanto interesse em voce.\p"
    .string "Carvalho e eu costumavamos ser bons\n"
    .string "rivais tambem, sabia? Como voce e {RIVAL}.\p"
    .string "Bem, o que esta esperando?\n"
    .string "Va para a proxima sala!$"
