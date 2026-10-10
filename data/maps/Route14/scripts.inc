.set LOCALID_FUGITIVE, 17

Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route14_OnResume
	.byte 0

Route14_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route14_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route14_EventScript_RouteSign::
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end

Route14_Text_RouteSign::
    .string "Rota 14\n"
    .string "Oeste para Cidade de Fuchsia$"

Route14_EventScript_Malik::
	trainerbattle_single TRAINER_BIKER_MALIK, Route14_Text_MalikIntro, Route14_Text_MalikDefeat
	msgbox Route14_Text_MalikPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MalikIntro::
    .string "Batalha Pokémon?\n"
    .string "Demais! Vamos brigar!$"

Route14_Text_MalikDefeat::
    .string "Fui varrido!$"

Route14_Text_MalikPostBattle::
    .string "Você sabe quem ganharia se fôssemos\n"
    .string "só você e eu no mano a mano!$"

Route14_EventScript_Lukas::
	trainerbattle_single TRAINER_BIKER_LUKAS, Route14_Text_LukasIntro, Route14_Text_LukasDefeat
	msgbox Route14_Text_LukasPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_LukasIntro::
    .string "Vamos, vamos.\n"
    .string "Bora, bora, bora!$"

Route14_Text_LukasDefeat::
    .string "Argh!\n"
    .string "Perdi! Dá o fora!$"

Route14_Text_LukasPostBattle::
    .string "O que foi, o que foi, o que foi?\n"
    .string "O que você ainda quer?$"


Route14_EventScript_Isaac::
	trainerbattle_single TRAINER_BIKER_ISAAC, Route14_Text_IsaacIntro, Route14_Text_IsaacDefeat
	msgbox Route14_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_IsaacIntro::
    .string "Preciso passar o tempo.\n"
    .string "Cale a boca e batalhe.$"

Route14_Text_IsaacDefeat::
    .string "O quê?\n"
    .string "Você!?$"

Route14_Text_IsaacPostBattle::
    .string "Treinar Pokémon é um saco, cara.$"

Route14_EventScript_Gerald::
	trainerbattle_single TRAINER_BIKER_GERALD, Route14_Text_GeraldIntro, Route14_Text_GeraldDefeat
	msgbox Route14_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_GeraldIntro::
    .string "Nós pilotamos por aqui por causa dos\n"
    .string "espaços bem abertos.$"

Route14_Text_GeraldDefeat::
    .string "Capotei!$"

Route14_Text_GeraldPostBattle::
    .string "É maneiro que você tenha deixado seus\n"
    .string "Pokémon tão fortes.\p"
    .string "O poder tem razão!\n"
    .string "E você sabe disso!$"

Route14_EventScript_Donald::
	trainerbattle_single TRAINER_BIRD_KEEPER_DONALD, Route14_Text_DonaldIntro, Route14_Text_DonaldDefeat
	msgbox Route14_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_DonaldIntro::
    .string "Você já ouviu a lenda das\n"
    .string "miragens aladas?$"

Route14_Text_DonaldDefeat::
    .string "Por quê?\n"
    .string "Por que eu perdi?$"

Route14_Text_DonaldPostBattle::
    .string "Bem, as miragens aladas são os\n"
    .string "Pokémon pássaros lendários.\p"
    .string "Há três deles: Articuno,\n"
    .string "Zapdos e Moltres.$"

Route14_EventScript_Benny::
	trainerbattle_single TRAINER_BIRD_KEEPER_BENNY, Route14_Text_BennyIntro, Route14_Text_BennyDefeat
	msgbox Route14_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_BennyIntro::
    .string "Não estou muito a fim, mas tudo bem.\n"
    .string "Vamos nessa!$"

Route14_Text_BennyDefeat::
    .string "Eu já sabia!$"

Route14_Text_BennyPostBattle::
    .string "Ganhar, perder… Não faz diferença\n"
    .string "sob este céu imenso.$"

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_BIRD_KEEPER_CARTER, Route14_Text_CarterIntro, Route14_Text_CarterDefeat
	msgbox Route14_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_CarterIntro::
    .string "Você precisa usar MTs para ensinar\n"
    .string "bons golpes aos seus Pokémon.$"

Route14_Text_CarterDefeat::
    .string "Ainda não estou bom o bastante.$"

Route14_Text_CarterPostBattle::
    .string "Você tem alguns MOs, certo? Pokémon\n"
    .string "não conseguem esquecer esses golpes fácil.$"


