.set LOCALID_FUGITIVE, 18

Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route10_OnResume
	.byte 0

Route10_OnTransition:
	setflag FLAG_VISITED_ROUTE_10
	call Common_EventScript_GetDayOrNight
	end

Route10_OnResume:
	call Common_EventScript_GetDayOrNight
	end


Route10_EventScript_NorthRockTunnelSign::
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end

Route10_Text_RockTunnelDetourToLavender::
    .string "Túnel de Rocha\n"
    .string "Desvio para o Vilarejo de Lavender$"

Route10_EventScript_SouthRockTunnelSign::
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end

Route10_Text_RockTunnel::
    .string "Túnel de Rocha$"

Route10_EventScript_PowerPlantSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_Text_PowerPlant::
    .string "Usina de Energia$"

Route10_EventScript_Mark::
	trainerbattle_single REMATCHABLE_TRAINER_POKEMANIAC_MARK_1, Route10_Text_MarkIntro, Route10_Text_MarkDefeat, Route10_EventScript_RegisterMarkAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route10_EventScript_MarkRematch
	msgbox Route10_Text_MarkPostBattle, MSGBOX_DEFAULT
	release
	end

Route10_Text_MarkIntro::
    .string "Nossa, você veio até aqui?\n"
    .string "Será que você também é um PokéManíaco?\l"
    .string "Quer ver a minha coleção?$"

Route10_Text_MarkDefeat::
    .string "Humph.\n"
    .string "Eu não estou bravo!$"

Route10_Text_MarkPostBattle::
    .string "Tenho Pokémon ainda mais raros em casa!$"

Route10_EventScript_RegisterMarkAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route10_Text_MarkRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_POKEMANIAC_MARK_1
	release
	end

Route10_Text_MarkRegister:
	.string "Se você me passar seu número,\n"
	.string "eu te mostro a minha coleção de\l"
	.string "Pokémon qualquer hora dessas.$"

Route10_EventScript_MarkRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_POKEMANIAC_MARK_1, Route10_Text_MarkRematchIntro, Route10_Text_MarkDefeat
	msgbox Route10_Text_MarkRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_MarkRematchIntro::
	.string "Meus Pokémon!\n"
	.string "Deixe-me mostrá-los a você!$"

Route10_Text_MarkRematchPostBattle::
	.string "Você é o verdadeiro PokéManíaco!$"


Route10_EventScript_Herman::
	trainerbattle_single TRAINER_POKEMANIAC_HERMAN, Route10_Text_HermanIntro, Route10_Text_HermanDefeat
	msgbox Route10_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_HermanIntro::
    .string "Oi, garoto!\n"
    .string "Quer ver meus Pokémon?$"

Route10_Text_HermanDefeat::
    .string "Oh, não!\n"
    .string "Meus Pokémon!$"

Route10_Text_HermanPostBattle::
    .string "Não gostei de você.\n"
    .string "Não gosto de ninguém melhor que eu!$"

Route10_EventScript_Heidi::
	trainerbattle_single TRAINER_PICNICKER_HEIDI, Route10_Text_HeidiIntro, Route10_Text_HeidiDefeat
	msgbox Route10_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_HeidiIntro::
    .string "Já fui a um Ginásio Pokémon\n"
    .string "algumas vezes.\p"
    .string "…Mas eu sempre perco.$"

Route10_Text_HeidiDefeat::
    .string "Aaah!\n"
    .string "Depois de todo o meu treino!$"

Route10_Text_HeidiPostBattle::
    .string "Notei alguns PokéManíacos rondando\n"
    .string "por aí.\p"
    .string "Dá para acreditar? Eles?\n"
    .string "Aqui em cima nas montanhas?$"

Route10_EventScript_Carol::
	trainerbattle_single TRAINER_PICNICKER_CAROL, Route10_Text_CarolIntro, Route10_Text_CarolDefeat
	msgbox Route10_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_CarolIntro::
    .string "Estou me sentindo meio tonta.\n"
    .string "Faz tempo que não faço trilha.$"

