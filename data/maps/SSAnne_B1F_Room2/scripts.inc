SSAnne_B1F_Room2_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
    .string "Até nós, marinheiros, temos Pokémon!$"

SSAnne_B1F_Room2_Text_HueyDefeat::
    .string "Tudo bem, você não é nada mau.$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
    .string "Capturamos todos os nossos Pokémon\n"
    .string "enquanto estávamos no mar.$"

SSAnne_B1F_Room2_EventScript_ItemTM44::
	finditem ITEM_TM44, 1
	release
	end
