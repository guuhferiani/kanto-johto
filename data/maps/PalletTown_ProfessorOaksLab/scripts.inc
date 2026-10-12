.set LOCALID_OAK, 1
.set LOCALID_RIVAL, 2
.set LOCALID_POKEBALL, 3
.set LOCALID_POKEDEX_L, 7
.set LOCALID_POKEDEX_R, 8
.set LOCALID_PIKACHU, 9

@OAK LAB STATES:
@ 0: Player hasn't met Oak yet
@ 1: Player met Oak and warped back to lab
@ 2: Oak gave intro speech
@ 3: Rival grabbed Eevee
@ 4: Triggered Rival Battle
@ 5: Returned from Rival Battle
@ 6: Collected Oak's Parcel
@ 7: Received Pokedex
@ 8: Left Lab after getting Pokedex
@ 9: Registered Oak in Cell Phone

PalletTown_ProfessorOaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, PalletTown_ProfessorOaksLab_OnReturnToField
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
	.byte 0

PalletTown_ProfessorOaksLab_OnReturnToField:
	call_if_eq VAR_OAK_LAB_STATE, 4, PalletTown_ProfessorOaksLab_EventScript_HealAfterFirstBattle
	end

PalletTown_ProfessorOaksLab_EventScript_HealAfterFirstBattle::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	setvar VAR_OAK_LAB_STATE, 5
	end

PalletTown_ProfessorOaksLab_OnWarp:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene
	map_script_2 VAR_OAK_LAB_STATE, 6, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForPokedexScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_RIVAL, DIR_NORTH
	end

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForPokedexScene::
	setobjectxyperm LOCALID_RIVAL, 6, 11
	setobjectmovementtype LOCALID_OAK, MOVEMENT_TYPE_FACE_UP
	savebgm MUS_RG_OAK
	end

PalletTown_ProfessorOaksLab_OnFrame:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_GetStarterScene
	map_script_2 VAR_OAK_LAB_STATE, 6, PalletTown_ProfessorOaksLab_EventScript_GetPokedexScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_GetStarterScene::
	lockall
	msgbox PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_OAK, Common_Movement_QuestionMark
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_TakeStarter, MSGBOX_DEFAULT
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe, MSGBOX_DEFAULT
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival, MSGBOX_DEFAULT
	setvar VAR_OAK_LAB_STATE, 2
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting:
    .string "{RIVAL}: Vovô!\n"
    .string "Eu cansei de esperar!$"

PalletTown_ProfessorOaksLab_Text_TakeStarter::
    .string "Carvalho: {RIVAL}?\n"
    .string "Deixe-me ver...\p"
    .string "Ah, é verdade, eu disse para você\n"
    .string "vir! Apenas espere!\p"
    .string "Aqui, {PLAYER}.\p"
    .string "Tem uma Pokébola na minha mesa.\p"
    .string "Quando eu era jovem, fui um treinador\n"
    .string "Pokémon dedicado.\p"
    .string "Mas agora, na velhice, estudo Pokémon\n"
    .string "mais do que batalho.\p"
    .string "Gostaria que você cuidasse deste\n"
    .string "Pokémon por mim!$"

PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe::
    .string "{RIVAL}: Ei! Vovô! Não vale!\n"
    .string "E quanto a mim?$"

PalletTown_ProfessorOaksLab_Text_OakBePatientRival::
    .string "Carvalho: Tenha paciência, {RIVAL}.\p"
    .string "Eu levarei você para capturar seu\n"
    .string "próprio Pokémon mais tarde.$"

PalletTown_ProfessorOaksLab_EventScript_ApproachPokeBallBehindDesk::
	lockall
	turnobject LOCALID_RIVAL, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_RivalMoveToDesk2
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_StealEeveeTooSlow
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PalletTown_ProfessorOaksLab_Text_TooSlow, MSGBOX_DEFAULT
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	msgbox PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerReturnToOakFar
	waitmovement 0
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu
	releaseall
	end

Movement_RivalMoveToDesk2::
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Movement_StealEeveeTooSlow::
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	delay_16
	delay_16
	delay_16
	step_end

PalletTown_ProfessorOaksLab_Text_TooSlow::
	.string "{RIVAL}: Lento demais, {PLAYER}!\p"
	.string "Isso é o que dá dar a volta\n"
	.string "pelo caminho mais longo.$"

Movement_PlayerReturnToOakFar::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	face_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_RivalStealEevee::
	lockall
	turnobject LOCALID_RIVAL, DIR_EAST
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_RivalMoveToDesk
	waitmovement 2
	playse SE_WALL_HIT
	applymovement LOCALID_RIVAL, Movement_PushPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Movement_GetPushed
	waitse
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_TakeEevee
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	msgbox PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerReturnToOak
	waitmovement 0
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu
	releaseall
	end

