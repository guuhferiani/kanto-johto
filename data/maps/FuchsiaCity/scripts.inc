FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FuchsiaCity_OnResume
	.byte 0

FuchsiaCity_OnTransition:
	setflag FLAG_VISITED_FUCHSIA_CITY
	call_if_ne VAR_FOSSIL_SELECTION, 2, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_eq VAR_FOSSIL_SELECTION, 2, FuchsiaCity_EventScript_SetKabutoGfx
	call Common_EventScript_GetDayOrNight
	end

FuchsiaCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_ne VAR_FOSSIL_SELECTION, 2, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_KabutoSign::
    .string "Nome: Kabuto\n"
    .string "Um Pokémon extremamente raro que foi\l"
    .string "regenerado a partir de um fóssil.$"

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_OmanyteSign::
    .string "Nome: Omanyte\n"
    .string "Um Pokémon extremamente raro que foi\l"
    .string "regenerado a partir de um fóssil.$"

FuchsiaCity_EventScript_GymSign::
	lockall
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

FuchsiaCity_Text_GymSign::
    .string "Ginásio Pokémon de Fuchsia\n"
    .string "Líder: Koga\l"
    .string "O Mestre Ninja Venenoso$"

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_ChanseySign::
    .string "Nome: Chansey\n"
    .string "Capturar uma depende só da sorte.$"

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_VoltorbSign::
    .string "Nome: Voltorb\n"
    .string "A própria imagem de uma Poké Bola.$"

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_KangaskhanSign::
    .string "Nome: Kangaskhan\p"
    .string "Um Pokémon maternal que cria seus\n"
    .string "filhotes em uma bolsa na barriga.$"

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_SlowpokeSign::
    .string "Nome: Slowpoke\n"
    .string "Amigável e se move muito devagar.$"

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_LaprasSign::
    .string "Nome: Lapras\n"
    .string "Também conhecido como o rei dos mares.$"

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_Text_CitySign::
    .string "Fuchsia\n"
    .string "Veja! É Rosa Paixão!$"

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_SafariZoneSign::
    .string "Paraíso dos Pokémon\n"
    .string "Zona do Safári$"

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_SafariGameSign::
    .string "Jogo do Safári\n"
    .string "Pegue quantos puder!$"

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

FuchsiaCity_Text_WardensHomeSign::
    .string "Zona do Safári\n"
    .string "Casa do Guarda$"

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_Text_DidYouTrySafariGame::
    .string "Você já tentou o Jogo do Safári?\p"
    .string "Há alguns Pokémon raros que só\n"
    .string "podem ser capturados lá.$"


FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_Text_SafariZoneZooInFront::
    .string "A Zona do Safári tem um zoológico\n"
    .string "em frente à entrada.\p"
    .string "Lá atrás fica o Jogo do Safári\n"
    .string "para capturar Pokémon.$"


FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_Text_WheresSara::
    .string "Erik: Onde está a Sara?\n"
    .string "Eu combinei de encontrá-la aqui.$"

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_Text_ItemBallInThere::
    .string "Aquela Poké Bola ali dentro…\n"
    .string "Você também estava de olho nela?\p"
    .string "Eu também!\n"
    .string "…Ué? Aquilo é um Pokémon?$"

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_Text_MyFatherIsGymLeader::
    .string "Meu pai é o Líder do Ginásio\n"
    .string "desta cidade.\p"
    .string "Estou treinando para usar Pokémon\n"
    .string "do tipo Venenoso tão bem quanto ele.$"

