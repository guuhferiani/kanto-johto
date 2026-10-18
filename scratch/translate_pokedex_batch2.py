# -*- coding: utf-8 -*-
import re

# Categorias da Pokédex (Lote 2: #202 a #251)
categories_lote2 = {
    "NATIONAL_DEX_WOBBUFFET": "Paciente",
    "NATIONAL_DEX_GIRAFARIG": "Pescoço Longo",
    "NATIONAL_DEX_PINECO": "Pinha",
    "NATIONAL_DEX_FORRETRESS": "Espinhos",
    "NATIONAL_DEX_DUNSPARCE": "Serpente Terra",
    "NATIONAL_DEX_GLIGAR": "Escorpião Voad",
    "NATIONAL_DEX_STEELIX": "Cobra de Ferro",
    "NATIONAL_DEX_SNUBBULL": "Fada",
    "NATIONAL_DEX_GRANBULL": "Fada",
    "NATIONAL_DEX_QWILFISH": "Balão",
    "NATIONAL_DEX_SCIZOR": "Tesoura",
    "NATIONAL_DEX_SHUCKLE": "Mofo",
    "NATIONAL_DEX_HERACROSS": "Besouro",
    "NATIONAL_DEX_SNEASEL": "Garra Afiada",
    "NATIONAL_DEX_TEDDIURSA": "Ursinho",
    "NATIONAL_DEX_URSARING": "Urso",
    "NATIONAL_DEX_SLUGMA": "Lava",
    "NATIONAL_DEX_MAGCARGO": "Lava",
    "NATIONAL_DEX_SWINUB": "Porco",
    "NATIONAL_DEX_PILOSWINE": "Suíno",
    "NATIONAL_DEX_CORSOLA": "Coral",
    "NATIONAL_DEX_REMORAID": "Jato",
    "NATIONAL_DEX_OCTILLERY": "Polvo",
    "NATIONAL_DEX_DELIBIRD": "Entrega",
    "NATIONAL_DEX_MANTINE": "Arraia",
    "NATIONAL_DEX_SKARMORY": "Pássaro de Aço",
    "NATIONAL_DEX_HOUNDOUR": "Sombrio",
    "NATIONAL_DEX_HOUNDOOM": "Sombrio",
    "NATIONAL_DEX_KINGDRA": "Dragão",
    "NATIONAL_DEX_PHANPY": "Nariz Longo",
    "NATIONAL_DEX_DONPHAN": "Armadura",
    "NATIONAL_DEX_PORYGON2": "Virtual",
    "NATIONAL_DEX_STANTLER": "Chifre Grande",
    "NATIONAL_DEX_SMEARGLE": "Pintor",
    "NATIONAL_DEX_TYROGUE": "Briguento",
    "NATIONAL_DEX_HITMONTOP": "Pião",
    "NATIONAL_DEX_SMOOCHUM": "Beijoqueiro",
    "NATIONAL_DEX_ELEKID": "Elétrico",
    "NATIONAL_DEX_MAGBY": "Brasa",
    "NATIONAL_DEX_MILTANK": "Vaca Leiteira",
    "NATIONAL_DEX_BLISSEY": "Felicidade",
    "NATIONAL_DEX_RAIKOU": "Trovão",
    "NATIONAL_DEX_ENTEI": "Vulcão",
    "NATIONAL_DEX_SUICUNE": "Aurora",
    "NATIONAL_DEX_LARVITAR": "Pele de Rocha",
    "NATIONAL_DEX_PUPITAR": "Casulo Rígido",
    "NATIONAL_DEX_TYRANITAR": "Armadura",
    "NATIONAL_DEX_LUGIA": "Mergulho",
    "NATIONAL_DEX_HO_OH": "Arco-Íris",
    "NATIONAL_DEX_CELEBI": "Viajante Tempo"
}

