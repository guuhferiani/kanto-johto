CinnabarIsland_Lab_ResearchRoom_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
    .string "Eevee pode evoluir para um de três\n"
    .string "tipos de Pokémon.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
    .string "Há uma mensagem de e-mail.\p"
    .string "... ... ...\p"
    .string "Existem três pássaros lendários\n"
    .string "Pokémon.\p"
    .string "Eles são Articuno, Zapdos e\n"
    .string "Moltres.\p"
    .string "Seus paradeiros são desconhecidos.\p"
    .string "Planejamos explorar a caverna\n"
    .string "próxima a Cerulean.\p"
    .string "De: Equipe de Pesquisa Pokémon...$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
    .string "Um cachimbo de âmbar!$"
