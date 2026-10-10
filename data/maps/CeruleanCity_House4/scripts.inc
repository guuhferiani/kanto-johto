CeruleanCity_House4_MapScripts::
	.byte 0

@Maybe use this NPC for some daily event stuff?
@Maybe he gives a reward after you're champion?
CeruleanCity_House4_EventScript_LonelyMan::
	goto CeruleanCity_House4_EventScript_NoNews
	end

CeruleanCity_House4_EventScript_NoNews::
	msgbox CeruleanCity_House4_Text_NothingEntertaining, MSGBOX_NPC
	release
	end

CeruleanCity_House4_Text_NothingEntertaining::
    .string "Ai, ai…\n"
    .string "Tempo demais, pouco o que fazer…\p"
    .string "Não acontece nada de divertido\n"
    .string "em lugar nenhum?$"
