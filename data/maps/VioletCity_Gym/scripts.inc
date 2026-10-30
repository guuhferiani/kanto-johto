VioletCity_Gym_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_FALKNER, VioletCity_Gym_EventScript_FalknerRematch
	msgbox BattleFrontier_RankingHall_Text_FalknerIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, BattleFrontier_RankingHall_Text_FalknerDefeat
	playfanfare MUS_OBTAIN_BADGE
	msgbox VioletCity_Gym_Text_ReceivedZephyrBadge, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_DEFEATED_LEADER_FALKNER
	msgbox BattleFrontier_RankingHall_Text_FalknerPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

VioletCity_Gym_EventScript_FalknerRematch::
	msgbox BattleFrontier_RankingHall_Text_FalknerRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_FalknerIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, BattleFrontier_RankingHall_Text_FalknerDefeat
	msgbox BattleFrontier_RankingHall_Text_FalknerPostBattle, MSGBOX_DEFAULT
	release
	end

VioletCity_Gym_EventScript_GymGuide::
	msgbox VioletCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

VioletCity_Gym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} recebeu a INSÍGNIA ZÉFIRO\n"
	.string "(Zephyr Badge) de Falkner!$"

VioletCity_Gym_Text_GymGuide:
	.string "E aí, Campeão em construção!\p"
	.string "Falkner é o especialista em Pokémon\n"
	.string "Voadores de Violet City!\p"
	.string "Choques elétricos do seu Pikachu ou\n"
	.string "golpes de Gelo e Pedra derrubarão\l"
	.string "suas aves num piscar de olhos!$"
