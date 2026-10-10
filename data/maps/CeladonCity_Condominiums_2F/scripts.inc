CeladonCity_Condominiums_2F_MapScripts::
	.byte 0

CeladonCity_Condominiums_2F_EventScript_MeetingRoomSign::
	msgbox CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom::
    .string "Sala de Reuniões da Revista Pokémon$"

CeladonCity_Condominiums_2F_EventScript_PokemonJournalErika::
	msgbox PokemonJournal_Text_SpecialFeatureErika, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureErika::
	.string "Revista Pokémon:\p"
	.string "Edição Especial: Líder do Ginásio\n"
	.string "de Celadon, Erika!\p"
	.string "Diz o boato que, se você der uma espiada\n"
	.string "no Ginásio de Celadon, muitas vezes\l"
	.string "verá a Erika tirando um cochilo.$"

CeladonCity_Condominiums_2F_EventScript_danenders::
	lock
	faceplayer
	msgbox CeladonCity_Condominiums_2F_Text_danenders, MSGBOX_NPC
	waitmessage
	turnobject 1, DIR_SOUTH
	release
	end

CeladonCity_Condominiums_2F_Text_danenders:
	.string "Olá, eu sou o danenders.\p"
	.string "Eu criei o jogo que você está jogando!\p"
	.string "Estou trabalhando em outros projetos agora,\n"
	.string "mas obrigado por vir dar um alô.$"

CeladonCity_Condominiums_2F_EventScript_DaniRainbow::
	lock
	faceplayer
	goto_if_set FLAG_MET_MAGAZINE_DANI, CeladonCity_Condominiums_2F_EventScript_DaniRainbowAlreadyMet
	msgbox CeladonCity_Condominiums_2F_Text_DaniRainbowIntroduction, MSGBOX_NPC
	waitmessage
	setflag FLAG_MET_MAGAZINE_DANI
	release
	end

CeladonCity_Condominiums_2F_EventScript_DaniRainbowAlreadyMet::
	msgbox CeladonCity_Condominiums_2F_Text_DaniRainbowAlreadyMet, MSGBOX_NPC
	waitmessage
	release
	end

CeladonCity_Condominiums_2F_Text_DaniRainbowIntroduction:
	.string "Já é hora da nossa entrevista?\p"
	.string "...\p"
	.string "Ah, você não trabalha na editora\n"
	.string "do andar de cima.\p"
	.string "Foi mal!\n"
	.string "Eu sou a Dani, ou melhor, a repórter de\l"
	.string "bugs que virou desenvolvedora.\p"
	.string "Tenho certeza de que o pobre danenders\n"
	.string "já está de saco cheio de mim a essa altura.\p"
	.string "Comecei a trabalhar neste jogo quando\n"
	.string "ele foi para outros projetos.\p"
	.string "Sou mais uma editora do que uma\n"
	.string "desenvolvedora de fato, mas espero que\l"
	.string "esteja curtindo seu tempo no Classic!$"

CeladonCity_Condominiums_2F_Text_DaniRainbowAlreadyMet:
	.string "Olá de novo!\n"
	.string "Eu sou a Dani, a repórter de bugs\l"
	.string "que virou desenvolvedora.\p"
	.string "Tenho certeza de que o pobre danenders\n"
	.string "já está de saco cheio de mim a essa altura.\p"
	.string "Comecei a trabalhar neste jogo quando\n"
	.string "ele foi para outros projetos.\p"
	.string "Sou mais uma editora do que uma\n"
	.string "desenvolvedora de fato, mas espero que\l"
	.string "esteja curtindo seu tempo no Classic!$"

CeladonCity_Condominiums_2F_EventScript_LiquidJustice::
	lock
	faceplayer
	msgbox CeladonCity_Condominiums_2F_Text_LiquidJustice, MSGBOX_NPC
	waitmessage
	turnobject 5, DIR_SOUTH
	release
	end

CeladonCity_Condominiums_2F_Text_LiquidJustice:
	.string "Como vão as coisas?\p"
	.string "Eu sou o LiquidJustice, um dos\n"
	.string "designers do jogo.\p"
	.string "Kanto.\n"
	.string "Toda vez que consigo sair,\l"
	.string "eles me puxam de volta para cá.\p"
	.string "Você já derrotou os Megatreinadores?$"

CeladonCity_Condominiums_2F_EventScript_Headlocker::
	lock
	faceplayer
	msgbox CeladonCity_Condominiums_2F_Text_Headlocker, MSGBOX_NPC
	waitmessage
	turnobject 6, DIR_WEST
	release
	end

CeladonCity_Condominiums_2F_Text_Headlocker:
	.string "Eu sou o Headlocker03, um humilde\n"
	.string "designer deste jogo!\p"
	.string "Tive a sorte de fazer um soul-link\n"
	.string "com esse pessoal.\p"
	.string "Um salve para o danenders e para a\n"
	.string "DaniRainbow pelo trabalho duro deles\l"
	.string "nessa jornada por Kanto!$"

CeladonCity_Condominiums_2F_EventScript_THEWALL::
	lock
	faceplayer
	playmoncry SPECIES_UMBREON, CRY_MODE_NORMAL
	waitmoncry
	msgbox CeladonCity_Condominiums_2F_Text_THEWALL, MSGBOX_DEFAULT
	waitmessage
	release
	end

CeladonCity_Condominiums_2F_Text_THEWALL:
	.string "THE WALL ignora completamente as\n"
	.string "regras e faz o que bem entender.$"

CeladonCity_Condominiums_2F_EventScript_CherryPie::
	lock
	faceplayer
	playmoncry SPECIES_WIGGLYTUFF, CRY_MODE_NORMAL
	waitmoncry
	msgbox CeladonCity_Condominiums_2F_Text_CherryPie, MSGBOX_DEFAULT
	waitmessage
	release
	end

CeladonCity_Condominiums_2F_Text_CherryPie:
	.string "Cherry Pie olha para você com o olhar mais vazio possível.$"

CeladonCity_Condominiums_2F_EventScript_danPikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	release
	end

CeladonCity_Condominiums_2F_EventScript_LiquidArcanine::
	lock
	faceplayer
	playmoncry SPECIES_ARCANINE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

