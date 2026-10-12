VictoryRoad_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_ne VAR_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	end

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 11
	setvar VAR_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 12
	setvar VAR_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DawsonIntro::
    .string "Se voce conseguir passar por aqui,\n"
    .string "podera conhecer a Elite dos Quatro.$"

VictoryRoad_2F_Text_DawsonDefeat::
    .string "Nao!\n"
    .string "Inacreditavel!$"

VictoryRoad_2F_Text_DawsonPostBattle::
    .string "Eu ainda te venço quando o assunto\n"
    .string "e conhecimento sobre Pokemon!$"

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DaisukeIntro::
    .string "Esta aqui e a Victory Road.\n"
    .string "E o teste final para treinadores!$"

VictoryRoad_2F_Text_DaisukeDefeat::
    .string "Atchim!$"

VictoryRoad_2F_Text_DaisukePostBattle::
    .string "Se ficar preso, tente empurrar\n"
    .string "algumas pedras por ai.$"

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_NelsonIntro::
    .string "Ah, entao deseja desafiar a\n"
    .string "Elite dos Quatro?$"

VictoryRoad_2F_Text_NelsonDefeat::
    .string "Voce me pegou!$"

VictoryRoad_2F_Text_NelsonPostBattle::
    .string "{RIVAL} tambem passou por aqui.$"

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_GregoryIntro::
    .string "A Victory Road e dura demais?$"

VictoryRoad_2F_Text_GregoryDefeat::
    .string "Muito bem!$"

VictoryRoad_2F_Text_GregoryPostBattle::
    .string "Muitos treinadores desistem do seu\n"
    .string "desafio aqui e voltam para casa.$"

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_VincentIntro::
    .string "Venha!\n"
    .string "Vou te dar uma surra!$"

VictoryRoad_2F_Text_VincentDefeat::
    .string "Eu que levei uma surra!$"

VictoryRoad_2F_Text_VincentPostBattle::
    .string "Voce conquistou o direito de estar\n"
    .string "na Victory Road...$"

VictoryRoad_2F_EventScript_ItemTM37::
	finditem ITEM_TM37, 1
	release
	end

VictoryRoad_2F_EventScript_ItemGuardSpec::
	finditem ITEM_GUARD_SPEC, 1
	release
	end

VictoryRoad_2F_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL, 1
	release
	end

VictoryRoad_2F_EventScript_ItemTM07::
	finditem ITEM_TM07, 1
	release
	end
	
//VictoryRoad_2F_Text_WarmthInCrater::
//    .string "There are scratch marks in\n"
//	.string "the crater and berry stems.\p"
//    .string "The air is oddly warmer here$"
	

