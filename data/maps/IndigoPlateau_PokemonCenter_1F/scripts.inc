.set LOCALID_NURSE, 1
.set LOCALID_GUARD, 5

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
    .string "E ai!\n"
    .string "Futuro campeao!\p"
    .string "Na Liga Pokemon, voce enfrentara\n"
    .string "a Elite dos Quatro em sequencia.\p"
    .string "Se perder, tera que comecar tudo\n"
    .string "de novo!\p"
    .string "E agora ou nunca!\n"
    .string "Va em frente!$"

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_GAME_CLEAR, IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourFirstChallenge
    msgbox IndigoPlateau_PokemonCenter_1F_Text_GreetingsChampion, MSGBOX_NPC
    goto_if_unset FLAG_DAILY_TITLE_MATCH, IndigoPlateau_PokemonCenter_1F_EventScript_TitleMatch
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourPostGame
    end

IndigoPlateau_PokemonCenter_1F_Text_GreetingsChampion::
	.string "Ola, Campeao {PLAYER}!$"
	
IndigoPlateau_PokemonCenter_1F_EventScript_TitleMatch::
	playse SE_PIN
	applymovement LOCALID_GUARD, Common_Movement_ExclamationMark
	waitmovement 5
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Challenger, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
	setflag FLAG_DAILY_TITLE_MATCH
	setvar VAR_TITLE_MATCH_OPPONENT, 0
	addvar VAR_TITLE_MATCHES, 1
	call ClearTitleMatches
	msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

ClearTitleMatches::
	cleartrainerflag TITLE_MATCH_STEPH
	cleartrainerflag TITLE_MATCH_LIZ
	cleartrainerflag TITLE_MATCH_MIKE
	cleartrainerflag TITLE_MATCH_CHRIS
	cleartrainerflag TITLE_MATCH_KEV
	cleartrainerflag TITLE_MATCH_MEGHAN
	cleartrainerflag TITLE_MATCH_STEVE
	cleartrainerflag TITLE_MATCH_M
	cleartrainerflag TITLE_MATCH_BEAN
	cleartrainerflag TITLE_MATCH_ANNIE
	cleartrainerflag TITLE_MATCH_BROCK
	cleartrainerflag TITLE_MATCH_MISTY
	cleartrainerflag TITLE_MATCH_SURGE
	cleartrainerflag TITLE_MATCH_ERIKA
	cleartrainerflag TITLE_MATCH_SABRINA
	cleartrainerflag TITLE_MATCH_KOGA
	cleartrainerflag TITLE_MATCH_BLAINE
	cleartrainerflag TITLE_MATCH_ROCKET
	cleartrainerflag TITLE_MATCH_DAISY
	cleartrainerflag TITLE_MATCH_RIVAL_VAPOREON
	cleartrainerflag TITLE_MATCH_RIVAL_JOLTEON
	cleartrainerflag TITLE_MATCH_RIVAL_FLAREON
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourPostGame::
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourPostGame, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
    msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    setvar VAR_ELITE_4_MODE, 2
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

IndigoPlateau_PokemonCenter_1F_Text_Challenger::
	.string "Oh! Parece que alguem derrotou a\n"
	.string "Elite dos Quatro hoje.\p"
	.string "Estao te desafiando para Disputa de Titulo!\n"
	.string "Veio aqui aceitar o desafio?$"

IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourFirstChallenge::
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFour, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
    msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    setvar VAR_ELITE_4_MODE, 1
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour::
	call_if_eq VAR_FACING, DIR_NORTH, IndigoPlateau_PokemonCenter_1F_EventScript_EnterNorth
	call_if_eq VAR_FACING, DIR_WEST, IndigoPlateau_PokemonCenter_1F_EventScript_EnterWest
	call_if_eq VAR_FACING, DIR_EAST, IndigoPlateau_PokemonCenter_1F_EventScript_EnterEast
	goto_if_eq VAR_ELITE_4_MODE, 0, IndigoPlateau_PokemonCenter_1F_EventScript_WarpTitleMatch
	warp MAP_POKEMON_LEAGUE_LORELEIS_ROOM, 6, 12
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_WarpTitleMatch::
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_FaceDown
	waitmovement 1
	warp MAP_POKEMON_LEAGUE_CHALLENGER_ROOM, 6, 3
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_EnterNorth::
	applymovement LOCALID_GUARD, Guard_Movement_StepRight
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterNorth
	waitmovement 0
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EnterWest::
	applymovement LOCALID_GUARD, Guard_Movement_StepLeft
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterWest
	waitmovement 0
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EnterEast::
	applymovement LOCALID_GUARD, Guard_Movement_StepRight
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterEast
	waitmovement 0
	return

