.set LOCALID_NURSE, 1

FuchsiaCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
    .string "Você não se torna um bom Treinador\n"
    .string "com apenas um Pokémon forte.\p"
    .string "Mas treinar vários Pokémon de forma\n"
    .string "equilibrada também não é tarefa fácil.$"

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
    .string "Há uma trilha estreita a oeste\n"
    .string "da Cidade de Viridian.\p"
    .string "Ela leva ao Quartel-General da Liga Pokémon.\n"
    .string "O QG comanda todos os Treinadores.$"

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
    .string "Se você está trabalhando na Pokédex,\n"
    .string "visite a Zona do Safári.\p"
    .string "Todos os tipos de Pokémon raros\n"
    .string "vivem por lá.$"
