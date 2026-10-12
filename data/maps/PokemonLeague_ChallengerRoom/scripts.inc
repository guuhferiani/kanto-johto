.set LOCALID_OPPONENT, 1

PokemonLeague_ChallengerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TitleMatch_Heal
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_ChallengerRoom_OnTransition
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChallengerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChallengerRoom_OnFrame
	.byte 0

TitleMatch_Heal::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	end

PokemonLeague_ChallengerRoom_OnTransition::
	call_if_eq VAR_TITLE_MATCH_OPPONENT, 0, PokemonLeague_ChallengerRoom_SelectOpponent
	return


PokemonLeague_ChallengerRoom_SelectOpponent::
	call_if_ne VAR_TITLE_MATCHES, 3, PokemonLeague_ChallengerRoom_StandardOpponent
	call_if_eq VAR_TITLE_MATCHES, 3, PokemonLeague_ChallengerRoom_SpecialOpponent
	return

PokemonLeague_ChallengerRoom_StandardOpponent::
	random 9
	addvar VAR_RESULT, 1
	call_if_eq VAR_RESULT, 1, PokemonLeague_ChallengerRoom_Setup_Steph
	call_if_eq VAR_RESULT, 2, PokemonLeague_ChallengerRoom_Setup_Liz
	call_if_eq VAR_RESULT, 3, PokemonLeague_ChallengerRoom_Setup_Mike
	call_if_eq VAR_RESULT, 4, PokemonLeague_ChallengerRoom_Setup_Chris
	call_if_eq VAR_RESULT, 5, PokemonLeague_ChallengerRoom_Setup_Kev
	call_if_eq VAR_RESULT, 6, PokemonLeague_ChallengerRoom_Setup_Meghan
	call_if_eq VAR_RESULT, 7, PokemonLeague_ChallengerRoom_Setup_Steve
	call_if_eq VAR_RESULT, 8, PokemonLeague_ChallengerRoom_Setup_M
	call_if_eq VAR_RESULT, 9, PokemonLeague_ChallengerRoom_Setup_Bean
	call_if_eq VAR_RESULT, 10, PokemonLeague_ChallengerRoom_Setup_Annie
	return

PokemonLeague_ChallengerRoom_SpecialOpponent::
	random 9
	addvar VAR_RESULT, 1
	call_if_eq VAR_RESULT, 1, PokemonLeague_ChallengerRoom_Setup_Brock
	call_if_eq VAR_RESULT, 2, PokemonLeague_ChallengerRoom_Setup_Misty
	call_if_eq VAR_RESULT, 3, PokemonLeague_ChallengerRoom_Setup_Surge
	call_if_eq VAR_RESULT, 4, PokemonLeague_ChallengerRoom_Setup_Erika
	call_if_eq VAR_RESULT, 5, PokemonLeague_ChallengerRoom_Setup_Sabrina
	call_if_eq VAR_RESULT, 6, PokemonLeague_ChallengerRoom_Setup_Koga
	call_if_eq VAR_RESULT, 7, PokemonLeague_ChallengerRoom_Setup_Blaine
	call_if_eq VAR_RESULT, 8, PokemonLeague_ChallengerRoom_Setup_Rocket
	call_if_eq VAR_RESULT, 9, PokemonLeague_ChallengerRoom_Setup_Daisy
	call_if_eq VAR_RESULT, 10, PokemonLeague_ChallengerRoom_Setup_Rival
	return

PokemonLeague_ChallengerRoom_Setup_Steph::
	setvar VAR_TITLE_MATCH_OPPONENT, 1
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LASS
	return

PokemonLeague_ChallengerRoom_Setup_Liz::
	setvar VAR_TITLE_MATCH_OPPONENT, 2
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	return

PokemonLeague_ChallengerRoom_Setup_Mike::
	setvar VAR_TITLE_MATCH_OPPONENT, 3
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_COOL_TRAINER_M
	return

PokemonLeague_ChallengerRoom_Setup_Chris::
	setvar VAR_TITLE_MATCH_OPPONENT, 4
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CUEBALL
	return

