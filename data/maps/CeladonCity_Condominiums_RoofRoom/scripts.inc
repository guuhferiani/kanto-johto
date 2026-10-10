.set LOCALID_PORYGON, 2

CeladonCity_Condominiums_RoofRoom_MapScripts::
	.byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_Maniac::
	goto_if_set FLAG_GOT_PORYGON, CeladonCity_Condominiums_RoofRoom_EventScript_AlreadyGotPorygon
	msgbox CeladonCity_Condominiums_RoofRoom_Text_CreatedMyOwnPokemon, MSGBOX_NPC
	end

CeladonCity_Condominiums_RoofRoom_Text_CreatedMyOwnPokemon::
	.string "Se Pokémon podem ser transformados em\n"
	.string "dados e guardados no PC, então\l"
	.string "devemos ser capazes de criar Pokémon\l"
	.string "artificialmente, certo?\p"
	.string "Essa era a minha hipótese — e eu\n"
	.string "provei isso criando o Porygon!\p"
	.string "Não acredita em mim?\p"
	.string "Pegue a Poké Bola ali na mesa,\n"
	.string "você pode ficar com o meu Porygon!$"

CeladonCity_Condominiums_RoofRoom_EventScript_AlreadyGotPorygon::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_CanAPokemonBeHacked, MSGBOX_NPC
	release
	end

CeladonCity_Condominiums_RoofRoom_Text_CanAPokemonBeHacked::
	.string "Se podemos transformar Pokémon em\n"
	.string "dados, será que um Pokémon pode\l"
	.string "ser hackeado?$"

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
	end

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
    .string "É um e-mail sobre MTs.\p"
    .string "… …\p"
    .string "Existem cinquenta MTs no total.\p"
    .string "Também há oito MOs que podem\n"
    .string "ser usadas no campo afora!\p"
    .string "SILPH S.A.$"

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonBall::
    setvar VAR_TEMP_1, SPECIES_PORYGON
    givemon SPECIES_PORYGON, 25, ITEM_NONE
    goto_if_eq VAR_RESULT, 0, CeladonCity_Condominiums_RoofRoom_EventScript_PorygonParty
    goto_if_eq VAR_RESULT, 1, CeladonCity_Condominiums_RoofRoom_EventScript_PorygonPC
    goto_if_eq VAR_RESULT, 2, CeladonCity_Condominiums_RoofRoom_EventScript_NoRoomForPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonParty::
    call CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon
    msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon::
    playfanfare MUS_LEVEL_UP
    message CeladonCity_Condominiums_RoofRoom_EventScript_Text_FoundPorygon
    waitmessage
    waitfanfare
    bufferspeciesname STR_VAR_1, SPECIES_PORYGON
    return

CeladonCity_Condominiums_RoofRoom_EventScript_Text_FoundPorygon::
    .string "{PLAYER} encontrou uma Poké Bola.\n"
    .string "Ela continha um Porygon!$"

CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon::
    setflag FLAG_GOT_PORYGON
    removeobject LOCALID_PORYGON
    release
    end

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonPC::
    call CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon
    msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon
    call Common_EventScript_NameReceivedBoxMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon::
    call Common_EventScript_TransferredToPC
    goto CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_NoRoomForPorygon::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
    release
    end

CeladonCity_Condominiums_RoofRoom_Text_NoRoomForMorePokemon::
    .string "Ah! Você não tem espaço\n"
    .string "para mais nenhum Pokémon!$"
