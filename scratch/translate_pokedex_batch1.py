# -*- coding: utf-8 -*-
import re

# Categorias da Pokédex (Lote 1: #152 a #201)
categories_lote1 = {
    "NATIONAL_DEX_CHIKORITA": "Folha",
    "NATIONAL_DEX_BAYLEEF": "Folha",
    "NATIONAL_DEX_MEGANIUM": "Erva",
    "NATIONAL_DEX_CYNDAQUIL": "Rato de Fogo",
    "NATIONAL_DEX_QUILAVA": "Vulcão",
    "NATIONAL_DEX_TYPHLOSION": "Vulcão",
    "NATIONAL_DEX_TOTODILE": "Mandibulão",
    "NATIONAL_DEX_CROCONAW": "Mandibulão",
    "NATIONAL_DEX_FERALIGATR": "Mandibulão",
    "NATIONAL_DEX_SENTRET": "Sentinela",
    "NATIONAL_DEX_FURRET": "Corpo Longo",
    "NATIONAL_DEX_HOOTHOOT": "Coruja",
    "NATIONAL_DEX_NOCTOWL": "Coruja",
    "NATIONAL_DEX_LEDYBA": "Cinco Estrelas",
    "NATIONAL_DEX_LEDIAN": "Cinco Estrelas",
    "NATIONAL_DEX_SPINARAK": "Fio de Teia",
    "NATIONAL_DEX_ARIADOS": "Perna Longa",
    "NATIONAL_DEX_CROBAT": "Morcego",
    "NATIONAL_DEX_CHINCHOU": "Pescador",
    "NATIONAL_DEX_LANTURN": "Luz",
    "NATIONAL_DEX_PICHU": "Ratinho",
    "NATIONAL_DEX_CLEFFA": "Estrela",
    "NATIONAL_DEX_IGGLYBUFF": "Balão",
    "NATIONAL_DEX_TOGEPI": "Bola Espinho",
    "NATIONAL_DEX_TOGETIC": "Felicidade",
    "NATIONAL_DEX_NATU": "Passarinho",
    "NATIONAL_DEX_XATU": "Místico",
    "NATIONAL_DEX_MAREEP": "Lã",
    "NATIONAL_DEX_FLAAFFY": "Lã",
    "NATIONAL_DEX_AMPHAROS": "Luz",
    "NATIONAL_DEX_BELLOSSOM": "Flor",
    "NATIONAL_DEX_MARILL": "Rato d'Água",
    "NATIONAL_DEX_AZUMARILL": "Coelho d'Água",
    "NATIONAL_DEX_SUDOWOODO": "Imitação",
    "NATIONAL_DEX_POLITOED": "Sapo",
    "NATIONAL_DEX_HOPPIP": "Dente de Leão",
    "NATIONAL_DEX_SKIPLOOM": "Dente de Leão",
    "NATIONAL_DEX_JUMPLUFF": "Dente de Leão",
    "NATIONAL_DEX_AIPOM": "Cauda Longa",
    "NATIONAL_DEX_SUNKERN": "Semente",
    "NATIONAL_DEX_SUNFLORA": "Sol",
    "NATIONAL_DEX_YANMA": "Asa Transpar.",
    "NATIONAL_DEX_WOOPER": "Peixe d'Água",
    "NATIONAL_DEX_QUAGSIRE": "Peixe d'Água",
    "NATIONAL_DEX_ESPEON": "Sol",
    "NATIONAL_DEX_UMBREON": "Luar",
    "NATIONAL_DEX_MURKROW": "Escuridão",
    "NATIONAL_DEX_SLOWKING": "Régio",
    "NATIONAL_DEX_MISDREAVUS": "Guincho",
    "NATIONAL_DEX_UNOWN": "Símbolo"
}

