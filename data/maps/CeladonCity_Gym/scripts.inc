CeladonCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Gym_OnTransition
	.byte 0

CeladonCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_ERIKA_REMATCH, CeladonCity_Gym_ResetRematchFlags
	end

CeladonCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_ERIKA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_ERIKA_POSTGAME
	return

CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_ERIKA_REWARD, CeladonCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_ERIKA_REMATCH, CeladonCity_Gym_EventScript_RematchLeader
	goto CeladonCity_Gym_EventScript_LeaderPostBattle
	end

CeladonCity_Gym_EventScript_ChallengeLeader::
	msgbox CeladonCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_LeaderIntro, CeladonCity_Gym_Text_LeaderDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

CeladonCity_Gym_Text_LeaderSpeech::
    .string "Olá…\n"
    .string "O clima está adorável hoje, não acha?\l"
    .string "É tão agradável…\p"
    .string "… Oh, céus…\n"
    .string "Eu devo ter cochilado. Boas-vindas.\p"
    .string "Meu nome é Erika.\n"
    .string "Sou a Líder do Ginásio de Celadon.\p"
    .string "Eu estudo a nobre arte dos\n"
    .string "arranjos florais.\p"
    .string "Meus Pokémon são exclusivamente do\n"
    .string "tipo Planta.$"


CeladonCity_Gym_Text_LeaderIntro::
    .string "… Ah, me perdoe, eu não fazia ideia\n"
    .string "de que desejava me desafiar.\p"
    .string "Muito bem, mas eu não vou perder.$"

CeladonCity_Gym_Text_LeaderDefeat::
    .string "Oh!\n"
    .string "Eu admito a derrota.$"

CeladonCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox CeladonCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CeladonCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox CeladonCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DAILY_ERIKA_REMATCH
	settrainerflag TRAINER_LASS_KAY						
	settrainerflag TRAINER_LASS_LISA						
	settrainerflag TRAINER_PICNICKER_TINA					
	settrainerflag TRAINER_BEAUTY_BRIDGET	
	settrainerflag TRAINER_BEAUTY_TAMIA					
	settrainerflag TRAINER_BEAUTY_LORI		
	settrainerflag TRAINER_COOLTRAINER_MARY
	call_if_set FLAG_RECEIVED_AIDE_EVERSTONE, CeladonCity_Gym_EventScript_NextAideCall
	goto CeladonCity_Gym_EventScript_GetTM
	end

CeladonCity_Gym_EventScript_NextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_3
	return

CeladonCity_Gym_Text_GetBadge::
    .string "Você é incrivelmente forte.\p"
    .string "Devo lhe conferir a\n"
    .string "Insígnia do Arco-Íris.$"

CeladonCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} recebeu a Insígnia do\n"
    .string "Arco-Íris de Erika!$"

CeladonCity_Gym_Text_ExplainBadge::
    .string "A Insígnia do Arco-Íris fará Pokémon\n"
    .string "de até Nv. 50 obedecerem a você.\p"
    .string "Ela também permite que Pokémon usem\n"
    .string "Força dentro e fora de batalha.$"

CeladonCity_Gym_EventScript_GetTM::
	msgbox CeladonCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM19, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeladonCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM19, 1
	setflag FLAG_GOT_ERIKA_REWARD
	msgbox CeladonCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_TakeThisWithYou::
    .string "Por favor, leve isto com você também.$"

CeladonCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} recebeu o MT19\n"
    .string "de Erika.$"

CeladonCity_Gym_Text_ExplainTM::
    .string "O MT19 contém o Dreno Gigante.\p"
    .string "Metade do dano causado é drenado\n"
    .string "para curar o seu Pokémon.\p"
    .string "Não concorda que é um golpe maravilhoso?$"

CeladonCity_Gym_EventScript_NoRoomForTM::
	msgbox CeladonCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_NoRoomForTM::
    .string "Você deveria abrir espaço para isto.$"

CeladonCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CeladonCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_LeaderPostBattle::
    .string "Você está catalogando Pokémon?\n"
    .string "Devo dizer que estou impressionada.\p"
    .string "Eu jamais colecionaria Pokémon se\n"
    .string "eles não fossem graciosos.$"

CeladonCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CeladonCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_PostBattleGameClear::
	.string "O clima está adorável hoje, não acha?\p"
	.string "É tão agradável…\p"
	.string "Receio que eu possa cochilar de novo…$"

CeladonCity_Gym_EventScript_RematchLeader::
	msgbox CeladonCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Gym_EventScript_PostgameRematch
	goto CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeladonCity_Gym_Text_RematchLeader::
	.string "Ah, se não é quem estava tentando\n"
	.string "completar a Pokédex.\p"
	.string "Espero sinceramente que as coisas tenham\n"
	.string "corrido bem desde o nosso último encontro.\p"
	.string "… Compreendo. Você com certeza andou ocupado.\p"
	.string "Eu não sou muito fã dessas coisas públicas…\p"
	.string "No entanto, batalhas são diferentes.\n"
	.string "É por isso que veio até aqui, não é?$"

