.set LOCALID_CAPTAIN, 1

SSAnne_CaptainsOffice_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_RECEIVED_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	delay 50
	applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 1
	checkitemspace ITEM_HM01, 1
	goto_if_eq VAR_RESULT, FALSE, SSAnne_CaptainsOffice_EventScript_NoRoomForCut
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	playfanfare MUS_OBTAIN_TMHM
	message SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain
	waitfanfare
	waitmessage
	additem ITEM_HM01, 1
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_RECEIVED_HM01
	setvar VAR_SS_ANNE_STATE, 2
	release
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
    .string "Capitão: Ooargh…\n"
    .string "Estou me sentindo horrível…\l"
    .string "Urrp! Enjoado do mar…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
    .string "{PLAYER} massageou as costas\n"
    .string "do Capitão!\p"
    .string "Esfrega, esfrega…\n"
    .string "Esfrega, esfrega, esfrega…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
    .string "Capitão: Ufa! Muito obrigado!\n"
    .string "Estou me sentindo bem melhor agora.\p"
    .string "Você quer ver a minha técnica secreta\n"
    .string "de cortar?\p"
    .string "Eu poderia lhe mostrar a minha técnica\n"
    .string "especial de corte se não estivesse tão mal…\p"
    .string "Já sei! Você pode ficar com isto!\n"
    .string "Esta Máquina Oculta!\p"
    .string "Ensine Cortar aos seus Pokémon e\n"
    .string "você poderá vê-los cortar quando quiser!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
    .string "{PLAYER} obteve o HM01\n"
    .string "do Capitão!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
    .string "Usando o Cortar, você pode derrubar\n"
    .string "árvores pequenas.\p"
    .string "Por que não tenta com as árvores\n"
    .string "ao redor de Vermilion?$"

SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
    .string "Oh, não!\n"
    .string "Você não tem espaço para isto!\p"
    .string "Ai não, estou sentindo outra ânsia\n"
    .string "chegando --- HURGH!!$"

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 1
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
    .string "Capitão: …Ufa!\p"
    .string "Agora que não estou mais enjoado,\n"
    .string "acho que chegou a hora.\p"
    .string "O S.S. Anne zarpará em breve!\p"
    .string "Até logo, até o nosso retorno\n"
    .string "à Cidade de Vermilion!$"

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
    .string "Eca!\n"
    .string "Não deveria ter olhado!$"

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
    .string "Como Vencer o Enjoo Marítimo…\n"
    .string "O Capitão está lendo isto!$"
