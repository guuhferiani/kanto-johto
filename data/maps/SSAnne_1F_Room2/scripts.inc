SSAnne_1F_Room2_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_Text_CruisingAroundWorld::
    .string "Estamos fazendo um cruzeiro ao redor do\n"
    .string "mundo, meus filhos e eu.$"


SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_AnnIntro::
    .string "Eu capturei esses Pokémon por\n"
    .string "todo o mundo!$"

SSAnne_1F_Room2_Text_AnnDefeat::
    .string "Oh, não!\n"
    .string "Eu viajei o mundo todo por eles!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
    .string "Você machucou meus pobres Pokémon!\p"
    .string "Exijo que vá curá-los em um\n"
    .string "Centro Pokémon!$"


SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
    .string "Eu amo Pokémon!\n"
    .string "E você?$"

SSAnne_1F_Room2_Text_TylerDefeat::
    .string "Uau!\n"
    .string "Você é incrível!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
    .string "Escuta, escuta!\n"
    .string "Vamos ser amigos, tá bom?\p"
    .string "Aí podemos trocar Pokémon e nos\n"
    .string "divertir.$"

SSAnne_1F_Room2_EventScript_ItemTM31::
    finditem ITEM_TM31, 1
    release
    end

