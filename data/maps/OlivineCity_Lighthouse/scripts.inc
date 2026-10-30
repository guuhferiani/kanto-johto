.set LOCALID_JASMINE, 1

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineCity_Lighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CIANWOOD_SECRETPOTION, OlivineCity_Lighthouse_EventScript_HealAmphy
	msgbox OlivineCity_Lighthouse_Text_JasmineNeedPotion, MSGBOX_DEFAULT
	release
	end

OlivineCity_Lighthouse_EventScript_HealAmphy::
	msgbox OlivineCity_Lighthouse_Text_JasmineHealsAmphy, MSGBOX_DEFAULT
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	waitmoncry
	msgbox OlivineCity_Lighthouse_Text_JasmineReturnToGym, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JASMINE
	setflag FLAG_HEALED_OLIVINE_AMPHY
	fadescreen FADE_FROM_BLACK
	release
	end

OlivineCity_Lighthouse_EventScript_Amphy::
	lock
	faceplayer
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	goto_if_set FLAG_HEALED_OLIVINE_AMPHY, OlivineCity_Lighthouse_EventScript_AmphyHealthy
	msgbox OlivineCity_Lighthouse_Text_AmphySick, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_Lighthouse_EventScript_AmphyHealthy::
	msgbox OlivineCity_Lighthouse_Text_AmphyHealthy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_Lighthouse_Text_JasmineNeedPotion::
	.string "Jasmine: Eu sou Jasmine, a Líder\n"
	.string "do Ginásio de Olivine...\p"
	.string "Mas Amphy, o Ampharos que ilumina\n"
	.string "este Farol para os marinheiros,\l"
	.string "está muito doente!\p"
	.string "Por favor, navegue pelo canal ao\n"
	.string "norte até a Farmácia de Cianwood\l"
	.string "City e traga a SecretPotion!$"

OlivineCity_Lighthouse_Text_JasmineHealsAmphy::
	.string "Jasmine: Você trouxe a SecretPotion\n"
	.string "de Cianwood City!\p"
	.string "Aqui está, Amphy... Tome o remédio!$"

OlivineCity_Lighthouse_Text_JasmineReturnToGym::
	.string "Jasmine: Olhe só! A cauda de Amphy\n"
	.string "voltou a brilhar com força total!\p"
	.string "Muito obrigada, {PLAYER}!\n"
	.string "Estarei esperando por você no\l"
	.string "Ginásio de Olivine City!$"

OlivineCity_Lighthouse_Text_AmphySick::
	.string "Amphy: Paaa...luu...\n"
	.string "(Sua respiração está fraca e a luz\l"
	.string "de sua cauda quase apagada...)$"

OlivineCity_Lighthouse_Text_AmphyHealthy::
	.string "Amphy: Palu! Paluuu!\n"
	.string "(Sua cauda ilumina todo o oceano\l"
	.string "com um brilho radiante!)$"
