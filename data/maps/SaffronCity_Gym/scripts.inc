SaffronCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Gym_OnTransition
	.byte 0

SaffronCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_SABRINA_REMATCH, SaffronCity_Gym_ResetRematchFlags
	end

SaffronCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_SABRINA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_SABRINA_POSTGAME
	return

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHANNA, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_JohanIntro::
    .string "Nosso poder invisível assusta você?$"

SaffronCity_Gym_Text_JohanDefeat::
    .string "Eu nunca previ isso!$"

SaffronCity_Gym_Text_JohanPostBattle::
    .string "Pokémon Psíquicos só temem\n"
    .string "fantasmas e insetos!$"

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TRISH, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_TyronIntro::
    .string "Você compreende, não é?\p"
    .string "Que poder por si só não basta\n"
    .string "para vencer no mundo Pokémon?$"

SaffronCity_Gym_Text_TyronDefeat::
    .string "Não acredito nisso!$"

SaffronCity_Gym_Text_TyronPostBattle::
    .string "Sabrina derrotou facilmente o\n"
    .string "Mestre do Karatê ao lado.$"

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_CameronIntro::
    .string "Sabrina é jovem, mas também é nossa\n"
    .string "Líder extremamente habilidosa.\p"
    .string "Você não chegará a ela facilmente!$"

SaffronCity_Gym_Text_CameronDefeat::
    .string "Ai!\n"
    .string "Fui nocauteado!$"

SaffronCity_Gym_Text_CameronPostBattle::
    .string "Costumava haver dois Ginásios Pokémon\n"
    .string "em Saffron.\p"
    .string "O Dojô de Luta ao lado perdeu seu\n"
    .string "título oficial de Ginásio.\p"
    .string "Nós simplesmente os massacramos quando\n"
    .string "decidiram ter apenas um Ginásio.$"

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_PrestonIntro::
    .string "O Ginásio Pokémon de Saffron é famoso\n"
    .string "por treinar médiuns psíquicos.\p"
    .string "Você quer ver a Sabrina, não quer?\n"
    .string "Eu posso sentir!$"

SaffronCity_Gym_Text_PrestonDefeat::
    .string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
    .string "Exato! Usei telepatia para ler a\n"
    .string "sua mente!$"

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_AmandaIntro::
    .string "Sabrina é bem mais jovem que eu,\n"
    .string "mas ela conquistou o meu respeito.$"

SaffronCity_Gym_Text_AmandaDefeat::
    .string "Não fui boa o bastante!$"

SaffronCity_Gym_Text_AmandaPostBattle::
    .string "Numa batalha entre iguais, vence quem\n"
    .string "tiver a determinação mais forte.\p"
    .string "Se deseja vencer Sabrina, concentre-se\n"
    .string "e canalize sua mente para a vitória.$"

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_StacyIntro::
    .string "Os Pokémon refletem a personalidade\n"
    .string "de seus treinadores.\p"
    .string "Seus Pokémon devem ser bem fortes!$"

SaffronCity_Gym_Text_StacyDefeat::
    .string "Eu sabia!$"

SaffronCity_Gym_Text_StacyPostBattle::
    .string "Ainda tenho muito a aprender...\p"
    .string "Preciso dominar o Psíquico e ensiná-lo\n"
    .string "aos meus Pokémon...$"

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_TashaIntro::
    .string "Você e eu, nossos Pokémon irão\n"
    .string "batalhar!$"

SaffronCity_Gym_Text_TashaDefeat::
    .string "Perdi afinal de contas!$"

SaffronCity_Gym_Text_TashaPostBattle::
    .string "Eu sabia que isso ia acontecer.$"


SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_SABRINA_REWARD, SaffronCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_SABRINA_REMATCH, SaffronCity_Gym_EventScript_RematchLeader
	goto SaffronCity_Gym_EventScript_LeaderPostBattle
	end

SaffronCity_Gym_EventScript_ChallengeLeader::
	msgbox SaffronCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_LeaderIntro, SaffronCity_Gym_Text_LeaderDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

SaffronCity_Gym_Text_LeaderSpeech::
    .string "Eu tive uma visão da sua chegada.\p"
    .string "Tenho poderes psíquicos desde que\n"
    .string "era criança.\p"
    .string "Tudo começou quando uma colher que\n"
    .string "joguei displicentemente entortou.$"

SaffronCity_Gym_Text_LeaderIntro::
    .string "Não gosto de batalhar, mas se insiste,\n"
    .string "eu lhe mostrarei os meus poderes!$"

SaffronCity_Gym_Text_LeaderDefeat::
    .string "Esta derrota me choca!\n"
    .string "Porém, uma derrota é uma derrota.$"

SaffronCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox SaffronCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message SaffronCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox SaffronCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DAILY_SABRINA_REMATCH
	settrainerflag TRAINER_PSYCHIC_PRESTON
	settrainerflag TRAINER_PSYCHIC_CAMERON				
	settrainerflag TRAINER_CHANNELER_TASHA
	settrainerflag TRAINER_PSYCHIC_TRISH
	settrainerflag TRAINER_CHANNELER_STACY
	settrainerflag TRAINER_PSYCHIC_JOHANNA
	settrainerflag TRAINER_CHANNELER_AMANDA
	call_if_set FLAG_RECEIVED_AIDE_AMULET_COIN, SaffronCity_Gym_EventScript_QueueNextAideCall
	goto SaffronCity_Gym_EventScript_GetTM
	end

SaffronCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_5
    return

SaffronCity_Gym_Text_GetBadge::
    .string "Admito, eu não me esforcei o bastante\n"
    .string "para vencer.\p"
    .string "Sua vitória lhe garantiu a Insígnia\n"
    .string "do Pântano.$"

SaffronCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insígnia do\n"
    .string "Pântano de Sabrina!$"

SaffronCity_Gym_Text_ExplainBadge::
    .string "A Insígnia do Pântano permite que\n"
    .string "seus Pokémon usem Quebrar Rocha\l"
    .string "fora de batalha.\p"
    .string "Ela também faz com que Pokémon até\n"
    .string "o Nv. 70 obedeçam a você.\p"
    .string "Pokémon mais fortes ficarão rebeldes,\n"
    .string "ignorando suas ordens em batalha.\p"
    .string "Apenas não os treine além da conta\n"
    .string "para evitar esse problema.$"

SaffronCity_Gym_EventScript_GetTM::
	msgbox SaffronCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM04, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox SaffronCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM04, 1
	setflag FLAG_GOT_SABRINA_REWARD
	msgbox SaffronCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_TakeThisWithYou::
    .string "Espere, por favor leve este MT.$"

SaffronCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} recebeu o MT04\n"
    .string "de Sabrina.$"

SaffronCity_Gym_Text_ExplainTM::
    .string "O MT04 contém Calm Mind.\p"
    .string "Ele faz o Pokémon se concentrar para\n"
    .string "elevar tanto o Sp. Atk quanto o Sp. Def.$"

SaffronCity_Gym_EventScript_NoRoomForTM::
	msgbox SaffronCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_NoRoomForTM::
    .string "Sua Mochila está cheia de itens.$"

SaffronCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SaffronCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox SaffronCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_LeaderPostBattle::
    .string "O poder psíquico não é algo reservado\n"
    .string "a poucas pessoas.\p"
    .string "Todos possuem poder psíquico.\n"
    .string "As pessoas apenas não percebem.$"

SaffronCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox SaffronCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_PostBattleGameClear::
	.string "Você se saiu muito bem.\p"
	.string "Se não consigo superá-lo agora,\n"
	.string "só me resta treinar ainda mais.\p"
	.string "Continue testando suas habilidades!$"

SaffronCity_Gym_EventScript_RematchLeader::
	msgbox SaffronCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, SaffronCity_Gym_EventScript_PostgameRematch
	goto SaffronCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

SaffronCity_Gym_Text_RematchLeader::
	.string "...É verdade que o poder psíquico é uma\n"
	.string "habilidade poderosa.\p"
	.string "No entanto, há coisas que não podem\n"
	.string "ser superadas apenas com esse poder.\p"
	.string "Finalmente compreendi isso após perder\n"
	.string "para você em nossa última batalha.\p"
	.string "Não vou depender só de poderes psíquicos\n"
	.string "desta vez.\p"
	.string "Minha verdadeira força... meu verdadeiro eu...\p"
	.string "Permita-me testá-los contra você!$"

SaffronCity_Gym_EventScript_DeclineRematch::
	msgbox SaffronCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_DeclineRematch::
	.string "Eu já previa esta possibilidade...$"

SaffronCity_Gym_EventScript_PostgameRematch::
	msgbox SaffronCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto SaffronCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

SaffronCity_Gym_Text_RematchMode::
	.string "Agora que você é o Campeão,\n"
	.string "gostaria de lutar com tudo?$"

SaffronCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_SABRINA_ORIGINAL, SaffronCity_Gym_Text_RematchOriginal, SaffronCity_Gym_Text_RematchDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderRematch
	end

SaffronCity_Gym_Text_RematchOriginal::
	.string "Vamos contemplar nosso passado para ver\n"
	.string "o que o futuro nos reserva!$" 

SaffronCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single LEADER_REMATCH_SABRINA_POSTGAME, SaffronCity_Gym_Text_RematchPostgame, SaffronCity_Gym_Text_RematchDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderRematch
	end

SaffronCity_Gym_Text_RematchPostgame::
	.string "Eu previ que você viria aqui ao olhar\n"
	.string "para o futuro.\p"
	.string "Mas deliberadamente não olhei quem\n"
	.string "vencerá nossa batalha.\p"
	.string "Vamos descobrir juntos!$"

SaffronCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_SABRINA_REMATCH
	goto SaffronCity_Gym_EventScript_LeaderPostBattle
	end

SaffronCity_Gym_Text_RematchDefeat::
	.string "Não encontrarei um Treinador como você\n"
	.string "por cerca de mais três anos.$"


SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_Text_GymGuyAdvice::
    .string "E aí!\n"
    .string "Futuro Campeão!\p"
    .string "Os Pokémon de Sabrina usam poder\n"
    .string "psíquico em vez de força bruta.\p"
    .string "Pokémon Lutadores são especialmente\n"
    .string "vulneráveis contra Psíquicos.\p"
    .string "Eles serão destruídos antes mesmo\n"
    .string "de conseguirem desferir um soco!$"

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_Text_GymGuyPostVictory::
    .string "Poder psíquico, hein?\p"
    .string "Se eu tivesse isso, ficaria milionário\n"
    .string "nos caça-níqueis!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_Text_GymStatue::
    .string "Ginásio Pokémon de Saffron\n"
    .string "Líder: Sabrina\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginásio Pokémon de Saffron\n"
    .string "Líder: Sabrina\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"
