.set LOCALID_MOM, 1
.set LOCALID_BILL, 2

PalletTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_1F_OnTransition
	.byte 0

PalletTown_PlayersHouse_1F_OnTransition:
	setflag FLAG_HIDE_MEGA_TRAINERS
	goto_if_set FLAG_GOT_MEGA_RING, PlayersHouse_1F_EventScriptChallengeUnlocked
	end

PalletTown_PlayersHouse_1F_EvenScripts_Mom::
	lock
	faceplayer
	goto_if_le VAR_ADVENTURE_BEGINS, 2, PalletTown_PlayersHouse_1F_EventScript_BetterHurry
	goto_if_eq VAR_ADVENTURE_BEGINS, 3, PlayersHouse_1F_EventScript_PokenavScene
	goto_if_eq VAR_SECRET_BATTLE_CLEAR, 2, PlayersHouse_1F_EventScript_BillVisiting
	goto_if_eq VAR_SECRET_BATTLE_CLEAR, 3, PlayersHouse_1F_EventScript_AnotherAdventure
	goto PalletTown_PlayersHouse_1F_EventScript_MomHeal
	end

PlayersHouse_1F_EventScript_BillVisiting::
	msgbox PalletTown_PlayersHouse_1F_Text_BillVisiting, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BillVisiting::
	.string "Mãe: Eu não sabia que você conhecia\n"
	.string "o famoso PokéManíaco, querido!\p"
	.string "Ele é um verdadeiro cavalheiro!$"

PlayersHouse_1F_EventScript_AnotherAdventure::
	msgbox PalletTown_PlayersHouse_1F_Text_AnotherAdventureAwaitsHuzzah, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_AnotherAdventureAwaitsHuzzah:
	.string "Pedras estranhas? Potencial oculto?\p"
	.string "As aventuras nunca acabam para\n" 
	.string "vocês, Treinadores Pokémon!$"

PalletTown_PlayersHouse_1F_EventScript_BetterHurry::
	msgbox PalletTown_PlayersHouse_1F_Text_BetterHurry, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BetterHurry:
	.string "Mãe: Você não vai querer perder o\n"
	.string "Professor Carvalho!\p"
	.string "É melhor se apressar!$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
    .string "Tem um filme passando na TV.\n"
    .string "Quatro garotos caminham sobre\l"
    .string "trilhos de trem.\p"
    .string "…É melhor eu ir também.$"

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end
	
PlayersHouse_1F_Text_RunningShoesManual:
	.string "É o manual de instruções do\n"
	.string "Tênis de Corrida.\p"
	.string "“Pressione o Botão B para correr\n"
	.string "enquanto calça seu Tênis de Corrida.\p"
	.string "Amarre seus sapatos e caia na\n"
	.string "estrada correndo!\p"
	.string "Se precisar andar mais devagar,\n"
	.string "segure o Botão A!”$"

PlayersHouse_1F_EventScript_PokenavScene::
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
	setflag FLAG_SYS_POKENAV_GET
	setvar VAR_ADVENTURE_BEGINS, 4
	turnobject LOCALID_MOM, DIR_WEST
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
    .string "Mãe: {PLAYER}!\n"
    .string "Você devia descansar um pouco.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
    .string "Mãe: Ah, que bom! Você e seus\n"
    .string "Pokémon estão ótimos.\l"
    .string "Se cuide por aí!$"

PlayersHouse_1F_EventScript_GameclearTrigger1::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto PlayersHouse_1F_EventScript_Gameclear

PlayersHouse_1F_EventScript_GameclearTrigger2::
	setvar VAR_TEMP_1, 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto PlayersHouse_1F_EventScript_Gameclear

PlayersHouse_1F_EventScript_DontLeaveYet::
	lockall
	turnobject LOCALID_MOM, DIR_SOUTH
	turnobject LOCALID_BILL, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox PlayersHouse_1F_Text_Visitor, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_MOM, DIR_WEST
	turnobject LOCALID_BILL, DIR_EAST
	release
	end

PlayersHouse_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_GOT_MEGA_RING, PlayersHouse_1F_EventScript_Bill2
	msgbox PlayersHouse_1F_Text_SomethingAmazing, MSGBOX_NPC
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PlayersHouse_1F_Text_GetMegaRing, MSGBOX_DEFAULT
	additem ITEM_MEGA_RING, 1
	setflag FLAG_GOT_MEGA_RING
	msgbox PlayersHouse_1F_Text_FindMegaStones, MSGBOX_NPC
	setvar VAR_SECRET_BATTLE_CLEAR, 3
	goto_if_set FLAG_GOT_MEGA_RING, PlayersHouse_1F_EventScriptChallengeUnlocked
	release
	end

PlayersHouse_1F_EventScriptChallengeUnlocked::
	clearflag FLAG_HIDE_MEGA_TRAINERS
	return

