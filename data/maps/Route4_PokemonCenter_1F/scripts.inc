.set LOCALID_NURSE, 1
.set MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_4
	end

.set LOCALID_NURSE, 1

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
    .string "Certo, seis Poké Bolas no meu\n"
    .string "cinto…\p"
    .string "É, isso basta. No máximo, você\n"
    .string "pode carregar seis Pokémon com você.$"

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
    .string "A Equipe Rocket atacou cidadãos\n"
    .string "de Cerulean…\p"
    .string "Não passa um dia sequer sem que a\n"
    .string "Equipe Rocket esteja no noticiário.\p"
	.string "Precisamos de mais pessoas gentis no mundo.\n"
	.string "Como o Montanhês que conheci lá em cima!$"

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
    .string "Às vezes você terá muitos Pokémon\n"
    .string "com você para poder adicionar mais.\p"
    .string "Nesse caso, basta guardar alguns\n"
    .string "usando qualquer PC.$"

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_Newspaper, MSGBOX_DEFAULT
	release
	end

Route4_PokemonCenter_1F_Text_Newspaper::
    .string "É um jornal.\n"
    .string "EQUIPE ROCKET ATACA CIDADÃOS DE\p"
    .string "CERULEAN!\p"
    .string "...múltiplas invasões reportadas\n"
    .string "...atividades de gangues em alta...\l"
    .string "Há rumores de que a Polícia Internacional\l"
    .string "está se envolvendo...$"

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	msgbox Route4_PokemonCenter_1F_Text_BuyMagikarpForJust500, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_Text_BuyMagikarpForJust500::
    .string "Homem: Olá, jovem!\n"
    .string "Tenho uma oferta imperdível só para você!\p"
    .string "Vou te passar um Pokémon secreto\n"
    .string "- um Magikarp - por apenas ¥500!\p"
    .string "E aí, você vai querer comprar, não vai?$"


Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	call Common_EventScript_NameReceivedBoxMon
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
    .string "Parece que não há mais espaço\n"
    .string "para nenhum outro Pokémon.$"

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney 500
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	hidemoneybox
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
    .string "{PLAYER} pagou a quantia absurda de\n"
    .string "¥500 e comprou o Magikarp…$"

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_MAGIKARP
	release
	end

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
    .string "Não? Você diz não? Eu só estou fazendo\n"
    .string "isso como um favor a você!$"

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
    .string "Você vai precisar de mais dinheiro que isso!$"

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds, MSGBOX_DEFAULT
	release
	end

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
    .string "Homem: Olha, eu não faço reembolsos.\n"
    .string "Você sabia muito bem o que estava levando!$"
