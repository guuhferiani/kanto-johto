MahoganyTown_Gym_MapScripts::
	.byte 0

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_PRYCE, MahoganyTown_Gym_EventScript_PryceDefeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_PRYCE, MahoganyTown_Gym_Text_PryceDefeat
	message MahoganyTown_Gym_Text_ReceivedGlacierBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_PRYCE
	giveitem ITEM_TM13_ICE_BEAM, 1
	giveitem ITEM_NEVER_MELT_ICE, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

MahoganyTown_Gym_EventScript_PryceDefeated::
	msgbox MahoganyTown_Gym_Text_PrycePostBattle, MSGBOX_DEFAULT
	release
	end

MahoganyTown_Gym_EventScript_GymGuide::
	msgbox MahoganyTown_Gym_Text_GymGuide, MSGBOX_NPC
	end

MahoganyTown_Gym_Text_PryceIntro::
	.string "Pryce: Eu sou Pryce, o Líder de\n"
	.string "Mahogany Town.\p"
	.string "Mais de 50 invernos rigorosos me\n"
	.string "ensinaram a paciência e a força\l"
	.string "implacável do gelo eterno!\p"
	.string "Mostre-me se o calor dos seus\n"
	.string "laços resiste à minha nevasca!$"

MahoganyTown_Gym_Text_PryceDefeat::
	.string "Ah... Impressionante! O calor da\n"
	.string "sua determinação derreteu meu\l"
	.string "gelo! Receba a Insígnia da Geleira!$"

MahoganyTown_Gym_Text_ReceivedGlacierBadge::
	.string "{PLAYER} recebeu a INSÍGNIA DA\n"
	.string "GELEIRA de Pryce!$"

MahoganyTown_Gym_Text_GlacierBadgeInfo::
	.string "Pryce: A Insígnia da Geleira é a\n"
	.string "sétima insígnia oficial de Johto!\p"
	.string "Leve também a TM13 (Ice Beam) e\n"
	.string "este Gelo Eterno (Never-Melt Ice)!$"

MahoganyTown_Gym_Text_PrycePostBattle::
	.string "Pryce: Agora atravesse a caverna\n"
	.string "Ice Path a oeste ou siga para o\l"
	.string "sul até Blackthorn City, onde\l"
	.string "Clair guarda a última Insígnia!$"

MahoganyTown_Gym_Text_GymGuide::
	.string "E aí, Campeão!\n"
	.string "Pryce usa Dewgong, Jynx, Lapras e\l"
	.string "Piloswine Lv. 76!\p"
	.string "Golpes de Fogo, Lutador, Elétrico\n"
	.string "e Aço são excelentes aqui!$"
