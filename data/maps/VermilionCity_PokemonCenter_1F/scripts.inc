.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
    .string "Meu Pokémon foi envenenado!\n"
    .string "Ele desmaiou enquanto andávamos!$"

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
    .string "Mesmo se estiverem no mesmo nível,\n"
    .string "os Pokémon podem ter atributos e\l"
    .string "habilidades bem diferentes.\p"
    .string "Um Pokémon criado por um treinador é\n"
    .string "mais forte do que um na natureza.$"

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
    .string "É verdade que um Pokémon de nível mais\n"
    .string "alto será mais poderoso…\p"
    .string "Mas todos os Pokémon têm pontos fracos\n"
    .string "contra determinados tipos.\p"
    .string "Por isso, parece não existir um Pokémon\n"
    .string "que seja universalmente invencível.$"

VermilionCity_PokemonCenter_1F_EventScript_RematchWoman::
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain, MSGBOX_NPC
	release
	end

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
    .string "A vontade de batalhar com alguém com\n"
    .string "quem você já disputou antes…\p"
    .string "Já sentiu essa vontade?\n"
    .string "Tenho certeza de que sim.\p"
    .string "Eu também quero batalhar de novo e\n"
    .string "de novo contra certas pessoas.\p"
    .string "Vou ligar para alguns treinadores\n"
    .string "pelo meu Celular!$"
