CinnabarIsland_Mart_MapScripts::
	.byte 0

CinnabarIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CinnabarIsland_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CinnabarIsland_Pokemart::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

CinnabarIsland_Mart_EventScript_Woman::
	msgbox CinnabarIsland_Mart_Text_DontTheyHaveXAttack, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Scientist::
	msgbox CinnabarIsland_Mart_Text_ExtraItemsNeverHurt, MSGBOX_NPC
	end

CinnabarIsland_Mart_Text_DontTheyHaveXAttack::
    .string "Eles não têm Ataque X?\p"
    .string "Eu gosto dele porque aumenta o Ataque\n"
    .string "durante a batalha.$"

CinnabarIsland_Mart_Text_ExtraItemsNeverHurt::
    .string "Nunca é demais carregar itens extras.\n"
    .string "Você nunca sabe o que pode acontecer.$"
