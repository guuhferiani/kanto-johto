SilphCo_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "2º Andar$"

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
    .string "Socorro!\n"
    .string "Sou um funcionário da Silph.$"

SilphCo_2F_Text_ConnorDefeat::
    .string "Como você sabia que\n"
    .string "eu era um Rocket?$"

SilphCo_2F_Text_ConnorPostBattle::
    .string "Eu trabalho tanto para a Silph quanto\n"
    .string "para a Equipe Rocket.$"

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_JerryIntro::
    .string "O acesso aqui é proibido!\n"
    .string "Vá para casa!$"

SilphCo_2F_Text_JerryDefeat::
    .string "Você é bom.$"

SilphCo_2F_Text_JerryPostBattle::
    .string "Você consegue resolver o labirinto?\n"
    .string "Não é nada fácil, garanto!$"

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_Grunt1Intro::
    .string "Crianças não são permitidas aqui!$"

SilphCo_2F_Text_Grunt1Defeat::
    .string "Que dureza!$"

SilphCo_2F_Text_Grunt1PostBattle::
    .string "Pisos em forma de losango são blocos\n"
    .string "de teletransporte.\p"
    .string "Eles transportam pessoas por este\n"
    .string "edifício de alta tecnologia.$"

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_Grunt2Intro::
    .string "Ei, garoto!\n"
    .string "O que faz perambulando por aqui?$"

SilphCo_2F_Text_Grunt2Defeat::
    .string "Eu vacilei!$"

SilphCo_2F_Text_Grunt2PostBattle::
    .string "A Silph S.A. será associada à\n"
    .string "Equipe Rocket!$"

