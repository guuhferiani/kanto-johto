.set LOCALID_OAK, 1
.set LOCALID_SAILOR, 7
.set LOCALID_JENNY, 9
.set LOCALID_SQUIRTLE, 10

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VermilionCity_OnResume
	.byte 0

VermilionCity_OnTransition:
	setflag FLAG_VISITED_VERMILION_CITY
	call_if_set FLAG_GOT_SQUIRTLE,  VermillionCity_EventScript_RepositionJenny
	call Common_EventScript_GetDayOrNight
	end

VermillionCity_EventScript_RepositionJenny::
	setobjectxyperm LOCALID_JENNY, 22, 20
	setobjectmovementtype LOCALID_JENNY, MOVEMENT_TYPE_LOOK_AROUND
	return

VermilionCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_Text_CitySign::
    .string "Cidade de Vermilion\n"
    .string "O Porto de Pores do Sol Deslumbrantes$"

@TODO: Change text depending on Snorlax State
VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_Text_SnorlaxBlockingRoute12::
    .string "AVISO!\p"
    .string "A Rota 12 pode estar bloqueada por um\n"
    .string "Pokémon adormecido.\p"
    .string "Faça um desvio pelo Túnel de Pedra até\n"
    .string "o Vilarejo de Lavender.\p"
    .string "Polícia de Vermilion$"

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_Text_PokemonFanClubSign::
    .string "Fã-Clube Pokémon\n"
    .string "Todos os fãs de Pokémon são bem-vindos!$"

VermilionCity_EventScript_GymSign::
	lockall
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

VermilionCity_Text_GymSign::
    .string "Ginásio Pokémon da Cidade de Vermilion\n"
    .string "Líder: Tenente Surge\l"
    .string "O Tenente Relâmpago!$"

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_VermilionHarbor::
    .string "Porto de Vermilion$"

VermilionCity_EventScript_ProfOakTrigger1::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOakTrigger2::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 2
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOakTrigger3::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 3
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOak::
	applymovement LOCALID_OAK, Movement_OakDockApproach
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitse
	playbgm MUS_RG_OAK, 0
	call_if_eq VAR_TEMP_1, 1, VermilionCity_EventScript_OakApproachPlayer1
	call_if_eq VAR_TEMP_1, 2, VermilionCity_EventScript_OakApproachPlayer2
	call_if_eq VAR_TEMP_1, 3, VermilionCity_EventScript_OakApproachPlayer3
	waitmovement 1
	msgbox VermilionCity_Text_VisitedSSAnne, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOak, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_PROF_OAK
	setvar VAR_OAK_LAB_STATE, 9
	release
	msgbox VermilionCity_Text_EnjoySSAnne, MSGBOX_DEFAULT
	call_if_le VAR_TEMP_1, 2, VermilionCity_EventScript_OakExit
	call_if_eq VAR_TEMP_1, 3, VermilionCity_EventScript_OakExitAlt
	waitmovement 1
	removeobject LOCALID_OAK
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadedefaultbgm
	releaseall
	end

Movement_OakDockApproach::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VermilionCity_Text_VisitedSSAnne::
	.string "Carvalho: Ah! {PLAYER}! Você estava indo\n"
	.string "visitar o S.S. Anne?\p"
	.string "Receio que você acabou de perder a minha\n"
	.string "apresentação sobre a Pokédex!\p"
	.string "Como assim, não sabia que eu estaria\n"
	.string "aqui? Que lástima...\p"
	.string "Ah! Já sei! Você tem um Celular,\n"
	.string "não tem? Vou te dar o meu número!\p"
	.string "Assim, posso entrar em contato se surgir\n"
	.string "qualquer novidade. E se quiser, pode\l"
	.string "me ligar para avaliar a sua Pokédex\l"
	.string "mesmo enquanto estiver explorando!$"

VermilionCity_Text_EnjoySSAnne::
	.string "Carvalho: Foi ótimo ver você!\n"
	.string "Aproveite o seu tempo no S.S. Anne.\p"
	.string "Muitos treinadores fortes estão reunidos\n"
	.string "por lá, mas não se distraia demais da\l"
	.string "sua missão com a Pokédex!$"