Movement_RivalMoveToDesk::
	walk_right
	walk_right
	walk_right
	step_end

Movement_PushPlayer::
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Movement_GetPushed::
	walk_right
	face_left
	step_end

Movement_TakeEevee::
	walk_right
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	delay_16
	step_end

Movement_PlayerReturnToOak::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne::
	.string "Carvalho: {RIVAL}!\p"
	.string "Ai, ai... tudo bem.\n"
	.string "Aquele Pokémon é seu.\p"
	.string "{PLAYER}, venha até aqui.$"

PalletTown_ProfessorOaksLab_EventScript_PreventExit::
	applymovement LOCALID_OAK, Movement_OakStopPlayer
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_QuestionMark
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_DontWantAPokemon, MSGBOX_DEFAULT
	applymovement LOCALID_OAK, Movement_OakReturnToPosition
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CantExitLab
	waitmovement 0
	release
	end

Movement_OakStopPlayer::
	walk_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_8
	step_end

Movement_OakReturnToPosition::
	walk_up
	face_down
	step_end

PalletTown_ProfessorOaksLab_Text_DontWantAPokemon::
	.string "Carvalho: Você não quer um\n"
	.string "Pokémon, {PLAYER}?$"

Movement_CantExitLab::
	walk_up
	face_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu::
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuFromEarlier, MSGBOX_DEFAULT
	playse SE_BALL_OPEN
	clearflag FLAG_HIDE_OAK_LAB_PIKACHU
	addobject LOCALID_PIKACHU
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	turnobject LOCALID_OAK, DIR_WEST
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow, MSGBOX_DEFAULT
	applymovement LOCALID_PIKACHU, Movement_PikachuJoinsParty
	waitmovement 9
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_PIKACHU, Common_Movement_Heart
	waitmovement 9
	waitse
	givemon SPECIES_PIKACHU_PARTNER, 5
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuJoinedTeam, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	msgbox PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty
	end

Movement_PikachuJoinsParty::
	walk_down
	face_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	step_end

PalletTown_ProfessorOaksLab_Text_PikachuFromEarlier:
	.string "Carvalho: Tecnicamente, aquele não\n"
	.string "era meu último Pokémon.\p"
	.string "Eu ainda tenho o Pikachu que\n"
	.string "capturei mais cedo...\p"
	.string "Eu ia devolvê-lo ao seu habitat\n"
	.string "natural, mas talvez seja melhor\l"
	.string "você ficar com ele.$"
	
PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree:
	.string "Carvalho: Incrível!\p"
	.string "Ele escapou da Pokébola!$"

PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow:
	.string "Carvalho: Ele parece ter gostado\n"
	.string "muito de você, {PLAYER}.\p"
	.string "Parece que o Pikachu já tomou\n"
	.string "a decisão dele!\p"
	.string "Você sem dúvida deve ficar com\n"
	.string "este Pokémon.$"

PalletTown_ProfessorOaksLab_Text_PikachuJoinedTeam:
	.string "Pikachu decidiu ficar ao lado\n"
	.string "de {PLAYER}!$"

PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon:
	.string "Carvalho: Diga, por que não dá um\n"
	.string "apelido ao seu novo parceiro?$"

PalletTown_ProfessorOaksLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty
	end

PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty::
	removeobject LOCALID_PIKACHU
	setflag FLAG_HIDE_OAK_LAB_PIKACHU
	callnative UpdateFollowingPokemon
	setvar VAR_OAK_LAB_STATE, 3
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger3::
	setvar VAR_TEMP_1, 3
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle::
	lockall
	setvar VAR_OAK_LAB_STATE, 4
	turnobject LOCALID_RIVAL, DIR_SOUTH
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproach3
	waitmovement 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TRAINER_RIVAL_FIRST_BATTLE,PalletTown_ProfessorOaksLab_Text_RivalBattleIntro,PalletTown_ProfessorOaksLab_Text_RivalDefeated,PalletTown_ProfessorOaksLab_EventScript_RivalBattleOutcome
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons::
    .string "{RIVAL}: Espere, {PLAYER}!$"

PalletTown_ProfessorOaksLab_Text_RivalBattleIntro::
    .string "Vamos testar nossos Pokémon!\p"
    .string "Venha, vou te mostrar do que sou capaz!$"

PalletTown_ProfessorOaksLab_Text_RivalDefeated::
    .string "{RIVAL}: O QUÊ?\n"
    .string "Inacreditável!\l"
    .string "Eu escolhi o Pokémon errado!$"

PalletTown_ProfessorOaksLab_EventScript_RivalBattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PalletTown_ProfessorOaksLab_EventScript_RivalBattleWon
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleLost
	end

