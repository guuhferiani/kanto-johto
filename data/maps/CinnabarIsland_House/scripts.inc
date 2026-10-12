.set LOCALID_SEA_CAPTAIN, 1

CinnabarIsland_House_MapScripts::
	.byte 0

CinnabarIsland_House_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, CinnabarIsland_House_Woman2
	msgbox CinnabarIsland_House_Text_MissesSailing, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_MissesSailing::
	.string "Meu pai já foi um grande Capitão\n"
	.string "da Marinha.\p"
	.string "Mas ele não é mais o mesmo desde\n"
	.string "que se aposentou.\p"
	.string "Ele passa os dias olhando com saudades\n"
	.string "para o mar...$"

CinnabarIsland_House_Woman2::
	msgbox CinnabarIsland_House_Text_Wonderful, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_Wonderful::
	.string "Isto é maravilhoso!\p"
	.string "Eu não via meu pai tão animado\n"
	.string "há anos!$"

CinnabarIsland_House_SeaCaptain::
	lock
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_House_SeaCaptain_Grumpy
	msgbox CinnabarIsland_House_Text_WhatsLeft, MSGBOX_DEFAULT
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SEA_CAPTAIN, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox CinnabarIsland_House_Text_WhatsThatYeGot, MSGBOX_DEFAULT
	waitmessage
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	call_if_eq VAR_FACING, DIR_NORTH, CinnabarIsland_House_BehindSeaCaptain
	call_if_ne VAR_FACING, DIR_NORTH, CinnabarIsland_House_SideOfSeaCaptain
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_SEA_CAPTAIN
	setflag FLAG_SHOWN_OLD_SEA_MAP
	setflag FLAG_HIDE_CINNABAR_SEA_CAPTAIN_HOUSE
	clearflag FLAG_HIDE_CINNABAR_SEA_CAPTAIN
	release
	end

CinnabarIsland_House_BehindSeaCaptain::
	applymovement LOCALID_SEA_CAPTAIN, Movement_CaptainExit1
	return

CinnabarIsland_House_SideOfSeaCaptain::
	applymovement LOCALID_SEA_CAPTAIN, Movement_CaptainExit2
	return

Movement_CaptainExit1::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_CaptainExit2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end


CinnabarIsland_House_Text_WhatsThatYeGot::
	.string "Ahoy!\p"
	.string "O que você tem aí, jovem?\p"
	.string "..."
	.string "É um Mapa do Mar Antigo!\p"
	.string "Veja só... Já dei a volta ao mundo\n"
	.string "mais vezes do que existem Pokémon,\l"
	.string "e posso jurar que nunca vi aquela\l"
	.string "ilha deste mapa!\p"
	.string "...\p"
	.string "O quê? Quer que eu te leve até lá?\p"
	.string "...\p"
	.string "Vamos nessa! Uma última aventura para\n"
	.string "este velho Capitão do Mar!$"

CinnabarIsland_House_SeaCaptain_Grumpy::
	msgbox CinnabarIsland_House_Text_Grumpy, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_WhatsLeft::
	.string "Hrmmph...\p"
	.string "Já explorei cada canto deste\n"
	.string "mundo...\p"
	.string "O que restou para eu fazer...$"

CinnabarIsland_House_Text_Grumpy::
	.string "Hrmmph...$"


