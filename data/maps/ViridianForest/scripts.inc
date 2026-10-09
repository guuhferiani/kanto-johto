ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianForest_OnResume
	.byte 0

ViridianForest_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_Text_FriendsItchingToBattle::
    .string "Vim aqui com alguns amigos para\n"
    .string "pegar uns Pokémon Inseto!\p"
    .string "Eles estão loucos para entrar em\n"
    .string "uma batalha Pokémon!$"

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_Text_RanOutOfPokeBalls::
    .string "Eu estava jogando Pokébolas para\n"
    .string "capturar Pokémon, e acabaram.\p"
    .string "Por isso você nunca deve ter\n"
    .string "poucas Pokébolas.$"

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_RickIntro::
    .string "Ei! Você tem Pokémon!\n"
    .string "Venha!\l"
    .string "Vamos batalhar!$"

ViridianForest_Text_RickDefeat::
    .string "Não!\n"
    .string "Caterpie não aguentou!$"

ViridianForest_Text_RickPostBattle::
    .string "Shiu! Vai espantar os insetos.\n"
    .string "Outra hora, tá bom?$"

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_DougIntro::
    .string "E aí!\n"
    .string "Você não pode amarelar se for\l"
    .string "um Treinador Pokémon!$"

ViridianForest_Text_DougDefeat::
    .string "O quê?\n"
    .string "Fiquei sem Pokémon!$"

ViridianForest_Text_DougPostBattle::
    .string "Que droga! Eu vou pegar uns\n"
    .string "mais fortes agora!$"


ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_SammyIntro::
    .string "Ei, espere aí!\n"
    .string "Qual a pressa? Por que correr?$"

ViridianForest_Text_SammyDefeat::
    .string "Eu me rendo!\n"
    .string "Você manda bem nisso!$"

ViridianForest_Text_SammyPostBattle::
    .string "Às vezes, você encontra coisas\n"
    .string "no chão.\p"
    .string "Estou procurando as coisas que\n"
    .string "eu deixei cair. Pode me ajudar?$"

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_AnthonyIntro::
    .string "Posso ser pequeno, mas não vou\n"
    .string "gostar se você pegar leve!$"

ViridianForest_Text_AnthonyDefeat::
    .string "Ah, droga.\n"
    .string "Nada deu certo.$"

ViridianForest_Text_AnthonyPostBattle::
    .string "Perdi parte da minha mesada…$"

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_CharlieIntro::
    .string "Você sabia que Pokémon evoluem?$"

ViridianForest_Text_CharlieDefeat::
    .string "Ah!\n"
    .string "Eu perdi!$"

ViridianForest_Text_CharliePostBattle::
    .string "Pokémon Inseto evoluem rápido.\n"
    .string "Eles são muito divertidos!$"

ViridianForest_EventScript_Lottie::
	trainerbattle_single TRAINER_LASS_LOTTIE, ViridianForest_Text_LottieIntro, ViridianForest_Text_LottieDefeat
	msgbox ViridianForest_Text_LottiePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_LottieIntro::
    .string "Oi, sou a Lottie!\n"
    .string "Você tem um Pikachu?$"

ViridianForest_Text_LottieDefeat::
    .string "Ah não, sério?$"

ViridianForest_Text_LottiePostBattle::
    .string "Procurei por horas, mas nunca\n"
    .string "achei um Pikachu por aqui.$"

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
    .string "Dicas para Treinadores:\p"
    .string "Se seus Pokémon estiverem fracos e\n"
    .string "você quiser evitar batalhas, fique\l"
    .string "longe das áreas de grama alta!$"

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_Text_UseAntidoteForPoison::
    .string "Dicas para Treinadores:\p"
    .string "Contra envenenamento, use Antídoto!\n"
    .string "Compre em Pokémon Marts!$"

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_Text_ContactOakViaPCToRatePokedex::
    .string "Dicas para Treinadores:\p"
    .string "Você pode ligar para o Prof. Carvalho\n"
    .string "pelo Celular para ter sua Pokédex\l"
    .string "avaliada!$"

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_Text_CantCatchOwnedMons::
    .string "Dicas para Treinadores:\p"
    .string "Você não pode capturar um Pokémon\n"
    .string "que pertence a outra pessoa.\p"
    .string "Jogue Pokébolas apenas em Pokémon\n"
    .string "selvagens para capturá-los!$"

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_Text_WeakenMonsBeforeCapture::
    .string "Dicas para Treinadores:\p"
    .string "Enfraqueça os Pokémon antes de\n"
    .string "tentar a captura!\p"
    .string "Se estiverem saudáveis, eles podem\n"
    .string "escapar com facilidade!$"

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_Text_LeavingViridianForest::
    .string "Saindo da Floresta de Viridian\n"
    .string "Cidade de Pewter à frente$"

