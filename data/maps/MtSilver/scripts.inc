MtSilver_MapScripts::
	.byte 0

MtSilver_EventScript_Red::
	lock
	faceplayer
	msgbox MtSilver_Text_RedEllipsis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CHAMPION_RED, MtSilver_Text_RedDefeat
	setflag FLAG_DEFEATED_CHAMPION_RED
	goto_if_set FLAG_GOT_RED_REWARD, MtSilver_EventScript_RedAfterReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox MtSilver_Text_SupremeChampion, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_MASTER_BALL, 1
	giveitem ITEM_ABILITY_PATCH, 1
	giveitem ITEM_MAX_CANDY, 10
	setflag FLAG_GOT_RED_REWARD
	msgbox MtSilver_Text_RedSilentRespect, MSGBOX_DEFAULT
	release
	end

MtSilver_EventScript_RedAfterReward::
	msgbox MtSilver_Text_RedSilentRespect, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

MtSilver_EventScript_ReturnGuide::
	lock
	faceplayer
	special HealPlayerParty
	msgbox MtSilver_Text_HealedAndAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtSilver_EventScript_StayOnSummit
	msgbox MtSilver_Text_ReturningToRoute27, MSGBOX_DEFAULT
	warp MAP_ROUTE27, 14, 8
	waitstate
	release
	end

MtSilver_EventScript_StayOnSummit::
	msgbox MtSilver_Text_StayOnSummit, MSGBOX_DEFAULT
	release
	end

MtSilver_Text_RedEllipsis::
	.string "Red: ...\p"
	.string "... ... ...!$"

MtSilver_Text_RedDefeat::
	.string "... ... ...!$"

MtSilver_Text_SupremeChampion::
	.string "Parabéns, {PLAYER}!\n"
	.string "Você derrotou a lenda viva Red no\l"
	.string "cume do Monte Silver e se tornou o\l"
	.string "Campeão Supremo de Kanto e Johto!$"

MtSilver_Text_RedSilentRespect::
	.string "Red observa você com um sorriso\n"
	.string "silencioso de profundo respeito.\p"
	.string "Você pode desafiá-lo novamente\n"
	.string "sempre que quiser testar seu\l"
	.string "poder no Monte Silver!$"

MtSilver_Text_HealedAndAskReturn::
	.string "Guarda do Monte Silver: Seus\n"
	.string "Pokémon foram totalmente curados!\p"
	.string "Deseja retornar para a fronteira\n"
	.string "na Rota 27 agora (ou sair pela\l"
	.string "caverna rumo a Blackthorn City)?$"

MtSilver_Text_ReturningToRoute27::
	.string "Descendo a montanha rumo à\n"
	.string "Rota 27!$"

MtSilver_Text_StayOnSummit::
	.string "Boa sorte contra a lenda no\n"
	.string "cume do Monte Silver!$"
