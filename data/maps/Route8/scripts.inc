.set LOCALID_FUGITIVE, 19

Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route8_OnResume
	.byte 0

Route8_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route8_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route8_EventScript_UndergroundPathSign::
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route8_Text_UndergroundPathSign::
    .string "Via Subterrânea\n"
    .string "Cidade de Celadon - Vilarejo de Lavender$"

Route8_EventScript_Aidan::
	trainerbattle_single REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1, Route8_Text_AidanIntro, Route8_Text_AidanDefeat, Route8_EventScript_RegisterAidanAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_AidanRematch
	msgbox Route8_Text_AidanPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_Text_AidanIntro::
    .string "Você parece entender de Pokémon,\n"
    .string "mas como anda sua nota de química?$"

Route8_Text_AidanDefeat::
    .string "Ai!\n"
    .string "Colapso total!$"

Route8_Text_AidanPostBattle::
    .string "Eu sou bem melhor na escola do que nisso!$"

Route8_EventScript_RegisterAidanAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_AidanRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1
	release
	end

Route8_Text_AidanRegister:
	.string "Eu te dou aulas de química se você\n"
	.string "me der aulas de batalhas Pokémon.$"

Route8_EventScript_AidanRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1, Route8_Text_AidanRematchIntro, Route8_Text_AidanDefeat
	msgbox Route8_Text_AidanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AidanRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Suas notas melhoraram?$"

Route8_Text_AidanRematchPostBattle::
	.string "Eu devia estar estudando em vez de\n"
	.string "brincar com Pokémon!$"

Route8_EventScript_Julia::
	trainerbattle_single TRAINER_LASS_JULIA, Route8_Text_JuliaIntro, Route8_Text_JuliaDefeat
	msgbox Route8_Text_JuliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_JuliaIntro::
    .string "Qual é o Pokémon fofo, redondo\n"
    .string "e macio?$"

Route8_Text_JuliaDefeat::
    .string "Pare!\p"
    .string "Não seja tão cruel com minha Clefairy!$"

Route8_Text_JuliaPostBattle::
    .string "Li que Clefairy evolui quando é\n"
    .string "exposta a uma Pedra da Lua.\p"
    .string "Li isso em uma Revista Pokémon.\n"
    .string "Será que é verdade?$"


Route8_EventScript_Paige::
	trainerbattle_single TRAINER_LASS_PAIGE, Route8_Text_PaigeIntro, Route8_Text_PaigeDefeat
	msgbox Route8_Text_PaigePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_PaigeIntro::
    .string "Eu gosto de Nidoran, por isso coleciono!$"

Route8_Text_PaigeDefeat::
    .string "Por quê?\n"
    .string "Por quê??$"

Route8_Text_PaigePostBattle::
    .string "Quando os Pokémon crescem, eles ficam\n"
    .string "feios! Eles não deviam evoluir.$"

Route8_EventScript_Andrea::
	trainerbattle_single TRAINER_LASS_ANDREA, Route8_Text_AndreaIntro, Route8_Text_AndreaDefeat
	msgbox Route8_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AndreaIntro::
    .string "Meowth é tão fofo, miau, miau,\n"
    .string "miau!$"

Route8_Text_AndreaDefeat::
    .string "Miaaaau!$"

Route8_Text_AndreaPostBattle::
    .string "Eu acho que Pidgey e Rattata\n"
    .string "também são fofos!$"

Route8_EventScript_Megan::
	trainerbattle_single TRAINER_LASS_MEGAN, Route8_Text_MeganIntro, Route8_Text_MeganDefeat
	msgbox Route8_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_MeganIntro::
    .string "A gente deve parecer boba parada\n"
    .string "aqui desse jeito.$"

Route8_Text_MeganDefeat::
    .string "Olhe o que você fez com o meu pobre\n"
    .string "e fofinho Pokémon!$"

