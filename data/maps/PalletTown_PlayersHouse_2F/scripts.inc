.set LOCALID_MOM, 1

PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition:
	call SecretBase_EventScript_SetDecorationFlags
	setrespawn HEAL_LOCATION_PLAYERS_HOUSE
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

PalletTown_PlayersHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

PlayersHouse_2F_EventScript_NewGameStart1::
	lockall
	addobject LOCALID_MOM
	playse SE_DOOR
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs1
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame1::
	lockall
	addobject LOCALID_MOM
	playse SE_DOOR
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs1
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

PlayersHouse_2F_EventScript_NewGameStart2::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairsAlt
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs2
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame2::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairsAlt
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs2
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

PlayersHouse_2F_EventScript_NewGameStart3::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_LookAtTheTime, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	msgbox PalletTown_PlayersHouse_2F_Text_GoingToBeLate, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs3
	waitmovement 1
	turnobject LOCALID_MOM, DIR_SOUTH
	msgbox PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_ADVENTURE_BEGINS, 1
	releaseall
	end

PlayersHouse_2F_EventScript_PostGame3::
	lockall
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, MomWalksUpstairs
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	applymovement LOCALID_MOM, WalkToPlayer3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, WalkToStairs3
	waitmovement 1
	applymovement LOCALID_MOM, MomGoesDownstairs
	waitmovement 1
	setflag FLAG_HIDE_MOM_PLAYERS_ROOM
	playse SE_EXIT
	removeobject LOCALID_MOM
	setvar VAR_SECRET_BATTLE_CLEAR, 2
	releaseall
	end

MomWalksUpstairs:
	walk_right
	walk_down
	step_end

MomWalksUpstairsAlt:
	walk_right
	walk_down
	walk_down
	step_end

WalkToPlayer1:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WalkToPlayer2:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

WalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

WalkToStairs1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

WalkToStairs2:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WalkToStairs3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MomGoesDownstairs:
	walk_up
	walk_left
	step_end

PalletTown_PlayersHouse_2F_Text_WeHaveAVisitor:
	.string "Mãe: {PLAYER}! Eu já devia saber\n"
	.string "que encontraria você jogando\l"
	.string "videogame aqui de novo.\p"
	.string "Você deveria descer.\n"
	.string "Alguém está aqui para te ver!$"

PalletTown_PlayersHouse_2F_Text_LookAtTheTime:
	.string "Mãe: {PLAYER}! Aí está você!\p"
	.string "Você ficou jogando videogame\n"
	.string "aqui em cima esse tempo todo?\p"
	.string "Você não deveria se encontrar com o\n"
	.string "Professor Carvalho no laboratório hoje?\p"
	.string "Você sabe que horas são?$"

PalletTown_PlayersHouse_2F_Text_GoingToBeLate:
	.string "É melhor se apressar até o laboratório,\n"
	.string "senão você vai perder o Professor!$"

PalletTown_PlayersHouse_2F_Text_FoldedYourLaundry:
	.string "Ah! Se quiser trocar de roupa\n"
	.string "antes de sair de casa,\l"
	.string "eu guardei suas roupas na cômoda.$"


PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_EventScript_Console::
	lock
	msgbox PlayersHouse_2F_Text_Console, MSGBOX_DEFAULT
	release
	end

PlayersHouse_2F_Text_Console:
	.string "É um videogame antigo.\p"
	.string "Jogos retrô estão com tudo!$"

PlayersHouse_2F_EventScript_ChangeClock::
	lock
	msgbox PlayersHouse_2F_ChangeClockText
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	releaseall
	end
	
PlayersHouse_2F_ChangeClockText:
	.string "Os tempos estão mudando.\n"
	.string "Vamos ajustar as horas.$"
	return

PlayersHouse_2F_EventScript_CheckWallClock2::
	lock
	msgbox PlayersHouse_2F_BeautifulView
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end
	
PlayersHouse_2F_BeautifulView:
	.string "Pokémon brincam na floresta.\n"
	.string "Você sorri e confere as horas.$"
	return
	
PlayersHouse_2F_WelcomeNewPlayers::
	msgbox PlayersHouse_2F_WelcomeNewPlayersText
	releaseall
	end
	
