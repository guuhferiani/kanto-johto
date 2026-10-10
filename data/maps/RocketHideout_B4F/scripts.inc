.set LOCALID_GIOVANNI,  1
.set LOCALID_CUBONE, 	2
.set LOCALID_JAMES,		3
.set LOCALID_ROCKET2,	4
.set LOCALID_ROCKET3,  	5
.set LOCALID_JESSIE,	6
.set LOCALID_LIFT_KEY,  7

.set NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	.byte 0

RocketHideout_B4F_OnLoad::
	setvar VAR_0x8003, 0
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_ne RocketHideout_B4F_EventScript_SetBarrier
	call_if_set FLAG_MOVENOW_JESSIEJAMES,  RocketHideout_B4F_EventScript_RepositionRockets
	end

RocketHideout_B4F_EventScript_CountGruntDefeated::
	addvar NUM_DOOR_GRUNTS_DEFEATED, 1
	return

RocketHideout_B4F_EventScript_Giovanni::
	lock
	faceplayer
	message RocketHideout_B4F_Text_GiovanniIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
	delay 10
	closemessage
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_HIDE_HIDEOUT_CUBONE
	addobject LOCALID_CUBONE
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	msgbox RocketHideout_B4F_Text_MeetAgain
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_GIOVANNI
	setflag FLAG_HIDE_CELADON_ROCKETS
	setflag FLAG_RESCUED_CUBONE
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	removeobject LOCALID_ROCKET2
	removeobject LOCALID_ROCKET3
	fadescreen FADE_FROM_BLACK
	goto RocketHideout_B4F_EventScript_Cubone
	end

RocketHideout_B4F_Text_GiovanniIntro::
    .string "???: Então! Devo dizer que estou\n"
    .string "impressionado por ter chegado aqui.\p"
    .string "A Equipe Rocket captura Pokémon do\n"
    .string "mundo inteiro.\p"
    .string "Eles são ferramentas vitais para manter\n"
    .string "nosso império criminoso funcionando.\p"
    .string "Eu sou o líder, Giovanni!\p"
    .string "Pela sua insolência, você sentirá uma\n"
    .string "dor inesquecível!$"

RocketHideout_B4F_Text_GiovanniDefeat::
    .string "O quê!\n"
    .string "Isso é impossível!$"

RocketHideout_B4F_Text_GiovanniPostBattle::
    .string "Giovanni: Vejo que você cria seus\n"
    .string "Pokémon com extremo cuidado.\p"
    .string "Uma criança como você jamais entenderia\n"
    .string "o que pretendo alcançar.\p"
    .string "Desta vez vou recuar, e libertar\n"
    .string "este Cubone de volta para você.$"

RocketHideout_B4F_Text_MeetAgain::
    .string "Espero que nos encontremos de novo…$"

RocketHideout_B4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	release
	end

RocketHideout_B4F_Text_Grunt1Intro::
    .string "O elevador não funciona?\n"
    .string "Quem está com a Chave do Elevador?$"

RocketHideout_B4F_Text_Grunt1Defeat::
    .string "Não!$"

RocketHideout_B4F_EventScript_DefeatedGrunt1::
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_HIDE_LIFT_KEY
	release
	end

RocketHideout_B4F_Text_Grunt1PostBattle::
    .string "Ah, não!\n"
    .string "Eu deixei a Chave do Elevador cair!$"

RocketHideout_B4F_EventScript_LiftKey::
	lock
	faceplayer
	removeobject LOCALID_LIFT_KEY
	giveitem ITEM_LIFT_KEY
	goto_if_eq  VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt2::
	lock
	faceplayer
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_Grunt2Intro::
    .string "Eu conheço você!\n"
    .string "Você arruinou nossos planos no Monte Lua!$"

RocketHideout_B4F_Text_Grunt2Defeat::
    .string "Derrotado de novo!$"

RocketHideout_B4F_Text_Grunt2PostBattle::
    .string "Você tem algo contra a Equipe Rocket?$"

RocketHideout_B4F_EventScript_DefeatedGrunt2::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Grunt3::
	lock
	faceplayer
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_Grunt3Intro::
    .string "Como você não consegue ver a beleza\n"
    .string "da nossa maldade?$"

RocketHideout_B4F_Text_Grunt3Defeat::
    .string "Chefe!\n"
    .string "Perdoe-me por falhar!$"

RocketHideout_B4F_Text_Grunt3PostBattle::
    .string "Você pode até ter me vencido, mas\n"
    .string "outros de nós estão a caminho!$"

RocketHideout_B4F_EventScript_DefeatedGrunt3::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_HoldItJessie::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_JESSIEJAMESRHB4F, RocketHideout_B4F_EventScript_JessieJames
	goto_if_unset FLAG_MOVENOW_JESSIEJAMES, RocketHideout_B4F_Eventscript_GiovannisTurn
	msgbox RocketHideout_B4F_Text_JessieDone, MSGBOX_NPC
	release
	end

