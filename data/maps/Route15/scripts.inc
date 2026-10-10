Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route15_OnResume
	.byte 0

Route15_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route15_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route15_EventScript_Olivia::
	trainerbattle_single REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1, Route15_Text_OliviaIntro, Route15_Text_OliviaDefeat, Route15_EventScript_RegisterOliviaAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_OliviaRematch
	msgbox Route15_Text_OliviaPostBattle, MSGBOX_DEFAULT
	release
	end

Route15_Text_OliviaIntro::
    .string "Eu treino Pokémon para proteção\n"
    .string "porque moro sozinha.$"

Route15_Text_OliviaDefeat::
    .string "Para mim, Pokémon não é uma questão\n"
    .string "de ganhar ou perder.$"

Route15_Text_OliviaPostBattle::
    .string "Adoro quando meus Pokémon me recebem\n"
    .string "quando chego em casa.\p"
    .string "É tão reconfortante.$"

Route15_EventScript_RegisterOliviaAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_OliviaRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1
	release
	end

Route15_Text_OliviaRegister:
	.string "Pode me passar seu número?\p"
	.string "Eu poderia te ligar se precisar\n"
	.string "de mais proteção.$"

Route15_EventScript_OliviaRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1, Route15_Text_OliviaRematchIntro, Route15_Text_OliviaDefeat
	msgbox Route15_Text_OliviaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_OliviaRematchIntro::
	.string "Ainda moro sozinha, então preciso\n"
	.string "treinar meus Pokémon para me protegerem.$"

Route15_Text_OliviaRematchPostBattle::
	.string "Talvez eu deva procurar outro lugar...$"

Route15_EventScript_Grace::
	trainerbattle_single TRAINER_BEAUTY_GRACE, Route15_Text_GraceIntro, Route15_Text_GraceDefeat
	msgbox Route15_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_GraceIntro::
    .string "Ah, você é uma fofura!\n"
    .string "Igualzinho a um lindo Pokémon!$"

Route15_Text_GraceDefeat::
    .string "Você parecia tão fofinho também!$"

Route15_Text_GracePostBattle::
    .string "Eu te perdoo.\n"
    .string "Eu aguento firme.\l"
    .string "Já sou uma garota crescida.$"

Route15_EventScript_Ernest::
	trainerbattle_single TRAINER_BIKER_ERNEST, Route15_Text_ErnestIntro, Route15_Text_ErnestDefeat
	msgbox Route15_Text_ErnestPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_ErnestIntro::
    .string "Ei, pirralho! Vamos lá!\n"
    .string "Acabei de surrupiar estes de um perdedor!$"

Route15_Text_ErnestDefeat::
    .string "Por que não?!$"

Route15_Text_ErnestPostBattle::
    .string "A vida é curta demais.\n"
    .string "É maneiro viver como um fora da lei.\l"
    .string "A Equipe Rocket manda ver!$"

Route15_EventScript_Alex::
	trainerbattle_single TRAINER_BIKER_ALEX, Route15_Text_AlexIntro, Route15_Text_AlexDefeat
	msgbox Route15_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_AlexIntro::
    .string "Passe toda a sua grana quando\n"
    .string "perder para mim, pirralho!$"

Route15_Text_AlexDefeat::
    .string "Não pode ser verdade!$"

Route15_Text_AlexPostBattle::
    .string "Eu estava só brincando sobre a grana.\n"
    .string "Não me leve tão a sério.$"

Route15_EventScript_Edwin::
	trainerbattle_single TRAINER_BIRD_KEEPER_EDWIN, Route15_Text_EdwinIntro, Route15_Text_EdwinDefeat
	msgbox Route15_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_EdwinIntro::
    .string "Quando assobio, consigo chamar\n"
    .string "Pokémon pássaro.$"

Route15_Text_EdwinDefeat::
    .string "Ai!\n"
    .string "Que tragédia!$"

Route15_Text_EdwinPostBattle::
    .string "Talvez eu não tenha nascido para batalhas.\n"
    .string "Acho que não faço o tipo certo.$"

Route15_EventScript_Chester::
	trainerbattle_single TRAINER_BIRD_KEEPER_CHESTER, Route15_Text_ChesterIntro, Route15_Text_ChesterDefeat
	msgbox Route15_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_ChesterIntro::
    .string "Hmm? Meus pássaros estão tremendo!\n"
    .string "Você é bom mesmo, não é?$"

Route15_Text_ChesterDefeat::
    .string "Exatamente como imaginei!$"

Route15_Text_ChesterPostBattle::
    .string "Isso é óbvio, você já deve saber,\n"
    .string "mas mesmo assim…\p"
    .string "Golpes como Terremoto e Fissura\n"
    .string "não têm efeito em Pokémon pássaro.$"

