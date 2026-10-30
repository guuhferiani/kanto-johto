EcruteakCity_Gym_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_MORTY, EcruteakCity_Gym_EventScript_MortyDefeated
	msgbox EcruteakCity_Gym_Text_MortyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_MORTY, EcruteakCity_Gym_Text_MortyDefeat
	message EcruteakCity_Gym_Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox EcruteakCity_Gym_Text_FogBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_MORTY
	giveitem ITEM_TM30_SHADOW_BALL, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

EcruteakCity_Gym_EventScript_MortyDefeated::
	msgbox EcruteakCity_Gym_Text_MortyPostBattle, MSGBOX_DEFAULT
	release
	end

EcruteakCity_Gym_EventScript_GymGuide::
	msgbox EcruteakCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

EcruteakCity_Gym_Text_MortyIntro::
	.string "Morty: Que bom que você veio!\n"
	.string "Aqui em Ecruteak, os espíritos e\l"
	.string "as lendas caminham lado a lado.\p"
	.string "Treinei minha vida inteira nas\n"
	.string "sombras para enxergar o que os\l"
	.string "outros não veem: o lendário Ho-Oh!\p"
	.string "Mostre-me seu poder além da\n"
	.string "névoa!$"

EcruteakCity_Gym_Text_MortyDefeat::
	.string "Ainda não sou forte o bastante...\n"
	.string "Sua luz dissipou toda a névoa!\l"
	.string "Esta Insígnia é sua!$"

EcruteakCity_Gym_Text_ReceivedFogBadge::
	.string "{PLAYER} recebeu a INSÍGNIA DA\n"
	.string "NÉVOA de Morty!$"

EcruteakCity_Gym_Text_FogBadgeInfo::
	.string "Morty: Com a Insígnia da Névoa,\n"
	.string "você dominou o quarto Ginásio de\l"
	.string "Johto!\p"
	.string "Aceite também a TM30 (Shadow Ball),\n"
	.string "o golpe supremo dos fantasmas!$"

EcruteakCity_Gym_Text_MortyPostBattle::
	.string "Morty: Siga para o norte pela\n"
	.string "Rota 38 e 39 para alcançar o\l"
	.string "porto marítimo de Olivine City!$"

EcruteakCity_Gym_Text_GymGuide::
	.string "E aí, Campeão!\n"
	.string "Morty domina o tipo Fantasma com\l"
	.string "Haunter, Misdreavus e dois Gengar\l"
	.string "até o nível 70!\p"
	.string "Golpes Sombrios (Crunch/Bite) e\n"
	.string "Psíquicos garantem a vitória!$"
