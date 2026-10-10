CeladonCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_5F_OnTransition
	.byte 0

CeladonCity_DepartmentStore_5F_OnTransition:
	setescapewarp MAP_CELADON_CITY, 15, 16
	end
	
CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers::
    .string "Potencializadores de atributos de\n"
    .string "Pokémon só podem ser comprados aqui.\p"
    .string "Mais HP aumenta os pontos de PS\n"
    .string "base de um Pokémon.\p"
    .string "Cálcio aumenta o ATQ. ESP. base\n"
    .string "de um Pokémon.\p"
    .string "Zinco aumenta a DEF. ESP. base\n"
    .string "de um Pokémon.\p"
    .string "Carboidrato aprimora a Velocidade\n"
    .string "base.$"

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers::
    .string "Estou aqui pelos potencializadores\n"
    .string "de atributos de Pokémon.\p"
    .string "Proteína aumenta o Ataque base.\p"
    .string "Ferro aumenta a Defesa base.$"

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_Text_Drugstore::
    .string "5º Andar: Farmácia$"

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_XItems
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_XItems::
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_Vitamins
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_Vitamins::
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_NONE
	release
	end
