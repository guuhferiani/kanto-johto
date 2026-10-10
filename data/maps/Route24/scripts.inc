.set LOCALID_CALE, 1
.set LOCALID_ALI, 2
.set LOCALID_TIMMY, 3
.set LOCALID_RELI, 4
.set LOCALID_ETHAN, 5
.set LOCALID_DISGUISED_ROCKET, 8
.set LOCALID_JESSIE, 9
.set LOCALID_JAMES, 10
.set LOCALID_ROCKET, 11
.set LOCALID_LOOKER, 12
.set LOCALID_CHARMANDER, 13


Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route24_OnResume
	.byte 0

Route24_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route24_OnResume:
	call Common_EventScript_GetDayOrNight
	end

@Charmander
Route24_EventScript_Charmander::
	call Route24_EventScript_CharmanderEmote
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	msgbox Route24_Text_Charmander, MSGBOX_NPC
	waitmoncry
	release
	end

Route24_Text_Charmander:
	.string "Charmander: Char!$"

Route24_EventScript_CharmanderEmote::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_CHARMANDER, Common_Movement_ExclamationMark
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Route24_EventScript_CharmanderGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_CHARMANDER, Route24_EventScript_HowsCharmander
	msgbox Route24_Text_NotCutOutToBeATrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_BetterReleaseIt
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	random 128
    copyvar VAR_0x8004, VAR_RESULT
    goto_if_eq VAR_0x8004, 1, Route24_EventScript_CharmanderGuyLucky
    setvar VAR_0x8004, 0
	givemon SPECIES_CHARMANDER, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route24_EventScript_CharmanderParty
	goto_if_eq VAR_RESULT, 1, Route24_EventScript_CharmanderPC
	goto_if_eq VAR_RESULT, 2, Route24_EventScript_NoRoomForCharmander
	end

Route24_EventScript_CharmanderGuyLucky::
	setvar VAR_0x8004, 0
    setflag FLAG_SHINY_CREATION
	givemon SPECIES_CHARMANDER, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route24_EventScript_CharmanderParty
	goto_if_eq VAR_RESULT, 1, Route24_EventScript_CharmanderPC
	goto_if_eq VAR_RESULT, 2, Route24_EventScript_NoRoomForCharmander
	end

Route24_EventScript_HowsCharmander::
	msgbox Route24_Text_HowsCharmander, MSGBOX_NPC
	release
	end

Route24_Text_HowsCharmander::
	.string "Como o Charmander está se saindo?$"

Route24_Text_NotCutOutToBeATrainer::
	.string "Eu não levo jeito para criar Pokémon.\p"
	.string "Eu devia libertar meu Charmander,\n"
	.string "já que não cuidei bem dele...\p"
	.string "Se me prometer que vai cuidar\n"
	.string "muito bem dele, ele é seu.$"

Route24_EventScript_BetterReleaseIt::
	msgbox Route24_Text_BetterReleaseIt, MSGBOX_NPC
	release
	end

Route24_Text_BetterReleaseIt::
	.string "Ah... Então é melhor eu libertá-lo...$"


Route24_EventScript_CharmanderParty::
	call Route24_EventScript_GetCharmander
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route24_EventScript_GotCharmander
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route24_EventScript_GotCharmander
	end

Route24_EventScript_GetCharmander::
	playfanfare MUS_LEVEL_UP
	message Route24_EventScript_Text_TakeCareOfCharmander
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	return

Route24_EventScript_Text_TakeCareOfCharmander::
	.string "{PLAYER} prometeu cuidar muito bem\n"
	.string "do Charmander do treinador!$"

Route24_EventScript_GotCharmander::
	setflag FLAG_GOT_CHARMANDER
	removeobject LOCALID_CHARMANDER
	release
	end

Route24_EventScript_CharmanderPC::
	call Route24_EventScript_GetCharmander
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route24_EventScript_TransferCharmander
	call Common_EventScript_NameReceivedBoxMon
	goto Route24_EventScript_TransferCharmander
	end

Route24_EventScript_TransferCharmander::
	call Common_EventScript_TransferredToPC
	goto Route24_EventScript_GotCharmander
	end

