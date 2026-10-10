SSAnne_B1F_Room3_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
    .string "Gosto de garotos cheios de fibra\n"
    .string "como você!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
    .string "Argh!\n"
    .string "Perdi essa!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
    .string "Pokémon marinhos vivem em águas fundas.\n"
    .string "Você precisará de uma vara para pescá-los!$"

SSAnne_B1F_Room3_EventScript_ItemEther::
	finditem ITEM_ETHER, 1
	release
	end