Route15_EventScript_Yazmin::
	trainerbattle_single TRAINER_PICNICKER_YAZMIN, Route15_Text_YazminIntro, Route15_Text_YazminDefeat
	msgbox Route15_Text_YazminPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_YazminIntro::
    .string "Quer brincar com meus Pokémon?$"

Route15_Text_YazminDefeat::
    .string "Fui impaciente demais!$"

Route15_Text_YazminPostBattle::
    .string "Vou treinar com pessoas mais fracas.$"

Route15_EventScript_Kindra::
	trainerbattle_single TRAINER_PICNICKER_KINDRA, Route15_Text_KindraIntro, Route15_Text_KindraDefeat
	msgbox Route15_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_KindraIntro::
    .string "Acabei de receber alguns Pokémon por troca.\n"
    .string "Posso testá-los em você?$"

Route15_Text_KindraDefeat::
    .string "Não foi bom o bastante!$"

Route15_Text_KindraPostBattle::
    .string "Você não pode mudar o apelido de\n"
    .string "um Pokémon recebido por troca.\p"
    .string "Apenas o Treinador Original consegue\n"
    .string "mudar o apelido dele.$"

Route15_EventScript_Becky::
	trainerbattle_single TRAINER_PICNICKER_BECKY, Route15_Text_BeckyIntro, Route15_Text_BeckyDefeat
	msgbox Route15_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_BeckyIntro::
    .string "Você parece dócil, então acho que\n"
    .string "consigo te vencer.\p"
    .string "Vou tentar!$"

Route15_Text_BeckyDefeat::
    .string "Não, deu tudo errado!$"

Route15_Text_BeckyPostBattle::
    .string "Tenho medo de Motoqueiros. Eles são\n"
    .string "tão feios e malvados!$"

Route15_EventScript_Celia::
	trainerbattle_single TRAINER_PICNICKER_CELIA, Route15_Text_CeliaIntro, Route15_Text_CeliaDefeat
	msgbox Route15_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_CeliaIntro::
    .string "O que está na moda e bombando?\n"
    .string "Trocar Pokémon!$"

Route15_Text_CeliaDefeat::
    .string "Eu falei troca!$"

Route15_Text_CeliaPostBattle::
    .string "Eu troco Pokémon com meus amigos\n"
    .string "o tempo todo.$"

Route15_EventScript_Mya::
	trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_MyaIntro, Route15_Text_MyaDefeat, Route15_Text_MyaNotEnoughMons
	msgbox Route15_Text_MyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_MyaIntro::
    .string "Mya: Você é perfeito.\n"
    .string "Ajude-me a treinar meu irmãozinho?$"

Route15_Text_MyaDefeat::
    .string "Mya: Ron, você tem que focar!\n"
    .string "Concentre-se no que está fazendo!$"

Route15_Text_MyaPostBattle::
    .string "Mya: Certo, vamos pegar mais pesado.\n"
    .string "Vou adicionar exercícios à nossa rotina!$"

Route15_Text_MyaNotEnoughMons::
    .string "Mya: Quer nos desafiar?\n"
    .string "Você vai precisar de dois Pokémon, no entanto.$"

Route15_EventScript_Ron::
	trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_RonIntro, Route15_Text_RonDefeat, Route15_Text_RonNotEnoughMons
	msgbox Route15_Text_RonPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_RonIntro::
    .string "Ron: Minha irmã fica assustadora\n"
    .string "quando nós perdemos.$"

Route15_Text_RonDefeat::
    .string "Ron: Ah, não, não…\n"
    .string "Maninha, me desculpa!$"

Route15_Text_RonPostBattle::
    .string "Ron: Ah, droga…\n"
    .string "Queria ter uma irmã boazinha…$"

Route15_Text_RonNotEnoughMons::
    .string "Ron: Você queria batalhar contra a\n"
    .string "minha irmã e eu?\p"
    .string "Então você precisa de dois Pokémon.$"

Route15_EventScript_RouteSign::
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end

Route15_Text_RouteSign::
    .string "Rota 15\n"
    .string "Oeste para Cidade de Fuchsia$"

Route15_EventScript_ItemTM18::
	finditem ITEM_TM18, 1
	release
	end

//Route15_Text_HiIAmConan:
    //.string "Hi there! I'm Conan!\p"
    //.string "My Omastar is so cool!\n"
    //.string "Come back later to play with me!$"
   // return

Route15_EventScript_SchoolKidConan::
	trainerbattle_single TRAINER_SCHOOLKID_CONAN, Route15_Text_ConanIntro, Route15_Text_ConanDefeat
	msgbox Route15_Text_ConanPostBattle MSGBOX_AUTOCLOSE
	releaseall
	end

Route15_Text_ConanIntro:
	.string "Espero que você esteja pronto!$"

Route15_Text_ConanDefeat:
	.string "Uau!$"

Route15_Text_ConanPostBattle:
	.string "Obrigado por brincar com a gente!$"
    

