SilphCo_8F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_ItemIron::
	finditem ITEM_IRON, 1
	release
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_8F_EventScript_WorkerMRocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsBack::
	msgbox SilphCo_8F_Text_WorkerMRocketsBack
	release
	end

SilphCo_8F_Text_WorkerMRocketsBack:
	.string "Nós superamos isso antes.\n"
	.string "Superaremos isso novamente.$"

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
    .string "Será que a Silph está arruinada...?$"

SilphCo_8F_Text_ThanksForSavingUs::
    .string "Obrigado por nos salvar!$"

SilphCo_8F_Text_Grunt1Intro::
    .string "Você não passa daqui!$"

SilphCo_8F_Text_Grunt1Defeat::
    .string "Faltou garra!$"

SilphCo_8F_Text_Grunt1PostBattle::
    .string "Se você não der meia-volta...\n"
    .string "vou chamar reforços!$"

SilphCo_8F_Text_ParkerIntro::
    .string "Você está nos causando problemas!$"

SilphCo_8F_Text_ParkerDefeat::
    .string "Hã?\n"
    .string "Eu perdi?$"

SilphCo_8F_Text_ParkerPostBattle::
    .string "E então, o que achou do labirinto\n"
    .string "do prédio da Silph?$"

SilphCo_8F_Text_Grunt2Intro::
    .string "Eu sou um dos quatro Irmãos Rocket!$"

SilphCo_8F_Text_Grunt2Defeat::
    .string "Uau!\n"
    .string "Ah, meus irmãos!$"

SilphCo_8F_Text_Grunt2PostBattle::
    .string "Deixo você por conta dos meus irmãos.$"

SilphCo_8F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "8º Andar$"

SilphCo_8F_EventScript_Scientist::
	lock
	faceplayer
	msgbox SilphCo_8F_Text_ToRocketBossMonsAreTools
	release
	end

SilphCo_8F_Text_ToRocketBossMonsAreTools::
    .string "O Chefe da Equipe Rocket é terrível\n"
    .string "e cruel!\p"
    .string "Para ele, Pokémon são apenas ferramentas\n"
    .string "a serem usadas.\p"
    .string "O que acontecerá se aquele tirano\n"
    .string "tomar posse da nossa empresa...$"
