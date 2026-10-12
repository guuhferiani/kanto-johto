CinnabarIsland_PokemonCenter_2F_MapScripts::
	.byte 0

CinnabarIsland_PokemonCenter_2F_Resident::
	lock
	faceplayer
	msgbox CinnabarIsland_PokemonCenter_2F_Volcano, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonCenter_2F_Volcano::
	.string "Dizem que a Ilha de Cinnabar é\n"
	.string "um vulcão ativo.\p"
	.string "Espero que nunca aconteça nada!$"
