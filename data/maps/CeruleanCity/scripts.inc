.set LOCALID_JENNY, 5
.set LOCALID_SLOWBRO, 9
.set LOCALID_LASS, 4
.set LOCALID_RIVAL, 10
.set LOCALID_TMBALL, 12
.set LOCALID_GRUNT, 6
.set LOCALID_BULBASAUR, 14
.set LOCALID_BREEDER, 13

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCity_OnResume
	.byte 0

CeruleanCity_OnTransition:
	setflag FLAG_VISITED_CERULEAN_CITY
	call_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_EventScript_ClearCeruleanCaveGuard
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	call_if_set FLAG_GOT_BULBASAUR,  CeruleanCity_EventScript_MoveBreederInside
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_EventScript_ClearCeruleanCaveGuard::
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	return

CeruleanCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_JENNY, 30, 12
	setobjectxyperm LOCALID_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_LASS, 27, 31
	return

CeruleanCity_EventScript_MoveBreederInside::
	clearflag FLAG_HIDE_CERULEAN_BREEDER
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_Text_CitySign::
    .string "Cerulean City\n"
    .string "Uma Misteriosa Aura Azulada a Envolve.$"

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_Text_TrainerTipsHeldItems::
    .string "Dicas para Treinadores:\p"
    .string "Um Pokémon pode segurar um item.\p"
    .string "Alguns itens podem até ser usados pelo\n"
    .string "Pokémon segurador durante a batalha.$"

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_Text_BikeShopSign::
    .string "Gramados e cavernas fáceis de encarar!\n"
    .string "Loja de Bicicletas$"

CeruleanCity_EventScript_GymSign::
	lockall
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Text_GymSign::
    .string "Ginásio Pokémon de Cerulean City\n"
    .string "Líder: Misty\l"
    .string "A Sereia Moleca!$"

CeruleanCity_EventScript_Police::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_JENNY, DIR_SOUTH
	release
	end

CeruleanCity_Text_PeopleHereWereRobbed::
    .string "As pessoas daqui foram assaltadas.\p"
    .string "É óbvio que a Equipe Rocket está por trás\n"
    .string "desse crime hediondo!\p"
    .string "Nossa força policial está tendo problemas\n"
    .string "com os Rockets, então pedimos ajuda à\l"
    .string "Polícia Internacional!$"

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
    .string "Se aquele Slowbro não estivesse ali, daria\n"
    .string "para Cortar a pequena árvore.\p"
    .string "Assim, daria para passar para o outro lado.\p"
    .string "Mas acho que tem outro caminho para dar a\n"
    .string "volta.$"

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_YouCanCutDownSmallTrees::
    .string "Você sabia que pode Cortar árvores\n"
    .string "pequenas?\p"
    .string "Até mesmo aquela arvorezinha em frente à\n"
    .string "loja pode ser Cortada.\p"
    .string "Mas acho que tem outro caminho para dar a\n"
    .string "volta.$"

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_Text_PokemonEncyclopediaAmusing::
    .string "Você está criando uma enciclopédia sobre\n"
    .string "Pokémon? Parece divertido.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
    .string "Você também é um Treinador?\p"
    .string "Colecionar, batalhar…\n"
    .string "É uma vida dura, não é?$"

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	turnobject LOCALID_WOMAN, DIR_NORTH
	release
	end

CeruleanCity_Text_WantBrightRedBicycle::
    .string "Eu quero uma bicicleta vermelho-brilhante.\p"
    .string "Vou guardá-la em casa, assim ela nunca vai\n"
    .string "se sujar.$"

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "Esta é a Cerulean Cave.\p"
    .string "Pokémon extremamente fortes vivem lá\n"
    .string "dentro.\p"
    .string "É preciso ser um Treinador muito especial\n"
    .string "para ter permissão de entrar lá.\p"
    .string "Quão forte?\n"
    .string "Hmm....\p"
    .string "Eu diria que apenas quem se tornar o\n"
    .string "Campeão da Liga Pokémon conseguiria dar\l"
    .string "conta.$"

CeruleanCity_EventScript_Lass::
	lock
	random 3
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_SlowbroLass1
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_SlowbroLass2
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_SlowbroLass3
	end

CeruleanCity_Slowbro::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 40
	playse SE_PIN
	applymovement LOCALID_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 9
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

CeruleanCity_EventScript_SlowbroLass1::
	msgbox CeruleanCity_Text_SlowbroUseSonicboom, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_SlowbroPayAttention, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroUseSonicboom::
    .string "Muito bem! Slowbro!\n"
    .string "Use o Boom Sônico!$"

