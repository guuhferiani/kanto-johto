CianwoodCity_Gym_MapScripts::
	.byte 0

CianwoodCity_Gym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_CHUCK, CianwoodCity_Gym_EventScript_ChuckDefeated
	msgbox CianwoodCity_Gym_Text_ChuckIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_CHUCK, CianwoodCity_Gym_Text_ChuckDefeat
	message CianwoodCity_Gym_Text_ReceivedStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodCity_Gym_Text_StormBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_CHUCK
	giveitem ITEM_TM01_FOCUS_PUNCH, 1
	giveitem ITEM_BLACK_BELT, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

CianwoodCity_Gym_EventScript_ChuckDefeated::
	msgbox CianwoodCity_Gym_Text_ChuckPostBattle, MSGBOX_DEFAULT
	release
	end

CianwoodCity_Gym_EventScript_GymGuide::
	msgbox CianwoodCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

CianwoodCity_Gym_Text_ChuckIntro::
	.string "Chuck: WAHAHAHA!\n"
	.string "Então você chegou até Cianwood!\p"
	.string "Meus Pokémon Lutadores esmagam\n"
	.string "rochas e treinam sob cachoeiras\l"
	.string "24 horas por dia!\p"
	.string "Não temos nada a ver com palavras:\n"
	.string "vamos decidir tudo nos punhos!$"

CianwoodCity_Gym_Text_ChuckDefeat::
	.string "O quê?! Meus punhos invencíveis\n"
	.string "foram superados?!\l"
	.string "Você merece a Insígnia da\l"
	.string "Tempestade!$"

CianwoodCity_Gym_Text_ReceivedStormBadge::
	.string "{PLAYER} recebeu a INSÍGNIA DA\n"
	.string "TEMPESTADE de Chuck!$"

CianwoodCity_Gym_Text_StormBadgeInfo::
	.string "Chuck: A Insígnia da Tempestade\n"
	.string "é o símbolo dos mestres marciais\l"
	.string "de Johto!\p"
	.string "Leve também a TM01 (Focus Punch)\n"
	.string "e minha Faixa Preta (Black Belt)!$"

CianwoodCity_Gym_Text_ChuckPostBattle::
	.string "Chuck: Com a Insígnia da Tempestade\n"
	.string "em mãos, o lendário Lugia nas\l"
	.string "Whirl Islands ao norte da cidade\l"
	.string "atenderá ao seu chamado!$"

CianwoodCity_Gym_Text_GymGuide::
	.string "E aí, Campeão!\n"
	.string "Chuck usa Primeape, Hitmontop,\l"
	.string "Machamp e Poliwrath Lv. 75!\p"
	.string "Golpes Psíquicos e Voadores são\n"
	.string "devastadores contra sua equipe!$"
