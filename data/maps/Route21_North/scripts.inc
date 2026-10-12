.set LOCALID_FUGITIVE, 7

Route21_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_North_OnResume
	.byte 0

Route21_North_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_EventScript_Anri::
	trainerbattle_single REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1, Route21_North_Text_AnriIntro, Route21_North_Text_AnriDefeat, Route21_North_EventScript_RegisterAnriAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route21_North_EventScript_AnriRematch
	msgbox Route21_North_Text_AnriPostBattle, MSGBOX_DEFAULT
	release
	end

Route21_North_Text_AnriIntro::
    .string "Estou treinando para a Victory Road!$"

Route21_North_Text_AnriDefeat::
    .string "Eu dei tudo de mim.$"

Route21_North_Text_AnriPostBattle::
    .string "Apenas os treinadores mais fortes\n"
    .string "conseguem chegar a Elite dos Quatro.$"

Route21_North_EventScript_RegisterAnriAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_North_Text_AnriRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1
	release
	end

Route21_North_Text_AnriRegister:
	.string "Gostei do seu estilo!\p"
	.string "Me ligue se encontrar um bom lugar\n"
	.string "para treinar!$"

Route21_North_EventScript_AnriRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1, Route21_North_Text_AnriRematchIntro, Route21_North_Text_AnriDefeat
	msgbox Route21_North_Text_AnriRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_AnriRematchIntro::
	.string "Muito bem! Hora de praticar!$"

Route21_North_Text_AnriRematchPostBattle::
	.string "Voce precisara de mais do que forca\n"
	.string "bruta para vencer a Elite dos Quatro!$"


Route21_North_EventScript_Ronald::
	trainerbattle_single TRAINER_FISHERMAN_RONALD, Route21_North_Text_RonaldIntro, Route21_North_Text_RonaldDefeat
	msgbox Route21_North_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_RonaldIntro::
	.string "Quer saber se os peixes estao\n"
	.string "mordendo a isca?$"

Route21_North_Text_RonaldDefeat::
	.string "Droga!$"

Route21_North_Text_RonaldPostBattle::
	.string "Nao consigo pescar nada que preste.\n"
	.string "Nenhum Pokemon bom por aqui!$"

Route21_North_EventScript_Wade::
	trainerbattle_single TRAINER_FISHERMAN_WADE, Route21_North_Text_WadeIntro, Route21_North_Text_WadeDefeat
	msgbox Route21_North_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_WadeIntro::
	.string "Consegui uma pescaria enorme!\n"
	.string "Quer tentar a sorte?$"

Route21_North_Text_WadeDefeat::
	.string "Heheh, Magikarp nao da conta do recado,\n"
	.string "nao e?$"

Route21_North_Text_WadePostBattle::
	.string "Parece que so pesco Magikarp!$"

Route21_North_EventScript_Spencer::
	trainerbattle_single TRAINER_SWIMMER_MALE_SPENCER, Route21_North_Text_SpencerIntro, Route21_North_Text_SpencerDefeat
	msgbox Route21_North_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_SpencerIntro::
	.string "O mar purifica meu corpo e minha alma!$"

Route21_North_Text_SpencerDefeat::
	.string "Ayah!$"

Route21_North_Text_SpencerPostBattle::
	.string "O mar e otimo e tudo mais, mas eu\n"
	.string "tambem gosto das montanhas.$"

Route21_North_EventScript_Lil::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_North_Text_LilIntro, Route21_North_Text_LilDefeat, Route21_North_Text_LilNotEnoughMons
	msgbox Route21_North_Text_LilPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_LilIntro::
	.string "Lil: Hein? Uma batalha?\n"
	.string "Ian, nao pode lutar sozinho?$"

Route21_North_Text_LilDefeat::
	.string "Lil: Ah, viu so?\n"
	.string "Perdemos. Feliz agora?$"

Route21_North_Text_LilPostBattle::
	.string "Lil: Estou cansada.\n"
	.string "Nao podemos ir logo para casa?$"

Route21_North_Text_LilNotEnoughMons::
	.string "Lil: Hein? Uma batalha?\n"
	.string "Nao estou a fim de lutar sozinha.\l"
	.string "Traga dois Pokemon, quer?$"

Route21_North_EventScript_Ian::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_North_Text_IanIntro, Route21_North_Text_IanDefeat, Route21_North_Text_IanNotEnoughMons
	msgbox Route21_North_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_IanIntro::
	.string "Ian: Minha irma nao faz exercicio o\n"
	.string "bastante, entao fiz ela vir comigo.$"

Route21_North_Text_IanDefeat::
	.string "Ian: Poxa, Mana!\n"
	.string "Foco na batalha!$"

Route21_North_Text_IanPostBattle::
	.string "Ian: Vamos la, Mana!\p"
	.string "Voce nao vai perder peso desse jeito!$"

Route21_North_Text_IanNotEnoughMons::
	.string "Ian: Queremos uma batalha de dois contra\n"
	.string "dois. Entao pode trazer dois Pokemon?$"


Route21_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
