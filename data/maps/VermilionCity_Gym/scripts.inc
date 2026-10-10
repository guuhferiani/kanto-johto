.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	call_if_unset FLAG_DAILY_SURGE_REMATCH, VermilionCity_Gym_ResetRematchFlags
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, Common_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_SURGE_ORIGINAL
	cleartrainerflag LEADER_REMATCH_SURGE_POSTGAME
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	compare SWITCH1_ID, TRASH_CAN_ID
	goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	compare SWITCH2_ID, TRASH_CAN_ID
	goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "Nada feito!\n"
    .string "Só tem lixo aqui dentro.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Ei! Há um botão sob o lixo!\n"
    .string "Você o ativou!\p"
    .string "A primeira trava elétrica se abriu!$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "A segunda trava elétrica se abriu!\n"
    .string "A porta motorizada foi destrancada!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "Nada feito!\n"
    .string "Só tem lixo aqui dentro.\p"
    .string "Ei!\n"
    .string "As travas elétricas foram rearmadas!$"


VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_SURGE_REWARD, VermilionCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_SURGE_REMATCH, VermilionCity_Gym_EventScript_RematchLeader
	goto VermilionCity_Gym_EventScript_LeaderPostBattle
	end

VermilionCity_Gym_EventScript_ChallengeLeader::
	msgbox VermilionCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SURGE, VermilionCity_Gym_Text_LeaderIntro, VermilionCity_Gym_Text_LeaderDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

VermilionCity_Gym_Text_LeaderSpeech::
    .string "Ei, pirralho! O que pensa que está\n"
    .string "fazendo aqui?\p"
    .string "Você não duraria um minuto em combate!\n"
    .string "Não com esse seu poderzinho minúsculo!\p"
    .string "Vou te contar, garoto, Pokémon elétricos\n"
    .string "salvaram a minha vida na guerra!$"

VermilionCity_Gym_Text_LeaderIntro::
    .string "Eles eletrocutavam meus inimigos até\n"
    .string "a paralisia total!\p"
    .string "E é exatamente isso que farei com você!$"

VermilionCity_Gym_Text_LeaderDefeat::
    .string "Agora isso sim foi um choque!\p"
    .string "Você é casca-grossa de verdade, garoto!$"

VermilionCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox VermilionCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message VermilionCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox VermilionCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DAILY_SURGE_REMATCH
	settrainerflag TRAINER_SAILOR_DWAYNE
	settrainerflag TRAINER_ENGINEER_BAILY
	settrainerflag TRAINER_GENTLEMAN_TUCKER
	call_if_set FLAG_RECEIVED_HM05, VermilionCity_Gym_EventScript_QueueNextAideCall
	goto VermilionCity_Gym_EventScript_GetTM
	end

VermilionCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_2
	return

VermilionCity_Gym_Text_GetBadge::
    .string "Muito bem, tome a Insígnia do Trovão!$"

VermilionCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insígnia do Trovão\n"
    .string "do Tenente Surge!$"

VermilionCity_Gym_Text_ExplainBadge::
    .string "A Insígnia do Trovão autoriza seus\n"
    .string "Pokémon a usarem Voar fora de batalha.\p"
    .string "Se eles souberem o golpe, podem te levar\n"
    .string "a qualquer lugar num piscar de olhos!\p"
    .string "Você é especial, garoto!$"

VermilionCity_Gym_EventScript_GetTM::
	msgbox VermilionCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM34, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox VermilionCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM34, 1
	setflag FLAG_GOT_SURGE_REWARD
	msgbox VermilionCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_TakeThisWithYou::
    .string "Fique com isto!$"

VermilionCity_Gym_Text_ReceivedTM::
    .string "{PLAYER} recebeu o MT34\n"
    .string "do Tenente Surge.$"

VermilionCity_Gym_Text_ExplainTM::
    .string "O MT34 contém Onda de Choque!\p"
    .string "Ensine a um Pokémon Elétrico!$"

VermilionCity_Gym_EventScript_NoRoomForTM::
	msgbox VermilionCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_NoRoomForTM::
    .string "Ei, garoto, abra espaço na sua mochila!$"

VermilionCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox VermilionCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_LeaderPostBattle::
    .string "Um conselhinho, garoto!\p"
    .string "A eletricidade com certeza é poderosa!\p"
    .string "Mas não serve de nada contra\n"
    .string "Pokémon do tipo Terra!$"

VermilionCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox VermilionCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_PostBattleGameClear::
	.string "Parece que ainda há uma distância\n"
	.string "entre as nossas habilidades que eu\l"
	.string "preciso diminuir, garoto!\p"
	.string "Esta é a primeira vez que me sinto\n"
	.string "assim desde que me tornei o Líder\l"
	.string "do Ginásio de Vermilion.$"

