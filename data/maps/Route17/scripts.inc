Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route17_OnResume
	.byte 0

Route17_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route17_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route17_EventScript_ItemsNotice::
	msgbox Route17_Text_WatchOutForDiscardedItems, MSGBOX_SIGN
	end

Route17_Text_WatchOutForDiscardedItems::
    .string "É um aviso.\p"
    .string "Cuidado com itens descartados.$"

Route17_EventScript_TrainerTips1::
	msgbox Route17_Text_SameSpeciesGrowDifferentRates, MSGBOX_SIGN
	end

Route17_Text_SameSpeciesGrowDifferentRates::
    .string "Dicas para Treinadores:\p"
    .string "Cada Pokémon é único.\p"
    .string "Mesmo Pokémon da mesma espécie\n"
    .string "e nível crescem em ritmos diferentes.$"

Route17_EventScript_TrainerTips2::
	msgbox Route17_Text_PressBToStayInPlace, MSGBOX_SIGN
	end

Route17_Text_PressBToStayInPlace::
    .string "Dicas para Treinadores:\p"
    .string "Aperte o Botão B para ficar parado\n"
    .string "enquanto estiver na ladeira.$"

Route17_EventScript_RouteSign::
	msgbox Route17_Text_RouteSign, MSGBOX_SIGN
	end

Route17_Text_RouteSign::
    .string "Rota 17\n"
    .string "Celadon - Fuchsia$"

Route17_EventScript_BallsNotice::
	msgbox Route17_Text_DontThrowGameThrowBalls, MSGBOX_SIGN
	end

Route17_Text_DontThrowGameThrowBalls::
    .string "É um aviso!\p"
    .string "Não jogue a toalha, jogue\n"
    .string "Poké Bolas!$"

Route17_EventScript_CyclingRoadSign::
	msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route17_Text_CyclingRoadSign::
    .string "Rodovia dos Ciclistas\n"
    .string "Fim da ladeira!$"

Route17_EventScript_Billy::
	trainerbattle_single TRAINER_BIKER_BILLY, Route17_Text_BillyIntro, Route17_Text_BillyDefeat
	msgbox Route17_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BillyIntro::
    .string "Nós somos Motoqueiros!\n"
    .string "Nós dominamos as pistas, cara!$"

Route17_Text_BillyDefeat::
    .string "Fui defumado!$"

Route17_Text_BillyPostBattle::
    .string "Você está procurando aventura?$"

Route17_EventScript_Nikolas::
	trainerbattle_single TRAINER_BIKER_NIKOLAS, Route17_Text_NikolasIntro, Route17_Text_NikolasDefeat
	msgbox Route17_Text_NikolasPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_NikolasIntro::
    .string "Deixe o Voltorb te eletrocutar!$"

Route17_Text_NikolasDefeat::
    .string "Entrei em curto!$"

Route17_Text_NikolasPostBattle::
    .string "Eu peguei meu Voltorb na Usina\n"
    .string "de Energia abandonada.$"

Route17_EventScript_Jaxon::
	trainerbattle_single TRAINER_BIKER_JAXON, Route17_Text_JaxonIntro, Route17_Text_JaxonDefeat
	msgbox Route17_Text_JaxonPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_JaxonIntro::
    .string "Bela bike!\n"
    .string "Como ela se comporta?$"

Route17_Text_JaxonDefeat::
    .string "Droga!$"

Route17_Text_JaxonPostBattle::
    .string "A ladeira torna difícil guiar a bike.$"

Route17_EventScript_William::
	trainerbattle_single TRAINER_BIKER_WILLIAM, Route17_Text_WilliamIntro, Route17_Text_WilliamDefeat
	msgbox Route17_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_WilliamIntro::
    .string "Dê o fora, pirralho!\n"
    .string "Estou exausto!$"

Route17_Text_WilliamDefeat::
    .string "Está satisfeito agora?$"

Route17_Text_WilliamPostBattle::
    .string "Eu preciso dormir um pouco!$"

Route17_EventScript_Raul::
	trainerbattle_single TRAINER_CUE_BALL_RAUL, Route17_Text_RaulIntro, Route17_Text_RaulDefeat
	msgbox Route17_Text_RaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_RaulIntro::
    .string "Não dá para ficar rico rápido\n"
    .string "batalhando contra crianças.$"

Route17_Text_RaulDefeat::
    .string "Fundi o motor!$"

Route17_Text_RaulPostBattle::
    .string "Você pode achar coisas boas jogadas\n"
    .string "pela Rodovia dos Ciclistas.\p"
    .string "Dá para tirar uma boa grana catando\n"
    .string "e vendendo elas.$"

Route17_EventScript_Isaiah::
	trainerbattle_single TRAINER_CUE_BALL_ISAIAH, Route17_Text_IsaiahIntro, Route17_Text_IsaiahDefeat
	msgbox Route17_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_IsaiahIntro::
    .string "Tenho muito orgulho do meu físico, pivete.\n"
    .string "Pode vir!$"

Route17_Text_IsaiahDefeat::
    .string "Uau!$"

Route17_Text_IsaiahPostBattle::
    .string "Eu poderia te jogar longe só com\n"
    .string "uma barrigada!$"

Route17_EventScript_Zeek::
	trainerbattle_single TRAINER_CUE_BALL_ZEEK, Route17_Text_ZeekIntro, Route17_Text_ZeekDefeat
	msgbox Route17_Text_ZeekPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_ZeekIntro::
    .string "Eu subi o nível do meu Pokémon, mas\n"
    .string "ele não evolui. Por quê?$"

Route17_Text_ZeekDefeat::
    .string "Ora, seu…!$"

Route17_Text_ZeekPostBattle::
    .string "Talvez alguns Pokémon precisem de pedras\n"
    .string "elementais para evoluir.$"

Route17_EventScript_Jamal::
	trainerbattle_single TRAINER_CUE_BALL_JAMAL, Route17_Text_JamalIntro, Route17_Text_JamalDefeat
	msgbox Route17_Text_JamalPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_JamalIntro::
    .string "Preciso de um pouco de exercício!$"

Route17_Text_JamalDefeat::
    .string "Ufa!\n"
    .string "Belo treino!$"

Route17_Text_JamalPostBattle::
    .string "Tenho certeza de que perdi peso ali!$"

Route17_EventScript_Corey::
	trainerbattle_single TRAINER_CUE_BALL_COREY, Route17_Text_CoreyIntro, Route17_Text_CoreyDefeat
	msgbox Route17_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_CoreyIntro::
    .string "Seja um rebelde!$"

Route17_Text_CoreyDefeat::
    .string "Aaaargh!$"

Route17_Text_CoreyPostBattle::
    .string "Esteja pronto para lutar pelo que acredita!$"

Route17_EventScript_Virgil::
	trainerbattle_single TRAINER_BIKER_VIRGIL, Route17_Text_VirgilIntro, Route17_Text_VirgilDefeat
	msgbox Route17_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_VirgilIntro::
    .string "Você está indo para Fuchsia?$"

Route17_Text_VirgilDefeat::
    .string "Bati e queimei!$"

Route17_Text_VirgilPostBattle::
    .string "Eu adoro correr descendo a ladeira!$"

