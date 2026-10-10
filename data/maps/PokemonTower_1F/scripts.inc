PokemonTower_1F_MapScripts::
	.byte 0

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
    .string "Eu sou uma Médium.\p"
    .string "Há espíritos tramando travessuras.\n"
    .string "Posso senti-los no topo da torre.$"

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_CueBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM42, PokemonTower_1F_EventScript_CueBall2
	msgbox PokemonTower_1F_Text_IDontNeedThis, MSGBOX_NPC
	giveitem ITEM_TM42, 1
	waitmessage
	setflag FLAG_GOT_TM42	
	releaseall
	end

PokemonTower_1F_Text_IDontNeedThis::
	.string "Oh... snif...\n"
	.string "Nuffle... sinto tanta sua falta!\p"
	.string "Tome... eu não preciso disto...$"

PokemonTower_1F_EventScript_CueBall2::
	msgbox PokemonTower_1F_Text_BraveFace, MSGBOX_NPC
	release
	end

PokemonTower_1F_Text_BraveFace::
	.string "Sempre que batalhávamos, eu\n"
	.string "conseguia mostrar coragem\l"
	.string "pelo meu Pokémon.\p"
	.string "Mas agora, não consigo mais\n"
	.string "manter as aparências...$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
    .string "Meu Growlithe…\n"
    .string "Por que você morreu?$"


PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	msgbox PokemonTower_1F_Text_ComeToPayRespects, MSGBOX_NPC
	release
	end

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
    .string "Vim rezar pela minha querida\n"
    .string "Clefairy que se foi.\p"
    .string "Snif!\n"
    .string "Estou em lágrimas…$"

PokemonTower_1F_Text_ComeToPayRespects::
    .string "Você veio prestar homenagens?\p"
    .string "Que coração bondoso você tem por amar\n"
    .string "tanto os Pokémon.$"

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
    .string "A Torre Pokémon foi erguida em memória\n"
    .string "dos Pokémon que faleceram.$"
