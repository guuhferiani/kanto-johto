.set LOCALID_SUDOWOODO, 1

Route36_MapScripts::
	.byte 0

Route36_EventScript_Sudowoodo::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_LEADER_WHITNEY, Route36_EventScript_WeirdTree
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	msgbox Route36_Text_SudowoodoAttacked, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_SUDOWOODO, 60, ITEM_HARD_STONE
	dowildbattle
	removeobject LOCALID_SUDOWOODO
	setflag FLAG_CAUGHT_ROUTE36_SUDOWOODO
	release
	end

Route36_EventScript_WeirdTree::
	msgbox Route36_Text_WeirdTree, MSGBOX_DEFAULT
	release
	end

Route36_EventScript_Florist::
	msgbox Route36_Text_Florist, MSGBOX_NPC
	end

Route36_EventScript_RouteSign::
	msgbox Route36_Text_RouteSign, MSGBOX_SIGN
	end

Route36_Text_WeirdTree::
	.string "Uma árvore estranha bloqueia a\n"
	.string "passagem para Ecruteak City!\p"
	.string "Conquiste a Insígnia da Planície\n"
	.string "no Ginásio de Whitney para ganhar\l"
	.string "o regador e despertá-la!$"

Route36_Text_SudowoodoAttacked::
	.string "Você borrifou água na árvore\n"
	.string "estranha!\p"
	.string "A árvore se contorceu furiosa!\n"
	.string "É um Sudowoodo selvagem!$"

Route36_Text_Florist::
	.string "Aquela árvore esquisita na verdade\n"
	.string "é um Pokémon do tipo Pedra que\l"
	.string "detesta água!\p"
	.string "Depois de passar por ela, atravesse\n"
	.string "o portão para chegar à histórica\l"
	.string "Ecruteak City!$"

Route36_Text_RouteSign::
	.string "ROTA 36 & 37\n"
	.string "Leste: Goldenrod City\l"
	.string "Portão Oeste: Ecruteak City$"
