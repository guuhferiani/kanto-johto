LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_Text_DoYouBelieveInGhosts::
    .string "Você acredita em fantasmas?$"

LavenderTown_Text_JustImaginingWhiteHand::
    .string "Hahaha, acho que não.\p"
    .string "Aquela mão branca no seu ombro…\n"
    .string "É só coisa da minha imaginação.$"


LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_Text_SoThereAreBelievers::
    .string "Sério?\n"
    .string "Então ainda há quem acredite…$"

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_Text_TownKnownAsMonGraveSite::
    .string "Este vilarejo é conhecido como o cemitério\n"
    .string "dos Pokémon.\p"
    .string "Serviços fúnebres são realizados na\n"
    .string "Torre Pokémon.$"

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_Text_GhostsAppearedInTower::
    .string "Fantasmas apareceram na Torre Pokémon.\p"
    .string "Acho que são os espíritos de Pokémon\n"
    .string "que os Rockets mataram.$"

LavenderTown_Text_TownSign::
    .string "Vilarejo de Lavender\n"
    .string "O Nobre Vilarejo Roxo$"

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_TrainerTips::
	msgbox LavenderTown_Text_TrainerTips, MSGBOX_SIGN
	end

LavenderTown_Text_TrainerTips::
    .string "Dicas para Treinadores!\n"
    .string "Segure o Botão A para andar em silêncio\n"
    .string "ao usar o seu PokéNav!$"

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_Text_VolunteerPokemonHouse::
    .string "Casa Voluntária dos\n"
    .string "Pokémon de Lavender$"

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokemonTowerSign::
    .string "Torre Pokémon\n"
    .string "Acalme os Espíritos dos Pokémon$"

LavenderTown_EventScript_Gengar::
	lock
	faceplayer
	playmoncry SPECIES_GENGAR, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_KISHI, LavenderTown_EventScript_GengarDefeated
	msgbox LavenderTown_Text_Gengar MSGBOX_DEFAULT
	release
	end

LavenderTown_Text_Gengar:
	.string "Você ouve o som de um carrossel rangendo\n"
	.string "girando em um parquinho vazio.\p"
	.string "Gengar dá uma risadinha enquanto o som some.$"

LavenderTown_EventScript_BeautyKishi::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KISHI, LavenderTown_EventScript_MegaHintGengar
	goto_if_set FLAG_GOT_MEGA_RING, LavenderTown_EventScript_BeautyKishiBattle
	msgbox LavenderTown_Text_KishiDoYouBelieve MSGBOX_NPC
	release
	end

LavenderTown_Text_KishiDoYouBelieve:
	.string "Diga-me, jovem.\n"
	.string "Você acredita em fantasmas?$"

LavenderTown_EventScript_BeautyKishiBattle::
	trainerbattle_single TRAINER_BEAUTY_KISHI, LavenderTown_Text_KishiIntro, LavenderTown_Text_KishiDefeat
	setflag FLAG_DEFEATED_KISHI
	msgbox LavenderTown_Text_KishiPostBattle MSGBOX_AUTOCLOSE
	release
	end

LavenderTown_Text_KishiIntro:
	.string "Diga-me, jovem.\n"
	.string "Você acredita em fantasmas?\p"
	.string "Ver para crer. Agora que você pode\n"
	.string "ver, nós podemos começar.$"

LavenderTown_Text_KishiDefeat:
	.string "Tudo está bem quando termina bem.$"

LavenderTown_Text_KishiPostBattle:
	.string "Aquilo em que você escolhe acreditar\n"
	.string "assombrará o mundo quando você\l"
	.string "partir desta vida.$"

LavenderTown_EventScript_MegaHintGengar::    
    goto_if_set FLAG_GOT_GENGARITE, LavenderTown_EventScript_KishiDefeated
    msgbox LavenderTown_Text_GengarMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
LavenderTown_Text_GengarMegaHint:
    .string "Marowak e eu acreditamos que você é\n"
	.string "um treinador bondoso, então, por favor,\l"
	.string "suba até o topo da Torre.$"

LavenderTown_EventScript_KishiDefeated::
    msgbox KishiDefeated_Text MSGBOX_DEFAULT
	release
	end

KishiDefeated_Text:	
	.string "Aquilo em que você escolhe acreditar\n"
	.string "assombrará o mundo quando você\l"
	.string "partir desta vida.\p"
	.string "Acredite que ainda há bondade para\n"
	.string "ser encontrada neste mundo.$"

LavenderTown_EventScript_GengarDefeated::
	msgbox GengarDefeated MSGBOX_DEFAULT
	release
	end

GengarDefeated:	
	.string "Gengar revira os olhos e coloca a\n"
	.string "língua para fora de brincadeira.$"
