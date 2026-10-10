.set LOCALID_FUGITIVE, 16

Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route6_OnResume
	.byte 0

Route6_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route6_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route6_EventScript_Keigo::
	trainerbattle_single REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1, Route6_Text_KeigoIntro, Route6_Text_KeigoDefeat, Route6_EventScript_RegisterKeigoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route6_EventScript_KeigoRematch
	msgbox Route6_Text_KeigoPostBattle, MSGBOX_DEFAULT
	release
	end

Route6_Text_KeigoIntro::
    .string "Não há muitos insetos por aqui.$"

Route6_Text_KeigoDefeat::
    .string "Não!\n"
    .string "Tá de brincadeira!$"

Route6_Text_KeigoPostBattle::
    .string "Eu gosto de insetos, então vou voltar\n"
    .string "para a Floresta de Viridian.$"

Route6_EventScript_RegisterKeigoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_KeigoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1
	release
	end

Route6_Text_KeigoRegister:
	.string "Vou provar que os Pokémon Inseto são\n"
	.string "os mais fortes. Vamos ter uma revanche\l"
	.string "qualquer dia!$"

Route6_EventScript_KeigoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1, Route6_Text_KeigoRematchIntro, Route6_Text_KeigoDefeat
	msgbox Route6_Text_KeigoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_KeigoRematchIntro::
	.string "Estou tentando achar algo bom que\n"
	.string "não seja um Pokémon Inseto, mas…$"

Route6_Text_KeigoRematchPostBattle::
	.string "Achei que devia variar um pouco,\n"
	.string "mas sempre vou amar Pokémon Inseto!$"

Route6_EventScript_Ricky::
	trainerbattle_single TRAINER_CAMPER_RICKY, Route6_Text_RickyIntro, Route6_Text_RickyDefeat
	msgbox Route6_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_RickyIntro::
    .string "Quem está aí?\n"
    .string "Parem de escutar a nossa conversa!$"

Route6_Text_RickyDefeat::
    .string "Eu simplesmente não consigo vencer!$"

Route6_Text_RickyPostBattle::
    .string "Cochicho…\n"
    .string "Cochicho…$"

Route6_EventScript_Nancy::
	trainerbattle_single TRAINER_PICNICKER_NANCY, Route6_Text_NancyIntro, Route6_Text_NancyDefeat
	msgbox Route6_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_NancyIntro::
    .string "Com licença!\n"
    .string "Esta é uma conversa particular!$"

Route6_Text_NancyDefeat::
    .string "Ugh!\n"
    .string "Eu odeio perder.$"

Route6_Text_NancyPostBattle::
    .string "Cochicho…\n"
    .string "Cochicho…$"

Route6_EventScript_Elijah::
	trainerbattle_single TRAINER_BUG_CATCHER_ELIJAH, Route6_Text_ElijahIntro, Route6_Text_ElijahDefeat
	msgbox Route6_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_ElijahIntro::
    .string "Nunca te vi por aqui.\n"
    .string "Você é bom?$"

Route6_Text_ElijahDefeat::
    .string "Você é bom até demais!$"

Route6_Text_ElijahPostBattle::
    .string "Será que meus Pokémon são fracos?\n"
    .string "Ou eu é que sou ruim?\l"
    .string "O que você acha?$"

Route6_EventScript_Isabelle::
	trainerbattle_single TRAINER_PICNICKER_ISABELLE, Route6_Text_IsabelleIntro, Route6_Text_IsabelleDefeat
	msgbox Route6_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_IsabelleIntro::
    .string "Eu?\n"
    .string "Bem, está bem. Vamos batalhar!$"

Route6_Text_IsabelleDefeat::
    .string "As coisas não deram muito certo…$"

Route6_Text_IsabellePostBattle::
    .string "Eu quero ficar mais forte.\n"
    .string "Qual é o seu segredo?$"

Route6_EventScript_Jeff::
	trainerbattle_single TRAINER_CAMPER_JEFF, Route6_Text_JeffIntro, Route6_Text_JeffDefeat
	msgbox Route6_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_JeffIntro::
    .string "Hã?\n"
    .string "Você quer falar comigo?$"

Route6_Text_JeffDefeat::
    .string "Que droga…\n"
    .string "Não consegui vencer o seu desafio…$"

Route6_Text_JeffPostBattle::
    .string "Eu devia trazer mais Pokémon comigo.\n"
    .string "Vou me sentir mais seguro assim.$"

Route6_EventScript_UndergroundPathSign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	release
	end

Route6_Text_UndergroundPathSign::
    .string "Passagem Subterrânea\n"
    .string "Cidade de Cerulean - Cidade de Vermilion$"

Route6_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
