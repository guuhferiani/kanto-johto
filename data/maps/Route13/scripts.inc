Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route13_OnResume
	.byte 0

Route13_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route13_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_Text_LookToLeftOfThatPost::
    .string "Dicas para Treinadores:\p"
    .string "Olhe, olhe!\n"
    .string "Olhe para a esquerda daquele poste!$"

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_Text_SelectToSwitchItems::
    .string "Dicas para Treinadores:\p"
    .string "Use Select para trocar a posição dos itens\n"
    .string "na janela de Itens.$"

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_Text_RouteSign::
    .string "ROTA 13\n"
    .string "Norte para a Ponte do Silêncio$"

Route13_EventScript_Lola::
	trainerbattle_single TRAINER_BEAUTY_LOLA, Route13_Text_LolaIntro, Route13_Text_LolaDefeat
	msgbox Route13_Text_LolaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_LolaIntro::
    .string "Claro, eu brinco com você, gracinha.$"

Route13_Text_LolaDefeat::
    .string "Oh!\n"
    .string "Sua ferinha!$"

Route13_Text_LolaPostBattle::
    .string "Fico pensando quem é mais forte,\n"
    .string "Pokémon macho ou fêmea?$"

Route13_EventScript_Sheila::
	trainerbattle_single TRAINER_BEAUTY_SHEILA, Route13_Text_SheilaIntro, Route13_Text_SheilaDefeat
	msgbox Route13_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SheilaIntro::
    .string "Você quer ter uma batalha Pokémon\n"
    .string "comigo?$"

Route13_Text_SheilaDefeat::
    .string "Já acabou?$"

Route13_Text_SheilaPostBattle::
    .string "Na verdade, eu não entendo nada\n"
    .string "de Pokémon.\p"
    .string "Os que eu uso… eu escolhi pela\n"
    .string "aparência deles!$"

Route13_EventScript_Jared::
	trainerbattle_single TRAINER_BIKER_JARED, Route13_Text_JaredIntro, Route13_Text_JaredDefeat
	msgbox Route13_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_JaredIntro::
    .string "Tá olhando o quê?$"

Route13_Text_JaredDefeat::
    .string "Droga!\n"
    .string "Engrenagem travada!$"

Route13_Text_JaredPostBattle::
    .string "Dá o fora!$"

Route13_EventScript_Sebastian::
	trainerbattle_single TRAINER_BIRD_KEEPER_SEBASTIAN, Route13_Text_SebastianIntro, Route13_Text_SebastianDefeat
	msgbox Route13_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SebastianIntro::
    .string "Meus Pokémon pássaros querem batalhar\n"
    .string "com você!$"

Route13_Text_SebastianDefeat::
    .string "Minha combinação de Pidgey e Pidgeotto\n"
    .string "perdeu?$"

Route13_Text_SebastianPostBattle::
    .string "Meus Pokémon parecem felizes mesmo\n"
    .string "tendo perdido.$"


Route13_EventScript_Perry::
	trainerbattle_single TRAINER_BIRD_KEEPER_PERRY, Route13_Text_PerryIntro, Route13_Text_PerryDefeat
	msgbox Route13_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_PerryIntro::
    .string "Eu não vou perder.\n"
    .string "Não quando o vento sopra a meu favor!$"

Route13_Text_PerryDefeat::
    .string "O vento mudou!$"

Route13_Text_PerryPostBattle::
    .string "Fui derrotado.\n"
    .string "Acho que vou voando para casa.$"

Route13_EventScript_Robert::
	trainerbattle_single TRAINER_BIRD_KEEPER_ROBERT, Route13_Text_RobertIntro, Route13_Text_RobertDefeat
	msgbox Route13_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_RobertIntro::
    .string "Eu sempre escolho Pokémon pássaros.\n"
    .string "Eu me dediquei totalmente a eles.$"

Route13_Text_RobertDefeat::
    .string "Sem energia!$"

Route13_Text_RobertPostBattle::
    .string "Eu queria poder voar como Pidgey e\n"
    .string "Pidgeotto…$"

Route13_EventScript_Alma::
	trainerbattle_single TRAINER_PICNICKER_ALMA, Route13_Text_AlmaIntro, Route13_Text_AlmaDefeat
	msgbox Route13_Text_AlmaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_AlmaIntro::
    .string "Certa vez achei um Carboidrato em uma caverna\n"
    .string "enquanto explorava.$"

Route13_Text_AlmaDefeat::
    .string "Ah, que pena!\n"
    .string "Eu estraguei tudo!$"

Route13_Text_AlmaPostBattle::
    .string "O Carboidrato aumentou a Velocidade\n"
    .string "do meu Pokémon.$"

Route13_EventScript_Susie::
	trainerbattle_single TRAINER_PICNICKER_SUSIE, Route13_Text_SusieIntro, Route13_Text_SusieDefeat
	msgbox Route13_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SusieIntro::
    .string "Dizem que eu sou muito boa para\n"
    .string "uma criança.$"

Route13_Text_SusieDefeat::
    .string "Ohh!\n"
    .string "Eu perdi!$"

Route13_Text_SusiePostBattle::
    .string "Eu quero me tornar uma boa Treinadora.\n"
    .string "Vou treinar duro, você vai ver.$"

Route13_EventScript_Valerie::
	trainerbattle_single TRAINER_PICNICKER_VALERIE, Route13_Text_ValerieIntro, Route13_Text_ValerieDefeat
	msgbox Route13_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_ValerieIntro::
    .string "Uau!\n"
    .string "Suas Insígnias são tão legais!$"

Route13_Text_ValerieDefeat::
    .string "Não foi o bastante!$"

Route13_Text_ValeriePostBattle::
    .string "Você conseguiu essas Insígnias dos\n"
    .string "Líderes de Ginásio. Eu sei!$"

Route13_EventScript_Gwen::
	trainerbattle_single TRAINER_PICNICKER_GWEN, Route13_Text_GwenIntro, Route13_Text_GwenDefeat
	msgbox Route13_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_GwenIntro::
    .string "Meus fofos Pokémon gostariam de conhecê-lo.$"

Route13_Text_GwenDefeat::
    .string "Muito bem!\n"
    .string "Você venceu com tudo!$"

Route13_Text_GwenPostBattle::
    .string "Você tem que fazer os Pokémon batalharem\n"
    .string "para deixá-los fortes.$"
