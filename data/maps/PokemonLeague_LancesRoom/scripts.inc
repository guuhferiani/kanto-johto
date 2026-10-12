.set LOCALID_LANCE, 1

PokemonLeague_LancesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LancesRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LancesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LancesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LancesRoom_OnFrame
	.byte 0

PokemonLeague_LancesRoom_OnResume::
	setvar VAR_0x8004, 3
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LancesRoom_OnLoad::
	compare VAR_ELITE_4_STATE, 4
	call_if_eq PokemonLeague_LancesRoom_EventScript_CloseEntry
	call_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_SetDoorOpen
	end

PokemonLeague_LancesRoom_EventScript_CloseEntry::
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	return

PokemonLeague_LancesRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpenLance
	return

PokemonLeague_LancesRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_LancesRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 3, PokemonLeague_LancesRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LancesRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_LancesRoom_Movement_WalkThroughCorridor
	waitmovement 0
	setflag FLAG_TEMP_2
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

PokemonLeague_LancesRoom_EventScript_SetEntryClosed::
	setmetatile 5, 14, METATILE_PokemonLeague_Entry_TopLeft_Closed, 1
	setmetatile 6, 14, METATILE_PokemonLeague_Entry_TopMid_Closed, 1
	setmetatile 7, 14, METATILE_PokemonLeague_Entry_TopRight_Closed, 1
	setmetatile 5, 15, METATILE_PokemonLeague_Entry_BottomLeft_Closed, 1
	setmetatile 6, 15, METATILE_PokemonLeague_Entry_BottomMid_Closed, 1
	setmetatile 7, 15, METATILE_PokemonLeague_Entry_BottomRight_Closed, 1
	setmetatile 6, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	setmetatile 7, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	return

PokemonLeague_LancesRoom_Movement_WalkThroughCorridor::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_LancesRoom_EventScript_Lance::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_LancePostgame
	msgbox PokemonLeague_LancesRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat
	setdynamicwarp MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM, 6, 19
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_LancePostgame::
	msgbox PokemonLeague_LancesRoom_Text_Intro2

	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	setdynamicwarp MAP_POKEMON_LEAGUE_SECRET_BATTLE, 6, 19
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_DefeatedLance::
	setvar VAR_0x8004, 0
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_LANCE
	call PokemonLeague_EventScript_OpenDoorLance
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	closemessage
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_LancesRoom_Text_PostBattle2
	release
	end

PokemonLeague_LancesRoom_Text_Intro::
    .string "Ah! Ouvi falar de voce,\n"
    .string "{PLAYER}!\p"
    .string "Eu lidero a Elite dos Quatro.\p"
    .string "Pode me chamar de Lance, o mestre\n"
    .string "dos dragoes.\p"
    .string "Voce sabe que dragoes sao Pokemon\n"
    .string "miticos.\p"
    .string "Sao dificeis de pegar e criar,\n"
    .string "mas seus poderes sao superiores.\p"
    .string "Eles sao praticamente indestrutiveis.\n"
    .string "Nao ha como bancar o esperto com eles.\p"
    .string "Bem, esta pronto para perder?\p"
    .string "Seu desafio na Liga termina comigo,\n"
    .string "{PLAYER}!$"

PokemonLeague_LancesRoom_Text_Intro2::
    .string "Fico feliz que tenha vindo.\p"
    .string "A reputacao da Liga Pokemon realmente\n"
    .string "decolou!\p"
    .string "E tudo gracas a voce.\p"
    .string "Teria vergonha de me chamar de Lance,\n"
    .string "o Treinador de Dragoes, se nao te\l"
    .string "desafiasse para uma batalha!$"

PokemonLeague_LancesRoom_Text_Defeat::
    .string "E isso!\p"
    .string "Odeio admitir, mas voce e um mestre\n"
    .string "Pokemon!$"

PokemonLeague_LancesRoom_Text_Defeat2::
    .string "Como pude ser encurralado a\n"
    .string "esse ponto?$"

PokemonLeague_LancesRoom_Text_PostBattle::
    .string "Ainda nao acredito que meus dragoes\n"
    .string "perderam para voce, {PLAYER}.\p"
    .string "Agora voce e o Campeao da Liga Pokemon!\p"
    .string "...Ou seria, mas ainda resta mais um\n"
    .string "desafio para voce.\p"
    .string "Ha mais um treinador para enfrentar!\n"
    .string "O nome dele e...\p"
    .string "{RIVAL}!\p"
    .string "Ele derrotou a Elite dos Quatro antes\n"
    .string "de voce.\p"
    .string "Ele e o verdadeiro Campeao da Liga\n"
    .string "Pokemon.$"

PokemonLeague_LancesRoom_Text_PostBattle2::
    .string "Minha brigada de dragoes nao e fraca.\p"
    .string "...O que significa que a sua forca e\n"
    .string "verdadeiramente incrivel!\p"
    .string "Muito bem entao, {PLAYER}!\p"
    .string "Voce derrotou a Elite dos Quatro mais\n"
    .string "uma vez, mas um ultimo desafio espera!\p"
    .string "Preparamos um desafio especial para\n"
    .string "voce, Campeao!$"
