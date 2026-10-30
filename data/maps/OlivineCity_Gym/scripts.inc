OlivineCity_Gym_MapScripts::
	.byte 0

OlivineCity_Gym_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_JASMINE, OlivineCity_Gym_EventScript_JasmineDefeated
	msgbox OlivineCity_Gym_Text_JasmineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_JASMINE, OlivineCity_Gym_Text_JasmineDefeat
	message OlivineCity_Gym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OlivineCity_Gym_Text_MineralBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_LEADER_JASMINE
	giveitem ITEM_TM23_IRON_TAIL, 1
	call BattleFrontier_RankingHall_EventScript_CheckAllLeaders
	release
	end

OlivineCity_Gym_EventScript_JasmineDefeated::
	msgbox OlivineCity_Gym_Text_JasminePostBattle, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_EventScript_GymGuide::
	msgbox OlivineCity_Gym_Text_GymGuide, MSGBOX_NPC
	end

OlivineCity_Gym_Text_JasmineIntro::
	.string "Jasmine: Obrigada por sua ajuda no\n"
	.string "Farol de Olivine...\p"
	.string "Mas uma batalha de Ginásio é\n"
	.string "diferente. Sou especialista no\l"
	.string "recém-descoberto tipo Aço!\p"
	.string "Meus Pokémon possuem uma defesa\n"
	.string "impenetrável como o ferro!\l"
	.string "Um... Vamos começar!$"

OlivineCity_Gym_Text_JasmineDefeat::
	.string "...Você é um treinador superior,\n"
	.string "tanto em força quanto em bondade.\p"
	.string "De acordo com as regras da Liga\n"
	.string "Pokémon, entrego-lhe esta Insígnia!$"

OlivineCity_Gym_Text_ReceivedMineralBadge::
	.string "{PLAYER} recebeu a INSÍGNIA\n"
	.string "MINERAL de Jasmine!$"

OlivineCity_Gym_Text_MineralBadgeInfo::
	.string "Jasmine: Com a Insígnia Mineral,\n"
	.string "sua jornada por Johto brilha ainda\l"
	.string "mais forte!\p"
	.string "Por favor, leve também a TM23\n"
	.string "(Iron Tail)!$"

OlivineCity_Gym_Text_JasminePostBattle::
	.string "Jasmine: Ao norte daqui, cruzando\n"
	.string "o canal marítimo da Rota 40, fica\l"
	.string "Cianwood City e as misteriosas\l"
	.string "Whirl Islands!$"

OlivineCity_Gym_Text_GymGuide::
	.string "E aí, Campeão!\n"
	.string "Jasmine comanda Magneton, Skarmory,\l"
	.string "Forretress e seu gigantesco\l"
	.string "Steelix Lv. 76!\p"
	.string "Ataques de Fogo, Água e Terra são\n"
	.string "a melhor resposta contra o Aço!$"
