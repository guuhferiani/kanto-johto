SafariZone_North_RestHouse_MapScripts::
	.byte 0

SafariZone_North_RestHouse_EventScript_Fisher::
	msgbox SafariZone_East_Text_PrizeInDeepestPartOfSafariZone, MSGBOX_NPC
	end

SafariZone_East_Text_PrizeInDeepestPartOfSafariZone::
    .string "Vá até a parte mais profunda da\n"
    .string "Zona do Safári. Você vai ganhar um prêmio!$"

SafariZone_North_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_KeepAnyItemFoundOnSafari, MSGBOX_NPC
	end

SafariZone_East_Text_KeepAnyItemFoundOnSafari::
    .string "Você pode ficar com qualquer item que\n"
    .string "encontrar na Zona do Safári.\p"
    .string "Mas seu tempo vai acabar se você tentar\n"
    .string "pegar todos de uma vez só.$"

SafariZone_North_RestHouse_EventScript_Gentleman::
	msgbox SafariZone_East_Text_MyEeveeEvolvedIntoFlareon, MSGBOX_NPC
	end

SafariZone_East_Text_MyEeveeEvolvedIntoFlareon::
    .string "Meu Eevee evoluiu para Flareon.\p"
    .string "Mas o Eevee de um amigo virou um\n"
    .string "Vaporeon. Por que será?$"

SafariZone_North_RestHouse_EventScript_Woman::
	msgbox SafariZone_North_RestHouse_Text_Woman, MSGBOX_NPC
	end

SafariZone_North_RestHouse_Text_Woman:
	.string "Às vezes, quando jogo um {POKEBLOCK} para\n"
	.string "um Pokémon, ele simplesmente ignora.\p"
	.string "Será que os Pokémon têm preferências\n"
	.string "sobre o que comem?$"

SafariZone_North_RestHouse_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox SafariZone_North_RestHouse_Text_KogaPatrolsSafariEverySoOften
	release
	end

SafariZone_North_RestHouse_Text_KogaPatrolsSafariEverySoOften::
    .string "A Zona do Safári é enorme, não acha?\p"
    .string "O Líder de Ginásio de Fuchsia, Koga,\n"
    .string "patrulha a área com frequência.\p"
    .string "Graças a ele, podemos nos divertir aqui\n"
    .string "sabendo que estamos seguros.$"
