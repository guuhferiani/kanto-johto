PokemonMansion_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonMansion_1F_OnTransition
	.byte 0

PokemonMansion_1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_1F
	end

PokemonMansion_1F_OnTransition::
	end

PokemonMansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_SCIENTIST_TED, PokemonMansion_1F_Text_TedIntro, PokemonMansion_1F_Text_TedDefeat
	msgbox PokemonMansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_TedIntro::
    .string "Quem é você?\n"
    .string "Não deveria haver ninguém aqui.$"

PokemonMansion_1F_Text_TedDefeat::
    .string "Ai!$"

PokemonMansion_1F_Text_TedPostBattle::
    .string "Uma chave? Não faço ideia do que\n"
    .string "você está falando.$"

PokemonMansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonIntro, PokemonMansion_1F_Text_JohnsonDefeat
	msgbox PokemonMansion_1F_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_JohnsonIntro::
    .string "U-u-uaah! Que susto você me deu!\n"
    .string "Achei que você fosse um fantasma.$"

PokemonMansion_1F_Text_JohnsonDefeat::
    .string "Tsc!\n"
    .string "Não consigo vencer nenhuma.$"

PokemonMansion_1F_Text_JohnsonPostBattle::
    .string "Eu estava explorando aqui sozinho,\n"
    .string "mas estou ficando assustado.\p"
    .string "É melhor eu ir embora logo.$"

PokemonMansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

PokemonMansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	release
	end

PokemonMansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS, 1
	release
	end

PokemonMansion_1F_EventScript_ItemBlackSludge::
	finditem ITEM_BLACK_SLUDGE, 1
	release
	end

PokemonMansion_1F_EventScript_Alakazam::
	lock
	faceplayer
    playmoncry SPECIES_ALAKAZAM, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_JUSTICE, PokemonMansion_1F_EventScript_AlakazamDefeated
	msgbox PokemonMansion_1F_Text_Alakazam MSGBOX_DEFAULT
	release
	end

PokemonMansion_1F_Text_Alakazam:
	.string "Alakazam penetra em sua mente.\n"
	.string "Ele deseja enfrentar sua equipe.$"

PokemonMansion_1F_EventScript_GentlemanJustice::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_JUSTICE, PokemonMansion_1F_EventScript_MegaHintAlakazam
	trainerbattle_single TRAINER_GENTLEMAN_JUSTICE, PokemonMansion_1F_Text_JusticeIntro, PokemonMansion_1F_Text_JusticeDefeat
	setflag FLAG_DEFEATED_JUSTICE
	msgbox PokemonMansion_1F_Text_JusticePostBattle MSGBOX_AUTOCLOSE
	release
	end

PokemonMansion_1F_Text_JusticeIntro:
	.string "Saudações! Eu sou Justice.\p"
	.string "Eu tinha um conhecido que morava aqui\n"
	.string "há décadas e quis revisitar as memórias.\p"
	.string "Você é o Campeão! Ora, ora.\n"
	.string "Que tal uma batalha?$"

PokemonMansion_1F_Text_JusticeDefeat:
	.string "Você realmente faz jus ao título!$"

PokemonMansion_1F_Text_JusticePostBattle:
	.string "As melhores batalhas acontecem nos\n"
	.string "lugares mais inesperados, não acha?$"

PokemonMansion_1F_EventScript_MegaHintAlakazam::    
    goto_if_set FLAG_GOT_ALAKAZITE, PokemonMansion_1F_EventScript_JusticeDefeated
    msgbox PokemonMansion_1F_Text_AlakazamMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
PokemonMansion_1F_Text_AlakazamMegaHint:
    .string "Não precisa perguntar, Alakazam\n"
	.string "já me disse o que você procura.\p"
	.string "Visite um conhecido meu na Cidade\n"
	.string "de Saffron para obter a Mega Pedra.$"

PokemonMansion_1F_EventScript_JusticeDefeated::
    msgbox JusticeDefeated_Text MSGBOX_DEFAULT
	release
	end

JusticeDefeated_Text:	
	.string "Você por acaso conhece o Professor Oak?\p"
	.string "... Entendo, então você é um dos assistentes\n"
	.string "que ele envia para coletar dados.\p"
	.string "... Oh, você também o venceu em uma disputa\n"
	.string "de Campeão? Fascinante!\p"
	.string "Eu conhecia Samuel Oak quando ele era apenas\n"
	.string "uma criança competindo na Liga.\p"
	.string "Eu detive o Título de Campeão por muitos\n"
	.string "anos até que ele me desafiou.\p"
	.string "Sinto-me honrado por testemunhar dois\n"
	.string "prodígios superarem as minhas alturas.$"

PokemonMansion_1F_EventScript_AlakazamDefeated::
	msgbox AlakazamDefeated MSGBOX_DEFAULT
	release
	end

AlakazamDefeated:	
	.string "KA ZAM!\p"
	.string "... visões de um Mega Alakazam\n"
	.string "segurando uma Life Orb e uma Mega Stone\l"
	.string "invadem intensamente a sua mente.$"
