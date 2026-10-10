SSAnne_2F_Room2_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_ItemStardust::
	finditem ITEM_STARDUST, 1
	release
	end

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_DaleIntro::
    .string "Olha só o que eu pesquei!$"

SSAnne_2F_Room2_Text_DaleDefeat::
    .string "Fiquei sem nada!$"

SSAnne_2F_Room2_Text_DalePostBattle::
    .string "Festa?\p"
    .string "A festa do navio já deve ter acabado\n"
    .string "a essa altura.$"

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_BrooksIntro::
    .string "Competir contra os jovens me mantém\n"
    .string "com espírito jovem.$"

SSAnne_2F_Room2_Text_BrooksDefeat::
    .string "Boa batalha!\n"
    .string "Ah, me sinto jovem novamente!$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
    .string "Quinze anos atrás, eu teria\n"
    .string "vencido!$"
