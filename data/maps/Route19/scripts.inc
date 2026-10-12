.set LOCALID_FUGITIVE, 13

Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route19_OnResume
	.byte 0

Route19_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route19_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end

Route19_Text_RouteSign::
    .string "Rota Maritima 19\n"
    .string "Fuchsia City - Seafoam Islands$"

Route19_EventScript_Richie::
	trainerbattle_single REMATCHABLE_TRAINER_TUBER_RICHIE_1, Route19_Text_RichieIntro, Route19_Text_RichieDefeat, Route19_EventScript_RegisterRichieAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route19_EventScript_RichieRematch
	msgbox Route19_Text_RichiePostBattle, MSGBOX_DEFAULT
	release
	end

Route19_Text_RichieIntro::
    .string "Tenho que me exercitar e aquecer\n"
    .string "antes de entrar na agua para nadar.$"

Route19_Text_RichieDefeat::
    .string "Tudo aquecido!$"

Route19_Text_RichiePostBattle::
    .string "Valeu!\n"
    .string "Estou pronto para nadar.$"

Route19_EventScript_RegisterRichieAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route19_Text_RichieRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_TUBER_RICHIE_1
	release
	end

Route19_Text_RichieRegister:
	.string "Adoro vir a praia!\n"
	.string "Vou te ligar sempre que estiver aqui!$"

Route19_EventScript_RichieRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_TUBER_RICHIE_1, Route19_Text_RichieRematchIntro, Route19_Text_RichieDefeat
	msgbox Route19_Text_RichieRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_RichieRematchIntro::
	.string "Eba! Dia de praia!\n"
	.string "Vamos aquecer para nadar!$"

Route19_Text_RichieRematchPostBattle::
	.string "Comi demais no almoco antes de vir,\n"
	.string "entao ainda nao posso entrar na agua.$"

Route19_EventScript_Lizzie::
	trainerbattle_single TRAINER_TUBER_LIZZIE, Route19_Text_LizzieIntro, Route19_Text_LizzieDefeat
	msgbox Route19_Text_LizziePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LizzieIntro::
    .string "Espere! Va devagar!\n"
    .string "Voce vai ter um ataque cardiaco!$"

Route19_Text_LizzieDefeat::
    .string "Brrr!\n"
    .string "Que agua gelada!$"

Route19_Text_LizziePostBattle::
    .string "Cuidado com os Tentacool.\n"
    .string "A ferroada deles doi bastante.$"

Route19_EventScript_Matthew::
	trainerbattle_single TRAINER_SWIMMER_MALE_MATTHEW, Route19_Text_MatthewIntro, Route19_Text_MatthewDefeat
	msgbox Route19_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_MatthewIntro::
    .string "Eu amo nadar!\n"
    .string "E voce?$"

Route19_Text_MatthewDefeat::
    .string "Dei de barriga na agua!$"

Route19_Text_MatthewPostBattle::
    .string "Consigo vencer ate Pokemon marinhos\n"
    .string "na natacao.$"

Route19_EventScript_Douglas::
	trainerbattle_single TRAINER_SWIMMER_MALE_DOUGLAS, Route19_Text_DouglasIntro, Route19_Text_DouglasDefeat
	msgbox Route19_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_DouglasIntro::
    .string "O que ha alem do horizonte?$"

Route19_Text_DouglasDefeat::
    .string "Glub!$"

Route19_Text_DouglasPostBattle::
    .string "Consigo ver umas ilhas logo ali\n"
    .string "adiante!$"

Route19_EventScript_David::
	trainerbattle_single TRAINER_SWIMMER_MALE_DAVID, Route19_Text_DavidIntro, Route19_Text_DavidDefeat
	msgbox Route19_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_DavidIntro::
    .string "Tentei mergulhar para achar Pokemon,\n"
    .string "mas nao deu em nada.$"

Route19_Text_DavidDefeat::
    .string "Socorro!$"

Route19_Text_DavidPostBattle::
    .string "Acho que o jeito e pescar para achar\n"
    .string "Pokemon marinhos.$"

Route19_EventScript_Tony::
	trainerbattle_single TRAINER_SWIMMER_MALE_TONY, Route19_Text_TonyIntro, Route19_Text_TonyDefeat
	msgbox Route19_Text_TonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_TonyIntro::
    .string "Eu olho para o mar para esquecer todas\n"
    .string "as coisas ruins que aconteceram.$"

