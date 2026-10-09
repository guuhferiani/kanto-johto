ViridianForest_Erin_House_MapScripts::
	.byte 0

ViridianForest_Erin_House_EventScript_Clefairy::
	lock
	faceplayer
	random 100
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_0x8004, 1, ViridianForest_Erin_House_EventScript_ClefairyLum
	setvar VAR_0x8004, 0
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_ENCOUNTER
	msgbox ViridianForest_Erin_House_Text_Clefairy MSGBOX_DEFAULT
	waitmessage
	msgbox ViridianForest_Erin_House_Text_ClefairyBerryGiven MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_ORAN_BERRY, 1
	release
	end

ViridianForest_Erin_House_EventScript_ClefairyLum::
	setvar VAR_0x8004, 0
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_ENCOUNTER
	msgbox ViridianForest_Erin_House_Text_Clefairy MSGBOX_DEFAULT
	waitmessage
	msgbox ViridianForest_Erin_House_Text_ClefairyBerryGiven MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_LUM_BERRY, 1
	release
	end

ViridianForest_Erin_House_Text_Clefairy:
	.string "Clefairy?$"
	return

ViridianForest_Erin_House_Text_ClefairyBerryGiven:
	.string "Clef fairy!$"	
	return

ViridianForest_Erin_House_EventScript_CoolTrainerErin::
	goto_if_set FLAG_DEFEATED_ERIN, ViridianForest_Erin_House_Defeated
	trainerbattle_single TRAINER_COOLTRAINER_ERIN, ViridianForest_Erin_House_Text_ErinIntro, ViridianForest_Erin_House_Text_ErinDefeat
	setflag FLAG_DEFEATED_ERIN
	msgbox ViridianForest_Erin_House_Text_ErinPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

ViridianForest_Erin_House_Text_ErinIntro:
	.string "Oh, olá novamente, {PLAYER}!\p"
	.string "Parabéns por se tornar o Campeão!\p"
	.string "É difícil acreditar que aquele jovem\n"
	.string "treinador que conheci há um tempo\l"
	.string "é agora o Campeão de Kanto.\p"
	.string "...\p"
	.string "Campeão {PLAYER}, eu te desafio\n"
	.string "para uma batalha Pokémon!$"

ViridianForest_Erin_House_Text_ErinDefeat:
	.string "Uau, digno de um Campeão!$"

ViridianForest_Erin_House_Text_ErinPostBattle:
	.string "Estou muito impressionada com sua\n"
	.string "equipe e a evolução de vocês.\l"
	.string "Clefairy e eu sempre soubemos\l"
	.string "que você iria longe.$"
	
ViridianForest_Erin_House_ChampionCheck::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, ViridianForest_Erin_House_EventScript_CoolTrainerErin
	msgbox ViridianForest_Erin_House_Greetings MSGBOX_DEFAULT
	releaseall
	end

ViridianForest_Erin_House_Greetings:
	.string "Olá! Boas-vindas à minha casa.\p"
	.string "Meu nome é Erin. Eu moro aqui com\n"
	.string "os amigos que fiz pelo caminho.\p"
	.string "Você começou a viajar recentemente\n"
	.string "com seus Pokémon?\p"
	.string "... Entendo. Vá dar um alô para o\n"
	.string "meu Clefairy! Ele tem Frutas Oran\l"
	.string "que seus Pokémon vão adorar.$"

ViridianForest_Erin_House_Defeated::
	msgbox ViridianForest_Erin_House_DefeatedText MSGBOX_DEFAULT
	releaseall
	end

ViridianForest_Erin_House_DefeatedText:	
	.string "Estou muito impressionada com sua\n"
	.string "equipe e a evolução de vocês.\l"
	.string "Clefairy e eu sempre soubemos\l"
	.string "que você iria longe.$"