PlayersHouse_2F_WelcomeNewPlayersText:	
	.string "Aperte START para abrir o Menu.\n"
	.string "Salve com frequência durante o jogo.\p"
	.string "Para ver as horas, olhe pela janela\n"
	.string "à direita. Se precisar ajustar a hora,\l"
	.string "inspecione a cortina mágica à esquerda.\p"
	.string "Você pode trocar de roupa usando\n"
	.string "a cômoda ao lado da estante.\p"
	.string "Por fim, sente-se na mesa quando quiser\n"
	.string "para aproveitar o seu próprio PC!$"
	return

PlayersHouse_2F_LetterFromDad::
	lock
	faceplayer
	msgbox Text_LetterOnTower, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LetterOnTower_PlayerAnsweredNo
	msgbox Text_HappyBirthdayLetter, MSGBOX_DEFAULT
	release
	end

LetterOnTower_PlayerAnsweredNo::
	msgbox Text_NoTimeToRead, MSGBOX_DEFAULT
	release
	end

Text_LetterOnTower:
	.string "Há um envelope colado na lateral\n"
	.string "do seu computador. Está escrito\l"
	.string "'Do Papai' do lado de fora.\p"
	.string "Gostaria de ler?$"

Text_HappyBirthdayLetter:
	.string "Papai: Olá, {PLAYER}!\n"
	.string "Feliz Aniversário, filhote!\p"
	.string "Nem acredito que você já tem idade para\n"
	.string "sair em sua própria Jornada Pokémon.\p"
	.string "É uma experiência assustadora e empolgante.\p"
	.string "Sinto muito que, por conta do meu trabalho\n"
	.string "em Hoenn, eu não possa estar aí\l"
	.string "com a sua mãe para a sua despedida.\p"
	.string "Deixei alguns itens para você com a Mamãe,\n"
	.string "ela vai colocá-los no PC do seu quarto\l"
	.string "a tempo de você pegá-los antes de partir.\p"
	.string "Esses itens são ótimos no começo.\n"
	.string "Minha mãe me deu eles quando comecei\l"
	.string "a treinar Pokémon aos 10 anos.\p"
	.string "Na minha jornada, encontrei duas Pepitas\n"
	.string "de ouro e guardei para dias difíceis,\l"
	.string "se faltasse dinheiro para poções.\p"
	.string "Guardei por todos esses anos e agora\n"
	.string "passo para você, para seus dias difíceis.\p"
	.string "Trate seus Pokémon com amor e carinho,\n"
	.string "pois eles retribuem o que recebem.\p"
	.string "Acampar é divertido até as roupas\n"
	.string "molharem, então escolha bem o lugar\l"
	.string "e use sempre a lona de chuva da barraca.\p"
	.string "Seja leal aos seus amigos e ajude\n"
	.string "aqueles que não tiverem amigos por perto.\p"
	.string "Haverá desafios inesperados na sua\n"
	.string "jornada, mas seja paciente consigo mesmo.\l"
	.string "Tenha calma enquanto aprende coisas novas.\p"
	.string "Você não pode controlar o que os outros\n"
	.string "fazem, mas é responsável por como\l"
	.string "escolhe reagir.\p"
	.string "Não perca tempo guardando rancor,\n"
	.string "e viva a vida com amor no coração.\p"
	.string "O destino é uma boa meta, mas não\n"
	.string "se esqueça de aproveitar o caminho.\p"
	.string "Nunca desista de perseguir seus sonhos.\p"
	.string "Entenda que sonhos podem mudar,\n"
	.string "e tudo bem se isso acontecer.\p"
	.string "Tenho muito orgulho da pessoa que você\n"
	.string "se tornou e sei que você irá longe.\p"
	.string "Com amor,\n"
	.string "Papai\p"
	.string "P.S.\n"
	.string "Espero que goste dos biscoitos!\p"
	.string "Eles são uma especialidade de Hoenn.\n"
	.string "Peguei a receita com uma senhora muito gentil\l"
	.string "quando fiz trilha perto de Lavaridge Town.$"
	
Text_NoTimeToRead:
	.string "Agora não, você tem lugares para ir!$"