Route8_Text_MeganPostBattle::
    .string "A Polícia em Saffron não nos deixa\n"
    .string "passar.\p"
    .string "Eu sei que estão fazendo o trabalho deles,\n"
    .string "mas acho uma maldade.$"

Route8_EventScript_Glenn::
	trainerbattle_single TRAINER_SUPER_NERD_GLENN, Route8_Text_GlennIntro, Route8_Text_GlennDefeat
	msgbox Route8_Text_GlennPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_GlennIntro::
    .string "Fique sabendo:\n"
    .string "é preciso estratégia para vencer nisto!$"

Route8_Text_GlennDefeat::
    .string "Não é lógico!$"

Route8_Text_GlennPostBattle::
    .string "Começar com Grimer primeiro… e…\n"
    .string "… e… depois…$"

Route8_EventScript_Leslie::
	trainerbattle_single TRAINER_SUPER_NERD_LESLIE, Route8_Text_LeslieIntro, Route8_Text_LeslieDefeat
	msgbox Route8_Text_LesliePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_LeslieIntro::
    .string "A escola é divertida, mas Pokémon\n"
    .string "também são.$"

Route8_Text_LeslieDefeat::
    .string "Você deixou claro para mim que\n"
    .string "eu devia me concentrar na escola.$"

Route8_Text_LesliePostBattle::
    .string "Eu estava planejando tomar um ar\n"
    .string "fresco para variar, mas…\p"
    .string "Estamos presos aqui por causa dos\n"
    .string "portões de Saffron.$"

Route8_EventScript_Stan::
	trainerbattle_single TRAINER_GAMBLER_STAN, Route8_Text_StanIntro, Route8_Text_StanDefeat
	msgbox Route8_Text_StanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_StanIntro::
    .string "Muito bem!\n"
    .string "Vamos jogar!$"

Route8_Text_StanDefeat::
    .string "Droga!\n"
    .string "Deu azar!$"

Route8_Text_StanPostBattle::
    .string "As coisas não deram certo hoje.$"

Route8_EventScript_Rich::
	trainerbattle_single TRAINER_GAMBLER_RICH, Route8_Text_RichIntro, Route8_Text_RichDefeat
	msgbox Route8_Text_RichPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_RichIntro::
    .string "Sou um cara que adora uma boa aposta!$"

Route8_Text_RichDefeat::
    .string "Perdi a grande chance!$"

Route8_Text_RichPostBattle::
    .string "Jogar e batalhar com Pokémon é como comer\n"
    .string "amendoim! Simplesmente não consigo parar!$"

Route8_EventScript_Eli::
	trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_EliIntro, Route8_Text_EliDefeat, Route8_Text_EliNotEnoughMons
	msgbox Route8_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_EliIntro::
    .string "Eli: O poder dos gêmeos é fantástico.\n"
    .string "Você sabia?$"

Route8_Text_EliDefeat::
    .string "Eli: Mas…\n"
    .string "Nós usamos nosso poder de gêmeos…$"

Route8_Text_EliPostBattle::
    .string "Eli: Eu capturei meu Pokémon com\n"
    .string "a Anne!$"

Route8_Text_EliNotEnoughMons::
    .string "Eli: Não podemos batalhar se você não\n"
    .string "tiver dois Pokémon.$"

Route8_EventScript_Anne::
	trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_AnneIntro, Route8_Text_AnneDefeat, Route8_Text_AnneNotEnoughMons
	msgbox Route8_Text_AnnePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AnneIntro::
    .string "Anne: Vamos te chocar com nosso poder\n"
    .string "de gêmeos!$"

Route8_Text_AnneDefeat::
    .string "Anne: Nosso poder de gêmeos…$"

Route8_Text_AnnePostBattle::
    .string "Anne: Estou criando Pokémon com\n"
    .string "o Eli.$"

Route8_Text_AnneNotEnoughMons::
    .string "Anne: Oi, oi! Vamos batalhar!\n"
    .string "Mas traga dois Pokémon.$"

