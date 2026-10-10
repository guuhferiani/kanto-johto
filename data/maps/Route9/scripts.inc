Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route9_OnResume
	.byte 0

Route9_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route9_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route9_EventScript_Alicia::
	trainerbattle_single REMATCHABLE_TRAINER_PICNICKER_ALICIA_1, Route9_Text_AliciaIntro, Route9_Text_AliciaDefeat, Route9_EventScript_RegisterAliciaAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route9_EventScript_AliciaRematch
	msgbox Route9_Text_AliciaPostBattle, MSGBOX_DEFAULT
	release
	end

Route9_Text_AliciaIntro::
    .string "Você tem Pokémon com você!\n"
    .string "Você é meu!$"

Route9_Text_AliciaDefeat::
    .string "Você me enganou…$"

Route9_Text_AliciaPostBattle::
    .string "O túnel logo adiante é um breu total\n"
    .string "lá dentro.\p"
    .string "Você vai precisar do Flash para passar\n"
    .string "por lá.$"

Route9_EventScript_RegisterAliciaAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route9_Text_AliciaRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_PICNICKER_ALICIA_1
	release
	end

Route9_Text_AliciaRegister:
	.string "Foi maldade me enganar, mas eu te\n"
	.string "perdoo se me der o número do seu\l"
	.string "Celular.$"

Route9_EventScript_AliciaRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_PICNICKER_ALICIA_1, Route9_Text_AliciaRematchIntro, Route9_Text_AliciaDefeat
	msgbox Route9_Text_AliciaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_AliciaRematchIntro::
	.string "Vamos batalhar de novo?\n"
	.string "Desta vez você é meu!$"

Route9_Text_AliciaRematchPostBattle::
	.string "Você me enganou de novo!$"


Route9_EventScript_Brent::
	trainerbattle_single TRAINER_BUG_CATCHER_BRENT, Route9_Text_BrentIntro, Route9_Text_BrentDefeat
	msgbox Route9_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_BrentIntro::
    .string "Acordei cedo todo dia para criar\n"
    .string "meus Pokémon desde os casulos!$"

Route9_Text_BrentDefeat::
    .string "O QUÊ?\p"
    .string "Que perda de tempo total!$"

Route9_Text_BrentPostBattle::
    .string "Preciso colecionar mais do que insetos\n"
    .string "para ficar mais forte…$"

Route9_EventScript_Conner::
    trainerbattle_single TRAINER_BUG_CATCHER_CONNER, Route9_Text_ConnerIntro, Route9_Text_ConnerDefeat
    msgbox Route9_Text_ConnerPostBattle, MSGBOX_AUTOCLOSE
    end
    
Route9_Text_ConnerIntro::
    .string "Vão, meus super Pokémon inseto!$"

Route9_Text_ConnerDefeat::
    .string "Meus insetos…$"

Route9_Text_ConnerPostBattle::
    .string "Se você não gosta de Pokémon inseto,\n"
    .string "você me irrita!$"

Route9_EventScript_Chris::
    trainerbattle_single TRAINER_CAMPER_CHRIS, Route9_Text_ChrisIntro, Route9_Text_ChrisDefeat
    msgbox Route9_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_ChrisIntro::
    .string "Quem é que vem andando ali com esses\n"
    .string "Pokémon bonitões?$"

Route9_Text_ChrisDefeat::
    .string "Apagou feito uma lâmpada!$"

Route9_Text_ChrisPostBattle::
    .string "Continue andando!$"

Route9_EventScript_Drew::
    trainerbattle_single TRAINER_CAMPER_DREW, Route9_Text_DrewIntro, Route9_Text_DrewDefeat
    msgbox Route9_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_DrewIntro::
    .string "Estou pegando o Túnel de Rocha para\n"
    .string "ir a Lavender…$"

Route9_Text_DrewDefeat::
    .string "Não dou conta…$"

Route9_Text_DrewPostBattle::
    .string "Você também está indo ao Túnel de Rocha?$"

Route9_EventScript_Caitlin::
    trainerbattle_single TRAINER_PICNICKER_CAITLIN, Route9_Text_CaitlinIntro, Route9_Text_CaitlinDefeat
    msgbox Route9_Text_CaitlinPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_CaitlinIntro::
    .string "Nem ouse me subestimar!$"

Route9_Text_CaitlinDefeat::
    .string "Não!\n"
    .string "Você é demais.$"

Route9_Text_CaitlinPostBattle::
    .string "Você tem muito talento, com certeza.\n"
    .string "Boa sorte para você!$"

Route9_EventScript_Alan::
    trainerbattle_single TRAINER_HIKER_ALAN, Route9_Text_AlanIntro, Route9_Text_AlanDefeat
    msgbox Route9_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_AlanIntro::
    .string "Hahahaha!\n"
    .string "Pode vir com tudo!$"

Route9_Text_AlanDefeat::
    .string "Hahahaha!\n"
    .string "Você me venceu na lealdade!$"

Route9_Text_AlanPostBattle::
    .string "Hahahaha!\n"
    .string "Nós, brutamontes, sempre rimos!$"

Route9_EventScript_Brice::
    trainerbattle_single TRAINER_HIKER_BRICE, Route9_Text_BriceIntro, Route9_Text_BriceDefeat
    msgbox Route9_Text_BricePostBattle, MSGBOX_AUTOCLOSE
    end
    
Route9_Text_BriceIntro::
    .string "Hahaha!\n"
    .string "Mas que sujeito durão você é!$"

Route9_Text_BriceDefeat::
    .string "O que foi isso?$"

Route9_Text_BricePostBattle::
    .string "Hahaha!\n"
    .string "Crianças têm que ser fortes mesmo!$"

Route9_EventScript_Jeremy::
    trainerbattle_single TRAINER_HIKER_JEREMY, Route9_Text_JeremyIntro, Route9_Text_JeremyDefeat
    msgbox Route9_Text_JeremyPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_JeremyIntro::
    .string "Bwahaha!\n"
    .string "Ótimo! Eu estava entediado, uai!$"

Route9_Text_JeremyDefeat::
    .string "Manda mais, uai!\p"
    .string "Opa, peraí.\n"
    .string "Acabaram os meus Pokémon!$"

Route9_Text_JeremyPostBattle::
    .string "Você teve muita coragem de me peitar\n"
    .string "ali, hein?$"

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_Text_RouteSign::
    .string "Rota 9\n"
    .string "Cidade de Cerulean - Túnel de Rocha$"

Route9_EventScript_ItemBurnHeal::
	finditem ITEM_BURN_HEAL, 1
	release
	end

Route9_EventScript_ItemTM40::
    finditem ITEM_TM40, 1
    release
    end
