IndigoPlateau_PokemonCenter_2F_MapScripts::
	.byte 0

IndigoPlateau_PokemonCenter_2F_Trainer::
	lock
	faceplayer
	msgbox IndigoPlateau_PokemonCenter_2F_NervousTrainer, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_2F_NervousTrainer::
	.string "Respira fundo...\n"
	.string "Respira fundo...\p"
	.string "Estou muito nervoso em enfrentar\n"
	.string "a Elite dos Quatro...$"