Route8_EventScript_Ricardo::
	trainerbattle_single TRAINER_BIKER_RICARDO, Route8_Text_RicardoIntro, Route8_Text_RicardoDefeat
	msgbox Route8_Text_RicardoPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_RicardoIntro::
    .string "Minha moto tá falhando, cara.$"

Route8_Text_RicardoDefeat::
    .string "Pô, cara.\n"
    .string "Não tô a fim disso.$"

Route8_Text_RicardoPostBattle::
    .string "Enroscou grama nos meus raios,\n"
    .string "cara.$"

Route8_EventScript_Jaren::
	trainerbattle_single TRAINER_BIKER_JAREN, Route8_Text_JarenIntro, Route8_Text_JarenDefeat
	msgbox Route8_Text_JarenPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_JarenIntro::
    .string "Saia da frente, ou vou passar por\n"
    .string "cima de você!$"

Route8_Text_JarenDefeat::
    .string "É sério mesmo, pivete?$"

Route8_Text_JarenPostBattle::
    .string "Não vá pensando que você é grande coisa\n"
    .string "só por causa disso.$"

Route8_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

Route8_EventScript_Beedrill::
	lock
	faceplayer
    playmoncry SPECIES_BEEDRILL, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_DIZZYPHOEBE, Route8_EventScript_BeedrillDefeated
	msgbox Route8_Text_Beedrill MSGBOX_DEFAULT
	release
	end

Route8_Text_Beedrill:
	.string "O Beedrill estava girando em círculos.\n"
    .string "Agora parou e encara você.$"

Route8_EventScript_AromaLadyPhoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DIZZYPHOEBE, Route8_EventScript_MegaHintBeedrill
	trainerbattle_single TRAINER_AROMALADY_PHOEBE, Route8_Text_PhoebeIntro, Route8_Text_PhoebeDefeat
	setflag FLAG_DEFEATED_DIZZYPHOEBE
	msgbox Route8_Text_PhoebePostBattle MSGBOX_AUTOCLOSE
	release
	end

Route8_Text_PhoebeIntro:
	.string "Gira, gira e gira sem parar!\n"
	.string "Um treinador se aproxima! Vou levá-lo\l"
	.string "para dar uma volta!$"

Route8_Text_PhoebeDefeat:
	.string "Você me fez rodar em círculos!$"

Route8_Text_PhoebePostBattle:
	.string "Você me faz girar em círculos, amor,\n"
    .string "em círculos. Como um disco, querido,\l"
    .string "rodando, rodando, rodando.$"

Route8_EventScript_MegaHintBeedrill::    
    goto_if_set FLAG_GOT_BEEDRILLITE, Route8_EventScript_PhoebeDefeated
    msgbox Route8_Text_BeedrillMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route8_Text_BeedrillMegaHint:
    .string "O que foi? Quer saber onde foi que\n"
    .string "eu encontrei a Megapedra?\p"
    .string "Dê voltas e voltas na Floresta de\n"
    .string "Viridian até uma cabana humilde. Foi\l"
    .string "para onde as voltas da vida me levaram.$"

Route8_EventScript_PhoebeDefeated::
    msgbox PhoebeDefeated_Text MSGBOX_DEFAULT
	release
	end

PhoebeDefeated_Text:	
    .string "A vida é curta demais para não dar\n"
    .string "uma chance às coisas. Assuma o volante\l"
    .string "da sua vida e faça zerinhos no\l"
    .string "estacionamento do seu destino!$"

Route8_EventScript_BeedrillDefeated::
	msgbox BeedrillDefeated MSGBOX_DEFAULT
	release
	end

BeedrillDefeated:	
	.string "Ver o Beedrill e sua treinadora\n"
	.string "rodopiando sem parar faz você se\l"
    .string "lembrar daquele filme com idiotas\l"
    .string "dançando em um posto de gasolina.$"
