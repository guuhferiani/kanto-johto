.set LOCALID_FUGITIVE, 18

Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route11_OnResume
	.byte 0

Route11_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route11_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
	end

Route11_Text_DiglettsCave::
    .string "Caverna dos Diglett$"

Route11_EventScript_Hugo::
	trainerbattle_single REMATCHABLE_TRAINER_GAMBLER_HUGO_1, Route11_Text_HugoIntro, Route11_Text_HugoDefeat, Route11_EventScript_RegisterHugoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route11_EventScript_HugoRematch
	msgbox Route11_Text_HugoPostBattle, MSGBOX_DEFAULT
	release
	end

Route11_Text_HugoIntro::
    .string "Ganhar, perder ou empatar!$"

Route11_Text_HugoDefeat::
    .string "Ai, ai!\n"
    .string "As coisas não saíram como planejei!$"

Route11_Text_HugoPostBattle::
    .string "Pokémon é vida!\n"
    .string "E viver é apostar na sorte!$"

Route11_EventScript_RegisterHugoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_HugoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_GAMBLER_HUGO_1
	release
	end

Route11_Text_HugoRegister:
	.string "Ei, que tal uma revanche outra hora?\n"
	.string "Quem sabe eu dou mais sorte.$"

Route11_EventScript_HugoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_GAMBLER_HUGO_1, Route11_Text_HugoRematchIntro, Route11_Text_HugoDefeat
	msgbox Route11_Text_HugoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_HugoRematchIntro::
	.string "Ganhar, perder ou empatar!\n"
	.string "Agora é a nossa revanche!$"

Route11_Text_HugoRematchPostBattle::
	.string "Ai! Lá se foi a minha sequência.$"

Route11_EventScript_Jasper::
	trainerbattle_single TRAINER_GAMBLER_JASPER, Route11_Text_JasperIntro, Route11_Text_JasperDefeat
	msgbox Route11_Text_JasperPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_JasperIntro::
    .string "Competição!\n"
    .string "Nunca me canso disso!$"

Route11_Text_JasperDefeat::
    .string "Eu tive uma chance!$"

Route11_Text_JasperPostBattle::
    .string "Não dá para ser covarde no mundo\n"
    .string "dos Pokémon!$"

Route11_EventScript_Bernie::
	trainerbattle_single REMATCHABLE_TRAINER_ENGINEER_BERNIE_1, Route11_Text_BernieIntro, Route11_Text_BernieDefeat, Route11_EventScript_RegisterBernieAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route11_EventScript_BernieRematch
	msgbox Route11_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route11_Text_BernieIntro::
    .string "Cuidado com os fios desencapados!$"

Route11_Text_BernieDefeat::
    .string "Uau!\n"
    .string "Você é uma vela de ignição!$"

Route11_Text_BerniePostBattle::
    .string "Bem, é melhor eu voltar ao trabalho.$"

Route11_EventScript_RegisterBernieAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_ENGINEER_BERNIE_1
	release
	end

Route11_Text_BernieRegister:
	.string "Da próxima vez que eu fizer uma pausa,\n"
	.string "vamos ter uma revanche.$"

Route11_EventScript_BernieRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_ENGINEER_BERNIE_1, Route11_Text_BernieRematchIntro, Route11_Text_BernieDefeat
	msgbox Route11_Text_BernieRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_BernieRematchIntro::
	.string "Ufa! Hora do descanso.\n"
	.string "Que tal uma revanche?$"

Route11_Text_BernieRematchPostBattle::
	.string "Bem, de volta à lida.$"

Route11_EventScript_Braxton::
	trainerbattle_single TRAINER_ENGINEER_BRAXTON, Route11_Text_BraxtonIntro, Route11_Text_BraxtonDefeat
	msgbox Route11_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_BraxtonIntro::
    .string "Cuidado!\n"
    .string "Estou passando cabos por aqui!$"

