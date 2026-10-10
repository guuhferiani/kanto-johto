Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route25_OnResume
	.byte 0

Route25_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route25_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_Text_SeaCottageSign::
    .string "Cabana Costeira\n"
    .string "O Bill mora aqui!$"

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_Text_AreYouHereAlone::
    .string "Olá, você está aqui sozinho?\p"
    .string "Se você está no cabo de Cerulean…\n"
    .string "Bem, devia ser em casal.$"

Route25_EventScript_Beauty::
	msgbox Route25_Text_MistyHighHopesAboutThisPlace, MSGBOX_NPC
	release
	end

Route25_Text_MistyHighHopesAboutThisPlace::
    .string "Este cabo é um lugar famoso para encontros.\p"
    .string "Misty, a Líder do Ginásio, tem grandes\n"
    .string "expectativas sobre este lugar.$"

Route25_EventScript_Franklin::
	trainerbattle_single REMATCHABLE_TRAINER_HIKER_FRANKLIN_1, Route25_Text_FranklinIntro, Route25_Text_FranklinDefeat, Route25_EventScript_RegisterFranklinAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route25_EventScript_FranklinRematch
	msgbox Route25_Text_FranklinPostBattle, MSGBOX_DEFAULT
	release
	end

Route25_Text_FranklinIntro::
    .string "Acabei de descer do Monte Lua,\n"
    .string "mas ainda tenho energia para dar e vender!$"

Route25_Text_FranklinDefeat::
    .string "Você lutou muito bem!$"

Route25_Text_FranklinPostBattle::
    .string "Droga!\n"
    .string "Um Zubat me mordeu lá naquela caverna.$"

Route25_EventScript_RegisterFranklinAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route25_Text_FranklinRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_HIKER_FRANKLIN_1
	release
	end

Route25_Text_FranklinRegister:
	.string "Hmm...\p"
	.string "Talvez eu não esteja tão descansado\n"
	.string "quanto imaginei...\p"
	.string "Vamos ter uma revanche outra hora!$"

Route25_EventScript_FranklinRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_HIKER_FRANKLIN_1, Route25_Text_FranklinRematchIntro, Route25_Text_FranklinDefeat
	msgbox Route25_Text_FranklinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_FranklinRematchIntro::
	.string "Ei, {PLAYER}!\n"
	.string "Ainda tenho energia no tanque!\p"
	.string "Vamos para mais um round!$"

Route25_Text_FranklinRematchPostBattle::
	.string "Talvez eu ainda esteja meio tonto\n"
	.string "daquela mordida de Zubat!$"


Route25_EventScript_Joey::
	trainerbattle_single TRAINER_YOUNGSTER_JOEY, Route25_Text_JoeyIntro, Route25_Text_JoeyDefeat
	msgbox Route25_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_JoeyIntro::
    .string "Os treinadores daqui vêm praticar\n"
    .string "neste lugar.$"

Route25_Text_JoeyDefeat::
    .string "Você é decente.$"

Route25_Text_JoeyPostBattle::
    .string "Todos os Pokémon têm fraquezas.\n"
    .string "Até mesmo os mais fortes.\p"
    .string "Por isso o melhor é criar\n"
    .string "Pokémon de tipos diferentes.$"


Route25_EventScript_Wayne::
	trainerbattle_single TRAINER_HIKER_WAYNE, Route25_Text_WayneIntro, Route25_Text_WayneDefeat
	msgbox Route25_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_WayneIntro::
    .string "Você vai ver o Bill?\n"
    .string "Primeiro, vamos batalhar!$"

Route25_Text_WayneDefeat::
    .string "Você manda bem.$"

Route25_Text_WaynePostBattle::
    .string "A trilha logo abaixo é um atalho para\n"
    .string "a Cidade de Cerulean.$"

