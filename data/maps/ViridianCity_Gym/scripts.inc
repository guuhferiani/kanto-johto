.set LOCALID_GIOVANNI, 1
.set LOCALID_RIVAL, 2

ViridianCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_Gym_OnTransition
	.byte 0

ViridianCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_RIVAL_REMATCH, ViridianCity_Gym_ResetRematchFlags
	end

ViridianCity_Gym_ResetRematchFlags::
	cleartrainerflag TRAINER_RIVAL_POSTGAME_JOLTEON
	cleartrainerflag TRAINER_RIVAL_POSTGAME_FLAREON
	cleartrainerflag TRAINER_RIVAL_POSTGAME_VAPOREON
	return

ViridianCity_Gym_EventScript_Giovanni::
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni
	goto_if_unset FLAG_GOT_GIOVANNI_REWARD, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_Text_GiovanniIntro::
    .string "Fwahahaha!\n"
    .string "Bem-vindo ao meu esconderijo!\p"
    .string "Sera assim ate que eu possa restaurar\n"
    .string "a Equipe Rocket a sua antiga gloria.\p"
    .string "Mas voce me encontrou de novo.\n"
    .string "Que assim seja.\p"
	.string "Desta vez, nao vou me conter!\p"
    .string "Mais uma vez, voce enfrentara\n"
    .string "Giovanni, o maior dos Treinadores!$"

ViridianCity_Gym_Text_GiovanniPostBattle::
    .string "Tendo perdido dessa forma,\n"
    .string "nao posso encarar meus seguidores.\l"
    .string "Eu traí a confianca deles.\p"
    .string "A partir de hoje, a Equipe Rocket\n"
    .string "esta acabada para sempre!\p"
    .string "Quanto a mim, dedicarei minha vida\n"
    .string "a treinar novamente.\p"
    .string "Que nos encontremos de novo algum dia!\n"
    .string "Adeus!$"

ViridianCity_Gym_Text_GiovanniDefeat::
    .string "Ha!\n"
    .string "Essa foi uma luta verdadeiramente\n"
    .string "intensa.$"

ViridianCity_Gym_Text_GiovanniGiveBadge::
    .string "Voce venceu!\p"
    .string "Como prova, aqui esta a Insignia da\n"
    .string "Terra!$"

ViridianCity_Gym_Text_ReceivedBadgeFromGiovanni::
    .string "{PLAYER} recebeu a Insignia da\n"
    .string "Terra de Giovanni.$"

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	msgbox ViridianCity_Gym_Text_GiovanniGiveBadge
	playfanfare MUS_OBTAIN_BADGE
	message ViridianCity_Gym_Text_ReceivedBadgeFromGiovanni
	waitmessage
	waitfanfare
	settrainerflag 	TRAINER_TAMER_JASON							
	settrainerflag 	TRAINER_TAMER_COLE							
	settrainerflag 	TRAINER_BLACK_BELT_ATSUSHI					
	settrainerflag 	TRAINER_BLACK_BELT_KIYO						
	settrainerflag 	TRAINER_BLACK_BELT_TAKASHI					
	settrainerflag 	TRAINER_COOLTRAINER_SAMUEL					
	settrainerflag 	TRAINER_COOLTRAINER_YUJI					
	settrainerflag 	TRAINER_COOLTRAINER_WARREN					
	setflag FLAG_BADGE08_GET
	clearflag FLAG_HIDE_RIVAL22_MANDATORY
	setvar VAR_ROUTE_22_RIVAL_STATE, 4
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_Gym_EventScript_NoRoomForTM26
	playfanfare MUS_OBTAIN_TMHM
	message ViridianCity_Gym_Text_ReceivedTM26FromGiovanni
	waitmessage
	waitfanfare
	additem ITEM_TM26, 1
	setflag FLAG_GOT_GIOVANNI_REWARD
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
    .string "A Insignia da Terra faz qualquer\n"
    .string "Pokemon de qualquer nivel obedecer\l"
    .string "sem questionar.\p"
    .string "E a prova do seu dominio como um\n"
    .string "Treinador de Pokemon.\p"
    .string "Com ela, voce pode desafiar a\n"
    .string "Liga Pokemon.\p"
    .string "Alem disso, fique com este TM.\p"
    .string "Considere-o um presente para o seu\n"
    .string "desafio na Liga Pokemon.$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
    .string "{PLAYER} recebeu o TM26\n"
    .string "de Giovanni.$"

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_Text_ExplainTM26::
    .string "O TM26 contem Earthquake.\p"
    .string "E um ataque poderoso que causa um\n"
    .string "tremor devastador.\p"
    .string "Eu o criei quando comandava o\n"
    .string "Ginasio aqui, ha muito tempo...$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
    .string "Voce nao tem espaco para isto!\p"
    .string "Nao vou permanecer aqui por muito tempo.\p"
    .string "Abra espaco na mochila e fale comigo\n"
    .string "novamente.$"


ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_JasonIntro::
    .string "Os Pokemon e eu, fazemos uma musica\n"
    .string "maravilhosa juntos!$"

