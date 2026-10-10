RocketHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_EventScript_SetBarrier
	call_if_set FLAG_HIDE_CELADON_ROCKETS, RocketHideout_B1F_EventScript_RemoveBarrier
	end

RocketHideout_B1F_OnTransition::
    call_if_set FLAG_HIDE_CELADON_ROCKETS, RocketHideout_B1F_EventScript_RemoveBarrier
	end

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt1Intro::
    .string "Quem é você?\n"
    .string "Como você veio parar aqui?$"

RocketHideout_B1F_Text_Grunt1Defeat::
    .string "Ai, ai!\n"
    .string "Fui derrotado!$"

RocketHideout_B1F_Text_Grunt1PostBattle::
    .string "Que droga… Você está desafiando a\n"
    .string "Equipe Rocket, não está?$"

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt2Intro::
    .string "Você invadiu as operações da\n"
    .string "Equipe Rocket? Que audácia!$"

RocketHideout_B1F_Text_Grunt2Defeat::
    .string "Bum!$"

RocketHideout_B1F_Text_Grunt2PostBattle::
    .string "Você não vai se safar dessa,\n"
    .string "pirralho!$"

RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt3Intro::
    .string "Alerta de intruso!$"

RocketHideout_B1F_Text_Grunt3Defeat::
    .string "Eu não consigo!$"

RocketHideout_B1F_Text_Grunt3PostBattle::
    .string "Cubone? Humph!\n"
    .string "Eu não faço ideia de onde está.$"

RocketHideout_B1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt4Intro::
    .string "Por que você veio até aqui?$"

RocketHideout_B1F_Text_Grunt4Defeat::
    .string "Assim não dá!$"

RocketHideout_B1F_Text_Grunt4PostBattle::
    .string "Tudo bem, eu falo…\n"
    .string "Pegue o elevador para ver meu Chefe.$"

RocketHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat, RocketHideout_B1F_EventScript_DefeatedGrunt5
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt5Intro::
    .string "Você se perdeu, seu ratinho?$"

RocketHideout_B1F_Text_Grunt5Defeat::
    .string "Por quê…?$"

RocketHideout_B1F_Text_Grunt5PostBattle::
    .string "Uh-oh, aquela confusão de alguma\n"
    .string "forma abriu a porta!$"

RocketHideout_B1F_EventScript_DefeatedGrunt5::
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 21, 19, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 20, 20, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 21, 20, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 19, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 20, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 20, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor, 0
	return


RocketHideout_B1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

RocketHideout_B1F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION, 1
	release
	end


RocketHideout_Burglars_Text_GetTM::
    .string "A Equipe Rocket deixou muito espólio\n"
    .string "bom para trás quando vazou.\p"
    .string "Aqui, pegue isto.\n"
    .string "Tem de sobra para todo mundo!$"

RocketHideout_Burglars_TM13::
    trainerbattle_single TRAINER_BURGLAR_TYLER, RocketHideout_Burglars_Text_BurglarIntro1, RocketHideout_Burglars_Text_BurglarDefeat1
    goto_if_set FLAG_GOT_TM13, RocketHideout_Burglars_EventScript_GotTM13
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM13, 1
    setflag FLAG_GOT_TM13
RocketHideout_Burglars_EventScript_GotTM13::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle1, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro1::
    .string "Ei! Eu cheguei aqui primeiro.\n"
    .string "Achado não é roubado!$"

RocketHideout_Burglars_Text_BurglarDefeat1::
    .string "Quem perde, chora…$"

RocketHideout_Burglars_Text_BurglarPostBattle1::
    .string "Alguns dos meus comparsas estão aqui\n"
    .string "também. A chance era boa demais para deixar passar!$"



RocketHideout_Burglars_TM23::
    trainerbattle_single TRAINER_BURGLAR_GREG, RocketHideout_Burglars_Text_BurglarIntro2, RocketHideout_Burglars_Text_BurglarDefeat2
    goto_if_set FLAG_GOT_TM23, RocketHideout_Burglars_EventScript_GotTM23
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM23, 1
    setflag FLAG_GOT_TM23
RocketHideout_Burglars_EventScript_GotTM23::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle2, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro2::
    .string "Vejamos… o que temos aqui?$"

RocketHideout_Burglars_Text_BurglarDefeat2::
    .string "Não! Eu queria esse aí!$"

RocketHideout_Burglars_Text_BurglarPostBattle2::
    .string "A gente nunca sabe o que vai achar\n"
    .string "quando arromba um lugar.$"


RocketHideout_Burglars_TM24::
    trainerbattle_single TRAINER_BURGLAR_TONY, RocketHideout_Burglars_Text_BurglarIntro3, RocketHideout_Burglars_Text_BurglarDefeat3
    goto_if_set FLAG_GOT_TM24, RocketHideout_Burglars_EventScript_GotTM24
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM24, 1
    setflag FLAG_GOT_TM24
RocketHideout_Burglars_EventScript_GotTM24::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle3, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro3::
    .string "Opa, ei, você está afanando isso?\n"
    .string "Isso não é nada educado!$"

RocketHideout_Burglars_Text_BurglarDefeat3::
    .string "Por que você fez isso?$"

RocketHideout_Burglars_Text_BurglarPostBattle3::
    .string "Ah, eu? Eu não estou roubando isto.\n"
    .string "Estou apenas pegando emprestado!$"


RocketHideout_Burglars_TM30::
    trainerbattle_single TRAINER_BURGLAR_JAKE, RocketHideout_Burglars_Text_BurglarIntro4, RocketHideout_Burglars_Text_BurglarDefeat4
    goto_if_set FLAG_GOT_TM30, RocketHideout_Burglars_EventScript_GotTM30
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM30, 1
    setflag FLAG_GOT_TM30
RocketHideout_Burglars_EventScript_GotTM30::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle4, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro4::
    .string "Vejamos… o que posso encontrar\n"
    .string "aqui hoje?$"

RocketHideout_Burglars_Text_BurglarDefeat4::
    .string "Nada!$"

RocketHideout_Burglars_Text_BurglarPostBattle4::
    .string "O quê? Arrumar um emprego honesto?\n"
    .string "Nesta economia?$"

RocketHideout_Burglars_TM36::
    trainerbattle_single TRAINER_BURGLAR_PETE, RocketHideout_Burglars_Text_BurglarIntro6, RocketHideout_Burglars_Text_BurglarDefeat6
    goto_if_set FLAG_GOT_TM36, RocketHideout_Burglars_EventScript_GotTM36
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM36, 1
    setflag FLAG_GOT_TM36
RocketHideout_Burglars_EventScript_GotTM36::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle6, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro6::
    .string "Uau! Isto parece caro!$"

RocketHideout_Burglars_Text_BurglarDefeat6::
    .string "Ah, cara, é só lixo!$"

RocketHideout_Burglars_Text_BurglarPostBattle6::
    .string "Eu nunca acho nada que preste.$"

