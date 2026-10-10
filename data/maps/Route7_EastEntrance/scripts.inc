.set LOCALID_JENNY, 1

Route7_EastEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route7_EastEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route7_EastEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route7_EastEntrance_EventScript_RoadsClosed
	msgbox Route7_EastEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route7_EastEntrance_Text_HiHowsItGoing::
    .string "Oi, como vão as coisas?$"

Route7_EastEntrance_EventScript_RoadsClosed::
	msgbox Route7_EastEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route7_EastEntrance_Text_RoadsClosed::
    .string "Ah, a propósito, a via está bloqueada.\p"
    .string "A Polícia Internacional está caçando\n"
    .string "a Equipe Rocket!$"

Route7_EastEntrance_EventScript_GuardThirsty::
	msgbox Route7_EastEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route7_EastEntrance_EventScript_GuardSmallTalk
	msgbox Route7_EastEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route7_EastEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route7_EastEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

Route7_EastEntrance_Text_ThirstyOnGuardDuty::
    .string "Estou de serviço como guarda.\n"
    .string "Nossa, que sede que eu tô!$"

Route7_EastEntrance_Text_ThatTeaLooksTasty::
    .string "Ah, esse chá…\n"
    .string "Parece tão saboroso…$"

Route7_EastEntrance_Text_ThanksIllShareTeaWithGuards::
    .string "Hã? Posso beber isto?\n"
    .string "Puxa, muito obrigado!\l"
    .string "… …\l"
    .string "Glub, glub…\l"
    .string "… …\l"
    .string "Glup…\l"
    .string "… …\l"
    .string "Caiu feito uma luva!…\p"
    .string "Vou compartilhar este chá com os\n"
    .string "outros guardas!$"

Route7_EastEntrance_EventScript_DenyGuard::
	msgbox Route7_EastEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route7_EastEntrance_Text_ThatsAShame::
	.string "Ah, que pena.\n"
	.string "Eu realmente precisava de algo para beber...$"

Route7_EastEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route7_EastEntrance_EventScript_RoadsClosed
	release
	end

Route7_EastEntrance_EventScript_Jenny::
	msgbox Route7_EastEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route7_EastEntrance_EventScript_DeliverRocketPlans
	release
	end

Route7_EastEntrance_Text_TipAboutTeamRocket::
	.string "Recebemos uma denúncia de que a Equipe\n"
	.string "Rocket pode passar por aqui, então não\l"
	.string "podemos deixar ninguém passar agora.$"

Route7_EastEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route7_EastEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route7_EastEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route7_EastEntrance_Text_DeliverRocketPlans::
	.string "O quê? Você encontrou planos da\n"
	.string "Equipe Rocket?\p"
	.string "É bom que isso não seja pegadinha, jovem.\p"
	.string "Deixe-me ver isso...\n"
	.string "... ... ...\p"
	.string "Eles parecem autênticos!\p"
	.string "Preciso entregar isto ao Inspetor\n"
	.string "imediatamente!$"

Route7_EastEntrance_Movement_JennyExit:
	face_right
	walk_in_place_faster_right
	delay_8
	step_end

