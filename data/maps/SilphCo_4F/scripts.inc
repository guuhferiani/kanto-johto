SilphCo_4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_4F_OnLoad
	.byte 0

SilphCo_4F_OnLoad::
	call_if_unset FLAG_SILPH_4F_DOOR_1, EventScript_Close4FDoor1
	call_if_unset FLAG_SILPH_4F_DOOR_2, EventScript_Close4FDoor2
	end

SilphCo_4F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

SilphCo_4F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

SilphCo_4F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL, 1
	release
	end

SilphCo_4F_EventScript_ItemTM41::
	finditem ITEM_TM41, 1
	release
	end

SilphCo_4F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_4F_EventScript_WorkerMRocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_4F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_4F_Text_CantYouSeeImHiding
	release
	end

SilphCo_4F_EventScript_WorkerMRocketsBack::
	msgbox SilphCo_4F_Text_TeamRocketIsBack
	release
	end

SilphCo_4F_Text_TeamRocketIsBack:
	.string "Shhh! Por favor vá embora!\p"
    .string "Eles voltaram e tenho medo de ser visto\n"
	.string "com a criança que arruinou os planos\l"
	.string "deles antes.$"

SilphCo_4F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_4F_Text_TeamRocketIsGone
	release
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat
	msgbox SilphCo_4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat
	msgbox SilphCo_4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_Text_CantYouSeeImHiding::
    .string "Shhh!\n"
    .string "Não está vendo que estou me escondendo?$"

SilphCo_4F_Text_TeamRocketIsGone::
    .string "Hã?\n"
    .string "A Equipe Rocket foi embora?$"

SilphCo_4F_Text_Grunt1Intro::
    .string "A Equipe Rocket assumiu o controle\n"
    .string "da Silph S.A.!$"

SilphCo_4F_Text_Grunt1Defeat::
    .string "Arrgh!$"

SilphCo_4F_Text_Grunt1PostBattle::
    .string "Fwahahaha!\n"
    .string "Meu Chefe estava de olho neste lugar!$"

SilphCo_4F_Text_RodneyIntro::
    .string "Meu Pokémon é meu servo leal.$"

SilphCo_4F_Text_RodneyDefeat::
    .string "Droga!\n"
    .string "Pokémon inútil!$"

SilphCo_4F_Text_RodneyPostBattle::
    .string "As portas são trancadas eletronicamente.\p"
    .string "É necessário um Cartão-Chave para abrir\n"
    .string "as portas aqui.$"

SilphCo_4F_Text_Grunt2Intro::
    .string "Intruso à vista!$"

SilphCo_4F_Text_Grunt2Defeat::
    .string "Quem é você?$"

SilphCo_4F_Text_Grunt2PostBattle::
    .string "É melhor eu avisar o Chefe no 11º andar!$"

SilphCo_4F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "4º Andar$"
