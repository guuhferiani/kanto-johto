CeladonCity_DepartmentStore_3F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_3F_OnTransition
	.byte 0

CeladonCity_DepartmentStore_3F_OnTransition:
	setescapewarp MAP_CELADON_CITY, 15, 16
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1::
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer::
    .string "Pokémon capturados são registrados\n"
    .string "com um Nº de ID e o TO.\p"
    .string "TO significa “Treinador Original” -\n"
    .string "o treinador que o capturou primeiro.$"

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2::
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter::
    .string "Beleza!\p"
    .string "Meu amigo vai trocar o Kangaskhan\n"
    .string "dele pelo meu Haunter!$"

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3::
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade::
    .string "Vamos lá, Haunter!\p"
    .string "Eu amo o Haunter!\n"
    .string "Eu coleciono eles!\p"
    .string "Ué?\p"
    .string "O Haunter se transformou em outro\n"
    .string "Pokémon durante a troca!$"

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl::
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID::
    .string "Você pode identificar Pokémon que\n"
    .string "recebeu em trocas pelos seus Números de ID.$"

CeladonCity_DepartmentStore_3F_EventScript_SuperNES::
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_ItsSuperNES::
    .string "É um Super Nintendo.$"

CeladonCity_DepartmentStore_3F_EventScript_TV1::
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_AnRPG::
    .string "Um RPG!\n"
    .string "Não há tempo para isso agora!$"

CeladonCity_DepartmentStore_3F_EventScript_TV2::
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_SportsGame::
    .string "Um jogo de esportes!\n"
    .string "Papai vai gostar desse!$"

CeladonCity_DepartmentStore_3F_EventScript_TV3::
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_PuzzleGame::
    .string "Um jogo de quebra-cabeça!\n"
    .string "Parece viciante!$"

CeladonCity_DepartmentStore_3F_EventScript_TV4::
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_FightingGame::
    .string "Um jogo de luta!\n"
    .string "Parece difícil!$"

CeladonCity_DepartmentStore_3F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_TVGameShop::
    .string "3º Andar: Loja de Videogames$"

CeladonCity_DepartmentStore_3F_EventScript_Poster::
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon::
    .string "Red e Green!\n"
    .string "Ambos são Pokémon!$"
