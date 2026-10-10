.set LOCALID_GRUNT1, 1
.set LOCALID_GRUNT2, 2
.set LOCALID_GRUNT3, 3
.set LOCALID_JESSIE, 4
.set LOCALID_JAMES,  5

PokemonTower_7F_MapScripts::
	.byte 0

PokemonTower_7F_EventScript_MrFuji::
    lock
    faceplayer
    setflag FLAG_HIDE_POKEMON_TOWER_FUJI
    clearflag FLAG_HIDE_POKEHOUSE_FUJI
    setflag FLAG_RESCUED_MR_FUJI
    msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe, MSGBOX_DEFAULT
    goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, PokemonTower_7F_EventScript_JessieJamesSecretBattle3
    goto PokemonTower_7F_EventScript_MrFujiExit
    release
    end

PokemonTower_7F_Text_MrFujiThankYouFollowMe::
    .string "Sr. Fuji: Hã?\n"
    .string "Você veio me salvar?\p"
    .string "Obrigado. Mas eu vim aqui por\n"
    .string "minha própria vontade.\p"
    .string "Vim para acalmar o espírito da\n"
    .string "mãe de Cubone.\p"
    .string "Acredito que o espírito de Marowak\n"
    .string "finalmente encontrou a paz.\p"
    .string "Agradeço imensamente pela sua nobre\n"
    .string "preocupação.\p"
    .string "Venha comigo até a minha casa, a\n"
    .string "Casa Pokémon, aos pés desta torre.$"

PokemonTower_7F_EventScript_MrFujiExit::
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	setvar VAR_POKEMON_TOWER_STATE, 3
	warp MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE, 4, 6
	waitstate
	release
	end

PokemonTower_7F_EventScript_JessieJamesSecretBattle3::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	clearflag FLAG_HIDE_POKEMON_TOWER_JESSIE_JAMES
	msgbox PokemonTower_7F_Text_HoldItKid, MSGBOX_AUTOCLOSE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	applymovement LOCALID_JESSIE, Movement_RocketDuoEnters
	applymovement LOCALID_JAMES, Movement_RocketDuoEnters
	waitmovement 4
	goto PokemonTower_7F_EventScript_JessieJamesBattle
	end

PokemonTower_7F_EventScript_JessieJamesBattle::
	trainerbattle_double TRAINER_POKEMON_TOWER_JESSIE_JAMES PokemonTower_7F_RocketDuoIntro, PokemonTower_7F_RocketDuoDefeat, Text_NeedTwoMons, PokemonTower_7F_EventScript_RocketDuoDefeated, NO_MUSIC
	end

PokemonTower_7F_Text_HoldItKid::
	.string "Jessie: Pare bem aí, pivete.$"

Movement_RocketDuoEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonTower_7F_RocketDuoIntro::
	.string "James: Nós viemos correndo desde Celadon\n"
	.string "para recuperar esses planos!\p"
	.string "Jessie: Você devia tê-los entregado à\n"
	.string "Polícia Internacional enquanto ainda\l"
	.string "tinha chance.\p"
	.string "James: Mas agora nós vamos pegá-los de volta!$"

PokemonTower_7F_RocketDuoDefeat::
    .string "Jessie: Seu fedelho!\n"
    .string "James: Você vai se arrepender disso!$"

PokemonTower_7F_EventScript_RocketDuoDefeated::
	msgbox PokemonTower_7F_Text_RocketDuoDefeated, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	fadescreen FADE_FROM_BLACK
	fadeinbgm 0
	msgbox PokemonTower_7F_Text_LetsGoToHouse, MSGBOX_AUTOCLOSE
	goto PokemonTower_7F_EventScript_MrFujiExit
	end

