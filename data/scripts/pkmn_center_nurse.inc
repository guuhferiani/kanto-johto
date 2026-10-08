Common_EventScript_PkmnCenterNurse::
	goto_if_set FLAG_IS_CHAMPION, EventScript_PkmnCenterNurse_ChampionHeal
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_PkmnCenterNurse_GameClearHeal
	goto EventScript_PkmnCenterNurse_NormalHeal
	end

EventScript_PkmnCenterNurse_NormalHeal::
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_WouldYouLikeToRestYourPkmn::
    .string "Olá! Bem-vindo ao\n"
    .string "Centro Pokémon.\p"
    .string "Nós recuperamos a saúde de seus\n"
    .string "Pokémon exaustos.\p"
    .string "Gostaria de descansar seus Pokémon?$"

EventScript_PkmnCenterNurse_GameClearHeal::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_YouWantTheUsual::
    .string "Que bom ver você, {PLAYER}!\n"
    .string "Vai querer o de sempre, certo?$"

EventScript_PkmnCenterNurse_ChampionHeal::
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	playse SE_PIN
	msgbox gText_ItsTheChampion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_ItsTheChampion::
    .string "Oh! É o Campeão, {PLAYER}!\n"
    .string "Vamos cuidar dos seus Pokémon?$"

EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message gText_IllTakeYourPkmn
	waitmessage
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	call_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye

gText_IllTakeYourPkmn::
    .string "Certo, vou cuidar dos seus\n"
    .string "Pokémon por alguns segundos.$"

gText_RestoredPkmnToFullHealth::
    .string "Obrigada por esperar.\p"
    .string "Seus Pokémon estão totalmente\n"
    .string "recuperados.$"

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	return

EventScript_PkmnCenterNurse_ExplainPokerus::
	msgbox gText_PokerusExplanation, MSGBOX_DEFAULT
	setflag FLAG_POKERUS_EXPLAINED
	return

gText_PokerusExplanation::
	.string "Seus Pokémon parecem estar infectados\n"
	.string "com Pokérus.\p"
	.string "Pouco se sabe sobre o Pokérus,\n"
	.string "além de serem formas de vida microscópicas\l"
	.string "que se fixam aos Pokémon.\p"
	.string "Enquanto infectados, dizem que os\n"
	.string "Pokémon se desenvolvem muito melhor.$"

gText_WeHopeToSeeYouAgain::
    .string "Esperamos vê-lo novamente!$"

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

EventScript_PkmnCenterNurse_Goodbye::
	msgbox gText_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end
