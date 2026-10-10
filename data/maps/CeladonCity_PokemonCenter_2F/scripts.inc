CeladonCity_PokemonCenter_2F_MapScripts::
	.byte 0

CeladonCity_PokemonCenter_2F_Shopper::
	lock
	faceplayer
	msgbox CeladonCity_PokemonCenter_2F_Shopping, MSGBOX_DEFAULT
	release
	end

CeladonCity_PokemonCenter_2F_Shopping::
	.string "Os Serviços da Liga aqui têm opções\n"
	.string "interessantes, mas prefiro fazer\l"
	.string "minhas compras na Loja de Departamentos.$"
