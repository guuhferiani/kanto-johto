PokemonTower_5F_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_ItemCleanseTag::
	finditem ITEM_CLEANSE_TAG, 1
	release
	end

PokemonTower_5F_EventScript_ItemNugget::
	finditem ITEM_NUGGET, 1
	release
	end

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
    .string "Venha, jovem!\n"
    .string "Purifiquei este local.\l"
    .string "Você pode descansar aqui.$"

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
    .string "Entrou na área purificada e\n"
    .string "protegida.\p"
    .string "Os Pokémon de {PLAYER} foram\n"
    .string "totalmente curados.$"

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_TammyIntro::
    .string "Dê…me…\n"
    .string "tudo…de…você…$"

PokemonTower_5F_Text_TammyDefeat::
    .string "Ahhh!$"

PokemonTower_5F_Text_TammyPostBattle::
    .string "Eu estava sob possessão.$"

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RuthIntro::
    .string "Você…irá…\n"
    .string "se…juntar…a…nós…$"

PokemonTower_5F_Text_RuthDefeat::
    .string "Que pesadelo!$"

PokemonTower_5F_Text_RuthPostBattle::
    .string "Eu estava possuída.$"

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_KarinaIntro::
    .string "Zumbis!$"

PokemonTower_5F_Text_KarinaDefeat::
    .string "Hã?$"

PokemonTower_5F_Text_KarinaPostBattle::
    .string "Recuperei meus sentidos.$"

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_JanaeIntro::
    .string "Urgah…\n"
    .string "Urff…$"

PokemonTower_5F_Text_JanaeDefeat::
    .string "Ufa!$"

PokemonTower_5F_Text_JanaePostBattle::
    .string "Fui dominada por espíritos malignos\n"
    .string "apesar do meu treino nas montanhas…$"
