.equ LOCALID_RIVAL,    1
.equ LOCALID_PROF_OAK, 2

PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerVaporeon
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerJolteon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_JOLTEON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerFlareon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_FLAREON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerVaporeon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_VAPOREON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_RG_VICTORY_GYM_LEADER
	call PokemonLeague_ChampionsRoom_EventScript_Battle
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_RIVAL_CHAMPION
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 255, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonLeague_ChampionsRoom_EventScript_BattleJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonLeague_ChampionsRoom_EventScript_BattleFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonLeague_ChampionsRoom_EventScript_BattleVaporeon
	return

PokemonLeague_ChampionsRoom_EventScript_BattleJolteon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_JOLTEON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleFlareon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_FLAREON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleVaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_VAPOREON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
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

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end


PokemonLeague_ChampionsRoom_Text_Intro::
    .string "{RIVAL}: Ei, {PLAYER}!\p"
    .string "Eu estava ansioso para te ver,\n"
    .string "{PLAYER}.\p"
    .string "Meu rival precisa ser forte para me\n"
    .string "manter afiado.\p"
    .string "Enquanto completava a Pokedex, procurei\n"
    .string "por Pokemon em todos os cantos.\p"
    .string "Nao so isso: montei equipes que\n"
    .string "vencem qualquer tipo de Pokemon.\p"
    .string "E agora...\p"
    .string "Eu sou o Campeao da Liga Pokemon!\p"
    .string "{PLAYER}!\n"
    .string "Sabe o que isso significa?\p"
    .string "Eu vou te dizer.\p"
    .string "Eu sou o treinador mais poderoso do\n"
    .string "mundo!$"

PokemonLeague_ChampionsRoom_Text_Defeat::
    .string "NAO!\n"
    .string "Nao pode ser!\l"
    .string "Voce me venceu no meu auge!\p"
    .string "Depois de todo o esforco para virar\n"
    .string "o Campeao da Liga?\p"
    .string "Meu reinado acabou tao rapido?\n"
    .string "Isso nao e justo!$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
    .string "Por que?\n"
    .string "Por que eu perdi?\p"
    .string "Eu nao cometi erro algum criando meus\n"
    .string "Pokemon...\p"
    .string "Droga! Voce e o novo Campeao da Liga\n"
    .string "Pokemon!\p"
    .string "Mesmo que eu nao queira admitir...$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
    .string "Carvalho: {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
    .string "Carvalho: Entao voce venceu!\n"
    .string "Meus sinceros parabens!\p"
    .string "Voce e o novo Campeao da Liga Pokemon!\p"
    .string "Voce cresceu tanto desde que partiu\n"
    .string "com Pikachu para trabalhar na Pokedex.\p"
    .string "{PLAYER}, voce agora e um mestre!$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
    .string "Carvalho: {RIVAL}...\n"
    .string "Estou desapontado com voce.\p"
    .string "Vim assim que soube que havia derrotado\n"
    .string "a Elite dos Quatro.\p"
    .string "Mas, quando cheguei aqui, voce ja\n"
    .string "tinha perdido!\p"
    .string "{RIVAL}, entende por que perdeu?\p"
    .string "Voce se esqueceu de tratar seus Pokemon\n"
    .string "com amor e confianca.\p"
    .string "Sem isso, voce nunca sera um Campeao\n"
    .string "novamente!$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
    .string "Carvalho: {PLAYER}.\p"
    .string "Voce entende que a sua vitoria nao\n"
    .string "foi apenas merito seu.\p"
    .string "O laco que compartilha com seus\n"
    .string "Pokemon e maravilhoso.\p"
    .string "{PLAYER}!\n"
    .string "Venha comigo!$"