PokemonLeague_ChallengerRoom_Setup_Kev::
	setvar VAR_TITLE_MATCH_OPPONENT, 5
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_NINJA_BOY
	return

PokemonLeague_ChallengerRoom_Setup_Meghan::
	setvar VAR_TITLE_MATCH_OPPONENT, 6
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HEX_MANIAC
	return

PokemonLeague_ChallengerRoom_Setup_Steve::
	setvar VAR_TITLE_MATCH_OPPONENT, 7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DRAGON_TAMER
	return

PokemonLeague_ChallengerRoom_Setup_M::
	setvar VAR_TITLE_MATCH_OPPONENT, 8
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BUG_CATCHER
	return

PokemonLeague_ChallengerRoom_Setup_Bean::
	setvar VAR_TITLE_MATCH_OPPONENT, 9
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_YOUNGSTER
	return

PokemonLeague_ChallengerRoom_Setup_Annie::
	setvar VAR_TITLE_MATCH_OPPONENT, 10
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCHOOL_KID_F
	return

PokemonLeague_ChallengerRoom_Setup_Brock::
	setvar VAR_TITLE_MATCH_OPPONENT, 11
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BROCK
	return

PokemonLeague_ChallengerRoom_Setup_Misty::
	setvar VAR_TITLE_MATCH_OPPONENT, 12
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MISTY
	return

PokemonLeague_ChallengerRoom_Setup_Surge::
	setvar VAR_TITLE_MATCH_OPPONENT, 13
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SURGE
	return

PokemonLeague_ChallengerRoom_Setup_Erika::
	setvar VAR_TITLE_MATCH_OPPONENT, 14
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ERIKA
	return

PokemonLeague_ChallengerRoom_Setup_Sabrina::
	setvar VAR_TITLE_MATCH_OPPONENT, 15
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SABRINA
	return

PokemonLeague_ChallengerRoom_Setup_Koga::
	setvar VAR_TITLE_MATCH_OPPONENT, 16
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KOGA
	return

PokemonLeague_ChallengerRoom_Setup_Blaine::
	setvar VAR_TITLE_MATCH_OPPONENT, 17
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLAINE
	return

PokemonLeague_ChallengerRoom_Setup_Rocket::
	setvar VAR_TITLE_MATCH_OPPONENT, 18
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ROCKET_MEMBER_F
	return

PokemonLeague_ChallengerRoom_Setup_Daisy::
	setvar VAR_TITLE_MATCH_OPPONENT, 19
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DAISY
	return

PokemonLeague_ChallengerRoom_Setup_Rival::
	setvar VAR_TITLE_MATCH_OPPONENT, 20
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLUE
	return

PokemonLeague_ChallengerRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, PokemonLeague_ChallengerRoom_EnterScene
	.2byte 0

PokemonLeague_ChallengerRoom_EnterScene::
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, ChallengeRoom_PlayerEnter
	waitmovement 0
	applymovement LOCALID_OPPONENT, ChallengeRoom_OpponentEnter
	waitmovement 1
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 1, TitleMatch_Steph
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 2, TitleMatch_Liz
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 3, TitleMatch_Mike
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 4, TitleMatch_Chris
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 5, TitleMatch_Kev
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 6, TitleMatch_Meghan
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 7, TitleMatch_Steve
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 8, TitleMatch_M
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 9, TitleMatch_Bean
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 10, TitleMatch_Annie
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 11, TitleMatch_Brock
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 12, TitleMatch_Misty
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 13, TitleMatch_Surge
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 14, TitleMatch_Erika
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 15, TitleMatch_Sabrina
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 16, TitleMatch_Koga
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 17, TitleMatch_Blaine
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 18, TitleMatch_Rocket
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 19, TitleMatch_Daisy
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 20, TitleMatch_Rival
	end

ChallengeRoom_PlayerEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

ChallengeRoom_OpponentEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TitleMatch_BattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TitleMatch_EventScript_Victory
	goto TitleMatch_EventScript_Defeat
	end

