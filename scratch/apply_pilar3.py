# -*- coding: utf-8 -*-
import sys

replacements = {
    # Fly
    'const u8 gText_FlyToWhere[] = _("Fly to where?");':
        'const u8 gText_FlyToWhere[] = _("Voar para onde?");',

    # Eggs
    'const u8 gText_EggWillTakeALongTime[] = _("It looks like this Egg will\\ntake a long time to hatch.");':
        'const u8 gText_EggWillTakeALongTime[] = _("Parece que este Ovo vai\\ndemorar bastante para chocar.");',
    'const u8 gText_EggWillTakeSomeTime[] = _("What will hatch from this?\\nIt will take some time.");':
        'const u8 gText_EggWillTakeSomeTime[] = _("O que vai chocar daqui?\\nAinda levará algum tempo.");',
    'const u8 gText_EggWillHatchSoon[] = _("It moves occasionally.\\nIt should hatch soon.");':
        'const u8 gText_EggWillHatchSoon[] = _("Ele se mexe de vez em quando.\\nDeve chocar em breve.");',
    'const u8 gText_EggAboutToHatch[] = _("It\'s making sounds.\\nIt\'s about to hatch!");':
        'const u8 gText_EggAboutToHatch[] = _("Está fazendo barulhos!\\nEstá quase chocando!");',
    'const u8 gText_OddEggFoundByCouple[] = _("An odd Pokémon Egg found\\nby the Day Care couple.");':
        'const u8 gText_OddEggFoundByCouple[] = _("Um Ovo Pokémon curioso achado\\npelo casal da Pensão.");',
    'const u8 gText_PeculiarEggNicePlace[] = _("A peculiar Pokémon Egg\\nobtained at the nice place.");':
        'const u8 gText_PeculiarEggNicePlace[] = _("Um Ovo Pokémon peculiar\\nobtido em um belo lugar.");',
    'const u8 gText_PeculiarEggTrade[] = _("A peculiar Pokémon Egg\\nobtained in a trade.");':
        'const u8 gText_PeculiarEggTrade[] = _("Um Ovo Pokémon peculiar\\nobtido em uma troca.");',
    'const u8 gText_EggFromHotSprings[] = _("A Pokémon Egg obtained\\nat the hot springs.");':
        'const u8 gText_EggFromHotSprings[] = _("Um Ovo Pokémon obtido\\nnas fontes termais.");',
    'const u8 gText_EggFromTraveler[] = _("An odd Pokémon Egg\\nobtained from a traveler.");':
        'const u8 gText_EggFromTraveler[] = _("Um Ovo Pokémon curioso\\nobtido de um viajante.");',

    # Registry & Decorate actions
    'const u8 gText_OkayToDeleteFromRegistry[] = _("Is it okay to delete {STR_VAR_1}\\nfrom the registry?");':
        'const u8 gText_OkayToDeleteFromRegistry[] = _("Deseja apagar {STR_VAR_1}\\ndo registro?");',
    'const u8 gText_RegisteredDataDeleted[] = _("The registered data was deleted.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_RegisteredDataDeleted[] = _("Os dados registrados foram apagados.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_NoRegistry[] = _("There is no registry.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_NoRegistry[] = _("Não há nenhum registro.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_DelRegist[] = _("Del Regist.");':
        'const u8 gText_DelRegist[] = _("Apagar Reg.");',
    'const u8 gText_Decorate[] = _("Decorate");':
        'const u8 gText_Decorate[] = _("Decorar");',
    'const u8 gText_PutAway[] = _("Put away");':
        'const u8 gText_PutAway[] = _("Guardar");',
    'const u8 gText_Toss2[] = _("Toss");':
        'const u8 gText_Toss2[] = _("Descartar");',

    # Decor items & messages
    'const u8 gText_PutOutSelectedDecorItem[] = _("Put out the selected decoration item.");':
        'const u8 gText_PutOutSelectedDecorItem[] = _("Colocar a decoração selecionada.");',
    'const u8 gText_StoreChosenDecorInPC[] = _("Store the chosen decoration in the PC.");':
        'const u8 gText_StoreChosenDecorInPC[] = _("Guardar a decoração no PC.");',
    'const u8 gText_ThrowAwayUnwantedDecors[] = _("Throw away unwanted decorations.");':
        'const u8 gText_ThrowAwayUnwantedDecors[] = _("Jogar fora decorações indesejadas.");',
    'const u8 gText_NoDecorations[] = _("There are no decorations.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_NoDecorations[] = _("Não há decorações.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_Desk[] = _("Big Doll");':
        'const u8 gText_Desk[] = _("Boneco Grande");',
    'const u8 gText_Chair[] = _("Chair");':
        'const u8 gText_Chair[] = _("Cadeira");',
    'const u8 gText_Plant[] = _("Plant");':
        'const u8 gText_Plant[] = _("Planta");',
    'const u8 gText_Ornament[] = _("Ornament");':
        'const u8 gText_Ornament[] = _("Ornamento");',
    'const u8 gText_Mat[] = _("Mat");':
        'const u8 gText_Mat[] = _("Tapete");',
    'const u8 gText_Poster[] = _("Poster");':
        'const u8 gText_Poster[] = _("Pôster");',
    'const u8 gText_Doll[] = _("Doll");':
        'const u8 gText_Doll[] = _("Boneco");',
    'const u8 gText_Cushion[] = _("Cushion");':
        'const u8 gText_Cushion[] = _("Almofada");',
    'const u8 gText_Gold[] = _("Gold");':
        'const u8 gText_Gold[] = _("Ouro");',
    'const u8 gText_Silver[] = _("Silver");':
        'const u8 gText_Silver[] = _("Prata");',
    'const u8 gText_PlaceItHere[] = _("Place it here?");':
        'const u8 gText_PlaceItHere[] = _("Colocar aqui?");',
    'const u8 gText_CantBePlacedHere[] = _("It can\'t be placed here.");':
        'const u8 gText_CantBePlacedHere[] = _("Não pode ser colocado aqui.");',
    'const u8 gText_CancelDecorating[] = _("Cancel decorating?");':
        'const u8 gText_CancelDecorating[] = _("Cancelar decoração?");',
    'const u8 gText_InUseAlready[] = _("This is in use already.");':
        'const u8 gText_InUseAlready[] = _("Já está em uso.");',
    'const u8 gText_NoMoreDecorations[] = _("No more decorations can be placed.\\nThe most that can be placed are {STR_VAR_1}.");':
        'const u8 gText_NoMoreDecorations[] = _("Não cabem mais decorações.\\nO máximo permitido é {STR_VAR_1}.");',
    'const u8 gText_NoMoreDecorations2[] = _("No more decorations can be placed.\\nThe most that can be placed are {STR_VAR_1}.");':
        'const u8 gText_NoMoreDecorations2[] = _("Não cabem mais decorações.\\nO máximo permitido é {STR_VAR_1}.");',
    'const u8 gText_MustBePlacedOnDesk[] = _("This can\'t be placed here.\\nIt must be on a Desk, etc.");':
        'const u8 gText_MustBePlacedOnDesk[] = _("Não pode ser colocado aqui.\\nDeve ficar sobre uma Mesa, etc.");',
    'const u8 gText_CantPlaceInRoom[] = _("This decoration can\'t be placed in\\nyour own room.");':
        'const u8 gText_CantPlaceInRoom[] = _("Esta decoração não pode ser\\ncolocada no seu próprio quarto.");',
    'const u8 gText_CantThrowAwayInUse[] = _("This decoration is in use.\\nIt can\'t be thrown away.");':
        'const u8 gText_CantThrowAwayInUse[] = _("Esta decoração está em uso.\\nNão pode ser jogada fora.");',
    'const u8 gText_DecorationWillBeDiscarded[] = _("This {STR_VAR_1} will be discarded.\\nIs that okay?");':
        'const u8 gText_DecorationWillBeDiscarded[] = _("Este(a) {STR_VAR_1} será\\ndescartado(a). Tudo bem?");',
    'const u8 gText_DecorationThrownAway[] = _("The decoration item was thrown away.");':
        'const u8 gText_DecorationThrownAway[] = _("A decoração foi jogada fora.");',
    'const u8 gText_StopPuttingAwayDecorations[] = _("Stop putting away decorations?");':
        'const u8 gText_StopPuttingAwayDecorations[] = _("Parar de guardar decorações?");',
    'const u8 gText_NoDecorationHere[] = _("There is no decoration item here.");':
        'const u8 gText_NoDecorationHere[] = _("Não há decoração aqui.");',
    'const u8 gText_ReturnDecorationToPC[] = _("Return this decoration to the PC?");':
        'const u8 gText_ReturnDecorationToPC[] = _("Devolver esta decoração ao PC?");',
    'const u8 gText_DecorationReturnedToPC[] = _("The decoration was returned to the PC.");':
        'const u8 gText_DecorationReturnedToPC[] = _("A decoração foi guardada no PC.");',
    'const u8 gText_NoDecorationsInUse[] = _("There are no decorations in use.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_NoDecorationsInUse[] = _("Não há decorações em uso.{PAUSE_UNTIL_PRESS}");',

    # PC Item Storage & Mailbox
    'const u8 gText_TurnOff[] = _("Turn off");':
        'const u8 gText_TurnOff[] = _("Desligar");',
    'const u8 gText_Decoration[] = _("Decoration");':
        'const u8 gText_Decoration[] = _("Decoração");',
    'const u8 gText_ItemStorage[] = _("Item storage");':
        'const u8 gText_ItemStorage[] = _("Armazenar itens");',
    'const u8 gText_Mailbox[] = _("Mailbox");':
        'const u8 gText_Mailbox[] = _("Caixa de correio");',
    'const u8 gText_DepositItem[] = _("Deposit item");':
        'const u8 gText_DepositItem[] = _("Depositar item");',
    'const u8 gText_WithdrawItem[] = _("Withdraw item");':
        'const u8 gText_WithdrawItem[] = _("Retirar item");',
    'const u8 gText_TossItem[] = _("Toss item");':
        'const u8 gText_TossItem[] = _("Descartar item");',
    'const u8 gText_StoreItemsInPC[] = _("Store items in the PC.");':
        'const u8 gText_StoreItemsInPC[] = _("Guardar itens no PC.");',
    'const u8 gText_TakeOutItemsFromPC[] = _("Take out items from the PC.");':
        'const u8 gText_TakeOutItemsFromPC[] = _("Retirar itens do PC.");',
    'const u8 gText_ThrowAwayItemsInPC[] = _("Throw away items stored in the PC.");':
        'const u8 gText_ThrowAwayItemsInPC[] = _("Jogar fora itens do PC.");',
    'const u8 gText_NoItems[] = _("There are no items.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_NoItems[] = _("Não há itens.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_NoRoomInBag[] = _("There is no more\\nroom in the Bag.");':
        'const u8 gText_NoRoomInBag[] = _("Não há mais espaço\\nna Mochila.");',
    'const u8 gText_WithdrawHowManyItems[] = _("Withdraw how many\\n{STR_VAR_1}(s)?");':
        'const u8 gText_WithdrawHowManyItems[] = _("Retirar quantos(as)\\n{STR_VAR_1}?");',
    'const u8 gText_WithdrawXItems[] = _("Withdrew {STR_VAR_2}\\n{STR_VAR_1}(s).");':
        'const u8 gText_WithdrawXItems[] = _("Retirou {STR_VAR_2}\\n{STR_VAR_1}.");',
    'const u8 gText_Read[] = _("Read");':
        'const u8 gText_Read[] = _("Ler");',
    'const u8 gText_MoveToBag[] = _("Move to Bag");':
        'const u8 gText_MoveToBag[] = _("Mover p/ Mochila");',
    'const u8 gText_Give2[] = _("Give");':
        'const u8 gText_Give2[] = _("Dar");',
    'const u8 gText_NoMailHere[] = _("There\'s no mail here.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_NoMailHere[] = _("Não há cartas aqui.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_WhatToDoWithVar1sMail[] = _("What would you like to do with\\n{STR_VAR_1}\'s mail?");':
        'const u8 gText_WhatToDoWithVar1sMail[] = _("O que deseja fazer com a\\ncarta de {STR_VAR_1}?");',
    'const u8 gText_MessageWillBeLost[] = _("The message will be lost.\\nIs that okay?");':
        'const u8 gText_MessageWillBeLost[] = _("A mensagem será perdida.\\nTudo bem?");',
    'const u8 gText_BagIsFull[] = _("The Bag is full.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_BagIsFull[] = _("A Mochila está cheia.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_MailToBagMessageErased[] = _("The mail was returned to the Bag\\nwith its message erased.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_MailToBagMessageErased[] = _("A carta voltou para a Mochila\\ncom a mensagem apagada.{PAUSE_UNTIL_PRESS}");',

    # Battles / Vending machines
    'const u8 gText_SingleBattle[] = _("Single battle");':
        'const u8 gText_SingleBattle[] = _("Batalha Individual");',
    'const u8 gText_DoubleBattle[] = _("Double battle");':
        'const u8 gText_DoubleBattle[] = _("Batalha em Duplas");',
    'const u8 gText_MultiBattle[] = _("Multi battle");':
        'const u8 gText_MultiBattle[] = _("Batalha Múltipla");',
    'const u8 gText_Challenge[] = _("Challenge");':
        'const u8 gText_Challenge[] = _("Desafio");',
    'const u8 gText_Lv50[] = _("Lv. 50");':
        'const u8 gText_Lv50[] = _("Nv. 50");',
    'const u8 gText_OpenLevel[] = _("Open level");':
        'const u8 gText_OpenLevel[] = _("Nível Livre");',
    'const u8 gText_FreshWaterAndPrice[] = _("Fresh Water{CLEAR_TO 0x48}¥200");':
        'const u8 gText_FreshWaterAndPrice[] = _("Água Fresca{CLEAR_TO 0x48}¥200");',
    'const u8 gText_SodaPopAndPrice[] = _("Soda Pop{CLEAR_TO 0x48}¥300");':
        'const u8 gText_SodaPopAndPrice[] = _("Refrigerante{CLEAR_TO 0x48}¥300");',
    'const u8 gText_LemonadeAndPrice[] = _("Lemonade{CLEAR_TO 0x48}¥350");':
        'const u8 gText_LemonadeAndPrice[] = _("Limonada{CLEAR_TO 0x48}¥350");',
    'const u8 gText_FreshWater[] = _("Fresh Water");':
        'const u8 gText_FreshWater[] = _("Água Fresca");',
    'const u8 gText_SodaPop[] = _("Soda Pop");':
        'const u8 gText_SodaPop[] = _("Refrigerante");',
    'const u8 gText_Lemonade[] = _("Lemonade");':
        'const u8 gText_Lemonade[] = _("Limonada");',

    # Safari stock
    'const u8 gText_SafariBallStock[] = _("Safari Balls\\nStock: {STR_VAR_1}");':
        'const u8 gText_SafariBallStock[] = _("Bolas de Safari\\nEstoque: {STR_VAR_1}");',

    # Move Relearner
    'const u8 gText_TeachWhichMoveToPkmn[] = _("Teach which move to {STR_VAR_1}?");':
        'const u8 gText_TeachWhichMoveToPkmn[] = _("Ensinar qual golpe a {STR_VAR_1}?");',
    'const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("Teach {STR_VAR_2}?");':
        'const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("Ensinar {STR_VAR_2}?");',
    'const u8 gText_MoveRelearnerPkmnLearnedMove[] = _("{STR_VAR_1} learned\\n{STR_VAR_2}!");':
        'const u8 gText_MoveRelearnerPkmnLearnedMove[] = _("{STR_VAR_1} aprendeu\\n{STR_VAR_2}!");',
    'const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _("{STR_VAR_1} is trying to learn\\n{STR_VAR_2}.\\pBut {STR_VAR_1} can\'t learn more\\nthan four moves.\\pDelete an older move to make\\nroom for {STR_VAR_2}?");':
        'const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _("{STR_VAR_1} tenta aprender\\n{STR_VAR_2}.\\pMas {STR_VAR_1} não pode aprender\\nmais de quatro golpes.\\pEsquecer um golpe para abrir\\nespaço para {STR_VAR_2}?");',
    'const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _("Stop trying to teach\\n{STR_VAR_2}?");':
        'const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _("Parar de tentar ensinar\\n{STR_VAR_2}?");',
    'const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\\p");':
        'const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2 e {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Puf!\\p");',
    'const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} forgot {STR_VAR_3}.\\pAnd…\\p{STR_VAR_1} learned {STR_VAR_2}.");':
        'const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} esqueceu {STR_VAR_3}.\\pE…\\p{STR_VAR_1} aprendeu {STR_VAR_2}.");',
    'const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _("{STR_VAR_1} did not learn the\\nmove {STR_VAR_2}.");':
        'const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _("{STR_VAR_1} não aprendeu o\\ngolpe {STR_VAR_2}.");',
    'const u8 gText_MoveRelearnerGiveUp[] = _("Give up trying to teach a new\\nmove to {STR_VAR_1}?");':
        'const u8 gText_MoveRelearnerGiveUp[] = _("Desistir de ensinar um novo\\ngolpe a {STR_VAR_1}?");',
    'const u8 gText_MoveRelearnerWhichMoveToForget[] = _("Which move should be\\nforgotten?\\p");':
        'const u8 gText_MoveRelearnerWhichMoveToForget[] = _("Qual golpe deve ser\\nesquecido?\\p");',
    'const u8 gText_MoveRelearnerBattleMoves[] = _("Battle moves");':
        'const u8 gText_MoveRelearnerBattleMoves[] = _("Golpes de Batalha");',
    'const u8 gText_MoveRelearnerContestMovesTitle[] = _("Contest moves");':
        'const u8 gText_MoveRelearnerContestMovesTitle[] = _("Golpes de Concurso");',
    'const u8 gText_MoveRelearnerType[] = _("Type/");':
        'const u8 gText_MoveRelearnerType[] = _("Tipo/");',
    'const u8 gText_MoveRelearnerPP[] = _("PP/");':
        'const u8 gText_MoveRelearnerPP[] = _("PP/");',
    'const u8 gText_MoveRelearnerPower[] = _("Power/");':
        'const u8 gText_MoveRelearnerPower[] = _("Poder/");',
    'const u8 gText_MoveRelearnerAccuracy[] = _("Accuracy/");':
        'const u8 gText_MoveRelearnerAccuracy[] = _("Precisão/");',
    'const u8 gText_MoveRelearnerAppeal[] = _("Appeal");':
        'const u8 gText_MoveRelearnerAppeal[] = _("Apelo");',
    'const u8 gText_MoveRelearnerJam[] = _("Jam");':
        'const u8 gText_MoveRelearnerJam[] = _("Inibição");',

    # Save & Clock
    'const u8 gText_ClearAllSaveData[] = _("Clear all save data areas?");':
        'const u8 gText_ClearAllSaveData[] = _("Apagar todos os dados salvos?");',
    'const u8 gText_ClearingData[] = _("Clearing data…\\nPlease wait.");':
        'const u8 gText_ClearingData[] = _("Apagando dados…\\nAguarde.");',
    'const u8 gText_IsThisTheCorrectTime[] = _("Is this the correct time?");':
        'const u8 gText_IsThisTheCorrectTime[] = _("Esta é a hora correta?");',
    'const u8 gText_Confirm3[] = _("Confirm");':
        'const u8 gText_Confirm3[] = _("Confirmar");',
    'const u8 gText_Cancel4[] = _("Cancel");':
        'const u8 gText_Cancel4[] = _("Cancelar");',

    # Blackboard Status
    'const u8 gText_ReadPoison[] = _("Poison");':
        'const u8 gText_ReadPoison[] = _("Veneno");',
    'const u8 gText_ReadSleep[] = _("Sleep");':
        'const u8 gText_ReadSleep[] = _("Sono");',
    'const u8 gText_ReadParalysis[] = _("Paralysis");':
        'const u8 gText_ReadParalysis[] = _("Paralisia");',
    'const u8 gText_ReadBurn[] = _("Burn");':
        'const u8 gText_ReadBurn[] = _("Queimadura");',
    'const u8 gText_ReadFreeze[] = _("Ice");':
        'const u8 gText_ReadFreeze[] = _("Gelo");',

    # Shop / Infinite TMs / Exp Share / Premier Balls
    'const u8 gText_SoldOut[] = _("I\'m sorry, but that item is sold out.\\p");':
        'const u8 gText_SoldOut[] = _("Sinto muito, mas esse item está esgotado.\\p");',
    'const u8 gText_SoldOut2[] = _("SOLD OUT");':
        'const u8 gText_SoldOut2[] = _("ESGOTADO");',
    'const u8 gOtherText_ExpShareOn[] = _("Turned on the Exp. Share.\\pParty will now gain a portion\\nof the Experience Points.{PAUSE_UNTIL_PRESS}");':
        'const u8 gOtherText_ExpShareOn[] = _("Exp. Share ativado.\\pA equipe agora receberá uma parte\\ndos Pontos de Experiência.{PAUSE_UNTIL_PRESS}");',
    'const u8 gOtherText_ExpShareOff[] = _("Turned off the Exp. Share.\\pParty will no longer gain a portion\\nof any Experience Points.{PAUSE_UNTIL_PRESS}");':
        'const u8 gOtherText_ExpShareOff[] = _("Exp. Share desativado.\\pA equipe não receberá mais uma parte\\ndos Pontos de Experiência.{PAUSE_UNTIL_PRESS}");',
    'const u8 gText_ThrowInPremierBalls[] = _("I\'ll throw in some Premier Balls, too.{PAUSE_UNTIL_PRESS}");':
        'const u8 gText_ThrowInPremierBalls[] = _("Vou incluir algumas Bolas de Estreia também.{PAUSE_UNTIL_PRESS}");',
}

with open('src/strings.c', 'r', encoding='utf-8', errors='ignore') as f:
    content = f.read()

count = 0
for old, new in replacements.items():
    if old in content:
        content = content.replace(old, new, 1)
        count += 1
    else:
        print(f"NOT FOUND: {old[:50]}")

print(f"Replaced {count} of {len(replacements)} strings.")

with open('src/strings.c', 'w', encoding='utf-8', newline='\n') as f:
    f.write(content)
print("Done writing src/strings.c")
