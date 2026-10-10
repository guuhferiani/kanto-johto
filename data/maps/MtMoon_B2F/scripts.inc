.set LOCALID_DOME_FOSSIL,  1
.set LOCALID_HELIX_FOSSIL, 2
.set LOCALID_MIGUEL,       3
.set LOCALID_JESSIE,	   12
.set LOCALID_JAMES,		   13

MtMoon_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt1Intro::
    .string "Nós, da Equipe Rocket, vamos encontrar\n"
    .string "os fósseis!\p"
    .string "Reviver Pokémon a partir deles vai nos\n"
    .string "render riquezas imensas!$"

MtMoon_B2F_Text_Grunt1Defeat::
    .string "Urgh!\n"
    .string "Agora fiquei furioso!$"

MtMoon_B2F_Text_Grunt1PostBattle::
    .string "Você me tirou do sério!\n"
    .string "A Equipe Rocket vai colocar você na lista\n"
    .string "negra!$"

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt2Intro::
    .string "Nós, da Equipe Rocket, somos os\n"
    .string "gângsteres do mundo Pokémon!\l"
    .string "Impomos medo com a nossa força!$"

MtMoon_B2F_Text_Grunt2Defeat::
    .string "Eu estraguei tudo!$"

MtMoon_B2F_Text_Grunt2PostBattle::
    .string "Droga de tudo!\n"
    .string "Meus comparsas não vão tolerar isso!$"

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt3Intro::
    .string "Estamos em um grande trabalho aqui!\n"
    .string "Dê o fora, pirralho!$"

MtMoon_B2F_Text_Grunt3Defeat::
    .string "Então você é bom mesmo…$"

MtMoon_B2F_Text_Grunt3PostBattle::
    .string "Se você achar um fóssil, passe pra cá e\n"
    .string "suma da minha frente!$"

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_Grunt4Intro::
    .string "Crianças não deveriam se meter nos\n"
    .string "assuntos dos adultos!\p"
    .string "Isso pode acabar muito mal!$"

MtMoon_B2F_Text_Grunt4Defeat::
    .string "Estou fervendo de raiva!$"

MtMoon_B2F_Text_Grunt4PostBattle::
    .string "Os Pokémon viviam aqui muito antes das\n"
    .string "pessoas chegarem.$"

MtMoon_B2F_EventScript_MiguelTrigger::
	lockall
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 3
	goto MtMoon_B2F_EventScript_BattleMiguel
	end

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MIGUEL2, MtMoon_B2F_EventScript_MegaHintAerodactyl
	goto_if_unset FLAG_HIDE_MEGA_TRAINERS, MtMoon_B2F_EventScript_SuperNerdMiguel
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	goto MtMoon_B2F_EventScript_BattleMiguel
	end

MtMoon_B2F_EventScript_BattleMiguel::
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	msgbox MtMoon_B2F_Text_MiguelIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MT_MOON_STATE, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_Text_MiguelIntro::
    .string "Ei, pare aí!\p"
    .string "Eu encontrei estes fósseis!\n"
    .string "Os dois são meus!$"

MtMoon_B2F_Text_MiguelDefeat::
    .string "Tudo bem!\n"
    .string "Eu divido com você!$"

MtMoon_B2F_Text_WellEachTakeAFossil::
    .string "Cada um de nós vai levar um fóssil!\n"
    .string "Nada de ser ganancioso!$"

MtMoon_B2F_EventScript_Aerodactyl::
	lock
	faceplayer
    playmoncry SPECIES_AERODACTYL, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_MIGUEL2, MtMoon_B2F_EventScript_AerodactylDefeated
	msgbox MtMoon_B2F_Text_Aerodactyl MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_Text_Aerodactyl:
	.string "Aerodactyl rosna conforme você se aproxima.$"

MtMoon_B2F_EventScript_SuperNerdMiguel::
	goto_if_set FLAG_HIDE_DOME_FOSSIL, MtMoon_B2F_EventScript_SuperNerdMiguelOmanyte
	goto_if_set FLAG_HIDE_HELIX_FOSSIL, MtMoon_B2F_EventScript_SuperNerdMiguelKabuto
	release
	end

MtMoon_B2F_EventScript_SuperNerdMiguelOmanyte::
	trainerbattle_single TRAINER_SUPER_NERD_MIGUEL_2A, MtMoon_B2F_Text_Miguel2Intro, MtMoon_B2F_Text_Miguel2Defeat
	setflag FLAG_DEFEATED_MIGUEL2
	msgbox MtMoon_B2F_Text_Miguel2PostBattle MSGBOX_AUTOCLOSE
	release
	end

MtMoon_B2F_EventScript_SuperNerdMiguelKabuto::
	trainerbattle_single TRAINER_SUPER_NERD_MIGUEL_2B, MtMoon_B2F_Text_Miguel2Intro, MtMoon_B2F_Text_Miguel2Defeat
	setflag FLAG_DEFEATED_MIGUEL2
	msgbox MtMoon_B2F_Text_Miguel2PostBattle MSGBOX_AUTOCLOSE
	release
	end

MtMoon_B2F_Text_Miguel2Intro:
	.string "Ah, que ótimo. Você de novo.\p"
	.string "Eu achei mais fósseis e não planejo\n"
	.string "perder para uma criança outra vez!$"

MtMoon_B2F_Text_Miguel2Defeat:
	.string "Inconcebível!$"

MtMoon_B2F_Text_Miguel2PostBattle:
	.string "Dá o fora daqui, quer fazer o favor?\p"
	.string "Este é o meu ponto, e você está estragando\n"
	.string "minha busca por fósseis!$"

