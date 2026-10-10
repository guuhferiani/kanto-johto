.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney::
    .string "A Equipe Rocket faz qualquer coisa por\n"
    .string "dinheiro!\p"
    .string "Não há trabalho sujo demais, nenhum ato\n"
    .string "hediondo demais, nenhum crime perverso demais!$"

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets::
    .string "Eu vi a mãe do Cubone tentando escapar\n"
    .string "da Equipe Rocket.\p"
    .string "Ela foi morta tentando fugir…$"

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls::
    .string "Você sabe que a espécie dos Cubone\n"
    .string "usa crânios, né?\p"
    .string "As pessoas pagam uma fortuna por um.$"

LavenderTown_PokemonCenter_1F_EventScript_BaldingMan::
	msgbox LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere, MSGBOX_NPC
	release
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
    .string "Eu me mudei recentemente para este vilarejo.\p"
    .string "Ouvi dizer que o Sr. Fuji também não é\n"
    .string "originalmente daqui.$"
