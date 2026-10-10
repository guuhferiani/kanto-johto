CeruleanCity_PokemonCenter_2F_MapScripts::
	.byte 0

CeruleanCity_PokemonCenter_2F_Girl::
	lock
	faceplayer
	goto_if_set FLAG_GOT_EVIOLITE, CeruleanCity_PokemonCenter_2F_Girl2
	msgbox CeruleanCity_PokemonCenter_2F_Text_Eviolite, MSGBOX_DEFAULT
	giveitem ITEM_EVIOLITE
	setflag FLAG_GOT_EVIOLITE
	release
	end

CeruleanCity_PokemonCenter_2F_Text_Eviolite::
	.string "Já ouviu falar do Mineral Evolutivo?\p"
	.string "É um item que aumenta as defesas\n"
	.string "de um Pokémon que ainda pode\l"
	.string "evoluir!\p"
	.string "Tome, fique com um!$"

CeruleanCity_PokemonCenter_2F_Girl2::
	msgbox CeruleanCity_PokemonCenter_2F_Oddish, MSGBOX_DEFAULT
	release
	end

CeruleanCity_PokemonCenter_2F_Oddish::
	.string "Eu nunca vou deixar meu Oddish evoluir!\n"
	.string "Ele é fofo demais!$"
