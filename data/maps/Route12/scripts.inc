.set LOCALID_FUGITIVE, 16

Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route12_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	call Common_EventScript_GetDayOrNight
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_Text_RouteSign::
    .string "Rota 12\n"
    .string "Norte para Lavender$"

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_SportfishingArea::
    .string "Área de Pesca Esportiva$"

@Snorlax
Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
    checkitem ITEM_POKE_FLUTE
    goto_if_eq VAR_RESULT, FALSE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call Common_EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED,Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_Text_MonSprawledOutInSlumber::
    .string "Um Pokémon está estirado em um sono\n"
    .string "profundo e confortável.$"

Text_PlayedPokeFlute::
    .string "{PLAYER} tocou a Poké Flauta.$"

@Trainers
Route12_EventScript_Ned::
	trainerbattle_single REMATCHABLE_TRAINER_FISHERMAN_NED_1, Route12_Text_NedIntro, Route12_Text_NedDefeat, Route12_EventScript_RegisterNedAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_NedRematch
	msgbox Route12_Text_NedPostBattle, MSGBOX_DEFAULT
	release
	end

Route12_Text_NedIntro::
    .string "Isso aí!\n"
    .string "Fisguei um aqui!$"

Route12_Text_NedDefeat::
    .string "Tsc!\n"
    .string "Só um peixinho miúdo…$"

Route12_Text_NedPostBattle::
    .string "Aguenta aí!\n"
    .string "Minha linha enroscou!$"

Route12_EventScript_RegisterNedAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_NedRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_FISHERMAN_NED_1
	release
	end

Route12_Text_NedRegister:
	.string "Me dê uma ligada se você quiser ir pescar\n"
	.string "algum dia.$"

Route12_EventScript_NedRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_FISHERMAN_NED_1, Route12_Text_NedRematchIntro, Route12_Text_NedDefeat
	msgbox Route12_Text_NedRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Text_NedRematchIntro::
	.string "Uau!\n"
	.string "Esse aqui vai ser dos grandes!$"

Route12_Text_NedRematchPostBattle::
	.string "Só mais um Magikarp.$"

Route12_EventScript_Luca::
    trainerbattle_single REMATCHABLE_TRAINER_ROCKER_LUCA_1, Route12_Text_LucaIntro, Route12_Text_LucaDefeat, Route12_EventScript_RegisterLucaAfterBattle
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_LucaRematch
    msgbox Route12_Text_LucaPostBattle, MSGBOX_DEFAULT
    release
    end

Route12_Text_LucaIntro::
    .string "Eletricidade é a minha especialidade.\p"
    .string "Mas eu não entendo nada de Pokémon\n"
    .string "do mar.$"

Route12_Text_LucaDefeat::
    .string "Desconectado!$"

Route12_Text_LucaPostBattle::
    .string "A água conduz eletricidade, então você\n"
    .string "deve dar um choque nos Pokémon do mar.$"

Route12_EventScript_RegisterLucaAfterBattle::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox Route12_Text_LucaRegister, MSGBOX_DEFAULT
    register_matchcall REMATCHABLE_TRAINER_ROCKER_LUCA_1
    release
    end

Route12_Text_LucaRegister:
    .string "Depois que eu recarregar, vamos ter\n"
    .string "uma revanche.$"

Route12_EventScript_LucaRematch::
    trainerbattle_rematch REMATCHABLE_TRAINER_ROCKER_LUCA_1, Route12_Text_LucaRematchIntro, Route12_Text_LucaDefeat
    msgbox Route12_Text_LucaRematchPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_LucaRematchIntro::
    .string "Eu ainda não entendo nada sobre\n"
    .string "Pokémon do mar.$"

Route12_Text_LucaRematchPostBattle::
    .string "Eletrocutado!$"

Route12_EventScript_Chip::
	trainerbattle_single TRAINER_FISHERMAN_CHIP, Route12_Text_ChipIntro, Route12_Text_ChipDefeat
	msgbox Route12_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Text_ChipIntro::
    .string "Tenha paciência.\n"
    .string "Pescar é um jogo de espera.$"

Route12_Text_ChipDefeat::
    .string "Aquele escapou!$"

Route12_Text_ChipPostBattle::
    .string "Com uma vara melhor, eu conseguiria\n"
    .string "pescar Pokémon melhores…$"

Route12_EventScript_Hank::
    trainerbattle_single TRAINER_FISHERMAN_HANK, Route12_Text_HankIntro, Route12_Text_HankDefeat
    msgbox Route12_Text_HankPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_HankIntro::
    .string "O maluco da pesca contra o prodígio\n"
    .string "Pokémon!$"

Route12_Text_HankDefeat::
    .string "Foi um pouco demais!$"

Route12_Text_HankPostBattle::
    .string "Acho que a gente fica bom naquilo\n"
    .string "que gosta.\p"
    .string "Bem, você me venceu no Pokémon,\n"
    .string "mas não me supera na pescaria.$"

Route12_EventScript_Elliot::
    trainerbattle_single TRAINER_FISHERMAN_ELLIOT, Route12_Text_ElliotIntro, Route12_Text_ElliotDefeat
    msgbox Route12_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
    end
    
Route12_Text_ElliotIntro::
    .string "Eu amo pescar, não me entenda mal.\p"
    .string "Mas seria melhor se eu também tivesse\n"
    .string "mais trabalho.$"

Route12_Text_ElliotDefeat::
    .string "Não é fácil…$"