CeruleanCity_Text_SlowbroPayAttention::
    .string "Qual é, Slowbro, preste atenção!$"

CeruleanCity_EventScript_SlowbroLass2::
	msgbox CeruleanCity_Text_SlowbroPunch, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_NoYouBlewItAgain, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroPunch::
    .string "Slowbro, dê um soco!$"

CeruleanCity_Text_NoYouBlewItAgain::
    .string "Não!\n"
    .string "Você errou de novo!$"

CeruleanCity_EventScript_SlowbroLass3::
	msgbox CeruleanCity_Text_SlowbroWithdraw, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_HardToControlMonsObedience, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroWithdraw::
    .string "Slowbro, ENCOLHER!$"

CeruleanCity_Text_HardToControlMonsObedience::
    .string "Não! Está tudo errado!\n"
    .string "É tão difícil controlar Pokémon!\p"
    .string "A obediência do seu Pokémon depende das\n"
    .string "suas habilidades como treinador.$"

CeruleanCity_EventScript_Slowbro::
	lock
	random 4 
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_Slowbro1
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_Slowbro2
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_Slowbro3
	goto_if_eq VAR_RESULT, 3, CeruleanCity_EventScript_Slowbro4
	end

CeruleanCity_EventScript_Slowbro1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroTookSnooze::
    .string "Slowbro tirou uma soneca…$"

CeruleanCity_EventScript_Slowbro2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroLoafingAround::
    .string "Slowbro está vadiando por aí…$"

CeruleanCity_EventScript_Slowbro3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroTurnedAway::
    .string "Slowbro virou a cara…$"

CeruleanCity_EventScript_Slowbro4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroIgnoredOrders::
    .string "Slowbro ignorou as ordens…$"

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	setvar VAR_ROUTE_22_RIVAL_STATE, 3
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	clearflag FLAG_HIDE_CERULEAN_RIVAL
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 10
	msgbox CeruleanCity_Text_RivalAppears, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_RIVAL_CERULEAN_CITY, CeruleanCity_Text_RivalIntro, CeruleanCity_Text_RivalDefeat, CeruleanCity_EventScript_RivalDefeated, NO_MUSIC
	end

CeruleanCity_EventScript_RivalDefeated::
	msgbox CeruleanCity_Text_RivalPostBattle, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor, MSGBOX_DEFAULT
	setvar VAR_RIVAL_CERULEAN_CITY, 1
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox CeruleanCity_Text_ObtainedPokeblockCase, MSGBOX_DEFAULT
	additem ITEM_POKEBLOCK_CASE
	waitfanfare
	msgbox CeruleanCity_Text_ExplainPokeblockSmellYa, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 10
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_Text_RivalAppears::
    .string "{RIVAL}: E aí, {PLAYER}!\p"
    .string "Você ainda está patinando aqui\n"
    .string "atrás?\p"
    .string "Eu estou indo super bem! Capturei um monte\n"
    .string "de Pokémon fortes e espertos!$"

CeruleanCity_Text_RivalIntro::
    .string "Deixa eu ver o que você capturou,\n"
    .string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
    .string "Ei!\n"
    .string "Pega leve!\l"
    .string "Você já ganhou!$"

CeruleanCity_Text_RivalPostBattle::
    .string "{RIVAL}: Ei, adivinha só!\p"
    .string "Eu fui até a casa do Bill e pedi para ele\n"
    .string "me mostrar a sua mais nova invenção.\p"
    .string "Isso vai me ajudar a adicionar muitas\n" 
    .string "páginas à minha Pokédex!\p"
    .string "Afinal, o Bill é famoso no mundo todo como\n"
    .string "um PokéManíaco.\p"
    .string "Ele inventou o Sistema de Armazenamento de\n"
    .string "Pokémon no PC também.\p"
    .string "Já que você usa o sistema dele,\n"
    .string "deveria ir lá agradecer.\p"
    .string "Bom, é melhor eu dar no pé!\n"
    .string "Até mais, perdedor!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
    .string "Ah, é verdade.\p"
    .string "Minha irmã me mandou um presente, mas ela\n"
    .string "acidentalmente colocou dois desses na caixa.\p"
    .string "Eu não preciso dos dois, então pode ficar\n"
    .string "com um.\p"
    .string "Sério mesmo.\p"
    .string "Vou te dar como um favor, já que você vive\n"
    .string "se arrastando atrás de mim.$"

CeruleanCity_Text_ObtainedPokeblockCase::
	.string "Você obteve o Porta-Pokéblocos!\p"
	.string "{PLAYER} guardou o Porta-Pokéblocos\n"
	.string "no bolso de Itens Chave.$"

