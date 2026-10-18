.set LOCALID_FUGITIVE, 12

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route20_OnResume
	.byte 0

Route20_OnTransition:
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	call Common_EventScript_GetDayOrNight
	end

Route20_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_SeafoamIslands::
    .string "Seafoam Islands$"

Route20_EventScript_Barry::
	trainerbattle_single TRAINER_SWIMMER_MALE_BARRY, Route20_Text_BarryIntro, Route20_Text_BarryDefeat
	msgbox Route20_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_BarryIntro::
    .string "A agua e rasa por aqui.\n"
    .string "Tem muita gente nadando.$"

Route20_Text_BarryDefeat::
    .string "Tchibum!$"

Route20_Text_BarryPostBattle::
    .string "Queria poder surfar num Pokemon.\n"
    .string "Aposto que voce nem se cansou.$"

Route20_EventScript_Dean::
	trainerbattle_single TRAINER_SWIMMER_MALE_DEAN, Route20_Text_DeanIntro, Route20_Text_DeanDefeat
	msgbox Route20_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_DeanIntro::
    .string "Olha so o meu porte fisico!$"

Route20_Text_DeanDefeat::
    .string "Fraquejei!$"

Route20_Text_DeanPostBattle::
    .string "Eu devia ter fortalecido meus\n"
    .string "Pokemon, e nao a mim mesmo!$"

Route20_EventScript_Darrin::
	trainerbattle_single TRAINER_SWIMMER_MALE_DARRIN, Route20_Text_DarrinIntro, Route20_Text_DarrinDefeat
	msgbox Route20_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_DarrinIntro::
    .string "Por que esta montado num Pokemon?\n"
    .string "Nao sabe nadar?$"

Route20_Text_DarrinDefeat::
    .string "Ai!\n"
    .string "Fui torpedeado!$"

Route20_Text_DarrinPostBattle::
    .string "Surfar num Pokemon parece bem legal!$"

Route20_EventScript_Slowbronite::
	finditem ITEM_WATER_STONE, 1
	setflag FLAG_GOT_SLOWBRONITE
	release
	end

Route20_EventScript_Tiffany::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_TIFFANY, Route20_Text_TiffanyIntro, Route20_Text_TiffanyDefeat
	msgbox Route20_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_TiffanyIntro::
    .string "Adoro boiar com os peixinhos aqui\n"
    .string "entre as ondas.$"

Route20_Text_TiffanyDefeat::
    .string "Ai ai ai!$"

Route20_Text_TiffanyPostBattle::
    .string "Quer boiar comigo?$"

Route20_EventScript_Nora::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_NORA, Route20_Text_NoraIntro, Route20_Text_NoraDefeat
	msgbox Route20_Text_NoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_NoraIntro::
    .string "Meu namorado me deu perolas grandes.$"

Route20_Text_NoraDefeat::
    .string "Ah, nao!\n"
    .string "Minhas perolas estavam neles!$"

Route20_Text_NoraPostBattle::
    .string "Sera que minhas perolas vao crescer\n"
    .string "dentro de um Cloyster?$"

Route20_EventScript_Melissa::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_MELISSA, Route20_Text_MelissaIntro, Route20_Text_MelissaDefeat
	msgbox Route20_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_MelissaIntro::
    .string "Cinnabar, no oeste, tem um laboratorio\n"
    .string "de Pokemon.\p"
    .string "Meu pai trabalha la.$"

Route20_Text_MelissaDefeat::
    .string "Espere!\n"
    .string "Voce tinha que esperar!$"

Route20_Text_MelissaPostBattle::
    .string "Cinnabar e uma ilha vulcanica.\p"
    .string "Ouvi dizer que ela emergiu do mar\n"
    .string "quando um vulcao entrou em erupcao.$"

Route20_EventScript_Shirley::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_SHIRLEY, Route20_Text_ShirleyIntro, Route20_Text_ShirleyDefeat
	msgbox Route20_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_ShirleyIntro::
    .string "Seafoam e um refugio tranquilo.\n"
    .string "Estou passando ferias aqui.$"

Route20_Text_ShirleyDefeat::
    .string "Para com isso!$"

Route20_Text_ShirleyPostBattle::
    .string "Ha uma caverna enorme embaixo desta\n"
    .string "ilha.$"

Route20_EventScript_Missy::
	trainerbattle_single TRAINER_PICNICKER_MISSY, Route20_Text_MissyIntro, Route20_Text_MissyDefeat
	msgbox Route20_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_MissyIntro::
    .string "Eu nadei da Ilha de Cinnabar ate aqui.\n"
    .string "Nao foi nada facil, sabia?$"

Route20_Text_MissyDefeat::
    .string "Que decepcao!$"

