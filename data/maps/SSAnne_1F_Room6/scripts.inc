SSAnne_1F_Room6_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
    .string "Você parece cansado. Gostaria de\n"
    .string "descansar um pouco?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
    .string "Fico feliz em ver que todos parecem\n"
    .string "renovados e cheios de energia.$"

SSAnne_1F_Room6_EventScript_DeclineHeal::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeSomeone
	release
	end

SSAnne_1F_Room6_Text_SorryYouLookLikeSomeone::
    .string "Oh, me desculpe por ser tão intrometida.\n"
    .string "Você me lembra tanto o meu neto…$"
