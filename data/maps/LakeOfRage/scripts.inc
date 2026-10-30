.set LOCALID_RED_GYARADOS, 2

LakeOfRage_MapScripts::
	.byte 0

LakeOfRage_EventScript_Lance::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_RED_GYARADOS, LakeOfRage_EventScript_LanceAfter
	msgbox LakeOfRage_Text_LanceIntro, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_LanceAfter::
	msgbox LakeOfRage_Text_LanceAfter, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_RedGyarados::
	lock
	faceplayer
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	msgbox LakeOfRage_Text_RedGyaradosAttacked, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_GYARADOS, 65, ITEM_DRAGON_SCALE
	dowildbattle
	removeobject LOCALID_RED_GYARADOS
	setflag FLAG_CAUGHT_RED_GYARADOS
	giveitem ITEM_RED_ORB, 1
	giveitem ITEM_GYARADOSITE, 1
	msgbox LakeOfRage_Text_ReceivedRedScale, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_ItemGyaradosite::
	finditem ITEM_GYARADOSITE, 1
	end

LakeOfRage_Text_LanceIntro::
	.string "Lance: Olá, Campeão {PLAYER}!\n"
	.string "Vim investigar os sinais de rádio\l"
	.string "da Equipe Rocket que forçaram os\l"
	.string "Magikarp deste lago a evoluírem!\p"
	.string "Logo à frente na ponte está o\n"
	.string "lendário Gyarados Vermelho em\l"
	.string "fúria! Só um mestre como você\l"
	.string "pode acalmá-lo ou capturá-lo!$"

LakeOfRage_Text_RedGyaradosAttacked::
	.string "GYAAAAARGH!\n"
	.string "O Gyarados Vermelho do Lago da\l"
	.string "Fúria avançou com olhos faiscantes!$"

LakeOfRage_Text_ReceivedRedScale::
	.string "Você obteve a Escama Vermelha\n"
	.string "(Red Orb) e a Mega Pedra\l"
	.string "Gyaradosite deixadas no lago!$"

LakeOfRage_Text_LanceAfter::
	.string "Lance: Excelente trabalho,\n"
	.string "{PLAYER}! Graças a você, o Lago\l"
	.string "da Fúria voltou à paz!\p"
	.string "Agora você pode desafiar Pryce no\n"
	.string "Ginásio de Mahogany e minha prima\l"
	.string "Clair em Blackthorn City!$"
