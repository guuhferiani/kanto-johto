.set LOCALID_JENNY_1, 7
.set LOCALID_JENNY_2, 8
.set LOCALID_LOOKER, 9
.set LOCALID_FUGITIVE_F, 15
.set LOCALID_FUGITIVE_M, 16

Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route4_OnResume
	.byte 0

Route4_OnTransition:
	setflag FLAG_VISITED_ROUTE_4
	call Common_EventScript_GetDayOrNight
	end

Route4_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route4_EventScript_Boy::
	msgbox Route4_Text_PeopleLikeAndRespectBrock, MSGBOX_NPC
	release
	end

Route4_Text_PeopleLikeAndRespectBrock::
    .string "Nossa, essa é a Insígnia da Rocha!\n"
    .string "Você conseguiu com o Brock, não foi?\p"
    .string "O Brock é incrível. Ele não é apenas durão.\n"
    .string "As pessoas gostam e o respeitam.\p"
    .string "Eu quero me tornar um Líder de Ginásio\n"
    .string "como ele.$"

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_Text_TrippedOverGeodude::
    .string "Ai! Eu tropecei em um Pokémon de\n"
    .string "pedra, Geodude!$"

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_Text_MtMoonEntrance::
    .string "Mt. Moon\n"
    .string "Entrada do Túnel$"

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_RouteSign::
    .string "Rota 4\n"
    .string "Mt. Moon - Cerulean City$"

Route4_EventScript_Crissy::
    trainerbattle_single TRAINER_LASS_ROBIN, Route4_Text_CrissyIntro, Route4_Text_CrissyDefeat
    msgbox Route4_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route4_Text_CrissyIntro::
    .string "Eu vim ao MT. MOON em busca de Pokémon\n"
    .string "cogumelo.$"

Route4_Text_CrissyDefeat::
    .string "Depois de tudo o que fiz para pegá-los!$"

Route4_Text_CrissyPostBattle::
    .string "Talvez não haja mais nenhum cogumelo\n"
    .string "por aqui.\p"
    .string "Acho que peguei todos.$"

Route4_EventScript_ItemTM05::
	finditem ITEM_TM05, 1
	end

Route4_EventScript_Captured1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepDownForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_StepDownForLooker:
	walk_down
	face_left
	step_end

Route4_EventScript_Captured2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_TurnAroundForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_TurnAroundForLooker:
	face_left
	step_end

Route4_EventScript_Captured3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepUpForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_StepUpForLooker:
	walk_up
	face_left
	step_end

Movement_PoliceApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route4_EventScript_Captured::
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	clearflag FLAG_HIDE_ROUTE4_POLICE
	addobject LOCALID_JENNY_1
	addobject LOCALID_JENNY_2
	addobject LOCALID_LOOKER
	applymovement LOCALID_JENNY_1, Movement_PoliceApproach
	applymovement LOCALID_JENNY_2, Movement_PoliceApproach
	applymovement LOCALID_LOOKER, Movement_PoliceApproach
	waitmovement 9
	msgbox Route4_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route4_Text_TeamRocketFossils, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredLooker, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_LOOKER
	applymovement LOCALID_JENNY_1, Movement_PoliceExit
	applymovement LOCALID_JENNY_2, Movement_PoliceExit
	applymovement LOCALID_LOOKER, Movement_LookerExit
	waitmovement 9
	setflag FLAG_HIDE_ROUTE4_POLICE
	removeobject LOCALID_JENNY_1
	removeobject LOCALID_JENNY_2
	removeobject LOCALID_LOOKER
	setvar VAR_MT_MOON_STATE, 3
	fadedefaultbgm
	releaseall
	end

Movement_PoliceExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_LookerExit:
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route4_Text_StopRightThere::
	.string "???: Parado aí mesmo!\p"
	.string "Achou que conseguiria fugir da Polícia\n"
	.string "Internacional?\p"
	.string "Pois eu sempre estarei um passo à frente\n"
	.string "dos seus planos, Equipe Rocket!$"

