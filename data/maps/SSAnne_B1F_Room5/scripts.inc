SSAnne_B1F_Room5_MapScripts::
	.byte 0

SSAnne_B1F_Room5_EventScript_ItemSuperPotion::
	finditem ITEM_SUPER_POTION, 1
	release
	end

SSAnne_B1F_Room5_EventScript_Boy::
	msgbox SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks, MSGBOX_NPC
	end

SSAnne_B1F_Room5_Text_MachokeHasStrengthToMoveRocks::
    .string "Meu parceiro Machoke é super forte!\p"
    .string "Ele tem força suficiente para mover\n"
    .string "pedregulhos enormes!$"

SSAnne_B1F_Room5_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox SSAnne_B1F_Room5_Text_Machoke
	waitmoncry
	release
	end

SSAnne_B1F_Room5_Text_Machoke::
    .string "Machoke: Gwoh! Goggoh!$"
