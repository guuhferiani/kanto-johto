.set LOCALID_BELT, 9

SaffronCity_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Dojo_OnTransition
	.byte 0

SaffronCity_Dojo_OnTransition::
	call_if_unset FLAG_DAILY_DOJO_RESET, SaffronCity_Dojo_Reset
	end

SaffronCity_Dojo_Reset::
	cleartrainerflag SPARRING_PARTNER_ATTACK
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPEED
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_HP
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	clearflag FLAG_DOJO_SPDEFENSE
	setflag FLAG_DAILY_DOJO_RESET
	return

SaffronCity_Dojo_OffenseMaster::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_IAmTheOffenseMaster, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_TrainWithMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_1, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_2, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_3, SaffronCity_Dojo_EventScript_DefeatMyPupils
	msgbox SaffronCityDojo_Text_ProvedYourselfOffensive, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	givemon SPECIES_HITMONCHAN, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonchanParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonchanPC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

SaffronCity_Dojo_Text_IAmTheOffenseMaster::
	.string "Eu sou o Mestre do Ataque.\p"
	.string "Meus pupilos dominaram a arte\n"
	.string "ofensiva, e seus Pokémon\l"
	.string "refletem isso.$"

SaffronCity_Dojo_EventScript_DefeatMyPupils::
	msgbox SaffronCity_Dojo_Text_DefeatThemAll, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_DefeatThemAll::
	.string "Se você derrotar todos os meus\n"
	.string "pupilos, eu lhe darei um\l"
	.string "Pokémon especial de presente!$"

SaffronCity_Dojo_TrainWithMyPupils::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsOffense, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsOffense::
	.string "Se treinar com meus pupilos, você\n"
	.string "também dominará a arte do Ataque.\p"
	.string "Você pode treinar com eles todo dia,\n"
	.string "mas eles precisam descansar.\p"
	.string "Manter-se hidratado é essencial\n"
	.string "para o treinamento.$"

SaffronCityDojo_Text_ProvedYourselfOffensive::
	.string "Então você derrotou todos os pupilos.\p"
	.string "Vejo que provou ser capaz de\n"
	.string "resistir ao mais forte ataque!\p"
	.string "Por isso, você conquistou este\n"
	.string "Pokémon... Hitmonchan!$"

SaffronCity_Dojo_EventScript_HitmonchanParty::
	call SaffronCity_Dojo_EventScript_GetHitmonchan
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_GotHitmonchan
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_GotHitmonchan
	end

SaffronCity_Dojo_EventScript_GetHitmonchan::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_EventScript_Text_EarnedHitmonchan
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HITMONCHAN
	return

SaffronCity_Dojo_EventScript_Text_EarnedHitmonchan::
	.string "{PLAYER} dominou a arte do Ataque\n"
	.string "e ganhou o Hitmonchan do Dojô!$"

SaffronCity_Dojo_EventScript_GotHitmonchan::
	setflag FLAG_RECEIVED_HITMONCHAN
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonchanPC::
	call SaffronCity_Dojo_EventScript_GetHitmonchan
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferHitmonchan
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferHitmonchan
	end

SaffronCity_Dojo_EventScript_TransferHitmonchan::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_GotHitmonchan
	end

SaffronCity_Dojo_DefenseMaster::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_IAmTheDefenseMaster, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_TrainWithMyPupilsDefense
	goto_if_unset FLAG_DOJO_DEFENSE_1, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_DEFENSE_2, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_DEFENSE_3, SaffronCity_Dojo_EventScript_DefeatMyPupils
	msgbox SaffronCityDojo_Text_ProvedYourselfDefensive, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	givemon SPECIES_HITMONLEE, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonleeParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonleePC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

SaffronCity_Dojo_Text_IAmTheDefenseMaster::
	.string "Eu sou o Mestre da Defesa.\p"
	.string "Meus pupilos dominaram a arte\n"
	.string "defensiva, e seus Pokémon\l"
	.string "refletem isso.$"

SaffronCity_Dojo_TrainWithMyPupilsDefense::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsDefense, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsDefense::
	.string "Se treinar com meus pupilos, você\n"
	.string "também dominará a arte da Defesa.\p"
	.string "Você pode treinar com eles todo dia,\n"
	.string "mas eles precisam descansar.\p"
	.string "Manter-se hidratado também é\n"
	.string "essencial para o treinamento.$"

