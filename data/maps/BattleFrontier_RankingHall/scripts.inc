BattleFrontier_RankingHall_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_DomeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PikeRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ShowRecords::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ALL_JOHTO_LEADERS, BattleFrontier_RankingHall_EventScript_AttendantMaster
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_AttendantMaster::
	goto_if_set FLAG_RECEIVED_JOHTO_HALL_REWARD, BattleFrontier_RankingHall_EventScript_AttendantMasterRepeat
	msgbox BattleFrontier_RankingHall_Text_MasterCongratulations, MSGBOX_DEFAULT
	giveitem ITEM_PP_MAX, 3
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_JOHTO_HALL_REWARD
	msgbox BattleFrontier_RankingHall_Text_MtSilverAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_AttendantMasterRepeat::
	msgbox BattleFrontier_RankingHall_Text_MtSilverAdvice, MSGBOX_DEFAULT
	release
	end

@ ========================================================
@ JOHTO GYM LEADERS
@ ========================================================

@ 1. Falkner (Violet City - Voador)
BattleFrontier_RankingHall_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_FALKNER, BattleFrontier_RankingHall_EventScript_FalknerRematch
	msgbox BattleFrontier_RankingHall_Text_FalknerIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, BattleFrontier_RankingHall_Text_FalknerDefeat
	setflag FLAG_DEFEATED_LEADER_FALKNER
	msgbox BattleFrontier_RankingHall_Text_FalknerPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_FalknerRematch::
	msgbox BattleFrontier_RankingHall_Text_FalknerRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_FalknerIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, BattleFrontier_RankingHall_Text_FalknerDefeat
	msgbox BattleFrontier_RankingHall_Text_FalknerPostBattle, MSGBOX_DEFAULT
	release
	end

@ 2. Bugsy (Azalea Town - Inseto)
BattleFrontier_RankingHall_EventScript_Bugsy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_BUGSY, BattleFrontier_RankingHall_EventScript_BugsyRematch
	msgbox BattleFrontier_RankingHall_Text_BugsyIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_BUGSY, BattleFrontier_RankingHall_Text_BugsyDefeat
	setflag FLAG_DEFEATED_LEADER_BUGSY
	msgbox BattleFrontier_RankingHall_Text_BugsyPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_SILVER_POWDER, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_BugsyRematch::
	msgbox BattleFrontier_RankingHall_Text_BugsyRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_BugsyIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_BUGSY, BattleFrontier_RankingHall_Text_BugsyDefeat
	msgbox BattleFrontier_RankingHall_Text_BugsyPostBattle, MSGBOX_DEFAULT
	release
	end

@ 3. Whitney (Goldenrod City - Normal)
BattleFrontier_RankingHall_EventScript_Whitney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_WHITNEY, BattleFrontier_RankingHall_EventScript_WhitneyRematch
	msgbox BattleFrontier_RankingHall_Text_WhitneyIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, BattleFrontier_RankingHall_Text_WhitneyDefeat
	setflag FLAG_DEFEATED_LEADER_WHITNEY
	msgbox BattleFrontier_RankingHall_Text_WhitneyPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_WhitneyRematch::
	msgbox BattleFrontier_RankingHall_Text_WhitneyRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_WhitneyIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, BattleFrontier_RankingHall_Text_WhitneyDefeat
	msgbox BattleFrontier_RankingHall_Text_WhitneyPostBattle, MSGBOX_DEFAULT
	release
	end

@ 4. Morty (Ecruteak City - Fantasma)
BattleFrontier_RankingHall_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_MORTY, BattleFrontier_RankingHall_EventScript_MortyRematch
	msgbox BattleFrontier_RankingHall_Text_MortyIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_MORTY, BattleFrontier_RankingHall_Text_MortyDefeat
	setflag FLAG_DEFEATED_LEADER_MORTY
	msgbox BattleFrontier_RankingHall_Text_MortyPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_MortyRematch::
	msgbox BattleFrontier_RankingHall_Text_MortyRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_MortyIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_MORTY, BattleFrontier_RankingHall_Text_MortyDefeat
	msgbox BattleFrontier_RankingHall_Text_MortyPostBattle, MSGBOX_DEFAULT
	release
	end

@ 5. Chuck (Cianwood City - Lutador)
BattleFrontier_RankingHall_EventScript_Chuck::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_CHUCK, BattleFrontier_RankingHall_EventScript_ChuckRematch
	msgbox BattleFrontier_RankingHall_Text_ChuckIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_CHUCK, BattleFrontier_RankingHall_Text_ChuckDefeat
	setflag FLAG_DEFEATED_LEADER_CHUCK
	msgbox BattleFrontier_RankingHall_Text_ChuckPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_ChuckRematch::
	msgbox BattleFrontier_RankingHall_Text_ChuckRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_ChuckIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_CHUCK, BattleFrontier_RankingHall_Text_ChuckDefeat
	msgbox BattleFrontier_RankingHall_Text_ChuckPostBattle, MSGBOX_DEFAULT
	release
	end

