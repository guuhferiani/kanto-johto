.set LOCALID_CUBONE, 6
.set LOCALID_MAROWAK,7

PokemonTower_6F_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_ItemXAccuracy::
	finditem ITEM_X_ACCURACY, 1
	release
	end

PokemonTower_6F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

PokemonTower_6F_EventScript_Gengarite::
	finditem ITEM_GENGARITE, 1
	setflag FLAG_GOT_GENGARITE
	goto_if_unset FLAG_FIRST_MEGASTONE, PokemonTower_6F_EventScript_FoundMegaStone
    end

PokemonTower_6F_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
    .string "Dê…me…\n"
    .string "sangue…$"

PokemonTower_6F_Text_AngelicaDefeat::
    .string "Urrgh!$"

PokemonTower_6F_Text_AngelicaPostBattle::
    .string "Sinto-me anêmica e fraca…$"

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_EmiliaIntro::
    .string "Urff…\n"
    .string "Kwaah!$"

PokemonTower_6F_Text_EmiliaDefeat::
    .string "Algo caiu!$"

PokemonTower_6F_Text_EmiliaPostBattle::
    .string "Meu cabelo não caiu!\n"
    .string "Era um espírito maligno!$"

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_JenniferIntro::
    .string "Ke…ke…ke…\n"
    .string "ke…ke…ke!$"

PokemonTower_6F_Text_JenniferDefeat::
    .string "Keee!$"

PokemonTower_6F_Text_JenniferPostBattle::
    .string "O que está acontecendo aqui?$"


PokemonTower_6F_EventScript_GhostTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 1
	goto PokemonTower_6F_EventScript_MarowakGhost

PokemonTower_6F_EventScript_GhostTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto PokemonTower_6F_EventScript_MarowakGhost

PokemonTower_6F_EventScript_MarowakGhost::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadeoutbgm 0
	msgbox PokemonTower_6F_Text_ScaryPresence, MSGBOX_AUTOCLOSE
	playse SE_M_PERISH_SONG
	waitse
	msgbox PokemonTower_6F_Text_BeGoneIntruders, MSGBOX_AUTOCLOSE
	clearflag FLAG_HIDE_POKEMON_TOWER_MAROWAK
	addobject LOCALID_MAROWAK
	playse SE_M_PERISH_SONG
	waitse
	goto_if_set FLAG_RESCUED_CUBONE, PokemonTower_6F_EventScript_SootheMarowakGhost
	removeobject LOCALID_MAROWAK
	msgbox PokemonTower_6F_Text_TooScaredToGoOn, MSGBOX_AUTOCLOSE
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement OBJ_EVENT_ID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	fadeinbgm 0
	releaseall
	end

PokemonTower_6F_EventScript_SootheMarowakGhost::
	clearflag FLAG_HIDE_POKEMON_TOWER_CUBONE
	addobject LOCALID_CUBONE
	call_if_eq VAR_TEMP_1, 1, PokemonTower_6F_EventScript_CuboneEntrance1
	call_if_eq VAR_TEMP_1, 2, PokemonTower_6F_EventScript_CuboneEntrance2
	waitmovement 6
	playse SE_PIN
	applymovement LOCALID_MAROWAK, Common_Movement_QuestionMark
	waitse
	waitmovement 7
	msgbox PokemonTower_6F_Text_CuboneApproachedTheSpirit
	delay 10
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	delay 20
	playse SE_PIN
	applymovement LOCALID_MAROWAK, Common_Movement_ExclamationMark
	waitse
	waitmovement 7
	msgbox PokemonTower_6F_Text_GhostRecognizedCubone, MSGBOX_AUTOCLOSE
	delay 10
	playse SE_PIN
	applymovement LOCALID_CUBONE, Common_Movement_Heart
	waitse
	delay 10
	applymovement LOCALID_CUBONE, Movement_StepAsideForMarowak
	call_if_eq VAR_TEMP_1, 1, PokemonTower_6F_EventScript_MarowakApproach1
	call_if_eq VAR_TEMP_1, 2, PokemonTower_6F_EventScript_MarowakApproach2
	waitmovement 7
	delay 10
	msgbox PokemonTower_6F_Text_SeemsToUnderstand
	delay 10
	closemessage
	fadescreen FADE_TO_WHITE
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitmoncry
	removeobject LOCALID_MAROWAK
	playse SE_M_SING
	waitse
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed, MSGBOX_AUTOCLOSE
	fadescreen FADE_FROM_WHITE
	delay 10
	call_if_eq VAR_TEMP_1, 1, PokemonTower_6F_EventScript_CuboneExit1
	call_if_eq VAR_TEMP_1, 2, PokemonTower_6F_EventScript_CuboneExit2
	waitmovement 6
	removeobject LOCALID_CUBONE
	setvar VAR_POKEMON_TOWER_STATE, 2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadeinbgm 0
	release
	end

PokemonTower_6F_Text_CuboneApproachedTheSpirit::
	.string "É o Cubone que você resgatou da\n"
	.string "Equipe Rocket...\p"
	.string "Ele se aproximou do espírito inquieto!$"

PokemonTower_6F_Text_GhostRecognizedCubone::
	.string "O fantasma parece reconhecer o\n"
	.string "Cubone...\p"
	.string "Será a mãe do Cubone?$"

PokemonTower_6F_Text_SeemsToUnderstand::
	.string "O fantasma da mãe de Cubone olhou\n"
	.string "para você e assentiu...\p"
	.string "Ele parece compreender o que você\n"
	.string "fez pelo filhote dela...$"

PokemonTower_6F_EventScript_CuboneEntrance1::
	applymovement LOCALID_CUBONE,PokemonTower_6F_Movement_CuboneEntrance1
	return

PokemonTower_6F_Movement_CuboneEntrance1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

PokemonTower_6F_EventScript_CuboneEntrance2::
	applymovement LOCALID_CUBONE, PokemonTower_6F_Movement_CuboneEntrance2
	return

PokemonTower_6F_Movement_CuboneEntrance2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end
	
PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

Movement_StepAsideForMarowak::
	walk_down
	face_up
	step_end

PokemonTower_6F_EventScript_MarowakApproach1::
	applymovement LOCALID_MAROWAK, Movement_MarowakApproach1
	return

Movement_MarowakApproach1::
	walk_right
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

PokemonTower_6F_EventScript_MarowakApproach2::
	applymovement LOCALID_MAROWAK, Movement_MarowakApproach2
	return

Movement_MarowakApproach2::
	walk_right
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	face_up
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

PokemonTower_6F_Text_ScaryPresence::
	.string "Uma presença sinistra toma conta\n"
	.string "do ambiente...$"

PokemonTower_6F_Text_BeGoneIntruders::
    .string "???: Vão embora…\n"
    .string "Intrusos…$"

PokemonTower_6F_Text_TooScaredToGoOn::
	.string "Seus Pokémon estão assustados demais\n"
	.string "para seguir em frente!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
    .string "O espírito da mãe foi acalmado.\p"
    .string "Ela partiu para o além…$"

PokemonTower_6F_EventScript_CuboneExit1::
	applymovement LOCALID_CUBONE,PokemonTower_6F_Movement_CuboneExit1
	return

PokemonTower_6F_Movement_CuboneExit1:
	walk_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	step_end

PokemonTower_6F_EventScript_CuboneExit2::
	applymovement LOCALID_CUBONE,PokemonTower_6F_Movement_CuboneExit2
	return

PokemonTower_6F_Movement_CuboneExit2:
	walk_up
	walk_up
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	step_end
