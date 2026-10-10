CeruleanCity_House5_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BadgeGuy::
	msgbox CeruleanCity_House5_Text_BadgesHaveAmazingSecrets, MSGBOX_NPC
	release
	end

CeruleanCity_House5_Text_BadgesHaveAmazingSecrets::
	.string "Insígnias são muito mais que broches legais!\p"
	.string "Uma insígnia certifica um Treinador a usar\n"
	.string "certos Golpes Ocultos, como Clarão ou\l"
	.string "Voar.\p"
	.string "Os Pokémon parecem entender a sua\n"
	.string "importância também.\p"
	.string "Pokémon de nível alto não vão obedecer você\n"
	.string "se você não tiver insígnias suficientes!$"

CeruleanCity_House5_EventScript_BadgeSign::
	msgbox CeruleanCity_House5_Text_BadgeSign, MSGBOX_SIGN
	release
	end

CeruleanCity_House5_Text_BadgeSign::
	.string "Certificado Oficial de Especialista\n"
	.string "em Insígnias da Liga Pokémon$"