SaffronCityDojo_Text_ProvedYourselfDefensive::
	.string "Então você derrotou todos os pupilos.\p"
	.string "Vejo que provou ser capaz de quebrar\n"
	.string "a mais impenetrável defesa!\p"
	.string "Por isso, você conquistou este\n"
	.string "Pokémon... Hitmonlee!$"

SaffronCity_Dojo_EventScript_HitmonleeParty::
	call SaffronCity_Dojo_EventScript_GetHitmonlee
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_GotHitmonlee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_GotHitmonlee
	end

SaffronCity_Dojo_EventScript_GetHitmonlee::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_EventScript_Text_EarnedHitmonlee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HITMONLEE
	return

SaffronCity_Dojo_EventScript_Text_EarnedHitmonlee::
	.string "{PLAYER} dominou a arte da Defesa\n"
	.string "e ganhou o Hitmonlee do Dojô!$"

SaffronCity_Dojo_EventScript_GotHitmonlee::
	setflag FLAG_RECEIVED_HITMONLEE
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleePC::
	call SaffronCity_Dojo_EventScript_GetHitmonlee
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferHitmonlee
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferHitmonlee
	end

SaffronCity_Dojo_EventScript_TransferHitmonlee::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_GotHitmonlee
	end

SaffronCity_Dojo_EventScript_NoRoomForPokemon::
	msgbox SaffronCity_Dojo_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_NoRoomForMorePokemon::
    .string "Oh! Você não tem espaço\n"
    .string "para mais nenhum Pokémon!$"

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_FightingDojo::
    .string "Dojô de Luta$"

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_StrongOffense, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_StrongOffense::
    .string "Um ataque poderoso é\n"
    .string "a chave para a vitória!$"

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_StrongDefense, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_StrongDefense::
    .string "Uma defesa sólida é\n"
    .string "a chave para a sobrevivência!$"


SaffronCity_Dojo_EventScript_FreshWater::
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	removeitem ITEM_FRESH_WATER
	return

SaffronCity_Dojo_EventScript_CouldUseADrink::
	msgbox SaffronCity_Dojo_Text_CouldUseADrink, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_SureAmThirsty:
	.string "Treinar Pokémon é exaustivo!\p"
	.string "Preciso me refrescar antes de\n"
	.string "poder lutar outra rodada...$"

SaffronCity_Dojo_Text_CanIHaveThat:
	.string "Oh! Você tem uma Água Fresca!\p"
	.string "Poderia me dar um pouco?$"

SaffronCity_Dojo_Text_CouldUseADrink:
	.string "Eu realmente preciso de algo\n"
	.string "para beber...$"

SaffronCity_Dojo_Text_HitsThatSpot:
	.string "Uau, obrigado!\p"
	.string "GLUB GLUB GLUB$"

SaffronCity_Dojo_Text_AhhMuchBetter:
	.string "Ahhhhhhh....\p"
	.string "Isso caiu muito bem!\p"
	.string "Sinto-me pronto para outra batalha!$"

SaffronCity_Dojo_EventScript_BattleLater::
	msgbox SaffronCity_Dojo_Text_BattleLater, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_PupilIntro:
	.string "Muito bem! Mostrarei o que\n"
	.string "meu sensei me ensinou!$"

SaffronCity_Dojo_Text_PupilDefeat:
	.string "Não fui páreo para você.$"

SaffronCity_Dojo_Text_AGoodWorkout:
	.string "Ainda tenho muito a aprender.\n"
	.string "Esse foi um ótimo treino.$"

SaffronCity_Dojo_Text_AttackPupil:
	.string "Estou estudando os caminhos do\n"
	.string "Mestre do Ataque!\p"
	.string "Ataques físicos são os golpes mais\n"
	.string "poderosos, e serei o mais forte\l"
	.string "de toda Kanto!\p"
	.string "Deseja me desafiar?$"	

SaffronCity_Dojo_Text_DefensePupil:
	.string "Estou estudando os caminhos do\n"
	.string "Mestre da Defesa!\p"
	.string "Ataques físicos nem sequer quebram\n"
	.string "minha defesa, e serei o mais\l"
	.string "forte de toda Kanto!\p"
	.string "Deseja me desafiar?$"	

SaffronCity_Dojo_Text_SpAttackPupil:
	.string "Estou estudando os caminhos do\n"
	.string "Mestre do Ataque!\p"
	.string "Ataques especiais são os golpes\n"
	.string "mais poderosos, e serei o mais\l"
	.string "forte de toda Kanto!\p"
	.string "Deseja me desafiar?$"

