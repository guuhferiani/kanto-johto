AzaleaTown_KurtsHouse_MapScripts::
	.byte 0

AzaleaTown_KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KURT_APRICORN_BALLS, AzaleaTown_KurtsHouse_EventScript_KurtAfter
	goto_if_unset FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_KurtsHouse_EventScript_KurtGoToWell
	msgbox AzaleaTown_KurtsHouse_Text_KurtReward, MSGBOX_DEFAULT
	giveitem ITEM_NET_BALL, 5
	giveitem ITEM_NEST_BALL, 5
	giveitem ITEM_TIMER_BALL, 5
	giveitem ITEM_LUXURY_BALL, 5
	setflag FLAG_RECEIVED_KURT_APRICORN_BALLS
	msgbox AzaleaTown_KurtsHouse_Text_KurtIlexShrine, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtGoToWell::
	msgbox AzaleaTown_KurtsHouse_Text_KurtGoToWell, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_KurtAfter::
	msgbox AzaleaTown_KurtsHouse_Text_KurtIlexShrine, MSGBOX_DEFAULT
	release
	end

AzaleaTown_KurtsHouse_EventScript_Maizie::
	msgbox AzaleaTown_KurtsHouse_Text_Maizie, MSGBOX_NPC
	end

AzaleaTown_KurtsHouse_Text_KurtGoToWell::
	.string "Kurt: Precisamos expulsar a Equipe\n"
	.string "Rocket do Poço dos Slowpoke ao\l"
	.string "norte da cidade antes que eu possa\l"
	.string "forjar novas Poké Bolas!$"

AzaleaTown_KurtsHouse_Text_KurtReward::
	.string "Kurt: Magnífico, {PLAYER}!\n"
	.string "Você pôs o Executivo Proton para\l"
	.string "correr e salvou todos os Slowpoke!\p"
	.string "Como prova da minha gratidão, aceite\n"
	.string "este lote especial de Poké Bolas\l"
	.string "forjadas na minha oficina!$"

AzaleaTown_KurtsHouse_Text_KurtIlexShrine::
	.string "Kurt: Sabia que no coração da\n"
	.string "Floresta Ilex existe um Santuário\l"
	.string "dedicado ao guardião do tempo?\p"
	.string "Dizem que quando um treinador de\n"
	.string "coração puro vence o Ginásio de\l"
	.string "Azalea e salva os Slowpoke, Celebi\l"
	.string "aparece no Santuário da floresta!$"

AzaleaTown_KurtsHouse_Text_Maizie::
	.string "Meu avô Kurt conhece todos os\n"
	.string "segredos das Poké Bolas e da\l"
	.string "Floresta Ilex!$"
