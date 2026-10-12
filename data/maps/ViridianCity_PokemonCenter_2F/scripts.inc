ViridianCity_PokemonCenter_2F_MapScripts::
	.byte 0

ViridianCity_PokemonCenter_2F_LittleGirl::
	lock
	faceplayer
	msgbox ViridianCity_PokemonCenter_2F_Text_Rank, MSGBOX_DEFAULT
	release
	end

ViridianCity_PokemonCenter_2F_Text_Rank::
	.string "Aquele homem nao me deixa comprar!\n"
	.string "Ele diz que nao tenho rank suficiente!\p"
	.string "O que isso quer dizer afinal?\p"
	.string "Acho que vou ate a proxima cidade\n"
	.string "e tentar a sorte por la.$"