TitleMatch_EventScript_Victory::
	msgbox TitleMatch_Text_TitleMatchVictory, MSGBOX_DEFAULT
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 11, 14
	goto TitleMatch_EventScript_Exit
	end

TitleMatch_EventScript_Defeat::
	msgbox TitleMatch_Text_TitleMatchDefeated, MSGBOX_DEFAULT

TitleMatch_EventScript_Exit::
	waitmessage
	closemessage
	applymovement LOCALID_OPPONENT, ChallengeRoom_PlayerEnter
	waitmovement 1
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 11, 14
	waitstate
	end


TitleMatch_Text_TitleMatchVictory::
	.string "A Disputa pelo Titulo terminou!\n"
	.string "{PLAYER} venceu a partida!$"

TitleMatch_Text_TitleMatchDefeated::
	.string "A Disputa pelo Titulo terminou!\n"
	.string "{PLAYER} foi derrotado!\p"
	.string "Kanto tem um novo Campeao!$"

TitleMatch_Steph::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_STEPH, TitleMatch_Text_StephIntro, TitleMatch_Text_StephDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_StephIntro::
	.string "Estou pronta!$"

TitleMatch_Text_StephDefeated::
	.string "Tudo bem, estou caindo fora.$"

TitleMatch_Liz::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_LIZ, TitleMatch_Text_LizIntro, TitleMatch_Text_LizDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_LizIntro::
	.string "Eu sou um genio.$"

TitleMatch_Text_LizDefeated::
	.string "Ah, nao!$"

TitleMatch_Mike::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MIKE, TitleMatch_Text_MikeIntro, TitleMatch_Text_MikeDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MikeIntro::
	.string "Meu rival e o Chris.$"

TitleMatch_Text_MikeDefeated::
	.string "Nao ligo se voce vencer, contanto\n"
	.string "que ele perca.$"

TitleMatch_Chris::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_CHRIS, TitleMatch_Text_ChrisIntro, TitleMatch_Text_ChrisDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_ChrisIntro::
	.string "Nao e hora de brincadeiras!$"

TitleMatch_Text_ChrisDefeated::
	.string "Medroso demais!$"

TitleMatch_Kev::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_KEV, TitleMatch_Text_KevIntro, TitleMatch_Text_KevDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_KevIntro::
	.string "Eu tenho o poder dos Pokémon\n"
	.string "do meu lado!$"

TitleMatch_Text_KevDefeated::
	.string "Nao! Eu deveria ter usado todo\n"
	.string "o meu poder!$"

TitleMatch_Meghan::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MEGHAN, TitleMatch_Text_MeghanIntro, TitleMatch_Text_MeghanDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MeghanIntro::
	.string "Nao e mais possivel se desconectar.$"

TitleMatch_Text_MeghanDefeated::
	.string "Cai fora daqui!$"

TitleMatch_Steve::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_STEVE, TitleMatch_Text_SteveIntro, TitleMatch_Text_SteveDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SteveIntro::
	.string "Pokémon e tudo uma questao de poder.$"

TitleMatch_Text_SteveDefeated::
	.string "Hoje nao foi o meu dia.$"

TitleMatch_M::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_M, TitleMatch_Text_MIntro, TitleMatch_Text_MDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MIntro::
	.string "Este e o meu pantano!$"

TitleMatch_Text_MDefeated::
	.string "Me deixe em paz!$"

TitleMatch_Bean::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BEAN, TitleMatch_Text_BeanIntro, TitleMatch_Text_BeanDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BeanIntro::
	.string "Eu nao tolero valentoes.$"

TitleMatch_Text_BeanDefeated::
	.string "Voce e forte! Eu gosto disso!$"

TitleMatch_Annie::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ANNIE, TitleMatch_Text_AnnieIntro, TitleMatch_Text_AnnieDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_AnnieIntro::
	.string "Peguei os Pokémon da minha mae emprestados.$"

TitleMatch_Text_AnnieDefeated::
	.string "Buaaaaa! Eu quero a minha mae!$"

TitleMatch_Brock::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BROCK, TitleMatch_Text_BrockIntro, TitleMatch_Text_BrockDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BrockIntro::
	.string "Brock: Estou pegando fogo!$"

