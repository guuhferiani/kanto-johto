FuchsiaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

FuchsiaCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_KOGA_REMATCH, FuchsiaCity_Gym_ResetRematchFlags
	end

FuchsiaCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_KOGA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_KOGA_POSTGAME
	return

FuchsiaCity_Gym_EventScript_Koga::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_KOGA_REWARD, FuchsiaCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_KOGA_REMATCH, FuchsiaCity_Gym_EventScript_RematchLeader
	goto FuchsiaCity_Gym_EventScript_LeaderPostBattle
	end

FuchsiaCity_Gym_EventScript_ChallengeLeader::
	msgbox FuchsiaCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_LeaderIntro, FuchsiaCity_Gym_Text_LeaderDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

FuchsiaCity_Gym_Text_LeaderSpeech::
    .string "Koga: Fwahahaha!\p"
    .string "Uma mera criança como você ousa me\n"
    .string "desafiar?\p"
    .string "Essa simples ideia me faz estremecer\n"
    .string "de alegria!\p"
    .string "Muito bem, vou lhe mostrar o verdadeiro\n"
    .string "terror de um mestre ninja.\p"
    .string "O veneno traz uma ruína constante.\n"
    .string "O sono deixa os oponentes indefesos.$"

FuchsiaCity_Gym_Text_LeaderIntro::
    .string "Desespere-se diante do horror rastejante\n"
    .string "dos Pokémon do tipo Venenoso!$"

FuchsiaCity_Gym_Text_LeaderDefeat::
    .string "Humph!\n"
    .string "Você provou o seu valor!$"

FuchsiaCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox FuchsiaCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message FuchsiaCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox FuchsiaCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DAILY_KOGA_REMATCH
	settrainerflag TRAINER_TAMER_PHIL					
	settrainerflag TRAINER_TAMER_EDGAR
	settrainerflag TRAINER_JUGGLER_KIRK
	settrainerflag TRAINER_JUGGLER_SHAWN
	settrainerflag TRAINER_JUGGLER_KAYDEN
	settrainerflag TRAINER_JUGGLER_NATE
	call_if_set FLAG_RECEIVED_ITEMFINDER, FuchsiaCity_Gym_EventScript_QueueNextAideCall
	goto FuchsiaCity_Gym_EventScript_GetTM
	end

FuchsiaCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_4
	return

FuchsiaCity_Gym_Text_GetBadge::
    .string "Aqui!\n"
    .string "Pegue a Insígnia da Alma!$"

FuchsiaCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insígnia da\n"
    .string "Alma de Koga!$"

FuchsiaCity_Gym_Text_ExplainBadge::
    .string "A Insígnia da Alma permitirá que você\n"
    .string "use o Surfar fora de batalha.$"

FuchsiaCity_Gym_EventScript_GetTM::
	msgbox FuchsiaCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM06, 1
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox FuchsiaCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM06, 1
	setflag FLAG_GOT_KOGA_REWARD
	msgbox FuchsiaCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_TakeThisWithYou::
    .string "Ah!\n"
    .string "Leve isto também!$"

FuchsiaCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} recebeu o MT06\n"
    .string "de Koga.$"

FuchsiaCity_Gym_Text_ExplainTM::
    .string "Selado dentro deste MT06 jaz\n"
    .string "o Tóxico!\p"
    .string "É uma técnica secreta com mais\n"
    .string "de quatrocentos anos de história.$"

FuchsiaCity_Gym_EventScript_NoRoomForTM::
	msgbox FuchsiaCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_NoRoomForTM::
    .string "Abra espaço para isto, criança!$"

FuchsiaCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, FuchsiaCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox FuchsiaCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_LeaderPostBattle::
    .string "Ao ser afligido por Tóxico, um Pokémon\n"
    .string "sofre cada vez mais.\p"
    .string "Ele sofre danos cada vez piores conforme\n"
    .string "a batalha se prolonga!\p"
    .string "Certamente aterrorizará seus inimigos!$"

FuchsiaCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox FuchsiaCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_PostBattleGameClear::
	.string "Com Treinadores como você e {RIVAL},\n"
	.string "a Liga Pokémon deve ser um lugar de\l"
	.string "força formidável!\p"
	.string "Verdadeiramente, é algo para se orgulhar!\p"
	.string "Por acaso, ando pensando em tentar me\n"
	.string "juntar à Elite dos Quatro também…$"

FuchsiaCity_Gym_EventScript_RematchLeader::
	msgbox FuchsiaCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, FuchsiaCity_Gym_EventScript_PostgameRematch
	goto FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

FuchsiaCity_Gym_Text_RematchLeader::
	.string "Fwahahaha! Se não é a criança.\p"
	.string "Parece que estávamos destinados a nos\n"
	.string "encontrar mais uma vez.\p"
	.string "Você veio em um momento verdadeiramente\n"
	.string "oportuno.\p"
	.string "Eu estava justamente pensando em testar\n"
	.string "minhas recém-refinadas e sinistras técnicas…\p"
	.string "…em uma batalha que terminará na sua\n"
	.string "completa derrota!\n"
	.string "Aceita o meu desafio?$"

