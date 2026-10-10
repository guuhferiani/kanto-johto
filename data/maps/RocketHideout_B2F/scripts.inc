RocketHideout_B2F_MapScripts::
	.byte 0

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntIntro::
    .string "É isso mesmo, nós matamos a mãe daquele\n"
    .string "Cubone. E o que você tem a ver com isso, pirralho?$"

RocketHideout_B2F_Text_GruntDefeat::
    .string "Eu me rendo!$"

RocketHideout_B2F_Text_GruntPostBattle::
    .string "A base da Equipe Rocket tem quatro\n"
    .string "andares subterrâneos.\p"
    .string "Acha mesmo que consegue alcançar o Chefe?$"

RocketHideout_B2F_EventScript_ItemXSpeed::
    finditem ITEM_X_SPEED, 1
    release
    end

RocketHideout_B2F_EventScript_ItemTM12::
    finditem ITEM_TM12, 1
    release
    end

RocketHideout_B2F_EventScript_ItemMoonStone::
    finditem ITEM_MOON_STONE, 1
    release
    end

RocketHideout_B2F_EventScript_ItemSuperPotion::
    finditem ITEM_SUPER_POTION, 1
    release
    end
