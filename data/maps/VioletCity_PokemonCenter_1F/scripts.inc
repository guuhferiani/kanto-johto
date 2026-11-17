.set LOCALID_NURSE, 1

VioletCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_PokemonCenter_1F_OnTransition
	.byte 0

VioletCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VIOLET_CITY
	end


VioletCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

VioletCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VioletCity_PokemonCenter_1F_Text_Gentleman, MSGBOX_NPC
	end

VioletCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VioletCity_PokemonCenter_1F_Text_Youngster, MSGBOX_NPC
	end

VioletCity_PokemonCenter_1F_EventScript_ElmsAide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_1F_EventScript_AideAfterEgg
	msgbox VioletCity_PokemonCenter_1F_Text_AideOfferEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_1F_EventScript_AideDeclined
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, VioletCity_PokemonCenter_1F_EventScript_AidePartyFull
	giveegg SPECIES_TOGEPI
	playfanfare MUS_OBTAIN_ITEM
	message VioletCity_PokemonCenter_1F_Text_ReceivedTogepiEgg
	waitfanfare
	waitmessage
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokemonCenter_1F_Text_AideTakeCareOfEgg, MSGBOX_DEFAULT
	release
	end

VioletCity_PokemonCenter_1F_EventScript_AideAfterEgg::
	msgbox VioletCity_PokemonCenter_1F_Text_AideTakeCareOfEgg, MSGBOX_DEFAULT
	release
	end

VioletCity_PokemonCenter_1F_EventScript_AideDeclined::
	msgbox VioletCity_PokemonCenter_1F_Text_AideDeclined, MSGBOX_DEFAULT
	release
	end

VioletCity_PokemonCenter_1F_EventScript_AidePartyFull::
	msgbox VioletCity_PokemonCenter_1F_Text_AidePartyFull, MSGBOX_DEFAULT
	release
	end

VioletCity_PokemonCenter_1F_Text_AideOfferEgg:
	.string "Olá! Sou assistente do Prof. Elm.\n"
	.string "Ele me pediu para entregar este Ovo\l"
	.string "misterioso a um treinador confiável.\p"
	.string "Gostaria de cuidar deste Ovo Pokémon?$"

VioletCity_PokemonCenter_1F_Text_ReceivedTogepiEgg:
	.string "{PLAYER} recebeu o Ovo Misterioso!$"

VioletCity_PokemonCenter_1F_Text_AideTakeCareOfEgg:
	.string "O Prof. Elm descobriu que os Ovos\n"
	.string "chocam conforme você caminha com eles\l"
	.string "na sua equipe. Cuide bem dele!$"

VioletCity_PokemonCenter_1F_Text_AideDeclined:
	.string "Tudo bem! Se mudar de ideia, estarei\n"
	.string "por aqui esperando.$"

VioletCity_PokemonCenter_1F_Text_AidePartyFull:
	.string "Oh! Sua equipe já está cheia com 6\n"
	.string "Pokémon. Libere um espaço no PC e\l"
	.string "fale comigo novamente!$"

VioletCity_PokemonCenter_1F_Text_Gentleman:
	.string "Os Centros Pokémon de Johto também\n"
	.string "estão integrados ao sistema de PC\l"
	.string "do Bill em Kanto!$"

VioletCity_PokemonCenter_1F_Text_Youngster:
	.string "Se você tiver um Pikachu forte, o\n"
	.string "Ginásio de Falkner será uma ótima\l"
	.string "oportunidade para brilhar!$"
