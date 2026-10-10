Route4_PokemonCenter_2F_MapScripts::
	.byte 0

Route4_PokemonCenter_2F_Hiker::
	lockall
	faceplayer
	goto_if_set FLAG_GOT_HM06, Route4_PokemonCenter_2F_HikerRockSmash
	msgbox Route4_PokemonCenter_2F_Text_RockSmash, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	waitmessage
	setflag FLAG_GOT_HM06
	msgbox Route4_PokemonCenter_2F_Text_MyGeodude, MSGBOX_DEFAULT
	releaseall
	end


Route4_PokemonCenter_2F_Text_RockSmash::
	.string "Estou procurando Pedras da Lua com os\n"
	.string "meus Pokémon!\p"
	.string "Você deveria tentar também!$"

Route4_PokemonCenter_2F_HikerRockSmash::
	lock
	msgbox Route4_PokemonCenter_2F_Text_MyGeodude, MSGBOX_NPC
	release
	end

Route4_PokemonCenter_2F_Text_MyGeodude::
	.string "Tenha cuidado ao usar o Quebrar Rocha.\n"
	.string "Às vezes, um Pokémon pode saltar para fora!\p"
	.string "Foi assim que conheci o meu Geodude!$"