# Textos descritivos da Pokédex (Lote 2: #202 a #251)
pokedex_text_lote2 = {
    "gWobbuffetPokedexText": (
        '    "Geralmente é dócil, mas contra-ataca com muita\\n"\n'
        '    "força se sua cauda for atacada. Esconde a cauda\\n"\n'
        '    "escura em cavernas e vive nas sombras para que\\n"\n'
        '    "ninguém a veja.");'
    ),
    "gGirafarigPokedexText": (
        '    "A cabeça na ponta de sua cauda tem um cérebro\\n"\n'
        '    "próprio e pequeno. Se você se aproximar por trás,\\n"\n'
        '    "a cauda pode reagir ao cheiro e morder de\\n"\n'
        '    "repente.");'
    ),
    "gPinecoPokedexText": (
        '    "Pendura-se em galhos de árvores esperando por\\n"\n'
        '    "presas. Cobre a casca com camadas de cascalho\\n"\n'
        '    "e cascas de árvore. Se alguém sacode a árvore,\\n"\n'
        '    "ele cai e explode.");'
    ),
    "gForretressPokedexText": (
        '    "Fica ancorado no tronco de árvores grandes. Fica\\n"\n'
        '    "sempre escondido dentro de sua concha de aço\\n"\n'
        '    "pesada, abrindo-a apenas ligeiramente para\\n"\n'
        '    "atirar espinhos.");'
    ),
    "gDunsparcePokedexText": (
        '    "Usa a cauda em formato de broca para cavar para\\n"\n'
        '    "trás e escapar para o subsolo caso veja alguém.\\n"\n'
        '    "Suas asas minúsculas quase não servem para voar,\\n"\n'
        '    "apenas para planar.");'
    ),
    "gGligarPokedexText": (
        '    "Desliza pelo ar silenciosamente abrindo suas\\n"\n'
        '    "membranas alares. Prende-se no rosto da presa\\n"\n'
        '    "com as patas e espeta seu ferrão venenoso na\\n"\n'
        '    "vítima indefesa.");'
    ),
    "gSteelixPokedexText": (
        '    "Vive nas profundezas da terra, ainda mais fundo\\n"\n'
        '    "que Onix. Dizem que seu corpo de rocha se tornou\\n"\n'
        '    "mais duro que diamante após engolir muito ferro\\n"\n'
        '    "sob calor intenso.");'
    ),
    "gSnubbullPokedexText": (
        '    "Apesar da cara de bravo e assustadora, na verdade\\n"\n'
        '    "é muito dócil, carinhoso e medroso. É muito\\n"\n'
        '    "popular entre mulheres jovens que adoram fazer\\n"\n'
        '    "carinho nele.");'
    ),
    "gGranbullPokedexText": (
        '    "Suas mandíbulas inferiores são tão pesadas que\\n"\n'
        '    "ele precisa inclinar a cabeça para equilibrar.\\n"\n'
        '    "Não morde sem motivo, a menos que seja assustado\\n"\n'
        '    "ou provocado.");'
    ),
    "gQwilfishPokedexText": (
        '    "Engole muita água para inflar o corpo redondo e\\n"\n'
        '    "atirar espinhos venenosos em todas as direções.\\n"\n'
        '    "Tem dificuldade para nadar quando está totalmente\\n"\n'
        '    "cheio d\'água.");'
    ),
    "gScizorPokedexText": (
        '    "Possui pinças de aço tão duras que conseguem\\n"\n'
        '    "esmagar qualquer objeto rígido em pedaços. Ergue\\n"\n'
        '    "as pinças decoradas com olhos falsos para intimidar\\n"\n'
        '    "o adversário.");'
    ),
    "gShucklePokedexText": (
        '    "Guarda frutas colhidas dentro de sua carapaça\\n"\n'
        '    "em formato de vaso. As frutas fermentam com seus\\n"\n'
        '    "fluidos corporais com o passar do tempo, virando\\n"\n'
        '    "um delicioso suco.");'
    ),
    "gHeracrossPokedexText": (
        '    "Tem uma força descomunal capaz de arremessar\\n"\n'
        '    "coisas cem vezes mais pesadas que ele com seu\\n"\n'
        '    "chifre poderoso. Adora a seiva doce de árvores\\n"\n'
        '    "na floresta.");'
    ),
    "gSneaselPokedexText": (
        '    "Escala árvores cravando suas garras curvas nas\\n"\n'
        '    "cascas. Procura ninhos de Pidgey para roubar ovos\\n"\n'
        '    "desprotegidos enquanto os pais estão distraídos\\n"\n'
        '    "procurando comida.");'
    ),
    "gTeddiursaPokedexText": (
        '    "Suas patas estão sempre lambuzadas de mel doce.\\n"\n'
        '    "Passa o dia todo lambendo as patas para saborear\\n"\n'
        '    "o mel que colhe em colmeias de Combee e\\n"\n'
        '    "Beedrill.");'
    ),
    "gUrsaringPokedexText": (
        '    "Embora tenha um corpo enorme, sabe subir em árvores\\n"\n'
        '    "com facilidade para colher frutas e dormir. Marca\\n"\n'
        '    "seu território arranhando troncos de árvores com\\n"\n'
        '    "suas garras.");'
    ),
    "gSlugmaPokedexText": (
        '    "Seu corpo é feito de magma fervente. Ele nunca\\n"\n'
        '    "dorme porque precisa se manter em constante\\n"\n'
        '    "movimento; se parar por muito tempo, a lava de\\n"\n'
        '    "seu corpo esfria e endurece.");'
    ),
    "gMagcargoPokedexText": (
        '    "A temperatura de seu corpo chega a quase 10.000\\n"\n'
        '    "graus. Chamas intensas escapam pelas frestas de\\n"\n'
        '    "sua concha de pedra de lava, que se quebra e\\n"\n'
        '    "regenera sempre.");'
    ),
    "gSwinubPokedexText": (
        '    "Esfrega o focinho no chão para desenterrar comida.\\n"\n'
        '    "Seu prato favorito são cogumelos que crescem sob\\n"\n'
        '    "a grama morta. Consegue farejar raízes mesmo sob\\n"\n'
        '    "camadas de gelo.");'
    ),
    "gPiloswinePokedexText": (
        '    "Seus pelos compridos e grossos o protegem contra\\n"\n'
        '    "o frio congelante. Como a pelagem cobre seus olhos,\\n"\n'
        '    "ele usa o olfato apurado para se guiar e corre com\\n"\n'
        '    "suas presas.");'
    ),
    "gCorsolaPokedexText": (
        '    "Galhos de coral crescem em sua cabeça. Em mares\\n"\n'
        '    "quentes e límpidos, muitos Corsola se juntam para\\n"\n'
        '    "formar colônias grandes que servem de abrigo para\\n"\n'
        '    "outros Pokémon.");'
    ),
    "gRemoraidPokedexText": (
        '    "Cospe jatos d\'água com enorme pressão e precisão\\n"\n'
        '    "para derrubar insetos voando sobre a água. Costuma\\n"\n'
        '    "se prender com a barbatana dorsal na asa de\\n"\n'
        '    "Mantine.");'
    ),
    "gOctilleryPokedexText": (
        '    "Costuma se abrigar em buracos de rochas no fundo\\n"\n'
        '    "do mar. Prende a presa com as ventosas fortes de\\n"\n'
        '    "seus tentáculos e bate sua cabeça dura feito pedra\\n"\n'
        '    "para atordoá-la.");'
    ),
    "gDelibirdPokedexText": (
        '    "Carrega comida enrolada dentro de sua cauda oca\\n"\n'
        '    "que parece um saco. Já salvou a vida de muitos\\n"\n'
        '    "exploradores perdidos em montanhas nevadas\\n"\n'
        '    "dividindo seus mantimentos.");'
    ),
    "gMantinePokedexText": (
        '    "Nada com elegância no mar aberto parecendo voar.\\n"\n'
        '    "Quando atinge grande velocidade na água, salta alto\\n"\n'
        '    "sobre a superfície das ondas, planando pelo ar\\n"\n'
        '    "por alguns segundos.");'
    ),
    "gSkarmoryPokedexText": (
        '    "Seu corpo e asas são blindados com ferro resistente.\\n"\n'
        '    "No passado, guerreiros colhiam penas caídas de\\n"\n'
        '    "Skarmory para forjar espadas afiadas e facas de\\n"\n'
        '    "combate.");'
    ),
    "gHoundourPokedexText": (
        '    "Comunica-se com outros de seu bando usando uivos\\n"\n'
        '    "diferentes para cercar a presa em equipe. Demonstra\\n"\n'
        '    "uma lealdade impressionante ao líder de sua\\n"\n'
        '    "matilha.");'
    ),
    "gHoundoomPokedexText": (
        '    "Se você for queimado pelas chamas que ele cospe,\\n"\n'
        '    "a dor durará para sempre por causa das toxinas no\\n"\n'
        '    "fogo. Seu uivo sinistro à noite faz qualquer um\\n"\n'
        '    "tremer de medo.");'
    ),
    "gKingdraPokedexText": (
        '    "Dorme em cavernas profundas no assoalho oceânico.\\n"\n'
        '    "Dizem que quando acorda e boceja, cria correntes\\n"\n'
        '    "marinhas tão violentas que são capazes de engolir\\n"\n'
        '    "embarcações inteiras.");'
    ),
    "gPhanpyPokedexText": (
        '    "É muito carinhoso e expressa afeto batendo com sua\\n"\n'
        '    "tromba. Porém, como é forte demais, esse golpe\\n"\n'
        '    "pode arremessar uma pessoa longe sem que ele tenha\\n"\n'
        '    "a intenção.");'
    ),
    "gDonphanPokedexText": (
        '    "Seu ataque consiste em enrolar o corpo como uma\\n"\n'
        '    "roda gigante e avançar girando em alta velocidade.\\n"\n'
        '    "É capaz de demolir uma casa inteira com apenas\\n"\n'
        '    "uma investida.");'
    ),
    "gPorygon2PokedexText": (
        '    "Foi aprimorado por cientistas para explorar o espaço\\n"\n'
        '    "sideral. Como ainda não consegue voar no vácuo,\\n"\n'
        '    "passa o tempo todo pesquisando e aprendendo novas\\n"\n'
        '    "habilidades virtuais.");'
    ),
    "gStantlerPokedexText": (
        '    "As curvas e o formato de seus chifres hipnotizam e\\n"\n'
        '    "alteram o fluxo de ar, criando ilusões de ótica\\n"\n'
        '    "que confundem a mente de quem os olha fixamente\\n"\n'
        '    "por muito tempo.");'
    ),
    "gSmearglePokedexText": (
        '    "Pinta marcas em paredes e árvores usando o fluido\\n"\n'
        '    "colorido que sai da ponta de sua cauda. A cor da\\n"\n'
        '    "tinta muda dependendo das emoções e sentimentos\\n"\n'
        '    "do Pokémon.");'
    ),
    "gTyroguePokedexText": (
        '    "Está sempre transbordando de energia para lutar.\\n"\n'
        '    "Para ficar mais forte, desafia qualquer oponente,\\n"\n'
        '    "mesmo que seja muito maior que ele, sem demonstrar\\n"\n'
        '    "nenhum medo.");'
    ),
    "gHitmontopPokedexText": (
        '    "Luta girando de cabeça para baixo sobre o chifre em\\n"\n'
        '    "sua cabeça, desferindo chutes contínuos e velozes.\\n"\n'
        '    "Essa técnica elegante une ataque e defesa com\\n"\n'
        '    "grande harmonia.");'
    ),
    "gSmoochumPokedexText": (
        '    "Examina tudo o que vê pela primeira vez tocando com\\n"\n'
        '    "seus lábios sensíveis. Olha seu reflexo na água\\n"\n'
        '    "para ver se seu rosto está limpo, pois adora\\n"\n'
        '    "vaidade.");'
    ),
    "gElekidPokedexText": (
        '    "Gira os braços como moinhos de vento para gerar\\n"\n'
        '    "eletricidade estática. Adora tempestades de raios\\n"\n'
        '    "e fica eufórico quando o céu se cobre de nuvens\\n"\n'
        '    "carregadas.");'
    ),
    "gMagbyPokedexText": (
        '    "Cada vez que respira, chamas e fumaça quente saem de\\n"\n'
        '    "seu nariz e boca. Seu sangue arde como magma e sua\\n"\n'
        '    "temperatura corporal ultrapassa 600 graus em\\n"\n'
        '    "combate.");'
    ),
    "gMiltankPokedexText": (
        '    "Produz mais de 20 litros de leite nutritivo e doce\\n"\n'
        '    "todos os dias. Dizem que crianças e adultos que\\n"\n'
        '    "bebem o leite de Miltank crescem fortes, saudáveis\\n"\n'
        '    "e cheios de vida.");'
    ),
    "gBlisseyPokedexText": (
        '    "Se pressente tristeza em alguém, corre até a pessoa\\n"\n'
        '    "para oferecer um ovo de pura felicidade. Qualquer\\n"\n'
        '    "um que coma seu ovo começa a sorrir e se enche\\n"\n'
        '    "de ternura.");'
    ),
    "gRaikouPokedexText": (
        '    "Personifica a velocidade do relâmpago. Seus rugidos\\n"\n'
        '    "fazem o chão tremer como se fossem trovões caindo\\n"\n'
        '    "do céu. Corre pelos campos disparando faíscas\\n"\n'
        '    "brilhantes.");'
    ),
    "gEnteiPokedexText": (
        '    "Personifica a paixão do magma. Dizem que ele nasceu\\n"\n'
        '    "da erupção de um vulcão furioso. Quando ruge com\\n"\n'
        '    "força, vulcões em alguma parte do mundo entram\\n"\n'
        '    "em erupção.");'
    ),
    "gSuicunePokedexText": (
        '    "Personifica a pureza das fontes de água límpida.\\n"\n'
        '    "Corre com elegância pela terra, purificando águas\\n"\n'
        '    "poluídas com apenas um toque e soprando ventos\\n"\n'
        '    "do norte.");'
    ),
    "gLarvitarPokedexText": (
        '    "Nasce no fundo da terra e se alimenta de rochas.\\n"\n'
        '    "Depois de devorar o equivalente a uma montanha de\\n"\n'
        '    "terra, adormece profundamente para conseguir\\n"\n'
        '    "evoluir.");'
    ),
    "gPupitarPokedexText": (
        '    "Cria gás comprimido dentro de seu casulo para se\\n"\n'
        '    "propulsar no ar feito um foguete a jato. Seu casco\\n"\n'
        '    "é tão resistente que suporta colisões contra blocos\\n"\n'
        '    "de puro aço.");'
    ),
    "gTyranitarPokedexText": (
        '    "Tem um poder tão descomunal que pode derrubar uma\\n"\n'
        '    "montanha inteira apenas para fazer seu ninho. Anda\\n"\n'
        '    "pelas montanhas em busca de novos adversários dignos\\n"\n'
        '    "para lutar.");'
    ),
    "gLugiaPokedexText": (
        '    "É tão poderoso que um bater suave de suas asas pode\\n"\n'
        '    "destelhar casas e erguer tufões de 40 dias. Por isso,\\n"\n'
        '    "escolheu viver isolado nas fossas mais profundas\\n"\n'
        '    "do oceano.");'
    ),
    "gHoOhPokedexText": (
        '    "Suas penas brilham em sete cores dependendo do ângulo\\n"\n'
        '    "da luz, trazendo alegria aos corações. Dizem que ele\\n"\n'
        '    "voa constantemente pelos céus do mundo sobre o pé\\n"\n'
        '    "do arco-íris.");'
    ),
    "gCelebiPokedexText": (
        '    "Veio do futuro viajando através do tempo. Dizem que\\n"\n'
        '    "enquanto Celebi continuar aparecendo em florestas\\n"\n'
        '    "vivas, um futuro brilhante e cheio de paz aguarda\\n"\n'
        '    "a humanidade.");'
    )
}