VermilionCity_Gym_EventScript_RematchLeader::
	msgbox VermilionCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_Gym_EventScript_PostgameRematch
	goto VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

VermilionCity_Gym_Text_RematchLeader::
	.string "E aí, garoto! É bem chocante ver\n"
	.string "que chegou tão longe na sua jornada!\p"
	.string "Sem dúvida algum Pokémon Elétrico\n"
	.string "teve um grande papel nisso, certo?\p"
	.string "Muito bem, então.\p"
	.string "Que tal uma revanche para me mostrar\n"
	.string "que tipo de Pokémon você treinou?$"

VermilionCity_Gym_EventScript_DeclineRematch::
	msgbox VermilionCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_DeclineRematch::
	.string "Hmph. Covarde!$"

VermilionCity_Gym_EventScript_PostgameRematch::
	msgbox VermilionCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

VermilionCity_Gym_Text_RematchMode::
	.string "Agora que você é o Campeão,\n"
	.string "gostaria de ir com tudo?$"

VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_SURGE_ORIGINAL, VermilionCity_Gym_Text_RematchOriginal, VermilionCity_Gym_Text_RematchDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderRematch
	end

VermilionCity_Gym_Text_RematchOriginal::
	.string "Sentido!\n"
	.string "Lembre-se, uma batalha Pokémon é guerra!\p"
	.string "Vamos lá, garoto!$"

VermilionCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single LEADER_REMATCH_SURGE_POSTGAME, VermilionCity_Gym_Text_RematchPostgame, VermilionCity_Gym_Text_RematchDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderRematch
	end

VermilionCity_Gym_Text_RematchPostgame::
	.string "Não há necessidade de apresentações!\n"
	.string "Campeões não precisam de palavras!\p"
	.string "Vamos lá, garoto!$"

VermilionCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_SURGE_REMATCH
	goto VermilionCity_Gym_EventScript_LeaderPostBattle
	end

VermilionCity_Gym_Text_RematchDefeat::
	.string "Absolutamente chocante!$"

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_DwayneIntro::
    .string "Este não é lugar para crianças!\n"
    .string "Nem mesmo se você for bom!$"

VermilionCity_Gym_Text_DwayneDefeat::
    .string "Uau!\n"
    .string "Me pegou de surpresa!$"

VermilionCity_Gym_Text_DwaynePostBattle::
    .string "O Ten. Surge instalou as armadilhas\n"
    .string "no ginásio pessoalmente.\p"
    .string "Ele colocou travas duplas por toda parte.\n"
    .string "Vou te dar uma dica.\p"
    .string "Ao abrir a primeira trava, a segunda\n"
    .string "estará bem ao lado dela.$"

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_BailyIntro::
    .string "Sou um peso-pena, mas sou muito\n"
    .string "bom com eletricidade!\p"
    .string "Foi por isso que entrei neste ginásio.$"

VermilionCity_Gym_Text_BailyDefeat::
    .string "Frito!$"

VermilionCity_Gym_Text_BailyPostBattle::
    .string "Tudo bem, eu falo!\p"
    .string "O Ten. Surge disse que escondeu\n"
    .string "os botões da porta dentro de algo.$"

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_TuckerIntro::
    .string "Quando eu estava no Exército, o Ten.\n"
    .string "Surge era o meu comandante rigoroso.\p"
    .string "Ele era um líder implacável.$"

VermilionCity_Gym_Text_TuckerDefeat::
    .string "Pare!\n"
    .string "Você é muito bom!$"

VermilionCity_Gym_Text_TuckerPostBattle::
    .string "Não é fácil abrir aquela porta.\p"
    .string "O Ten. Surge sempre foi famoso por\n"
    .string "sua cautela no Exército.$"


VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "E aí!\n"
    .string "Futuro Campeão!\p"
    .string "O Ten. Surge tem um apelido.\p"
    .string "As pessoas o chamam de o\n"
    .string "Tenente Relâmpago!\p"
    .string "Ele é um especialista em Pokémon Elétricos.\p"
    .string "Pokémon Pássaro e do tipo Água devem\n"
    .string "tomar cuidado com ataques Elétricos!\p"
    .string "Cuidado com paralisia também.\p"
    .string "O Ten. Surge é muito cauteloso.\p"
    .string "Ele se trancou lá dentro, então não\n"
    .string "será fácil chegar até ele.$"

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_Text_GymGuyPostVictory::
    .string "Ufa!\n"
    .string "Aquela batalha foi eletrizante!$"

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_Text_GymStatue::
    .string "Ginásio Pokémon de Vermilion\n"
    .string "Líder: Ten. Surge\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginásio Pokémon de Vermilion\n"
    .string "Líder: Ten. Surge\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"
