.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
    .string "Sinta-se à vontade para usar aquele PC\n"
    .string "no canto.\p"
    .string "A recepcionista me disse isso.\n"
    .string "Ela é muito gentil!$"

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
    .string "Os Centros Pokémon curam seus Pokémon\n"
    .string "cansados, feridos ou desmaiados.\p"
    .string "Eles deixam todos os Pokémon com a saúde\n"
    .string "completamente restaurada.$"

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
    .string "Há um Centro Pokémon em todas as cidades\n"
    .string "pela frente.\p"
    .string "Eles não cobram nada, então não tenha vergonha\n"
    .string "de curar seus Pokémon.\p"
	.string "O segundo andar desses centros funciona\n"
	.string "como ponto de encontro para treinadores\l"
	.string "mais dedicados.\p"
	.string "Você pode se surpreender com o que vai achar,\n"
	.string "então sempre que visitar um novo centro,\l"
	.string "suba ao segundo andar para se apresentar!$"