PalletTown_ProfessorOaksLab_EventScript_RivalBattleLost::
	msgbox PalletTown_ProfessorOaksLab_Text_RivalVictory, MSGBOX_DEFAULT
	goto PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle
	end

PalletTown_ProfessorOaksLab_Text_RivalVictory::
    .string "{RIVAL}: É isso aí!\n"
    .string "Eu sou um gênio ou não sou?$"

PalletTown_ProfessorOaksLab_EventScript_RivalBattleWon::
	addvar VAR_RIVAL_WINRATE, 1
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon, MSGBOX_DEFAULT
	goto PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle
	end

PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon::
    .string "{RIVAL}: Beleza! Vou treinar meu Pokémon\n"
    .string "em muitas batalhas para deixá-lo forte!\p"
    .string "{PLAYER}! Vovô!\n"
    .string "Até mais ver!$"

PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle::
	closemessage
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle3
	playbgm MUS_RG_RIVAL_EXIT, 0
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RIVAL_IN_LAB
	setvar VAR_ADVENTURE_BEGINS, 3
	fadedefaultbgm
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalApproach1::
	applymovement LOCALID_RIVAL, Movement_RivalApproach1
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach2::
	applymovement LOCALID_RIVAL, Movement_RivalApproach2
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach3::
	applymovement LOCALID_RIVAL, Movement_RivalApproach3
	return

Movement_RivalApproach1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_RivalApproach2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_RivalApproach3:
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle1::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle1
	return

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle2::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle2
	return

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle3::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle3
	return

Movement_RivalLeavesAfterBattle1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_RivalLeavesAfterBattle2:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

Movement_RivalLeavesAfterBattle3:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_GetPokedexScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachOak
	waitmovement 0
	turnobject LOCALID_OAK, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_TMHM
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
	waitmessage
	waitfanfare
	removeitem ITEM_OAKS_PARCEL, 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
	addobject LOCALID_RIVAL
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_RIVAL, Movement_RivalReturnsToLab
	waitmovement 2
	fadedefaultbgm
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
	closemessage
	delay 30
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
	closemessage
	applymovement LOCALID_OAK, Movement_OakGoToPokedex1
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
	closemessage
	delay 40
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
	closemessage
	applymovement LOCALID_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	removeobject LOCALID_POKEDEX_L
	delay 10
	applymovement LOCALID_OAK, Movement_OakGoToPokedex2
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	removeobject LOCALID_POKEDEX_R
	setflag FLAG_HIDE_POKEDEX_ON_TABLE
	delay 10
	applymovement LOCALID_OAK, Movement_OakReturnToPlayer
	waitmovement 1
	delay 10
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
	giveitem ITEM_POKE_BALL, 5
	@PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls 
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
	turnobject LOCALID_RIVAL, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouNumber
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, Movement_RivalLeavesWithPokedex
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	fadedefaultbgm
	setflag FLAG_HIDE_OFFICER_JENNY_VIRIDIAN_CITY
	setvar VAR_OAK_LAB_STATE, 7
	setvar VAR_ADVENTURE_BEGINS, 6
	setvar VAR_ROUTE_22_RIVAL_STATE, 1
	releaseall
	end

Movement_PlayerApproachOak:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_RivalReturnsToLab:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	face_up
	step_end

Movement_OakGoToPokedex1:
	walk_up
	walk_left
	walk_left
	face_up
	step_end

Movement_OakGoToPokedex2:
	walk_right
	face_up
	step_end

Movement_OakReturnToPlayer:
	walk_right
	walk_down
	step_end

Movement_RivalLeavesWithPokedex:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe::
    .string "Carvalho: Oh, {PLAYER}!\n"
    .string "Como vai o seu novo Pokémon?\p"
    .string "Bem, parece que ele está cada vez mais\n"
    .string "apegado a você.\p"
    .string "Você deve ter um talento natural como\n"
    .string "treinador de Pokémon.\p"
    .string "O que é isso?\n"
    .string "Tem alguma coisa para mim?$"

PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel::
    .string "{PLAYER} entregou a Encomenda do Carvalho.$"

PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered::
    .string "Ah!\n"
    .string "É a Pokébola personalizada!\p"
    .string "Eu a havia encomendado.\n"
    .string "Muito obrigado!$"

PalletTown_ProfessorOaksLab_Text_RivalGramps::
    .string "{RIVAL}: Vovô!$"

PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor::
    .string "{RIVAL}: Quase esqueci!\n"
    .string "Por que me chamou aqui?$"

PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo::
    .string "Carvalho: Ah, sim!\n"
    .string "Tenho um pedido para vocês dois.$"

PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk::
    .string "Na mesa está a minha invenção,\n"
    .string "a Pokédex!\p"
    .string "Ela registra automaticamente os dados dos\n"
    .string "Pokémon que vocês viram ou capturaram.\p"
    .string "É uma enciclopédia de alta tecnologia!$"

PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou::
    .string "Carvalho: {PLAYER} e {RIVAL}.\n"
    .string "Levem isto com vocês.$"

PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak::
    .string "{PLAYER} recebeu a Pokédex\n"
    .string "do Professor Carvalho!$"

PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese::
    .string "Carvalho: Vocês não obtêm dados\n"
    .string "detalhados apenas ao vê-los.\p"
    .string "É necessário capturá-los para\n"
    .string "obter informações completas.\p"
    .string "Portanto, aqui estão algumas ferramentas\n"
    .string "para capturar Pokémon selvagens.$"

PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls::
    .string "{PLAYER} recebeu cinco Pokébolas.$"

PalletTown_ProfessorOaksLab_Text_OakExplainCatching::
    .string "Quando um Pokémon selvagem aparecer,\n"
    .string "é a sua chance.\p"
    .string "Basta arremessar uma Pokébola\n"
    .string "e tentar capturá-lo!\p"
    .string "Contudo, nem sempre isso vai dar certo.\p"
    .string "Um Pokémon saudável pode escapar.\n"
    .string "É preciso ter um pouco de sorte!\p"
	.string "Tente usar golpes que causem efeitos de\n"
	.string "status para aumentar suas chances.\p"
	.string "Durante uma batalha, a Pokédex pode ajudar\n"
	.string "a explicar a função e o efeito dos golpes\l"
	.string "ao pressionar o Botão R.$"

PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream::
    .string "Criar um guia completo com todos\n"
    .string "os Pokémon deste mundo...\p"
    .string "Esse sempre foi o meu grande sonho!\p"
    .string "Mas estou velho demais.\n"
    .string "Não consigo concluir essa tarefa.\p"
    .string "Por isso, quero que vocês dois realizem\n"
    .string "esse sonho por mim.\p"
    .string "Vão em frente, vocês dois.\p"
    .string "Este é um grande marco na história\n"
    .string "dos Pokémon!$"

PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps::
    .string "{RIVAL}: Pode deixar, Vovô!\n"
    .string "Deixa tudo comigo!$"

PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouNumber::
    .string "{PLAYER}, detesto admitir, mas você\n"
    .string "não vai fazer falta nenhuma nisso.\p"
    .string "A partir de agora é cada um por si,\n"
    .string "então nem perca tempo me ligando!\p"
    .string "E nem pense em pedir meu número para a\n"
    .string "minha irmã também.\p"
    .string "Vou dizer para ela não te passar nada,\n"
    .string "{PLAYER}! Hahaha!$"

PalletTown_ProfessorOaksLab_EventScript_Rival::
	goto_if_eq VAR_OAK_LAB_STATE, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWaiting
	goto_if_eq VAR_OAK_LAB_STATE, 2, PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy
	goto_if_eq VAR_OAK_LAB_STATE, 3, PalletTown_ProfessorOaksLab_EventScript_RivalMyMonLooksTough
	end

PalletTown_ProfessorOaksLab_EventScript_RivalWaiting::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround::
    .string "{RIVAL}: O quê, é só o {PLAYER}?\n"
    .string "O vovô não está aqui.$"

PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer, MSGBOX_DEFAULT
	release
	end 

PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer:
    .string "{RIVAL}: Heh, eu não preciso ser\n"
    .string "ganancioso como você. Sou maduro!\p"
    .string "Pode ir em frente e pegar, {PLAYER}!$"

PalletTown_ProfessorOaksLab_EventScript_RivalMyMonLooksTough::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher, MSGBOX_DEFAULT
	release
	end 

PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher::
    .string "{RIVAL}: O meu Pokémon parece bem mais\n"
    .string "forte que o seu, {PLAYER}.$"

PalletTown_ProfessorOaksLab_EventScript_Computer::
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_EmailMessage::
    .string "Há uma mensagem de e-mail aqui.\p"
    .string "...\p"
    .string "Finalmente!\n"
    .string "Os melhores treinadores da Liga Pokémon\l"
    .string "estão prontos para novos desafiantes!\p"
    .string "Traga seus melhores Pokémon e veja\n"
    .string "o seu nível como treinador!\p"
    .string "QG da Liga Pokémon\n"
    .string "Planalto Índigo\p"
    .string "Prof. Carvalho, venha nos visitar!\n"
    .string "...$"

PalletTown_ProfessorOaksLab_EventScript_LeftSign::
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu::
    .string "Pressione START para abrir o MENU!\p"
    .string "A opção SALVAR está no MENU.\n"
    .string "Use com frequência.$"

PalletTown_ProfessorOaksLab_EventScript_RightSign::
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints::
    .string "Todos os tipos de Pokémon possuem vantagens\n"
    .string "e desvantagens uns contra os outros.$"

