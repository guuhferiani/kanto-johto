.set LOCALID_NIDORAN, 3

PewterCity_House1_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_Text_TradeMonsAreFinicky::
    .string "Nosso Pokémon veio de fora, então ele\n"
    .string "é teimoso e difícil de controlar.\p"
    .string "Um Pokémon de fora é aquele que você\n"
    .string "recebe através de uma troca.\p"
    .string "Ele cresce rápido, mas pode ignorar\n"
    .string "um treinador novato em batalha.\p"
    .string "Se ao menos tivéssemos Insígnias…$"

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_Text_NidoranSit::
    .string "Nidoran, senta!$"

PewterCity_House1_EventScript_DoNidoranCry::
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	return

PewterCity_House1_Text_Nidoran::
    .string "Nidoran♂: Bowbow!$"