ViridianCity_Gym_Text_JasonDefeat::
    .string "Voce esta em perfeita harmonia!$"

ViridianCity_Gym_Text_JasonPostBattle::
    .string "Voce sabe a identidade do nosso\n"
    .string "Lider de Ginasio?$"

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_ColeIntro::
    .string "Seus Pokemon vao tremer ao estalo\n"
    .string "do meu chicote!$"

ViridianCity_Gym_Text_ColeDefeat::
    .string "Ai ai ai!\n"
    .string "Que chicotada!$"

ViridianCity_Gym_Text_ColePostBattle::
    .string "Espere!\n"
    .string "Eu fui apenas descuidado!$"

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_AtsushiIntro::
    .string "Rrrroaar!\n"
    .string "Estou ficando enfurecido!$"

ViridianCity_Gym_Text_AtsushiDefeat::
    .string "Uaaargh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
    .string "Ainda nao sou digno!$"

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_KiyoIntro::
    .string "O karate e a forma definitiva de arte\n"
    .string "marcial!$"

ViridianCity_Gym_Text_KiyoDefeat::
    .string "Aiyah!$"

ViridianCity_Gym_Text_KiyoPostBattle::
    .string "Se meus Pokemon fossem tao bons no\n"
    .string "karate quanto eu...$"

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_TakashiIntro::
    .string "Eu sou o Rei do Karate!\n"
    .string "Seu destino repousa comigo!$"

ViridianCity_Gym_Text_TakashiDefeat::
    .string "Ayah!$"

ViridianCity_Gym_Text_TakashiPostBattle::
    .string "A Liga Pokemon?\n"
    .string "Voce? Nao fique convencido!$"

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_SamuelIntro::
    .string "O Ginasio de Viridian ficou fechado\n"
    .string "por muito tempo.\p"
    .string "Mas agora, nosso Lider voltou!$"

ViridianCity_Gym_Text_SamuelDefeat::
    .string "Eu fui derrotado?$"

ViridianCity_Gym_Text_SamuelPostBattle::
    .string "Voce so podera ir para a Liga Pokemon\n"
    .string "se derrotar o nosso Lider de Ginasio!$"

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_YujiIntro::
    .string "Heh!\n"
    .string "Voce ja deve estar perdendo o folego\l"
    .string "a essa altura!$"

ViridianCity_Gym_Text_YujiDefeat::
    .string "Acabou meu combustivel!$"

ViridianCity_Gym_Text_YujiPostBattle::
    .string "Voce precisara de forca para aguentar\n"
    .string "o ritmo do nosso Lider.$"

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_WarrenIntro::
    .string "Os que tem verdadeiro talento vencem\n"
    .string "com estilo.$"

ViridianCity_Gym_Text_WarrenDefeat::
    .string "Perdi o controle!$"

ViridianCity_Gym_Text_WarrenPostBattle::
    .string "O Lider vai me dar uma bronca por\n"
    .string "perder dessa maneira...$"


ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_Text_GymGuyAdvice::
    .string "E ai!\n"
    .string "Futuro campeao!\p"
    .string "Nem mesmo eu sei a identidade do\n"
    .string "Lider de Viridian.\p"
    .string "Mas uma coisa e certa:\n"
    .string "este sera o mais dificil de todos\l"
    .string "os Lideres de Ginasio.\p"
    .string "Alem disso, ouvi dizer que os\n"
    .string "Treinadores daqui curtem Pokemon\l"
    .string "do tipo Terrestre.$"

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_Text_GymGuyPostVictory::
    .string "Caiu o meu queixo! Giovanni era o\n"
    .string "Lider de Ginasio de Viridian?$"

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "Ginasio Pokemon de Viridian\n"
    .string "Lider: ?\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}$"

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "Ginasio Pokemon de Viridian\n"
    .string "Lider: ?\p"
    .string "Treinadores Vencedores:\n"
    .string "{RIVAL}, {PLAYER}$"