ViridianForest_EventScript_ItemPotion::
	finditem ITEM_POTION, 1
	end

ViridianForest_EventScript_ItemPotion2::
	finditem ITEM_POTION, 1
	end

ViridianForest_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE, 1
	end

ViridianForest_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL, 1
	end

ViridianForest_EventScript_Beedrillite::
    finditem ITEM_BEEDRILLITE, 1
    setflag FLAG_GOT_BEEDRILLITE
    goto_if_unset FLAG_FIRST_MEGASTONE, ViridianForest_EventScript_FoundMegaStone
    end

ViridianForest_EventScript_FoundMegaStone::
    lockall
    pokenavcall MatchCall_Text_Bill7
    waitmessage
    setflag FLAG_FIRST_MEGASTONE
    releaseall
    end

ViridianForest_EventScript_Venusaur::
	lock
	faceplayer
    playmoncry SPECIES_VENUSAUR, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_DANI, ViridianForest_EventScript_VenusaurDefeated
	msgbox ViridianForest_Text_Venusaur MSGBOX_DEFAULT
	release
	end

ViridianForest_Text_Venusaur:
	.string "CHARLES: Sarrrr...\p"
    .string "Venusaur está aproveitando o cheiro\n"
	.string "da grama e o pólen no vento.$"

ViridianForest_EventScript_BugCatcherDani::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DANI, ViridianForest_EventScript_MegaHintVenusaur
	trainerbattle_single TRAINER_BUGCATCHER_DANI, ViridianForest_Text_DaniIntro, ViridianForest_Text_DaniDefeat
	setflag FLAG_DEFEATED_DANI
	msgbox ViridianForest_Text_DaniPostBattle MSGBOX_AUTOCLOSE
	release
	end

ViridianForest_Text_DaniIntro:
	.string "Olá!\p"
	.string "Posso pedir um favor? O Charles ali\n"
	.string "precisa de um pouco de exercício.\p"
	.string "Pode nos dar uma boa batalha?$"

ViridianForest_Text_DaniDefeat:
	.string "Você foi ótimo, Charles!$"

ViridianForest_Text_DaniPostBattle:
	.string "Muito obrigado por isso. Ele é mais\n"
    .string "velho, mas é o melhor Venusaur\l"
    .string "que conheço.\p"
    .string "A batalha de hoje vai ajudá-lo a\n"
    .string "manter a energia em dia!$"

ViridianForest_EventScript_MegaHintVenusaur::    
    goto_if_set FLAG_GOT_VENUSAURITE, ViridianForest_EventScript_DaniDefeated
    msgbox ViridianForest_Text_VenusaurMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
ViridianForest_Text_VenusaurMegaHint:
    .string "Hmm? Você está procurando pelas\n"
    .string "Mega Pedras?\p"
    .string "Eu posso te dizer onde encontrar a\n"
    .string "Venusaurita, sem problemas!\p"
    .string "Tenho amigos Criadores Pokémon na\n"
    .string "Cidade de Cerulean. O quintal deles\l"
    .string "tinha duas na última vez que visitei.\l"
    .string "Eles me deram uma, vá perguntar a eles!$"

ViridianForest_EventScript_DaniDefeated::
    msgbox DaniDefeated_Text MSGBOX_DEFAULT
	release
	end

DaniDefeated_Text:	
	.string "Você já conheceu a Erin, a treinadora\n"
	.string "que mora na cabana?\p"
    .string "O Clefairy dela me dá Frutas\n"
    .string "sempre que o Charles quer.$"

ViridianForest_EventScript_VenusaurDefeated::
	msgbox VenusaurDefeated MSGBOX_DEFAULT
	release
	end

VenusaurDefeated:	
	.string "Charles está respirando fundo,\n"
	.string "mas seus olhos estão cheios de encanto.$"