PlayersHouse_1F_Text_SomethingAmazing::
	.string "Ei, {PLAYER}!\n"
	.string "Eu descobri algo impressionante!\p"
	.string "Eu estava pesquisando para a minha\n"
	.string "coleção de Pokémon, quando um dos meus\l"
	.string "aparelhos captou uma leitura estranha.\p"
	.string "Parece que certos Pokémon têm um\n"
	.string "potencial oculto que nunca vimos antes.\p"
	.string "E este sinal parece ser a chave!\p"
	.string "Encontrei a origem do sinal perto do\n"
	.string "Chalé do Mar.\p"
	.string "Era uma pedra rara que nunca vi antes!\p"
	.string "Trouxe para o laboratório e construí\n"
	.string "um dispositivo para extrair seu poder!\p"
	.string "Quero que você fique com ele!$"

PlayersHouse_1F_Text_GetMegaRing::
	.string "Bill entregou o Mega Anel!$"

PlayersHouse_1F_Text_FindMegaStones::
	.string "De acordo com minhas leituras, há mais\n"
	.string "dessas pedras escondidas por Kanto.\p"
	.string "Agora que você tem o Mega Anel,\n"
	.string "você será capaz de vê-las!\p"
	.string "Precisamos encontrar uma Mega Pedra\n"
	.string "para testar minha teoria!$"

PlayersHouse_1F_EventScript_Bill2::
	msgbox PlayersHouse_1F_Text_MegaStones, MSGBOX_NPC
	release
	end

PlayersHouse_1F_Text_MegaStones::
	.string "Bill: Precisamos encontrar uma\n"
	.string "Mega Pedra para testar minha teoria!$"

PlayersHouse_1F_Text_Visitor::
	.string "Mãe: Onde você vai, {PLAYER}?\p"
	.string "Não vai cumprimentar nossa visita?$"

PlayersHouse_1F_EventScript_Gameclear::
	lockall
	setflag FLAG_OAK_ADVENTURE_AWAITS
	clearflag FLAG_HIDE_PKMNRANGER_ALEX
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	call_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_MoveMomToStairs1
	call_if_eq VAR_TEMP_1, 2, PlayersHouse_1F_EventScript_MoveMomToStairs2
	waitmovement 1
	msgbox PlayersHouse_1F_Text_Gameclear, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PlayersHouse_1F_Text_FollowerOptions, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox PlayersHouse_1F_Text_Gameclear2, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Heart
	waitmovement 1
	waitse
	call_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_MoveMomToTable1
	call_if_eq VAR_TEMP_1, 2, PlayersHouse_1F_EventScript_MoveMomToTable2
	waitmovement 1
	setvar VAR_ADVENTURE_BEGINS, 8
	releaseall
	end

PlayersHouse_1F_Text_Gameclear::
	.string "Mãe: Oh, {PLAYER}!\n"
	.string "Você já acordou?\p"
	.string "Depois de tudo o que enfrentou,\n"
	.string "achei que fosse descansar mais.\p"
	.string "...\p"
	.string "Você realmente cresceu, {PLAYER}.\p"
	.string "Acho que seus Pokémon também veem isso.\p"
	.string "Eles vão te seguir para qualquer lugar!$"

PlayersHouse_1F_Text_FollowerOptions::
	.string "A opção Seguidor no menu de Opções\n"
	.string "agora pode ser definida como Qualquer!\p"
	.string "Quando ativada, seu primeiro Pokémon\n"
	.string "andará ao seu lado pelo mapa!$"

PlayersHouse_1F_Text_Gameclear2::
	.string "Mãe: Só porque você se tornou o novo\n"
	.string "campeão, não quer dizer que a sua\l"
	.string "história acabou!\p"
	.string "O Professor Carvalho com certeza terá\n"
	.string "novos conselhos se você for visitá-lo.\p"
	.string "Há um mundo inteiro lá fora esperando\n"
	.string "por você e seus Pokémon!\p"
	.string "Tenho tanto orgulho de você, {PLAYER}!\n"
	.string "Vá e divirta-se com seus Pokémon!$"

PlayersHouse_1F_EventScript_MoveMomToStairs1::
	applymovement LOCALID_MOM, Movement_MoveMomToStairs1
	return

PlayersHouse_1F_EventScript_MoveMomToStairs2::
	applymovement LOCALID_MOM, Movement_MoveMomToStairs2
	return

PlayersHouse_1F_EventScript_MoveMomToTable1::
	applymovement LOCALID_MOM, Movement_MoveMomToTable1
	return

PlayersHouse_1F_EventScript_MoveMomToTable2::
	applymovement LOCALID_MOM, Movement_MoveMomToTable2
	return

Movement_MoveMomToStairs1::
	walk_up
	walk_up
	face_right
	step_end

Movement_MoveMomToStairs2::
	walk_right
	walk_right
	face_up
	step_end

Movement_MoveMomToTable1::
	walk_down
	walk_down
	face_left
	step_end

Movement_MoveMomToTable2::
	walk_left
	walk_left
	step_end