Route10_Text_CarolDefeat::
    .string "Estou muito cansada.\n"
    .string "Eu não estava no clima.$"

Route10_Text_CarolPostBattle::
    .string "Os Pokémon aqui nas montanhas\n"
    .string "são tão rechonchudos…\p"
    .string "Quem dera houvesse Pokémon cor-de-rosa\n"
    .string "com estampas florais!$"

Route10_EventScript_Clark::
	trainerbattle_single TRAINER_HIKER_CLARK, Route10_Text_ClarkIntro, Route10_Text_ClarkDefeat
	msgbox Route10_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_ClarkIntro::
    .string "Ha-hahah-ah-ha!$"

Route10_Text_ClarkDefeat::
    .string "Ha-haha!\n"
    .string "Não tô rindo!\l"
    .string "É al-alergia! Haha-ha-atchim!$"

Route10_Text_ClarkPostBattle::
    .string "Haha-ha-atchim!\n"
    .string "Ha-atchim!\l"
    .string "Fung! Snif!$"

Route10_EventScript_Trent::
	trainerbattle_single TRAINER_HIKER_TRENT, Route10_Text_TrentIntro, Route10_Text_TrentDefeat
	msgbox Route10_Text_TrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_TrentIntro::
    .string "Ah!\n"
    .string "Este ar da montanha é uma delícia!$"

Route10_Text_TrentDefeat::
    .string "Isso clareou a minha mente!$"

Route10_Text_TrentPostBattle::
    .string "Sinto-me empanturrado de ar da montanha!$"

Route10_EventScript_LightBall::
	finditem ITEM_LIGHT_BALL, 1
	release
	end

Route10_EventScript_BerryLass::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HEALING_BERRY, Route10_EventScript_GotDailyBerry
	msgbox Route10_Text_BerryLass, MSGBOX_DEFAULT
	random 7
	call_if_eq VAR_RESULT, 0, Route10_EventScript_GiveOranBerry
	call_if_eq VAR_RESULT, 1, Route10_EventScript_GiveSitrusBerry
	call_if_eq VAR_RESULT, 2, Route10_EventScript_GiveFigyBerry
	call_if_eq VAR_RESULT, 3, Route10_EventScript_GiveWikiBerry
	call_if_eq VAR_RESULT, 4, Route10_EventScript_GiveMagoBerry
	call_if_eq VAR_RESULT, 5, Route10_EventScript_GiveAguavBerry
	call_if_eq VAR_RESULT, 6, Route10_EventScript_GiveIapapaBerry
	setflag FLAG_DAILY_HEALING_BERRY
	goto Route10_EventScript_GotDailyBerry
	end

Route10_EventScript_GiveOranBerry::
	giveitem ITEM_ORAN_BERRY, 1
	return

Route10_EventScript_GiveSitrusBerry::
	giveitem ITEM_SITRUS_BERRY, 1
	return

Route10_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY, 1
	return

Route10_EventScript_GiveWikiBerry::
	giveitem ITEM_WIKI_BERRY, 1
	return

Route10_EventScript_GiveMagoBerry::
	giveitem ITEM_MAGO_BERRY, 1
	return

Route10_EventScript_GiveAguavBerry::
	giveitem ITEM_AGUAV_BERRY, 1
	return

Route10_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY, 1
	return

Route10_Text_BerryLass::
	.string "Nunca se sabe quanto tempo vai levar\n"
	.string "até encontrar o próximo Centro Pokémon.\p"
	.string "Frutas podem te salvar num aperto.$"

Route10_EventScript_GotDailyBerry::
	msgbox Route10_Text_BerryPrepared, MSGBOX_NPC
	release
	end

Route10_Text_BerryPrepared::
	.string "Eu sempre garanto levar algumas\n"
	.string "Frutas comigo quando saio.\p"
	.string "Dá para dizer que sou super pre-frutada.\p"
	.string "...\p"
	.string "Entendeu o trocadilho?$"

Route10_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