Route11_Text_BraxtonDefeat::
    .string "Isso foi eletrizante!$"

Route11_Text_BraxtonPostBattle::
    .string "Espalhe a palavra para economizar energia!$"

Route11_EventScript_Eddie::
	trainerbattle_single TRAINER_YOUNGSTER_EDDIE, Route11_Text_EddieIntro, Route11_Text_EddieDefeat
	msgbox Route11_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_EddieIntro::
    .string "Vamos lá, mas sem trapaça!$"

Route11_Text_EddieDefeat::
    .string "Hã?\n"
    .string "Isso não tá certo!$"

Route11_Text_EddiePostBattle::
    .string "Dei o meu melhor.\n"
    .string "Não tenho arrependimentos.$"

Route11_EventScript_Dillon::
	trainerbattle_single TRAINER_YOUNGSTER_DILLON, Route11_Text_DillonIntro, Route11_Text_DillonDefeat
	msgbox Route11_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DillonIntro::
    .string "Acabei de me tornar um treinador.\n"
    .string "Mas acho que consigo vencer.$"

Route11_Text_DillonDefeat::
    .string "Meus Pokémon não conseguiram vencer…\n"
    .string "Será que eles não cresceram o bastante?$"

Route11_Text_DillonPostBattle::
    .string "E agora?\n"
    .string "Me deixe em paz!$"

Route11_EventScript_Yasu::
	trainerbattle_single TRAINER_YOUNGSTER_YASU, Route11_Text_YasuIntro, Route11_Text_YasuDefeat
	msgbox Route11_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_YasuIntro::
    .string "Sou o melhor da minha turma.\n"
    .string "Eu treino todas as manhãs.$"

Route11_Text_YasuDefeat::
    .string "Droga!\n"
    .string "Meus Pokémon precisam ficar mais fortes!$"

Route11_Text_YasuPostBattle::
    .string "Tem um Pokémon gordo que desce\n"
    .string "lá das montanhas.\p"
    .string "Aposto que ele deve ser bem forte\n"
    .string "se você conseguir pegá-lo.$"

Route11_EventScript_Dave::
	trainerbattle_single TRAINER_YOUNGSTER_DAVE, Route11_Text_DaveIntro, Route11_Text_DaveDefeat
	msgbox Route11_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DaveIntro::
    .string "Criei meus Pokémon com todo o cuidado.\n"
    .string "Eles devem estar prontos agora!$"

Route11_Text_DaveDefeat::
    .string "Tchauzinho!\n"
    .string "Muito obrigado e adeus!$"

Route11_Text_DavePostBattle::
    .string "Tsc…\n"
    .string "É melhor eu ir procurar outros mais fortes!$"

Route11_EventScript_Dirk::
	trainerbattle_single TRAINER_GAMBLER_DIRK, Route11_Text_DirkIntro, Route11_Text_DirkDefeat
	msgbox Route11_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DirkIntro::
    .string "Uahahah!\n"
    .string "Eu nunca perdi!$"

Route11_Text_DirkDefeat::
    .string "Minha primeira derrota!$"

Route11_Text_DirkPostBattle::
    .string "Você só teve sorte, foi só isso.$"

Route11_EventScript_Darian::
	trainerbattle_single TRAINER_GAMBLER_DARIAN, Route11_Text_DarianIntro, Route11_Text_DarianDefeat
	msgbox Route11_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DarianIntro::
    .string "Eu nunca venci antes…$"

Route11_Text_DarianDefeat::
    .string "Eu já previa isso…$"

Route11_Text_DarianPostBattle::
    .string "Eu não tive sorte, como sempre.$"


Route11_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL, 1
	release
	end

Route11_EventScript_ItemXDefend::
	finditem ITEM_X_DEFEND, 1
	release
	end

Route11_EventScript_ItemAwakening::
	finditem ITEM_AWAKENING, 1
	release
	end

Route11_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
