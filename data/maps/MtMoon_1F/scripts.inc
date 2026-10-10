MtMoon_1F_MapScripts::
	.byte 0

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_Text_ZubatIsABloodsucker::
    .string "Cuidado!\n"
    .string "Zubat é um sugador de sangue!$"

MtMoon_1F_EventScript_Macros::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
    .string "UOU!\n"
    .string "Que susto você me deu!\l"
    .string "…Ah, é só uma criança!$"

MtMoon_1F_Text_MarcosDefeat::
    .string "Uau!\n"
    .string "Chocado de novo!$"

MtMoon_1F_Text_MarcosPostBattle::
    .string "Crianças como você não deveriam ficar\n"
    .string "vadiando por aqui no escuro.$"

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_JoshIntro::
    .string "Você veio explorar a caverna também?$"

MtMoon_1F_Text_JoshDefeat::
    .string "Perder é péssimo!\n"
    .string "Não tem nada de legal nisso.$"

MtMoon_1F_Text_JoshPostBattle::
    .string "Eu vim até aqui embaixo para me exibir\n"
    .string "para as garotas.$"


MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MiriamIntro::
    .string "Nossa! Aqui dentro é bem maior do que\n"
    .string "eu pensava!$"

MtMoon_1F_Text_MiriamDefeat::
    .string "Ah!\n"
    .string "Eu perdi!$"

MtMoon_1F_Text_MiriamPostBattle::
    .string "Como se sai daqui?\n"
    .string "É tão grande que acho que vou me perder.$"

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end


MtMoon_1F_Text_IrisIntro::
    .string "O quê?\n"
    .string "Estou esperando meus amigos me encontrarem\l"
    .string "aqui.$"

MtMoon_1F_Text_IrisDefeat::
    .string "Eu perdi?$"

MtMoon_1F_Text_IrisPostBattle::
    .string "Eu vim porque ouvi dizer que há alguns\n"
    .string "fósseis muito raros por aqui.$"

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_JovanIntro::
    .string "O quê!\n"
    .string "Não chegue de mansinho pelas minhas costas!$"

MtMoon_1F_Text_JovanDefeat::
    .string "Meus Pokémon não deram conta!$"

MtMoon_1F_Text_JovanPostBattle::
    .string "Preciso encontrar Pokémon mais fortes.\n"
    .string "Onde será que eles estão?$"

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_KentIntro::
    .string "Homens suspeitos estão na caverna.\n"
    .string "E quanto a você?$"

MtMoon_1F_Text_KentDefeat::
    .string "Você me pegou!$"

MtMoon_1F_Text_KentPostBattle::
    .string "Eu vi eles!\n"
    .string "Tenho certeza de que são da Equipe Rocket!$"

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_RobbyIntro::
    .string "Você precisa atravessar esta caverna para\n"
    .string "chegar a Cerulean City.$"

MtMoon_1F_Text_RobbyDefeat::
    .string "Eu perdi.$"

MtMoon_1F_Text_RobbyPostBattle::
    .string "Zubat é durão!\n"
    .string "Mas se você conseguir capturar um, vai\l"
    .string "poder contar com ele.$"

MtMoon_1F_EventScript_BaldingMan::
    msgbox MtMoon_1F_Text_BrockHelpsExcavateFossils, MSGBOX_NPC
    release
    end

MtMoon_1F_Text_BrockHelpsExcavateFossils::
    .string "Olá, estou escavando fósseis aqui sob o\n"
    .string "Mt. Moon.\p"
    .string "Às vezes, o Brock do Ginásio de Pewter me\n"
    .string "dá uma mãozinha.$"

MtMoon_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL, 1
	end

MtMoon_1F_EventScript_ItemTM09::
	finditem ITEM_TM09, 1
	end

MtMoon_1F_EventScript_ItemPotion::
	finditem ITEM_POTION, 1
	end

MtMoon_1F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	end

MtMoon_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	end

MtMoon_1F_EventScript_ItemMoonStone::
	finditem ITEM_MOON_STONE, 1
	end
