.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	goto_if_set FLAG_REGISTERED_BILL, CeruleanCity_PokemonCenter_1F_EventScript_MetBill
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
    .string "Já ouviu falar do Bill?\p"
    .string "Todo mundo chama ele de PokéManíaco!\p"
    .string "Mas acho que o pessoal só tem inveja\n"
    .string "dele, isso sim.\p"
    .string "Quem não gostaria de se gabar\n"
    .string "dos seus Pokémon?$"

CeruleanCity_PokemonCenter_1F_EventScript_MetBill:
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillNumber, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_BillNumber::
	.string "Ah, então você conheceu o Bill!\n"
	.string "E ele até te deu o número\l"
	.string "de telefone dele!\p"
	.string "Nossa, ele é tão acessível!$"

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	goto_if_set FLAG_REGISTERED_BILL, CeruleanCity_PokemonCenter_1F_EventScript_IsItTrueAboutBill
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
    .string "Aquele Bill!\p"
    .string "Ouvi dizer que ele faz de tudo\n"
    .string "para conseguir Pokémon raros.\p"
    .string "Dizem que ele é capaz de qualquer\n"
    .string "coisa, foi o que ouvi falar.$"

CeruleanCity_PokemonCenter_1F_EventScript_IsItTrueAboutBill::
	msgbox CeruleanCity_PokemonCenter_1F_Text_IsItTrue, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_IsItTrue::
	.string "Ah, você conheceu o Bill?\p"
	.string "É verdade o que dizem por aí?\n"
	.string "Ele realmente faz qualquer coisa\l"
	.string "por Pokémon raros?$"


CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
    .string "O Bill tem um montão de Pokémon!\n"
    .string "Ele coleciona os mais raros também!$"

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
    .string "Na minha época, a gente subia as\n"
    .string "escadas e trocava Pokémon com amigos.\p"
    .string "Dava para conseguir muito mais variedade\n"
    .string "fazendo trocas.\p"
    .string "Mas ninguém parece trocar Pokémon\n"
    .string "hoje em dia.$"

CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty::
	msgbox PokemonJournal_Text_SpecialFeatureMisty, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureMisty::
	.string "Jornal Pokémon:\p"
	.string "Edição Especial: Misty, a Líder do\n"
	.string "Ginásio de Cerulean!\p"
	.string "Dizem que a Misty admira muito\n"
	.string "Lorelei, da Elite dos Quatro.$"
