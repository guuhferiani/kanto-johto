SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_WelcomePresidentInBoardroom::
    .string "Bem-vindo.\p"
    .string "O Presidente está na sala de\n"
    .string "reuniões no 11º andar.$"

SilphCo_1F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "1º Andar$"


SilphCo_1F_EventScript_PostgameGrunt1::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_1, SilphCo_1F_Text_PostgameGrunt1Intro, SilphCo_1F_Text_PostgameGrunt1Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt1Intro::
    .string "A Equipe Rocket voltou, bebê!$"

SilphCo_1F_Text_PostgameGrunt1Defeat::
    .string "Derrubado no meu auge!$"

SilphCo_1F_Text_PostgameGrunt1PostBattle::
    .string "Estamos aqui para terminar o que\n"
    .string "Giovanni começou.$"

SilphCo_1F_EventScript_PostgameGrunt2::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_2, SilphCo_1F_Text_PostgameGrunt2Intro, SilphCo_1F_Text_PostgameGrunt2Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt2Intro::
    .string "Diferente de outros covardes, nós não\n"
    .string "fugimos quando Giovanni foi derrotado\l"
    .string "na cidade de Viridian.$"

SilphCo_1F_Text_PostgameGrunt2Defeat::
    .string "Talvez eu deva desistir...$"

SilphCo_1F_Text_PostgameGrunt2PostBattle::
    .string "Eu nunca vou desistir!\n"
    .string "Equipe Rocket para sempre!$"

SilphCo_1F_EventScript_PostgameGrunt3::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_3, SilphCo_1F_Text_PostgameGrunt3Intro, SilphCo_1F_Text_PostgameGrunt3Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt3Intro::
    .string "Passe todo o seu dinheiro!$"

SilphCo_1F_Text_PostgameGrunt3Defeat::
    .string "Estamos falidos!$"

SilphCo_1F_Text_PostgameGrunt3PostBattle::
    .string "O novo chefe não quer admitir,\n"
    .string "mas a Equipe Rocket está por um fio.\p"
    .string "Precisamos que este trabalho dê certo!$"
