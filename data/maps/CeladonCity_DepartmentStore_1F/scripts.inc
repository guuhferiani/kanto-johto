CeladonCity_DepartmentStore_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_1F_OnTransition
	.byte 0

CeladonCity_DepartmentStore_1F_OnTransition:
	setescapewarp MAP_CELADON_CITY, 15, 16
	end

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
    .string "Olá! Boas-vindas à Loja de\n"
    .string "Departamentos de Celadon.\p"
    .string "O quadro à direita descreve a\n"
    .string "organização dos andares da loja.$"

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
    .string "1º A: Balcão de Atendimento\p"
    .string "2º A: Mercado do Treinador\p"
    .string "3º A: Loja de Videogames\p"
    .string "4º A: Presentes do Sábio\p"
    .string "5º A: Farmácia\p"
    .string "Cobertura: Máquinas de Bebidas$"

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
    .string "1º Andar: Balcão de Atendimento$"
