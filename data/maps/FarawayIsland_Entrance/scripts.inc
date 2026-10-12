.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	.byte 0

FarawayIsland_Entrance_OnTransition:
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	setflag FLAG_HIDE_KAIRI
	goto_if_set FLAG_CAUGHT_MEW, FarawayIsland_Entrance_KairiAppear
	end

FarawayIsland_Entrance_KairiAppear::
	clearflag FLAG_HIDE_KAIRI
	return

FarawayIsland_Entrance_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_Return, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_CINNABAR_ISLAND, 11, 11
	waitstate
	release
	end

FarawayIsland_Entrance_Text_Return:
    .string "Essa foi uma baita jornada!\p"
	.string "Fazia muito tempo que eu nao tinha\n"
	.string "a chance de velejar para um lugar novo.\n"
	.string "Voce ja explorou toda a ilha?\p"
	.string "Deseja retornar para Cinnabar?$"

FarawayIsland_Entrance_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_Sign::
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
	end

FarawayIsland_Entrance_EventScript_LassKairi::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, FarawayIsland_Entrance_EventScript_LassKairiBattle
	msgbox FarawayIsland_Entrance_Text_KairiNoBattle MSGBOX_DEFAULT
	releaseall
	end

FarawayIsland_Entrance_Text_KairiNoBattle:
	.string "Ola, sou a Kairi! Como vai voce?\p"
	.string "Voce tambem e amigo do Mew?\n"
	.string "Que maravilhoso!\p"
	.string "Sinto que voce esta numa grande\n"
	.string "aventura, nao e?\p"
	.string "Por favor, venha nos visitar sempre\n"
	.string "que quiser.$"

FarawayIsland_Entrance_EventScript_LassKairiBattle::
	trainerbattle_double TRAINER_LASS_KAIRI, FarawayIsland_Entrance_Text_KairiIntro, FarawayIsland_Entrance_Text_KairiDefeat, FarawayIsland_Entrance_Text_KairiNotEnoughMons
	msgbox FarawayIsland_Entrance_Text_KairiPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

FarawayIsland_Entrance_Text_KairiIntro:
	.string "Ola, {PLAYER}, que bom ter voce de volta!\p"
	.string "... Voce se tornou Campeao???\n"
	.string "Uau! Sera que voce consegue me vencer?$"

FarawayIsland_Entrance_Text_KairiDefeat:
	.string "Agora vejo por que Mew escolheu voce.$"

FarawayIsland_Entrance_Text_KairiPostBattle:
	.string "Batalhar com Pokémon e divertido, mas\n"
	.string "eu sonho mesmo em ser uma artista!$"

FarawayIsland_Entrance_Text_KairiNotEnoughMons::
	.string "Onde estao seus amigos Pokémon?$"

