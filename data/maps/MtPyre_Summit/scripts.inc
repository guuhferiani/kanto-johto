MtPyre_Summit_MapScripts::
	.byte 0

MtPyre_Summit_EventScript_Red::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CHAMPION_RED, MtPyre_Summit_EventScript_RedRematch
	msgbox MtPyre_Summit_Text_Red_Intro, MSGBOX_DEFAULT
	closemessage
	delay 30
	trainerbattle_no_intro TRAINER_CHAMPION_RED, MtPyre_Summit_Text_Red_Defeat
	goto MtPyre_Summit_EventScript_RedDefeated
	release
	end

MtPyre_Summit_EventScript_RedDefeated::
	setflag FLAG_DEFEATED_CHAMPION_RED
	goto_if_set FLAG_GOT_RED_REWARD, MtPyre_Summit_EventScript_RedPostReward
	msgbox MtPyre_Summit_Text_Red_PostBattle, MSGBOX_DEFAULT
	closemessage
	delay 20
	giveitem ITEM_SACRED_ASH, 1
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_GOT_RED_REWARD
	msgbox MtPyre_Summit_Text_Red_Farewell, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_RedRematch::
	msgbox MtPyre_Summit_Text_Red_RematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_RedDecline
	msgbox MtPyre_Summit_Text_Red_Intro, MSGBOX_DEFAULT
	closemessage
	delay 30
	trainerbattle_no_intro TRAINER_CHAMPION_RED, MtPyre_Summit_Text_Red_Defeat
	goto MtPyre_Summit_EventScript_RedPostReward
	release
	end

MtPyre_Summit_EventScript_RedDecline::
	msgbox MtPyre_Summit_Text_Red_Farewell, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_RedPostReward::
	msgbox MtPyre_Summit_Text_Red_Farewell, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_Sailor::
	lock
	faceplayer
	msgbox MtPyre_Summit_Text_Sailor_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_SailorStay
	msgbox MtPyre_Summit_Text_Sailor_Depart, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	fadenewbgm MUS_SURF
	playse SE_SHIP
	delay 60
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 70
	waitstate
	release
	end

MtPyre_Summit_EventScript_SailorStay::
	msgbox MtPyre_Summit_Text_Sailor_Stay, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ExitTrigger::
	lockall
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	delay 30
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 70
	waitstate
	releaseall
	end

MtPyre_Summit_Text_Red_Intro:
	.string "Red: …\p"
	.string "… …!$"

MtPyre_Summit_Text_Red_Defeat:
	.string "…!$"

MtPyre_Summit_Text_Red_PostBattle:
	.string "Red: …\p"
	.string "Red reconhece sua vitória histórica com\n"
	.string "um aceno solene e silencioso…\p"
	.string "Ele entrega a você presentes sagrados\n"
	.string "dignos do verdadeiro Mestre Pokémon!$"

MtPyre_Summit_Text_Red_Farewell:
	.string "Red: …\p"
	.string "Red ajusta a aba de seu boné e contempla\n"
	.string "o horizonte sob a neve constante…$"

MtPyre_Summit_Text_Red_RematchPrompt:
	.string "Red: …\p"
	.string "Red olha em seus olhos com determinação e\n"
	.string "prepara sua Pokébola!\p"
	.string "Deseja enfrentar o Campeão Red novamente?$"

MtPyre_Summit_Text_Sailor_Intro:
	.string "Marinheiro: O clima no cume do Monte Silver\n"
	.string "é extremo e congelante!\p"
	.string "Deseja que meu barco te leve de volta\n"
	.string "à Costa de Johto?$"

MtPyre_Summit_Text_Sailor_Depart:
	.string "Marinheiro: Entendido! Todos a bordo!\n"
	.string "Retornando à Costa de Johto!$"

MtPyre_Summit_Text_Sailor_Stay:
	.string "Marinheiro: Muito bem, Campeão {PLAYER}!\n"
	.string "Estarei aqui a postos caso queira voltar.$"