PalletTown_ProfessorOaksLab_EventScript_Aide1::
	lock
	faceplayer
	goto_if_unset FLAG_REGISTERED_AIDE, PalletTown_ProfessorOaksLab_StudyAsOaksAide
	goto_if_unset FLAG_RECEIVED_HM05, PalletTown_ProfessorOaksLab_NOFlash
	goto_if_unset FLAG_RECEIVED_AIDE_EVERSTONE, PalletTown_ProfessorOaksLab_NOEverstone
	goto_if_unset FLAG_RECEIVED_ITEMFINDER, PalletTown_ProfessorOaksLab_NOItemfinder
	goto_if_unset FLAG_BADGE05_GET, PalletTown_ProfessorOaksLab_NoUpdateOnCedar1
	goto_if_unset FLAG_RECEIVED_AIDE_AMULET_COIN, PalletTown_ProfessorOaksLab_NOAmuletCoin
	goto_if_unset FLAG_BADGE06_GET, PalletTown_ProfessorOaksLab_NoUpdateOnCedar2
	goto_if_unset FLAG_RECEIVED_EXP_SHARE, PalletTown_ProfessorOaksLab_NOExpShare
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide2, MSGBOX_NPC
	waitmessage
	releaseall
	end

PalletTown_ProfessorOaksLab_StudyAsOaksAide::
    msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide:
    .string "Eu estudo Pokémon como Ajudante\n"
    .string "do Prof. Carvalho.$"

PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide2:
    .string "Eu sei o que voce vai perguntar.\n"
	.string "Ela esta aqui, va dar um oi para Cedar!\p"
	.string "Sejamos francos, eu nao tinha muito a\n"
	.string "dizer antes e isso nao mudou nada.\l"
	.string "Aproveite a sua estadia.$"

PalletTown_ProfessorOaksLab_NOFlash::
	msgbox PalletTown_ProfessorOaksLab_Text_NOFlash, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NOFlash:
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\p"
	.string "Receio que ela nao esteja aqui, mas\n"
	.string "eu sei onde ela deveria estar.\p"
	.string "Disseram a ela para ir a Rota 2.\n"
	.string "Ela esta a leste das arvores de corte.\p"
	.string "Voce nao pode cortar arvores sem a\n"
	.string "insignia certa, mas pode dar a volta\l"
	.string "pela Diglett Cave a partir de Vermilion.$"

PalletTown_ProfessorOaksLab_NOEverstone::
	msgbox PalletTown_ProfessorOaksLab_Text_NOEverstone, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NOEverstone:
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\p"
	.string "Receio que ela nao esteja aqui, mas\n"
	.string "eu sei onde ela deveria estar.\p"
	.string "Disseram a ela para ir ao Rock Tunnel.\n"
	.string "E um tunel dificil de atravessar.\p"
	.string "Tente ver no Centro Pokemon do lado\n"
	.string "de fora da entrada norte.\p"
	.string "Ja pegou o Fly? Se sim, por favor,\n"
	.string "va voando para o Rock Tunnel.$"

PalletTown_ProfessorOaksLab_NOItemfinder::
	msgbox PalletTown_ProfessorOaksLab_Text_NOItemfinder, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NOItemfinder::
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\p"
	.string "Receio que ela nao esteja aqui, mas\n"
	.string "eu sei onde ela deveria estar.\p"
	.string "Disseram a ela para ir a Rota 11.\n"
	.string "Suspeito que esteja descansando no\l"
	.string "posto de controle a leste de la.$"

PalletTown_ProfessorOaksLab_NoUpdateOnCedar1::
	msgbox PalletTown_ProfessorOaksLab_Text_NoUpdateOnCedar1, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NoUpdateOnCedar1:
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\l"
	.string "Receio que ela nao esteja aqui.\p"
	.string "Na verdade, ela nao tem nenhuma tarefa\n"
	.string "agora, entao esta de folga.\p"
	.string "Ela deve estar fazendo compras em\n"
	.string "Celadon ou no Game Corner.\p"
	.string "Quando o Prof. Carvalho passar uma nova\n"
	.string "tarefa, Cedar com certeza vai ligar.$"

PalletTown_ProfessorOaksLab_NOAmuletCoin::
	msgbox PalletTown_ProfessorOaksLab_Text_NOAmuletCoin, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NOAmuletCoin::
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\p"
	.string "Receio que ela nao esteja aqui, mas\n"
	.string "eu sei onde ela deveria estar.\p"
	.string "Disseram a ela para ir a Rota 16.\n"
	.string "Ela ligou avisando que um Snorlax dormiu\l"
	.string "e bloqueou o caminho de volta para\l"
	.string "Celadon City.\p"
	.string "Entao... sem uma bicicleta, ela deve\n"
	.string "estar no posto de controle ate que o\l"
	.string "Snorlax seja convencido a sair.$"