CeruleanCity_Text_ExplainPokeblockSmellYa::
    .string "Para um fracote como você…\n"
    .string "Essa coisa é perfeita.\p"
    .string "Eu não preciso disso porque não dou a mínima\n"
    .string "para Concursos Pokémon.\p"
    .string "Beleza, dessa vez eu fui de verdade.\n"
    .string "Fui!$"

CeruleanCity_EventScript_RivalStartExit::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 10
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 10
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntIntro, CeruleanCity_Text_GruntDefeat, CeruleanCity_EventScript_GruntDefeated
	releaseall
	end

CeruleanCity_Text_GruntIntro::
    .string "Ei! Fique longe!\n"
    .string "Esse quintal não é seu!\p"
    .string "…Hã?\n"
    .string "Eu?\p"
    .string "Sou apenas um cidadão inocente!\n"
    .string "Não acredita em mim?$"

CeruleanCity_Text_GruntDefeat::
    .string "Recruta: Pare! Eu desisto!\n"
    .string "Vou sair de fininho!$"

CeruleanCity_EventScript_GruntDefeated::
	setvar VAR_CERULEAN_CITY_ROCKETS, 2
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_CERULEAN_ROCKET
	removeobject LOCALID_GRUNT
	clearflag FLAG_HIDE_CERULEAN_TM28
	addobject LOCALID_TMBALL
	playse SE_FLEE
	waitse
	fadescreen FADE_FROM_BLACK
	release
	return

CeruleanCity_Text_OkayIllReturnStolenTM::
    .string "…Está bem! Tome aqui!\p"
    .string "Eu não vou para a cadeia por\n"
    .string "causa de um mísero TM!$"

CeruleanCity_EventScript_StolenTM::
	lock
	checkitemspace ITEM_TM28, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	setflag FLAG_HIDE_CERULEAN_TM28
	removeobject LOCALID_TMBALL
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeruleanCity_Text_RecoveredStolenTM, MSGBOX_DEFAULT
	additem ITEM_TM28, 1
	setflag FLAG_RECOVERED_STOLEN_TM
	release
	end

CeruleanCity_Text_RecoveredStolenTM::
	.string "{PLAYER} recuperou o TM28\n"
	.string "roubado!$"

CeruleanCity_EventScript_NoRoomForTM28::
	msgbox CeruleanCity_Text_MakeRoomForThis, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_MakeRoomForThis::
	.string "Você não tem espaço suficiente.\n"
	.string "É melhor liberar espaço na mochila!$"

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_Grunt
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_Grunt
	end

CeruleanCity_EventScript_Bulbasaur::
	lock
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, CeruleanCity_EventScript_BulbasaurHappy
	turnobject LOCALID_BULBASAUR, DIR_NORTH
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Bulbasaur, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Bulbasaur:
	.string "Bulbasaur: ...grrr...$"

CeruleanCity_EventScript_BulbasaurHappy::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	playse SE_PIN
	applymovement LOCALID_BULBASAUR, Common_Movement_Heart
	waitmovement 14
	delay 8
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

CeruleanCity_EventScript_BulbasaurBreeder::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BULBASAUR, CeruleanCity_EventScript_ProudOfBulbasaur
	msgbox CeruleanCity_Text_BulbasaurDoesntTrustPeople, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, 4, CeruleanCity_EventScript_BulbasaurStillNeedsTime
	call_if_eq VAR_FACING, DIR_NORTH, CeruleanCity_EventScript_BulbasaurApproachPlayerNear
	call_if_eq VAR_FACING, DIR_WEST, CeruleanCity_EventScript_BulbasaurApproachPlayerFar
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	playse SE_PIN
	applymovement LOCALID_BULBASAUR, Common_Movement_Heart
	waitmovement 14
	delay 8
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	turnobject LOCALID_BREEDER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_BREEDER, Common_Movement_ExclamationMark
	waitse
	waitmovement 13
	faceplayer
	msgbox CeruleanCity_Text_BulbasaurTrustsYou, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	random 128
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, 1, CeruleanCity_EventScript_BulbasaurBreederLucky
    setvar VAR_0x8004, 0
	givemon SPECIES_BULBASAUR, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_BulbasaurParty
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_BulbasaurPC
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_NoRoomForBulbasaur
	end

CeruleanCity_EventScript_BulbasaurBreederLucky::
	setvar VAR_0x8004, 0
    setflag FLAG_SHINY_CREATION
	givemon SPECIES_BULBASAUR, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_BulbasaurParty
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_BulbasaurPC
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_NoRoomForBulbasaur
	end

