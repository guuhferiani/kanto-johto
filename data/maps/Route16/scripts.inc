Route16_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnTransition:
	call_if_eq VAR_CYCLING_ROAD, 1, Route16_OnTransitionCyclingRoad
	call Common_EventScript_GetDayOrNight
	end

Route16_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_TryRemoveSnorlax
	call Common_EventScript_GetDayOrNight
	end

Route16_OnWarp::
	map_script_2 VAR_CYCLING_ROAD, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_CYCLING_ROAD
	return

@Snorlax
Route16_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
    checkitem ITEM_POKE_FLUTE
    goto_if_eq VAR_RESULT, FALSE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call Common_EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_16_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED,Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_Text_MonSprawledOutInSlumber::
    .string "Um Pokémon está estirado em um\n"
    .string "sono profundo e confortável.$"

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_CyclingRoadSign::
    .string "Aproveite a ladeira!\n"
    .string "Rodovia dos Ciclistas$"

Route16_Text_RouteSign::
    .string "Rota 16\n"
    .string "Celadon - Fuchsia$"

Route16_EventScript_Hideo::
	trainerbattle_single REMATCHABLE_TRAINER_BIKER_HIDEO_1, Route16_Text_HideoIntro, Route16_Text_HideoDefeat, Route16_EventScript_RegisterHideoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route16_EventScript_HideoRematch
	msgbox Route16_Text_HideoPostBattle, MSGBOX_DEFAULT
	release
	end

Route16_Text_HideoIntro::
    .string "Ei, você esbarrou em mim!$"

Route16_Text_HideoDefeat::
    .string "Kabum!$"

Route16_Text_HideoPostBattle::
    .string "Nós sempre estaremos por aqui,\n"
    .string "mesmo que você não goste disso.\p"
    .string "Você pode pegar um desvio para Vermilion\n"
    .string "a partir de Fuchsia seguindo pela costa.$"

Route16_EventScript_RegisterHideoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_HideoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BIKER_HIDEO_1
	release
	end

Route16_Text_HideoRegister:
	.string "Ei, já que você bateu na minha bike,\n"
	.string "vai ter que me compensar.\p"
	.string "Vou aceitar uma revanche como pagamento.$"

Route16_EventScript_HideoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BIKER_HIDEO_1, Route16_Text_HideoRematchIntro, Route16_Text_HideoDefeat
	msgbox Route16_Text_HideoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_HideoRematchIntro::
	.string "Fiz você esperar, não é?$"

Route16_Text_HideoRematchPostBattle::
	.string "Nunca é o fim da linha!$"


Route16_EventScript_Koji::
	trainerbattle_single REMATCHABLE_TRAINER_CUE_BALL_KOJI_1, Route16_Text_KojiIntro, Route16_Text_KojiDefeat, Route16_EventScript_RegisterKojiAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route16_EventScript_KojiRematch
	msgbox Route16_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route16_Text_KojiIntro::
    .string "Bela Bicicleta!\n"
    .string "Passe para cá!$"

Route16_Text_KojiDefeat::
    .string "Nocauteado!$"

Route16_Text_KojiPostBattle::
    .string "Esquece, quem precisa da sua bike!$"

Route16_EventScript_RegisterKojiAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_KojiRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_CUE_BALL_KOJI_1
	release
	end

Route16_Text_KojiRegister:
	.string "Se você não vai me dar a sua bike,\n"
	.string "vou ficar com o número do seu\l"
	.string "Celular então!$"

Route16_EventScript_KojiRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_CUE_BALL_KOJI_1, Route16_Text_KojiRematchIntro, Route16_Text_KojiDefeat
	msgbox Route16_Text_KojiRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_KojiRematchIntro::
	.string "Ei! Passe essa bike para cá…\n"
	.string "Ah, é você, {PLAYER}!$"

Route16_Text_KojiRematchPostBattle::
	.string "Eu nunca vou ter dinheiro para uma\n"
	.string "bike manera, então vou ter que pegar uma!$"

Route16_EventScript_Lao::
	trainerbattle_single TRAINER_BIKER_LAO, Route16_Text_LaoIntro, Route16_Text_LaoDefeat
	msgbox Route16_Text_LaoPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LaoIntro::
    .string "O que você quer?$"