SaffronCity_Dojo_Text_SpDefensePupil:
	.string "Estou estudando os caminhos do\n"
	.string "Mestre da Defesa!\p"
	.string "Ataques especiais nem sequer quebram\n"
	.string "minha defesa, e serei o mais\l"
	.string "forte de toda Kanto!\p"
	.string "Deseja me desafiar?$"	

SaffronCity_Dojo_Text_SpeedPupil:
	.string "Estou estudando os caminhos do\n"
	.string "Mestre do Ataque!\p"
	.string "A velocidade é o fator mais\n"
	.string "importante em batalha, e serei\l"
	.string "o mais forte de toda Kanto!\p"
	.string "Deseja me desafiar?$"	

SaffronCity_Dojo_Text_HpPupil:
	.string "Estou estudando os caminhos do\n"
	.string "Mestre da Defesa!\p"
	.string "Ter mais HP que o oponente é o\n"
	.string "fator mais importante em batalha,\l"
	.string "e serei o mais forte de toda Kanto!\p"
	.string "Deseja me desafiar?$"	
	
SaffronCity_Dojo_Text_BattleLater:
	.string "Se deseja se tornar o melhor,\n"
	.string "precisa se esforçar para isso!$"

SaffronCity_Dojo_EventScript_AttackPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_ATTACK, SaffronCity_Dojo_EventScript_AttackPupilThirsty
	msgbox SaffronCity_Dojo_Text_AttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_ATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpAttackPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPATTACK, SaffronCity_Dojo_EventScript_SpAttackPupilThirsty
	msgbox SaffronCity_Dojo_Text_SpAttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpeedPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPEED, SaffronCity_Dojo_EventScript_SpeedPupilThirsty
	msgbox SaffronCity_Dojo_Text_SpeedPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPEED, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSpeed
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_DefensePupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_DEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	msgbox SaffronCity_Dojo_Text_DefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_DEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpDefensePupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPDEFENSE, SaffronCity_Dojo_EventScript_SpDefensePupilThirsty
	msgbox SaffronCity_Dojo_Text_SpDefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPDEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_HpPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_HP, SaffronCity_Dojo_EventScript_HpPupilThirsty
	msgbox SaffronCity_Dojo_Text_HpPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_HP, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledHP
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_AttackPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_ATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	playbgm MUS_B_DOME, 0
	msgbox SaffronCity_Dojo_Text_AhhMuchBetter, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpAttackPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	playbgm MUS_B_DOME, 0
	msgbox SaffronCity_Dojo_Text_AhhMuchBetter, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpeedPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_SPEED
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	playbgm MUS_B_DOME, 0
	msgbox SaffronCity_Dojo_Text_AhhMuchBetter, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_DefensePupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	playbgm MUS_B_DOME, 0
	msgbox SaffronCity_Dojo_Text_AhhMuchBetter, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpDefensePupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPDEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	playbgm MUS_B_DOME, 0
	msgbox SaffronCity_Dojo_Text_AhhMuchBetter, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_HpPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_HP
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	playbgm MUS_B_DOME, 0
	msgbox SaffronCity_Dojo_Text_AhhMuchBetter, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_BattledAttack::
	setflag FLAG_DOJO_ATTACK
	setflag FLAG_DOJO_OFFENSE_1
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPAttack::
	setflag FLAG_DOJO_SPATTACK
	setflag FLAG_DOJO_OFFENSE_2
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSpeed::
	setflag FLAG_DOJO_SPEED
	setflag FLAG_DOJO_OFFENSE_3
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledDefense::
	setflag FLAG_DOJO_DEFENSE
	setflag FLAG_DOJO_DEFENSE_1
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPDefense::
	setflag FLAG_DOJO_SPDEFENSE
	setflag FLAG_DOJO_DEFENSE_2
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledHP::
	setflag FLAG_DOJO_HP
	setflag FLAG_DOJO_DEFENSE_3
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_ExpertBelt::
	msgbox SaffronCity_Dojo_Text_ExpertBelt, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_Unworthy
	goto_if_unset FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_Unworthy
	giveitem ITEM_EXPERT_BELT
	removeobject LOCALID_BELT
	release
	end

SaffronCity_Dojo_Text_ExpertBelt::
	.string "Este cinto prova que você é\n"
	.string "um mestre em batalhas Pokémon.$"

SaffronCity_Dojo_Unworthy::
	msgbox SaffronCity_Dojo_Text_Unworthy, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_Unworthy::
	.string "Você não se sente digno disso.$"

