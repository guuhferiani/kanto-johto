CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
    .string "O Repelente não apenas afasta insetos,\n"
    .string "ele também afasta Pokémon fracos.\p"
    .string "Coloque seu Pokémon mais forte na\n"
    .string "primeira posição da sua equipe.\p"
    .string "Se seu primeiro Pokémon for forte,\n"
    .string "o efeito do REPELENTE é ampliado.$"

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
    .string "Você conhece o Doce Raro?\n"
    .string "Eles não vendem isso em lojas.\p"
    .string "Acho que faz o Pokémon crescer\n"
    .string "muito rápido, num piscar de olhos.$"

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeruleanCity_Pokemart::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end
