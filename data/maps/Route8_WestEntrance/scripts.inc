.set LOCALID_JENNY, 1

Route8_WestEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route8_WestEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route8_WestEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route8_WestEntrance_EventScript_RoadsClosed
	msgbox Route8_WestEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route8_WestEntrance_Text_HiHowsItGoing::
    .string "Oi, como vão as coisas?$"

Route8_WestEntrance_EventScript_RoadsClosed::
	msgbox Route8_WestEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route8_WestEntrance_Text_RoadsClosed::
    .string "Ah, a propósito, a via está bloqueada.\p"
    .string "A Polícia Internacional está caçando\n"
    .string "a Equipe Rocket!$"

Route8_WestEntrance_EventScript_GuardThirsty::
	msgbox Route8_WestEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route8_WestEntrance_EventScript_GuardSmallTalk
	msgbox Route8_WestEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route8_WestEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

GateGuard_GiveNugget::
	msgbox GateGuard_Text_FoundThis, MSGBOX_NPC
	giveitem ITEM_NUGGET, 1
	release
	end

GateGuard_GiveStone::
	msgbox GateGuard_Text_FoundThis, MSGBOX_NPC
	giveitem ITEM_POWER_STONE, 1
	release
	end

GateGuard_Text_FoundThis::
	.string "Ei, já que compartilhou seu\n"
	.string "Chá comigo, por que não fica\l"
	.string "com isto?\p"
	.string "Está nos Achados e Perdidos há\n"
	.string "uma eternidade, não acho que\l"
	.string "alguém vá vir buscar!$"

GateGuard_ResetSnorlax1::
	goto_if_unset FLAG_HIDE_ROUTE12_SNORLAX, GateGuard_GiveNugget
	msgbox GateGuard_Text_SnorlaxLavender, MSGBOX_NPC
	clearflag FLAG_HIDE_ROUTE12_SNORLAX
	release
	end

GateGuard_Text_SnorlaxLavender:
	.string "Ah, você ouviu falar?\p"
	.string "Um Pokémon enorme foi visto\n"
	.string "dormindo na estrada perto do\l"
	.string "Vilarejo de Lavender!\p"
	.string "Queria poder tirar uma soneca assim.$"

GateGuard_ResetSnorlax2::
	goto_if_unset FLAG_HIDE_ROUTE16_SNORLAX, GateGuard_GiveStone
	msgbox GateGuard_Text_SnorlaxCyclingRoad, MSGBOX_NPC
	clearflag FLAG_HIDE_ROUTE16_SNORLAX
	release
	end

GateGuard_Text_SnorlaxCyclingRoad::
	.string "Ah, você ouviu falar?\p"
	.string "Um Pokémon enorme foi visto\n"
	.string "dormindo na estrada perto da\l"
	.string "Cidade de Celadon!\p"
	.string "Queria poder tirar uma soneca assim.$"

Route8_WestEntrance_Text_ThirstyOnGuardDuty::
    .string "Estou de serviço como guarda.\n"
    .string "Nossa, que sede que eu tô!$"

Route8_WestEntrance_Text_ThatTeaLooksTasty::
    .string "Ah, esse chá…\n"
    .string "Parece tão saboroso…$"

Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards::
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

Route8_WestEntrance_EventScript_DenyGuard::
	msgbox Route8_WestEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route8_WestEntrance_Text_ThatsAShame::
	.string "Ah, que pena.\n"
	.string "Eu realmente precisava de algo para beber...$"

Route8_WestEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route8_WestEntrance_EventScript_RoadsClosed
	release
	end

Route8_WestEntrance_EventScript_Jenny::
	msgbox Route8_WestEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route8_WestEntrance_EventScript_DeliverRocketPlans
	release
	end

Route8_WestEntrance_Text_TipAboutTeamRocket::
	.string "Recebemos uma denúncia de que a Equipe\n"
	.string "Rocket pode passar por aqui, então não\l"
	.string "podemos deixar ninguém passar agora.$"

Route8_WestEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route8_WestEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route8_WestEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route8_WestEntrance_Text_DeliverRocketPlans::
	.string "O quê? Você encontrou planos da\n"
	.string "Equipe Rocket?\p"
	.string "É bom que isso não seja pegadinha, jovem.\p"
	.string "Deixe-me ver isso...\n"
	.string "... ... ...\p"
	.string "Eles parecem autênticos!\p"
	.string "Preciso entregar isto ao Inspetor\n"
	.string "imediatamente!$"

Route8_WestEntrance_Movement_JennyExit:
	face_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_8
	step_end

