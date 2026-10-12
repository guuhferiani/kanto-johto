SilphCo_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	release
	end

SilphCo_5F_EventScript_ItemTM01::
	finditem ITEM_TM01, 1
	release
	end

SilphCo_5F_EventScript_ItemCardKey::
	finditem ITEM_CARD_KEY, 1
	release
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE, SilphCo_5F_EventScript_WorkerMRocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsBack::
	msgbox SilphCo_5F_Text_WorkerMRocketsBack
	release
	end

SilphCo_5F_Text_WorkerMRocketsBack:
	.string "A Equipe Rocket está lutando pelo\n"
    .string "controle do prédio.\p"
    .string "Você vai nos ajudar de novo?$"

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
    .string "A Equipe Rocket está em polvorosa\n"
    .string "por causa de um invasor.\p"
    .string "É você, não é?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
    .string "A Equipe Rocket fugiu!\n"
    .string "Você é o nosso herói! Obrigado!$"

SilphCo_5F_Text_Grunt1Intro::
    .string "Ouvi falar que um pirralho estava\n"
    .string "perambulando por aqui.$"

SilphCo_5F_Text_Grunt1Defeat::
    .string "Bum!$"

SilphCo_5F_Text_Grunt1PostBattle::
    .string "Não é nada esperto comprar briga com\n"
    .string "a Equipe Rocket!$"

SilphCo_5F_Text_BeauIntro::
    .string "Estudamos a tecnologia de Pokébolas\n"
    .string "neste andar.$"

SilphCo_5F_Text_BeauDefeat::
    .string "Droga!\n"
    .string "Que droga!$"

SilphCo_5F_Text_BeauPostBattle::
    .string "Trabalhamos na Pokébola definitiva,\n"
    .string "capaz de capturar qualquer coisa.$"

SilphCo_5F_Text_DaltonIntro::
    .string "O quêêê?\p"
    .string "Não deveria haver nenhuma criança\n"
    .string "aqui!$"

SilphCo_5F_Text_DaltonDefeat::
    .string "Ai, céus!$"

SilphCo_5F_Text_DaltonPostBattle::
    .string "Você está apenas no 5º andar.\n"
    .string "Ainda falta muito até o meu Chefe!$"

SilphCo_5F_Text_Grunt2Intro::
    .string "Tenha mais respeito pela Equipe Rocket!$"

SilphCo_5F_Text_Grunt2Defeat::
    .string "Cof...\n"
    .string "Cof...$"

SilphCo_5F_Text_Grunt2PostBattle::
    .string "O que me lembra:\p"
    .string "Koffing evolui para Weezing!$"

SilphCo_5F_Text_PorygonFirstVRMon::
    .string "É um Relatório Pokémon!\p"
    .string "Em casos raros, alguns Pokémon\n"
    .string "podem ter habilidades diferentes.$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
    .string "É um Relatório Pokémon!\p"
    .string "Mais de 350 golpes Pokémon foram\n"
    .string "confirmados.$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
    .string "É um Relatório Pokémon!\p"
    .string "Foi confirmado que certos Pokémon\n"
    .string "evoluem quando são trocados.$"

SilphCo_5F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "5º Andar$"

SilphCo_5F_EventScript_Scientist::
	lock
	faceplayer
	msgbox SilphCo_5F_Text_RocketBossLookingForStrongMons
	release
	end

SilphCo_5F_Text_RocketBossLookingForStrongMons::
    .string "Aqueles bandidos que tomaram nosso\n"
    .string "prédio...\p"
    .string "O Chefe deles disse estar procurando\n"
    .string "por Pokémon fortes.\p"
    .string "Espero que nosso Presidente tenha\n"
    .string "conseguido evitar problemas...$"
