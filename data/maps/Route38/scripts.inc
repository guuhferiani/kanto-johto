Route38_MapScripts::
	.byte 0

Route38_EventScript_MoomooFarmGirl::
	lock
	faceplayer
	msgbox Route38_Text_MoomooFarmGirl, MSGBOX_DEFAULT
	giveitem ITEM_MOOMOO_MILK, 1
	release
	end

Route38_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR, 1
	release
	end

Route38_Text_MoomooFarmGirl::
	.string "Bem-vindo à Fazenda Moomoo na\n"
	.string "Rota 38/39!\p"
	.string "Nossas Miltank produzem o leite\n"
	.string "mais nutritivo de Johto. Experimente\l"
	.string "uma garrafa de Moomoo Milk!\p"
	.string "Continue subindo para chegar ao\n"
	.string "porto de Olivine City!$"
