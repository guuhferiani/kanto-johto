BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BlackthornCity_Mart_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BlackthornCity_Mart_Items:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_DRAGON_FANG
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end
