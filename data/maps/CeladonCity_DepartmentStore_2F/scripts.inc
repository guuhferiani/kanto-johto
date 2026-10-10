CeladonCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_2F_OnTransition
	.byte 0

CeladonCity_DepartmentStore_2F_OnTransition:
	setescapewarp MAP_CELADON_CITY, 15, 16
	end

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
    .string "O Super Repelente afasta Pokémon\n"
    .string "fracos…\p"
    .string "Hmm, é uma versão mais potente\n"
    .string "do Repelente comum.$"

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
    .string "Para viagens longas, você deveria\n"
    .string "comprar Reviver.$"

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_Text_FloorSign::
    .string "Itens de Primeira Linha para Treinadores!\p"
    .string "2º Andar: Mercado do Treinador$"

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM44
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_Woman::
    lock
    faceplayer
    msgbox CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes
    release
    end

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
    .string "Temos um cliente, o Lance, que vem\n"
    .string "aqui de vez em quando.\p"
    .string "Ele sempre compra capas.\p"
    .string "Fico pensando… Será que ele tem um\n"
    .string "monte de capas iguais em casa?$"