PalletTown_ProfessorOaksLab_NoUpdateOnCedar2::
	msgbox PalletTown_ProfessorOaksLab_Text_NoUpdateOnCedar2, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NoUpdateOnCedar2:
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\l"
	.string "Receio que ela nao esteja aqui.\p"
	.string "Na verdade, ela nao tem nenhuma tarefa\n"
	.string "agora, entao esta de folga.\p"
	.string "Ela falou sobre nadar ate as cavernas\n"
	.string "de Seafoam da ultima vez que tomou cha\l"
	.string "com os outros assistentes.\p"
	.string "Quando o Prof. Carvalho passar uma nova\n"
	.string "tarefa, Cedar com certeza vai ligar.$"

PalletTown_ProfessorOaksLab_NOExpShare::
	msgbox PalletTown_ProfessorOaksLab_Text_NOExpShare, MSGBOX_NPC
	release
	end

PalletTown_ProfessorOaksLab_Text_NOExpShare:
	.string "... O que disse?\n"
	.string "Esta procurando a Cedar?\p"
	.string "Receio que ela nao esteja aqui, mas\n"
	.string "eu sei onde ela deveria estar.\p"
	.string "Disseram a ela para ir a Rota 15.\n"
	.string "Dito isso, ela sempre falou sobre ir\l"
	.string "a Safari Zone se tivesse chance.\p"
	.string "Ja estou parecendo um disco quebrado,\n"
	.string "mas meu palpite e que ela esta no posto\l"
	.string "de controle da Rota 15.$"

PalletTown_ProfessorOaksLab_EventScript_Aide2::
	lock
	faceplayer
	goto_if_set FLAG_REGISTERED_AIDE, PalletTown_ProfessorOaksLab_EventScript_JealousAide
	msgbox PalletTown_ProfessorOaksLab_Text_CedarRunsErrands
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarRunsErrands::
    .string "Cedar e a mais nova assistente do lab,\n"
    .string "entao vive na rua fazendo recados.$"

PalletTown_ProfessorOaksLab_EventScript_JealousAide::
	msgbox PalletTown_ProfessorOaksLab_Text_Jealous
	release
	end

PalletTown_ProfessorOaksLab_Text_Jealous::
    .string "Para ser sincero, o trabalho no lab\n"
    .string "pode ficar meio sem graca.\p"
    .string "Eu implicava com ela no comeco, mas\n"
    .string "agora tenho uma pontinha de inveja de\l"
    .string "que Cedar possa viajar tanto!$"

PalletTown_ProfessorOaksLab_EventScript_Cedar::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ALL_CHARMS, PalletTown_ProfessorOaksLab_EventScript_CedarAllItems
	goto_if_set FLAG_RECEIVED_EXP_SHARE, PalletTown_ProfessorOaksLab_EventScript_CedarPostgame
	msgbox PalletTown_ProfessorOaksLab_Text_JustJoined
	setflag FLAG_MET_CEDAR
	release
	end

PalletTown_ProfessorOaksLab_Text_JustJoined::
    .string "Cedar: Ola! Muito prazer!\n"
    .string "Eu me juntei recentemente a equipe\l"
    .string "do Professor Carvalho.\p"
    .string "Estou muito empolgada em trabalhar\n"
    .string "com todos.$"

PalletTown_ProfessorOaksLab_EventScript_CedarPostgame::
	msgbox PalletTown_ProfessorOaksLab_Text_CedarHiPlayer, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetCatchingCharm
	goto_if_unset FLAG_RECEIVED_OVAL_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetOvalCharm
PalletTown_ProfessorOaksLab_EventScript_CedarCheckNext::
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetShinyCharm
PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems::
	msgbox PalletTown_ProfessorOaksLab_Text_MaybeMoreItems, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_GetCatchingCharm::
	goto_if_unset FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems
	msgbox PalletTown_ProfessorOaksLab_Text_CatchingCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedCatchingCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_CATCHING_CHARM
	additem ITEM_CATCHING_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_CatchingCharmReward::
	.string "Uau! Voce venceu a Elite dos Quatro?\n"
	.string "Isso e uma grande conquista!\p"
	.string "Sabe, ainda ha mais Pokemon para\n"
	.string "ver por ai afora.\p"
	.string "Isto vai te ajudar a completar sua Pokedex!$"

PalletTown_ProfessorOaksLab_Text_ReceivedCatchingCharm::
	.string "{PLAYER} recebeu o Catching Charm!$"