Route4_Text_TeamRocketFossils::
	.string "Ha! Você está dizendo que não é da\n"
	.string "Equipe Rocket?\p"
	.string "Então como explica esse fóssil que está\n"
	.string "carregando?\p"
	.string "Nós sabemos que a Equipe Rocket está atrás\n"
	.string "de fósseis raros para vender no mercado\l"
	.string "negro!\p"
	.string "...\n"
	.string "......\l"
	.string "...........ah.\p"
	.string "Então quer dizer que você os deteve?\n"
	.string "E que eles já fugiram do Mt. Moon?\p"
	.string "Droga! Como deixamos eles passarem!\p"
	.string "Peço desculpas pelo mal-entendido.\p"
	.string "Meu nome é Looker. Como você já enfrentou\n"
	.string "a Equipe Rocket antes, talvez possamos\l"
	.string "nos ajudar mutuamente.\p"
	.string "Aqui está o número do meu celular. Me ligue\n"
	.string "se descobrir algo sobre a Equipe Rocket!$"

Route4_EventScript_PixieDust::
	finditem ITEM_PIXIE_DUST, 1
	release
	end

Route4_RocketFugitiveF::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_F
	waitse
	fadescreen FADE_FROM_BLACK
	end

Route4_RocketFugitiveM::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_M
	waitse
	fadescreen FADE_FROM_BLACK
	end

Route4_EventScript_PicnickerSolana::
	trainerbattle_double TRAINER_PICNICKER_SOLANA, Route4_Text_SolanaIntro, Route4_Text_SolanaDefeat, Route4_Text_SolanaNotEnoughMons
	msgbox Route4_Text_SolanaPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

Route4_Text_SolanaIntro:
	.string "Acha que consegue me vencer?\n"
	.string "Até parece!$"
	return

Route4_Text_SolanaDefeat:
	.string "Ah não! Vocês dois estão bem?$"

Route4_Text_SolanaPostBattle:
	.string "Mesmo tendo perdido, estou muito orgulhosa\n"
	.string "dos meus Pokémon.\p"
	.string "Você é um treinador incrível!$"	

Route4_Text_SolanaNotEnoughMons::
    .string "Você só tem um Pokémon?\n"
    .string "Como você conseguiu passar pelo Mt. Moon?$"

Route4_EventScript_Charizard::
	lock
	faceplayer
    playmoncry SPECIES_CHARIZARD, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_KODY, Route4_EventScript_CharizardDefeated
	msgbox Route4_Text_Charizard MSGBOX_DEFAULT
	release
	end

Route4_Text_Charizard:
	.string "Charizard parece indiferente.\n"
	.string "Ele é incomumente alto para um Charizard.$"

Route4_EventScript_YoungsterKody::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KODY, Route4_EventScript_MegaHintCharizard
	trainerbattle_single TRAINER_YOUNGSTER_KODY, Route4_Text_KodyIntro, Route4_Text_KodyDefeat
	setflag FLAG_DEFEATED_KODY
	msgbox Route4_Text_KodyPostBattle MSGBOX_AUTOCLOSE
	release
	end

Route4_Text_KodyIntro:
	.string "Já que espadas não são bem-vistas,\n"
	.string "vou derrotar você com o meu Charizard!$"

Route4_Text_KodyDefeat:
	.string "Isso é tão injusto!$"

Route4_Text_KodyPostBattle:
	.string "Se eu pudesse legalmente lutar de espada\n"
	.string "com você, eu seria o vencedor!$"

Route4_EventScript_MegaHintCharizard::    
    goto_if_set FLAG_GOT_CHARIZARDITE_Y, Route4_EventScript_KodyDefeated
    msgbox Route4_Text_CharizardMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route4_Text_CharizardMegaHint:
    .string "Onde consegui a Mega Pedra para o meu\n"
	.string "Charizard?\p"
	.string "Eu estava treinando no topo da Mansão\n"
	.string "na Cinnabar Island!$"

Route4_EventScript_KodyDefeated::
    msgbox KodyDefeated_Text MSGBOX_DEFAULT
	release
	end

KodyDefeated_Text:	
	.string "Mesmo que o amanhã seja desprovido de\n"
	.string "promessas, nada impedirá o meu retorno.$"

Route4_EventScript_CharizardDefeated::
	msgbox CharizardYDefeated MSGBOX_DEFAULT
	release
	end

CharizardYDefeated:	
	.string "Você acha que o Charizard está sorrindo,\n"
	.string "mas é difícil dizer.$"