Route14_EventScript_Mitch::
	trainerbattle_single TRAINER_BIRD_KEEPER_MITCH, Route14_Text_MitchIntro, Route14_Text_MitchDefeat
	msgbox Route14_Text_MitchPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MitchIntro::
    .string "Meus Pokémon pássaros devem estar\n"
    .string "prontos para a batalha.$"

Route14_Text_MitchDefeat::
    .string "Ainda não estão prontos!$"

Route14_Text_MitchPostBattle::
    .string "Meus Pokémon pássaros precisam aprender\n"
    .string "golpes melhores.$"

Route14_EventScript_Beck::
	trainerbattle_single TRAINER_BIRD_KEEPER_BECK, Route14_Text_BeckIntro, Route14_Text_BeckDefeat
	msgbox Route14_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_BeckIntro::
    .string "Eles vendem MTs no Shopping\n"
    .string "de Celadon.\p"
    .string "MTs não são tão raros, mas poucas\n"
    .string "pessoas têm MOs.$"

Route14_Text_BeckDefeat::
    .string "Ah, que droga!$"

Route14_Text_BeckPostBattle::
    .string "Tente ensinar a um Pokémon um golpe\n"
    .string "do mesmo tipo que ele.\p"
    .string "Aparentemente, isso aumenta a força\n"
    .string "do golpe.$"


Route14_EventScript_Marlon::
	trainerbattle_single TRAINER_BIRD_KEEPER_MARLON, Route14_Text_MarlonIntro, Route14_Text_MarlonDefeat
	msgbox Route14_Text_MarlonPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MarlonIntro::
    .string "Você ensinou seus Pokémon pássaros\n"
    .string "a Voar?\p"
    .string "Você poderá planar com eles pelos\n"
    .string "céus!$"

Route14_Text_MarlonDefeat::
    .string "Derrubado em chamas!$"

Route14_Text_MarlonPostBattle::
    .string "Pokémon pássaros são meu único e verdadeiro\n"
    .string "amor. Não quero criar mais nada.$"


Route14_EventScript_Kiri::
	trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_KiriIntro, Route14_Text_KiriDefeat, Route14_Text_KiriNotEnoughMons
	msgbox Route14_Text_KiriPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_KiriIntro::
    .string "Kiri: Jan, vamos nos esforçar muito,\n"
    .string "muito juntas.$"

Route14_Text_KiriDefeat::
    .string "Kiri: Snif…\n"
    .string "Nós perdemos, né?$"

Route14_Text_KiriPostBattle::
    .string "Kiri: Será que perdemos por minha causa?$"

Route14_Text_KiriNotEnoughMons::
    .string "Kiri: Nós podemos batalhar se você tiver\n"
    .string "dois Pokémon.$"


Route14_EventScript_Jan::
	trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_JanIntro, Route14_Text_JanDefeat, Route14_Text_JanNotEnoughMons
	msgbox Route14_Text_JanPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_JanIntro::
    .string "Jan: Kiri, lá vamos nós!\n"
    .string "Temos que dar o nosso melhor!$"

Route14_Text_JanDefeat::
    .string "Jan: Eeeeh!\n"
    .string "Não vale!$"

Route14_Text_JanPostBattle::
    .string "Jan: Kiri, não chora!\n"
    .string "Nós vamos nos esforçar mais da próxima vez.$"

Route14_Text_JanNotEnoughMons::
    .string "Jan: Você quer batalhar?\n"
    .string "Você não tem Pokémon suficientes.$"

Route14_EventScript_BigRoot::
    finditem ITEM_BIG_ROOT, 1
    release
    end

Route14_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

Route14_EventScript_HexManiacCamran::
	trainerbattle_single TRAINER_HEXMANIAC_CAMRAN, Route14_Text_CamranIntro, Route14_Text_CamranDefeat
	msgbox Route14_Text_CamranPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

Route14_Text_CamranIntro:
	.string "Não pise na Ração de Gato!\p"
    .string "Pare com isso!\n"
	.string "Não queremos germes na Ração de Gato!$"

Route14_Text_CamranDefeat:
	.string "… da próxima vez não machuque meus gatinhos… suspiro$"

Route14_Text_CamranPostBattle:
	.string "Esses gatinhos significam tanto para mim…\p"
    .string "Não consigo viver sem eles.$"

