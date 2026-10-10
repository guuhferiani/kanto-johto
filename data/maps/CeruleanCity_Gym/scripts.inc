CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_Gym_OnTransition
	.byte 0

CeruleanCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_MISTY_REMATCH, CeruleanCity_Gym_ResetRematchFlags
	end

CeruleanCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_MISTY_ORIGINAL
	cleartrainerflag LEADER_REMATCH_MISTY_POSTGAME
	return

CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_ChallengeMisty
	goto_if_unset FLAG_GOT_MISTY_REWARD, CeruleanCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_MISTY_REMATCH, CeruleanCity_Gym_EventScript_RematchLeader
	goto CeruleanCity_Gym_EventScript_LeaderPostBattle
	end

CeruleanCity_Gym_EventScript_ChallengeMisty::
	msgbox CeruleanCity_Gym_Text_MistySpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_DefeatedMistyGetBadge
	end

CeruleanCity_Gym_Text_MistySpeech::
    .string "Olá, você é um rosto novo!\p"
    .string "Apenas aqueles Treinadores que têm uma\n"
    .string "filosofia sobre Pokémon podem virar pro.\p"
    .string "Qual é a sua abordagem ao capturar e\n"
    .string "treinar Pokémon?$"

CeruleanCity_Gym_Text_MistyIntro::
    .string "A minha filosofia é um ataque total\n"
    .string "com Pokémon do tipo Água!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "Uau!\n"
    .string "Você é demais!\p"
    .string "Muito bem!$"

CeruleanCity_Gym_EventScript_DefeatedMistyGetBadge::
	msgbox CeruleanCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CeruleanCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox CeruleanCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setflag FLAG_DAILY_MISTY_REMATCH
	settrainerflag TRAINER_PICNICKER_DIANA
	settrainerflag TRAINER_SWIMMER_MALE_LUIS
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_1
	goto CeruleanCity_Gym_EventScript_GetTM
	end

CeruleanCity_Gym_Text_GetBadge::
    .string "Você pode ficar com a Insígnia da\n"
    .string "Cascata para provar que me venceu.$"

CeruleanCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insígnia da\n"
    .string "Cascata de Misty!$"

CeruleanCity_Gym_Text_ExplainBadge::
	.string "A Insígnia da Cascata faz com que todos\n"
    .string "os Pokémon até o Nv. 30 obedeçam.\p"
    .string "Isso inclui até aqueles obtidos em trocas\n"
    .string "com outros treinadores.\p"
    .string "E tem mais. Agora você pode usar Cortar\n"
    .string "a qualquer momento, fora de batalha.\p"
    .string "Você pode Cortar pequenas árvores para\n"
    .string "abrir novos caminhos.$"

CeruleanCity_Gym_EventScript_GetTM::
	msgbox CeruleanCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM03, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeruleanCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM03, 1
	setflag FLAG_GOT_MISTY_REWARD
	msgbox CeruleanCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	call_if_eq VAR_SEA_COTTAGE_STATE, 3, CeruleanCity_Gym_EventScript_PrepDexNavCall
	release
	end

CeruleanCity_Gym_Text_TakeThisWithYou::
	 .string "Você também pode ficar com o meu TM favorito.$"

CeruleanCity_Gym_Text_ReceivedTM::
    .string "{PLAYER} recebeu o TM03\n"
    .string "de Misty.$"

CeruleanCity_Gym_Text_ExplainTM::
    .string "O TM03 ensina Pulso d'Água.\p"
    .string "Use-o em um Pokémon aquático!$"

CeruleanCity_Gym_EventScript_NoRoomForTM::
	msgbox CeruleanCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_NoRoomForTM::
    .string "É melhor você abrir espaço para isso!$"

CeruleanCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CeruleanCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_LeaderPostBattle::
	.string "Misty: Há momentos em que só quero me\n"
	.string "libertar de uma piscina minúscula e nadar no\l" 
	.string "grande azul do oceano!$"

CeruleanCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CeruleanCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_PostBattleGameClear::
	.string "Sabe de uma coisa?\p"
    .string "Meu sonho era enfrentar Treinadores\n" 
    .string "poderosos e me tornar uma Líder de Ginásio...\p"
    .string "Eu realizei meu sonho, e agora meu\n"
    .string "próximo sonho é derrotar você!$"

