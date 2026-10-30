BlackthornCity_MapScripts::
	.byte 0

BlackthornCity_EventScript_DragonTamer::
	msgbox BlackthornCity_Text_DragonTamer, MSGBOX_NPC
	end

BlackthornCity_EventScript_MtSilverGuard::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_ALL_JOHTO_LEADERS, BlackthornCity_EventScript_MtSilverLocked
	msgbox BlackthornCity_Text_AskMtSilver, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BlackthornCity_EventScript_MtSilverDecline
	msgbox BlackthornCity_Text_GoingMtSilver, MSGBOX_DEFAULT
	warp MAP_MT_SILVER, 4, 7
	waitstate
	release
	end

BlackthornCity_EventScript_MtSilverLocked::
	msgbox BlackthornCity_Text_MtSilverLocked, MSGBOX_DEFAULT
	release
	end

BlackthornCity_EventScript_MtSilverDecline::
	msgbox BlackthornCity_Text_MtSilverDecline, MSGBOX_DEFAULT
	release
	end

BlackthornCity_EventScript_ItemDragonScale::
	finditem ITEM_DRAGON_SCALE, 1
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCity_Text_CitySign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornCity_Text_GymSign, MSGBOX_SIGN
	end

BlackthornCity_Text_DragonTamer::
	.string "Esta é Blackthorn City, a cidade\n"
	.string "dos lendários domadores de Dragão!\p"
	.string "A caverna a noroeste é o santuário\n"
	.string "Dragon's Den, e o Ginásio de Clair\l"
	.string "fica logo ao lado do Centro Pokémon!$"

BlackthornCity_Text_MtSilverLocked::
	.string "Guarda de Elite: Esta passagem nas\n"
	.string "montanhas leva diretamente ao cume\l"
	.string "do Monte Silver!\p"
	.string "Derrote todos os 8 Líderes de\n"
	.string "Ginásio de Johto para liberar o\l"
	.string "acesso ao duelo contra Red!$"

BlackthornCity_Text_AskMtSilver::
	.string "Guarda de Elite: Você conquistou\n"
	.string "todas as 8 Insígnias de Johto!\p"
	.string "Deseja subir agora mesmo para o\n"
	.string "cume do Monte Silver, onde o\l"
	.string "Campeão Red o aguarda?$"

BlackthornCity_Text_GoingMtSilver::
	.string "Que a sorte esteja com você no\n"
	.string "Monte Silver, Campeão {PLAYER}!$"

BlackthornCity_Text_MtSilverDecline::
	.string "Prepare bem sua equipe antes de\n"
	.string "subir ao Monte Silver!$"

BlackthornCity_Text_CitySign::
	.string "BLACKTHORN CITY\n"
	.string "Um Retiro Silencioso nas Montanhas!\l"
	.string "Noroeste: Dragon's Den & Monte Silver$"

BlackthornCity_Text_GymSign::
	.string "GINÁSIO POKÉMON DE BLACKTHORN CITY\n"
	.string "Líder: Clair\l"
	.string "A Abençoada Usuária de Pokémon Dragão!$"
