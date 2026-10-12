.set LOCALID_WOMAN, 1
.set LOCALID_LASS,  2

ViridianCity_School_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes, MSGBOX_DEFAULT
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 2
	release
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
    .string "Ufa! Estou tentando memorizar todas\n"
    .string "as minhas anotacoes.$"

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully, MSGBOX_DEFAULT
	turnobject LOCALID_WOMAN, DIR_SOUTH
	waitmovement 1
	release
	end

ViridianCity_School_Text_ReadBlackboardCarefully::
    .string "Certo!\p"
    .string "Certifique-se de ler o que esta no\n"
    .string "quadro-negro com atencao!$"

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage, MSGBOX_DEFAULT
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 2
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes, MSGBOX_DEFAULT
	releaseall
	end

ViridianCity_School_Text_TurnThePage::
    .string "Virar a pagina?$"

ViridianCity_School_Text_NotebookFirstPage::
    .string "Vamos conferir o caderno.\p"
    .string "Primeira pagina...\p"
    .string "Poke Bolas sao usadas para capturar\n"
    .string "Pokemon.\p"
    .string "Ate seis Pokemon podem ser levados\n"
    .string "na sua equipe.\p"
    .string "Pessoas que criam e batalham com\n"
    .string "Pokemon sao chamadas de Treinadores.$"

ViridianCity_School_Text_NotebookSecondPage::
    .string "Segunda pagina...\p"
    .string "Um Pokemon saudavel pode ser dificil\n"
    .string "de pegar, entao enfraqueca-o antes.\p"
    .string "Envenene, queime ou cause outro\n"
    .string "problema de status para enfraquece-lo.$"

ViridianCity_School_Text_NotebookThirdPage::
    .string "Terceira pagina...\p"
    .string "Treinadores buscam outros para travar\n"
    .string "batalhas de Pokemon.\p"
    .string "Para os Treinadores, o gosto da\n"
    .string "vitoria e doce, de fato.\p"
    .string "Batalhas sao travadas constantemente\n"
    .string "em Ginasios Pokemon por toda parte.$"

ViridianCity_School_Text_NotebookFourthPage::
    .string "Quarta pagina...\p"
    .string "O objetivo final de todos os\n"
    .string "Treinadores de Pokemon e simples.\p"
    .string "E derrotar os oito Lideres de\n"
    .string "Ginasio de Pokemon.\p"
    .string "Faca isso para ganhar o direito de\n"
    .string "enfrentar...\p"
    .string "A Elite dos Quatro da Liga Pokemon!$"

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_Text_HeyDontLookAtMyNotes::
    .string "Garota: Ei!\n"
    .string "Nao olhe as minhas anotacoes!$"

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_BlackboardListsStatusProblems::
    .string "O quadro-negro lista problemas de\n"
    .string "status dos Pokemon em batalha.$"

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_TRAINER_SCHOOL_WHITEBOARD, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadPoison
	case 1, ViridianCity_School_EventScript_ReadSleep
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case MULTI_B_PRESSED, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_Text_ReadWhichTopic::
    .string "Qual assunto voce quer ler?$"

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainSleep::
    .string "Um Pokemon nao pode atacar se\n"
    .string "estiver dormindo.\p"
    .string "Pokemon continuarao dormindo mesmo\n"
    .string "depois das batalhas.\p"
    .string "Use Awakening para acordar um\n"
    .string "Pokemon adormecido.$"

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainBurn::
    .string "A queimadura reduz o Ataque.\n"
    .string "Tambem causa perda continua de HP.\p"
    .string "A queimadura continua apos a batalha.\n"
    .string "Use Burn Heal para curar a queimadura.$"

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainPoison::
    .string "Quando envenenado, o HP do Pokemon\n"
    .string "cai de forma constante.\p"
    .string "O veneno persiste apos as batalhas.\n"
    .string "Use um Antidote para curar o veneno!$"

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainFreeze::
    .string "Um Pokemon congelado fica totalmente\n"
    .string "imovel e indefeso.\p"
    .string "Ele permanece congelado mesmo apos\n"
    .string "o fim da batalha.\p"
    .string "Use Ice Heal para descongelar o\n"
    .string "pobre Pokemon.$"

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainParalysis::
    .string "A paralisia reduz a Velocidade e\n"
    .string "pode impedir o Pokemon de se mover.\p"
    .string "A paralisia persiste apos batalhas.\n"
    .string "Use Parlyz Heal para o tratamento.$"

ViridianCity_School_EventScript_ExitBlackboard::
	closemessage
	releaseall
	end

ViridianCity_School_EventScript_PokemonJournal::
	lock
	msgbox PokemonJournal_Text_SpecialFeatureProfOak
	release
	end

PokemonJournal_Text_SpecialFeatureProfOak::
	.string "Revista Pokemon\p"
	.string "Especial: Prof. Carvalho,\n"
	.string "o Pesquisador de Pokemon!\p"
	.string "Dizem que o Prof. Carvalho vive com\n"
	.string "seus netos Daisy e {RIVAL}.$"

ViridianCity_School_EventScript_PokemonJournal2::
	lock
	msgbox PokemonJournal_Text_SpecialFeatureDaisyOak
	release
	end

PokemonJournal_Text_SpecialFeatureDaisyOak::
	.string "Esta e uma Revista Pokemon de\n"
	.string "anos atras...\p"
	.string "Revista Pokemon\n"
	.string "Especial do Concurso!\p"
	.string "A Grande Campea do Concurso de\n"
	.string "Pokemon da Primavera e Daisy Carvalho\l"
	.string "de Pallet Town!$"