CeruleanCity_Gym_EventScript_RematchLeader::
	msgbox CeruleanCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_Gym_EventScript_PostgameRematch
	goto CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeruleanCity_Gym_Text_RematchLeader::
	.string "Ouvi um boato interessante!\p" 
	.string "Você e aquele outro garoto andaram\n" 
	.string "enfrentando aqueles caras da Equipe Rocket.\p" 
	.string "Isso é verdade?\p" 
	.string "Argh! Eu simplesmente não aguento mais!\p" 
	.string "Você ficou tão forte que eu simplesmente\n" 
	.string "preciso batalhar com você de novo!\p" 
	.string "Entendeu bem? Nada de recusar!$"

CeruleanCity_Gym_EventScript_DeclineRematch::
	msgbox CeruleanCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_DeclineRematch::
	.string "Argh! Qual é! Batalha comigo!$"

CeruleanCity_Gym_EventScript_PostgameRematch::
	msgbox CeruleanCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CeruleanCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeruleanCity_Gym_Text_RematchMode::
	.string "Agora que você é o campeão,\n"
	.string "gostaria de ir com força total?$"

CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_MISTY_ORIGINAL, CeruleanCity_Gym_Text_RematchOriginal, CeruleanCity_Gym_Text_RematchDefeat, CeruleanCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeruleanCity_Gym_Text_RematchOriginal::
	.string "Beleza, {PLAYER}!\n"
	.string "Vamos lá!$"

CeruleanCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single LEADER_REMATCH_MISTY_POSTGAME, CeruleanCity_Gym_Text_RematchPostgame, CeruleanCity_Gym_Text_RematchDefeat, CeruleanCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeruleanCity_Gym_Text_RematchPostgame::
	.string "Meus adoráveis Pokémon estão prontos\n" 
	.string "para te enfrentar!\p" 
	.string "A ofensiva definitiva dos Pokémon do\n" 
	.string "tipo Água!\p" 
	.string "Espero que você esteja pronto!$"

CeruleanCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_MISTY_REMATCH
	goto CeruleanCity_Gym_EventScript_LeaderPostBattle
	end

CeruleanCity_Gym_Text_RematchDefeat::
	.string "Hmph! Que irritante!$"


CeruleanCity_Gym_EventScript_PrepDexNavCall::
	setvar VAR_SEA_COTTAGE_STATE, 4
	return

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_DianaIntro::
    .string "O quê? Você?\n"
    .string "Eu sou mais do que suficiente para você!\p"
    .string "A Misty nem vai precisar se incomodar.$"

CeruleanCity_Gym_Text_DianaDefeat::
    .string "Você me superou completamente!$"

CeruleanCity_Gym_Text_DianaPostBattle::
    .string "Você precisa enfrentar outros Treinadores\n"
    .string "para ver quão bom você realmente é.$"

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_LuisIntro::
    .string "Tchibum!\p"
    .string "Eu sou o primeiro!\n"
    .string "Vamos nessa!$"

CeruleanCity_Gym_Text_LuisDefeat::
    .string "Não pode ser!$"

CeruleanCity_Gym_Text_LuisPostBattle::
    .string "A Misty é uma Treinadora que vai\n"
    .string "continuar evoluindo sempre.\p"
    .string "Ela não vai perder para alguém como você!$"

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_GymGuyAdvice::
    .string "E aí!\n"
    .string "Futuro campeão!\p"
    .string "Deixe-me dar um conselho!\p"
    .string "A Líder, Misty, é uma fera que usa\n"
    .string "Pokémon do tipo Água.\p"
    .string "Você pode sugar toda a água deles com\n"
    .string "Pokémon do tipo Planta.\p"
    .string "Ou pode usar Pokémon do tipo Elétrico e\n"
    .string "dar um belo choque neles!$"

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
    .string "Você venceu a Misty!\n"
    .string "Viu só o que eu te falei?\p"
    .string "Você e eu, garoto, formamos uma\n"
    .string "baita equipe!$"

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "Ginásio Pokémon de Cerulean\n"
    .string "Líder: Misty\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginásio Pokémon de Cerulean\n"
    .string "Líder: Misty\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"
