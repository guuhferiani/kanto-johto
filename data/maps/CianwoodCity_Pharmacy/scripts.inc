CianwoodCity_Pharmacy_MapScripts::
	.byte 0

CianwoodCity_Pharmacy_EventScript_Pharmacist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CIANWOOD_SECRETPOTION, CianwoodCity_Pharmacy_EventScript_Shop
	msgbox CianwoodCity_Pharmacy_Text_GiveSecretPotion, MSGBOX_DEFAULT
	giveitem ITEM_FULL_RESTORE, 3
	setflag FLAG_RECEIVED_CIANWOOD_SECRETPOTION
	msgbox CianwoodCity_Pharmacy_Text_DeliverToLighthouse, MSGBOX_DEFAULT
	release
	end

CianwoodCity_Pharmacy_EventScript_Shop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart CianwoodCity_Pharmacy_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CianwoodCity_Pharmacy_Pokemart:
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE
	release
	end

CianwoodCity_Pharmacy_Text_GiveSecretPotion::
	.string "Farmacêutico: Bem-vindo à Farmácia\n"
	.string "Tradicional de 500 Anos de Cianwood!\p"
	.string "Ah, o Amphy do Farol de Olivine\n"
	.string "está doente? Tome imediatamente\l"
	.string "nossa SecretPotion especial e\l"
	.string "3 Full Restores!$"

CianwoodCity_Pharmacy_Text_DeliverToLighthouse::
	.string "Farmacêutico: Leve a SecretPotion\n"
	.string "para Jasmine no topo do Farol de\l"
	.string "Olivine City!$"
