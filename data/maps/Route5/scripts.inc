.set LOCALID_DAYCARE_WOMAN, 1
.set LOCALID_FUGITIVE, 11

Route5_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route5_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route5_OnResume
	.byte 0

Route5_OnFrame::
	map_script_2 VAR_DAYCARE_EGG_PENDING, 1, Route5_EventScript_TryTurnDayCareWoman
	.2byte 0

Route5_EventScript_TryTurnDayCareWoman::
	turnobject LOCALID_DAYCARE_WOMAN, DIR_SOUTH
	setvar VAR_DAYCARE_EGG_PENDING, 0
	end

Route5_OnTransition:
	call_if_set FLAG_PENDING_DAYCARE_EGG, Route5_EventScript_TurnCareWoman
	call Common_EventScript_GetDayOrNight
	end

Route5_EventScript_TurnCareWoman::
	setobjectmovementtype LOCALID_DAYCARE_WOMAN, MOVEMENT_TYPE_FACE_DOWN
	setvar VAR_DAYCARE_EGG_PENDING, 0
	return

Route5_OnResume:
	call_if_set FLAG_PENDING_DAYCARE_EGG, Route5_EventScript_TurnCareWoman
	call Common_EventScript_GetDayOrNight
	end

Route5_EventScript_UndergroundPathSign::
	msgbox Route5_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route5_Text_UndergroundPathSign::
    .string "Passagem Subterrânea\n"
    .string "Cidade de Cerulean - Cidade de Vermilion$"

Route5_EventScript_DayCareSign::
	msgbox Route5_Text_DayCareSign, MSGBOX_SIGN
	end

Route5_Text_DayCareSign::
	.string "Creche Pokémon\n"
	.string "“Deixe-nos criar seus Pokémon.”$"


@Daycare Woman
Route5_EventScript_DaycareWoman::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route5_EventScript_CheckOnTwoMons
	msgbox Route5_Text_GoInsideIfYoudLikeMeToRaiseMon, MSGBOX_NPC
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_GoInsideIfYoudLikeMeToRaiseMon:
	.string "Sou voluntária na Creche.\p"
	.string "Treinadores de toda Kanto nos pedem\n"
	.string "para cuidar dos seus Pokémon.\p"
	.string "Se quiser que criemos o seu Pokémon,\n"
	.string "converse com o pessoal lá dentro.$"

Route5_EventScript_DaycareEggWaiting::
	msgbox Route5_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_EventScript_DaycareAcceptEgg
	msgbox Route5_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route5_EventScript_DaycareAcceptEgg
	msgbox Route5_Text_IllKeepIt, MSGBOX_NPC
	clearflag FLAG_PENDING_DAYCARE_EGG
	setvar VAR_DAYCARE_EGG_PENDING, 0
	special RejectEggFromDayCare
	release
	end

Route5_Text_DoYouWantEgg:
	.string "Ah, é você!\p"
	.string "Estávamos criando seu Pokémon,\n"
	.string "e caramba, que surpresa nós tivemos!\p"
	.string "Seu Pokémon tinha um Ovo!\p"
	.string "Não sabemos como ele apareceu,\n"
	.string "mas o seu Pokémon o tinha.\p"
	.string "Gostaria de levá-lo com você?$"

Route5_Text_IWillKeepDoYouWantIt:
	.string "Você não quer levar?\n"
	.string "Quer que eu doe para outra pessoa?$"

Route5_Text_IllKeepIt:
	.string "Certo! Encontraremos um bom lar\n"
	.string "para este Ovo.$"

Route5_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route5_EventScript_DaycareReceiveEgg
	msgbox Route5_Text_YouHaveNoRoomForIt, MSGBOX_NPC
	release
	end

Route5_Text_YouHaveNoRoomForIt:
	.string "Você não tem espaço para ele…\n"
	.string "Volte quando tiver liberado um espaço.$"

Route5_EventScript_DaycareReceiveEgg::
	message Route5_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route5_Text_TakeGoodCareOfIt, MSGBOX_NPC
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	setvar VAR_DAYCARE_EGG_PENDING, 0
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_ReceivedEgg:
	.string "{PLAYER} recebeu o Ovo\n"
	.string "da Creche.$"

Route5_Text_TakeGoodCareOfIt:
	.string "Cuide muito bem dele.$"

Route5_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route5_Text_YourMonIsDoingFine, MSGBOX_NPC
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_YourMonIsDoingFine:
	.string "Ah, é você! Que bom ver você.\n"
	.string "Seu {STR_VAR_1} está indo muito bem.$"

Route5_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route5_Text_YourMonsAreDoingFine, MSGBOX_NPC
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	turnobject LOCALID_DAYCARE_WOMAN, DIR_NORTH
	release
	end

Route5_Text_YourMonsAreDoingFine:
	.string "Ah, é você! Seus {STR_VAR_1} e\n"
	.string "{STR_VAR_2} estão indo muito bem.$"

Route5_EventScript_BerryGuy::
	lock
	faceplayer
	msgbox Route5_Text_FriendshipBerries MSGBOX_DEFAULT
	release
	end

Route5_Text_FriendshipBerries:
	.string "Ouvi dizer que existem Frutas que\n"
	.string "deixam o Pokémon mais amigável.$"

Route5_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
