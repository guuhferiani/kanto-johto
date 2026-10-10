CeladonCity_Restaurant_MapScripts::
	.byte 0
CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
    .string "Olá!\p"
    .string "Desculpe, mas estamos no nosso\n"
    .string "intervalo agora.$"

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
    .string "Meus Pokémon são fraquinhos, então\n"
    .string "tenho que ir com frequência à Farmácia.$"

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan
	waitfanfare
	waitmessage
	additem ITEM_COIN_CASE, 1
	setflag FLAG_RECEIVED_COIN_CASE
	release
	end

CeladonCity_Restaurant_Text_TakeThisImBusted::
    .string "Vai em frente! Pode rir!\n"
    .string "Estou completamente falido!\p"
    .string "Chega de caça-níqueis para mim!\n"
    .string "Vou andar na linha!\p"
    .string "Tome!\n"
    .string "Não vou mais precisar disto!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
    .string "{PLAYER} recebeu um Porta-Fichas\n"
    .string "do homem.$"

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_Text_MakeRoomForThis::
    .string "Abra espaço para isto!$"

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
    .string "Eu sempre achei que ia recuperar\n"
    .string "o que perdi…$"

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
    .string "Psiu! Ouvi dizer que tem um porão\n"
    .string "secreto sob o Cassino.$"

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
    .string "Nhom, nhom…\p"
    .string "O homem naquela mesa perdeu tudo\n"
    .string "nos caça-níqueis.$"
