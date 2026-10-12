SilphCo_6F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP, 1
	release
	end

SilphCo_6F_EventScript_ItemXSpecial::
	finditem ITEM_X_SPECIAL, 1
	release
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_6F_EventScript_WorkerM2RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsBack::
	msgbox SilphCo_6F_Text_WorkerM2RocketsBack
	release
	end

SilphCo_6F_Text_WorkerM2RocketsBack:
	.string "Não posso reclamar da invasão.\p"
	.string "Você está aqui e uma reunião\n"
	.string "que eu temia foi cancelada.$"

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_6F_EventScript_WorkerM3RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsBack::
	msgbox SilphCo_6F_Text_WorkerM3RocketsBack
	release
	end

SilphCo_6F_Text_WorkerM3RocketsBack:
	.string "Esses Rockets não cansam.\n"
	.string "Mas essa folga extra é ótima.$"

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_6F_EventScript_WorkerM1RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsBack::
	msgbox SilphCo_6F_Text_WorkerM1RocketsBack
	release
	end

SilphCo_6F_Text_WorkerM1RocketsBack:
	.string "Ai não, o que eu vou fazer?\n"
	.string "Eu prometi que seria corajoso!$"

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_6F_EventScript_WorkerF1RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsBack::
	msgbox SilphCo_6F_Text_WorkerF1RocketsBack
	release
	end

SilphCo_6F_Text_WorkerF1RocketsBack:
	.string "Os homens estariam perdidos sem nós.$"

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_6F_EventScript_WorkerF2RocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsBack::
	msgbox SilphCo_6F_Text_WorkerF2RocketsBack
	release
	end

SilphCo_6F_Text_WorkerF2RocketsBack:
	.string "Você é meu herói, por favor venha\n"
	.string "em nosso socorro mais uma vez!$"

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
    .string "Os Rockets vieram e tomaram\n"
    .string "o prédio!$"

SilphCo_6F_Text_BetterGetBackToWork::
    .string "Bem, é melhor voltar ao trabalho.$"

SilphCo_6F_Text_HelpMePlease::
    .string "Ai, meu Deus, ai, meu Deus.\n"
    .string "Me ajude, por favor!$"

SilphCo_6F_Text_WeGotEngaged::
    .string "Ficamos noivos.\n"
    .string "Heheh!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
    .string "Aquele homem ao meu lado...\n"
    .string "Ele é tão covarde!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
    .string "Ele é tão indefeso, precisava de\n"
    .string "alguém como eu para cuidar dele.$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
    .string "A Equipe Rocket está tentando\n"
    .string "conquistar o mundo com Pokémon.$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
    .string "A Equipe Rocket fugiu, e é tudo\n"
    .string "graças a você!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
    .string "Eles devem ter invadido a Silph por\n"
    .string "causa de nossos produtos Pokémon.$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
    .string "Venha trabalhar na Silph quando\n"
    .string "você crescer.$"

SilphCo_6F_Text_Grunt1Intro::
    .string "Eu sou um dos quatro Irmãos Rocket!$"

SilphCo_6F_Text_Grunt1Defeat::
    .string "Apagou a chama!$"

SilphCo_6F_Text_Grunt1PostBattle::
    .string "Não importa!\n"
    .string "Meus irmãos me vingarão!$"

SilphCo_6F_Text_TaylorIntro::
    .string "Aquele Presidente imprestável!\p"
    .string "Bem feito para ele por me transferir\n"
    .string "para a filial de Unova!\p"
    .string "É por isso que a Equipe Rocket nos\n"
    .string "atacou, tenho certeza!$"

SilphCo_6F_Text_TaylorDefeat::
    .string "Droga!$"

SilphCo_6F_Text_TaylorPostBattle::
    .string "Filial de Unova?\n"
    .string "Fica do outro lado do mundo!$"

SilphCo_6F_Text_Grunt2Intro::
    .string "Você ousa desafiar a Equipe Rocket?$"

SilphCo_6F_Text_Grunt2Defeat::
    .string "Seu traidor!$"

SilphCo_6F_Text_Grunt2PostBattle::
    .string "Se você defende a justiça, você\n"
    .string "trai a nós, os vilões!$"

SilphCo_6F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "6º Andar$"