Route24_EventScript_NoRoomForCharmander::
	msgbox Route24_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

Route24_Text_NoRoomForMorePokemon::
    .string "Ah! Você não tem espaço\n"
    .string "para mais Pokémon!$"

@Rocket Scene

Route24_EventScript_RocketTriggerLeft::
	lock
	applymovement LOCALID_DISGUISED_ROCKET, Movement_StopPlayerLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	waitmovement 8
	msgbox Route24_Text_GetYourReward, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CenterPlayerLeft
	waitmovement 0
	turnobject LOCALID_DISGUISED_ROCKET, DIR_SOUTH
	goto Route24_EventScript_DisguisedRocket
	end

Movement_StopPlayerLeft:
	face_left
	emote_question_mark
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	delay_16
	step_end

Movement_CenterPlayerLeft:
	walk_down
	walk_right
	face_up
	step_end

Route24_EventScript_RocketTriggerRight::
	lock
	applymovement LOCALID_DISGUISED_ROCKET, Movement_StopPlayerRight
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 8
	msgbox Route24_Text_GetYourReward, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CenterPlayerRight
	waitmovement 0
	turnobject LOCALID_DISGUISED_ROCKET, DIR_SOUTH
	goto Route24_EventScript_DisguisedRocket
	end

Movement_StopPlayerRight:
	face_right
	emote_question_mark
	delay_16
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

Movement_CenterPlayerRight:
	walk_down
	walk_left
	face_up
	step_end

Route24_Text_GetYourReward:
	.string "Com licença!\n"
	.string "Não quer a sua recompensa?$"

Route24_EventScript_DisguisedRocket::
	lock
	msgbox Route24_Text_JustEarnedFabulousPrize, MSGBOX_DEFAULT
	checkitemspace ITEM_NUGGET, 1
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route24_Text_ReceivedNuggetFromMysteryTrainer, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_NUGGET, 1
	applymovement LOCALID_DISGUISED_ROCKET, Movement_LookSuspicious
	msgbox Route24_Text_SecretPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route24_EventScript_SecretPrize
	msgbox Route24_Text_WasntReallyAQuestion, MSGBOX_DEFAULT
	removeobject LOCALID_ROCKET
	setobjectxyperm LOCALID_ROCKET, 11, 15
	clearflag FLAG_HIDE_ROUTE24_ROCKET
	applymovement LOCALID_DISGUISED_ROCKET, Movement_RocketReveal
	playse SE_EXIT
	waitse
	addobject LOCALID_ROCKET
	removeobject LOCALID_DISGUISED_ROCKET
	goto Route24_EventScript_DisguisedRocketBattle
	end

Route24_Text_JustEarnedFabulousPrize::
    .string "Parabéns! Você derrotou nossos\n"
    .string "cinco Treinadores do desafio!\p"
    .string "Você acabou de ganhar um prêmio fabuloso!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
    .string "{PLAYER} recebeu uma Pepita\n"
    .string "do Treinador misterioso!$"

Route24_Text_SecretPrize::
	.string "Sabe, garoto, eu nunca vi\n"
	.string "ninguém batalhar assim antes...\p"
	.string "Acho que você se qualificou para\n"
	.string "o Prêmio Secreto!\p"
	.string "E aí, o que me diz?...\n"
	.string "Gostaria do Prêmio Secreto?$"

Movement_LookSuspicious:
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end

Route24_Text_WasntReallyAQuestion::
	.string "Talvez eu não tenha sido muito claro.\p"
	.string "Não era bem uma pergunta.\p"
	.string "Veja bem, a Ponte Pepita é financiada\n"
	.string "por ninguém menos que a Equipe Rocket!$"

Movement_RocketReveal::
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	step_end

Route24_EventScript_DisguisedRocketBattle::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketGruntIntro, Route24_Text_RocketGruntDefeat, Route24_EventScript_DisguisedRocketDefeated
	end

Route24_Text_RocketGruntIntro:
	.string "Somos um grupo de criminosos\n"
    .string "profissionais especialistas em Pokémon!\p"
    .string "Um treinador forte como você, bem,\n"
    .string "meus chefes ficariam furiosos se\l"
    .string "eu perdesse a chance de recrutar!\p"
    .string "Esse é o prêmio secreto: entrar para\n"
    .string "a única e incomparável Equipe Rocket!\p"
    .string "…Certo, você precisa ser convencido!\p"
    .string "Vou fazer uma oferta irrecusável!$"

