.set LOCALID_NURSE, 1

CinnabarIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
	.byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
    .string "O amigo do Líder do Ginásio costumava\n"
    .string "morar naquela mansão queimada.\p"
    .string "Ao menos é o que dizem por aí.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
    .string "Você tem muitos amigos?\p"
    .string "Envelhecer pode ser solitário, então\n"
    .string "é importante tentar coisas novas de\l"
    .string "vez em quando.\p"
    .string "Quem sabe você não faz novos amigos?$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
    .string "Os Pokémon ainda podem aprender golpes\n"
    .string "mesmo cancelando a evolução.\p"
    .string "A evolução pode esperar até que novos\n"
    .string "golpes tenham sido aprendidos.$"
