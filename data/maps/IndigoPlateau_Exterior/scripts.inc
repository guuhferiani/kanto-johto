IndigoPlateau_Exterior_MapScripts::
	.byte 0

IndigoPlateau_Exterior_EventScript_Charizard::
	lock
	faceplayer
    playmoncry SPECIES_CHARIZARD, CRY_MODE_ENCOUNTER
    waitmoncry
    delay 20
    goto_if_set FLAG_DEFEATED_NICK, IndigoPlateau_Exterior_EventScript_CharizardDefeated
	msgbox IndigoPlateau_Exterior_Text_Charizard MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_Text_Charizard:
	.string "Charizard bufa enquanto encara.$"

IndigoPlateau_Exterior_EventScript_DragonTamerNick::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_NICK, IndigoPlateau_Exterior_EventScript_MegaHintCharizard
	trainerbattle_single TRAINER_DRAGONTAMER_NICK, IndigoPlateau_Exterior_Text_NickIntro, IndigoPlateau_Exterior_Text_NickDefeat
	setflag FLAG_DEFEATED_NICK
	msgbox IndigoPlateau_Exterior_Text_NickPostBattle MSGBOX_AUTOCLOSE
	release
	end

IndigoPlateau_Exterior_Text_NickIntro:
	.string "Que otimo! Um treino!$"

IndigoPlateau_Exterior_Text_NickDefeat:
	.string "Ha ha, sim!$"

IndigoPlateau_Exterior_Text_NickPostBattle:
	.string "Agora estou pegando fogo!$"

IndigoPlateau_Exterior_EventScript_MegaHintCharizard::    
    goto_if_set FLAG_GOT_CHARIZARDITE_X, IndigoPlateau_Exterior_EventScript_NickDefeated
    msgbox IndigoPlateau_Exterior_Text_CharizardMegaHint MSGBOX_DEFAULT
    waitmessage
    release
    end
    
IndigoPlateau_Exterior_Text_CharizardMegaHint:
    .string "Se quiser um Charizard tao impressionante\n"
	.string "quanto o meu, busque na Mansao Pokemon.$"

IndigoPlateau_Exterior_EventScript_NickDefeated::
    msgbox NickDefeated_Text MSGBOX_DEFAULT
	release
	end

NickDefeated_Text:	
	.string "A chama do meu Charizard queima tao\n"
	.string "forte que ele consegue nadar sem a\l"
	.string "cauda se apagar!$"

IndigoPlateau_Exterior_EventScript_CharizardDefeated::
	msgbox CharizardDefeated MSGBOX_DEFAULT
	release
	end

CharizardDefeated:	
	.string "Charizard parece irritado com voce.\n"
	.string "Ele balanca a cauda, soltando fumaca.$"
