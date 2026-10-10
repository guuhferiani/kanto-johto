CeladonCity_Condominiums_3F_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
    .string "Eu?\n"
    .string "Sou o Fotógrafo!$"

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
    .string "Sou o designer gráfico!\n"
    .string "Você gosta da Revista Pokémon?$"

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
    .string "Eu escrevo os artigos!\n"
    .string "A Erika não é uma gracinha?\p"
    .string "Também gosto muito da Misty!\n"
    .string "Ah, e da Sabrina, eu adoro ela!$"

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
    .string "Sou o Editor-Chefe!\p"
    .string "Você está trabalhando na Pokédex?\n"
    .string "É isso mesmo?\p"
    .string "Completar a Pokédex é difícil,\n"
    .string "mas não desista!\p"
    .string "Quando terminar, venha me contar!\p"
    .string "Vamos escrever uma matéria sobre você!$"

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
    .string "Uau! Excelente!\n"
    .string "Você completou a sua Pokédex!\l"
    .string "Parabéns!\l"
    .string "…$"

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
    .string "QG DA REVISTA POKéMON$"

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
    .string "É uma reportagem investigativa sobre a Equipe Rocket!\p"
    .string "Parece que eles tinham alguém infiltrado\n"
    .string "na organização!$"

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
    .string "Alguém está jogando videogame em vez de trabalhar!$"

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
    .string "É a próxima edição!\n"
    .string "O Professor Carvalho está na capa!$"
