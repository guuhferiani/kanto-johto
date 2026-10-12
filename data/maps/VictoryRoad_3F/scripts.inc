VictoryRoad_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_VICTORY_ROAD_3F_STATE, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_3F_STATE, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 7
	copyobjectxytoperm 10
	setvar VAR_VICTORY_ROAD_3F_STATE, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_GeorgeIntro::
    .string "Ouvi boatos sobre uma crianca prodigio.$"

VictoryRoad_3F_Text_GeorgeDefeat::
    .string "Os boatos eram verdadeiros!$"

VictoryRoad_3F_Text_GeorgePostBattle::
    .string "Entao foi voce quem derrotou Giovanni\n"
    .string "da Equipe Rocket?$"

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_ColbyIntro::
    .string "Apenas os escolhidos podem passar aqui!$"

VictoryRoad_3F_Text_ColbyDefeat::
    .string "Nao acredito nisso!$"

VictoryRoad_3F_Text_ColbyPostBattle::
    .string "Todos os Treinadores aqui vao para\n"
    .string "a Liga Pokemon.\p"
    .string "Nao baixe a sua guarda.$"

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_CarolineIntro::
    .string "Vou te mostrar o quao bom voce e.\n"
    .string "So que nao!$"

VictoryRoad_3F_Text_CarolineDefeat::
    .string "Estou furiosa!$"

VictoryRoad_3F_Text_CarolinePostBattle::
    .string "Voce me mostrou o quao boa eu era...$"

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_AlexaIntro::
    .string "Treinadores vivem para buscar\n"
    .string "oponentes mais fortes.$"

VictoryRoad_3F_Text_AlexaDefeat::
    .string "Oh!\n"
    .string "Tao forte!$"

VictoryRoad_3F_Text_AlexaPostBattle::
    .string "Lutando batalhas dificeis, voce fica\n"
    .string "mais forte.$"

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_RayIntro::
    .string "Ray: Juntos, nos dois estamos\n"
    .string "destinados a grandeza!$"

VictoryRoad_3F_Text_RayDefeat::
    .string "Ray: Ridiculo!\n"
    .string "Isso nao pode ser!$"

VictoryRoad_3F_Text_RayPostBattle::
    .string "Ray: Voce nos venceu.\n"
    .string "A grandeza continua distante...$"

VictoryRoad_3F_Text_RayNotEnoughMons::
    .string "Ray: Juntos, nos dois buscamos\n"
    .string "o topo.\p"
    .string "Precisamos que traga dois Pokemon para\n"
    .string "batalhar conosco.$"

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_TyraIntro::
    .string "Tyra: Estamos tentando nos tornar\n"
    .string "campeoes juntos.$"

VictoryRoad_3F_Text_TyraDefeat::
    .string "Tyra: Ah, mas...$"

VictoryRoad_3F_Text_TyraPostBattle::
    .string "Tyra: Voce me ensinou que o poder\n"
    .string "pode ter infinitas formas e feitios.$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
    .string "Tyra: Nao podemos batalhar se voce\n"
    .string "tiver apenas um Pokemon.$"

VictoryRoad_3F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

VictoryRoad_3F_EventScript_ItemTM50::
	finditem ITEM_TM50, 1
	release
	end

VictoryRoad_3F_EventScript_ItemPowerStone::
	finditem ITEM_POWER_STONE, 1
	release
	end

VictoryRoad_3F_EventScript_NinjaOrion::
	trainerbattle_double TRAINER_NINJABOY_ORION, VictoryRoad_3F_Text_OrionIntro, VictoryRoad_3F_Text_OrionDefeat, VictoryRoad_3F_Text_OrionNotEnoughMons
	msgbox VictoryRoad_3F_Text_OrionPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

VictoryRoad_3F_Text_OrionIntro:
	.string "Cai dentro, parceiro!$"

VictoryRoad_3F_Text_OrionDefeat:
	.string "Tamanho poder! Como isso e possivel?$"

VictoryRoad_3F_Text_OrionPostBattle:
	.string "Posso ter perdido esta batalha,\n"
	.string "mas ainda veremos se voce consegue\l"
	.string "vencer esta guerra!\p"
	.string "Raichu, Blastoise e eu vamos treinar\n"
	.string "mais duro do que nunca.\p"
	.string "Esse e o nosso Jeito Ninja!$"	

VictoryRoad_3F_Text_OrionNotEnoughMons::
    .string "Voce e muito corajoso ou muito\n"
    .string "tolo para andar por aqui com apenas\l"
    .string "um Pokemon.$"

