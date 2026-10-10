.set LOCALID_FUGITIVE, 6 

Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route18_OnResume
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition:
	call_if_eq VAR_CYCLING_ROAD, 1, Route18_OnTransitionCyclingRoad
	call Common_EventScript_GetDayOrNight
	end

Route18_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_CYCLING_ROAD, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_EventScript_Ramiro::
	trainerbattle_single TRAINER_BIRD_KEEPER_RAMIRO, Route18_Text_RamiroIntro, Route18_Text_RamiroDefeat
	msgbox Route18_Text_RamiroPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_Text_RamiroIntro::
    .string "Kurukkoo!\n"
    .string "O que achou do meu canto de pássaro?$"

Route18_Text_RamiroDefeat::
    .string "Tive que incomodar você!$"

Route18_Text_RamiroPostBattle::
    .string "Eu coleciono Pokémon marinhos aos\n"
    .string "fins de semana porque o mar é muito perto.$"

Route18_EventScript_Jacob::
	trainerbattle_single TRAINER_BIRD_KEEPER_JACOB, Route18_Text_JacobIntro, Route18_Text_JacobDefeat
	msgbox Route18_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_Text_JacobIntro::
    .string "Este é o meu território!\n"
    .string "Saia daqui!$"

Route18_Text_JacobDefeat::
    .string "Droga!$"

Route18_Text_JacobPostBattle::
    .string "Esta é a minha área favorita para\n"
    .string "capturar Pokémon.$"

Route18_Text_RouteSign::
    .string "Rota 18\n"
    .string "Celadon - Fuchsia$"

Route18_Text_CyclingRoadSign::
    .string "Rodovia dos Ciclistas\n"
    .string "Proibida a entrada de pedestres!$"

Route18_EventScript_Wilton::
	trainerbattle_single REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1, Route18_Text_WiltonIntro, Route18_Text_WiltonDefeat, Route18_EventScript_RegisterWiltonAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route18_EventScript_WiltonRematch
	msgbox Route18_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route18_Text_WiltonIntro::
    .string "Eu sempre vasculho cada área de mato\n"
    .string "em busca de novos Pokémon.$"

Route18_Text_WiltonDefeat::
    .string "Tsc!$"

Route18_Text_WiltonPostBattle::
    .string "Como eu queria ter uma bicicleta!$"

Route18_EventScript_RegisterWiltonAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route18_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1
	release
	end

Route18_Text_WiltonRegister:
	.string "Você está completando a Pokédex?\p"
	.string "Me ligue se encontrar bons lugares\n"
	.string "para capturar Pokémon!$"

Route18_EventScript_WiltonRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1, Route18_Text_WiltonRematchIntro, Route18_Text_WiltonDefeat
	msgbox Route18_Text_WiltonRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_Text_WiltonRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Capturou algum Pokémon raro?$"

Route18_Text_WiltonRematchPostBattle::
	.string "Se eu tivesse uma bicicleta, poderia ir\n"
	.string "procurar Pokémon em qualquer lugar!$"

Route18_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

Route18_EventScript_Pinsir::
	lock
	faceplayer
	playmoncry SPECIES_PINSIR, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_LILY, Route18_EventScript_PinsirDefeated
	msgbox Route18_Text_Pinsir MSGBOX_DEFAULT
	release
	end

Route18_Text_Pinsir:
	.string "Pinsir está mastigando um graveto.$"

Route18_EventScript_AromaLadyLily::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LILY, Route18_EventScript_MegaHintPinsir
	trainerbattle_single TRAINER_AROMALADY_LILY, Route18_Text_LilyIntro, Route18_Text_LilyDefeat
	setflag FLAG_DEFEATED_LILY
	msgbox Route18_Text_LilyPostBattle MSGBOX_AUTOCLOSE
	release
	end

Route18_Text_LilyIntro:
	.string "Mais um treinador por aqui!\n"
	.string "Você também usa Pokémon pássaro?$"

Route18_Text_LilyDefeat:
	.string "Eu perdi? Que maravilhoso!$"

Route18_Text_LilyPostBattle:
	.string "Essa foi uma ótima batalha!\n"
	.string "Não acha, Beliscão?$"

Route18_EventScript_MegaHintPinsir::    
    goto_if_set FLAG_GOT_PINSIRITE, Route18_EventScript_LilyDefeated
    msgbox Route18_Text_PinsirMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route18_Text_PinsirMegaHint:
    .string "O que é isso? Mega Pedra?\n"
	.string "Ah, é verdade, eu encontrei a minha\l"
	.string "na Zona do Safári logo ali!$"

Route18_EventScript_LilyDefeated::
    msgbox LilyDefeated_Text MSGBOX_DEFAULT
	release
	end

LilyDefeated_Text:	
	.string "Obrigada pela ótima partida!\n"
	.string "Eu só posso desafiar o Wilton de tempos\l"
	.string "em tempos, sabe como é.$"

Route18_EventScript_PinsirDefeated::
	msgbox PinsirDefeated MSGBOX_DEFAULT
	release
	end

PinsirDefeated:	
	.string "Pinsir gesticula pedindo um toca aqui.$"
