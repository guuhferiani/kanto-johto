SaffronCity_CopycatsHouse_1F_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsMom::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsDad::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_1F_Text_Chansey
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered::
    .string "Minha filha é tão egocêntrica.\n"
    .string "Ela quase não tem amigos.$"

SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople::
    .string "Minha filha adora imitar as pessoas.\n"
    .string "É bastante irritante.\p"
    .string "Esse hábito de imitação lhe rendeu o\n"
    .string "apelido de Copiona por aqui.$"

SaffronCity_CopycatsHouse_1F_Text_Chansey::
    .string "Chansey: Chaan! Sii!$"