# 1. Atualizar pokedex_entries.h
with open('src/data/pokemon/pokedex_entries.h', 'r', encoding='utf-8') as f:
    entries_code = f.read()

count_cats = 0
for dex, cat in categories_lote2.items():
    pattern = rf'(\[{dex}\]\s*=\s*\{{[^}}]*?\.categoryName\s*=\s*_\(")[^"]*("\))'
    if re.search(pattern, entries_code):
        entries_code = re.sub(pattern, rf'\g<1>{cat}\g<2>', entries_code)
        count_cats += 1
    else:
        print(f"WARN: Category for {dex} not found")

with open('src/data/pokemon/pokedex_entries.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(entries_code)

print(f"Sucesso! {count_cats} categorias de Pokédex atualizadas no Lote 2.")

# 2. Atualizar pokedex_text.h
with open('src/data/pokemon/pokedex_text.h', 'r', encoding='utf-8') as f:
    text_code = f.read()

count_texts = 0
for var_name, replacement in pokedex_text_lote2.items():
    pattern = rf'(const u8 {var_name}\[\] = _\(\s*\n)(.*?)(?=\);)'
    m = re.search(pattern, text_code, re.DOTALL)
    if m:
        text_code = text_code[:m.start(2)] + replacement + "\n" + text_code[m.end(2) + 2:]
        count_texts += 1
    else:
        print(f"WARN: Text for {var_name} not found")

with open('src/data/pokemon/pokedex_text.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(text_code)

print(f"Sucesso! {count_texts} textos de Pokédex atualizados no Lote 2.")