ViridianCity_Gym_EventScript_Rival::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_RIVAL_REMATCH, ViridianCity_Gym_EventScript_RivalPostBattle
	goto_if_set FLAG_RIVAL_REMATCHED, ViridianCity_Gym_EventScript_SkipRivalSpeech
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	msgbox ViridianCity_Gym_Text_RivalSpeech, MSGBOX_NPC
	setflag FLAG_RIVAL_REMATCHED

ViridianCity_Gym_EventScript_SkipRivalSpeech::
	msgbox ViridianCity_Gym_Text_RematchLeader, MSGBOX_DEFAULT
	goto_if_eq VAR_RIVAL_WINRATE, 2, ViridianCity_Gym_EventScript_RivalJolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, ViridianCity_Gym_EventScript_RivalFlareon
	goto ViridianCity_Gym_EventScript_RivalVaporeon
	end

ViridianCity_Gym_Text_RivalSpeech::
	.string "{RIVAL}: ...{PLAYER}?\n"
	.string "Eu estive pensando...\p"
	.string "Quando comecei esta jornada,\n"
	.string "eu realmente achava que era o melhor\l"
	.string "que existia...\p"
	.string "Mas voce sempre esteve la, logo\n"
	.string "atras de mim... e eu me descuidei.\p"
	.string "Preciso de um tempo para refletir.\n"
	.string "Quem sabe...\p"
	.string "Posso nao ser o campeao, mas talvez\n"
	.string "um dia eu seja um Lider de Ginasio...\p"
	.string "...\p"
	.string "Ah, tanto faz! Nao ha tempo para ficar\n"
	.string "sentimental!$"

ViridianCity_Gym_Text_RematchLeader::
	.string "Entao o que esta fazendo aqui?\n"
	.string "Veio esfregar na minha cara?\p"
	.string "Pois saiba que cometeu um erro!\p"
	.string "Nao pense que vou te deixar aparecer\n"
	.string "sem te desafiar para uma batalha!$"

ViridianCity_Gym_EventScript_RivalJolteon::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single TRAINER_RIVAL_POSTGAME_JOLTEON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_EventScript_RivalFlareon::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single TRAINER_RIVAL_POSTGAME_FLAREON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_EventScript_RivalVaporeon::
	setvar VAR_0x8003, 1
	setvar VAR_0x8004, 10
	trainerbattle_single TRAINER_RIVAL_POSTGAME_VAPOREON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_Text_RivalIntro::
	.string "Muito bem!\n"
	.string "Ja faz um tempo que nao luto com tudo.\p"
	.string "Vou provar que ainda sou o melhor!$"

ViridianCity_Gym_Text_RivalDefeat::
	.string "Poxa vida, o que eu estava fazendo?$"

ViridianCity_Gym_EventScript_DefeatedRival::
	setflag FLAG_DAILY_RIVAL_REMATCH

ViridianCity_Gym_EventScript_RivalPostBattle::
	msgbox ViridianCity_Gym_Text_RivalPostBattle, MSGBOX_DEFAULT
	call_if_unset FLAG_GOT_GIOVANNI_REWARD, ViridianCity_Gym_EventScript_RivalFoundTM
	turnobject LOCALID_RIVAL, DIR_NORTH
	release
	end

ViridianCity_Gym_Text_RivalPostBattle::
	.string "Nao gosto de admitir, mas ainda nao\n"
	.string "estou no seu nivel.\p"
	.string "Mas da proxima vez, eu vou vencer!$"

ViridianCity_Gym_EventScript_RivalFoundTM::
	msgbox ViridianCity_Gym_Text_FoundThis, MSGBOX_DEFAULT
	checkitemspace ITEM_TM26, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_Gym_EventScript_NoRoomForTM262
	playfanfare MUS_OBTAIN_TMHM
	message ViridianCity_Gym_Text_ReceivedTM26FromRival
	waitmessage
	waitfanfare
	additem ITEM_TM26, 1
	setflag FLAG_GOT_GIOVANNI_REWARD
	msgbox ViridianCity_Gym_Text_RivalExplainTM26	
	return

