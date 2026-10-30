SproutTower_MapScripts::
	.byte 0

SproutTower_EventScript_ElderLi::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_SPROUT_TOWER_ELDER, SproutTower_EventScript_ElderLiAfter
	msgbox SproutTower_Text_ElderLiIntro, MSGBOX_DEFAULT
	giveitem ITEM_MYSTIC_WATER, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_MIRACLE_SEED, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_BEAT_SPROUT_TOWER_ELDER
	msgbox SproutTower_Text_ElderLiAfter, MSGBOX_DEFAULT
	release
	end

SproutTower_EventScript_ElderLiAfter::
	msgbox SproutTower_Text_ElderLiAfter, MSGBOX_DEFAULT
	release
	end

SproutTower_EventScript_Sage1::
	msgbox SproutTower_Text_Sage1, MSGBOX_NPC
	end

SproutTower_EventScript_Sage2::
	msgbox SproutTower_Text_Sage2, MSGBOX_NPC
	end

SproutTower_Text_ElderLiIntro:
	.string "Ancião Li: Bem-vindo ao topo da\n"
	.string "Sprout Tower, jovem Campeão!\p"
	.string "Consigo sentir o forte laço de amizade\n"
	.string "que une você ao seu Pikachu e a toda\l"
	.string "a sua equipe.\p"
	.string "Aquele que caminha em harmonia com\n"
	.string "seus Pokémon merece as bênçãos da\l"
	.string "natureza de Johto. Aceite isto!$"

SproutTower_Text_ElderLiAfter:
	.string "Ancião Li: Que a serenidade da\n"
	.string "Sprout Tower ilumine seu desafio no\l"
	.string "Ginásio de Violet City contra Falkner!$"

SproutTower_Text_Sage1:
	.string "O pilar central da Sprout Tower\n"
	.string "balança suavemente como um Bellsprout,\l"
	.string "protegendo a torre contra terremotos.$"

SproutTower_Text_Sage2:
	.string "Nossos ensinamentos dizem que todos\n"
	.string "os seres vivos compartilham a mesma\l"
	.string "luz espiritual.$"