@ 6. Jasmine (Olivine City - Aço)
BattleFrontier_RankingHall_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_JASMINE, BattleFrontier_RankingHall_EventScript_JasmineRematch
	msgbox BattleFrontier_RankingHall_Text_JasmineIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_JASMINE, BattleFrontier_RankingHall_Text_JasmineDefeat
	setflag FLAG_DEFEATED_LEADER_JASMINE
	msgbox BattleFrontier_RankingHall_Text_JasminePostBattle, MSGBOX_DEFAULT
	giveitem ITEM_METAL_COAT, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_JasmineRematch::
	msgbox BattleFrontier_RankingHall_Text_JasmineRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_JasmineIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_JASMINE, BattleFrontier_RankingHall_Text_JasmineDefeat
	msgbox BattleFrontier_RankingHall_Text_JasminePostBattle, MSGBOX_DEFAULT
	release
	end

@ 7. Pryce (Mahogany Town - Gelo)
BattleFrontier_RankingHall_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_PRYCE, BattleFrontier_RankingHall_EventScript_PryceRematch
	msgbox BattleFrontier_RankingHall_Text_PryceIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_PRYCE, BattleFrontier_RankingHall_Text_PryceDefeat
	setflag FLAG_DEFEATED_LEADER_PRYCE
	msgbox BattleFrontier_RankingHall_Text_PrycePostBattle, MSGBOX_DEFAULT
	giveitem ITEM_NEVER_MELT_ICE, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_PryceRematch::
	msgbox BattleFrontier_RankingHall_Text_PryceRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_PryceIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_PRYCE, BattleFrontier_RankingHall_Text_PryceDefeat
	msgbox BattleFrontier_RankingHall_Text_PrycePostBattle, MSGBOX_DEFAULT
	release
	end

@ 8. Clair (Blackthorn City - Dragão)
BattleFrontier_RankingHall_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_CLAIR, BattleFrontier_RankingHall_EventScript_ClairRematch
	msgbox BattleFrontier_RankingHall_Text_ClairIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_CLAIR, BattleFrontier_RankingHall_Text_ClairDefeat
	setflag FLAG_DEFEATED_LEADER_CLAIR
	msgbox BattleFrontier_RankingHall_Text_ClairPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_DRAGON_FANG, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

BattleFrontier_RankingHall_EventScript_ClairRematch::
	msgbox BattleFrontier_RankingHall_Text_ClairRematchPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_RankingHall_EventScript_LeaderDecline
	msgbox BattleFrontier_RankingHall_Text_ClairIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LEADER_CLAIR, BattleFrontier_RankingHall_Text_ClairDefeat
	msgbox BattleFrontier_RankingHall_Text_ClairPostBattle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_LeaderDecline::
	msgbox BattleFrontier_RankingHall_Text_LeaderDecline, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_CheckAllLeaders::
	goto_if_unset FLAG_DEFEATED_LEADER_FALKNER, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_BUGSY, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_WHITNEY, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_MORTY, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_CHUCK, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_JASMINE, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_PRYCE, Common_EventScript_Return
	goto_if_unset FLAG_DEFEATED_LEADER_CLAIR, Common_EventScript_Return
	goto_if_set FLAG_DEFEATED_ALL_JOHTO_LEADERS, Common_EventScript_Return
	setflag FLAG_DEFEATED_ALL_JOHTO_LEADERS
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox BattleFrontier_RankingHall_Text_AllLeadersDefeatedAlert, MSGBOX_DEFAULT
	waitfanfare
	return

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_NinjaBoy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy::
	msgbox BattleFrontier_RankingHall_Text_Boy, MSGBOX_NPC
	end

@ ========================================================
@ TEXTOS EM PORTUGUÊS
@ ========================================================

BattleFrontier_RankingHall_Text_ExplainRankingHall:
	.string "Recepcionista: Boas-vindas ao Salão\n"
	.string "dos Líderes de Johto!\p"
	.string "Os 8 Líderes de Ginásio oficiais de\n"
	.string "Johto vieram em missão de treinamento\l"
	.string "após a chegada do novo Campeão!\p"
	.string "Cada um deles montou uma equipe de nível\n"
	.string "elevadíssimo para testar suas forças.\p"
	.string "Derrote todos os 8 para provar que é o\n"
	.string "maior mestre das duas regiões!$"