# Textos descritivos da Pokédex (Lote 1: #152 a #201)
pokedex_text_lote1 = {
    "gChikoritaPokedexText": (
        '    "Balança a folha de sua cabeça para afastar\\n"\n'
        '    "adversários. Um aroma suave e relaxante sai\\n"\n'
        '    "da folha, criando uma atmosfera amigável que\\n"\n'
        '    "acalma todos na batalha.");'
    ),
    "gBayleefPokedexText": (
        '    "O pescoço de Bayleef é rodeado de folhas\\n"\n'
        '    "curvadas. Dentro de cada folha há um pequeno\\n"\n'
        '    "broto de árvore cujo perfume revigorante\\n"\n'
        '    "enche as pessoas de energia.");'
    ),
    "gMeganiumPokedexText": (
        '    "O aroma da flor de Meganium acalma as emoções.\\n"\n'
        '    "Durante as lutas, ele libera ainda mais de seu\\n"\n'
        '    "perfume calmante para enfraquecer o espírito\\n"\n'
        '    "combativo do oponente.");'
    ),
    "gCyndaquilPokedexText": (
        '    "Solta chamas pelas costas para se proteger.\\n"\n'
        '    "O fogo arde intensamente quando o Pokémon está\\n"\n'
        '    "irritado. Quando fica cansado, solta apenas\\n"\n'
        '    "pequenas faíscas vacilantes.");'
    ),
    "gQuilavaPokedexText": (
        '    "Intimida adversários com rajadas fortes de\\n"\n'
        '    "chamas e ar superaquecido. Sua agilidade veloz\\n"\n'
        '    "permite desviar de ataques enquanto queima\\n"\n'
        '    "o oponente sem piedade.");'
    ),
    "gTyphlosionPokedexText": (
        '    "Esconde-se atrás de névoas de calor criadas\\n"\n'
        '    "por suas chamas. Typhlosion é capaz de gerar\\n"\n'
        '    "explosões de fogo devastadoras que reduzem\\n"\n'
        '    "tudo em seu caminho a cinzas.");'
    ),
    "gTotodilePokedexText": (
        '    "Apesar do corpo pequeno, suas mandíbulas são\\n"\n'
        '    "muito fortes. Embora ache que está apenas\\n"\n'
        '    "mordiscando por brincadeira, sua mordida tem\\n"\n'
        '    "força suficiente para ferir gravemente.");'
    ),
    "gCroconawPokedexText": (
        '    "Uma vez que prende a presa com suas presas,\\n"\n'
        '    "nunca mais a solta. Seus dentes afiados voltam\\n"\n'
        '    "a crescer sem parar se forem arrancados\\n"\n'
        '    "durante um combate feroz.");'
    ),
    "gFeraligatrPokedexText": (
        '    "Costuma intimidar adversários abrindo suas\\n"\n'
        '    "grandes mandíbulas. Na luta, corre com grande\\n"\n'
        '    "velocidade apoiado nas patas traseiras para\\n"\n'
        '    "abocanhar a presa de repente.");'
    ),
    "gSentretPokedexText": (
        '    "Ao dormir, revezam para que um fique sempre de\\n"\n'
        '    "vigia. A sentinela acorda o bando batendo a cauda\\n"\n'
        '    "no chão ou gritando caso perceba qualquer\\n"\n'
        '    "perigo se aproximando.");'
    ),
    "gFurretPokedexText": (
        '    "Possui um corpo esguio e muito flexível. Quando\\n"\n'
        '    "é atacado, escapa com agilidade por qualquer\\n"\n'
        '    "pequeno buraco e fendas estreitas onde o rival\\n"\n'
        '    "jamais consegue entrar.");'
    ),
    "gHoothootPokedexText": (
        '    "Possui um órgão interno que sente a rotação da\\n"\n'
        '    "Terra. Por isso, começa a piar todos os dias\\n"\n'
        '    "exatamente no mesmo horário, funcionando feito\\n"\n'
        '    "um relógio confiável.");'
    ),
    "gNoctowlPokedexText": (
        '    "Seus olhos captam qualquer fresta de luz mesmo\\n"\n'
        '    "na escuridão total. Voa silenciosamente sem que\\n"\n'
        '    "as asas façam barulho, pegando presas desprevenidas\\n"\n'
        '    "no meio da noite.");'
    ),
    "gLedybaPokedexText": (
        '    "É muito tímido e costuma ter medo de agir sozinho.\\n"\n'
        '    "Quando o clima esfria, muitos Ledyba se juntam de\\n"\n'
        '    "todos os cantos para se aquecerem em grupos\\n"\n'
        '    "muito unidos.");'
    ),
    "gLedianPokedexText": (
        '    "Dizem que nos locais onde o céu noturno tem muitas\\n"\n'
        '    "estrelas vivem grandes bandos de Ledian. Eles\\n"\n'
        '    "acumulam luz estelar para convertê-la em energia\\n"\n'
        '    "para suas lutas.");'
    ),
    "gSpinarakPokedexText": (
        '    "A teia que tece pode ser considerada o seu segundo\\n"\n'
        '    "sistema nervoso. Consegue descobrir o tipo da presa\\n"\n'
        '    "apenas sentindo as vibrações sutis nos fios de\\n"\n'
        '    "sua armadilha.");'
    ),
    "gAriadosPokedexText": (
        '    "Seus pés têm ganchos minúsculos que lhe permitem\\n"\n'
        '    "andar por tetos e paredes. Prende o inimigo com\\n"\n'
        '    "fios de seda resistentes disparados pela boca e\\n"\n'
        '    "pela cauda ao mesmo tempo.");'
    ),
    "gCrobatPokedexText": (
        '    "O desenvolvimento de asas nas patas traseiras o\\n"\n'
        '    "tornou extremamente veloz. Consegue voar por longas\\n"\n'
        '    "distâncias descansando pares de asas de forma\\n"\n'
        '    "alternada.");'
    ),
    "gChinchouPokedexText": (
        '    "Nas profundezas escuras do oceano, seu único modo\\n"\n'
        '    "de comunicação é piscando as luzes de suas duas\\n"\n'
        '    "antenas. Gera eletricidade positiva e negativa\\n"\n'
        '    "na ponta delas.");'
    ),
    "gLanturnPokedexText": (
        '    "A luz intensa emitida por sua antena consegue\\n"\n'
        '    "iluminar o oceano a mais de 5.000 metros de\\n"\n'
        '    "profundidade, ganhando o apelido carinhoso de\\n"\n'
        '    "Estrela do Fundo do Mar.");'
    ),
    "gPichuPokedexText": (
        '    "Ainda é pequeno e não tem controle total de sua\\n"\n'
        '    "eletricidade. Pode descarregar choques por acidente\\n"\n'
        '    "quando se assusta ou quando dá risadas de\\n"\n'
        '    "pura alegria.");'
    ),
    "gCleffaPokedexText": (
        '    "Em noites com chuvas de meteoros, muitos Cleffa\\n"\n'
        '    "podem ser vistos dançando em círculos. Dizem que\\n"\n'
        '    "avistar um dançando traz muita sorte para a vida\\n"\n'
        '    "inteira.");'
    ),
    "gIgglybuffPokedexText": (
        '    "Seu corpo é extremamente macio e elástico como\\n"\n'
        '    "um balão. Ao começar a quicar, ganha tanto impulso\\n"\n'
        '    "que fica difícil fazê-lo parar sem ajuda de\\n"\n'
        '    "seu treinador.");'
    ),
    "gTogepiPokedexText": (
        '    "Usa sentimentos positivos e a alegria das pessoas\\n"\n'
        '    "para encher sua casca de energia. Dizem que divide\\n"\n'
        '    "toda essa felicidade acumulada com quem o trata\\n"\n'
        '    "com carinho.");'
    ),
    "gTogeticPokedexText": (
        '    "Dizem que é um Pokémon que traz muita sorte. Ao\\n"\n'
        '    "encontrar alguém de coração bondoso e puro, ele\\n"\n'
        '    "aparece flutuando suavemente para compartilhar\\n"\n'
        '    "sua alegria sincera.");'
    ),
    "gNatuPokedexText": (
        '    "Costuma pular de galho em galho, pois suas asas\\n"\n'
        '    "ainda não se desenvolveram o bastante para voar.\\n"\n'
        '    "Passa o tempo todo encarando fixamente algo no\\n"\n'
        '    "chão com atenção.");'
    ),
    "gXatuPokedexText": (
        '    "Permanece quase imóvel o dia inteiro encarando o\\n"\n'
        '    "sol. Dizem que com seu olho direito enxerga o futuro\\n"\n'
        '    "e com o olho esquerdo contempla o passado de\\n"\n'
        '    "todo o mundo.");'
    ),
    "gMareepPokedexText": (
        '    "Sua lã farta acumula eletricidade estática. Quanto\\n"\n'
        '    "mais estática acumula, mais a lâmpada na ponta de\\n"\n'
        '    "sua cauda brilha com intensidade no campo aberto.");'
    ),
    "gFlaaffyPokedexText": (
        '    "Sua pele emborrachada impede que ele leve choques\\n"\n'
        '    "da própria eletricidade. A lã em seu corpo guarda\\n"\n'
        '    "tanta carga que dispara raios se for tocada com\\n"\n'
        '    "descuido.");'
    ),
    "gAmpharosPokedexText": (
        '    "A luz intensa da ponta de sua cauda pode ser vista\\n"\n'
        '    "de muito longe, mesmo do espaço. Desde a antiguidade,\\n"\n'
        '    "ele é usado como farol guia para navegantes em\\n"\n'
        '    "alto-mar.");'
    ),
    "gBellossomPokedexText": (
        '    "Quando Bellossom dança sob a luz do sol, suas pétalas\\n"\n'
        '    "se chocam produzindo sons suaves e encantadores.\\n"\n'
        '    "Aparece com frequência em ilhas e regiões do sul.");'
    ),
    "gMarillPokedexText": (
        '    "A ponta de sua cauda flutua como uma boia cheia de\\n"\n'
        '    "óleo leve. Graças a isso, consegue nadar sem se afogar\\n"\n'
        '    "mesmo em rios com fortes correntes e corredeiras.");'
    ),
    "gAzumarillPokedexText": (
        '    "Passa a maior parte do dia debaixo d\'água. Suas orelhas\\n"\n'
        '    "longas conseguem escutar sons distantes com clareza,\\n"\n'
        '    "sabendo exatamente o que se move em rios caudalosos.");'
    ),
    "gSudowoodoPokedexText": (
        '    "Disfarça-se de árvore para não ser atacado. Como suas\\n"\n'
        '    "patas permanecem verdes no inverno, seu disfarce é\\n"\n'
        '    "descoberto no frio. Odeia água e foge na chuva.");'
    ),
    "gPolitoedPokedexText": (
        '    "Ao cantar com sua voz rouca inflando a garganta,\\n"\n'
        '    "Poliwag e Poliwhirl de todas as partes se reúnem ao\\n"\n'
        '    "seu redor para obedecer às suas ordens de líder.");'
    ),
    "gHoppipPokedexText": (
        '    "Flutua levado pelas brisas suaves. Se pressente a\\n"\n'
        '    "chegada de ventos fortes, entrelaça as folhas com outros\\n"\n'
        '    "colegas e se ancora firmemente no chão para não voar.");'
    ),
    "gSkiploomPokedexText": (
        '    "A flor no topo de sua cabeça se abre quando a\\n"\n'
        '    "temperatura sobe além de 18 graus. Por esse motivo,\\n"\n'
        '    "muitas pessoas o utilizam como um termômetro natural.");'
    ),
    "gJumpluffPokedexText": (
        '    "Deixa-se levar pelos ventos quentes da primavera\\n"\n'
        '    "para viajar pelo mundo. Espalha esporos de algodão\\n"\n'
        '    "por onde passa para criar novos descendentes.");'
    ),
    "gAipomPokedexText": (
        '    "Sua cauda forte termina em uma mão tão ágil que ele\\n"\n'
        '    "a usa para quase tudo, desde colher frutas até se\\n"\n'
        '    "pendurar em galhos, usando menos os braços reais.");'
    ),
    "gSunkernPokedexText": (
        '    "Tenta se mover o mínimo possível para guardar todos os\\n"\n'
        '    "nutrientes que acumulou. Vive apenas bebendo o orvalho\\n"\n'
        '    "matinal que escorre sob as folhas das árvores.");'
    ),
    "gSunfloraPokedexText": (
        '    "Converte os raios solares em energia com grande vigor.\\n"\n'
        '    "Fica muito ativo durante o dia enquanto há sol, mas\\n"\n'
        '    "fica totalmente imóvel e repousa assim que anoitece.");'
    ),
    "gYanmaPokedexText": (
        '    "Seus olhos grandes conseguem enxergar 360 graus sem\\n"\n'
        '    "mover a cabeça. Consegue parar bruscamente no ar e\\n"\n'
        '    "mudar de rumo com extrema agilidade para caçar.");'
    ),
    "gWooperPokedexText": (
        '    "Vive na lama e em águas frias. Quando a terra esfria\\n"\n'
        '    "à noite, costuma sair da água para buscar alimento\\n"\n'
        '    "em terra firme, cobrindo o corpo com muco protetor.");'
    ),
    "gQuagsirePokedexText": (
        '    "Tem uma personalidade calma e despreocupada. Ao nadar,\\n"\n'
        '    "costuma bater a cabeça no fundo dos barcos sem se\\n"\n'
        '    "importar, continuando seu caminho tranquilamente.");'
    ),
    "gEspeonPokedexText": (
        '    "Sua pelagem fina tem a textura do veludo. A ponta de\\n"\n'
        '    "sua cauda bifurcada oscila quando lê correntes de ar\\n"\n'
        '    "para prever o próximo movimento do adversário.");'
    ),
    "gUmbreonPokedexText": (
        '    "Evoluiu ao ser exposto à luz da lua. Fica à espreita na\\n"\n'
        '    "escuridão esperando que a presa se distraia. Os anéis\\n"\n'
        '    "amarelos em seu corpo brilham quando parte para o ataque.");'
    ),
    "gMurkrowPokedexText": (
        '    "Tem o hábito de roubar objetos brilhantes e cintilantes.\\n"\n'
        '    "Costuma esconder suas preciosidades em esconderijos\\n"\n'
        '    "secretos, brigando com Aipom que tentam roubá-los.");'
    ),
    "gSlowkingPokedexText": (
        '    "A mordida de Shellder em sua cabeça liberou toxinas\\n"\n'
        '    "que despertaram uma inteligência extraordinária. Ele\\n"\n'
        '    "pesquisa os mistérios do mundo com grande calma.");'
    ),
    "gMisdreavusPokedexText": (
        '    "Gosta de assustar pessoas de repente no escuro dando\\n"\n'
        '    "gritos estridentes. Alimenta-se do medo e da surpresa\\n"\n'
        '    "daqueles que assusta para encher suas esferas de energia.");'
    ),
    "gUnownPokedexText": (
        '    "Possui o formato de antigas letras de alfabetos. Dizem\\n"\n'
        '    "que quando dois ou mais Unown se juntam, poderes\\n"\n'
        '    "estranhos e misteriosos começam a se manifestar.");'
    )
}