VermilionCity_EventScript_OakApproachPlayer1::
	applymovement LOCALID_OAK, Movement_OakDockEntrance1
	return

Movement_OakDockEntrance1::
	walk_up
	walk_up
	walk_left
	face_up
	step_end

VermilionCity_EventScript_OakApproachPlayer2::
	applymovement LOCALID_OAK, Movement_OakDockEntrance2
	return

Movement_OakDockEntrance2::
	walk_up
	walk_up
	step_end

VermilionCity_EventScript_OakApproachPlayer3::
	applymovement LOCALID_OAK, Movement_OakDockEntrance3
	return

Movement_OakDockEntrance3::
	walk_up
	walk_up
	walk_right
	face_up
	step_end

VermilionCity_EventScript_OakExit::
	applymovement LOCALID_OAK, Movement_OakDockExit
	return

Movement_OakDockExit::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VermilionCity_EventScript_OakExitAlt::
	applymovement LOCALID_OAK, Movement_OakDockExitAlt
	return

Movement_OakDockExitAlt::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end


VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_SS_ANNE_STATE, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
    .string "Você viu o S.S. Anne ancorado\n"
    .string "aqui no porto?$"

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_Text_SSAnneHasDepartedForYear::
    .string "Então o S.S. Anne já zarpou?\p"
    .string "Ele voltará para Vermilion mais ou\n"
    .string "menos nesta mesma época no ano que vem.$"

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_Text_GrimerMultipliesInSludge::
    .string "Tomamos muito cuidado com a poluição aqui.\p"
    .string "Ouvimos dizer que Grimer se multiplica\n"
    .string "em lodo tóxico.$"

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_Text_BuildingOnThisLand::
    .string "Estou construindo um prédio neste\n"
    .string "terreno. Sou o dono de tudo.\p"
    .string "Meu Pokémon está compactando a terra\n"
    .string "para preparar as fundações.$"

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop, MSGBOX_NPC
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat, MSGBOX_NPC
	release
	end

VermilionCity_Text_Machop::
    .string "Machop: Guoh! Gogogoh!$"

VermilionCity_Text_MachopStompingLandFlat::
    .string "Um Machop está pisoteando o solo para nivelá-lo.$"

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_Text_SSAnneVisitsOnceAYear::
    .string "O S.S. Anne é um famoso navio de luxo.\p"
    .string "Ele visita Vermilion uma vez por ano.$"

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_ANNE_STATE, 3, VermilionCity_EventScript_CheckSSTidal
	msgbox VermilionCity_Text_WelcomeToTheSSAnne, MSGBOX_NPC
	release
	end

VermilionCity_Text_WelcomeToTheSSAnne::
    .string "Marinheiro: Bem-vindo ao S.S. Anne!$"

VermilionCity_EventScript_CheckSSTidal::
	goto_if_unset FLAG_HIDE_SS_TIDAL, VermilionCity_EventScript_SSTidalArrived
	msgbox VermilionCity_Text_TheShipSetSail, MSGBOX_NPC
	release
	end

VermilionCity_Text_TheShipSetSail::
    .string "O navio partiu.$"

VermilionCity_EventScript_SSTidalArrived::
	.string "Já ouviu as novidades?\p"
	.string "Um navio novinho, o S.S. Tidal,\n"
	.string "acabou de atracar no porto!$"

VermilionCity_EventScript_TicketCheckTrigger1::
	lock
	setvar VAR_TEMP_2, 1
	goto VermilionCity_EventScript_TicketCheck
	end

VermilionCity_EventScript_TicketCheckTrigger2::
	lock
	setvar VAR_TEMP_2, 2
	goto VermilionCity_EventScript_TicketCheck
	end

VermilionCity_EventScript_TicketCheck::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_TicketCheck1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_TicketCheck2
	waitmovement 7
	msgbox VermilionCity_Text_DoYouHaveATicket, MSGBOX_NPC
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	playse SE_PIN
	msgbox VermilionCity_Text_FlashedSSTicket, MSGBOX_DEFAULT
	setvar VAR_SS_TICKET_CHECK, 1
	waitse
	msgbox VermilionCity_Text_SailorGreat, MSGBOX_NPC
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_MoveSailor1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_MoveSailor2
	end

