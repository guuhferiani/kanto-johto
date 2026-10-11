.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
	.byte 0

SaffronCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end


SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Woman::
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SaffronCity_PokemonCenter_1F_EventScript_Woman2
	msgbox SaffronCity_PokemonCenter_1F_Text_RocketsUpstairs, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_Text_RocketsUpstairs::
	.string "A Equipe Rocket é tão suspeita!\p"
	.string "Eles nos deixaram em paz aqui embaixo\n"
	.string "enquanto saqueavam o segundo andar!$"

SaffronCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone
	msgbox SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone::
	msgbox SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff
	release
	end

SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies::
    .string "A velocidade de crescimento dos\n"
    .string "Pokémon varia conforme a espécie.$"

SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame::
    .string "A Silph S.A. é amplamente conhecida.\p"
    .string "Ela foi vítima da própria fama -\n"
    .string "acabou atraindo a Equipe Rocket.$"

SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets::
    .string "Ai, ai...\n"
    .string "Não seria fantástico se a Elite dos\p"
    .string "Quatro viesse aqui e esmagasse a\n"
    .string "Equipe Rocket?$"

SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff::
    .string "A Equipe Rocket bateu em retirada!\n"
    .string "Podemos sair em segurança de novo!\l"
    .string "Isso é maravilhoso!$"
