GoldenrodCity_Gym_MapScripts::
	.byte 0

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_WHITNEY, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, GoldenrodCity_Gym_Text_WhitneyDefeat
	message GoldenrodCity_Gym_Text_ReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_PlainBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_WHITNEY
	giveitem ITEM_SILK_SCARF, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	msgbox GoldenrodCity_Gym_Text_WhitneyPostBattle, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_Gym_EventScript_GymGuide::
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

GoldenrodCity_Gym_Text_WhitneyIntro::
	.string "Whitney: Oi! Eu sou a Whitney!\n"
	.string "Todo mundo estava falando de você,\l"
	.string "então eu queria muito ver o quão\l"
	.string "forte o Campeão de Kanto é!\p"
	.string "Pokémon do tipo Normal parecem\n"
	.string "fofinhos, mas a minha Miltank é\l"
	.string "imbatível! Vamos batalhar!$"

GoldenrodCity_Gym_Text_WhitneyDefeat::
	.string "Buáááá! Você é malvado!\n"
	.string "...Sniff... Tá bom, eu paro de\l"
	.string "chorar! Você venceu de verdade!$"

GoldenrodCity_Gym_Text_ReceivedPlainBadge::
	.string "{PLAYER} recebeu a INSÍGNIA DA\n"
	.string "PLANÍCIE de Whitney!$"

GoldenrodCity_Gym_Text_PlainBadgeInfo::
	.string "Whitney: A Insígnia da Planície\n"
	.string "prova que você superou o Ginásio\l"
	.string "de Goldenrod City!\p"
	.string "Fique também com este Lenço de\n"
	.string "Seda (Silk Scarf) para dar mais\l"
	.string "poder aos seus golpes Normais!$"

GoldenrodCity_Gym_Text_WhitneyPostBattle::
	.string "Whitney: A Equipe Rocket está\n"
	.string "causando confusão na Torre de\l"
	.string "Rádio de Goldenrod!\p"
	.string "Por favor, ajude o Diretor na\n"
	.string "Torre de Rádio no centro da cidade!$"

GoldenrodCity_Gym_Text_GymGuide::
	.string "E aí, Campeão!\n"
	.string "Whitney usa Clefable, Ursaring e\l"
	.string "sua famosa Miltank Lv. 67!\p"
	.string "Golpes Lutadores como Brick Break\n"
	.string "e Superpower são a chave para\l"
	.string "vencer rápido!$"
