RockTunnel_B1F_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_ItemRevive::
	finditem ITEM_REVIVE, 1
	release
	end

RockTunnel_B1F_EventScript_ItemPowerStone::
    finditem ITEM_POWER_STONE, 1
    release
    end

RockTunnel_B1F_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

RockTunnel_B1F_EventScript_Aerodactlyite::
    finditem ITEM_AERODACTYLITE, 1
    setflag FLAG_GOT_AERODACTYLITE
    goto_if_unset FLAG_FIRST_MEGASTONE, RockTunnel_B1F_EventScript_FoundMegaStone
    end

RockTunnel_B1F_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
    .string "Você sabe como evitar se perder\n"
    .string "nas montanhas?\p"
    .string "Você pode dobrar gravetos para marcar\n"
    .string "a trilha.$"

RockTunnel_B1F_Text_SofiaDefeat::
    .string "Aaah!\n"
    .string "Eu dei o meu melhor!$"

RockTunnel_B1F_Text_SofiaPostBattle::
    .string "Eu quero ir para casa!$"

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_MarthaIntro::
    .string "Eu não venho muito aqui, mas vou\n"
    .string "batalhar contra você.$"

RockTunnel_B1F_Text_MarthaDefeat::
    .string "Oh!\n"
    .string "Eu perdi!$"

RockTunnel_B1F_Text_MarthaPostBattle::
    .string "Eu gosto de Pokémon pequenininhos.\n"
    .string "Os grandões dão muito medo!$"

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_DudleyIntro::
    .string "Hahaha!\n"
    .string "Consegue superar a minha força bruta?$"

RockTunnel_B1F_Text_DudleyDefeat::
    .string "Opa!\n"
    .string "Fui superado nos músculos!$"

RockTunnel_B1F_Text_DudleyPostBattle::
    .string "Eu prefiro força bruta porque odeio\n"
    .string "ter que pensar.$"

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_AllenIntro::
    .string "As técnicas dos meus Pokémon vão\n"
    .string "fazer você chorar!$"

RockTunnel_B1F_Text_AllenDefeat::
    .string "Eu me rendo!\n"
    .string "Você tem uma técnica muito melhor!$"

RockTunnel_B1F_Text_AllenPostBattle::
    .string "Nas montanhas, você frequentemente\n"
    .string "encontra Pokémon do tipo Pedra.$"

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_EricIntro::
    .string "Mande o seu melhor golpe!$"

RockTunnel_B1F_Text_EricDefeat::
    .string "Manda ver!$"

RockTunnel_B1F_Text_EricPostBattle::
    .string "Vou treinar meus Pokémon para vencer\n"
    .string "os seus, garoto.$"

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_CooperIntro::
    .string "Você tem uma Pokédex?\n"
    .string "Eu quero uma também.$"

RockTunnel_B1F_Text_CooperDefeat::
    .string "Droga!\n"
    .string "Que inveja de você!$"

RockTunnel_B1F_Text_CooperPostBattle::
    .string "Quando você terminar sua Pokédex,\n"
    .string "pode me dar ela?$"

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SteveIntro::
    .string "Hum… Você conhece cosplay de Pokémon?$"

RockTunnel_B1F_Text_SteveDefeat::
    .string "Bem, fazer o quê.$"

RockTunnel_B1F_Text_StevePostBattle::
    .string "Cosplay de Pokémon é se fantasiar\n"
    .string "de Pokémon por pura diversão.\p"
    .string "Clefairy é um dos favoritos.$"

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_WinstonIntro::
    .string "Eu faço desenhos de Pokémon\n"
    .string "quando estou em casa.$"

RockTunnel_B1F_Text_WinstonDefeat::
    .string "Ufa…\n"
    .string "Estou exausto…$"

RockTunnel_B1F_Text_WinstonPostBattle::
    .string "Sou um artista, não um lutador.\n"
    .string "Vou para casa desenhar.$"

RockTunnel_B1F_EventScript_HelmetGuy::
    lock
    goto_if_set FLAG_GOT_ROCKY_HELMET, RockTunnel_B1F_EventScript_HelmetGuy2
    msgbox RockTunnel_B1F_Text_Helmet, MSGBOX_NPC
    giveitem ITEM_ROCKY_HELMET, 1
    setflag FLAG_GOT_ROCKY_HELMET
    release
    end

RockTunnel_B1F_Text_Helmet::
    .string "Eu estava explorando o túnel aqui\n"
    .string "quando um Geodude usou Autodestruição!\p"
    .string "Isso causou um pequeno desmoronamento.\n"
    .string "Ainda bem que eu estava usando capacete.\p"
    .string "Tome, você devia usar um também!$"

RockTunnel_B1F_EventScript_HelmetGuy2::
    lock
    msgbox RockTunnel_B1F_Text_Helmet2, MSGBOX_NPC
    release
    end

RockTunnel_B1F_Text_Helmet2::
    .string "Às vezes, as rochas contêm itens.\n"
    .string "Mas também podem conter Pokémon!$"