Route24_Text_RocketGruntDefeat::
    .string "Arrgh!\n"
    .string "Você é bom mesmo!$"

Route24_EventScript_DisguisedRocketDefeated::
	msgbox Route24_Text_BossesAreGonnaKillMe, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Movement_RocketBails
	waitmovement 11
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	setvar VAR_CERULEAN_CITY_ROCKETS, 1
	fadenewbgm MUS_ENCOUNTER_CHAMPION
	goto Route24_EventScript_LookerConclusion
	end

Route24_Text_BossesAreGonnaKillMe::
	.string "Meus chefes vão me matar!\n"
	.string "Tenho que dar o fora!$"

Route24_EventScript_SecretPrize::
	applymovement LOCALID_DISGUISED_ROCKET, Common_Movement_ExclamationMark
	msgbox Route24_Text_OhWowThatsGreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DISGUISED_ROCKET, Movement_GetJessieJames
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	waitmovement 9
	removeobject LOCALID_DISGUISED_ROCKET
	delay 10
	fadescreen FADE_FROM_BLACK
	fadenewbgm MUS_RG_ENCOUNTER_ROCKET
	applymovement LOCALID_ROCKET, Movement_RocketApproach
	applymovement LOCALID_JESSIE, Movement_JessieJamesEnter
	applymovement LOCALID_JAMES, Movement_JessieJamesEnter
	waitmovement 11
	msgbox Route24_Text_ThisIsTheKid, MSGBOX_DEFAULT
	applymovement LOCALID_JESSIE, Movement_JessieAction
	applymovement LOCALID_JAMES, Movement_JamesAction
	waitmovement 9
	msgbox Route24_Text_YouFool, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitmovement 11
	msgbox Route24_Text_YourProblemNow, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Movement_RocketBails
	closemessage
	waitmovement 11
	removeobject LOCALID_ROCKET
	applymovement LOCALID_JESSIE, Movement_JessieApproach
	applymovement LOCALID_JAMES, Movement_JamesApproach
	waitmovement 9
	goto Route24_EventScript_BattleJessieJames
	end

Movement_RocketApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_JessieJamesEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_Text_ThisIsTheKid::
	.string "Jessie, James, este é o moleque\n"
	.string "de quem eu estava falando!\p"
	.string "Ele ganhou o Prêmio Secreto.\p"
    .string "Com a força que tem, viraria\n"
    .string "um dos líderes da Equipe Rocket.\p"
    .string "Tenho certeza disso!\p"
    .string "E então, o que me dizem?\n"
    .string "Devemos deixar ele entrar?$"

Route24_Text_OhWowThatsGreat::
	.string "Nossa! Sério?\p"
	.string "Geralmente é preciso insistir\n"
	.string "um pouco mais...\p"
	.string "Que ótimo! Deixe-me chamar meus\n"
	.string "chefes e vamos preparar o seu\l"
	.string "Prêmio Secreto!$"

Movement_GetJessieJames::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_JessieAction:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	delay_16
	step_end

Movement_JamesAction:
	delay_16
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Movement_RocketBails:
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_JessieApproach:
	walk_down
	face_right
	emote_exclamation_mark
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

Movement_JamesApproach:
	delay_16
	delay_16
	walk_down
	face_left
	emote_exclamation_mark
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route24_Text_YouFool:
	.string "Jessie: Seu tolo!\p"
	.string "James: Seu imbecil!\p"
	.string "Jessie: Este é o pirralho que\n"
	.string "arruinou nossos planos no Monte Lua!\p"
	.string "James: Ele provavelmente guiou a\n"
	.string "Polícia Internacional direto a nós!$"

Route24_Text_YourProblemNow:
	.string "Rocket: Eita!\p"
	.string "Bem... hum... isso quer dizer que\n"
	.string "vocês dois querem uma revanche, né?\p"
	.string "É isso! Hum, vou avisar os outros!$"

