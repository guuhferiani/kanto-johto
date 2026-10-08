.set LOCALID_MOM, 1

PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PalletTown_OnResume
	.byte 0

PalletTown_OnTransition:
	setflag FLAG_VISITED_PALLET_TOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	call_if_eq VAR_SECRET_BATTLE_CLEAR, 3, EventScript_UpdatePostgame
	call_if_eq VAR_OAK_LAB_STATE, 7, EventScript_UpdateOakLabState
	call Common_EventScript_GetDayOrNight
	end

PalletTown_OnResume:
	call Common_EventScript_GetDayOrNight
	end

EventScript_UpdatePostgame::
	setvar VAR_SECRET_BATTLE_CLEAR, 4
	setflag FLAG_HIDE_PALLET_BILL
	return

EventScript_UpdateOakLabState::
	setvar VAR_OAK_LAB_STATE, 8
	return

PalletTown_EventScript_PokenavSceneStart1::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart2::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 2
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart3::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 3
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart4::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 4
	goto PalletTown_EventScript_PokenavSceneStartFar

PalletTown_EventScript_PokenavSceneStart5::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 5
	goto PalletTown_EventScript_PokenavSceneStartFar

PalletTown_EventScript_MomEntersFromDoor::
	opendoor 6,7
	playse SE_DOOR
	waitdooranim
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	closedoor 6,7
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PokenavMomApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_EventScript_PokenavMomApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_EventScript_PokenavMomApproach3
	return

PalletTown_EventScript_PokenavSceneStartFar::
	setobjectxyperm LOCALID_MOM, 11, 7
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavScene::
	call_if_le VAR_TEMP_1, 3, PalletTown_EventScript_MomEntersFromDoor
	call_if_eq VAR_TEMP_1, 4, PalletTown_EventScript_PokenavMomApproach4
	call_if_eq VAR_TEMP_1, 5, PalletTown_EventScript_PokenavMomApproach5
	msgbox PalletTown_Text_DidYouMeetOak, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, Common_Movement_Heart
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_Text_WhatACutePokemon, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_Text_ReceivedPokeGear
	waitmessage
	waitfanfare
	msgbox PalletTown_Text_CallMeSometime, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PokenavMomExit1
	call_if_eq VAR_TEMP_1, 2, PalletTown_EventScript_PokenavMomExit2
	call_if_eq VAR_TEMP_1, 3, PalletTown_EventScript_PokenavMomExit3
	call_if_eq VAR_TEMP_1, 4, PalletTown_EventScript_PokenavMomExit4
	call_if_eq VAR_TEMP_1, 5, PalletTown_EventScript_PokenavMomExit5
	waitmovement 1
	call_if_le VAR_TEMP_1, 3, PalletTown_EventScript_PokenavSceneExitDoor
	removeobject LOCALID_MOM
	setflag FLAG_HIDE_MOM_PALLET_TOWN
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setvar VAR_ADVENTURE_BEGINS, 4
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

PalletTown_Text_DidYouMeetOak:
	.string "Mãe: {PLAYER}!\p"
	.string "Você já falou com o\n"
	.string "Professor Carvalho?$"

PalletTown_Text_WhatACutePokemon:
	.string "Oh! Que Pokémon adorável!\n"
	.string "Você ganhou do Prof. Carvalho? Que ótimo!\p"
	.string "E agora você está a caminho de\n"
	.string "Viridian City?\p"
	.string "Bem, acho que todo mundo sonha em\n"
	.string "viajar. Pelo menos é o que diz na TV.\p"
	.string "Sendo assim, você não iria querer sair\n"
	.string "sem o seu PokéGear, iria?$"

PalletTown_Text_CallMeSometime:
	.string "Seu PokéGear tem um mapa, então\n"
	.string "você nunca vai se perder.\p"
	.string "Eu também já salvei o meu número\n"
	.string "no seu celular.\p"
	.string "Não se esqueça da sua mãe durante\n"
	.string "as suas aventuras. Me ligue de vez em quando!$"

