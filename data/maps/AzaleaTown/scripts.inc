AzaleaTown_MapScripts::
	.byte 0

AzaleaTown_EventScript_KurtOutside::
	lock
	faceplayer
	goto_if_set FLAG_CLEARED_SLOWPOKE_WELL, AzaleaTown_EventScript_KurtSaved
	msgbox AzaleaTown_Text_KurtHelpWell, MSGBOX_DEFAULT
	release
	end

AzaleaTown_EventScript_KurtSaved::
	msgbox AzaleaTown_Text_KurtVisitHouse, MSGBOX_DEFAULT
	release
	end

AzaleaTown_EventScript_Slowpoke::
	lock
	faceplayer
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	msgbox AzaleaTown_Text_Slowpoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

AzaleaTown_EventScript_BugCatcher::
	msgbox AzaleaTown_Text_BugCatcher, MSGBOX_NPC
	end

AzaleaTown_EventScript_TownSign::
	msgbox AzaleaTown_Text_TownSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_GymSign::
	msgbox AzaleaTown_Text_GymSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_WellSign::
	msgbox AzaleaTown_Text_WellSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KurtSign::
	msgbox AzaleaTown_Text_KurtSign, MSGBOX_SIGN
	end

AzaleaTown_Text_KurtHelpWell::
	.string "Kurt: Rápido, treinador!\n"
	.string "Remanescentes da Equipe Rocket\l"
	.string "invadiram o Poço dos Slowpoke ao\l"
	.string "norte da cidade!\p"
	.string "Por favor, ajude a expulsá-los no\n"
	.string "prédio do Poço ao norte!$"

AzaleaTown_Text_KurtVisitHouse::
	.string "Kurt: Graças a você, os Slowpoke\n"
	.string "voltaram a viver em paz em Azalea!\p"
	.string "Entre na minha casa logo aqui atrás\n"
	.string "para receber minhas Poké Bolas\l"
	.string "artesanais!$"

AzaleaTown_Text_Slowpoke::
	.string "Slowpoke: Slooow... poke?$"

AzaleaTown_Text_BugCatcher::
	.string "O Ginásio de Bugsy fica aqui em\n"
	.string "Azalea! E o portão ao sudoeste\l"
	.string "leva direto para a Floresta Ilex!$"

AzaleaTown_Text_TownSign::
	.string "AZALEA TOWN\n"
	.string "Onde Pessoas e Pokémon Vivem em\l"
	.string "Feliz Harmonia!\p"
	.string "Oeste/Sul: Entrada da Floresta Ilex$"

AzaleaTown_Text_GymSign::
	.string "GINÁSIO POKÉMON DE AZALEA TOWN\n"
	.string "Líder: Bugsy\l"
	.string "A Enciclopédia Ambulante de\l"
	.string "Pokémon Inseto!$"

AzaleaTown_Text_WellSign::
	.string "POÇO DOS SLOWPOKE\n"
	.string "Também conhecido como Poço da Chuva.$"

AzaleaTown_Text_KurtSign::
	.string "CASA DO KURT\n"
	.string "Artesão Mestre de Poké Bolas$"
