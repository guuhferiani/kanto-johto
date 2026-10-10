CeruleanCity_House1_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BulbasaurBreeder::
	msgbox CeruleanCity_House1_Text_HowsThatBulbasaur, MSGBOX_NPC
	release
	end

CeruleanCity_House1_Text_HowsThatBulbasaur::
	.string "Como aquele Bulbasaur está se dando\n"
	.string "com os seus Pokémon?\p"
	.string "Espero que esteja cuidando bem dele!$"

CeruleanCity_House1_EventScript_BerryGuy::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WATERING_CAN, CeruleanCity_House1_EventScript_GetWailmerPail
	goto_if_set FLAG_DAILY_CERULEAN_BERRY, CeruleanCity_House1_EventScript_GrowAVariety
	goto CeruleanCity_House1_EventScript_GetDailyBerry

CeruleanCity_House1_EventScript_GetDailyBerry::
	msgbox CeruleanCity_House1_Text_PokemonLoveBerries, MSGBOX_DEFAULT
	random 6
	call_if_eq VAR_RESULT, 0, CeruleanCity_House1_EventScript_GiveGrepaBerry
	call_if_eq VAR_RESULT, 1, CeruleanCity_House1_EventScript_GiveHondewBerry
	call_if_eq VAR_RESULT, 2, CeruleanCity_House1_EventScript_GiveKelpsyBerry
	call_if_eq VAR_RESULT, 3, CeruleanCity_House1_EventScript_GivePomegBerry
	call_if_eq VAR_RESULT, 4, CeruleanCity_House1_EventScript_GiveQualotBerry
	call_if_eq VAR_RESULT, 5, CeruleanCity_House1_EventScript_GiveTamatoBerry
	setflag FLAG_DAILY_CERULEAN_BERRY
	goto CeruleanCity_House1_EventScript_GrowAVariety
	end


CeruleanCity_House1_Text_PokemonLoveBerries::
	.string "Os Pokémon adoram Frutas!\p"
	.string "Alimentar seus Pokémon é uma ótima\n"
	.string "maneira de fortalecer seus laços.\p"
	.string "Tome, por que você não experimenta\n"
	.string "você mesmo!$"

CeruleanCity_House1_EventScript_GiveGrepaBerry::
	giveitem ITEM_GREPA_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveHondewBerry::
	giveitem ITEM_HONDEW_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveKelpsyBerry::
	giveitem ITEM_KELPSY_BERRY, 1
	return

CeruleanCity_House1_EventScript_GivePomegBerry::
	giveitem ITEM_POMEG_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveQualotBerry::
	giveitem ITEM_QUALOT_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveTamatoBerry::
	giveitem ITEM_TAMATO_BERRY, 1
	return

CeruleanCity_House1_EventScript_GrowAVariety::
	msgbox CeruleanCity_House1_Text_GrowAVariety, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_GrowAVariety::
	.string "Existem todos os tipos de Frutas.\p"
	.string "E elas não têm todas os mesmos\n"
	.string "efeitos!\p"
	.string "Tente cultivar uma variedade!$"

CeruleanCity_House1_EventScript_GetWailmerPail::
	msgbox CeruleanCity_House1_Text_WifeAndIGrowBerries, MSGBOX_DEFAULT
	checkitemspace ITEM_WAILMER_PAIL, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House1_EventScript_BagFull
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox CeruleanCity_House1_Text_GetWailmerPail, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_WAILMER_PAIL
	setflag FLAG_RECEIVED_WATERING_CAN
	goto CeruleanCity_House1_EventScript_GetDailyBerry
	end

CeruleanCity_House1_Text_GetWailmerPail::
	.string "{PLAYER} recebeu o Regador\n"
	.string "do Homem das Frutas!\p"
	.string "{PLAYER} guardou o Regador no\n"
	.string "bolso de Itens-Chave.$"

CeruleanCity_House1_Text_WifeAndIGrowBerries::
	.string "Talvez você não saiba, mas Kanto\n"
	.string "nem sempre teve Frutas!\p"
	.string "Elas podem ser bem difíceis de plantar\n"
	.string "e as pessoas não sabiam quase nada\l"
	.string "sobre Frutas naquela época.\p"
	.string "Por isso, minha esposa e eu viajamos\n"
	.string "por toda Kanto plantando árvores!\p"
	.string "Se encontrar alguma delas por aí,\n"
	.string "por favor, sinta-se à vontade.\p"
	.string "Queremos que todos cuidem melhor da\n"
	.string "terra, tanto para as pessoas quanto\l"
	.string "para os Pokémon!\p"
	.string "Então, se colher uma Fruta, plante\n"
	.string "outra! E se tiver um tempinho,\l"
	.string "você pode regá-las com isto!$"

CeruleanCity_House1_EventScript_BagFull::
	msgbox CeruleanCity_House1_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_MaybeLater::
	.string "Opa... Sua Mochila está cheia.\p"
	.string "Quem sabe volte mais tarde?$"


