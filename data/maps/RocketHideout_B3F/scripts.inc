RocketHideout_B3F_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
    .string "Pare de se meter nos assuntos da\n"
    .string "Equipe Rocket, senão vai ver só!$"

RocketHideout_B3F_Text_Grunt1Defeat::
    .string "Ugh!\n"
    .string "Fui derrotado!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
    .string "Cubone?\n"
    .string "Ah, aquele Pokémon que roubamos.\p"
    .string "Ele está em algum lugar por aqui.$"

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt2Intro::
    .string "Ficamos sabendo lá de cima que você\n"
    .string "estava vindo!$"

RocketHideout_B3F_Text_Grunt2Defeat::
    .string "O quê?\n"
    .string "Eu perdi? Não!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
    .string "Pode ir em frente!\p"
    .string "Mas você não vai conseguir usar o elevador\n"
    .string "sem a Chave do Elevador.$"

RocketHideout_B3F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

RocketHideout_B3F_EventScript_ItemTM21::
	finditem ITEM_TM21, 1
	release
	end

RocketHideout_B3F_EventScript_ItemBlackGlasses::
	finditem ITEM_BLACK_GLASSES, 1
	release
	end
