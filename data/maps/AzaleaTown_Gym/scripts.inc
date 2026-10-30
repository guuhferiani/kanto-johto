AzaleaTown_Gym_MapScripts::
	.byte 0

AzaleaTown_Gym_EventScript_Bugsy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_BUGSY, AzaleaTown_Gym_EventScript_BugsyDefeated
	msgbox AzaleaTown_Gym_Text_BugsyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_BUGSY, AzaleaTown_Gym_Text_BugsyDefeat
	message AzaleaTown_Gym_Text_ReceivedHiveBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox AzaleaTown_Gym_Text_HiveBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_BUGSY
	giveitem ITEM_SILVER_POWDER, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

AzaleaTown_Gym_EventScript_BugsyDefeated::
	msgbox AzaleaTown_Gym_Text_BugsyPostBattle, MSGBOX_DEFAULT
	release
	end

AzaleaTown_Gym_EventScript_GymGuide::
	msgbox AzaleaTown_Gym_Text_GymGuide, MSGBOX_NPC
	end

AzaleaTown_Gym_Text_BugsyIntro::
	.string "Bugsy: Olá! Eu sou Bugsy!\n"
	.string "Nunca perco quando o assunto são\l"
	.string "Pokémon Inseto!\p"
	.string "Minhas pesquisas provam que os\n"
	.string "Insetos são mais rápidos e letais\l"
	.string "do que qualquer outro tipo!\p"
	.string "Deixe-me mostrar o resultado das\n"
	.string "minhas descobertas em batalha!$"

AzaleaTown_Gym_Text_BugsyDefeat::
	.string "Incrível! Você é um verdadeiro\n"
	.string "especialista em Pokémon!\l"
	.string "Minha pesquisa ainda tem muito a\l"
	.string "aprender!$"

AzaleaTown_Gym_Text_ReceivedHiveBadge::
	.string "{PLAYER} recebeu a INSÍGNIA DA\n"
	.string "COLMEIA de Bugsy!$"

AzaleaTown_Gym_Text_HiveBadgeInfo::
	.string "Bugsy: A Insígnia da Colmeia é a\n"
	.string "segunda insígnia oficial da Liga\l"
	.string "Johto!\p"
	.string "Leve também este Pó de Prata\n"
	.string "(Silver Powder) para fortalecer\l"
	.string "seus ataques do tipo Inseto!$"

AzaleaTown_Gym_Text_BugsyPostBattle::
	.string "Bugsy: A Floresta Ilex fica logo\n"
	.string "a oeste de Azalea Town.\p"
	.string "Atravesse a floresta para chegar\n"
	.string "à Rota 34 e à grande metrópole\l"
	.string "de Goldenrod City!$"

AzaleaTown_Gym_Text_GymGuide::
	.string "E aí, Campeão em construção!\n"
	.string "Bugsy lidera com Scyther, Heracross\l"
	.string "e seu temido Scizor!\p"
	.string "Ataques de Fogo são fatais contra\n"
	.string "Scizor, e ataques Voadores dão\l"
	.string "conta de Heracross!$"
