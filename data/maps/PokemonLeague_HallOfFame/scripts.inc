.set LOCALID_PROF_OAK, 1

PokemonLeague_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_HallOfFame_OnWarp
	.byte 0

PokemonLeague_HallOfFame_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_HallOfFame_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_HallOfFame_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_HallOfFame_EventScript_EnterRoom
	.2byte 0

PokemonLeague_HallOfFame_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_EnterRoom
	waitmovement 0
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_OakCongratulations
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_OakCongratulations2
	closemessage
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	call_if_le VAR_ADVENTURE_BEGINS, 6, PokemonLeague_HallOfFame_EventScript_UpdatePostgameVariables
	call_if_unset FLAG_LOOKER_POSTGAME_STARTED, PokemonLeague_HallOfFame_EventScript_BeginPostgameRockets
	setrespawn HEAL_LOCATION_PLAYERS_HOUSE
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_Movement_EnterRoom::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_HallOfFame_EventScript_OakCongratulations::
	msgbox PokemonLeague_HallOfFame_Text_OakCongratulations
	return

PokemonLeague_HallOfFame_EventScript_OakCongratulations2::
	msgbox PokemonLeague_HallOfFame_Text_OakCongratulations2
	return

PokemonLeague_HallOfFame_Text_OakCongratulations::
    .string "Carvalho: Cof-cof!\n"
    .string "Parabens, {PLAYER}!\p"
    .string "Este andar e o Hall da Fama Pokemon.\p"
    .string "Os Campeoes da Liga Pokemon sao\n"
    .string "homenageados por seus feitos aqui.\p"
    .string "Seus Pokemon tambem sao registrados\n"
    .string "no Hall da Fama.\p"
    .string "{PLAYER}!\p"
    .string "Voce trabalhou duro para se tornar o\n"
    .string "novo Campeao da Liga.\p"
    .string "Parabens, {PLAYER}, voce e seus Pokemon\n"
    .string "estao no Hall da Fama!$"

PokemonLeague_HallOfFame_Text_OakCongratulations2::
    .string "Carvalho: Cof-cof!\n"
    .string "Parabens, {PLAYER}!\p"
    .string "Voce trabalhou duro para manter seu\n"
    .string "status como Campeao da Liga.\p"
    .string "Vamos registrar estes Pokemon no\n"
    .string "Hall da Fama.\p"
    .string "Parabens, {PLAYER}, voce e seus Pokemon\n"
    .string "sao verdadeiros Campeoes!$"

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	special SetChampionSaveWarp
	setflag FLAG_IS_CHAMPION
	setflag FLAG_DAILY_TITLE_MATCH
	call PokemonLeague_HallOfFame_EventScript_ResetDefeatedEventLegendaries
	call PokemonLeague_HallOfFame_EventScript_ResetEliteFour
	special UpdateTrainerFanClubGameClear
	return

PokemonLeague_HallOfFame_EventScript_ResetDefeatedEventLegendaries::
	clearflag FLAG_DEFEATED_ARTICUNO
	clearflag FLAG_DEFEATED_ZAPDOS
	clearflag FLAG_DEFEATED_MOLTRES
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_DEFEATED_MEWTWO
	return

PokemonLeague_HallOfFame_EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_LORELEI
	clearflag FLAG_DEFEATED_BRUNO
	clearflag FLAG_DEFEATED_AGATHA
	clearflag FLAG_DEFEATED_LANCE
	clearflag FLAG_DEFEATED_RIVAL_CHAMPION
	clearflag FLAG_DEFEATED_SECRET_BATTLE
	cleartrainerflag TRAINER_ELITE_FOUR_LORELEI
	cleartrainerflag TRAINER_ELITE_FOUR_BRUNO
	cleartrainerflag TRAINER_ELITE_FOUR_AGATHA
	cleartrainerflag TRAINER_ELITE_FOUR_LANCE
	cleartrainerflag TRAINER_RIVAL_CHAMPION_JOLTEON
	cleartrainerflag TRAINER_RIVAL_CHAMPION_FLAREON
	cleartrainerflag TRAINER_RIVAL_CHAMPION_VAPOREON
	cleartrainerflag POSTGAME_ELITE_FOUR_LORELEI
	cleartrainerflag POSTGAME_ELITE_FOUR_BRUNO
	cleartrainerflag POSTGAME_ELITE_FOUR_AGATHA
	cleartrainerflag POSTGAME_ELITE_FOUR_LANCE
	cleartrainerflag SECRET_BATTLE_OAK
	setvar VAR_ELITE_4_STATE, 0
	setvar VAR_ELITE_4_MODE, 0
	return

PokemonLeague_HallOfFame_EventScript_UpdatePostgameVariables::
	setvar VAR_ADVENTURE_BEGINS, 7
	return

PokemonLeague_HallOfFame_EventScript_BeginPostgameRockets::
	setflag FLAG_QUEUE_LOOKER_POSTGAME_CALL
	setvar VAR_LOOKER_POSTGAME_CALL_STEPS, 0
	return