Route12_Text_ElliotPostBattle::
    .string "Tudo bem.\n"
    .string "Perder não me incomoda mais.$"

Route12_EventScript_Jes::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_JesIntro, Route12_Text_JesDefeat, Route12_Text_JesNotEnoughMons
    msgbox Route12_Text_JesPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_JesIntro::
    .string "Jes: Se eu vencer, vou pedir a Gia\n"
    .string "em casamento.$"

Route12_Text_JesDefeat::
    .string "Jes: Ah, por favor, por que você não\n"
    .string "podia nos deixar vencer?$"

Route12_Text_JesPostBattle::
    .string "Jes: Ah, Gia, me perdoe,\n"
    .string "meu amor!$"

Route12_Text_JesNotEnoughMons::
    .string "Jes: A Gia e eu ficaremos\n"
    .string "juntos para sempre.\p"
    .string "Só batalhamos se você tiver\n"
    .string "dois Pokémon.$"

Route12_EventScript_Gia::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaIntro, Route12_Text_GiaDefeat, Route12_Text_GiaNotEnoughMons
    msgbox Route12_Text_GiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_GiaIntro::
    .string "Gia: Ei, Jes…\p"
    .string "Se nós vencermos, eu me caso com você!$"

Route12_Text_GiaDefeat::
    .string "Gia: Ah, mas por quê?$"

Route12_Text_GiaPostBattle::
    .string "Gia: Jes, seu bobo!\n"
    .string "Você arruinou tudo!$"

Route12_Text_GiaNotEnoughMons::
    .string "Gia: Eu não consigo batalhar\n"
    .string "sem o meu Jes!\p"
    .string "Você não tem mais um Pokémon?$"

Route12_EventScript_Justin::
    trainerbattle_single TRAINER_CAMPER_JUSTIN, Route12_Text_JustinIntro, Route12_Text_JustinDefeat
    msgbox Route12_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_JustinIntro::
    .string "Estou procurando uma Pedra da Lua.\n"
    .string "Você encontrou alguma?$"

Route12_Text_JustinDefeat::
    .string "Ai, ai!$"

Route12_Text_JustinPostBattle::
    .string "Eu poderia ter feito meu Pokémon\n"
    .string "evoluir com uma Pedra da Lua.\p"
    .string "Aposto que eu teria vencido então.$"

Route12_EventScript_Andrew::
    trainerbattle_single TRAINER_FISHERMAN_ANDREW, Route12_Text_AndrewIntro, Route12_Text_AndrewDefeat
    msgbox Route12_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_AndrewIntro::
    .string "O que está fisgando?\p"
    .string "Nunca se sabe o que pode\n"
    .string "pescar!$"

Route12_Text_AndrewDefeat::
    .string "Perdi a fisgada!$"

Route12_Text_AndrewPostBattle::
    .string "O quê, Magikarp?\p"
    .string "Eu pesco eles o tempo todo, claro.\n"
    .string "Mas nossa, como são molengas.$"

Route12_EventScript_ItemIron::
    finditem ITEM_IRON, 1
    release
    end

Route12_EventScript_ItemTM48::
    finditem ITEM_TM48, 1
    release
    end

Route12_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

Route12_EventScript_Dennis::
	lock
	faceplayer
    playmoncry SPECIES_MAGIKARP, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_LARRY, Route12_EventScript_DennisDefeated
	msgbox Route12_Text_Dennis MSGBOX_DEFAULT
	release
	end

Route12_Text_Dennis:
	.string "DENNIS: KAAAARP!\p"
	.string "… você sente um arrepio, como se estivesse\n"
	.string "olhando para a própria morte.$"

Route12_EventScript_FishermanLarry::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LARRY, Route12_EventScript_MegaHintGyarados
	trainerbattle_single TRAINER_FISHERMAN_LARRY, Route12_Text_LarryIntro, Route12_Text_LarryDefeat
	setflag FLAG_DEFEATED_LARRY
	msgbox Route12_Text_LarryPostBattle MSGBOX_AUTOCLOSE
	release
	end

Route12_Text_LarryIntro:
	.string "Como vai, jovem?\n"
    .string "Você parece um Treinador capaz.\p"
	.string "Os peixes não estão mordendo no\n"
    .string "momento, então mostre-me o que você tem!$"

Route12_Text_LarryDefeat:
	.string "Isso foi divertido!$"

Route12_Text_LarryPostBattle:
	.string "Dennis, isso foi emocionante!$"

Route12_EventScript_MegaHintGyarados::    
    goto_if_set FLAG_GOT_GYARADOSITE, Route12_Text_LarryDefeated
    msgbox Route12_Text_GyaradosMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
Route12_Text_GyaradosMegaHint:
    .string "Se não se importar com a viagem, as\n"
    .string "Ilhas Espuma são lindas nesta época\l"
    .string "do ano.$"

Route12_Text_LarryDefeated::
    msgbox LarryDefeated_Text MSGBOX_DEFAULT
	release
	end

LarryDefeated_Text:	
	.string "Dennis deve gostar de você. Ele…\p"
	.string "Bem. Digamos apenas que eu não saio\n"
    .string "de casa sem muitos Reviver Máximo\l"
    .string "para meus oponentes.$"

Route12_EventScript_DennisDefeated::
	msgbox DennisDefeated MSGBOX_DEFAULT
	release
	end

DennisDefeated:	
	.string "DENNIS: KARP!\p"
	.string "… uma sensação calorosa te invade\n"
	.string "e você se curva em gratidão por ter\l"
    .string "sido poupado por este deus.$"
