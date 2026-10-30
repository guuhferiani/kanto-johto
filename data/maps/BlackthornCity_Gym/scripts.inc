BlackthornCity_Gym_MapScripts::
	.byte 0

BlackthornCity_Gym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_CLAIR, BlackthornCity_Gym_EventScript_ClairDefeated
	msgbox BlackthornCity_Gym_Text_ClairIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_CLAIR, BlackthornCity_Gym_Text_ClairDefeat
	message BlackthornCity_Gym_Text_ReceivedRisingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox BlackthornCity_Gym_Text_RisingBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_CLAIR
	giveitem ITEM_TM02_DRAGON_CLAW, 1
	giveitem ITEM_DRAGON_FANG, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BlackthornCity_Gym_EventScript_ClairDefeated::
	msgbox BlackthornCity_Gym_Text_ClairPostBattle, MSGBOX_DEFAULT
	release
	end

BlackthornCity_Gym_EventScript_GymGuide::
	msgbox BlackthornCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

BlackthornCity_Gym_Text_ClairIntro::
	.string "Clair: Eu sou Clair, a maior\n"
	.string "mestra de Pokémon Dragão do mundo!\p"
	.string "Mesmo que você tenha vencido a\n"
	.string "Liga Kanto e meu primo Lance, não\l"
	.string "espere clemência em Blackthorn!\p"
	.string "Enfrente o rugido dos meus dragões!$"

BlackthornCity_Gym_Text_ClairDefeat::
	.string "O quê?! Como meus dragões foram\n"
	.string "superados?!... Tudo bem, eu\l"
	.string "reconheço: você é digno da\l"
	.string "Insígnia da Ascensão!$"

BlackthornCity_Gym_Text_ReceivedRisingBadge::
	.string "{PLAYER} recebeu a INSÍGNIA DA\n"
	.string "ASCENSÃO de Clair!$"

BlackthornCity_Gym_Text_RisingBadgeInfo::
	.string "Clair: A Insígnia da Ascensão é a\n"
	.string "oitava e última Insígnia de Johto!\p"
	.string "Leve também a TM02 (Dragon Claw)\n"
	.string "e esta Presa de Dragão sagrada!$"

BlackthornCity_Gym_Text_ClairPostBattle::
	.string "Clair: Visite o Mestre Ancião no\n"
	.string "santuário Dragon's Den a noroeste\l"
	.string "da cidade!\p"
	.string "E com todas as 8 Insígnias de\n"
	.string "Johto em mãos, o acesso ao Monte\l"
	.string "Silver está aberto para você\l"
	.string "enfrentar Red!$"

BlackthornCity_Gym_Text_GymGuide::
	.string "E aí, Campeão!\n"
	.string "Clair usa Gyarados, dois Dragonair\l"
	.string "e seu poderoso Kingdra Lv. 78!\p"
	.string "Golpes de Gelo, Fada e Dragão são\n"
	.string "a chave para a vitória!$"
