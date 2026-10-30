DragonsDen_MapScripts::
	.byte 0

DragonsDen_EventScript_DragonMaster::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DRAGONS_DEN_DRATINI, DragonsDen_EventScript_MasterAfter
	goto_if_unset FLAG_DEFEATED_LEADER_CLAIR, DragonsDen_EventScript_MasterBeforeClair
	msgbox DragonsDen_Text_MasterGiftDratini, MSGBOX_DEFAULT
	givemon SPECIES_DRATINI, 50, ITEM_DRAGON_SCALE
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	playfanfare MUS_OBTAIN_ITEM
	msgbox DragonsDen_Text_ReceivedDratini, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_RECEIVED_DRAGONS_DEN_DRATINI
	release
	end

DragonsDen_EventScript_MasterBeforeClair::
	msgbox DragonsDen_Text_MasterBeforeClair, MSGBOX_DEFAULT
	release
	end

DragonsDen_EventScript_MasterAfter::
	msgbox DragonsDen_Text_MasterAfter, MSGBOX_DEFAULT
	release
	end

DragonsDen_Text_MasterBeforeClair::
	.string "Ancião do Clã: Bem-vindo ao\n"
	.string "sagrado Dragon's Den!\p"
	.string "Derrote Clair no Ginásio de\n"
	.string "Blackthorn City e retorne aqui\l"
	.string "para receber a bênção ancestral\l"
	.string "do nosso clã de dragões!$"

DragonsDen_Text_MasterGiftDratini::
	.string "Ancião do Clã: Sinto em seu olhar\n"
	.string "que você trata seus Pokémon com\l"
	.string "confiança e amor verdadeiros!\p"
	.string "Como prova da aprovação do Clã\n"
	.string "dos Dragões, confio a você este\l"
	.string "Dratini especial segurando uma\l"
	.string "Dragon Scale!$"

DragonsDen_Text_ReceivedDratini::
	.string "{PLAYER} recebeu o DRATINI do\n"
	.string "Ancião do Dragon's Den!$"

DragonsDen_Text_MasterAfter::
	.string "Ancião do Clã: Agora que você\n"
	.string "reuniu todas as Insígnias de\l"
	.string "Johto, vá ao Monte Silver!\p"
	.string "O lendário Campeão Red espera\n"
	.string "por você no topo nevado!$"
