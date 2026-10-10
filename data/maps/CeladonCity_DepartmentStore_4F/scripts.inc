CeladonCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_4F_OnTransition
	.byte 0

CeladonCity_DepartmentStore_4F_OnTransition:
	setescapewarp MAP_CELADON_CITY, 15, 16
	end

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent::
    .string "Estou escolhendo um presente para\n"
    .string "minha namorada.\p"
    .string "Acho que vai ser uma Poké Boneca.\n"
    .string "É a novidade mais popular.$"

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll::
    .string "Ouvi algo muito útil.\p"
    .string "Se um Pokémon selvagem aparecer,\n"
    .string "você pode distraí-lo com uma Poké Boneca.\p"
    .string "Você pode fugir enquanto o Pokémon\n"
    .string "selvagem estiver distraído.$"

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_Text_FloorSign::
    .string "Expresse seus sentimentos com presentes!\n"
    .string "4º Andar: Presentes do Sábio\p"
    .string "Especial de Evolução!\n"
    .string "Pedras Elementais à venda agora!$"

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items::
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_POWER_STONE
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_AIR_BALLOON
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_LAGGING_TAIL
	.2byte ITEM_NONE
	release
	end