FuchsiaCity_Gym_EventScript_DeclineRematch::
	msgbox FuchsiaCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_DeclineRematch::
	.string "Você já perdeu!$"

FuchsiaCity_Gym_EventScript_PostgameRematch::
	msgbox FuchsiaCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

FuchsiaCity_Gym_Text_RematchMode::
	.string "Agora que você é o campeão,\n"
	.string "gostaria de ir com tudo?$"

FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_KOGA_ORIGINAL, FuchsiaCity_Gym_Text_RematchOriginal, FuchsiaCity_Gym_Text_RematchDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch
	end

FuchsiaCity_Gym_Text_RematchOriginal::
	.string "Fwahahaha!\n"
	.string "Vamos reviver nossas batalhas passadas!$"

FuchsiaCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single LEADER_REMATCH_KOGA_POSTGAME, FuchsiaCity_Gym_Text_RematchPostgame, FuchsiaCity_Gym_Text_RematchDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch
	end

FuchsiaCity_Gym_Text_RematchPostgame::
	.string "Fwahahaha!\p"
	.string "Hoje não só irei derrotar você, como\n"
	.string "também demonstrarei minha dignidade de pai\l"
	.string "para a minha filha!$"

FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_KOGA_REMATCH
	goto FuchsiaCity_Gym_EventScript_LeaderPostBattle
	end

FuchsiaCity_Gym_Text_RematchDefeat::
	.string "…Se não sou forte o suficiente para\n"
	.string "derrotá-lo agora, resta apenas uma coisa.\p"
	.string "Devo aprimorar ainda mais minhas habilidades.$"

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_PhilIntro::
    .string "Pare bem aí!\p"
    .string "As famosas paredes invisíveis do\n"
    .string "Ginásio de Fuchsia te deixaram frustrado?$"

FuchsiaCity_Gym_Text_PhilDefeat::
    .string "Uau!\n"
    .string "Você pegou o jeito!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
    .string "Você me impressionou!\n"
    .string "Aqui vai uma dica!\p"
    .string "Olhe com muita atenção para ver as brechas\n"
    .string "nas paredes invisíveis!$"

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_EdgarIntro::
    .string "Eu também estudo o caminho ninja\n"
    .string "com o Mestre Koga!\p"
    .string "Os ninjas têm uma longa história de uso\n"
    .string "de animais!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
    .string "Auuu!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
    .string "Ainda tenho muito a aprender.$"

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_KirkIntro::
    .string "Eu já fui um mágico no passado.\p"
    .string "Mas eu sonhava em ser um ninja,\n"
    .string "então entrei para este ginásio.$"

FuchsiaCity_Gym_Text_KirkDefeat::
    .string "Estou acabado!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
    .string "Mesmo tendo perdido, continuarei\n"
    .string "treinando de acordo com os ensinamentos\l"
    .string "de Koga, meu mestre ninja.$"

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_ShawnIntro::
    .string "O Mestre Koga descende de uma longa\n"
    .string "linhagem de ninjas.\p"
    .string "De quem você descende?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
    .string "Você é mais habilidoso do que\n"
    .string "eu imaginei!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
    .string "Onde há luz, há sombra!\p"
    .string "Luz e sombra!\n"
    .string "Qual você escolhe?$"

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_KaydenIntro::
    .string "A força bruta não é a chave para Pokémon.\n"
    .string "Você compreende isso?\p"
    .string "Pokémon é sobre estratégia!\p"
    .string "Vou lhe mostrar como a estratégia pode\n"
    .string "superar a força bruta.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
    .string "O quê?\n"
    .string "Extraordinário!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
    .string "Então você combina força com inteligência?\n"
    .string "Boa estratégia!\p"
    .string "Isso é notável para uma criança\n"
    .string "treinadora.$"

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_NateIntro::
    .string "Quero ver você superar minhas\n"
    .string "técnicas especiais!$"

FuchsiaCity_Gym_Text_NateDefeat::
    .string "Você me enganou direitinho!$"

FuchsiaCity_Gym_Text_NatePostBattle::
    .string "Eu gosto de técnicas de veneno e sono,\n"
    .string "já que elas continuam após a batalha!$"

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_Text_GymGuyAdvice::
    .string "E aí!\n"
    .string "Futuro campeão!\p"
    .string "O Ginásio de Fuchsia é cheio de truques.\n"
    .string "Ele está repleto de paredes invisíveis!\p"
    .string "O Koga pode parecer perto, mas o caminho\n"
    .string "está bloqueado.\p"
    .string "Você precisa achar as brechas nas paredes\n"
    .string "para chegar até ele.$"

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_Text_GymGuyPostVictory::
    .string "É impressionante como os ninjas ainda\n"
    .string "conseguem aterrorizar, até hoje!$"

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_GymStatue::
    .string "Ginásio Pokémon de Fuchsia\n"
    .string "Líder: Koga\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginásio Pokémon de Fuchsia\n"
    .string "Líder: Koga\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"

