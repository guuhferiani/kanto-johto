Route12_FishingHouse_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
    .string "Eu sou o irmão mais novo do\n"
    .string "Guru da Pesca.\p"
    .string "Eu simplesmente aamo pescar!\n"
    .string "Não consigo viver sem isso.\p"
    .string "Diga-me, você gosta de pescar?$"

Route12_FishingHouse_Text_OhThatsDisappointing::
    .string "Oh…\n"
    .string "Que decepção…$"

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD, 1
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route12_FishingHouse_Text_ReceivedSuperRod
	waitfanfare
	waitmessage
	additem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_Text_NoRoomForGift::
    .string "Oh, não!\p"
    .string "Eu tinha um presente para você,\n"
    .string "mas você não tem espaço para ele.$"

Route12_FishingHouse_Text_ReceivedSuperRod::
    .string "{PLAYER} recebeu uma Supervara do\n"
    .string "irmão do Guru da Pesca.$"

Route12_FishingHouse_Text_TakeThisAndFish::
    .string "Excelente! Gostei do seu estilo.\n"
    .string "Acho que podemos ser amigos.\p"
    .string "Pegue isto e pesque, jovem amigo!$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
    .string "Pescar é um estilo de vida!\n"
    .string "É como a mais bela poesia.\p"
    .string "Dos mares aos rios, vá lá fora e\n"
    .string "pesque o grandalhão, meu amigo.\p"
    .string "Agora, tenho um pedido.\p"
    .string "Se você algum dia pegar um Magikarp grande,\n"
    .string "eu quero ver.\p"
    .string "Por mais que eu ame pescar, também adoro\n"
    .string "ver Magikarp gigantescos.$"

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq  VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
    .string "Oh? {PLAYER}?\n"
    .string "Ora, se não é um Magikarp!\p"
    .string "Deixe-me vê-lo, rápido!$"

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
    .string "Olá, {PLAYER}!\n"
    .string "Tem pescado ultimamente?\p"
    .string "Tente pescar em qualquer corpo d'água\n"
    .string "com varas diferentes!\p"
    .string "Você encontrará Pokémon diferentes em locais\n"
    .string "diferentes, e em horários diferentes\l"
    .string "do dia também!\p"
    .string "Ah, e não se esqueça de me trazer um\n"
    .string "Magikarp gigantesco.$"

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_BIG_PEARL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
    .string "… … …Uau!\n"
    .string "{STR_VAR_2} polegadas!\p"
    .string "Você tem um raro apreço pelos aspectos\n"
    .string "finos e poéticos da pescaria!\p"
    .string "Você deve ficar com isto.\n"
    .string "Eu insisto!$"

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
    .string "Ficarei ansioso para ver recordes ainda\n"
    .string "maiores de você!$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
    .string "Hã?\n"
    .string "{STR_VAR_2} polegadas?\p"
    .string "Este tem o mesmo tamanho do que\n"
    .string "eu vi antes.$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
    .string "Hmm…\n"
    .string "Este tem {STR_VAR_2} polegadas de comprimento.\p"
    .string "Não supera o de {STR_VAR_3} polegadas\n"
    .string "que você me trouxe antes.$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
    .string "Hum… Isso não se parece muito com\n"
    .string "um Magikarp.$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
    .string "O Magikarp mais gigantesco\n"
    .string "que eu já presenciei…\p"
    .string "{STR_VAR_3} polegadas!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
    .string "É uma tabela em branco de algum tipo.\p"
    .string "Tem espaços para registrar algum tipo\n"
    .string "de recorde.$"