RocketHideout_B4F_EventScript_HoldItJames::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_JESSIEJAMESRHB4F, RocketHideout_B4F_EventScript_JessieJames
	goto_if_unset FLAG_MOVENOW_JESSIEJAMES, RocketHideout_B4F_Eventscript_GiovannisTurn
	msgbox RocketHideout_B4F_Text_JamesSorry, MSGBOX_NPC
	release
	end

RocketHideout_B4F_EventScript_JessieJames::
	trainerbattle_single TRAINER_HIDEOUT_JESSIE_JAMES, RocketHideout_B4F_Text_JessieJamesIntro, RocketHideout_B4F_Text_JessieJamesDefeat
	msgbox RocketHideout_B4F_Text_JessieJamesPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_DEFEATED_JESSIEJAMESRHB4F
	release
	end

RocketHideout_B4F_EventScript_RepositionRockets::
	setobjectxyperm LOCALID_JESSIE, 16, 11
	setobjectmovementtype LOCALID_JESSIE, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_JAMES, 19, 11
	setobjectmovementtype LOCALID_JAMES, MOVEMENT_TYPE_FACE_LEFT
	return

RocketHideout_B4F_Text_JamesSorry:
	.string "James: Se serve de consolo, eu sinto\n"
	.string "muito pelo que aconteceu com a mãe\l"
	.string "daquele Cubone…$"
	
RocketHideout_B4F_Text_JessieJamesIntro:
	.string "Jessie: É você, o pirralho que vive\n"
	.string "estragando os nossos planos!\p"
	.string "James: Você já está tirando toda a\n"
	.string "graça disso tudo.$"

RocketHideout_B4F_Text_JessieJamesDefeat:
	.string "Jessie: Não! Não! Não!\p"
	.string "James: Isso já está me dando nos nervos!$"

RocketHideout_B4F_Text_JessieDone:
	.string "Jessie: Você pode ter nos derrotado\n"
	.string "de novo, mas o Chefe vai se livrar\l"
	.string "de você de uma vez por todas.$"

RocketHideout_B4F_Text_JessieJamesPostBattle:
	.string "Jessie: Você pode ter nos derrotado\n"
	.string "de novo, mas o Chefe vai se livrar\l"
	.string "de você de uma vez por todas.\p"
	.string "James: Se serve de consolo, eu sinto\n"
	.string "muito pelo que aconteceu com a mãe\l"
	.string "daquele Cubone…$"

//RocketHideout_B4F_EventScript_Jessie::
	//trainerbattle_single TRAINER_ROCKET_HIDEOUT_JESSIE, RocketHideout_B4F_Text_JessieIntro, RocketHideout_B4F_Text_JessieDefeat
	//msgbox RocketHideout_B4F_Text_JessiePostBattle, MSGBOX_AUTOCLOSE
	//end

//RocketHideout_B4F_Text_JessieIntro::
	//.string "Jessie: You're that twerp that\n"
	//.string "keeps interrupting our schemes!$"

//RocketHideout_B4F_Text_JessieDefeat::
	//.string "Jessie: No! No! No!$"

//RocketHideout_B4F_Text_JessiePostBattle::
	//.string "Jessie: You may have defeated\n"
	//.string "me again, but the Boss will\l"
	//.string "finally get rid of you for good.$"

//RocketHideout_B4F_EventScript_James::
	//trainerbattle_single TRAINER_ROCKET_HIDEOUT_JAMES, RocketHideout_B4F_Text_JamesIntro, RocketHideout_B4F_Text_JamesDefeat
	//msgbox RocketHideout_B4F_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	//end

//RocketHideout_B4F_Text_JamesIntro::
	//.string "James: You're starting to take\n"
	//.string "the fun out of all of this.$"

//RocketHideout_B4F_Text_JamesDefeat::
	//.string "James: This is really starting\n"
	//.string "to get to me!$"

//RocketHideout_B4F_Text_JamesPostBattle::
	//.string "James: For what it's worth, I\n"
	//.string "am sorry about what happened to\l"
	//.string "that Cubone's mother...$"

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval::
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setflag FLAG_JESSIE_JAMES_READY
	return

Movement_HoldItJessie::
	walk_right
	face_down
	step_end

Movement_HoldItJames::
	walk_left
	face_down
	step_end

RocketHideout_B4F_Eventscript_GiovannisTurn::
	applymovement LOCALID_JESSIE, Movement_LeaveItJessie
	waitmovement 0
	applymovement LOCALID_JAMES, Movement_LeaveItJames
	waitmovement 0
	clearflag FLAG_JESSIE_JAMES_READY
	setflag FLAG_MOVENOW_JESSIEJAMES
	release
	end

Movement_LeaveItJessie::
	walk_left
	face_right
	step_end

Movement_LeaveItJames::
	walk_right
	face_left
	step_end

RocketHideout_B4F_EventScript_SetBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
	return


RocketHideout_B4F_EventScript_ItemTM49::
	finditem ITEM_TM49, 1
	release
	end

RocketHideout_B4F_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

RocketHideout_B4F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

