VermilionCity_PokemonCenter_2F_MapScripts::
	.byte 0

VermilionCity_PokemonCenter_2F_Pokefan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_DESTINY_KNOT, VermilionCity_PokemonCenter_2F_Pokefan2
	msgbox VermilionCity_PokemonCenter_2F_DestinyKnot, MSGBOX_DEFAULT
	giveitem ITEM_DESTINY_KNOT
	setflag FLAG_GOT_DESTINY_KNOT
	release
	end

VermilionCity_PokemonCenter_2F_DestinyKnot::
	.string "Tive que deixar meu doce Meowth na\n"
	.string "Creche quando fui fazer um cruzeiro.\p"
	.string "Não queria que ele se sentisse só,\n"
	.string "então deixei um presentinho com ele.\p"
	.string "Tome, eu tinha um extra, então você\n"
	.string "deveria ficar com ele!$"

VermilionCity_PokemonCenter_2F_Pokefan2::
	msgbox VermilionCity_PokemonCenter_2F_Daycare, MSGBOX_DEFAULT
	release
	end

VermilionCity_PokemonCenter_2F_Daycare::
	.string "Você já visitou a Creche Pokémon?\n"
	.string "Fica na Rota 5.$"