Route24_EventScript_BattleJessieJames::
	trainerbattle_double TRAINER_ROCKET_DUO_NB, Route24_Text_RocketDuoIntro, Route24_Text_RocketDuoDefeat, Text_NeedTwoMons, Route24_EventScript_RocketDuoDefeated, NO_MUSIC
	end

Route24_Text_RocketDuoIntro:
	.string "Jessie: Por nos derrotar no\n"
	.string "Monte Lua...\p"
	.string "James: Faremos você parecer\n"
	.string "uma gazua!\p"
	.string "Jessie: Prepare-se para a encrenca!\n"
	.string "James: Encrenca em dobro!$"

Route24_Text_RocketDuoDefeat:
	.string "Pirralho! Como você pôde fazer\n"
	.string "isso com a gente de novo?!$"

Route24_EventScript_RocketDuoDefeated::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox Route24_Text_WontBeTheLastTime, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	closemessage
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	setvar VAR_CERULEAN_CITY_ROCKETS, 1
	fadenewbgm MUS_ENCOUNTER_CHAMPION
	fadescreen FADE_FROM_BLACK
	goto Route24_EventScript_LookerConclusion

Route24_Text_WontBeTheLastTime::
	.string "Esta não será a última vez que\n"
	.string "você enfrentará a Equipe Rocket!\p"
	.string "Então agradeça por termos deixado\n"
	.string "você escapar tão fácil!$"

Route24_EventScript_LookerConclusion::
	closemessage
	clearflag FLAG_HIDE_ROUTE24_LOOKER
	addobject LOCALID_LOOKER
	setobjectxyperm LOCALID_ROCKET, 11,9
	clearflag FLAG_HIDE_ROUTE24_ROCKET
	addobject LOCALID_ROCKET
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToLooker
	waitmovement 0
	message Route25_Text_ComingWithUs
	waitmessage
	delay 10
	closemessage
	applymovement LOCALID_LOOKER, Movement_LookerCaughtRocket
	applymovement LOCALID_ROCKET, Movement_RocketGotCaught
	waitmovement 12
	removeobject LOCALID_LOOKER
	removeobject LOCALID_ROCKET
	fadedefaultbgm
	releaseall
	end

Route25_Text_ComingWithUs::
	.string "Looker: Nada disso.\n"
	.string "Você vem com a gente.\p"
	.string "Mal posso esperar para ouvir mais\n"
	.string "sobre esse tal Prêmio Secreto...$"

Movement_MoveToLooker::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	emote_exclamation_mark
	step_end

Movement_LookerCaughtRocket::
	delay_16
	delay_16
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_RocketGotCaught::
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	delay_16
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route24_Text_YouDontHaveAnyRoom::
    .string "Você não tem espaço!\p"
    .string "Meu chefe me mataria se eu não\n"
    .string "lhe entregasse o seu prêmio,\l"
    .string "então volte quando tiver espaço!$"

Route24_EventScript_ItemTM45::
	finditem ITEM_TM45, 1
	end

Route24_EventScript_Shane::
	trainerbattle_single REMATCHABLE_TRAINER_CAMPER_SHANE_1, Route24_Text_ShaneIntro, Route24_Text_ShaneDefeat, Route24_EventScript_RegisterShaneAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route24_EventScript_ShaneRematch
	msgbox Route24_Text_ShanePostBattle, MSGBOX_DEFAULT
	release
	end

Route24_Text_ShaneIntro::
    .string "Eu estava assistindo às suas batalhas\n"
    .string "na Ponte Pepita daqui de longe!$"

Route24_Text_ShaneDefeat::
    .string "Como imaginei!$"

Route24_Text_ShanePostBattle::
    .string "Eu me escondi porque o pessoal\n"
    .string "da ponte me dava medo.$"

Route24_EventScript_RegisterShaneAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route24_Text_ShaneRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_CAMPER_SHANE_1
	release
	end

Route24_Text_ShaneRegister:
	.string "Uau! Você é forte!\p"
	.string "Se você fosse meu amigo, eu não\n"
	.string "precisaria ter medo de nada!$"