PalletTown_ProfessorOaksLab_EventScript_GetOvalCharm::
	goto_if_unset FLAG_CLEARED_SECRET_BATTLE, PalletTown_ProfessorOaksLab_EventScript_CedarCheckNext
	msgbox PalletTown_ProfessorOaksLab_Text_OvalCharmReward
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedOvalCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_OVAL_CHARM
	additem ITEM_OVAL_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_OvalCharmReward::
	.string "Uau! Voce venceu o Prof. Carvalho?\n"
	.string "Essa e uma conquista impressionante!\p"
	.string "Criar Pokemon e tao importante quanto\n"
	.string "batalhar, sabia?\p"
	.string "Isto deve te ajudar a criar novos Pokemon!$"

PalletTown_ProfessorOaksLab_Text_ReceivedOvalCharm::
	.string "{PLAYER} recebeu o Oval Charm!$"

PalletTown_ProfessorOaksLab_EventScript_GetShinyCharm::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems
	msgbox PalletTown_ProfessorOaksLab_Text_ShinyCharmReward
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedShinyCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_SHINY_CHARM
	additem ITEM_SHINY_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_ShinyCharmReward::
	.string "Incrivel! Voce capturou todos eles?\n"
	.string "Essa e uma conquista extraordinaria!\p"
	.string "Ouvi dizer que Pokemon tem variacoes\n"
	.string "rarissimas.\p"
	.string "Eu nunca vi uma, no entanto...\p"
	.string "Isto pode te ajudar a acha-los!$"

PalletTown_ProfessorOaksLab_Text_ReceivedShinyCharm::
	.string "{PLAYER} recebeu o Shiny Charm!$"

Cedar_CheckCharms::
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, Common_EventScript_Return
	goto_if_unset FLAG_RECEIVED_OVAL_CHARM, Common_EventScript_Return
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, Common_EventScript_Return
	setflag FLAG_RECEIVED_ALL_CHARMS
	return

PalletTown_ProfessorOaksLab_EventScript_CedarAllItems::
	msgbox PalletTown_ProfessorOaksLab_Text_WhatAJourney
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarHiPlayer:
	.string "Cedar: Ola, {PLAYER}!\n"
	.string "Passou para ver o Professor?\p"
	.string "Ah? Veio falar comigo?$"

PalletTown_ProfessorOaksLab_Text_MaybeMoreItems::
	.string "Hmm, nao tenho novos itens para te\n"
	.string "dar no momento.\p"
	.string "Mas adoraria continuar ouvindo sobre\n"
	.string "as suas aventuras!\p"
	.string "Se tiver uma grande conquista para me\n"
	.string "contar, posso convencer o Professor a\l"
	.string "te dar algo muito bom!$"

PalletTown_ProfessorOaksLab_Text_WhatAJourney::
	.string "Cedar: Ah, {PLAYER}!\n"
	.string "E tao bom te ver.\p"
	.string "Nao tenho novos itens para voce desta\n"
	.string "vez, no entanto. Ha!\p"
	.string "Sabe, quando entrei no lab do Prof.\n"
	.string "Carvalho, eu nao gostei de passar tanto\l"
	.string "tempo viajando longe daqui!\p"
	.string "Mas acompanhar sua jornada tambem foi\n"
	.string "uma aventura para mim!\p"
	.string "Eu vi tanto de Kanto e vi como e a\n"
	.string "vida de um Treinador.\p"
	.string "Agora entendo por que o Professor me\n"
	.string "deu essa missao.\p"
	.string "Entao, obrigada pela aventura!$"

PalletTown_ProfessorOaksLab_EventScript_Pokedex::
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia::
    .string "E como uma enciclopedia, mas as\n"
    .string "paginas estao em branco.$"

PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_Text_OaksLastMon::
    .string "Esse e o ultimo Pokémon do Prof. Carvalho.$"

PalletTown_ProfessorOaksLab_EventScript_ProfOak::
	lock
	faceplayer
	goto_if_set FLAG_OAK_ADVENTURE_AWAITS, PalletTown_ProfessorOaksLab_EventScript_HelloChampion
	goto_if_eq VAR_OAK_LAB_STATE, 2, PalletTown_ProfessorOaksLab_EventScript_GoTakePokeball
	goto_if_eq VAR_OAK_LAB_STATE, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
	goto_if_le VAR_OAK_LAB_STATE, 5, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
	goto_if_eq VAR_OAK_LAB_STATE, 7, PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait
	goto_if_unset FLAG_REGISTERED_PROF_OAK, EventScript_RegisterProfOak
	goto ProfOak_EventScript_AskRatePokedex
	release
	end

PalletTown_ProfessorOaksLab_EventScript_HelloChampion::
	msgbox PalletTown_ProfessorOaksLab_WonderfulToSeeYou, MSGBOX_NPC
	waitmessage
	goto_if_unset FLAG_DEFEATED_SECRET_BATTLE, PalletTown_ProfessorOaksLab_EventScript_NoE42
	clearflag FLAG_OAK_ADVENTURE_AWAITS
	release
	end

