SilphCo_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION, 1
	release
	end

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_3F_EventScript_WorkerMInvasion
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMInvasion::
	msgbox SilphCo_3F_Text_WorkerMInvasion, MSGBOX_NPC
	release
	end

SilphCo_3F_Text_WorkerMInvasion:
	.string "Bem quando achei que as coisas\n"
	.string "estavam se acalmando por aqui,\l"
	.string "os Rockets invadem novamente bem\l"
	.string "na hora do meu almoço.$"

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
    .string "Eu trabalho para a Silph S.A.\n"
    .string "O que é que eu posso fazer?$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
    .string "{PLAYER}!\n"
    .string "Você e seus Pokémon nos salvaram!$"

SilphCo_3F_Text_GruntIntro::
    .string "Pare de nos atrapalhar, pirralho!$"

SilphCo_3F_Text_GruntDefeat::
    .string "Eu me rendo!$"

SilphCo_3F_Text_GruntPostBattle::
    .string "Uma dica? Você pode abrir portas\n"
    .string "com o Cartão-Chave!$"

SilphCo_3F_Text_JoseIntro::
    .string "Eu apoio a Equipe Rocket muito mais\n"
    .string "do que a Silph S.A.!$"

SilphCo_3F_Text_JoseDefeat::
    .string "Você me pegou de jeito!$"

SilphCo_3F_Text_JosePostBattle::
    .string "Humph...\p"
    .string "A Equipe Rocket disse que se eu os\n"
    .string "ajudasse, me deixariam estudar Pokémon.$"

SilphCo_3F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "3º Andar$"

SilphCo_3F_EventScript_PostgameGrunt4::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_4, SilphCo_3F_Text_PostgameGrunt4Intro, SilphCo_3F_Text_PostgameGrunt4Defeat
	msgbox SilphCo_3F_Text_PostgameGrunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_PostgameGrunt4Intro::
    .string "Rockets nunca desistem!$"

SilphCo_3F_Text_PostgameGrunt4Defeat::
    .string "Já éramos!$"

SilphCo_3F_Text_PostgameGrunt4PostBattle::
    .string "Esta era a nossa última chance.\p"
    .string "O Chefe fez o Presidente da Silph\n"
    .string "de refém novamente.\p"
    .string "Não tem volta depois disso!$"
