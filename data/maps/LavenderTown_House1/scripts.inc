LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	goto_if_set FLAG_RESCUED_CUBONE, LavenderTown_House1_EventScript_CooltrainerSawCuboneReturn
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_Text_RocketsKilledCubonesMother::
    .string "Aqueles Rockets horríveis!\n"
    .string "Eles não merecem piedade nenhuma!\p"
    .string "Eles sequestraram aquele Cubone e\n"
    .string "mataram a pobre mãe dele…$"

LavenderTown_House1_EventScript_CooltrainerSawCuboneReturn::
	msgbox LavenderTown_House1_Text_CuboneReturnedToTower
	release
	end

LavenderTown_House1_Text_CuboneReturnedToTower::
	.string "Eu vi o Cubone voltar para a Torre\n"
	.string "Pokémon!\p"
	.string "Ele parecia muito determinado!$"

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
    .string "Então o fantasma da Torre Pokémon era\n"
    .string "a mãe do Cubone?\p"
    .string "Fico tão feliz que este Cubone conseguiu\n"
    .string "acalmar o espírito inquieto dela!$"

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
    .string "Cubone: Kyarugoo!$"