PalletTown_ProfessorOaksLab_WonderfulToSeeYou:
	.string "Campeao {PLAYER}!\n"
	.string "Que bom que voce apareceu.\p"
	.string "Entao! Procurando ideias de como\n"
	.string "continuar a sua jornada?\p"
	.string "...\p"
	.string "O que? Esperava que sua mae parasse\n"
	.string "de chiar por voce jogar videogame?\p"
	.string "Ha ha, imagino que ficar em casa e\n"
	.string "jogar o seu videogame seria otimo.\p"
	.string "{RIVAL} tem um tambem. Uma tecnologia\n"
	.string "fascinante.\p"
	.string "Enfim, se quiser mais aventura, aqui\n"
	.string "estao os proximos passos que um Campeao\l"
	.string "deve considerar para se tornar um\l"
	.string "Mestre Pokemon.\p"
	.string "Nao sei se acompanhou as noticias,\n"
	.string "mas a sua vitoria gerou uma onda de\l"
	.string "interesse na Liga!\p"
	.string "Voce agora esta no lugar de {RIVAL},\n"
	.string "e quando um desafiante derrotar a\l"
	.string "Elite, precisara ir a Liga defender\l"
	.string "o seu titulo.\p"
	.string "Sei que todos os Ginasios de Kanto\n"
	.string "estao treinando em ritmo acelerado.\p"
	.string "Parte do seu papel como Campeao e\n"
	.string "visitar os Ginasios.\p"
	.string "Que tal desafiar os Lideres para\n"
	.string "uma revanche?\p"
	.string "Eles nao poderao te dar outra insignia,\n"
	.string "mas voce ganhara Pontos de Batalha!\p"
	.string "..."
	.string "O que sao Pontos de Batalha?\p"
	.string "Sao recompensas para treinadores que\n"
	.string "foram alem dos limites.\p"
	.string "Imagino que conheceu Scott?\p"
	.string "Ele comanda a Battle Tower a oeste\n"
	.string "de Viridian City.\p"
	.string "Voce pode trocar Pontos de Batalha la!\p"
	.string "Por fim, continue ajudando Looker e\n"
	.string "a Policia Internacional.\p"
	.string "Campeoes ajudam a manter a paz, mas\n"
	.string "voce e um treinador especial.\p"
	.string "... Vejo que seus olhos estao pesando,\n"
	.string "entao vou parar por aqui.\p"
	.string "Apenas va la fora e seja o melhor,\n"
	.string "como ninguem jamais foi.$"

PalletTown_ProfessorOaksLab_EventScript_NoE42::
	msgbox PalletTown_ProfessorOaksLab_Text_NoE42, MSGBOX_NPC
	waitmessage
	clearflag FLAG_OAK_ADVENTURE_AWAITS
	release
	end

PalletTown_ProfessorOaksLab_Text_NoE42:
	.string "Hmm?\p"
	.string "Para um Professor Pokémon,\n"
	.string "parece que sei muito sobre\l"
	.string "a Liga Pokémon, nao e?\p"
	.string "Curioso, nao acha?\p"
	.string "Boa sorte la fora, Campeao.$"

PalletTown_ProfessorOaksLab_EventScript_GoTakePokeball::
	msgbox PalletTown_ProfessorOaksLab_Text_TakeMyPokemon, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_TakeMyPokemon::
    .string "Carvalho: Agora, {PLAYER}.\p"
    .string "Dentro daquela Pokebola esta\n"
    .string "um dos meus Pokemon.\p"
    .string "Por favor, cuide muito bem dele!$"

PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon::
    .string "Carvalho: Se um Pokemon selvagem surgir,\n"
    .string "seu Pokemon pode batalhar com ele.\p"
    .string "Com ele ao seu lado, voce conseguira\n"
    .string "chegar a proxima cidade.$"

PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow::
    .string "Carvalho: {PLAYER}, treine seu jovem\n"
    .string "Pokémon fazendo-o batalhar.\p"
    .string "Ele precisa batalhar para crescer.$"

PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait::
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait::
    .string "Pokemon de todo o mundo esperam\n"
    .string "por voce, {PLAYER}!$"

EventScript_RegisterProfOak::
	msgbox MatchCall_Text_OakRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOak, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_PROF_OAK
	setvar VAR_OAK_LAB_STATE, 9
	release
	end

ProfOak_EventScript_AskRatePokedex::
	msgbox gOakDexRatingText_GoodToSeeYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfOak_EventScript_DeclineRating
	call ProfOak_EventScript_RatePokedex
	release
	end

ProfOak_EventScript_DeclineRating::
	msgbox gOakDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfOak_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfOak_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gOakDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfOak_EventScript_ShowRatingMessage
	return