PalletTown_Text_ReceivedPokeGear:
	.string "{PLAYER} recebeu o PokéGear\n"
    .string "da Mamãe!$"

PalletTown_EventScript_PokenavSceneExitDoor::
	applymovement LOCALID_MOM, Movement_MomExitDoor
	waitmovement 1
	closedoor 6,7
	playse SE_EXIT
	return

Movement_MomExitDoor:
	walk_up
	step_end

PalletTown_EventScript_PokenavMomApproach1::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Movement_MomApproachPokenav1:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	face_left
	step_end

PalletTown_EventScript_PokenavMomApproach2::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Movement_MomApproachPokenav2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

PalletTown_EventScript_PokenavMomApproach3::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Movement_MomApproachPokenav3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

PalletTown_EventScript_PokenavMomApproach4::
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, Movement_MomApproachPokenav4
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Movement_MomApproachPokenav4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	face_left
	step_end

PalletTown_EventScript_PokenavMomApproach5::
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, Movement_MomApproachPokenav5
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Movement_MomApproachPokenav5:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_right
	step_end

PalletTown_EventScript_PokenavMomExit1::
	applymovement LOCALID_MOM, Movement_MomExitPokenav1
	waitmovement 1
	opendoor 6, 7
	waitdooranim
	return

Movement_MomExitPokenav1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit2::
	applymovement LOCALID_MOM, Movement_MomExitPokenav2
	return

Movement_MomExitPokenav2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit3::
	applymovement LOCALID_MOM, Movement_MomExitPokenav3
	return

Movement_MomExitPokenav3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit4::
	applymovement LOCALID_MOM, Movement_MomExitPokenav4
	return

Movement_MomExitPokenav4:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_EventScript_PokenavMomExit5::
	applymovement LOCALID_MOM, Movement_MomExitPokenav5
	return

Movement_MomExitPokenav5:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_Text_TownSign::
    .string "Pallet Town\n"
    .string "Cores de uma nova jornada!$"

PalletTown_EventScript_TrainerTips::
	lockall
	msgbox PalletTown_Text_PressStartToOpenMenu, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_Text_PressStartToOpenMenu::
	.string "Dicas para Treinadores:\p"
	.string "Pressione Start para abrir o Menu!$"

PalletTown_EventScript_OaksLabSign::
	lockall
	msgbox PalletTown_Text_OakPokemonResearchLab, MSGBOX_SIGN
	releaseall
	end

PalletTown_Text_OakPokemonResearchLab::
    .string "Laboratório de Pesquisa Pokémon\n"
    .string "do Prof. Carvalho$"

PalletTown_EventScript_Lady::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEMON_GET, PalletTown_EventScript_SignLady
	msgbox PalletTown_Text_RaisingMonsToo, MSGBOX_DEFAULT
	release
	end

PalletTown_Text_RaisingMonsToo::
    .string "Eu também estou criando Pokémon.\p"
    .string "Quando eles ficarem fortes, poderão\n"
    .string "me proteger.$"

PalletTown_EventScript_SignLady::
	msgbox PalletTown_Text_SignsAreUsefulArentThey, MSGBOX_DEFAULT
	release
	end

PalletTown_Text_SignsAreUsefulArentThey::
	.string "Placas são muito úteis, não são?\p"
	.string "Dá para aprender bastante com\n"
	.string "essas placas de Dicas para Treinadores!$"

PalletTown_EventScript_FatMan::
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
	end

PalletTown_Text_CanStoreItemsAndMonsInPC::
    .string "A tecnologia é incrível!\p"
    .string "Agora você pode guardar e resgatar itens\n"
    .string "e Pokémon como dados através do PC.$"

PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end

PalletTown_Text_PlayersHouse::
    .string "Casa de {PLAYER}$"

PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end

PalletTown_Text_RivalsHouse::
    .string "Casa de {RIVAL}$"
