.set LOCALID_CHAIRMAN, 1
.set LOCALID_WOMAN,   3
.set LOCALID_FAT_MAN, 4

VermilionCity_PokemonFanClub_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	call_if_unset FLAG_DAILY_FANCLUB_REWARD, VermilionCity_PokemonFanClub_DailyReward
	release
	end

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
    .string "Olá, {PLAYER}!\p"
    .string "Você veio me visitar para ouvir sobre\n"
    .string "meus Pokémon de novo?\p"
    .string "Não?\n"
    .string "Que pena!$"

VermilionCity_PokemonFanClub_DailyReward::
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, 4, Common_EventScript_Return
	checkitemspace ITEM_RARE_CANDY, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_Return
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_CHAIRMAN, Common_Movement_Heart
	waitse
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox VermilionCity_PokemonFanClub_Text_TruePokeFan, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 1
	setflag FLAG_DAILY_FANCLUB_REWARD
	return

VermilionCity_PokemonFanClub_Text_TruePokeFan::
	.string "Dá para ver que você cuida muito\n"
	.string "bem dos seus Pokémon!\p"
	.string "Você é um verdadeiro PokéFã!\p"
	.string "Por favor, pegue isto e divida\n"
	.string "com o seu Pokémon!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
    .string "Eu presido o Fã-Clube Pokémon!\p"
    .string "Eu crio mais de cem\n"
    .string "Pokémon!\p"
    .string "Eu sou muito exigente quando o assunto\n"
    .string "são Pokémon! Com certeza sou!\p"
    .string "Então…\p"
    .string "Você veio me visitar para ouvir falar\n"
    .string "dos meus Pokémon?$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
    .string "Oh. Volte quando quiser ouvir\n"
    .string "a minha história!$"

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, MSGBOX_DEFAULT
	additem ITEM_BIKE_VOUCHER, 1
	waitfanfare
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_Text_ChairmansStory::
    .string "Ótimo!\n"
    .string "Então preste atenção!\p"
    .string "Meu querido Rapidash…\p"
    .string "Ele é…fofo…adorável…esperto…\n"
    .string "além de…incrível…você não acha?…\l"
    .string "ah sim…ele é…deslumbrante…\l"
    .string "gentil…eu o amo tanto!\p"
    .string "Abraço ele…ao…dormir…quentinho\n"
    .string "e macio…espetacular…\l"
    .string "arrebatador…\l"
    .string "…Opa! Olha só a hora!\l"
    .string "Prendi você por tempo demais!\p"
    .string "Obrigado por me escutar!\n"
    .string "Quero que fique com isto!$"

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForEste
	release
	end

VermilionCity_PokemonFanClub_Text_MakeRoomForEste::
    .string "Abra espaço para isto!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
    .string "{PLAYER} recebeu um Cupom de Bicicleta\n"
    .string "do Presidente.$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
    .string "Leve esse Cupom de Bicicleta até a\n"
    .string "Loja de Bicicletas em Cerulean.\p"
    .string "Troque-o por uma Bicicleta\n"
    .string "totalmente de graça!\p"
    .string "Não se preocupe, meu querido Fearow\n"
    .string "me leva voando para onde eu precisar ir.\p"
    .string "Por isso, não tenho utilidade para uma.\p"
    .string "Espero que goste de pedalar!$"

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
    .string "O nosso Presidente realmente adora os\n"
    .string "Pokémon dele.\p"
    .string "Mas a pessoa de quem os Pokémon mais\n"
    .string "gostam é a Daisy, na minha opinião.$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
    .string "O nosso Presidente fala sem parar\n"
    .string "sobre Pokémon.$"

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_1, 2, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 1
	release
	end

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
    .string "Eu simplesmente adoro o meu Seel!\n"
    .string "Ele é tão adorável!\p"
    .string "Ele faz “Kyuuuh” quando eu\n"
    .string "o abraço!$"

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 0
	release
	end

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
    .string "Ora, faça-me o favor!\p"
    .string "O meu Seel é muito mais atraente.\n"
    .string "O dobro, eu diria.$"

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_1, 1, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 2
	release
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
    .string "Você não gostaria de admirar a cauda\n"
    .string "adorável do meu Pikachu?$"

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 0
	release
	end

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
    .string "Hmph!\p"
    .string "O meu Pikachu é duas vezes mais fofo\n"
    .string "do que aquele ali!$"

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Text_Pikachu::
    .string "Pikachu: Chu! Pikachu!$"

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Text_Seel::
    .string "Seel: Kyuoo!$"

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
    .string "Vamos todos ouvir educadamente os\n"
    .string "outros treinadores!$"

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
    .string "Se alguém se gabar, gabe-se de volta!$"
