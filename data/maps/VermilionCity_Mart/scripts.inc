VermilionCity_Mart_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer, MSGBOX_NPC
	end

VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer::
    .string "Acho que os Pokémon podem ser bons ou\n"
    .string "maus. Isso depende do treinador.$"

VermilionCity_Mart_EventScript_BaldingMan::
	msgbox VermilionCity_Mart_Text_TeamRocketAreWickedPeople, MSGBOX_NPC
	end

VermilionCity_Mart_Text_TeamRocketAreWickedPeople::
    .string "Existem pessoas perversas que usam\n"
    .string "Pokémon para cometer crimes.\p"
    .string "A Equipe Rocket trafica Pokémon\n"
    .string "raros, por exemplo.\p"
    .string "Eles também abandonam Pokémon que\n"
    .string "consideram impopulares ou inúteis.\p"
    .string "Esse é o tipo de gente horrível\n"
    .string "que a Equipe Rocket é.$"

VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VermilionCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VermilionCity_Pokemart::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end
