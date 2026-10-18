import os

translations = {
    # Intro e Registros
    "MatchCall_Text_OakRegisterCall": r"""\t.string "Carvalho: Olá, {PLAYER}{KUN}!\n"
\t.string "Vejo que você tem um Celular!\p"
\t.string "Bem, eu deveria te dar meu número.\p"
\t.string "Assim poderei avaliar a sua Pokédex\n"
\t.string "mesmo enquanto você estiver\l"
\t.string "em campo explorando.$" """,

    "MatchCall_Text_RegisteredOak": r"""\t.string "O Prof. Carvalho registrou o número\n"
\t.string "dele no seu Celular.$" """,

    "MatchCall_Text_RegisteredScott": r"""\t.string "Scott registrou as informações dele\n"
\t.string "no seu Celular.$" """,

    # Scott
    "MatchCall_Text_ScottBusy": r"""\t.string "... tuu ... tuu ... tuu ...\p"
\t.string "A linha do Scott parece\n"
\t.string "estar ocupada...$" """,

    "MatchCall_Text_ScottCerulean": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Você chegou em Cerulean!\p"
\t.string "Vai desafiar a Misty?\n"
\t.string "Melhor trazer traje de banho! Ha!\p"
\t.string "Vamos ver se eu estava certo sobre\n"
\t.string "você. Te vejo no ginásio!$" """,

    "MatchCall_Text_ScottGotBadge2": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Parabéns por conquistar a sua\n"
\t.string "Insígnia da Cascata!\p"
\t.string "Você realmente está pegando o jeito!$" """,

    "MatchCall_Text_ScottVermilion": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Soube que você chegou em Vermilion!\p"
\t.string "Planejando enfrentar o Tenente Surge?\p"
\t.string "Ótimo! Estarei assistindo!$" """,

    "MatchCall_Text_ScottGotBadge3": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Que batalha! Eu sabia que você\n"
\t.string "levaria essa Insígnia do Trovão!\p"
\t.string "Mas só vai ficar mais difícil daqui pra frente!$" """,

    "MatchCall_Text_ScottCeladon": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Então você chegou em Celadon!\p"
\t.string "Talvez eu dê uma pausa no cassino\n"
\t.string "para assistir a sua batalha!$" """,

    "MatchCall_Text_ScottGotBadge4": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Que bom que não perdi essa luta.\n"
\t.string "Que show!\p"
\t.string "Você com certeza está construindo\n"
\t.string "um grande nome!$" """,

    "MatchCall_Text_ScottSaffron": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Eu esperava te ver em Saffron, mas\n"
\t.string "havia todos aqueles capangas da\l"
\t.string "Equipe Rocket por lá!\p"
\t.string "Você sabia de algo sobre isso?$" """,

    "MatchCall_Text_ScottGotBadge5": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Se Sabrina tivesse lido minha mente,\n"
\t.string "saberia que nunca duvidei de você!\p"
\t.string "Excelente trabalho com a Insígnia da Lama!$" """,

    "MatchCall_Text_ScottFuchsia": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "O que disse? Você está em Fuchsia?\n"
\t.string "Também está aqui na cidade?\p"
\t.string "Como?\n"
\t.string "Sim! Estou na Zona do Safari!\p"
\t.string "Desculpe, não consegui ouvir!\p"
\t.string "Não ouço nada com todo esse barulho\n"
\t.string "de Tauros selvagens...\p"
\t.string "Eles parecem que vão entrar\n"
\t.string "em debandada!\p"
\t.string "... ... ...\p"
\t.string "Tenho que ir!$" """,

    "MatchCall_Text_ScottGotBadge6": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Mesmo com todos os truques,\n"
\t.string "Koga não teve a menor chance!\p"
\t.string "Quantas insígnias já são?\p"
\t.string "Você está numa sequência incrível!$" """,

    "MatchCall_Text_ScottCinnabar": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Está a caminho da Ilha Cinnabar\n"
\t.string "para encarar o Blaine?\p"
\t.string "Te vejo lá!$" """,

    "MatchCall_Text_ScottGotBadge7": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Dava para sentir o calor fervendo\n"
\t.string "daquela batalha!\p"
\t.string "Mas não baixe a guarda!\n"
\t.string "Rumo à próxima insígnia!$" """,

    "MatchCall_Text_ScottFinalBadge": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Falta apenas mais uma insígnia!\p"
\t.string "Ouviu dizer que o Líder do\n"
\t.string "Ginásio de Viridian retornou?\p"
\t.string "Ninguém sabe quase nada sobre ele,\n"
\t.string "então isso promete ser eletrizante.$" """,

    "MatchCall_Text_ScottPkmnLeague": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "Uau! Todas as oito insígnias!\p"
\t.string "Desde que te vi desafiar Brock,\n"
\t.string "eu sabia que você tinha talento.\p"
\t.string "Mas será o bastante para derrotar\n"
\t.string "a Elite dos Quatro?$" """,

    "MatchCall_Text_ScottThisIsIt": r"""\t.string "Scott: Ei! Futuro Campeão!\p"
\t.string "O que posso dizer...\n"
\t.string "Você alcançou o Planalto Índigo.\p"
\t.string "Mostre do que você é feito!$" """,

    "MatchCall_Text_ScottBattleTower": r"""\t.string "{PLAYER}!\n"
\t.string "Você conseguiu!\p"
\t.string "Venha me encontrar na Battle Tower.\n"
\t.string "Tenho uma surpresa para você...$" """,

    "MatchCall_Text_ScottBattleTower2": r"""\t.string "{PLAYER}!\p"
\t.string "Tem curtido os desafios da\n"
\t.string "Battle Tower?\p"
\t.string "Ótimo! Continue mirando no topo!$" """,

    "MatchCall_Text_ScottGameClear": r"""\t.string "Scott: Ei, futuro ca-!\p"
\t.string "Espere, agora é só Campeão,\n"
\t.string "não é mesmo!\p"
\t.string "Mas vou te contar um pequeno segredo.\p"
\t.string "Sua jornada não termina na\n"
\t.string "Liga Pokémon!\p"
\t.string "Existe um lugar ainda mais fascinante.\p"
\t.string "Mas isso é tudo o que vou revelar\n"
\t.string "por enquanto.\p"
\t.string "É algo para ficar muito empolgado.\p"
\t.string "Te ligo assim que estiver pronto.$" """,

    # Mãe
    "MatchCall_Text_Mom1": r"""\t.string "Mãe: Ah! {PLAYER}!\p"
\t.string "Que alegria receber sua ligação!\p"
\t.string "Quer dizer que seu Celular\n"
\t.string "está funcionando perfeitamente!\p"
\t.string "Você fará muitos amigos na sua jornada,\n"
\t.string "então registre eles também!\p"
\t.string "Que bom! Que bom!\n"
\t.string "Você parece muito feliz!\p"
\t.string "Hum...\n"
\t.string "Como eu sei disso?\p"
\t.string "Porque sou sua mãe, claro!\p"
\t.string "Eu sei tudo sobre você!\p"
\t.string "Hehehe.\n"
\t.string "Até logo, meu bem!$" """,

    "MatchCall_Text_Mom2": r"""\t.string "Mãe: Ouvi dizer que um rapaz muito\n"
\t.string "inteligente mora perto de Cerulean.\p"
\t.string "Fico pensando quanto ganha um\n"
\t.string "Pokémaníaco...\p"
\t.string "Será que é mais do que um treinador?\p"
\t.string "Talvez você devesse pedir alguns\n"
\t.string "conselhos de carreira a ele.$" """,

    "MatchCall_Text_Mom3": r"""\t.string "Mãe: Seu pai e você...\n"
\t.string "Todos são fascinados por Pokémon.\p"
\t.string "Qual será o grande encanto deles?\p"
\t.string "Eu?\n"
\t.string "Eu adoro Pokémon que me ajudam\l"
\t.string "nas tarefas de casa no dia a dia.$" """,

    "MatchCall_Text_Mom4": r"""\t.string "Mãe: Lavender...\n"
\t.string "Que lugar melancólico...\p"
\t.string "Quando penso em todos aqueles Pokémon...\p"
\t.string "...\p"
\t.string "Me perdoe, {PLAYER}.\p"
\t.string "Não quero te deixar triste também.$" """,

    "MatchCall_Text_Mom5": r"""\t.string "Mãe: {PLAYER}!\n"
\t.string "Eu estava justamente pensando em você.\p"
\t.string "Queria poder te ajudar mais\n"
\t.string "durante a sua aventura.\p"
\t.string "Talvez eu pudesse guardar dinheiro pra você!\p"
\t.string "O quê? Tem medo que eu gaste tudo\n"
\t.string "no Shopping de Celadon?\p"
\t.string "Que desfeita!$" """,

    "MatchCall_Text_Mom6": r"""\t.string "Mãe: Ah, você visitou Fuchsia?\p"
\t.string "Eu adorava passear na Zona do Safari\n"
\t.string "quando tinha a sua idade!\p"
\t.string "Adorava o Jogo do Safari,\n"
\t.string "mas nunca conseguia vencer.\p"
\t.string "Eu sempre me perdia por lá!$" """,

    "MatchCall_Text_Mom7": r"""\t.string "Mãe: Ah, {PLAYER}!\p"
\t.string "Eu estava vendo as notícias.\n"
\t.string "A Equipe Rocket atacou Saffron!\p"
\t.string "Aonde este mundo vai parar...\n"
\t.string "Por favor, tome muito cuidado!$" """,

    "MatchCall_Text_Mom8": r"""\t.string "Mãe: Você visitou a Ilha Cinnabar?\p"
\t.string "Quando eu era mais jovem, meus amigos\n"
\t.string "e eu íamos nadando até lá!\p"
\t.string "Mas tínhamos medo demais de entrar\n"
\t.string "na Mansão Pokémon.\p"
\t.string "Aquele casarão me dava calafrios!$" """,

    "MatchCall_Text_Mom9": r"""\t.string "Mãe: Oi, {PLAYER}!\p"
\t.string "Você está viajando há tanto tempo.\n"
\t.string "Espero que esteja se divertindo!\p"
\t.string "Mas lembre-se: você sempre pode voltar\n"
\t.string "para casa se as coisas ficarem difíceis!$" """,

    "MatchCall_Text_MomGameClear": r"""\t.string "Mãe: {PLAYER}...\n"
\t.string "Parece que foi ontem que você saiu\n"
\t.string "de Pallet, e agora você já viajou\l"
\t.string "por toda a região de Kanto!\p"
\t.string "Quem diria que você viveria uma\n"
\t.string "aventura tão linda com seus Pokémon!\p"
\t.string "Estou tão orgulhosa de você!$" """,

    # Rival
    "MatchCall_Text_RegisteredRival": r"""\t.string "Daisy registrou o contato de {RIVAL}\n"
\t.string "no seu Celular.$" """,

    "MatchCall_Text_Rival1": r"""\t.string "{RIVAL}: O quê? Quem está ligando?\p"
\t.string "...\p"
\t.string "{PLAYER}? Quem te deu meu número?\p"
\t.string "Argh, minha irmã é uma chata mesmo.\p"
\t.string "Não me ligue de novo!$" """,

    "MatchCall_Text_Rival2": r"""\t.string "{RIVAL}: Ah, é você, {PLAYER}?\p"
\t.string "Mal consigo te ouvir com o barulho de\n"
\t.string "todas essas insígnias que estou ganhando.\p"
\t.string "O quê? Você conseguiu uma também?\p"
\t.string "Que surpresa!$" """,

    "MatchCall_Text_Rival3": r"""\t.string "{RIVAL}: Me ligando de novo?\p"
\t.string "Nem pense que vou te dar dicas,\n"
\t.string "{PLAYER}.\p"
\t.string "Eu já nasci com esse talento,\n"
\t.string "não dá pra ensinar!$" """,

    "MatchCall_Text_Rival4": r"""\t.string "{RIVAL}: Ah, {PLAYER}.\p"
\t.string "Ouvi um boato de que você tinha\n"
\t.string "caído do navio S.S. Anne.\p"
\t.string "Pena que era bom demais pra ser verdade.$" """,

    "MatchCall_Text_Rival5": r"""\t.string "{RIVAL}: Ei, {PLAYER}.\p"
\t.string "Você chegou até Celadon?\p"
\t.string "Tem um restaurante ótimo lá,\n"
\t.string "mas eles não deixam perdedores como você\l"
\t.string "comer lá dentro! Hahaha!$" """,

    "MatchCall_Text_Rival6": r"""\t.string "{RIVAL}: Que saco, {PLAYER}.\p"
\t.string "Por que não para de me ligar?\p"
\t.string "Parece até que é meu fã.\n"
\t.string "Vê se não enche!$" """,

    "MatchCall_Text_Rival7": r"""\t.string "{RIVAL}: Não posso falar agora, {PLAYER}.\p"
\t.string "Estou enfrentando alguns Treinadores Maneiros.\p"
\t.string "É, dois contra um.\p"
\t.string "Eu venço essas lutas o tempo todo.$" """,

    "MatchCall_Text_Rival8": r"""\t.string "{RIVAL}: Ei, {PLAYER}.\p"
\t.string "As coisas estão ficando sérias, hein?\p"
\t.string "Lembra quando a gente brincava quando criança?\p"
\t.string "Quem diria que eu cresceria pra ser\n"
\t.string "o futuro Campeão de Kanto!$" """,

    "MatchCall_Text_Rival9": r"""\t.string "{RIVAL}: {PLAYER}.\p"
\t.string "Eu vou conseguir.\p"
\t.string "Eu vou ser o campeão.\p"
\t.string "Ninguém pode me parar.$" """,

    "MatchCall_Text_RivalGameClear": r"""\t.string "{RIVAL}: Ah, é você, {PLAYER}.\p"
\t.string "Ligando pra esfregar na minha cara?\p"
\t.string "Escuta aqui, o que rolou na Liga\n"
\t.string "foi pura sorte sua!\p"
\t.string "Eu vou te vencer da próxima vez!$" """,

    # Aide Cedar
    "MatchCall_Text_AideIntro": r"""\t.string "Cedar: ...............\n"
\t.string "Alô? Ah, {PLAYER}!\p"
\t.string "Aqui é o Cedar! Um dos assistentes\n"
\t.string "do professor!\p"
\t.string "Nós nos conhecemos em Pallet, lembra?\p"
\t.string "Sim, sim! Que ótimo!\p"
\t.string "O professor me passou seu número.\n"
\t.string "Espero que não se importe.\p"
\t.string "Ele me pediu para te dar suporte na jornada,\n"
\t.string "então logo entrarei em contato. Até mais!$" """,

    "MatchCall_Text_AideIntro2": r"""\t.string "Cedar: ...............\n"
\t.string "Alô? Ah, {PLAYER}!\p"
\t.string "Aqui é o Cedar! Um dos assistentes\n"
\t.string "do professor!\p"
\t.string "Eu te vi no laboratório, mas nunca\n"
\t.string "tivemos a chance de conversar.\p"
\t.string "O professor me passou seu número.\n"
\t.string "Espero que não se importe.\p"
\t.string "Ele me pediu para te dar suporte na jornada,\n"
\t.string "então logo entrarei em contato. Até mais!$" """,

    "MatchCall_Text_RegisteredOaksAide": r"""\t.string "O Assistente do Carvalho registrou o\n"
\t.string "contato dele no seu Celular.$" """,

    "MatchCall_Text_AideWatchingProgress": r"""\t.string "Cedar: Olá, {PLAYER}!\p"
\t.string "Como está indo a sua jornada?\p"
\t.string "Que bom!\p"
\t.string "Estarei acompanhando o seu progresso!$" """,

    "MatchCall_Text_AideFlashReady": r"""\t.string "Cedar: Ah, olá {PLAYER}!\p"
\t.string "Parabéns por conquistar mais\n"
\t.string "uma Insígnia de Ginásio!\p"
\t.string "O Prof. Carvalho gostaria de\n"
\t.string "te dar uma recompensa.\p"
\t.string "Venha me encontrar na Rota 2\n"
\t.string "que eu entregarei a você!$" """,

    "MatchCall_Text_AideOnMyWayRoute2": r"""\t.string "Cedar: Olá, {PLAYER}!\p"
\t.string "Estou a caminho da Rota 2\n"
\t.string "neste exato momento!\p"
\t.string "Acho que entrei no caminho errado,\n"
\t.string "no entanto.\p"
\t.string "Acabei parando no Prédio Leste.\p"
\t.string "Pode ser um pouco difícil chegar até mim,\n"
\t.string "mas estarei te esperando!$" """,

    "MatchCall_Text_AideEverstoneReady": r"""\t.string "Cedar: Ah, olá {PLAYER}!\p"
\t.string "Parabéns por conquistar mais\n"
\t.string "uma Insígnia de Ginásio!\p"
\t.string "O Prof. Carvalho gostaria de\n"
\t.string "te dar uma recompensa.\p"
\t.string "Venha me encontrar na Rota 10\n"
\t.string "que eu entregarei a você!$" """,

    "MatchCall_Text_AideOnMyWayRoute10": r"""\t.string "Cedar: Olá, {PLAYER}!\p"
\t.string "Estou a caminho da Rota 10!\p"
\t.string "Acabei enfrentando alguns Treinadores,\n"
\t.string "então meus Pokémon precisam descansar.\p"
\t.string "Venha me ver no Centro Pokémon!$" """,

    "MatchCall_Text_AideItemfinderReady": r"""\t.string "Cedar: Ah, olá {PLAYER}!\p"
\t.string "Parabéns por conquistar mais\n"
\t.string "uma Insígnia de Ginásio!\p"
\t.string "O Prof. Carvalho gostaria de\n"
\t.string "te dar uma recompensa.\p"
\t.string "Venha me encontrar na Rota 11\n"
\t.string "que eu entregarei a você!$" """,

    "MatchCall_Text_AideOnMyWayRoute11": r"""\t.string "Cedar: Olá, {PLAYER}!\p"
\t.string "Estou a caminho da Rota 11!\p"
\t.string "Queria muito admirar a vista do oceano,\n"
\t.string "então tentarei achar um bom ponto\l"
\t.string "para contemplar o mar.$" """,

    "MatchCall_Text_AideAmuletCoinReady": r"""\t.string "Cedar: Ah, olá {PLAYER}!\p"
\t.string "Parabéns por conquistar mais\n"
\t.string "uma Insígnia de Ginásio!\p"
\t.string "O Prof. Carvalho gostaria de\n"
\t.string "te dar uma recompensa.\p"
\t.string "Venha me encontrar na Rota 16\n"
\t.string "que eu entregarei a você!$" """,

    "MatchCall_Text_AideOnMyWayRoute16": r"""\t.string "Cedar: Olá, {PLAYER}!\p"
\t.string "Estou a caminho da Rota 16!\p"
\t.string "Havia uns tipos assustadores perto da\n"
\t.string "Ciclovia, então vou ficar esperando\l"
\t.string "dentro do Posto de Guarda!$" """,

    "MatchCall_Text_AideExpShareReady": r"""\t.string "Cedar: Ah, olá {PLAYER}!\p"
\t.string "Parabéns por conquistar mais\n"
\t.string "uma Insígnia de Ginásio!\p"
\t.string "O Prof. Carvalho gostaria de\n"
\t.string "te dar uma recompensa.\p"
\t.string "Venha me encontrar na Rota 15\n"
\t.string "que eu entregarei a você!$" """,

    "MatchCall_Text_AideOnMyWayRoute15": r"""\t.string "Cedar: Olá, {PLAYER}!\p"
\t.string "Estou a caminho da Rota 15!\p"
\t.string "Você já visitou a Zona do Safari?\p"
\t.string "Tentei capturar um Pokémon super\n"
\t.string "raro por lá, mas ele fugiu!$" """,

    "MatchCall_Text_AideAllCharms": r"""\t.string "Cedar: Oh, {PLAYER}!\n"
\t.string "Obrigado por ligar.\p"
\t.string "Sabe, quando comecei no laboratório,\n"
\t.string "não gostei da ideia de passar tanto\l"
\t.string "tempo viajando para longe!\p"
\t.string "Mas acompanhar sua jornada acabou sendo\n"
\t.string "uma verdadeira aventura para mim também!\p"
\t.string "Conheci tanto de Kanto e vi de perto\n"
\t.string "como é a vida de um Treinador.\p"
\t.string "Agora entendo por que o professor me deu\n"
\t.string "essa missão.\p"
\t.string "Muito obrigado por essa aventura!$" """,

    "MatchCall_Text_AideGameClear": r"""\t.string "Cedar: Ah, olá {PLAYER}!\p"
\t.string "Parabéns por se tornar o grande campeão!\p"
\t.string "Ainda tenho alguns presentes do\n"
\t.string "professor para te entregar.\p"
\t.string "Se eu não estiver no laboratório,\n"
\t.string "fale com o assistente à esquerda\l"
\t.string "da entrada que ele dirá onde estou.\l"
\t.string "Au revoir!$" """,

    # Looker
    "MatchCall_Text_LookerIntro": r"""\t.string "Looker: A Equipe Rocket...\p"
\t.string "Eles não ligam para quem machucam,\n"
\t.string "desde que isso lhes renda dinheiro!\p"
\t.string "Pessoas...\n"
\t.string "Pokémon...\l"
\t.string "Nós precisamos protegê-los!\p"
\t.string "Por isso jurei impedir a Equipe Rocket.$" """,

    "MatchCall_Text_LookerCeladon": r"""\t.string "Looker: Olá, {PLAYER}!\p"
\t.string "Com o esquema de recrutamento deles\n"
\t.string "desmantelado em Cerulean, precisamos\l"
\t.string "descobrir onde a Equipe Rocket\l"
\t.string "está se escondendo.\p"
\t.string "Meu instinto diz que é numa cidade próxima,\n"
\t.string "mas pode ser em qualquer lugar.\p"
\t.string "Fique de olhos abertos para qualquer\n"
\t.string "atividade suspeita!$" """,

    "MatchCall_Text_LookerRocketHideout": r"""\t.string "Looker: Ah, é você, {PLAYER}.\n"
\t.string "Obrigado pela pista sobre o esconderijo\l"
\t.string "da Equipe Rocket em Celadon.\p"
\t.string "Isso certamente vai atrasar as operações\n"
\t.string "deles por um bom tempo!$" """,

    "MatchCall_Text_LookerSaffron": r"""\t.string "Looker: Sinto muito, {PLAYER}, mas\n"
\t.string "não tenho tempo para falar agora!\p"
\t.string "Interceptamos alguns planos da Equipe\n"
\t.string "Rocket, e parece que o próximo golpe\l"
\t.string "deles será em Saffron!\p"
\t.string "...o quê!?\p"
\t.string "Você disse que eles já estão lá?\n"
\t.string "Chegamos tarde de novo!\p"
\t.string "Tome muito cuidado, {PLAYER}!$" """,

    "MatchCall_Text_LookerSilphCo": r"""\t.string "Looker: {PLAYER}, obrigado de novo.\p"
\t.string "Não pegamos o líder deles, mas pelo\n"
\t.string "menos salvamos a cidade de Saffron.\p"
\t.string "Logo descobriremos quem dá as ordens.\p"
\t.string "Os dias da Equipe Rocket estão contados!$" """,

    "MatchCall_Text_LookerGiovanni": r"""\t.string "Looker: Giovanni pode ter escapado,\n"
\t.string "mas este deve ser o fim da\l"
\t.string "Equipe Rocket.\p"
\t.string "Toda a minha equipe está em dívida com você!$" """,

    "MatchCall_Text_LookerPostgameReady": r"""\t.string "Looker: {PLAYER}!\p"
\t.string "É uma emergência!\p"
\t.string "A Equipe Rocket ressurgiu\n"
\t.string "na cidade de Saffron!\p"
\t.string "Fizeram o Presidente da Silph Co.\n"
\t.string "de refém novamente...\p"
\t.string "...e tem mais uma coisa...\p"
\t.string "Te explicarei quando chegar aqui.\p"
\t.string "Venha me encontrar em Saffron\n"
\t.string "imediatamente!$" """,

    "MatchCall_Text_LookerPostgameWaiting": r"""\t.string "Looker: {PLAYER}!\p"
\t.string "Depressa, venha para Saffron!$" """,

    "MatchCall_Text_LookerPostgameCompleted": r"""\t.string "Looker: Equipe Rocket!\p"
\t.string "Eles tentam de tudo para conseguir\n"
\t.string "o que querem.\p"
\t.string "Por isso temos que estar sempre atentos!\p"
\t.string "Fico feliz que Kanto tenha treinadores\n"
\t.string "como você nos ajudando, {PLAYER}.$" """,

    # Treinadores genéricos de rota
    "MatchCall_WildBattleText1": r"""\t.string "E aí, {PLAYER}!\n"
\t.string "Sou eu, {STR_VAR_1}.\p"
\t.string "Tentei capturar um {STR_VAR_2}\n"
\t.string "agora há pouco, mas ele fugiu!\p"
\t.string "Estive tão perto!\p"
\t.string "Estragou meu dia...\n"
\t.string "Até mais!$" """,

    "MatchCall_NegativeBattleText1": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Batalhei contra outro Treinador,\n"
\t.string "mas acabei perdendo.\p"
\t.string "Foi bem frustrante.\n"
\t.string "Nos vemos por aí!$" """,

    "MatchCall_PositiveBattleText1": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Aqui é {STR_VAR_1}!\p"
\t.string "Batalhei contra um Treinador agora há pouco.\n"
\t.string "Eu venci! Eu venci!\p"
\t.string "Meu {STR_VAR_2} se esforçou muito\n"
\t.string "por mim. Isso é bom demais!$" """,

    "MatchCall_SameRouteBattleRequestText1": r"""\t.string "Olá, {PLAYER}!\n"
\t.string "É {STR_VAR_1}.\p"
\t.string "Ah? Você está por aqui\n"
\t.string "perto de {STR_VAR_2} agora?\p"
\t.string "Que tal uma batalha?\n"
\t.string "Vou te esperar! Até já!$" """,

    "MatchCall_DifferentRouteBattleRequestText1": r"""\t.string "Ei, {PLAYER}{KUN}.\n"
\t.string "Aqui é {STR_VAR_1}.\l"
\t.string "Como vão as coisas?\p"
\t.string "Meus Pokémon estão ficando bem\n"
\t.string "fortes ultimamente.\p"
\t.string "Gostaria de ter outra batalha comigo?\p"
\t.string "Vamos nos encontrar perto de\n"
\t.string "{STR_VAR_2}, pode ser?$" """,

    "MatchCall_BattleFrontierStreakText1": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Você esteve no(a) {STR_VAR_2}\n"
\t.string "e venceu {STR_VAR_3} batalhas seguidas?\l"
\t.string "Que incrível!\p"
\t.string "Tenho que treinar mais meus Pokémon.\n"
\t.string "Até breve!$" """,

    "MatchCall_BattleFrontierRecordStreakText1": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Você esteve no(a) {STR_VAR_2}\n"
\t.string "e venceu {STR_VAR_3} batalhas seguidas?\l"
\t.string "Isso é impressionante!\p"
\t.string "Eu? Acho que estou evoluindo aos poucos.\n"
\t.string "Até breve!$" """,

    "MatchCall_WildBattleText2": r"""\t.string "E aí, {PLAYER}!\n"
\t.string "É {STR_VAR_1}.\p"
\t.string "Acabei de quase pegar um {STR_VAR_2},\n"
\t.string "mas ele escapou na última hora!\p"
\t.string "Foi por um triz!\n"
\t.string "Até a próxima!$" """,

    "MatchCall_NegativeBattleText2": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Perdi uma batalha contra um Treinador.\n"
\t.string "Preciso rever minha estratégia.\p"
\t.string "Até mais!$" """,

    "MatchCall_PositiveBattleText2": r"""\t.string "Olá, {PLAYER}{KUN}!\n"
\t.string "Aqui é {STR_VAR_1}!\p"
\t.string "Acabei de vencer uma batalha!\n"
\t.string "Meu {STR_VAR_2} deu um show!\p"
\t.string "Estou muito feliz!$" """,

    "MatchCall_SameRouteBattleRequestText2": r"""\t.string "Oi, {PLAYER}!\n"
\t.string "É {STR_VAR_1}.\p"
\t.string "Você está aqui perto de {STR_VAR_2}?\n"
\t.string "Vamos ter uma revanche agora!\p"
\t.string "Estou te esperando!$" """,

    "MatchCall_DifferentRouteBattleRequestText2": r"""\t.string "Ei, {PLAYER}{KUN}.\n"
\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Que tal uma nova batalha?\n"
\t.string "Venha me encontrar em {STR_VAR_2}!$" """,

    "MatchCall_BattleFrontierStreakText2": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Soube da sua sequência de vitórias\n"
\t.string "no(a) {STR_VAR_2}!\p"
\t.string "Você é fora de série!$" """,

    "MatchCall_BattleFrontierRecordStreakText2": r"""\t.string "Olá, {PLAYER}{KUN}!\n"
\t.string "Parabéns pelas {STR_VAR_3} vitórias\n"
\t.string "no(a) {STR_VAR_2}!\p"
\t.string "Um dia chego no seu nível!$" """,

    "MatchCall_WildBattleText3": r"""\t.string "E aí, {PLAYER}!\n"
\t.string "Avistei um {STR_VAR_2} selvagem,\n"
\t.string "mas ele fugiu para a floresta!\p"
\t.string "Vou continuar procurando!$" """,

    "MatchCall_NegativeBattleText3": r"""\t.string "Oi, {PLAYER}.\n"
\t.string "Tive uma derrota difícil hoje,\n"
\t.string "mas não vou desanimar!\p"
\t.string "A gente se fala!$" """,

    "MatchCall_PositiveBattleText3": r"""\t.string "Oi, {PLAYER}!\n"
\t.string "Ganhamos mais uma partida!\n"
\t.string "A equipe está afinadíssima!\p"
\t.string "Até breve!$" """,

    "MatchCall_SameRouteBattleRequestText3": r"""\t.string "Olá, {PLAYER}!\n"
\t.string "Vi que você está perto de {STR_VAR_2}.\n"
\t.string "Topa uma batalha agora?\p"
\t.string "Venha logo!$" """,

    "MatchCall_DifferentRouteBattleRequestText3": r"""\t.string "Ei, {PLAYER}{KUN}!\n"
\t.string "Que tal marcarmos uma revanche\n"
\t.string "perto de {STR_VAR_2}?\p"
\t.string "Te espero por lá!$" """,

    "MatchCall_BattleFrontierStreakText3": r"""\t.string "Uau, {PLAYER}{KUN}!\n"
\t.string "{STR_VAR_3} vitórias seguidas em\n"
\t.string "{STR_VAR_2}? Sensacional!$" """,

    "MatchCall_BattleFrontierRecordStreakText3": r"""\t.string "Olá, {PLAYER}{KUN}!\n"
\t.string "Seu recorde no(a) {STR_VAR_2}\n"
\t.string "é incrível! Parabéns!$" """,

    "MatchCall_WildBattleText4": r"""\t.string "Olá, {PLAYER}!\n"
\t.string "Quase capturei um {STR_VAR_2}!\n"
\t.string "Da próxima não escapa!$" """,

    "MatchCall_NegativeBattleText4": r"""\t.string "Oi, {PLAYER}.\n"
\t.string "As batalhas têm sido duras,\n"
\t.string "mas faz parte do treino!$" """,

    "MatchCall_PositiveBattleText4": r"""\t.string "E aí, {PLAYER}!\n"
\t.string "Venci mais um duelo!\n"
\t.string "Meu Pokémon foi genial!$" """,

    "MatchCall_SameRouteBattleRequestText4": r"""\t.string "Ei, {PLAYER}!\n"
\t.string "Você está por {STR_VAR_2}?\n"
\t.string "Venha batalhar comigo!$" """,

    "MatchCall_DifferentRouteBattleRequestText4": r"""\t.string "Olá, {PLAYER}{KUN}!\n"
\t.string "Vamos batalhar de novo?\n"
\t.string "Me encontre em {STR_VAR_2}!$" """,

    "MatchCall_BattleFrontierStreakText4": r"""\t.string "Caramba, {PLAYER}{KUN}!\n"
\t.string "Arrasou no(a) {STR_VAR_2}!\n"
\t.string "Continue assim!$" """,

    "MatchCall_BattleFrontierRecordStreakText4": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Suas vitórias no(a) {STR_VAR_2}\n"
\t.string "me inspiram a treinar mais!$" """,

    "MatchCall_WildBattleText5": r"""\t.string "E aí, {PLAYER}!\n"
\t.string "Tentei pegar um {STR_VAR_2} forte,\n"
\t.string "mas ele correu! Uma pena!$" """,

    "MatchCall_NegativeBattleText5": r"""\t.string "Oi, {PLAYER}.\n"
\t.string "Acabei perdendo hoje,\n"
\t.string "mas amanhã é outro dia!$" """,

    "MatchCall_PositiveBattleText5": r"""\t.string "Olá, {PLAYER}!\n"
\t.string "Consegui uma grande vitória!\n"
\t.string "Estou muito orgulhoso!$" """,

    "MatchCall_SameRouteBattleRequestText5": r"""\t.string "Ei, {PLAYER}!\n"
\t.string "Você está aqui em {STR_VAR_2}?\n"
\t.string "Não me faça esperar, venha batalhar!$" """,

    "MatchCall_DifferentRouteBattleRequestText5": r"""\t.string "Olá, {PLAYER}{KUN}.\n"
\t.string "Que tal uma nova disputa?\n"
\t.string "Vamos nos ver em {STR_VAR_2}!$" """,

    "MatchCall_BattleFrontierStreakText5": r"""\t.string "Oi, {PLAYER}{KUN}!\n"
\t.string "Vitórias consecutivas no(a) {STR_VAR_2}?\n"
\t.string "Que façanha incrível!$" """,

    "MatchCall_BattleFrontierRecordStreakText5": r"""\t.string "Olá, {PLAYER}{KUN}!\n"
\t.string "Parabéns pelo recorde no(a) {STR_VAR_2}!\n"
\t.string "Você é um exemplo!$" """,

    # Mensagens Personalizadas
    "MatchCall_PersonalizedText1": r"""\t.string "Snif... Sou eu... {STR_VAR_1}...\n"
\t.string "...Snif...\p"
\t.string "Minha professora me deu uma bronca\n"
\t.string "na aula hoje.\p"
\t.string "Mas eu não tenho raiva dela.\p"
\t.string "Ela me ensina exatamente onde errei\n"
\t.string "para que eu possa aprender.\p"
\t.string "Com certeza estarei na Escola de\n"
\t.string "Treinadores amanhã!\p"
\t.string "Até mais!$" """,

    "MatchCall_PersonalizedText2": r"""\t.string "É o {STR_VAR_1}!\p"
\t.string "Estou um pouco ocupado, mas queria\n"
\t.string "te contar que derrotei cinco Treinadores\l"
\t.string "hoje de novo.\p"
\t.string "Se eu mantiver esse ritmo, poderei\n"
\t.string "te vencer da próxima vez.\p"
\t.string "Seremos grandes rivais, você e eu.\n"
\t.string "Até logo!$" """,

    "MatchCall_PersonalizedText3": r"""\t.string "Sou eu, {STR_VAR_1}, você sabe,\n"
\t.string "o especialista em acampar!\p"
\t.string "Quando lutamos, acabei perdendo.\p"
\t.string "Afinal, minha especialidade é acampar.\p"
\t.string "Mas ganhando ou perdendo, eu adoro\n"
\t.string "batalhar enquanto acampo.\p"
\t.string "Vamos batalhar de novo, ok?\n"
\t.string "Ah, e vamos acampar também!$" """,

    "MatchCall_PersonalizedText4": r"""\t.string "Sou eu, {STR_VAR_1},\n"
\t.string "o amante das montanhas!\p"
\t.string "Desde que nos conhecemos, você aprendeu\n"
\t.string "a valorizar mais as montanhas?\p"
\t.string "Raramente te vejo por aqui...\p"
\t.string "Da próxima vez, nos vemos em\n"
\t.string "{STR_VAR_2}.$" """,

    "MatchCall_PersonalizedText5": r"""\t.string "Sou eu, {STR_VAR_1}.\p"
\t.string "Sou popular porque tenho vários\n"
\t.string "Pokémon Inseto, né?\p"
\t.string "Bem, levei vários dos meus favoritos\n"
\t.string "para a escola hoje.\p"
\t.string "A garota que eu gosto começou a chorar!\n"
\t.string "Pode rir se quiser.\p"
\t.string "Tenho que tentar ensiná-la o quanto\n"
\t.string "Pokémon Inseto são fascinantes.\p"
\t.string "Snif...\n"
\t.string "Até mais!$" """,

    "MatchCall_PersonalizedText6": r"""\t.string "Ei, {PLAYER}!\n"
\t.string "Aqui é {STR_VAR_1}!\p"
\t.string "{STR_VAR_2} é uma rota muito movimentada,\n"
\t.string "então sou desafiado por todo tipo de\l"
\t.string "Treinador todos os dias.\p"
\t.string "Hoje venci cinco batalhas e perdi\n"
\t.string "apenas três!\p"
\t.string "Como foi seu dia?\n"
\t.string "Me conte na próxima vez, tá?$" """,

    "MatchCall_PersonalizedText7": r"""\t.string "Ei, {PLAYER}!\n"
\t.string "É o Bernie.\p"
\t.string "Adivinha só?\p"
\t.string "Vivo perdendo minha chave inglesa\n"
\t.string "porque sempre que a coloco no chão,\l"
\t.string "meu Magnemite corre e ela gruda nele!\p"
\t.string "Quem precisa de caixa de ferramentas\n"
\t.string "quando se tem Pokémon magnéticos?\p"
\t.string "O difícil é fazê-lo soltar a chave\n"
\t.string "quando preciso apertar parafusos...\p"
\t.string "Será que ele brincaria de buscar\n"
\t.string "se eu jogasse a chave?\p"
\t.string "Bem, preciso voltar ao trabalho.\n"
\t.string "Tenha um dia maravilhoso!$" """,

    "MatchCall_PersonalizedText8": r"""\t.string "Ahoy!\n"
\t.string "Aqui é {STR_VAR_1}!\p"
\t.string "Como sempre, pescando com paixão!\p"
\t.string "Será que existem outros lugares para\n"
\t.string "pescar além do mar e dos rios?\p"
\t.string "Dá uma vontade imensa de jogar a linha\n"
\t.string "em qualquer lugar!\p"
\t.string "Caramba!\n"
\t.string "Minha linha embaraçou!\p"
\t.string "Preciso ir!\n"
\t.string "Descubra novos pontos de pesca para mim!$" """,

    "MatchCall_PersonalizedText9": r"""\t.string "Sou eu, {STR_VAR_1}.\n"
\t.string "Como vão suas viagens?\p"
\t.string "...Uau, é mesmo?\n"
\t.string "Parece muito estimulante!\p"
\t.string "Acho que poderia compor uma música\n"
\t.string "sobre uma de suas aventuras.\p"
\t.string "...Ah, estou sentindo a inspiração!\n"
\t.string "Consigo ouvir os acordes na minha cabeça.\p"
\t.string "Melhor eu anotar essa melodia logo,\n"
\t.string "então preciso voar! Até depois!$" """,

    "MatchCall_PersonalizedText10": r"""\t.string "Eu amo Pokémon!\n"
\t.string "É a {STR_VAR_1}!\p"
\t.string "Você precisa ouvir isso!\n"
\t.string "Meu amado Pokémon...\p"
\t.string "Hahaha!\n"
\t.string "Não posso contar mais! É segredo!\l"
\t.string "É fofo demais para descrever em palavras!\p"
\t.string "Olha, meu querido {STR_VAR_2} está\n"
\t.string "pedindo um {POKEBLOCK}!\p"
\t.string "É a imagem da fofura!\p"
\t.string "Desculpe, não posso falar agora!\n"
\t.string "Te conto tudo da próxima vez!$" """,

    "MatchCall_PersonalizedText11": r"""\t.string "Ufufufufu...\n"
\t.string "Sou eu, {STR_VAR_1}...\p"
\t.string "Adivinha o que estou vendo?\n"
\t.string "Um par de {STR_VAR_2} em batalha.\p"
\t.string "Talvez eu capture o vencedor...\n"
\t.string "Ufufufufufu...\p"
\t.string "Eu... estou meio ocupada agora.\n"
\t.string "Tenho que ir.$" """,

    "MatchCall_PersonalizedText12": r"""\t.string "É {STR_VAR_1}.\p"
\t.string "Quando há um Treinador forte por perto,\n"
\t.string "às vezes consigo pressentir isso.\p"
\t.string "Você passou por aqui perto, {PLAYER}{KUN}?\n"
\t.string "Talvez tenha sido você.\p"
\t.string "Estarei esperando sua visita.\n"
\t.string "Tchau!$" """,

    "MatchCall_PersonalizedText13": r"""\t.string "Vruuuuuuuuum!\p"
\t.string "Ei! É o {STR_VAR_1}! Hahaha!\p"
\t.string "Tentar conversar...\n"
\t.string "Enquanto pedalo na bike...\l"
\t.string "É muito perigoso!\p"
\t.string "Conversamos... outra hora...\l"
\t.string "Não quero bater de cara no chão!!$" """,

    "MatchCall_PersonalizedText14": r"""\t.string "Ihuuu, é o {STR_VAR_1}!\n"
\t.string "Como você está?\p"
\t.string "Estive treinando meus Pokémon tendo\n"
\t.string "você como objetivo.\p"
\t.string "Não pretendo perder na próxima luta.\p"
\t.string "Não é ótimo ter amigos Treinadores?\n"
\t.string "Vamos nos ver de novo!$" """,

    "MatchCall_PersonalizedText15": r"""\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Meu {STR_VAR_2} ficou ainda mais\n"
\t.string "forte do que da última vez.\p"
\t.string "Não vou perder para você de novo.\n"
\t.string "Espere até a próxima!\p"
\t.string "Nos vemos por aí!$" """,

    "MatchCall_PersonalizedText16": r"""\t.string "Ohoho!\p"
\t.string "Aqui é {STR_VAR_1}! Mal posso esperar\n"
\t.string "para falar do meu querido Pokémon!\p"
\t.string "Por favor, você precisa ouvir.\n"
\t.string "É sobre meu adorável {STR_VAR_2}.\p"
\t.string "Sempre que alguém tenta pegá-lo,\n"
\t.string "ele pula direto nos meus braços!\p"
\t.string "Oh... Haveria algo mais abençoado?\p"
\t.string "É uma sensação tão divina!\p"
\t.string "Fico tão feliz em compartilhar um pouco\n"
\t.string "da minha alegria com você.\p"
\t.string "Bem, preciso ir.\n"
\t.string "Até mais!$" """,

    "MatchCall_PersonalizedText17": r"""\t.string "Ah, é o {STR_VAR_1}, olá.\p"
\t.string "Tenho nadado bastante, mas ainda\n"
\t.string "não consigo chegar a Cinnabar.\p"
\t.string "Talvez eu esteja nadando em círculos.\p"
\t.string "Não, não, isso é impossível.\n"
\t.string "Hahaha.\l"
\t.string "Se cuide!$" """,

    "MatchCall_PersonalizedText18": r"""\t.string "Olá, {PLAYER}{KUN}.\n"
\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Como estão seus Pokémon?\p"
\t.string "Meus Pokémon Dragão parecem estar\n"
\t.string "no ápice da forma. Até mais.$" """,

    "MatchCall_PersonalizedText19": r"""\t.string "Aqui é {STR_VAR_1}.\p"
\t.string "Continuei com meus estudos\n"
\t.string "na arte do malabarismo.\p"
\t.string "Não tenho tido muito sucesso.\n"
\t.string "Parecido com treinar um Abra...\p"
\t.string "Às vezes sinto que minha vida é igual\n"
\t.string "às minhas bolas de malabarismo...\p"
\t.string "Caem no chão e quicam por aí\n"
\t.string "no mais completo caos.\p"
\t.string "Até logo, {PLAYER}!$" """,

    "MatchCall_PersonalizedText20": r"""\t.string "Olá, aqui é {STR_VAR_1}...\p"
\t.string "Fiquei um pouco cansada de toda essa\n"
\t.string "expectativa de Treinadora Maneira...\p"
\t.string "Todo mundo acha que sou impecável,\n"
\t.string "e isso me pressiona a corresponder.\p"
\t.string "Mas acho que faz parte do papel.\p"
\t.string "Vou apenas respirar fundo...\n"
\t.string "e seguir em frente com um sorriso.\p"
\t.string "Você é a única pessoa com quem posso\n"
\t.string "desabafar assim.\p"
\t.string "Mas quando nos vermos da próxima vez,\n"
\t.string "não se preocupe, não vou reclamar!$" """
}

with open('data/text/match_call.inc', 'r', encoding='utf-8') as f:
    content = f.read()

import re

count = 0
for label, replacement in translations.items():
    # Convert literal \t to real tab
    replacement = replacement.replace('\\t', '\t')
    # Regex to find label:: and its following .string lines
    pattern = rf'({re.escape(label)}::?\s*\n)((?:\t\.string\s+"[^"]*"\n)+)'
    match = re.search(pattern, content)
    if match:
        content = content[:match.start(2)] + replacement + "\n" + content[match.end(2):]
        count += 1
    else:
        print(f"WARN: Label not found: {label}")

content = content.replace('\r\n', '\n')
with open('data/text/match_call.inc', 'w', encoding='utf-8', newline='\n') as f:
    f.write(content)

print(f"Successfully replaced {count}/{len(translations)} labels in data/text/match_call.inc!")