Route20_Text_MissyPostBattle::
    .string "Os Pokemon tomaram conta de uma mansao\n"
    .string "abandonada em Cinnabar.\p"
    .string "Agora chamam o lugar de Mansao\n"
    .string "Pokemon.$"

Route20_EventScript_Irene::
	trainerbattle_single TRAINER_PICNICKER_IRENE, Route20_Text_IreneIntro, Route20_Text_IreneDefeat
	msgbox Route20_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_IreneIntro::
    .string "Voce tambem esta de ferias?$"

Route20_Text_IreneDefeat::
    .string "Sem piedade nenhuma!$"

Route20_Text_IrenePostBattle::
    .string "Seafoam costumava ser uma unica ilha\n"
    .string "no passado distante.$"

Route20_EventScript_Roger::
	trainerbattle_single REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1, Route20_Text_RogerIntro, Route20_Text_RogerDefeat, Route20_EventScript_RegisterRogerAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RogerRematch
	msgbox Route20_Text_RogerPostBattle, MSGBOX_DEFAULT
	release
	end

Route20_Text_RogerIntro::
    .string "Voce nunca vai chegar a Elite dos\n"
    .string "Quatro com essa equipe!$"

Route20_Text_RogerDefeat::
    .string "Nao! Agora nunca vou conhecer Lance!$"

Route20_Text_RogerPostBattle::
    .string "Espera, quer dizer que Gyarados nao e\n"
    .string "do tipo Dragao?$"

Route20_EventScript_RegisterRogerAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_RogerRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1
	release
	end

Route20_Text_RogerRegister:
	.string "Ha! Eu deixei voce vencer...\p"
	.string "Me ligue quando quiser uma disputa\n"
	.string "de verdade.$"

Route20_EventScript_RogerRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1, Route20_Text_RogerRematchIntro, Route20_Text_RogerDefeat
	msgbox Route20_Text_RogerRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_RogerRematchIntro::
	.string "Desta vez vou te esmagar com meus\n"
	.string "Pokemon de Dragao!$"

Route20_Text_RogerRematchPostBattle::
	.string "Gyarados nao e do tipo Dragao, mas\n"
	.string "pode aprender golpes de Dragao!$"

Route20_EventScript_Camper::
	lock
	faceplayer
	msgbox Route20_Text_MistyTrainsHere
	release
	end

Route20_Text_MistyTrainsHere::
    .string "Treinadores fortes e Pokemon de Agua\n"
    .string "sao comuns por aqui.\p"
    .string "Dizem que Misty do Ginasio de Cerulean\n"
    .string "treina nesta regiao.$"

Route20_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

Route20_EventScript_Blastoise::
	lock
	faceplayer
	playmoncry SPECIES_BLASTOISE, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
    goto_if_set FLAG_DEFEATED_DYLAN, Route20_EventScript_BlastoiseDefeated
	msgbox Route20_Text_Blastoise MSGBOX_DEFAULT
	release
	end

Route20_Text_Blastoise:
	.string "Blastoise te encara nos olhos.\n"
	.string "Ele transborda confianca.$"

Route20_EventScript_EngineerDylan::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DYLAN, Route20_EventScript_MegaHintBlastoise
	trainerbattle_single TRAINER_ENGINEER_DYLAN, Route20_Text_DylanIntro, Route20_Text_DylanDefeat
	setflag FLAG_DEFEATED_DYLAN
	msgbox Route20_Text_DylanPostBattle MSGBOX_AUTOCLOSE
	release
	end

Route20_Text_DylanIntro:
	.string "Voce parece mais forte que as outras\n"
	.string "criancas nadando por aqui.\p"
	.string "Talvez a gente precise levar isto a\n"
	.string "serio!$"

Route20_Text_DylanDefeat:
	.string "Kanto ainda tem garra.$"

Route20_Text_DylanPostBattle:
	.string "Que equipe incrivel voce tem!$"

Route20_EventScript_MegaHintBlastoise::  
    goto_if_set FLAG_GOT_BLASTOISINITE, Route20_EventScript_DylanDefeated
    msgbox Route20_Text_BlastoiseMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route20_Text_BlastoiseMegaHint:
    .string "...Hmmm? Onde consegui a Blastoisinite?\p"
	.string "Eu a encontrei na praia depois de\n"
	.string "vencer o ginasio em Vermilion City.$"

Route20_EventScript_DylanDefeated::
    msgbox DylanDefeated_Text MSGBOX_DEFAULT
	release
	end

DylanDefeated_Text:	
	.string "Posso ver que voce e um treinador que\n"
	.string "luta de corpo e alma.$"

Route20_EventScript_BlastoiseDefeated::
	msgbox BlastoiseDefeated MSGBOX_DEFAULT
	release
	end

BlastoiseDefeated:	
	.string "Blastoise olha para voce e bufa em\n"
	.string "sinal de aprovacao.$"