# 1. Atualizar pokedex_entries.h
with open('src/data/pokemon/pokedex_entries.h', 'r', encoding='utf-8') as f:
    entries_code = f.read()

count_cats = 0
for dex, cat in categories_lote1.items():
    pattern = rf'(\[{dex}\]\s*=\s*\{{[^}}]*?\.categoryName\s*=\s*_\(")[^"]*("\))'
    if re.search(pattern, entries_code):
        entries_code = re.sub(pattern, rf'\g<1>{cat}\g<2>', entries_code)
        count_cats += 1
    else:
        print(f"WARN: Category for {dex} not found")

with open('src/data/pokemon/pokedex_entries.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(entries_code)

print(f"Sucesso! {count_cats} categorias de Pokédex atualizadas no Lote 1.")

# 2. Atualizar pokedex_text.h
with open('src/data/pokemon/pokedex_text.h', 'r', encoding='utf-8') as f:
    text_code = f.read()

count_texts = 0
for var_name, replacement in pokedex_text_lote1.items():
    pattern = rf'(const u8 {var_name}\[\] = _\(\s*\n)(.*?)(?=\);)'
    m = re.search(pattern, text_code, re.DOTALL)
    if m:
        text_code = text_code[:m.start(2)] + replacement + "\n" + text_code[m.end(2) + 2:]
        count_texts += 1
    else:
        print(f"WARN: Text for {var_name} not found")

with open('src/data/pokemon/pokedex_text.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(text_code)

print(f"Sucesso! {count_texts} textos de Pokédex atualizados no Lote 1.")