TitleMatch_Text_BrockDefeated::
	.string "Voce percorreu um longo caminho, {PLAYER}.$"

TitleMatch_Misty::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MISTY, TitleMatch_Text_MistyIntro, TitleMatch_Text_MistyDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MistyIntro::
	.string "Misty: Ei, e voce!\p"
	.string "Essa defesa de titulo vai ser\n"
	.string "facil entao.$"

TitleMatch_Text_MistyDefeated::
	.string "Eca! Nao acredito que perdi\n"
	.string "para voce de novo!$"

TitleMatch_Surge::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_SURGE, TitleMatch_Text_SurgeIntro, TitleMatch_Text_SurgeDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SurgeIntro::
	.string "Surge: A vida e uma guerra, garoto.\p"
	.string "Este e so mais um campo de batalha.$"

TitleMatch_Text_SurgeDefeated::
	.string "De volta ao treinamento basico!$"

TitleMatch_Erika::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ERIKA, TitleMatch_Text_ErikaIntro, TitleMatch_Text_ErikaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_ErikaIntro::
	.string "Erika: Ola, {PLAYER}.\p"
	.string "Vamos batalhar novamente?$"

TitleMatch_Text_ErikaDefeated::
	.string "Parece que perdi de novo...$"

TitleMatch_Sabrina::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_SABRINA, TitleMatch_Text_SabrinaIntro, TitleMatch_Text_SabrinaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SabrinaIntro::
	.string "Sabrina: Eu ja previa esta batalha.$"

TitleMatch_Text_SabrinaDefeated::
	.string "Eu sabia que terminaria assim...$"

TitleMatch_Koga::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_KOGA, TitleMatch_Text_KogaIntro, TitleMatch_Text_KogaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_KogaIntro::
	.string "Koga: Decidi dar o proximo passo\n"
	.string "e entrar para a Elite dos Quatro.\p"
	.string "Voce e meu unico obstaculo!$"

TitleMatch_Text_KogaDefeated::
	.string "Ainda não sou digno...$"

TitleMatch_Blaine::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BLAINE, TitleMatch_Text_BlaineIntro, TitleMatch_Text_BlaineDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BlaineIntro::
	.string "Blaine: Voce acendeu a minha chama!$"

TitleMatch_Text_BlaineDefeated::
	.string "Nao quente o suficiente!$"

TitleMatch_Rocket::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ROCKET, TitleMatch_Text_RocketIntro, TitleMatch_Text_RocketDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_RocketIntro::
	.string "Nos lutamos la na Silph Co.\p"
	.string "Estou tentando andar na linha.\n"
	.string "Voce me inspirou a tentar ser\l"
	.string "um treinador de verdade.$"

TitleMatch_Text_RocketDefeated::
	.string "Eu nao merecia vencer depois de\n"
	.string "todas as coisas terriveis que fiz.$"

TitleMatch_Daisy::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_DAISY, TitleMatch_Text_DaisyIntro, TitleMatch_Text_DaisyDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_DaisyIntro::
	.string "Daisy: Oi, {PLAYER}!\p"
	.string "Voce e meu irmao estavam sempre falando\n"
	.string "sobre batalhas, entao decidi tentar.\p"
	.string "Acho que ate sou muito boa nisso!$"

TitleMatch_Text_DaisyDefeated::
	.string "Isso foi divertido!$"

TitleMatch_Rival::
	goto_if_eq VAR_RIVAL_WINRATE, 2, TitleMatch_Rival_Jolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, TitleMatch_Rival_Flareon
	goto TitleMatch_Rival_Vaporeon

TitleMatch_Rival_Jolteon::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_JOLTEON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Rival_Flareon::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_FLAREON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Rival_Vaporeon::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_VAPOREON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_RivalIntro::
	.string "{RIVAL}: Muito bem, nos encontramos de novo!\p"
	.string "Agora e a minha chance de provar que\n"
	.string "sou o verdadeiro campeao!$"

TitleMatch_Text_RivalDefeated::
	.string "Heh, ainda nao dou conta de voce.$"
