VermilionCity_House1_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing, MSGBOX_DEFAULT
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
    .string "Eu sou o Guru da Pesca!\p"
    .string "Eu simplesmente amoo pescar!\n"
    .string "Não consigo viver sem isso.\p"
    .string "Me diga, você gosta de pescar?$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
    .string "Oh…\n"
    .string "Que decepcionante…$"

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_Text_HowAreTheFishBiting::
    .string "Olá, {PLAYER}!\p"
    .string "Os peixes estão mordendo a isca?$"

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_OLD_ROD, 1
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife, MSGBOX_DEFAULT
	release
	end

VermilionCity_House1_Text_TakeThisAndFish::
    .string "Excelente! Gostei do seu estilo.\n"
    .string "Acho que podemos ser amigos.\p"
    .string "Pegue isto e pesque, jovem amigo!$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
    .string "Pescar é um estilo de vida!\n"
    .string "É como a mais bela poesia.\p"
    .string "Dos mares aos rios, vá lá fora e\n"
    .string "pesque o grandalhão, meu amigo!$"


VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift, MSGBOX_DEFAULT
	release
	end

VermilionCity_House1_Text_NoRoomForNiceGift::
    .string "Oh, não!\p"
    .string "Eu tinha um belo presente para você,\n"
    .string "mas você não tem espaço para ele!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
    .string "{PLAYER} recebeu uma Vara Velha do\n"
    .string "Guru da Pesca.$"







