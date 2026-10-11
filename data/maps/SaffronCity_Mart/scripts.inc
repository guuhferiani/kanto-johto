SaffronCity_Mart_MapScripts::
	.byte 0

SaffronCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SaffronCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SaffronCity_Pokemart::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

SaffronCity_Mart_EventScript_Lass::
	msgbox SaffronCity_Mart_Text_ReviveIsCostly, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Youngster::
	msgbox SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper, MSGBOX_NPC
	end

SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper::
    .string "O Repelente Máx evita que Pokémon\n"
    .string "mais fracos apareçam.\p"
    .string "O Repelente Máx dura mais tempo\n"
    .string "do que o Super-Repelente.$"

SaffronCity_Mart_Text_ReviveIsCostly::
    .string "O Reviver é caro, mas revive um\n"
    .string "Pokémon desmaiado!$"
