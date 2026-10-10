SSAnne_1F_Corridor_MapScripts::
	.byte 0

SSAnne_1F_Corridor_EventScript_WorkerM::
	msgbox SSAnne_1F_Corridor_Text_LeStrongSilentType, MSGBOX_NPC
	end

SSAnne_1F_Corridor_Text_LeStrongSilentType::
    .string "Bonjour!\n"
    .string "Eu sou le garçom deste navio!\p"
    .string "Terei prazer em servi-lo com\n"
    .string "o que desejar!\p"
    .string "… … …\n"
    .string "Ah! Le tipo forte e calado!$"

SSAnne_1F_Corridor_EventScript_Sailor::
	msgbox SSAnne_1F_Corridor_Text_PassengersAreRestless, MSGBOX_NPC
	end

SSAnne_1F_Corridor_Text_PassengersAreRestless::
    .string "Os passageiros estão inquietos por\n"
    .string "causa desta longa viagem.\p"
    .string "Você pode ser desafiado pelos\n"
    .string "mais entediados!$"
