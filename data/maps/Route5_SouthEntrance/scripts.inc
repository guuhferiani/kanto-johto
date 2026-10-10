.set LOCALID_JENNY, 1

Route5_SouthEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route5_SouthEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route5_SouthEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route5_SouthEntrance_EventScript_RoadsClosed
	msgbox Route5_SouthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route5_SouthEntrance_Text_HiHowsItGoing::
    .string "Oi, como vão as coisas?$"

Route5_SouthEntrance_EventScript_RoadsClosed::
	msgbox Route5_SouthEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route5_SouthEntrance_Text_RoadsClosed::
    .string "Ah, a propósito, a estrada está fechada.\p"
    .string "A Polícia Internacional está em\n"
    .string "plena caçada à Equipe Rocket!$"

Route5_SouthEntrance_EventScript_GuardThirsty::
	msgbox Route5_SouthEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route5_SouthEntrance_EventScript_GuardSmallTalk
	msgbox Route5_SouthEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route5_SouthEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

Route5_SouthEntrance_Text_ThirstyOnGuardDuty::
    .string "Estou de serviço de guarda.\n"
    .string "Nossa, mas que sede que estou!$"

Route5_SouthEntrance_Text_ThatTeaLooksTasty::
    .string "Ah, esse chá…\n"
    .string "Parece tão gostoso…$"

Route5_SouthEntrance_Text_ThanksIllShareTeaWithGuards::
    .string "Hã? Essa bebida é para mim?\n"
    .string "Puxa, muito obrigado!\l"
    .string "… …\l"
    .string "Glub, glub…\l"
    .string "… …\l"
    .string "Glup…\l"
    .string "… …\l"
    .string "Caiu como uma luva!…\p"
    .string "Vou dividir esse chá com os outros\n"
    .string "guardas!$"

Route5_SouthEntrance_EventScript_DenyGuard::
	msgbox Route5_SouthEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route5_SouthEntrance_Text_ThatsAShame::
	.string "Ah, que pena.\n"
	.string "Eu bem que precisava de uma bebida...$"

Route5_SouthEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route5_SouthEntrance_EventScript_RoadsClosed
	release
	end

Route5_SouthEntrance_EventScript_Jenny::
	msgbox Route5_SouthEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route5_SouthEntrance_EventScript_DeliverRocketPlans
	release
	end

Route5_SouthEntrance_Text_TipAboutTeamRocket::
	.string "Recebemos uma denúncia de que a Equipe Rocket\n"
	.string "pode passar por aqui, então não podemos\l"
	.string "deixar ninguém passar agora.$"

Route5_SouthEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route5_SouthEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route5_SouthEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route5_SouthEntrance_Text_DeliverRocketPlans::
	.string "O quê? Você encontrou planos da\n"
	.string "Equipe Rocket?\p"
	.string "É bom não ser brincadeira, jovem.\p"
	.string "Deixe-me ver isso...\n"
	.string "... ... ...\p"
	.string "Eles parecem ser autênticos!\p"
	.string "Preciso entregar isto ao\n"
	.string "Inspetor imediatamente!$"

Route5_SouthEntrance_Movement_JennyExit:
	face_down
	walk_in_place_faster_down
	delay_8
	step_end

