SaffronCity_PokemonCenter_2F_MapScripts::
	.byte 0

SaffronCity_PokemonCenter_2F_Rocket1::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket1, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket1::
	.string "Hehe, dá o fora daqui, pirralho!\n"
	.string "Isto agora é saque da Equipe Rocket!$"


SaffronCity_PokemonCenter_2F_Rocket2::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket2, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket2::
	.string "Ué... esqueci o que viemos fazer aqui.$"

SaffronCity_PokemonCenter_2F_Rocket3::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket3, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket3::
	.string "Uau! Tem coisas realmente raras\n"
	.string "guardadas aqui atrás!\p"
	.string "O Chefe vai adorar esse carregamento!$"


SaffronCity_PokemonCenter_2F_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BLACK_BELT, SaffronCity_PokemonCenter_2F_BlackBelt2
	msgbox SaffronCity_PokemonCenter_2F_Text_Unworthy, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT, 1
	setflag FLAG_RECEIVED_BLACK_BELT
	release
	end

SaffronCity_PokemonCenter_2F_BlackBelt2::
	msgbox SaffronCity_PokemonCenter_2F_Text_Unworthy2, MSGBOX_DEFAULT
	release
	end

SaffronCity_PokemonCenter_2F_Text_Unworthy::
	.string "Eu me sinto envergonhado.\p"
	.string "Quando a Equipe Rocket atacou\n"
	.string "Saffron City, fui incapaz de detê-los.\p"
	.string "Não sou digno disto.$"

SaffronCity_PokemonCenter_2F_Text_Unworthy2::
	.string "Preciso retornar ao Dojo.\n"
	.string "Devo retreinar meu corpo e espírito.$"
