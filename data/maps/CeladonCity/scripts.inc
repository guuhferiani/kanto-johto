.set LOCALID_FAT_MAN,   1
.set LOCALID_POLIWRATH, 2
.set LOCALID_FUGITIVE, 17

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeladonCity_OnResume
	.byte 0

CeladonCity_OnTransition:
	setflag FLAG_VISITED_CELADON_CITY
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_EventScript_ItemEther::
	finditem ITEM_ETHER, 1
	release
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 1
	release
	end

CeladonCity_Text_MyTrustedPalPoliwrath::
    .string "Este é o meu grande amigo, Poliwrath.\p"
    .string "Ele evoluiu de um Poliwhirl quando\n"
    .string "usei uma Pedra da Água.$"

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 2
	release
	end

CeladonCity_Text_Poliwrath::
    .string "Poliwrath: Ribi ribit!$"

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_Text_ScaldedTongueOnTea::
    .string "Aaaagh, ai…\n"
    .string "Queimei minha língua!\p"
    .string "Aquela velhinha gentil na Mansão\n"
    .string "me deu um pouco de Chá.\p"
    .string "Mas estava fervendo de quente!\n"
    .string "Tem que esperar esfriar para beber.$"

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_Text_GameCornerIsBadForCitysImage::
    .string "Celadon se orgulha de seus esforços\n"
    .string "para manter a cidade linda.\p"
    .string "Por isso o novo Cassino é tão\n"
    .string "ruim para a imagem da cidade.$"

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_Text_KeepOutOfTeamRocketsWay::
    .string "Fique fora do caminho da Equipe Rocket!$"

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_Text_GetLostOrIllPunchYou::
    .string "Tá olhando o quê?\n"
    .string "Dê o fora ou te encho de pancada.$"

CeladonCity_EventScript_Breeder::
	goto_if_set FLAG_RESCUED_CUBONE, CeladonCity_EventScript_BreederRescuedCubone 
	msgbox CeladonCity_Text_KidnappedPokemon, MSGBOX_NPC
	end

CeladonCity_Text_KidnappedPokemon::
    .string "Ai, o que eu vou fazer…\p"
    .string "A Equipe Rocket anda sequestrando\n"
    .string "Pokémon.\p"
    .string "Eu persegui um Recruta Rocket com um\n"
    .string "Cubone desde Lavender!\p"
    .string "Eles vieram correndo por aqui,\n"
    .string "tenho certeza absoluta.\p"
    .string "Mas acabei perdendo ele de vista!\n"
    .string "Onde será que estão escondidos?$"

CeladonCity_EventScript_BreederRescuedCubone::
	msgbox CeladonCity_Text_RescuedCubone, MSGBOX_NPC
	end

CeladonCity_Text_RescuedCubone::
    .string "Ah! Você resgatou o Cubone da\n"
    .string "Equipe Rocket?\p"
    .string "Isso é maravilhoso!$"

CeladonCity_EventScript_OldMan::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Text_BlewItAllAtSlots::
    .string "Ai, ai…\n"
    .string "Perdi tudo nas máquinas caça-níqueis!\p"
    .string "Eu sabia que devia ter trocado minhas\n"
    .string "Fichas por prêmios!$"

CeladonCity_EventScript_Pervert::
    msgbox CeladonCity_Text_OwOwOw, MSGBOX_NPC
    end

CeladonCity_Text_OwOwOw::
    .string "Ei! Não aperte tanto!\n"
    .string "Ai ai ai!$"

CeladonCity_EventScript_Jenny::
    msgbox CeladonCity_Text_CaughtThisCreep, MSGBOX_NPC
    end

CeladonCity_Text_CaughtThisCreep::
    .string "Fique quieto, tarado.\n"
    .string "Você vem comigo.$"

CeladonCity_EventScript_Police::
    msgbox CeladonCity_Text_GettingComplaints, MSGBOX_NPC
    end

CeladonCity_Text_GettingComplaints::
    .string "Recebemos várias denúncias de\n"
    .string "treinadoras do Ginásio da Erika\l"
    .string "sobre alguém importunando elas.$"

CeladonCity_EventScript_GymSign::
	lockall
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_Text_GymSign::
    .string "Ginásio Pokémon da Cidade de Celadon\n"
    .string "Líder: Erika\l"
    .string "A Princesa Amante da Natureza!$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_Text_CitySign::
    .string "Cidade de Celadon\n"
    .string "A Cidade dos Sonhos do Arco-Íris$"

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_Text_DeptStoreSign::
    .string "Encontre tudo o que precisa na\n"
    .string "Loja de Departamentos de Celadon!$"

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_Text_MansionSign::
    .string "Mansão Celadon$"

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_Text_ExplainXAccuracyDireHit::
    .string "Dicas para Treinadores:\p"
    .string "Precisão X aumenta a precisão dos\n"
    .string "golpes.\p"
    .string "Golpe Crítico aumenta as chances\n"
    .string "de acertar acertos críticos.\p"
    .string "Compre seus itens na Loja de\n"
    .string "Departamentos de Celadon!$"

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_Text_GuardSpecProtectsFromStatus::
    .string "Dicas para Treinadores:\p"
    .string "Guarda Especial protege os Pokémon\n"
    .string "contra reduções de atributos em\l"
    .string "batalha.\p"
    .string "Compre seus itens na Loja de\n"
    .string "Departamentos de Celadon!$"

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_Text_PrizeExchangeSign::
    .string "Fichas trocadas por prêmios!\n"
    .string "Troca de Prêmios$"

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GameCornerSign::
    .string "Cassino Rocket\n"
    .string "Decole Rumo a um Mundo de Riquezas!$"

CeladonCity_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