PokemonTower_7F_Text_RocketDuoDefeated::
    .string "Jessie: Eca! Sério? De novo?\p"
    .string "James: Parece que a nossa chance de\n"
    .string "recuperar os planos foi por água abaixo...\p"
    .string "Jessie: E você acha que eu não sei?\n"
    .string "Tanto faz, se esse pivete ainda não\l"
    .string "entregou os planos para a Polícia\l"
    .string "Internacional, significa que ainda temos\l"
    .string "tempo de ajudar na invasão de Saffron.\p"
    .string "Jessie & James: A Equipe Rocket está\n"
    .string "decolando de novoooo!$"

PokemonTower_7F_Text_LetsGoToHouse::
	.string "Sr. Fuji: Bem, isso certamente foi\n"
	.string "inesperado.\p"
	.string "Vamos voltar para a minha casa antes\n"
	.string "que mais Rockets apareçam...$"

PokemonTower_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_19, PokemonTower_7F_Text_Grunt1Intro, PokemonTower_7F_Text_Grunt1Defeat, PokemonTower_7F_EventScript_DefeatedGrunt1
	msgbox PokemonTower_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_EventScript_DefeatedGrunt1::
	msgbox PokemonTower_7F_Text_Grunt1PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitMid
	compare VAR_0x8004, 11
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitLeft
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitMid::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitMid
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitRight::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitLeft::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitLeft
	waitmovement 0
	playse SE_EXIT
	delay 25
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_Text_Grunt1Intro::
    .string "O que você quer?\n"
    .string "Por que está aqui?$"

PokemonTower_7F_Text_Grunt1Defeat::
    .string "Eu desisto!$"

PokemonTower_7F_Text_Grunt1PostBattle::
    .string "Não vou esquecer disso!$"

PokemonTower_7F_EventScript_RemoveGrunt1::
	removeobject LOCALID_GRUNT1
	release
	end

PokemonTower_7F_Movement_Grunt1ExitMid::
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PokemonTower_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_20, PokemonTower_7F_Text_Grunt2Intro, PokemonTower_7F_Text_Grunt2Defeat, PokemonTower_7F_EventScript_DefeatedGrunt2
	msgbox PokemonTower_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_Text_Grunt2Intro::
    .string "Esse velho marchou direto até o\n"
    .string "nosso Esconderijo.\p"
    .string "Depois, começou a reclamar que a\n"
    .string "Equipe Rocket maltrata os Pokémon.\p"
    .string "Então, estamos apenas conversando\n"
    .string "como adultos.$"

PokemonTower_7F_Text_Grunt2Defeat::
    .string "Por favor!\n"
    .string "Chega!$"

PokemonTower_7F_Text_Grunt2PostBattle::
    .string "Pokémon só servem para ganhar dinheiro.\n"
    .string "Por que não usá-los?\p"
    .string "Fique fora dos nossos negócios!$"

PokemonTower_7F_EventScript_DefeatedGrunt2::
	msgbox PokemonTower_7F_Text_Grunt2PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitLeft
	compare VAR_0x8004, 13
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitRight
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitLeft::
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitRight::
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_RemoveGrunt2::
	removeobject LOCALID_GRUNT2
	release
	end

PokemonTower_7F_Movement_Grunt2ExitLeft::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2ExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_21, PokemonTower_7F_Text_Grunt3Intro, PokemonTower_7F_Text_Grunt3Defeat, PokemonTower_7F_EventScript_DefeatedGrunt3
	msgbox PokemonTower_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_Text_Grunt3Intro::
    .string "Você não vai salvar ninguém, pirralho!$"

PokemonTower_7F_Text_Grunt3Defeat::
    .string "Não lute contra nós, os Rockets!$"

PokemonTower_7F_Text_Grunt3PostBattle::
    .string "Você não vai se safar dessa!$"

PokemonTower_7F_EventScript_DefeatedGrunt3::
	msgbox PokemonTower_7F_Text_Grunt3PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitLeft
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitRight::
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitLeft::
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_RemoveGrunt3::
	removeobject LOCALID_GRUNT3
	release
	end

PokemonTower_7F_EventScript_Unused::
	release
	end

PokemonTower_7F_Movement_Grunt3ExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3ExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
