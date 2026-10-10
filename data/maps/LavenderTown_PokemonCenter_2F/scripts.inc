LavenderTown_PokemonCenter_2F_MapScripts::
	.byte 0


LavenderTown_PokemonCenter_2F_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, LavenderTown_PokemonCenter_2F_EventScript_OldWoman2
	msgbox LavenderTown_PokemonCenter_2F_Text_SilkScarf, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_SILK_SCARF, 1
	setflag FLAG_GOT_SILK_SCARF
	release
	end

LavenderTown_PokemonCenter_2F_Text_SilkScarf::
	.string "Isto era do meu Meowth...\n"
	.string "Ele sempre ficava tão elegante...\p"
	.string "Acho que ele gostaria que ficasse\n"
	.string "com você...$"

LavenderTown_PokemonCenter_2F_EventScript_OldWoman2::
	lock
	faceplayer
	msgbox LavenderTown_PokemonCenter_2F_Text_FancyPants, MSGBOX_DEFAULT
	release
	end

LavenderTown_PokemonCenter_2F_Text_FancyPants::
	.string "Pokémon são mais que animais de estimação.\n"
	.string "Eles são amigos e família.$"
