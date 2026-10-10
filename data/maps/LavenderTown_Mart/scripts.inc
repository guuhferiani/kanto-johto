LavenderTown_Mart_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavenderTown_Pokemart::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
    .string "Estou procurando por itens que aumentam\n"
    .string "os atributos dos Pokémon.\p"
    .string "Eles fazem efeito durante o decorrer\n"
    .string "de uma única batalha.\p"
    .string "Ataque X, Defesa X, Velocidade X\n"
    .string "e Especial X são os que eu procuro.\p"
    .string "Você sabe onde posso encontrá-los?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
    .string "Você comprou alguns Reviver?\n"
    .string "Eles revivem qualquer Pokémon desmaiado!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
    .string "Às vezes, uma dupla de treinadores vai\n"
    .string "te desafiar com dois Pokémon\l"
    .string "ao mesmo tempo.\p"
    .string "Se isso acontecer, você precisará mandar\n"
    .string "dois Pokémon para a batalha também.$"
