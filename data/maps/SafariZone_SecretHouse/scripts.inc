SafariZone_SecretHouse_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM03, SafariZone_SecretHouse_EventScript_CheckDailyPrize
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03, 1
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	playfanfare MUS_OBTAIN_TMHM
	message SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant
	waitfanfare
	waitmessage
	additem ITEM_HM03, 1
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_RECEIVED_HM03
	setflag FLAG_DAILY_SAFARI_GAME_PRIZE
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
    .string "Ah! Finalmente!\p"
    .string "Você é a primeira pessoa a chegar\n"
    .string "à Casa Secreta!\p"
    .string "Embora eu tenha feito uma campanha\n"
    .string "para nossa grande inauguração,\p"
    .string "já estava ficando preocupado que ninguém\n"
    .string "fosse ganhar o prêmio da campanha.\p"
    .string "Parabéns!\n"
    .string "Você venceu!$"

SafariZone_SecretHouse_Text_ExplainSurf::
    .string "O MO03 é o Surfar.\p"
    .string "Com ele, os Pokémon poderão te levar\n"
    .string "pela água.\p"
    .string "Você tem muita sorte por ganhar este\n"
    .string "prêmio fabuloso!$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
    .string "{PLAYER} recebeu o MO03\n"
    .string "do atendente!$"

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
    .string "Você não tem espaço para este\n"
    .string "prêmio fabuloso!$"

@TODO: replace this prize with a BOTTLE CAP
SafariZone_SecretHouse_EventScript_CheckDailyPrize::
	goto_if_set FLAG_DAILY_SAFARI_GAME_PRIZE, SafariZone_SecretHouse_EventScript_ExplainDailyPrize
	msgbox SafariZone_SecretHouse_Text_WinDailyPrize
	giveitem ITEM_RARE_CANDY
	setflag FLAG_DAILY_SAFARI_GAME_PRIZE
	release
	end

SafariZone_SecretHouse_Text_WinDailyPrize::
	.string "Parabéns!\n"
    .string "Você conseguiu chegar à Casa Secreta—\p"
    .string "Oh! Ei, você é o vencedor do Grande\n"
    .string "Prêmio. Já sabia o caminho até aqui,\n"
    .string "não é?\p"
    .string "Bem, você ainda tem direito ao prêmio\n"
    .string "normal, então aqui está!$"

SafariZone_SecretHouse_EventScript_ExplainDailyPrize::
	msgbox SafariZone_SecretHouse_Text_ExplainDailyPrize
	release
	end

SafariZone_SecretHouse_Text_ExplainDailyPrize::
	.string "Você já ganhou o grande prêmio por ser\n"
	.string "a primeira pessoa a chegar à Casa Secreta,\l"
	.string "mas ainda pode receber um prêmio normal\l"
	.string "se conseguir chegar aqui de novo!\p"
	.string "No entanto, só entregamos prêmios normais\n"
	.string "uma vez por dia!\p"
	.string "Volte amanhã!$"
