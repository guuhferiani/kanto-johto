RockTunnel_1F_MapScripts::
	.byte 0

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
    .string "Este túnel é longo pra caramba, garoto!$"

RockTunnel_1F_Text_LennyDefeat::
    .string "Doh!\n"
    .string "Você venceu!$"

RockTunnel_1F_Text_LennyPostBattle::
    .string "Cuidado com os Onix.\n"
    .string "Eles aparecem só de vez em quando.\p"
    .string "Os de nível alto podem te esmagar!$"

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_OliverIntro::
    .string "Hmm.\n"
    .string "Acho que me perdi aqui dentro…$"

RockTunnel_1F_Text_OliverDefeat::
    .string "Pega leve!\n"
    .string "O que estou fazendo?\l"
    .string "Para que lado fica a saída?$"

RockTunnel_1F_Text_OliverPostBattle::
    .string "Aquele Pokémon dorminhoco na Rota 12\n"
    .string "me obrigou a fazer este desvio.$"

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LucasIntro::
    .string "Forasteiros como você precisam me\n"
    .string "mostrar algum respeito!$"

RockTunnel_1F_Text_LucasDefeat::
    .string "Eu me rendo!$"

RockTunnel_1F_Text_LucasPostBattle::
    .string "Você tem talento de sobra para trilhas!$"

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_AshtonIntro::
    .string "Batalha de Pokémon!\n"
    .string "Preparar, vai!$"

RockTunnel_1F_Text_AshtonDefeat::
    .string "Fim de jogo!$"

RockTunnel_1F_Text_AshtonPostBattle::
    .string "Ah bem, vou pegar um Zubat pelo caminho!$"

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LeahIntro::
    .string "Eek!\p"
    .string "Não tente nenhuma gracinha no escuro!$"

RockTunnel_1F_Text_LeahDefeat::
    .string "Estava escuro demais…$"

RockTunnel_1F_Text_LeahPostBattle::
    .string "Eu vi um Machop neste túnel.$"

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_ArianaIntro::
    .string "Você tem Pokémon!\n"
    .string "Vamos começar!$"

RockTunnel_1F_Text_ArianaDefeat::
    .string "Você joga pesado!$"

RockTunnel_1F_Text_ArianaPostBattle::
    .string "Ufa!\n"
    .string "Fiquei toda suada agora.$"

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_DanaIntro::
    .string "Eu vim até aqui procurando por\n"
    .string "Pokémon selvagens.$"

RockTunnel_1F_Text_DanaDefeat::
    .string "Fiquei sem Pokémon!$"

RockTunnel_1F_Text_DanaPostBattle::
    .string "Você parecia tão fofo e inofensivo.\n"
    .string "Como eu estava enganada!$"

RockTunnel_1F_Text_RouteSign::
    .string "Túnel de Rocha\n"
    .string "Cidade de Cerulean - Vilarejo de Lavender$"

RockTunnel_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

RockTunnel_1F_EventScript_ItemPearl::
	finditem ITEM_PEARL, 1
	release
	end

RockTunnel_1F_EventScript_ItemRepel::
	finditem ITEM_REPEL, 1
	release
	end
