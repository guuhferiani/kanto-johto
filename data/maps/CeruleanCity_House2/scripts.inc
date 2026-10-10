CeruleanCity_House2_MapScripts::
	.byte 0

@POSTGAME, let's clean their house up with a layout change or some metatile redraws.

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_STOLEN_TM, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
    .string "Aqueles miseráveis da Equipe Rocket!\p"
    .string "Olhe o que eles fizeram com a\n"
    .string "minha casa!\p"
    .string "Eles roubaram um MT que ensina\n"
    .string "os Pokémon a cavar buracos!\p"
    .string "Eu ia usá-lo em um Mankey ou\n"
    .string "em um Sandshrew…\p"
    .string "Aquilo me custou uma fortuna!$"

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
    .string "Acho que o que se foi, já era.\p"
    .string "Decidi ensinar meu Diglett a Cavar\n"
    .string "sem precisar de nenhum MT.$"

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
    .string "A Equipe Rocket deve estar cavando\n"
    .string "para aprontar alguma maldade!$"

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
    .string "A Equipe Rocket abriu um buraco de fuga!$"