CeladonCity_Gym_EventScript_DeclineRematch::
	msgbox CeladonCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_DeclineRematch::
	.string "Ora bem… talvez em outra ocasião.$"

CeladonCity_Gym_EventScript_PostgameRematch::
	msgbox CeladonCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeladonCity_Gym_Text_RematchMode::
	.string "Agora que você é o campeão,\n"
	.string "gostaria de ir com tudo?$"

CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_ERIKA_ORIGINAL, CeladonCity_Gym_Text_RematchOriginal, CeladonCity_Gym_Text_RematchDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeladonCity_Gym_Text_RematchOriginal::
	.string "Encantador, {PLAYER}!\n"
	.string "Vamos guardar esta lembrança com carinho!$"

CeladonCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10	
	trainerbattle_single LEADER_REMATCH_ERIKA_POSTGAME, CeladonCity_Gym_Text_RematchPostgame, CeladonCity_Gym_Text_RematchDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeladonCity_Gym_Text_RematchPostgame::
	.string "Muito bem, {PLAYER}!\n"
	.string "Prepare-se para uma batalha com tudo!$"

CeladonCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_ERIKA_REMATCH
	goto CeladonCity_Gym_EventScript_LeaderPostBattle
	end

CeladonCity_Gym_Text_RematchDefeat::
	.string "Simplesmente maravilhoso.\p"
	.string "Esse foi um esforço digno de pelo\n"
	.string "menos 10 Insígnias do Arco-Íris.$"

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_KayIntro::
    .string "Vou te contar uma coisa sobre este Ginásio:\p"
    .string "Apenas verdadeiras damas têm permissão\n"
    .string "para entrar aqui!$"

CeladonCity_Gym_Text_KayDefeat::
    .string "Você é bruto demais!$"

CeladonCity_Gym_Text_KayPostBattle::
    .string "Bleeh!\n"
    .string "Espero que a Erika acabe com você!$"

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LisaIntro::
    .string "Ei, você aí!\p"
    .string "Não gostamos de Pokémon dos tipos\n"
    .string "Inseto ou Fogo por aqui!$"

CeladonCity_Gym_Text_LisaDefeat::
    .string "Ah!\n"
    .string "Seu chato!$"

CeladonCity_Gym_Text_LisaPostBattle::
    .string "Nossa Líder Erika pode ser reservada,\n"
    .string "mas é muito famosa por aqui.$"

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TinaIntro::
    .string "… Não era você que estava espiando\n"
    .string "aqui mais cedo?$"

CeladonCity_Gym_Text_TinaDefeat::
    .string "Você me abriu os olhos!$"

CeladonCity_Gym_Text_TinaPostBattle::
    .string "Ah, você estava olhando para a Erika…\n"
    .string "Não estava olhando para mim…$"

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BridgetIntro::
    .string "Ah, boas-vindas.\n"
    .string "Eu já estava ficando entediada.$"

CeladonCity_Gym_Text_BridgetDefeat::
    .string "Minha maquiagem!$"

CeladonCity_Gym_Text_BridgetPostBattle::
    .string "Pokémon do tipo Planta são fortes\n"
    .string "contra o tipo Água.\p"
    .string "Eles também têm vantagem sobre Pokémon\n"
    .string "dos tipos Pedra e Terrestre.$"

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TamiaIntro::
    .string "Olhe, olhe!\n"
    .string "Veja meus Pokémon!\p"
    .string "Eu adoro o tipo Planta.\n"
    .string "Gosto de como são fáceis de criar.$"

CeladonCity_Gym_Text_TamiaDefeat::
    .string "Não!$"

CeladonCity_Gym_Text_TamiaPostBattle::
    .string "Só usamos Pokémon do tipo Planta\n"
    .string "no nosso Ginásio.\p"
    .string "Por quê? Porque também os usamos para\n"
    .string "fazer arranjos florais!$"

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LoriIntro::
    .string "Prazer em conhecer você.\n"
    .string "Meu passatempo é treinar Pokémon.$"

CeladonCity_Gym_Text_LoriDefeat::
    .string "Oh!\n"
    .string "Esplêndido!$"

CeladonCity_Gym_Text_LoriPostBattle::
    .string "Tenho um encontro às cegas em breve.\n"
    .string "Preciso aprender a ser educada,\l"
    .string "especialmente se tiver que batalhar.$"

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_MaryIntro::
    .string "Boas-vindas ao Ginásio de Celadon!\p"
    .string "É melhor não subestimar as doces\n"
    .string "damas daqui.$"

CeladonCity_Gym_Text_MaryDefeat::
    .string "Oh!\n"
    .string "Derrotada!$"

CeladonCity_Gym_Text_MaryPostBattle::
    .string "Eu não trouxe meus melhores Pokémon.\n"
    .string "Espere só até a próxima!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "Ginásio Pokémon de Celadon\n"
    .string "Líder: Erika\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginásio Pokémon de Celadon\n"
    .string "Líder: Erika\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"