Route19_Text_TonyDefeat::
    .string "Uau!\n"
    .string "Que traumatico!$"

Route19_Text_TonyPostBattle::
    .string "Estou olhando para o mar para esquecer\n"
    .string "a coisa ruim que aconteceu!$"

Route19_EventScript_Axle::
	trainerbattle_single TRAINER_SWIMMER_MALE_AXLE, Route19_Text_AxleIntro, Route19_Text_AxleDefeat
	msgbox Route19_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AxleIntro::
    .string "Ahoy!\n"
    .string "Estas aguas sao traiçoeiras!$"

Route19_Text_AxleDefeat::
    .string "Ui!\n"
    .string "Perigoso!$"

Route19_Text_AxlePostBattle::
    .string "M-minhas pernas! Deu caimbra!\n"
    .string "Glub, glub...$"

Route19_EventScript_Anya::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ANYA, Route19_Text_AnyaIntro, Route19_Text_AnyaDefeat
	msgbox Route19_Text_AnyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AnyaIntro::
    .string "Ah, adorei a sua montaria!\n"
    .string "Posso ficar com ela se vencer?$"

Route19_Text_AnyaDefeat::
    .string "Ah! Eu perdi!$"

Route19_Text_AnyaPostBattle::
    .string "Ainda falta muito ate as Seafoam\n"
    .string "Islands...\p"
    .string "Eu queria voltar para Fuchsia...$"

Route19_EventScript_Alice::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ALICE, Route19_Text_AliceIntro, Route19_Text_AliceDefeat
	msgbox Route19_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AliceIntro::
    .string "Nadar e otimo!\n"
    .string "Queimaduras de sol nao sao!$"

Route19_Text_AliceDefeat::
    .string "Que choque!$"

Route19_Text_AlicePostBattle::
    .string "Meu namorado queria nadar ate as\n"
    .string "Seafoam Islands.$"

Route19_EventScript_Connie::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_CONNIE, Route19_Text_ConnieIntro, Route19_Text_ConnieDefeat
	msgbox Route19_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_ConnieIntro::
    .string "Nadei ate aqui com meus amigos...\n"
    .string "Estou cansada...$"

Route19_Text_ConnieDefeat::
    .string "Estou exausta...$"

Route19_Text_ConniePostBattle::
    .string "Se eu fosse surfar num Pokemon pelo\n"
    .string "mar, queria um Lapras.\p"
    .string "Lapras e tao grande que acho que me\n"
    .string "manteria sequinha na agua.$"

Route19_EventScript_Lia::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LiaIntro, Route19_Text_LiaDefeat, Route19_Text_LiaNotEnoughMons
	msgbox Route19_Text_LiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LiaIntro::
    .string "Lia: Estou cuidando do meu irmao.\n"
    .string "Ele acabou de se tornar Treinador.$"

Route19_Text_LiaDefeat::
    .string "Lia: Nao trate o meu irmaozinho\n"
    .string "dessa forma!$"

Route19_Text_LiaPostBattle::
    .string "Lia: Voce tem um irmao mais novo?\p"
    .string "Espero que esteja ensinando todo tipo\n"
    .string "de coisas a ele.$"

Route19_Text_LiaNotEnoughMons::
    .string "Lia: Quero batalhar em dupla com\n"
    .string "o meu irmaozinho.\p"
    .string "Voce nao tem dois Pokemon?$"

Route19_EventScript_Luc::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LucIntro, Route19_Text_LucDefeat, Route19_Text_LucNotEnoughMons
	msgbox Route19_Text_LucPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LucIntro::
    .string "Luc: Minha irma me ensinou a nadar\n"
    .string "e a treinar Pokemon.$"

Route19_Text_LucDefeat::
    .string "Luc: Uau!\n"
    .string "Alguem mais forte que a minha irma!$"

Route19_Text_LucPostBattle::
    .string "Luc: Minha irma e forte e boazinha.\n"
    .string "Eu acho ela demais!$"

Route19_Text_LucNotEnoughMons::
    .string "Luc: Eu nao quero lutar se nao puder\n"
    .string "ser em dupla com a minha irma.\p"
    .string "Voce nao tem dois Pokemon?$"

Route19_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

