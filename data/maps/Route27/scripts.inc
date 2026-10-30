Route27_MapScripts::
	.byte 0

Route27_EventScript_Sign::
	msgbox Route27_Text_Sign, MSGBOX_SIGN
	end

Route27_Text_Sign::
	.string "Rota 27\n"
	.string "Fronteira Oficial entre Kanto e Johto\p"
	.string "Leste: Guarita da Liga (Kanto)\n"
	.string "Oeste: Cachoeiras de Tohjo e Johto$"

Route27_EventScript_BorderWatcher::
	msgbox Route27_Text_BorderWatcher, MSGBOX_NPC
	end

Route27_Text_BorderWatcher::
	.string "Ei, Campeao {PLAYER}!\n"
	.string "Olhe no seu mapa!\p"
	.string "Voce esta pisando na lendaria Rota 27!\n"
	.string "Atravessando as Cachoeiras de Tohjo logo\l"
	.string "a frente, voce chegara a Johto!$"

Route27_EventScript_FriendshipWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM27, Route27_EventScript_FriendshipWomanPost
	msgbox Route27_Text_FriendshipWomanIntro, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, Route27_EventScript_GiveReturnTM
	msgbox Route27_Text_FriendshipNotMax, MSGBOX_DEFAULT
	release
	end

Route27_EventScript_GiveReturnTM::
	msgbox Route27_Text_FriendshipMax, MSGBOX_DEFAULT
	giveitem ITEM_TM27, 1
	setflag FLAG_RECEIVED_TM27
	msgbox Route27_Text_FriendshipWomanPostMsg, MSGBOX_DEFAULT
	release
	end

Route27_EventScript_FriendshipWomanPost::
	msgbox Route27_Text_FriendshipWomanPostMsg, MSGBOX_NPC
	end

Route27_Text_FriendshipWomanIntro::
	.string "Ah, que treinador dedicado e carinhoso!\p"
	.string "Deixe-me ver o laco entre voce e o\n"
	.string "Pokemon que te acompanha...$"

Route27_Text_FriendshipMax::
	.string "Que maravilha emocionante!\p"
	.string "O seu Pokemon confia plenamente em voce!\n"
	.string "A amizade de voces e pura e inabalavel!\p"
	.string "Tome este TM especial. Ele causa muito mais\n"
	.string "dano quando usado com amor!$"

Route27_Text_FriendshipNotMax::
	.string "O seu Pokemon gosta muito de voce,\n"
	.string "mas tenho certeza que com mais tempo\l"
	.string "juntos a confianca sera ainda maior!$"

Route27_Text_FriendshipWomanPostMsg::
	.string "O TM27 contem o golpe Retorno (Return)!\n"
	.string "E a prova viva de que a amizade vence\l"
	.string "qualquer batalha!$"


Route27_EventScript_MtSilverRanger::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_ALL_JOHTO_LEADERS, Route27_EventScript_MtSilverLocked
	msgbox Route27_Text_MtSilverAskWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route27_EventScript_MtSilverDecline
	msgbox Route27_Text_MtSilverDeparting, MSGBOX_DEFAULT
	warp MAP_MT_SILVER, 4, 7
	waitstate
	release
	end

Route27_EventScript_MtSilverLocked::
	msgbox Route27_Text_MtSilverLocked, MSGBOX_DEFAULT
	release
	end

Route27_EventScript_MtSilverDecline::
	msgbox Route27_Text_MtSilverDecline, MSGBOX_DEFAULT
	release
	end

Route27_Text_MtSilverLocked::
	.string "Guarda Florestal: Eu protejo a\n"
	.string "trilha secreta para o Monte Silver!\p"
	.string "Apenas treinadores que conquistaram\n"
	.string "as 8 Insígnias de Johto têm\l"
	.string "permissão para subir ao cume onde\l"
	.string "o lendário Campeão Red treina!$"

Route27_Text_MtSilverAskWarp::
	.string "Guarda Florestal: Impressionante!\n"
	.string "Você possui todas as 8 Insígnias\l"
	.string "de Kanto e as 8 de Johto!\p"
	.string "Deseja que eu o escolte agora mesmo\n"
	.string "até o cume nevado do Monte Silver?$"

Route27_Text_MtSilverDeparting::
	.string "Prepare-se para o frio extremo!\n"
	.string "Rumo ao Monte Silver!$"

Route27_Text_MtSilverDecline::
	.string "Estarei aqui sempre que quiser ir\n"
	.string "ao Monte Silver!$"