VermilionCity_Text_DoYouHaveATicket::
    .string "Marinheiro: Bem-vindo ao S.S. Anne!\p"
    .string "Com licença, você tem um bilhete?$"

VermilionCity_Text_FlashedSSTicket::
    .string "{PLAYER} mostrou o BILHETE do S.S. Anne!$"

VermilionCity_Text_SailorGreat:: 
    .string "Marinheiro: Maravilha!\n"
    .string "Seja bem-vindo a bordo do S.S. Anne!$"

VermilionCity_EventScript_TicketCheck1::
	applymovement LOCALID_SAILOR, Movement_TicketCheck1
	return

Movement_TicketCheck1::
	walk_left
	walk_left
	face_up
	step_end

VermilionCity_EventScript_TicketCheck2::
	applymovement LOCALID_SAILOR, Movement_TicketCheck2
	return

Movement_TicketCheck2::
	walk_left
	face_up
	step_end

VermilionCity_EventScript_NoTicket::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark 
	waitmovement 0
	waitse
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_MoveSailor1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_MoveSailor2
	waitmovement 7
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CannotEnterSSAnne
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

VermilionCity_Text_DontHaveNeededSSTicket::
    .string "Desculpe!\p"
    .string "Você precisa de um Bilhete do S.S. Anne\n"
    .string "para poder embarcar.$"

VermilionCity_EventScript_MoveSailor1::
	applymovement LOCALID_SAILOR, Movement_MoveSailor1
	return

Movement_MoveSailor1::
	walk_right
	walk_right
	face_up
	step_end

VermilionCity_EventScript_MoveSailor2::
	applymovement LOCALID_SAILOR, Movement_MoveSailor2
	return

Movement_MoveSailor2::
	walk_right
	face_up
	step_end

Movement_CannotEnterSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_SS_TICKET_CHECK, 0
	releaseall
	end

VermilionCity_EventScript_SquirtleEventAlternate::
	setvar VAR_GOT_SQUIRTLE, 2
VermilionCity_EventScript_SquirtleEvent::
	lockall
	turnobject LOCALID_JENNY, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitse
	msgbox VermilionCity_Text_SquirtleIsAMenace, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE03_GET, VermilionCity_EventScript_DontGiveSquirtle
	call_if_eq VAR_GOT_SQUIRTLE, 2, VermilionCity_EventScript_Sidestep
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepForward
	waitmovement 0
	playse SE_PIN
	message VermilionCity_Text_PlayerFlashedBadge
	waitse
	waitmessage
	msgbox VermilionCity_Text_AStrongTrainer, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_JENNY, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_SQUIRTLE, Movement_MoveToPlayer
	waitmovement 10
	playse SE_PIN
	applymovement LOCALID_SQUIRTLE, Common_Movement_Heart
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	random 128
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, 1, VermilionCity_EventScript_SquirtleEventLucky
    setvar VAR_0x8004, 0
	givemon SPECIES_SQUIRTLE, 10, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, 0, VermilionCity_EventScript_SquirtleParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_EventScript_SquirtlePC
	goto_if_eq VAR_RESULT, 2, VermilionCity_EventScript_NoRoomForSquirtle
	releaseall
	end

VermilionCity_EventScript_SquirtleEventLucky::
	setvar VAR_0x8004, 0
    setflag FLAG_SHINY_CREATION
	givemon SPECIES_SQUIRTLE, 10, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, 0, VermilionCity_EventScript_SquirtleParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_EventScript_SquirtlePC
	goto_if_eq VAR_RESULT, 2, VermilionCity_EventScript_NoRoomForSquirtle
	releaseall
	end

VermilionCity_EventScript_SquirtleParty::
	call VermilionCity_EventScript_GetSquirtle
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_GotSquirtle
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VermilionCity_EventScript_GotSquirtle
	end

VermilionCity_EventScript_GetSquirtle::
	playfanfare MUS_LEVEL_UP
	message VermilionCity_EventScript_Text_BailedOutSquirtle
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	return

VermilionCity_EventScript_Text_BailedOutSquirtle::
	.string "{PLAYER} pagou a fiança do Squirtle!$"

