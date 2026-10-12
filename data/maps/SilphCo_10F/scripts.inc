SilphCo_10F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL, 1
	release
	end

SilphCo_10F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS, 1
	release
	end

SilphCo_10F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
    .string "Bem-vindo ao 10º andar!\n"
    .string "Que bom que veio se juntar a mim!$"

SilphCo_10F_Text_GruntDefeat::
    .string "Estou pasmo!$"

SilphCo_10F_Text_GruntPostBattle::
    .string "Boa tentativa, mas a sala da diretoria\n"
    .string "fica um andar acima.$"

SilphCo_10F_Text_TravisIntro::
    .string "Chega de joguinhos tolos!$"

SilphCo_10F_Text_TravisDefeat::
    .string "Sem fichas restantes!$"

SilphCo_10F_Text_TravisPostBattle::
    .string "Ficou satisfeito em me derrotar?\n"
    .string "Então vá para casa!$"

SilphCo_10F_Text_WaaaImScared::
    .string "Buaaaa!\n"
    .string "Estou com medo!$"

SilphCo_10F_Text_KeepMeCryingASecret::
    .string "Sobre eu estar chorando...\n"
    .string "Por favor, guarde segredo.$"

SilphCo_10F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "10º Andar$"
