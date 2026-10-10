FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD, 1
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message FuchsiaCity_House2_Text_ReceivedGoodRod
	waitfanfare
	waitmessage
	additem ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_RECEIVED_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
    .string "Eu sou o irmão mais velho do\n"
    .string "Guru da Pesca.\p"
    .string "Eu simplesmente aamo pescar!\n"
    .string "Não consigo viver sem isso.\p"
    .string "Diga-me, você gosta de pescar?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
    .string "Excelente! Gostei do seu estilo.\n"
    .string "Acho que podemos ser amigos.\p"
    .string "Pegue isto e pesque, jovem amigo!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
    .string "{PLAYER} recebeu uma Vara Boa do\n"
    .string "irmão do Guru da Pesca.$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
    .string "Pescar é um estilo de vida!\n"
    .string "É como a mais bela poesia.\p"
    .string "Uma Vara Velha mixuruca só conseguia\n"
    .string "pescar Magikarp, não é?\p"
    .string "Mas com uma Vara Boa, você pode\n"
    .string "fisgar Pokémon muito melhores.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
    .string "Oh…\n"
    .string "Que decepção…$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
    .string "Olá, {PLAYER}!\p"
    .string "Como estão as fisgadas dos peixes?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
    .string "Oh, não!\p"
    .string "Eu tinha um presente para você,\n"
    .string "mas você não tem espaço para ele!$"
