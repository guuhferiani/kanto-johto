VioletCity_Mart_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VioletCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VioletCity_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE
	release
	end

VioletCity_Mart_EventScript_Customer::
	msgbox VioletCity_Mart_Text_Customer, MSGBOX_NPC
	end

VioletCity_Mart_Text_Customer:
	.string "O Poké Mart de Violet City estoca\n"
	.string "Ultra Balls e Full Restores para os\l"
	.string "desafiantes dos Ginásios de Johto!$"
