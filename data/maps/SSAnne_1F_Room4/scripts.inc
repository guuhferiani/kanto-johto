SSAnne_1F_Room4_MapScripts::
	.byte 0

SSAnne_1F_Room4_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room4_Text_CherryPiePlease
	release
	end

SSAnne_1F_Room4_Text_CherryPiePlease::
    .string "Com licença, eu gostaria de uma torta\n"
    .string "de cereja, por favor!$"