Route24_EventScript_ShaneRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_CAMPER_SHANE_1, Route24_Text_ShaneRematchIntro, Route24_Text_ShaneDefeat
	msgbox Route24_Text_ShaneRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route24_Text_ShaneRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Me ensine a ser forte como você!$"

Route24_Text_ShaneRematchPostBattle::
	.string "Vou continuar assistindo você\n"
	.string "daqui de longe!$"


@Normal Nugget Bridge Trainers
Movement_NuggetBridgeTrainerExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_EventScript_Cale::
	trainerbattle_single TRAINER_BUG_CATCHER_CALE, Route24_Text_CaleIntro, Route24_Text_CaleDefeat, Route24_EventScript_CalePostBattle
	end

Route24_EventScript_CalePostBattle::
	msgbox Route24_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_CALE, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 1
	removeobject LOCALID_CALE
	end

Route24_Text_CaleIntro::
    .string "As pessoas chamam esta ponte de\n"
    .string "Ponte Pepita!\p"
    .string "Derrote nós cinco Treinadores e vença\n"
    .string "um prêmio fabuloso!\p"
    .string "Acha que dá conta do recado?$"

Route24_Text_CaleDefeat::
    .string "Uau!\n"
    .string "Mandou muito bem!$"

Route24_Text_CalePostBattle::
    .string "Dei o meu melhor. Não me arrependo!$"

Route24_EventScript_Ali::
	trainerbattle_single TRAINER_LASS_ALI, Route24_Text_AliIntro, Route24_Text_AliDefeat, Route24_EventScript_AliPostBattle
	
Route24_EventScript_AliPostBattle::
	msgbox Route24_Text_AliPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ALI, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 2
	removeobject LOCALID_ALI
	end

Route24_Text_AliIntro::
    .string "Eu sou a número 2!\n"
    .string "Agora a coisa ficou séria!$"

Route24_Text_AliDefeat::
    .string "Como eu pude perder?$"

Route24_Text_AliPostBattle::
    .string "Dei o meu melhor. Não me arrependo!$"

Route24_EventScript_Timmy::
	trainerbattle_single TRAINER_YOUNGSTER_TIMMY, Route24_Text_TimmyIntro, Route24_Text_TimmyDefeat, Route24_EventSript_TimmyPostBattle
	end

Route24_EventSript_TimmyPostBattle::
	msgbox Route24_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_TIMMY, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 3
	removeobject LOCALID_TIMMY
	end

Route24_Text_TimmyIntro::
    .string "Aqui vem o número 3!\n"
    .string "Eu não serei fácil!$"

Route24_Text_TimmyDefeat::
    .string "Ai!\n"
    .string "Fui esmagado!$"

Route24_Text_TimmyPostBattle::
    .string "Dei o meu melhor. Não me arrependo!$"

Route24_EventScript_Reli::
	trainerbattle_single TRAINER_LASS_RELI, Route24_Text_ReliIntro, Route24_Text_ReliDefeat, Route24_EventScript_ReliPostBattle
	end

Route24_EventScript_ReliPostBattle::
	msgbox Route24_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_RELI, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 4
	removeobject LOCALID_RELI
	end

Route24_Text_ReliIntro::
    .string "Eu sou a número 4!\n"
    .string "Já está cansando?$"

Route24_Text_ReliDefeat::
    .string "Eu perdi também!$"

Route24_Text_ReliPostBattle::
    .string "Dei o meu melhor, não me arrependo!$"

Route24_EventScript_Ethan::
	trainerbattle_single TRAINER_CAMPER_ETHAN, Route24_Text_EthanIntro, Route24_Text_EthanDefeat, Route24_EventScript_EthanPostBattle
	end

Route24_EventScript_EthanPostBattle::
	msgbox Route24_Text_EthanPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ETHAN, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 5
	removeobject LOCALID_ETHAN
	end

Route24_Text_EthanIntro::
    .string "Muito bem! Eu sou o número 5!\n"
    .string "Vou acabar com você!$"

Route24_Text_EthanDefeat::
    .string "Uau!\n"
    .string "Forte demais!$"

Route24_Text_EthanPostBattle::
    .string "Dei o meu melhor. Não me arrependo!$"

@TODO: Postgame Nugget Bridge

