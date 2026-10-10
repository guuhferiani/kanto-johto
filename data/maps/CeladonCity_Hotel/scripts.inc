CeladonCity_Hotel_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
    .string "Pokémon?\n"
    .string "Não, este é um hotel para pessoas.\p"
    .string "Infelizmente estamos lotados.$"

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
    .string "Estou de férias com meu irmão e\n"
    .string "meu namorado.\p"
    .string "Celadon é uma cidade tão linda!$"

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
    .string "Por quê?\n"
    .string "Por que ela trouxe o irmão dela?$"

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
    .string "Oba! Estou de férias!\n"
    .string "Minha irmã me trouxe junto! Demais!$"