RocketHideout_B4F_EventScript_Cubone::
	delay 30
	playse SE_PIN
	applymovement LOCALID_CUBONE, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_CUBONE, Movement_CuboneExit
	waitmovement 2
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	removeobject LOCALID_CUBONE
	release
	end

Movement_CuboneExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

RocketHideout_B4F_EventScript_Kangaskhan::
	lock
	faceplayer
    playmoncry SPECIES_KANGASKHAN, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_TONY, RocketHideout_B4F_EventScript_KangaskhanDefeated
	msgbox RocketHideout_B4F_Text_Kangaskhan MSGBOX_DEFAULT
	release
	end

RocketHideout_B4F_Text_Kangaskhan:
	.string "Há algo de sinistro sobre este Kangaskhan.$"

RocketHideout_B4F_EventScript_WaiterTony::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_TONY, RocketHideout_B4F_EventScript_MegaHintKangaskhan
	trainerbattle_single TRAINER_COOLTRAINER_TONY, RocketHideout_B4F_Text_TonyIntro, RocketHideout_B4F_Text_TonyDefeat
	setflag FLAG_DEFEATED_TONY
	msgbox RocketHideout_B4F_Text_TonyPostBattle MSGBOX_AUTOCLOSE
	release
	end

RocketHideout_B4F_Text_TonyIntro:
	.string "Como ousa entrar nos aposentos do\n"
	.string "grande Giovanni!\p"
	.string "…\p"
	.string "Espere… não pode ser!\p"
	.string "Você é o pirralho que desmantelou\n"
	.string "a organização do Giovanni?\p"
	.string "Kangaskhan, esmague-o!$"

RocketHideout_B4F_Text_TonyDefeat:
	.string "Agora eu entendo…$"

RocketHideout_B4F_Text_TonyPostBattle:
	.string "Agora tudo está claro para mim.\p"
	.string "A Equipe Rocket não teve escolha a não\n"
	.string "ser debandar. Você os forçou a isso.$"

RocketHideout_B4F_EventScript_MegaHintKangaskhan::    
    goto_if_set FLAG_GOT_KANGASKHANITE, RocketHideout_B4F_EventScript_TonyDefeated
    msgbox RocketHideout_B4F_Text_KangaskhanMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
RocketHideout_B4F_Text_KangaskhanMegaHint:
    .string "Olhe, pirralho, não nos machuque!\n"
	.string "Eu posso te dizer onde encontrar a\l"
	.string "sua própria Kangaskhanita!\p"
	.string "Eu encontrei ela jogada no chão na\n"
	.string "Zona do Safári.$"

RocketHideout_B4F_EventScript_TonyDefeated::
    msgbox TonyDefeated_Text MSGBOX_DEFAULT
	release
	end

TonyDefeated_Text:	
	.string "Este com certeza não pode ser o fim da\n"
	.string "história do grande Giovanni.$"

RocketHideout_B4F_EventScript_KangaskhanDefeated::
	msgbox KangaskhanDefeated MSGBOX_DEFAULT
	release
	end

KangaskhanDefeated:	
	.string "Kangaskhan respira fundo e solta\n"
	.string "um grunhido insatisfeito.$"

RocketHideout_B4F_EventScript_Burglars_TM35::
	lock
	faceplayer
	goto_if_defeated TRAINER_BURGLAR_KYLE, RocketHideout_B4F_EventScript_TM35_Fix
    trainerbattle_single TRAINER_BURGLAR_KYLE, RocketHideout_B4F_Burglars_Text_BurglarIntro5, RocketHideout_B4F_Burglars_Text_BurglarDefeat5
    msgbox RocketHideout_B4F_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM35, 1
    setflag FLAG_GOT_TM35
	release
	end

RocketHideout_B4F_Burglars_Text_GetTM:
    .string "A Equipe Rocket deixou muito espólio\n"
    .string "bom para trás quando vazou.\p"
    .string "Aqui, pegue isto.\n"
    .string "Tem de sobra para todo mundo!$"

RocketHideout_B4F_EventScript_GotTM35::
    msgbox RocketHideout_B4F_Burglars_Text_BurglarPostBattle5, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_B4F_Burglars_Text_BurglarIntro5:
    .string "Roubar é muito maneiro!$"

RocketHideout_B4F_Burglars_Text_BurglarDefeat5:
    .string "Perder não é nada maneiro!$"

RocketHideout_B4F_Burglars_Text_BurglarPostBattle5:
    .string "Eu simplesmente amo roubar.\n"
    .string "É a única coisa que eu amo!$"

RocketHideout_B4F_EventScript_TM35_Fix::
	goto_if_set FLAG_GOT_TM35, RocketHideout_B4F_EventScript_GotTM35
	msgbox RocketHideout_B4F_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM35, 1
	setflag FLAG_GOT_TM35
	release
	end

RocketHideout_B4F_Text_YouForgotThis:
	.string "Eu não sabia que tinha que dividir\n"
	.string "antes. Tome aqui!$"
