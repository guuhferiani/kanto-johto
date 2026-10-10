PokemonTower_3F_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_PatriciaIntro::
    .string "Vá embora!\n"
    .string "Espírito maligno!$"

PokemonTower_3F_Text_PatriciaDefeat::
    .string "Ufa!\n"
    .string "O espírito se foi!$"

PokemonTower_3F_Text_PatriciaPostBattle::
    .string "As outras lá em cima…\n"
    .string "Elas devem ter sido possuídas.$"

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_CarlyIntro::
    .string "Kekeke…\n"
    .string "Kwaaah!$"

PokemonTower_3F_Text_CarlyDefeat::
    .string "Hum?\n"
    .string "O que estou fazendo?$"

PokemonTower_3F_Text_CarlyPostBattle::
    .string "Desculpe!\n"
    .string "Eu estava possuída!$"

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
    .string "Urrg… Awaa…\n"
    .string "Huhu… Graa…$"

PokemonTower_3F_Text_HopeDefeat::
    .string "Ah!\n"
    .string "Estou salva!$"

PokemonTower_3F_Text_HopePostBattle::
    .string "Serei para sempre transformada\n"
    .string "por esta experiência.$"

