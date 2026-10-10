.set LOCALID_MRFUJI, 1

LavenderTown_VolunteerPokemonHouse_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE, 1
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji
	waitmessage
	waitfanfare
	additem ITEM_POKE_FLUTE, 1
	setflag FLAG_RECEIVED_POKE_FLUTE
	clearflag FLAG_HIDE_LAVENDER_TOWN_CUBONE
	setvar VAR_POKEMON_TOWER_STATE, 4
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
    .string "Sr. Fuji: {PLAYER}…\p"
    .string "Sua jornada com a Pokédex requer\n"
    .string "uma imensa dedicação.\p"
    .string "Sem um profundo amor pelos Pokémon,\n"
    .string "sua busca pode falhar.\p"
    .string "Não sei se isso irá ajudar,\n"
    .string "mas gostaria que ficasse com isto.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
    .string "{PLAYER} recebeu uma Flauta Pokémon\n"
    .string "do Sr. Fuji.$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
    .string "Ao ouvir a Flauta Pokémon,\n"
    .string "Pokémon adormecidos vão despertar.\p"
    .string "Tente usá-la em Pokémon que estiverem\n"
    .string "dormindo e bloqueando o caminho.$"

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
    .string "Sr. Fuji: A minha Flauta Pokémon\n"
    .string "tem sido útil para você?$"

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
    .string "Você precisa abrir espaço para isto!$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
    .string "Esta é a casa do Sr. Fuji.\p"
    .string "Ele é muito bondoso.\p"
    .string "Ele cuida de Pokémon abandonados\n"
    .string "e órfãos.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
    .string "É tão quentinho!\n"
    .string "É tão bom abraçar os Pokémon.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
    .string "Que estranho, o Sr. Fuji não está aqui.\n"
    .string "Para onde ele foi?$"

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
    .string "O Sr. Fuji estava rezando sozinho\n"
    .string "pela mãe de Cubone.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
    .string "Nidorino: Gaoo!$"

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
    .string "Psyduck: Gwappa!$"


LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
    .string "Revista dos Fãs de Pokémon\n"
    .string "Sorteio Mensal do Grande Prêmio!\p"
    .string "O formulário de inscrição está…\p"
    .string "Faltando! Foi recortado.\n"
    .string "Alguém já deve ter se inscrito.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
    .string "Revistas de Pokémon enchem a estante.\p"
    .string "Pokémon Insider…\p"
    .string "Pokémon Fan…$"

LavenderTown_VolunteerPokemonHouse_EventScript_GetReward::
	playse SE_PIN
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_MRFUJI, Common_Movement_QuestionMark
	waitmovement 1
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GetReward, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachFuji
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_GetReward::
	.string "Sr. Fuji: Ah, {PLAYER}, eu tenho\n"
	.string "algo para você.\p"
	.string "Venha até aqui por um instante.$"

 Movement_ApproachFuji::
 	walk_up
 	walk_up
 	step_end
