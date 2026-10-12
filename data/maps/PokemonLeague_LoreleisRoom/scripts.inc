PokemonLeague_LoreleisRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LoreleisRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LoreleisRoom_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_LoreleisRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LoreleisRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LoreleisRoom_OnFrame
	.byte 0

PokemonLeague_LoreleisRoom_OnResume::
	setvar VAR_0x8004, 0
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LoreleisRoom_OnLoad::
	call_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 1
	call_if_eq PokemonLeague_LoreleisRoom_EventScript_CloseEntry
	end

PokemonLeague_LoreleisRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_LoreleisRoom_OnTransition::
	end

PokemonLeague_LoreleisRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_LoreleisRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 0, PokemonLeague_LoreleisRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

PokemonLeague_LoreleisRoom_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LoreleisRoom_EventScript_LoreleiPostgame
	msgbox PokemonLeague_LoreleisRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LORELEI, PokemonLeague_LoreleisRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei
	end

PokemonLeague_LoreleisRoom_Text_Intro::
    .string "Boas-vindas a Liga Pokemon.\p"
    .string "Eu sou Lorelei, da Elite dos Quatro.\p"
    .string "Ninguem me supera quando se trata de\n"
    .string "Pokemon de gelo.\p"
    .string "Golpes congelantes sao poderosos.\p"
    .string "Seus Pokemon ficarao a minha merce\n"
    .string "quando estiverem congelados.\p"
    .string "Hahaha!\n"
    .string "Voce esta pronto?$"

PokemonLeague_LoreleisRoom_Text_Defeat::
    .string "...As coisas nao deviam ser assim!$"

PokemonLeague_LoreleisRoom_EventScript_LoreleiPostgame::
	msgbox PokemonLeague_LoreleisRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_LORELEI, PokemonLeague_LoreleisRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei
	end

PokemonLeague_LoreleisRoom_Text_Intro2::
    .string "Boas-vindas a Liga Pokemon!\p"
    .string "Ei, que momento perfeito!\p"
    .string "Eu estava pensando no quanto queria\n"
    .string "batalhar com voce. Esteja pronto!$"

PokemonLeague_LoreleisRoom_Text_Defeat2::
	.string "Argh! Como?!$"

PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei::
	setflag FLAG_DEFEATED_LORELEI
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LoreleisRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LoreleisRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_Text_PostBattle::
    .string "Voce e melhor do que eu pensava.\n"
    .string "Pode prosseguir.\p"
    .string "Voce so teve uma amostra do poder\n"
    .string "da Liga Pokemon.$"

PokemonLeague_LoreleisRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle2
	release
	end

PokemonLeague_LoreleisRoom_Text_PostBattle2::
    .string "Posso ter perdido, mas nunca vou abrir\n"
    .string "mao dos meus Pokemon de Gelo!\p"
    .string "Voce tambem deve vencer usando os\n"
    .string "Pokemon de que mais gosta!$"
