SilphCo_9F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad::
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman::
	lock
	faceplayer
	goto_if_set FLAG_SILPH_INVASION_ACTIVE SilphCo_9F_EventScript_HealWomanRocketsBack
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsBack::
	msgbox SilphCo_9F_Text_HealWomanRocketsBack
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

SilphCo_9F_Text_HealWomanRocketsBack:
	.string "Pronto para lutar?\n"
    .string "Você deveria tirar um cochilo rápido.$"

SilphCo_9F_EventScript_HealWomanRocketsGone::
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_Text_YouShouldTakeQuickNap::
    .string "Você parece cansado.\n"
    .string "Deveria tirar um cochilo rápido.$"

SilphCo_9F_Text_DontGiveUp::
    .string "Não desista!$"

SilphCo_9F_Text_ThankYouSoMuch::
    .string "Muito obrigada.$"

SilphCo_9F_Text_Grunt1Intro::
    .string "Seus Pokémon parecem te adorar,\n"
    .string "pirralho!$"

SilphCo_9F_Text_Grunt1Defeat::
    .string "Ghaaah!$"

SilphCo_9F_Text_Grunt1PostBattle::
    .string "Se eu tivesse começado como treinador\n"
    .string "na sua idade...$"

SilphCo_9F_Text_EdIntro::
    .string "Seus Pokémon têm pontos fracos!\n"
    .string "Eu vou acertá-los em cheio!$"

SilphCo_9F_Text_EdDefeat::
    .string "Você me arrasou!$"

SilphCo_9F_Text_EdPostBattle::
    .string "Explorar pontos fracos funciona mesmo.\n"
    .string "Pense nas vantagens de tipos!$"

SilphCo_9F_Text_Grunt2Intro::
    .string "Eu sou um dos quatro Irmãos Rocket!$"

SilphCo_9F_Text_Grunt2Defeat::
    .string "Warg!\n"
    .string "Irmãos, eu perdi!$"

SilphCo_9F_Text_Grunt2PostBattle::
    .string "Meus irmãos me vingarão!$"

SilphCo_9F_Text_FloorSign::
    .string "Sede da Silph S.A.\n"
    .string "9º Andar$"