Route25_EventScript_Dan::
	trainerbattle_single TRAINER_YOUNGSTER_DAN, Route25_Text_DanIntro, Route25_Text_DanDefeat
	msgbox Route25_Text_DanPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_DanIntro::
    .string "Papai me levou para uma grande festa\n"
    .string "no S.S. Anne, na Cidade de Vermilion.$"

Route25_Text_DanDefeat::
    .string "Não estou chateado!$"

Route25_Text_DanPostBattle::
    .string "No S.S. Anne, vi treinadores\n"
    .string "do mundo inteiro.$"

Route25_EventScript_Kelsey::
	trainerbattle_single TRAINER_PICNICKER_KELSEY, Route25_Text_KelseyIntro, Route25_Text_KelseyDefeat
	msgbox Route25_Text_KelseyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_KelseyIntro::
    .string "Oi!\n"
    .string "Meu namorado é demais!$"

Route25_Text_KelseyDefeat::
    .string "Minha preparação não foi das melhores…$"

Route25_Text_KelseyPostBattle::
    .string "Queria que meu namorado fosse\n"
    .string "tão bom quanto você.$"

Route25_EventScript_Nob::
	trainerbattle_single TRAINER_HIKER_NOB, Route25_Text_NobIntro, Route25_Text_NobDefeat
	msgbox Route25_Text_NobPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_NobIntro::
    .string "Estou indo ver a coleção de um\n"
    .string "Pokémaníaco lá no cabo.$"

Route25_Text_NobDefeat::
    .string "Você me pegou de jeito,\n"
    .string "e mandou muito bem!$"

Route25_Text_NobPostBattle::
    .string "O Pokémaníaco realmente faz jus\n"
    .string "ao apelido.\p"
    .string "A coleção dele inclui muitas espécies\n"
    .string "raras de Pokémon.$"

Route25_EventScript_Flint::
	trainerbattle_single TRAINER_CAMPER_FLINT, Route25_Text_FlintIntro, Route25_Text_FlintDefeat
	msgbox Route25_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_FlintIntro::
    .string "Eu sou um cara legal.\n"
    .string "Eu tenho uma namorada!$"

Route25_Text_FlintDefeat::
    .string "Ah, que droga…$"

Route25_Text_FlintPostBattle::
    .string "Ah, tanto faz.\n"
    .string "Minha namorada vai me animar.$"

Route25_EventScript_Chad::
	trainerbattle_single TRAINER_YOUNGSTER_CHAD, Route25_Text_ChadIntro, Route25_Text_ChadDefeat
	msgbox Route25_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_ChadIntro::
    .string "Tive um pressentimento…\n"
    .string "Sabia que tinha que batalhar com você!$"

Route25_Text_ChadDefeat::
    .string "Eu sabia que ia perder também!$"

Route25_Text_ChadPostBattle::
    .string "Se o seu Pokémon ficar confuso,\n"
    .string "troque por outro.\p"
    .string "Essa é uma boa tática.$"

Route25_EventScript_Haley::
	trainerbattle_single TRAINER_LASS_HALEY, Route25_Text_HaleyIntro, Route25_Text_HaleyDefeat
	msgbox Route25_Text_HaleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_HaleyIntro::
    .string "Minha amiga tem muitos Pokémon fofos.\n"
    .string "Tenho tanta inveja!$"

Route25_Text_HaleyDefeat::
    .string "Nem tenho tanta inveja assim!$"

Route25_Text_HaleyPostBattle::
    .string "Você veio do Monte Lua?\n"
    .string "Poderia me dar uma Clefairy?$"

Route25_FindItem_ToxicOrb::
	finditem ITEM_TOXIC_ORB, 1
	end

Route25_EventScript_ZubatDroppedThis::
	goto_if_set FLAG_MISSING_PECHA_BERRY, Route25_EventScript_TakeCare
	finditem ITEM_PECHA_BERRY, 1
	setflag FLAG_MISSING_PECHA_BERRY
	release
	end

Route25_EventScript_TakeCare::
	release
	end
