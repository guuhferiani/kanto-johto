.set LOCALID_FUGITIVE, 9

Route21_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_South_OnResume
	.byte 0

Route21_South_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_EventScript_Johan::
	trainerbattle_single REMATCHABLE_TRAINER_JUGGLER_JOHAN_1, Route21_South_Text_JohanIntro, Route21_South_Text_JohanDefeat, Route21_South_EventScript_RegisterJohanAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route21_South_EventScript_JohanRematch
	msgbox Route21_South_Text_JohanPostBattle
	release
	end

Route21_South_Text_JohanIntro::
    .string "Olhe para mim fazendo malabarismo\n"
    .string "com estas Poke Bolas!$"

Route21_South_Text_JohanDefeat::
    .string "Derrubei minhas bolas...$"
	
Route21_South_Text_JohanDefeat2::
    .string "Derrubei minhas bolas... de novo.$"

Route21_South_Text_JohanPostBattle::
    .string "Por que os outros treinadores podem\n"
    .string "voltar ao Centro Pokemon quando perdem,\l"
	.string "mas eu fico preso aqui?\p"
	.string "Queria ter trago um Ether na mochila\n"
	.string "para o meu Abra. Vivendo e aprendendo.$"

Route21_South_EventScript_RegisterJohanAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_South_Text_JohanRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_JUGGLER_JOHAN_1
	release
	end

Route21_South_Text_JohanRegister:
	.string "Eu me teletransportei para ca por impulso,\n"
	.string "mas meu Abra ficou sem PP.\p"
	.string "Posso te ligar pedindo carona depois?$"

Route21_South_EventScript_JohanRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_JUGGLER_JOHAN_1, Route21_South_Text_JohanRematchIntro, Route21_South_Text_JohanDefeat2
	msgbox Route21_South_Text_JohanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JohanRematchIntro::
	.string "Estive praticando meu malabarismo!$"

Route21_South_Text_JohanRematchPostBattle::
	.string "Se eu nao tivesse saido da escola,\n"
	.string "poderia estar trabalhando na Silph!\p"
	.string "Mas sera que seria feliz se nao\n"
	.string "estivesse aqui fazendo malabarismo?\p"
	.string "Quem sabe...$"


Route21_South_EventScript_Claude::
	trainerbattle_single TRAINER_FISHERMAN_CLAUDE, Route21_South_Text_ClaudeIntro, Route21_South_Text_ClaudeDefeat
	msgbox Route21_South_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_ClaudeIntro::
	.string "Ei, nao assuste os peixes!$"

Route21_South_Text_ClaudeDefeat::
	.string "Desculpe! E que estou tao frustrado\n"
	.string "por nao pescar nada.$"

Route21_South_Text_ClaudePostBattle::
	.string "Nossa, nao peguei nada ate agora.\n"
	.string "Sera que este lugar e uma piscina\l"
	.string "gigante ou algo assim?$"

Route21_South_EventScript_Nolan::
	trainerbattle_single TRAINER_FISHERMAN_NOLAN, Route21_South_Text_NolanIntro, Route21_South_Text_NolanDefeat
	msgbox Route21_South_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_NolanIntro::
	.string "Me faca companhia ate um peixe morder.$"

Route21_South_Text_NolanDefeat::
	.string "Isso ajudou a passar o tempo.$"

Route21_South_Text_NolanPostBattle::
	.string "Espere!\n"
	.string "Um peixe mordeu a isca! Uhuu!$"

Route21_South_EventScript_Jack::
	trainerbattle_single TRAINER_SWIMMER_MALE_JACK, Route21_South_Text_JackIntro, Route21_South_Text_JackDefeat
	msgbox Route21_South_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JackIntro::
	.string "Capturei meus Pokemon no mar.$"

Route21_South_Text_JackDefeat::
	.string "Mergulhador!!\n"
	.string "Ao mar!!$"

Route21_South_Text_JackPostBattle::
	.string "Onde voce capturou seus Pokemon?$"

Route21_South_EventScript_Jerome::
	trainerbattle_single TRAINER_SWIMMER_MALE_JEROME, Route21_South_Text_JeromeIntro, Route21_South_Text_JeromeDefeat
	msgbox Route21_South_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JeromeIntro::
	.string "Agora mesmo estou disputando um\n"
	.string "triatlo.$"

Route21_South_Text_JeromeDefeat::
	.string "Arf...\n"
	.string "Arf... Arf...$"

Route21_South_Text_JeromePostBattle::
	.string "Estou exausto! Mas ainda faltam a corrida\n"
	.string "de bicicleta e a maratona!$"

Route21_South_EventScript_Roland::
	trainerbattle_single TRAINER_SWIMMER_MALE_ROLAND, Route21_South_Text_RolandIntro, Route21_South_Text_RolandDefeat
	msgbox Route21_South_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_RolandIntro::
	.string "Ahh!\n"
	.string "Sinta o sol e a brisa!$"

Route21_South_Text_RolandDefeat::
	.string "Ai!\n"
	.string "Eu perdi!$"

Route21_South_Text_RolandPostBattle::
	.string "Fiquei torrado como um camarao!$"

Route21S_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