VermilionCity_EventScript_GotSquirtle::
	setflag FLAG_GOT_SQUIRTLE
	setvar VAR_GOT_SQUIRTLE, 1
	removeobject LOCALID_SQUIRTLE
	release
	end

VermilionCity_EventScript_SquirtlePC::
	call VermilionCity_EventScript_GetSquirtle
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_TransferSquirtle
	call Common_EventScript_NameReceivedBoxMon
	goto VermilionCity_EventScript_TransferSquirtle
	end

VermilionCity_EventScript_TransferSquirtle::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	call Common_EventScript_TransferredToPC
	goto VermilionCity_EventScript_GotSquirtle
	end

VermilionCity_EventScript_NoRoomForSquirtle::
	msgbox VermilionCity_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	applymovement LOCALID_SQUIRTLE, Movement_SquirtleReturn
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	release
	end

Movement_SquirtleReturn::
	walk_right
	walk_up
	face_left
	step_end

VermilionCity_Text_NoRoomForMorePokemon::
    .string "Oficial: Não tem espaço na equipe?\n"
    .string "Então é direto para o xilindró!$"

VermilionCity_EventScript_Sidestep::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Sidestep
	waitmovement 0
	return

Movement_Sidestep::
	walk_left
	step_end

Movement_MoveToPlayer::
	walk_down
	walk_left
	step_end

VermilionCity_Text_PlayerFlashedBadge::
	.string "{PLAYER} mostrou a Insígnia do Trovão.$"

VermilionCity_Text_AStrongTrainer::
	.string "Oficial: Ah! Você tem uma Insígnia do Trovão?\p"
	.string "Você deve ser um treinador bem forte.\p"
	.string "Como é que é?\p"
	.string "Está dizendo que você se responsabiliza\n"
	.string "por este Pokémon?\p"
	.string "...\p"
	.string "Não tenho certeza do que meu chefe vai\n"
	.string "achar disso, mas tenho um bom pressentimento\l"
	.string "sobre você.\p"
	.string "Afinal de contas, provou suas habilidades\n"
	.string "como treinador Pokémon.\p"
	.string "Talvez um bom exemplo a seguir seja\n"
	.string "justamente o que este Pokémon precisa!$"


VermilionCity_EventScript_DontGiveSquirtle::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	setvar VAR_GOT_SQUIRTLE, 0
	release
	end

 Movement_StepForward::
 	walk_up
 	step_end

VermilionCity_Text_SquirtleIsAMenace::
	.string "Oficial: Afaste-se, cidadão!\p"
	.string "Este Squirtle é uma verdadeira ameaça!\p"
	.string "Ele anda cometendo delitos por toda\n"
	.string "a Cidade de Vermilion!\p"
	.string "Eu o encurralei, mas estou aguardando\n"
	.string "reforços para levá-lo detido!$"

VermilionCity_EventScript_Jenny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SQUIRTLE, VermilionCity_EventScript_JennyGaveSquirtle
	msgbox VermilionCity_Text_SquirtleIsAMenace, MSGBOX_NPC
	release
	end

VermilionCity_EventScript_JennyGaveSquirtle::
	msgbox VermilionCity_Text_JennyGaveSquirtle, MSGBOX_NPC
	release
	end

VermilionCity_Text_JennyGaveSquirtle::
	.string "Primeiro eram motoqueiros e ladrões,\n"
	.string "depois foi a Equipe Rocket.\p"
	.string "Este trabalho já é difícil o suficiente\n"
	.string "sem Pokémon entrando para o crime também!$"

VermilionCity_EventScript_Squirtle::
	lock
	faceplayer
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_SquirtleGlasses, MSGBOX_NPC
	release
	end

VermilionCity_Text_SquirtleGlasses::
	.string "Aquele Squirtle está usando óculos escuros?$"
	
VermilionCity_EventScript_Blastoisinite::
	finditem ITEM_BLASTOISINITE, 1
	setflag FLAG_GOT_BLASTOISINITE
	goto_if_unset FLAG_FIRST_MEGASTONE, VermilionCity_EventScript_FoundMegaStone
    end

VermilionCity_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end
