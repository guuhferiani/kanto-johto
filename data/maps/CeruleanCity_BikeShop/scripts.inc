CeruleanCity_BikeShop_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Bicycle::
	goto_if_unset FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_NoBikeYet
	checkitem ITEM_ACRO_BIKE, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_BikeShop_EventScript_GetAcroBike
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_EventScript_NoBikeYet::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_EventScript_GetAcroBike::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeruleanCity_BikeShop_Text_BonusBike
	waitmessage
	waitfanfare
	closemessage
	additem ITEM_ACRO_BIKE, 1
	release
	end

CeruleanCity_BikeShop_Text_BonusBike:
	.string "{PLAYER} resgatou a\n"
    .string "Bicicleta Acro restante!$"

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
    .string "Uma Bicicleta novinha em folha!$"

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 14, 0, MULTI_BIKE, FALSE
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
    .string "Olá!\n"
    .string "Bem-vindo à nossa Loja de Bicicletas.\p"
    .string "Temos a bicicleta perfeita para\n"
    .string "você!$"

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
    .string "Desculpe!\n"
    .string "Você não tem dinheiro suficiente!$"

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
    .string "Obrigado!\n"
    .string "Volte sempre!$"

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
    .string "O que está achando das suas novas bikes?\n"
    .string "Gosta de como elas andam?\p"
    .string "Você pode passear com elas pela Rodovia\n"
    .string "dos Ciclistas e até dentro de cavernas!$"

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	checkitem ITEM_BIKE_VOUCHER, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_BikeShop_EventScript_BringBikeVoucher
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle
	waitmessage
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE, 1
	additem ITEM_MACH_BIKE, 1
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
    .string "Oh, isso é…\p"
    .string "Um Vale-Bicicleta!\p"
    .string "Muito bem!\n"
    .string "Aqui estão elas!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
    .string "{PLAYER} trocou o Vale-Bicicleta\n"
    .string "por duas bicicletas!$"

CeruleanCity_BikeShop_EventScript_BringBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
    .string "Como assim, garoto?\p"
    .string "Não adianta só me dizer que tem um\n"
    .string "Vale-Bicicleta, você precisa trazê-lo\l"
    .string "aqui comigo!$"

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
    .string "Uma bicicleta urbana comum já é boa\n"
    .string "o bastante para mim.\p"
    .string "Não preciso fazer manobras.\p"
    .string "Afinal, não dá para empinar a roda quando\n"
    .string "se tem uma cesta de compras!$"

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
    .string "Essas bicicletas são incríveis, mas são\n"
    .string "caras demais!$"

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end
	
CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
    .string "Uau.\n"
    .string "Você conseguiu duas bicicletas?!$"



