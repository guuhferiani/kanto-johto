SSAnne_Kitchen_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
    .string "Você aí, mon petit!\n"
    .string "Estamos ocupados aqui!\l"
    .string "Saia do caminho!$"

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_SawOddBerryInTrash::
    .string "Eu vi uma fruta estranha no lixo.\n"
    .string "O que será que era?$"

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_SoBusyImDizzy::
    .string "Estou tão ocupado que estou até tonto!\n"
    .string "Você precisa me dar espaço aqui!$"

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	call_if_eq VAR_RESULT, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_RESULT, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_RESULT, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
    .string "Aham!\n"
    .string "De fato, eu sou le Chef!\p"
    .string "Le prato principal é$"

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_Text_SalmonDuSalad::
    .string "Salmão du Salad!\p"
    .string "Les convidados podem reclamar que é\n"
    .string "peixe de novo, no entanto!$"

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_Text_EelsAuBarbecue::
    .string "Enguias au Barbecue!\p"
    .string "Les convidados vão se amotinar, temo eu.$"

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_Text_PrimeBeefsteak::
    .string "Filé Bovino de Primeira!\p"
    .string "Mas será que tenho filés du\n"
    .string "bife suficientes?$"

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
    .string "Hum-de-hum-de-ho…\p"
    .string "Descasco batatas todo santo dia!\n"
    .string "Hum-hum…$"

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
    .string "Você já ouviu falar do Snorlax?\n"
    .string "Ele é um comilão.\p"
    .string "Nenhum outro Pokémon come e dorme\n"
    .string "tanto quanto o Snorlax!$"

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
    .string "Fung… Snif…\p"
    .string "Eu só fico descascando cebolas…\n"
    .string "Snif…$"

SSAnne_Kitchen_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL, 1
	release
	end