Route16_Text_LaoDefeat::
    .string "Não ouse rir!$"

Route16_Text_LaoPostBattle::
    .string "A gente gosta de ficar por aqui.\n"
    .string "O que você tem a ver com isso?$"

Route16_EventScript_Ruben::
	trainerbattle_single TRAINER_BIKER_RUBEN, Route16_Text_RubenIntro, Route16_Text_RubenDefeat
	msgbox Route16_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_RubenIntro::
    .string "E aí, beleza!\n"
    .string "Vamos nos divertir um pouco!$"

Route16_Text_RubenDefeat::
    .string "Não me deixe com raiva!$"

Route16_Text_RubenPostBattle::
    .string "Eu me divirto incomodando as pessoas\n"
    .string "com meus Pokémon fedorentos.\p"
    .string "Eles são ótimos para assustar os outros.\n"
    .string "E eles mordem também.$"

Route16_EventScript_Luke::
	trainerbattle_single TRAINER_CUE_BALL_LUKE, Route16_Text_LukeIntro, Route16_Text_LukeDefeat
	msgbox Route16_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LukeIntro::
    .string "Venha brincar, seu ratinho!$"

Route16_Text_LukeDefeat::
    .string "Seu rato insignificante!$"

Route16_Text_LukePostBattle::
    .string "Eu odeio perder!\n"
    .string "Saia da minha frente!$"

Route16_EventScript_Camron::
	trainerbattle_single TRAINER_CUE_BALL_CAMRON, Route16_Text_CamronIntro, Route16_Text_CamronDefeat
	msgbox Route16_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_CamronIntro::
    .string "Estou com fome e com raiva!\n"
    .string "Preciso de um saco de pancadas!$"

Route16_Text_CamronDefeat::
    .string "Péssimo, péssimo, péssimo!$"

Route16_Text_CamronPostBattle::
    .string "Se é para ter Pokémon, que eles\n"
    .string "sejam ferozes.\p"
    .string "Eu os uso para deixar meus inimigos\n"
    .string "em pedaços.$"

Route16_EventScript_Jed::
	trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_JedIntro, Route16_Text_JedDefeat, Route16_Text_JedNotEnoughMons
	msgbox Route16_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_JedIntro::
    .string "Jed: Nosso amor não conhece limites.\n"
    .string "Estamos apaixonados e mostramos isso!$"

Route16_Text_JedDefeat::
    .string "Jed: Oh, não!\n"
    .string "Meu amor me viu perder!$"

Route16_Text_JedPostBattle::
    .string "Jed: Ouça, Lea.\n"
    .string "Você precisa focar menos em mim.$"

Route16_EventScript_Lea::
	trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaIntro, Route16_Text_LeaDefeat, Route16_Text_LeaNotEnoughMons
	msgbox Route16_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LeaIntro::
    .string "Lea: Às vezes, a intensidade do\n"
    .string "nosso amor me assusta.$"

Route16_Text_LeaDefeat::
    .string "Lea: Ahh! Mas o Jed continua incrível\n"
    .string "mesmo perdendo!$"

Route16_Text_LeaPostBattle::
    .string "Lea: Ehehe, desculpe.\n"
    .string "O Jed é tão incrível.$"

Route16_Text_JedNotEnoughMons::
    .string "Jed: Você só tem um Pokémon?\n"
    .string "Não há amor em seu coração?$"

Route16_Text_LeaNotEnoughMons::
    .string "Lea: Oh, você não tem dois\n"
    .string "Pokémon com você?\p"
    .string "Não se sente solitário para você\n"
    .string "ou para o seu Pokémon?$"


@TODO: Change based on if a new snorlax is here
Route16_EventScript_BerryMan::
	lock
	faceplayer
	msgbox Route16_Text_SnorlaxEatsBerries, MSGBOX_NPC
	release
	end

Route16_Text_SnorlaxEatsBerries:
	.string "Às vezes o Snorlax entra no nosso\n"
	.string "Bosque das Frutas e come toda a colheita!\p"
	.string "Depois disso, ele tira um longo cochilo.\p"
	.string "Nem mesmo o barulho da Rodovia dos\n"
	.string "Ciclistas consegue acordá-lo.$"