CeruleanCity_EventScript_BulbasaurApproachPlayerNear::
	applymovement LOCALID_BULBASAUR, Movement_BulbaNear
	waitmovement 14
	return

Movement_BulbaNear:
 	walk_down
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	delay_16
 	step_end

CeruleanCity_EventScript_BulbasaurApproachPlayerFar::
	applymovement LOCALID_BULBASAUR,  Movement_BulbaFar
	waitmovement 14
	return

Movement_BulbaFar:
 	walk_down
 	walk_right
 	walk_right
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	delay_16
 	step_end

CeruleanCity_EventScript_BulbasaurParty::
	call CeruleanCity_EventScript_GetBulbasaur
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_GotBulbasaur
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CeruleanCity_EventScript_GotBulbasaur
	end

CeruleanCity_EventScript_GetBulbasaur::
	playfanfare MUS_LEVEL_UP
	message CeruleanCity_EventScript_Text_BefriendedBulbasaur
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	return

CeruleanCity_EventScript_Text_BefriendedBulbasaur::
	.string "{PLAYER} fez amizade com o Bulbasaur!$"

CeruleanCity_EventScript_GotBulbasaur::
	setflag FLAG_GOT_BULBASAUR
	removeobject LOCALID_BULBASAUR
	release
	end

CeruleanCity_EventScript_BulbasaurPC::
	call CeruleanCity_EventScript_GetBulbasaur
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_TransferBulbasaur
	call Common_EventScript_NameReceivedBoxMon
	goto CeruleanCity_EventScript_TransferBulbasaur
	end

CeruleanCity_EventScript_TransferBulbasaur::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	call Common_EventScript_TransferredToPC
	goto CeruleanCity_EventScript_GotBulbasaur
	end

CeruleanCity_EventScript_NoRoomForBulbasaur::
	msgbox CeruleanCity_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_NoRoomForMorePokemon::
    .string "Oh! Você não tem espaço para\n"
    .string "mais nenhum Pokémon!$"

CeruleanCity_Text_BulbasaurDoesntTrustPeople::
	.string "Este Bulbasaur se machucou tentando\n"
	.string "impedir a Equipe Rocket de raptar\l"
	.string "outros Pokémon...\p"
	.string "Estou tentando fazer com que ele confie\n"
	.string "nas pessoas novamente.$"

CeruleanCity_Text_BulbasaurTrustsYou::
	.string "Incrível! Maravilhoso!\p"
	.string "Este Bulbasaur confia em você!\p"
	.string "Ele abriu o coração para as pessoas de\n"
	.string "novo...\p"
	.string "Acho que ele quer ir com você.\p"
	.string "Tudo bem! Eu também confio em você!\p"
	.string "Por favor, cuide muito bem dele!$"

CeruleanCity_EventScript_BulbasaurStillNeedsTime::
	turnobject LOCALID_BREEDER, DIR_WEST
	msgbox CeruleanCity_Text_BulbasaurNeedsTime, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_BulbasaurNeedsTime::
	.string "Ele ainda precisa de um tempo, porém.\p"
	.string "Não o culpo por guardar rancor. O que\n"
	.string "a Equipe Rocket fez é imperdoável!$"

CeruleanCity_EventScript_ProudOfBulbasaur::
	msgbox CeruleanCity_Text_ProudOfBulbasaur, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_ProudOfBulbasaur::
	.string "Estou muito orgulhosa do Bulbasaur.\p"
	.string "É preciso muita coragem para confiar\n"
	.string "nos outros novamente.$"

CeruleanCity_EventScript_BillCallsPlayer::
	lockall
	pokenavcall CeruleanCity_Text_DexNavCall
	waitmessage
	setvar VAR_SEA_COTTAGE_STATE, 5
	releaseall
	end

CeruleanCity_Text_DexNavCall::
	.string "???: Alô, é o {PLAYER}?\p"
	.string "Bill: Sim, é o Bill!\p"
	.string "Tive que mandar um e-mail pro\n"
	.string "Prof. Carvalho para pegar o seu número,\l"
	.string "espero que não se importe!\p"
	.string "Meu cérebro devia estar meio bagunçado\n"
	.string "do teletransportador depois que você me\l"
	.string "salvou — esqueci completamente de te\l"
	.string "mostrar uma coisa!\p"
	.string "Volte à Casa do Mar qualquer hora que\n"
	.string "eu te mostro!$"

CeruleanCity_EventScript_Venusaurite::
	finditem ITEM_VENUSAURITE, 1
	setflag FLAG_GOT_VENUSAURITE
	goto_if_unset FLAG_FIRST_MEGASTONE, CeruleanCity_EventScript_FoundMegaStone
    end

CeruleanCity_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
