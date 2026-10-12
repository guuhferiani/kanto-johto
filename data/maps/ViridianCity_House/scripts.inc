ViridianCity_House_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	lock
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	release
	end
	
ViridianCity_House_Text_NicknamingIsFun::
    .string "Dar apelidos e divertido, mas\n"
    .string "nao e tao facil de fazer.\p"
    .string "Nomes espertos sao legais, mas nomes\n"
    .string "simples sao mais faceis de lembrar.$"

ViridianCity_House_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	release
	end

ViridianCity_House_Text_MyDaddyLovesMonsToo::
    .string "Meu papai tambem adora Pokémon!$"

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_Text_Speary::
    .string "Speary: Piu-piu!$"

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_SpearowNameSpeary::
    .string "Spearow\n"
    .string "Nome: Speary$"