BattleFrontier_RankingHall_Text_AllLeadersDefeatedAlert:
	.string "Extraordinário!\p"
	.string "Você derrotou todos os 8 Líderes\n"
	.string "de Ginásio da região de Johto!\p"
	.string "Fale com a recepcionista na entrada\n"
	.string "para receber sua consagração!$"

BattleFrontier_RankingHall_Text_MasterCongratulations:
	.string "Recepcionista: Incrível, {PLAYER}!\n"
	.string "Você venceu os 8 Líderes de Johto!\p"
	.string "Como prova do seu feito lendário,\n"
	.string "por favor, aceite esta recompensa!$"

BattleFrontier_RankingHall_Text_MtSilverAdvice:
	.string "Recepcionista: Agora que você conquistou\n"
	.string "Kanto e Johto, resta apenas um desafio...\p"
	.string "O lendário Campeão Red está treinando\n"
	.string "sob a tempestade de neve no cume do\l"
	.string "Monte Silver!\p"
	.string "Pegue o barco S.S. Aqua no porto e\n"
	.string "enfrente o teste definitivo!$"

BattleFrontier_RankingHall_Text_LeaderDecline:
	.string "Tudo bem! Venha quando sua equipe\n"
	.string "estiver completamente preparada.$"

@ Falkner
BattleFrontier_RankingHall_Text_FalknerIntro:
	.string "Falkner: Eu sou Falkner, Líder de\n"
	.string "Violet City!\p"
	.string "Com as asas velozes dos meus Pokémon dos\n"
	.string "céus, cortaremos os ventos da vitória!$"

BattleFrontier_RankingHall_Text_FalknerDefeat:
	.string "Minhas asas... foram derrubadas por\n"
	.string "sua força admirável!$"

BattleFrontier_RankingHall_Text_FalknerPostBattle:
	.string "Falkner: Seus Pokémon voam mais alto do\n"
	.string "que qualquer tempestade. Fique com isto!$"

BattleFrontier_RankingHall_Text_FalknerRematchPrompt:
	.string "Falkner: O vento sopra forte hoje!\n"
	.string "Deseja travar um duelo aéreo novamente?$"

@ Bugsy
BattleFrontier_RankingHall_Text_BugsyIntro:
	.string "Bugsy: Eu sou Bugsy, Líder de Azalea!\n"
	.string "Sei tudo sobre Pokémon do tipo Inseto!\p"
	.string "Vou te mostrar o poder fascinante da\n"
	.string "minha grande pesquisa entomológica!$"

BattleFrontier_RankingHall_Text_BugsyDefeat:
	.string "Incrível! Você explorou cada fraqueza\n"
	.string "com maestria cirúrgica!$"

BattleFrontier_RankingHall_Text_BugsyPostBattle:
	.string "Bugsy: Nunca subestime um inseto!\n"
	.string "Eles são resilientes, assim como você!$"

BattleFrontier_RankingHall_Text_BugsyRematchPrompt:
	.string "Bugsy: Quer rever minhas estratégias de\n"
	.string "inseto em outra batalha?$"

@ Whitney
BattleFrontier_RankingHall_Text_WhitneyIntro:
	.string "Whitney: Oi! Eu sou Whitney, Líder de\n"
	.string "Goldenrod City!\p"
	.string "Todo mundo acha meus Pokémon fofinhos,\n"
	.string "mas espere até sentir o poder devastador\l"
	.string "do meu querido Miltank!$"

BattleFrontier_RankingHall_Text_WhitneyDefeat:
	.string "Buaaaa! Você é forte demais!\n"
	.string "Não vale me fazer chorar assim!$"

BattleFrontier_RankingHall_Text_WhitneyPostBattle:
	.string "Whitney: Fung... Snif... Pronto, já passou!\n"
	.string "Você realmente sabe lutar muito bem!\l"
	.string "Fique com isto de lembrança!$"

BattleFrontier_RankingHall_Text_WhitneyRematchPrompt:
	.string "Whitney: Não vou chorar dessa vez!\n"
	.string "Vamos ter uma revanche agora?$"

@ Morty
BattleFrontier_RankingHall_Text_MortyIntro:
	.string "Morty: Eu sou Morty, Líder de Ecruteak.\p"
	.string "Passei minha vida inteira meditando e\n"
	.string "desvendando os segredos do além.\p"
	.string "Consegue enxergar através do véu de\n"
	.string "ilusão dos meus Pokémon Fantasma?$"

BattleFrontier_RankingHall_Text_MortyDefeat:
	.string "Sua luz é intensa demais...\n"
	.string "Ela dissipou todas as minhas sombras!$"

BattleFrontier_RankingHall_Text_MortyPostBattle:
	.string "Morty: A conexão que você compartilha\n"
	.string "com seus parceiros é profunda e eterna.$"

