Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route3_OnResume
	.byte 0

Route3_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route3_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route3_EventScript_Youngster::
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_Text_TunnelFromCeruleanTiring::
    .string "Ufa… É melhor eu descansar um pouco…\n"
    .string "Ai, ai…\p"
    .string "Aquele túnel vindo de Cerulean exige\n"
    .string "muito de você!$"

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_Text_RouteSign::
    .string "Rota 3\n"
    .string "Mt. Moon à frente$"

Route3_EventScript_Janice::
	trainerbattle_single REMATCHABLE_TRAINER_LASS_JANICE_1, Route3_Text_JaniceIntro, Route3_Text_JaniceDefeat, Route3_EventScript_RegisterJaniceAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_JaniceRematch
	msgbox Route3_Text_JanicePostBattle, MSGBOX_DEFAULT
	release
	end

Route3_Text_JaniceIntro::
    .string "Com licença!\n"
    .string "Você olhou para mim, não olhou?$"

Route3_Text_JaniceDefeat::
    .string "Que maldade!$"

Route3_Text_JanicePostBattle::
    .string "Você não deveria ficar encarando se não\n"
    .string "quiser batalhar!$"

Route3_EventScript_RegisterJaniceAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_JaniceRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_LASS_JANICE_1
	release
	end

Route3_Text_JaniceRegister:
	.string "Eu odeio perder!\n"
	.string "Vamos ter uma revanche qualquer dia desses.$"

Route3_EventScript_JaniceRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_LASS_JANICE_1, Route3_Text_JaniceRematchIntro, Route3_Text_JaniceDefeat
	msgbox Route3_Text_JaniceRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JaniceRematchIntro::
	.string "Com licença!\n"
	.string "Você continua olhando para mim, não é?$"

Route3_Text_JaniceRematchPostBattle::
	.string "Eu odeio treinadores maldosos como você!\n"
	.string "Vou te dar uma lição qualquer dia!$"


Route3_EventScript_Colton::
	trainerbattle_single TRAINER_BUG_CATCHER_COLTON, Route3_Text_ColtonIntro, Route3_Text_ColtonDefeat
	msgbox Route3_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_ColtonIntro::
    .string "Ei! Você batalhou contra o meu amigo lá\n"
    .string "na Floresta de Viridian!$"

Route3_Text_ColtonDefeat::
    .string "Você me venceu também!$"

Route3_Text_ColtonPostBattle::
    .string "Existem outros tipos de Pokémon além dos\n"
    .string "que você encontra em florestas.$"

Route3_EventScript_Ben::
	trainerbattle_single REMATCHABLE_TRAINER_YOUNGSTER_BEN_1, Route3_Text_BenIntro, Route3_Text_BenDefeat, Route3_EventScript_RegisterBenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_BenRematch
	msgbox Route3_Text_BenPostBattle, MSGBOX_DEFAULT
	release
	end

Route3_Text_BenIntro::
    .string "Oi!\n"
    .string "Eu gosto de bermudas!\p"
    .string "Elas são incrivelmente confortáveis e\n"
    .string "fáceis de vestir!$"

Route3_Text_BenDefeat::
    .string "Não acredito!$"

Route3_Text_BenPostBattle::
    .string "Você usa o PC do Centro Pokémon para\n"
    .string "guardar os seus Pokémon?\p"
    .string "Cada Caixa comporta até\n"
    .string "30 Pokémon.$"

Route3_EventScript_RegisterBenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_BenRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_YOUNGSTER_BEN_1
	release
	end

Route3_Text_BenRegister:
	.string "Você parece um treinador que me entende.\n"
	.string "Vamos ser amigos!$"

Route3_EventScript_BenRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_YOUNGSTER_BEN_1, Route3_Text_BenRematchIntro, Route3_Text_BenDefeat
	msgbox Route3_Text_BenRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_BenRematchIntro::
	.string "E aí!\n"
	.string "Já tentou usar bermudas?$"

Route3_Text_BenRematchPostBattle::
	.string "Você tem que experimentar!\n"
	.string "Vai mudar a sua vida!$"

Route3_EventScript_Greg::
	trainerbattle_single TRAINER_BUG_CATCHER_GREG, Route3_Text_GregIntro, Route3_Text_GregDefeat
	msgbox Route3_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_GregIntro::
    .string "Você é um treinador?\n"
    .string "Vamos começar isso agora mesmo!$"

Route3_Text_GregDefeat::
    .string "Se eu tivesse Pokémon novos, eu teria\n"
    .string "vencido!$"

Route3_Text_GregPostBattle::
    .string "Se uma CAIXA de Pokémon no PC ficar cheia,\n"
    .string "é só mudar para outra caixa.$"

Route3_EventScript_Calvin::
	trainerbattle_single TRAINER_YOUNGSTER_CALVIN, Route3_Text_CalvinIntro, Route3_Text_CalvinDefeat
	msgbox Route3_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_CalvinIntro::
    .string "Ei! Você não está usando bermudas!\n"
    .string "Qual é o seu problema?$"

Route3_Text_CalvinDefeat::
    .string "Perdi!\n"
    .string "Perdi! Perdi!$"

Route3_Text_CalvinPostBattle::
    .string "Eu sempre uso bermudas, até mesmo no\n"
    .string "inverno. Essa é a minha filosofia.$"

Route3_EventScript_Sally::
	trainerbattle_single TRAINER_LASS_SALLY, Route3_Text_SallyIntro, Route3_Text_SallyDefeat
	msgbox Route3_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_SallyIntro::
    .string "Esse jeito que você me olhou…\n"
    .string "É tão intrigante!$"

Route3_Text_SallyDefeat::
    .string "Pegue leve!$"

Route3_Text_SallyPostBattle::
    .string "Você pode evitar batalhas se não deixar\n"
    .string "os treinadores verem você.$"

Route3_EventScript_James::
	trainerbattle_single TRAINER_BUG_CATCHER_JAMES, Route3_Text_JamesIntro, Route3_Text_JamesDefeat
	msgbox Route3_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JamesIntro::
    .string "Vou batalhar com você usando os Pokémon\n"
    .string "que acabei de capturar.$"

Route3_Text_JamesDefeat::
    .string "Fui derrotado em um piscar de olhos!$"

Route3_Text_JamesPostBattle::
    .string "Pokémon treinados são mais fortes que os\n"
    .string "selvagens.$"

Route3_EventScript_Robin::
	trainerbattle_single TRAINER_LASS_ROBIN, Route3_Text_RobinIntro, Route3_Text_RobinDefeat
	msgbox Route3_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_RobinIntro::
    .string "Eek!\n"
    .string "Você encostou em mim?$"

Route3_Text_RobinDefeat::
    .string "Só isso?$"

Route3_Text_RobinPostBattle::
    .string "A Rota 4 fica no sopé do\n"
    .string "Mt. Moon.$"