ViridianCity_Gym_Text_FoundThis::
	.string "Ah, quase esqueci!\p"
	.string "Encontrei isto quando estava vigiando\n"
	.string "este lugar.\p"
	.string "Por mais que eu odeie te presentear,\n"
	.string "eu ja tenho esse TM.\p"
	.string "Pode ficar com ele.$"

ViridianCity_Gym_Text_ReceivedTM26FromRival::
    .string "{PLAYER} recebeu o TM26\n"
    .string "de {RIVAL}.$"

ViridianCity_Gym_EventScript_NoRoomForTM262::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace2
	release
	end

ViridianCity_Gym_Text_RivalExplainTM26::
    .string "O TM26 contem Earthquake.\p"
    .string "E um ataque poderoso que causa um\n"
    .string "tremor devastador.$"

ViridianCity_Gym_Text_YouDoNotHaveSpace2::
    .string "Ah, voce nao tem espaco para isto?\p"
    .string "Uma pena! Acho que vou guardar. Ha!$"

ViridianCity_Gym_EventScript_MewtwoY::
	lock
	faceplayer
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_MEIHUI, ViridianCity_Gym_EventScript_MewtwoYDefeated
	msgbox ViridianCity_Gym_Text_MewtwoY MSGBOX_DEFAULT
	release
	end

ViridianCity_Gym_Text_MewtwoY:
	.string "Entao foi voce quem esvaziou o ego\n"
	.string "gigantesco de Giovanni.\p"
	.string "Os lacos que voce forjou com seus\n"
	.string "Pokemon lhe concedem imensa forca.\p"
	.string "Espero que aceite o nosso desafio.$"

ViridianCity_Gym_EventScript_Ranger_MEIHUI::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MEIHUI, ViridianCity_Gym_EventScript_MegaHintMewtwo
	trainerbattle_single TRAINER_POKEMON_RANGER_F_MEIHUI, ViridianCity_Gym_Text_MeiHuiIntro, ViridianCity_Gym_Text_MeiHuiDefeat
	setflag FLAG_DEFEATED_MEIHUI
	msgbox ViridianCity_Gym_Text_MeiHuiPostBattle MSGBOX_AUTOCLOSE
	release
	end

ViridianCity_Gym_Text_MeiHuiIntro:
	.string "Parado bem ai!\p"
	.string "Este Ginasio Pokemon agora esta sob o\n"
	.string "controle da Equipe Amarela!$"

ViridianCity_Gym_Text_MeiHuiDefeat:
	.string "Lute com justica, quer fazer o favor?$"

ViridianCity_Gym_Text_MeiHuiPostBattle:
	.string "Admita! Meus Pokemon bebes mandam\n"
	.string "muito bem!$"

ViridianCity_Gym_EventScript_MegaHintMewtwo::    
    goto_if_set FLAG_GOT_MEWTWONITE_Y, ViridianCity_Gym_EventScript_MeiHuiDefeated
    msgbox ViridianCity_Gym_Text_MewtwoYMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
ViridianCity_Gym_Text_MewtwoYMegaHint:
    .string "Nao, voce nao pode ter meus itens!\p"
	.string "Quem voce pensa que e... ah.\n"
	.string "Voce quer saber como meu Mewtwo pode\l"
	.string "evoluir durante uma batalha.\p"
	.string "Esse e o poder dos Mega Pokemon!\p"
	.string "Procure na Cerulean Cave por uma\n"
	.string "pedra especial. Confie em mim!\p"
	.string "Ela deixou o meu 3 Estrelas ainda\n"
	.string "melhor.$"

ViridianCity_Gym_EventScript_MeiHuiDefeated::
    msgbox MeiHuiDefeated_Text MSGBOX_DEFAULT
	release
	end

MeiHuiDefeated_Text:	
	.string "Ei, voce e da equipe Vermelha ou Azul?\p"
	.string "Pode me derrubar do ginasio?\n"
	.string "Eu queria pegar minhas moedas.$"

ViridianCity_Gym_EventScript_MewtwoYDefeated::
	msgbox MewtwoYDefeated MSGBOX_DEFAULT
	release
	end

MewtwoYDefeated:	
	.string "Mantenha a cabeca erguida, {PLAYER}.\p"
	.string "Voce foi um oponente formidavel.$"