Guard_Movement_StepRight:
	walk_right
	face_down
	step_end

Guard_Movement_StepLeft:
	walk_left
	face_down
	step_end

Player_Movement_EnterNorth:
	walk_up
	walk_up
	set_invisible
	step_end

Player_Movement_EnterWest:
	walk_left
	walk_up
	set_invisible
	step_end

Player_Movement_EnterEast:
	walk_right
	walk_up
	set_invisible
	step_end

Player_Movement_FaceDown:
	face_down
	step_end

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFour::
    .string "A partir daqui, voce enfrenta a\n"
    .string "Elite dos Quatro um por um.\p"
    .string "Se vencer, uma porta se abre para o\n"
    .string "proximo treinador.\p"
    .string "Nao pode voltar ate derrotar todos\n"
    .string "ou ser derrotado.\p"
    .string "Esta preparado para o desafio?$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourPostGame::
    .string "Como Campeao, voce pode desafiar a\n"
    .string "Elite dos Quatro para exibicao.\p"
    .string "Mas esteja avisado.\p"
    .string "Agora que ja provou suas habilidades,\n"
    .string "eles nao vao pegar leve.\p"
    .string "Esta preparado para o desafio?$"

IndigoPlateau_PokemonCenter_1F_EventScript_Decline::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GuardDecline, MSGBOX_DEFAULT
	turnobject LOCALID_GUARD, DIR_SOUTH
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GuardDecline::
	.string "Eu compreendo.\n"
	.string "Fale comigo se mudar de ideia.$"

IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck::
	.string "Excelente!\n"
	.string "Boa sorte!$"

IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
    .string "Os Pokemon Fantasma de Agatha sao\n"
    .string "assustadoramente resistentes.\p"
    .string "Treinei meus Pokemon do tipo Lutador\n"
    .string "ao maximo.\p"
    .string "Fui enfrentar Agatha bem confiante,\n"
    .string "mas ela acabou com a gente.\p"
    .string "Aquela senhora tambem tem um pavio\n"
    .string "curtissimo.\p"
    .string "Nao precisa de nada para aquela velha\n"
    .string "assustadora comecar a gritar.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Dragontamer::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
    .string "Talvez ser da Elite dos Quatro\n"
    .string "esteja no sangue.\p"
    .string "Pelo que ouvi, Lance tem uma prima\n"
    .string "que e Lider de Ginasio em algum\l"
    .string "lugar bem distante.$"

IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal::
	lock
	faceplayer
	msgbox PokemonJournal_Text_SpecialFeatureLance
	release
	end

PokemonJournal_Text_SpecialFeatureLance::
	.string "Revista Pokemon\p"
	.string "Edicao Especial:\n"
	.string "Lance da Elite dos Quatro!\p"
	.string "Dizem que o avo de Lance e o anciao\n"
	.string "de um famoso cla de mestres de\l"
	.string "dragoes.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Pokemart::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NONE
	release
	end


IndigoPlateau_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_BERRY, IndigoPlateau_PokemonCenter_1F_EventScript_Determination
	msgbox IndigoPlateau_PokemonCenter_1F_Text_NoPokeCenters MSGBOX_NPC
	random 3
	call_if_eq VAR_RESULT, 0, IndigoPlateau_PokemonCenter_1F_EventScript_GiveSitrusBerry
	call_if_eq VAR_RESULT, 1, IndigoPlateau_PokemonCenter_1F_EventScript_GiveLumBerry
	call_if_eq VAR_RESULT, 2, IndigoPlateau_PokemonCenter_1F_EventScript_GiveLeppaBerry
	setflag FLAG_DAILY_BATTLE_BERRY
	goto IndigoPlateau_PokemonCenter_1F_EventScript_Determination
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GiveSitrusBerry::
	giveitem ITEM_SITRUS_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_EventScript_GiveLumBerry::
	giveitem ITEM_LUM_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_EventScript_GiveLeppaBerry::
	giveitem ITEM_LEPPA_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_Text_NoPokeCenters::
	.string "Ao enfrentar a Elite dos Quatro, voce\n"
	.string "nao podera voltar ao Centro Pokemon\l"
	.string "para se curar!\p"
	.string "Uma frutinha como esta pode fazer toda\n"
	.string "a diferenca!$"

IndigoPlateau_PokemonCenter_1F_EventScript_Determination::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Determination, MSGBOX_NPC
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_Determination::
	.string "E preciso dar tudo de si para encarar\n"
	.string "a Elite dos Quatro!\p"
	.string "Espero que esteja cheio de determinacao!$"