MtMoon_B2F_EventScript_MegaHintAerodactyl::    
    goto_if_set FLAG_GOT_AERODACTYLITE, MtMoon_B2F_EventScript_Miguel2Defeated
    msgbox MtMoon_B2F_Text_AerodactylMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
MtMoon_B2F_Text_AerodactylMegaHint:
    .string "UGH, para de falar comigo!\p"
	.string "Certamente tem outros lugares para você\n"
	.string "ficar correndo por aí além daqui.\p"
	.string "Se quiser mais fósseis, vá ao norte de\n"
	.string "Lavender Town para uma caminhada.\p" 
	.string "O Rock Tunnel está cheio de rochas,\n"
	.string "incluindo Mega Pedras. É sério!$"

MtMoon_B2F_EventScript_Miguel2Defeated::
    msgbox Miguel2Defeated_Text MSGBOX_DEFAULT
	release
	end

Miguel2Defeated_Text:	
	.string "É isso que eu ganho por tentar sair do meu\n"
	.string "quarto e ver a luz do sol.$"

MtMoon_B2F_EventScript_AerodactylDefeated::
	msgbox AerodactylDefeated MSGBOX_DEFAULT
	release
	end

AerodactylDefeated:	
	.string "Aerodactyl encara você com o que parece ser\n"
	.string "um olhar de admiração.$"

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
    .string "Muito longe daqui, na Cinnabar Island,\n"
    .string "existe um Laboratório Pokémon.\p"
    .string "Eles fazem pesquisas para regenerar\n"
    .string "fósseis.$"

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_DOME_FOSSIL
	setflag FLAG_HIDE_DOME_FOSSIL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ObtainedDomeFossil
	waitmessage
	waitfanfare
	additem ITEM_DOME_FOSSIL, 1
	delay 10
	closemessage
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 3
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	setvar VAR_FOSSIL_SELECTION, 1
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Text_YouWantDomeFossil::
    .string "Você quer o Fóssil Domo?$"

MtMoon_B2F_Text_ObtainedDomeFossil::
    .string "Você obteve o Fóssil Domo!$"

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	setflag FLAG_HIDE_HELIX_FOSSIL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ObtainedHelixFossil
	waitmessage
	waitfanfare
	additem ITEM_HELIX_FOSSIL, 1
	delay 10
	closemessage
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 3
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_DOME_FOSSIL
	setvar VAR_FOSSIL_SELECTION, 2
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Text_YouWantHelixFossil::
    .string "Você quer o Fóssil Hélix?$"

MtMoon_B2F_Text_ObtainedHelixFossil::
    .string "Você obteve o Fóssil Hélix!$"

MtMoon_B2F_Text_ThenThisFossilIsMine::
    .string "Certo.\n"
    .string "Então este fóssil é meu!$"

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_EventScript_ItemStarPiece::
	finditem ITEM_STAR_PIECE, 1
	end

MtMoon_B2F_EventScript_ItemTM46::
	finditem ITEM_TM46, 1
	end

MtMoon_B2F_EventScript_ItemRevive::
	finditem ITEM_REVIVE, 1
	end

MtMoon_B2F_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE, 1
	end

MtMoon_B2F_EventScript_RocketDuoTrigger1::
	lockall
	msgbox MtMoon_B2F_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FaceRockets1
	waitmovement 0	
	goto MtMoon_B2F_EventScript_RocketDuo
	end

Movement_FaceRockets1:
	walk_up
	walk_right
	step_end

MtMoon_B2F_EventScript_RocketDuoTrigger2::
	lockall
	msgbox MtMoon_B2F_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FaceRockets2
	waitmovement 0
	goto MtMoon_B2F_EventScript_RocketDuo
	end

Movement_FaceRockets2:
	walk_up
	face_right
	step_end

MtMoon_B2F_Text_StopRightThere::
	.string "???: Parados aí mesmo!$"

MtMoon_B2F_EventScript_RocketDuo::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	clearflag FLAG_HIDE_MT_MOON_JESSIE_JAMES
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	applymovement LOCALID_JESSIE, MtMoon_Movement_PrepareForTrouble
	applymovement LOCALID_JAMES, MtMoon_Movement_AndMakeItDouble
	waitmovement 13
	trainerbattle_double TRAINER_ROCKET_DUO_1, MtMoon_B2F_Text_RocketDuoIntro, MtMoon_B2F_Text_RocketDuoDefeat, Text_NeedTwoMons, MtMoon_B2F_EventScript_RocketDuoDefeated, NO_MUSIC
	end

MtMoon_B2F_EventScript_RocketDuoDefeated::
	delay 10
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtMoon_B2F_Text_RocketDuoDefeated, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_MT_MOON_JESSIE_JAMES
	setflag FLAG_HIDE_MT_MOON_ROCKETS
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	setvar VAR_MT_MOON_STATE, 2
	playse SE_EXIT
	waitse
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MtMoon_Movement_PrepareForTrouble:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	face_down
	step_end

MtMoon_Movement_AndMakeItDouble:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_left
	step_end

MtMoon_B2F_Text_RocketDuoIntro::
	.string "???: Esse fóssil pertence à\n"
	.string "Equipe Rocket!\p"
	.string "Renda-se agora, ou prepare-se para\n"
	.string "lutar!$"

MtMoon_B2F_Text_RocketDuoDefeat::
	.string "O quê? Esse pirralho venceu a gente?$"

MtMoon_B2F_Text_RocketDuoDefeated::
	.string "Jessie: Isso não acabou aqui, pirralho!\p"
	.string "James: Equipe Rocket, decolando na\n"
	.string "velocidade da luz!$"
