SSAnne_2F_Room4_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
    .string "Qual você acha mais valioso:\n"
    .string "um Pokémon forte ou um raro?$"

SSAnne_2F_Room4_Text_LamarDefeat::
    .string "Tenho que tirar o chapéu para você!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
    .string "Pessoalmente, prefiro Pokémon que\n"
    .string "sejam fortes e raros.$"

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LADY_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_DawnIntro::
    .string "Acho que não te vi na festa?$"

SSAnne_2F_Room4_Text_DawnDefeat::
    .string "Vá com calma!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
    .string "Oh, eu adoro seus Pokémon fortes!\n"
    .string "Nossa, quanta inveja eu tenho de você!$"

SSAnne_2F_Room4_EventScript_ItemXAttack::
	finditem ITEM_X_ATTACK, 1
	release
	end