BattleFrontier_RankingHall_Text_MortyRematchPrompt:
	.string "Morty: Os espíritos sussurram seu nome...\n"
	.string "Deseja cruzar o véu espiritual de novo?$"

@ Chuck
BattleFrontier_RankingHall_Text_ChuckIntro:
	.string "Chuck: Wahahaha! Eu sou Chuck, Líder de\n"
	.string "Cianwood City!\p"
	.string "Treinei dia e noite sob cachoeiras\n"
	.string "estrondosas e quebrando rochedos!\p"
	.string "Mostre-me a força bruta dos seus punhos\n"
	.string "e a determinação do seu espírito!$"

BattleFrontier_RankingHall_Text_ChuckDefeat:
	.string "Urrgh! Que impacto monumental!\n"
	.string "Fui completamente arremessado!$"

BattleFrontier_RankingHall_Text_ChuckPostBattle:
	.string "Chuck: Wahaha! Fazia tempo que eu não\n"
	.string "sentia um golpe tão firme! Fique com isto!$"

BattleFrontier_RankingHall_Text_ChuckRematchPrompt:
	.string "Chuck: Meus músculos já estão aquecidos!\n"
	.string "Pronto para mais um round de ferro?$"

@ Jasmine
BattleFrontier_RankingHall_Text_JasmineIntro:
	.string "Jasmine: Olá... Eu sou Jasmine, Líder\n"
	.string "do Ginásio de Olivine City.\p"
	.string "Meus Pokémon podem parecer serenos,\n"
	.string "mas sua carapaça de aço é impenetrável!$"

BattleFrontier_RankingHall_Text_JasmineDefeat:
	.string "Você... brilhou com ainda mais força\n"
	.string "que o meu mais puro aço temperado!$"

BattleFrontier_RankingHall_Text_JasminePostBattle:
	.string "Jasmine: A verdadeira fortaleza não vem\n"
	.string "apenas do metal, mas sim do coração.$"

BattleFrontier_RankingHall_Text_JasmineRematchPrompt:
	.string "Jasmine: Gostaria de testar a dureza do\n"
	.string "meu Steelix mais uma vez?$"

@ Pryce
BattleFrontier_RankingHall_Text_PryceIntro:
	.string "Pryce: Sou Pryce, Líder de Mahogany.\p"
	.string "Mais de 50 invernos de frio congelante\n"
	.string "me ensinaram a resiliência do gelo.\p"
	.string "Seus laços suportarão uma tempestade de\n"
	.string "neve com ventos polares?$"

BattleFrontier_RankingHall_Text_PryceDefeat:
	.string "Ah... O calor da sua determinação\n"
	.string "derreteu até o mais espesso permafrost!$"

BattleFrontier_RankingHall_Text_PrycePostBattle:
	.string "Pryce: Juventude com sabedoria é uma\n"
	.string "combinação magnífica. Leve este cristal.$"

BattleFrontier_RankingHall_Text_PryceRematchPrompt:
	.string "Pryce: O inverno é paciente.\n"
	.string "Aceita congelar o campo em novo duelo?$"

@ Clair
BattleFrontier_RankingHall_Text_ClairIntro:
	.string "Clair: Eu sou Clair, Líder de Blackthorn\n"
	.string "e a maior mestra de dragões do mundo!\p"
	.string "Não pense que será fácil só porque você\n"
	.string "conquistou a Liga Pokémon de Kanto!\p"
	.string "Curva-se diante da fúria draconiana!$"

BattleFrontier_RankingHall_Text_ClairDefeat:
	.string "O quê?! Como eu pude ser superada por\n"
	.string "você?! Não é possível!$"

BattleFrontier_RankingHall_Text_ClairPostBattle:
	.string "Clair: Hmph! Eu não aceito fácil... mas\n"
	.string "admito que você possui garra de lenda!\l"
	.string "Tome esta presa de dragão sagrada!$"

BattleFrontier_RankingHall_Text_ClairRematchPrompt:
	.string "Clair: Da próxima vez meu Kingdra não\n"
	.string "terá piedade! Aceita a desforra?$"

@ Visitantes
BattleFrontier_RankingHall_Text_NinjaBoy:
	.string "Todos os 8 Líderes de Johto aqui no mesmo\n"
	.string "teto... O poder neste salão é surreal!$"

BattleFrontier_RankingHall_Text_Boy:
	.string "A Whitney parece inofensiva, mas aquele\n"
	.string "Rollout do Miltank assombra meus sonhos!$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords:
	.string "Registros do Domo, Tubo e Fábrica da Batalha$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords:
	.string "Registros do Palácio, Arena e Pirâmide$"

