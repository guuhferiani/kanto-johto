# -*- coding: utf-8 -*-
import re

anime_names_gen2 = {
    "MOVE_SKETCH": "Desenho",
    "MOVE_TRIPLE_KICK": "Chute Triplo",
    "MOVE_THIEF": "Ladrão",
    "MOVE_SPIDER_WEB": "Teia de Aranha",
    "MOVE_MIND_READER": "Ler Mentes",
    "MOVE_NIGHTMARE": "Pesadelo",
    "MOVE_FLAME_WHEEL": "Roda de Fogo",
    "MOVE_SNORE": "Ronco",
    "MOVE_CURSE": "Maldição",
    "MOVE_FLAIL": "Debater",
    "MOVE_CONVERSION_2": "Conversão 2",
    "MOVE_AEROBLAST": "Explosão Aérea",
    "MOVE_COTTON_SPORE": "Esporo Algodão",
    "MOVE_REVERSAL": "Inversão",
    "MOVE_SPITE": "Rancor",
    "MOVE_POWDER_SNOW": "Pó de Neve",
    "MOVE_PROTECT": "Proteção",
    "MOVE_MACH_PUNCH": "Soco Supersôn.",
    "MOVE_SCARY_FACE": "Cara Assustad.",
    "MOVE_FEINT_ATTACK": "Ataque Falso",
    "MOVE_SWEET_KISS": "Beijo Doce",
    "MOVE_BELLY_DRUM": "Tambor Barriga",
    "MOVE_SLUDGE_BOMB": "Bomba de Lodo",
    "MOVE_MUD_SLAP": "Tiro de Lama",
    "MOVE_OCTAZOOKA": "Octazuca",
    "MOVE_SPIKES": "Espinhos",
    "MOVE_ZAP_CANNON": "Canhão Elétric",
    "MOVE_FORESIGHT": "Previsão",
    "MOVE_DESTINY_BOND": "Laço Destino",
    "MOVE_PERISH_SONG": "Canção Perecer",
    "MOVE_ICY_WIND": "Vento Gelado",
    "MOVE_DETECT": "Detectar",
    "MOVE_BONE_RUSH": "Investida Osso",
    "MOVE_LOCK_ON": "Travar Mira",
    "MOVE_OUTRAGE": "Ultraje",
    "MOVE_SANDSTORM": "Tempest. Areia",
    "MOVE_GIGA_DRAIN": "Giga Dreno",
    "MOVE_ENDURE": "Resistir",
    "MOVE_CHARM": "Charme",
    "MOVE_ROLLOUT": "Rolo Compressor",
    "MOVE_FALSE_SWIPE": "Golpe Falso",
    "MOVE_SWAGGER": "Provocar",
    "MOVE_MILK_DRINK": "Beber Leite",
    "MOVE_SPARK": "Faísca",
    "MOVE_FURY_CUTTER": "Corte Furioso",
    "MOVE_STEEL_WING": "Asa de Aço",
    "MOVE_MEAN_LOOK": "Olhar Malvado",
    "MOVE_ATTRACT": "Atração",
    "MOVE_SLEEP_TALK": "Sonilóquio",
    "MOVE_HEAL_BELL": "Sino de Cura",
    "MOVE_RETURN": "Retribuição",
    "MOVE_PRESENT": "Presente",
    "MOVE_FRUSTRATION": "Frustração",
    "MOVE_SAFEGUARD": "Salvaguarda",
    "MOVE_PAIN_SPLIT": "Divisão de Dor",
    "MOVE_SACRED_FIRE": "Fogo Sagrado",
    "MOVE_MAGNITUDE": "Magnitude",
    "MOVE_DYNAMIC_PUNCH": "Soco Dinâmico",
    "MOVE_MEGAHORN": "Mega Chifre",
    "MOVE_DRAGON_BREATH": "Sopro do Dragão",
    "MOVE_BATON_PASS": "Passa Bastão",
    "MOVE_ENCORE": "Bis",
    "MOVE_PURSUIT": "Perseguição",
    "MOVE_RAPID_SPIN": "Giro Rápido",
    "MOVE_SWEET_SCENT": "Doce Aroma",
    "MOVE_IRON_TAIL": "Cauda de Ferro",
    "MOVE_METAL_CLAW": "Garra de Metal",
    "MOVE_VITAL_THROW": "Arremesso Vital",
    "MOVE_MORNING_SUN": "Sol da Manhã",
    "MOVE_SYNTHESIS": "Síntese",
    "MOVE_MOONLIGHT": "Luar",
    "MOVE_HIDDEN_POWER": "Poder Oculto",
    "MOVE_CROSS_CHOP": "Golpe Cruzado",
    "MOVE_TWISTER": "Tornado",
    "MOVE_RAIN_DANCE": "Dança da Chuva",
    "MOVE_SUNNY_DAY": "Dia Ensolarado",
    "MOVE_CRUNCH": "Triturar",
    "MOVE_MIRROR_COAT": "MantoEspelhado",
    "MOVE_PSYCH_UP": "Copiar Força",
    "MOVE_EXTREME_SPEED": "Velocid.Extrema",
    "MOVE_ANCIENT_POWER": "PoderAncestral",
    "MOVE_SHADOW_BALL": "Bola Sombria",
    "MOVE_FUTURE_SIGHT": "Visão Futuro",
    "MOVE_ROCK_SMASH": "Quebra-Pedra",
    "MOVE_WHIRLPOOL": "Redemoinho",
    "MOVE_BEAT_UP": "Pancadaria"
}

with open('src/data/text/move_names.h', 'r', encoding='utf-8') as f:
    names_code = f.read()

count_names = 0
for const, name in anime_names_gen2.items():
    pattern = rf'(\[{const}\]\s*=\s*_\(")[^"]*("\),)'
    if re.search(pattern, names_code):
        names_code = re.sub(pattern, rf'\g<1>{name}\g<2>', names_code)
        count_names += 1
    else:
        print(f"WARN: {const} not found in move_names.h")

with open('src/data/text/move_names.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(names_code)

print(f"Sucesso! {count_names} nomes de golpes da Geração 2 atualizados para o Anime.")

moves_gen2 = {
    # 166: Sketch
    "Sketch": {
        "2line": '    "Copia o golpe usado pelo\\n"\n    "alvo para sempre."',
        "4line": '"Permite ao usuário\\naprender o último golpe\\nusado pelo alvo para\\nsempre."'
    },
    # 167: Triple Kick
    "TripleKick": {
        "2line": '    "Chuta o alvo 3 vezes com\\n"\n    "poder crescente."',
        "4line": '"Desfere três chutes\\nem sucessão veloz,\\ncada um ficando mais\\nforte que o anterior."'
    },
    # 168: Thief
    "Thief": {
        "2line": '    "Ataca e pode roubar o item\\n"\n    "segurado pelo alvo."',
        "4line": '"Desfere um golpe e\\npode roubar o item\\nsegurado pelo alvo,\\nse não estiver com um."'
    },
    # 169: Spider Web
    "SpiderWeb": {
        "2line": '    "Prende o alvo em teia para\\n"\n    "impedi-lo de fugir."',
        "4line": '"Uma teia pegajosa e\\nviscosa prende o alvo,\\nimpossibilitando-o de\\nfugir da batalha."'
    },
    # 170: Mind Reader
    "MindReader": {
        "2line": '    "Lê os pensamentos do alvo.\\n"\n    "O próximo golpe acerta."',
        "4line": '"Prevê os movimentos\\ndo alvo para garantir\\nque o próximo ataque\\nacertará em cheio."'
    },
    # 171: Nightmare
    "Nightmare": {
        "2line": '    "Faz o alvo adormecido perder\\n"\n    "1/4 do HP por turno."',
        "4line": '"Provoca pesadelos em\\num alvo adormecido,\\nfazendo-o perder 1/4\\ndo HP a cada turno."'
    },
    # 172: Flame Wheel
    "FlameWheel": {
        "2line": '    "Investida em chamas que\\n"\n    "pode queimar o alvo."',
        "4line": '"O atacante se cobre de\\nfogo e rola contra o\\nalvo. Pode deixar com\\nqueimadura."'
    },
    # 173: Snore
    "Snore": {
        "2line": '    "Ataque sonoro alto usado\\n"\n    "enquanto está dormindo."',
        "4line": '"Um ronco alto e feroz\\né emitido enquanto\\ndorme. Pode fazer o\\nalvo hesitar."'
    },
    # 174: Curse
    "Curse": {
        "2line": '    "Funciona diferente para\\n"\n    "Pokémon do tipo Fantasma."',
        "4line": '"Fantasmas perdem vida\\npara amaldiçoar o alvo.\\nOutros tipos sobem\\nAtaque e Defesa."'
    },
    # 175: Flail
    "Flail": {
        "2line": '    "Causa mais dano quanto menor\\n"\n    "for o HP do usuário."',
        "4line": '"O atacante se debate\\ncom desespero. Causa\\nmuito mais dano se\\nestiver com pouco HP."'
    },
    # 176: Conversion 2
    "Conversion2": {
        "2line": '    "Muda o tipo para resistir ao\\n"\n    "último golpe sofrido."',
        "4line": '"Muda o tipo do corpo\\npara se tornar resistente\\nao tipo do último golpe\\nrecebido."'
    },
    # 177: Aeroblast
    "Aeroblast": {
        "2line": '    "Dispara um vórtice de ar.\\n"\n    "Alta chance crítica."',
        "4line": '"Um vórtice de vácuo\\ne ar cortante é lançado\\nno alvo. Tem alta chance\\nde acerto crítico."'
    },
    # 178: Cotton Spore
    "CottonSpore": {
        "2line": '    "Esporos de algodão grudam e\\n"\n    "reduzem muito Velocidade."',
        "4line": '"Esporos felpudos de\\nalgodão grudam no alvo,\\nreduzindo bastante a\\nsua Velocidade."'
    },
    # 179: Reversal
    "Reversal": {
        "2line": '    "Causa mais dano quanto menor\\n"\n    "for o HP do usuário."',
        "4line": '"Um contra-ataque de\\nreviravolta. Fica muito\\nmais forte quando o HP\\ndo usuário está baixo."'
    },
    # 180: Spite
    "Spite": {
        "2line": '    "Reduz o PP do último golpe\\n"\n    "usado pelo alvo."',
        "4line": '"Um rancor amargo drena\\nde 2 a 5 PPs do último\\ngolpe utilizado pelo\\noponente."'
    },
    # 181: Powder Snow
    "PowderSnow": {
        "2line": '    "Rajada de neve em pó que\\n"\n    "pode congelar o alvo."',
        "4line": '"Flocos de neve gélidos\\ne finos sopram sobre o\\nalvo. Pode deixar com\\ncongelamento."'
    },
    # 182: Protect
    "Protect": {
        "2line": '    "Protege contra ataques.\\n"\n    "Pode falhar se repetido."',
        "4line": '"Cria um escudo que\\ndefende contra qualquer\\ngolpe. Pode falhar se\\nusado em seguida."'
    },
    # 183: Mach Punch
    "MachPunch": {
        "2line": '    "Soco veloz na velocidade do\\n"\n    "som. Ataca primeiro."',
        "4line": '"Desfere um soco na\\nvelocidade do som num\\npiscar de olhos. Sempre\\nataca primeiro."'
    },
    # 184: Scary Face
    "ScaryFace": {
        "2line": '    "Cara assustadora que reduz\\n"\n    "muito a Velocidade."',
        "4line": '"Faz uma careta sinistra\\ne amedrontadora, fazendo\\no alvo recuar e baixar\\nsua Velocidade."'
    },
    # 185: Feint Attack
    "FeintAttack": {
        "2line": '    "Engana o alvo com uma finta\\n"\n    "e nunca erra o golpe."',
        "4line": '"Aproxima-se fingindo\\ndesatenção e ataca de\\nsurpresa. Esse golpe\\nnunca erra."'
    },
    # 186: Sweet Kiss
    "SweetKiss": {
        "2line": '    "Beijo doce e sedutor que\\n"\n    "deixa o alvo confuso."',
        "4line": '"Exige um beijo fofo e\\nencantador que pega o\\noponente de surpresa,\\ndeixando-o confuso."'
    },
    # 187: Belly Drum
    "BellyDrum": {
        "2line": '    "Gasta metade do HP máximo\\n"\n    "para maximizar o Ataque."',
        "4line": '"Bate na barriga como\\num tambor, gastando\\nmetade do HP para elevar\\no Ataque ao máximo."'
    },
    # 188: Sludge Bomb
    "SludgeBomb": {
        "2line": '    "Atira lodo imundo que pode\\n"\n    "envenenar o alvo."',
        "4line": '"Bolas de lodo tóxico e\\nimundo explodem no alvo.\\nPode causar envenenamento\\nno oponente."'
    },
    # 189: Mud-Slap
    "MudSlap": {
        "2line": '    "Atira lama nos olhos do\\n"\n    "alvo para baixar precisão."',
        "4line": '"Atira lama suja nos\\nolhos do oponente,\\ncausando dano e baixando\\na precisão dele."'
    },
    # 190: Octazooka
    "Octazooka": {
        "2line": '    "Dispara tinta como canhão.\\n"\n    "Pode baixar a precisão."',
        "4line": '"Dispara uma bola de\\ntinta preta como um\\ncanhão. Pode reduzir a\\nprecisão do alvo."'
    },
    # 191: Spikes
    "Spikes": {
        "2line": '    "Espalha espinhos no chão\\n"\n    "que ferem quem entrar."',
        "4line": '"Espalha espinhos no\\ncampo do oponente, que\\nferem qualquer Pokémon\\nterrestre que entrar."'
    },
    # 192: Zap Cannon
    "ZapCannon": {
        "2line": '    "Canhão elétrico impreciso\\n"\n    "que sempre paralisa."',
        "4line": '"Dispara um canhão de\\neletricidade potente.\\nErra com facilidade, mas\\nsempre paralisa."'
    },
    # 193: Foresight
    "Foresight": {
        "2line": '    "Anula evasão do alvo e faz\\n"\n    "Fantasmas levarem dano."',
        "4line": '"Anula bônus de evasão\\ndo oponente e permite\\nque golpes Normais e\\nLutadores atinjam Fantasmas."'
    },
    # 194: Destiny Bond
    "DestinyBond": {
        "2line": '    "Se desmaiar pelo alvo, o\\n"\n    "alvo desmaia junto."',
        "4line": '"Cria um elo do destino.\\nSe o usuário desmaiar\\npor um golpe do alvo, o\\nalvo desmaia junto."'
    },
    # 195: Perish Song
    "PerishSong": {
        "2line": '    "Qualquer Pokémon que ouvir\\n"\n    "desmaia em 3 turnos."',
        "4line": '"Quem ouvir essa canção\\ndesmaiará em três turnos,\\na menos que seja trocado\\nda batalha."'
    },
    # 196: Icy Wind
    "IcyWind": {
        "2line": '    "Rajada de vento gélido que\\n"\n    "reduz a Velocidade."',
        "4line": '"Um vento gelado atinge\\nos oponentes com frio\\nintenso, reduzindo a\\nsua Velocidade."'
    },
    # 197: Detect
    "Detect": {
        "2line": '    "Esquiva-se de ataques.\\n"\n    "Pode falhar se repetido."',
        "4line": '"Prevê o ataque inimigo\\ne se esquiva de tudo.\\nPode falhar se usado em\\nturnos seguidos."'
    },
    # 198: Bone Rush
    "BoneRush": {
        "2line": '    "Golpeia o alvo com um osso\\n"\n    "de 2 a 5 vezes seguidas."',
        "4line": '"O usuário ataca o alvo\\ncom um osso em riste de\\nduas a cinco vezes num\\núnico turno."'
    },
    # 199: Lock-On
    "LockOn": {
        "2line": '    "Trava a mira no alvo para o\\n"\n    "próximo golpe não errar."',
        "4line": '"Trava a mira no oponente\\ncom precisão cirúrgica.\\nO próximo ataque do\\nusuário não errará."'
    },
    # 200: Outrage
    "Outrage": {
        "2line": '    "Fúria por 2 ou 3 turnos,\\n"\n    "mas fica confuso."',
        "4line": '"O atacante entra em\\nfúria violenta por 2\\nou 3 turnos, ficando\\nconfuso ao terminar."'
    },
    # 201: Sandstorm
    "Sandstorm": {
        "2line": '    "Tempestade de areia que fere\\n"\n    "todos que não forem Rocha."',
        "4line": '"Uma tempestade de areia\\nfere todos os Pokémon a\\ncada turno, exceto os de\\nRocha, Terra e Aço."'
    },
    # 202: Giga Drain
    "GigaDrain": {
        "2line": '    "Drena muita energia vital e\\n"\n    "cura metade do dano."',
        "4line": '"Um ataque que suga a\\nenergia vital do alvo,\\ncurando o atacante em\\nmetade do dano causado."'
    },
    # 203: Endure
    "Endure": {
        "2line": '    "Aguenta qualquer golpe com\\n"\n    "pelo menos 1 de HP."',
        "4line": '"O usuário resiste com\\ndeterminação a qualquer\\ngolpe no turno, ficando\\ncom pelo menos 1 de HP."'
    },
    # 204: Charm
    "Charm": {
        "2line": '    "Olhar adorável que reduz\\n"\n    "muito o Ataque do alvo."',
        "4line": '"Encanta o alvo com um\\nolhar adorável e meigo,\\nreduzindo bastante o seu\\natributo de Ataque."'
    },
    # 205: Rollout
    "Rollout": {
        "2line": '    "Rola contra o alvo por 5\\n"\n    "turnos, dobrando poder."',
        "4line": '"Rola contra o alvo por\\ncinco turnos, ganhando\\nmais velocidade e força\\na cada acerto."'
    },
    # 206: False Swipe
    "FalseSwipe": {
        "2line": '    "Golpe contido que sempre\\n"\n    "deixa o alvo com 1 de HP."',
        "4line": '"Um ataque contido que\\nnunca desmaia o alvo,\\ndeixando-o sempre com\\npelo menos 1 de HP."'
    },
    # 207: Swagger
    "Swagger": {
        "2line": '    "Confunde o alvo, mas amplia\\n"\n    "muito o Ataque dele."',
        "4line": '"Provoca o oponente até\\nenfurecê-lo. Deixa-o\\nconfuso, mas amplia muito\\no Ataque dele."'
    },
    # 208: Milk Drink
    "MilkDrink": {
        "2line": '    "Bebe leite para curar até\\n"\n    "metade do HP máximo."',
        "4line": '"Bebe leite nutritivo\\npara curar até metade\\ndo HP. Pode curar colegas\\nde equipe fora da luta."'
    },
    # 209: Spark
    "Spark": {
        "2line": '    "Investida elétrica que pode\\n"\n    "paralisar o alvo."',
        "4line": '"Cobre-se de faíscas e\\navança contra o alvo.\\nPode deixar o oponente\\nparalisado."'
    },
    # 210: Fury Cutter
    "FuryCutter": {
        "2line": '    "Corte que dobra de poder a\\n"\n    "cada turno que acerta."',
        "4line": '"Ataca com foices ou\\ngarras afiadas. O poder\\ndobra a cada turno que\\nacertar em sucessão."'
    },
    # 211: Steel Wing
    "SteelWing": {
        "2line": '    "Golpe com asas rígidas.\\n"\n    "Pode aumentar a Defesa."',
        "4line": '"Atinge o oponente com\\nasas rijas de metal.\\nPode também aumentar\\na Defesa do usuário."'
    },
    # 212: Mean Look
    "MeanLook": {
        "2line": '    "Olhar fixo e sinistro que\\n"\n    "impede o alvo de fugir."',
        "4line": '"Fixa um olhar sinistro\\ne hipnotizante no alvo,\\nimpossibilitando-o de fugir\\nou ser trocado."'
    },
    # 213: Attract
    "Attract": {
        "2line": '    "Faz o sexo oposto hesitar\\n"\n    "em atacar por paixão."',
        "4line": '"Seduz o sexo oposto com\\ncharme irresistível, com\\n50% de chance do alvo\\nnão atacar por paixão."'
    },
    # 214: Sleep Talk
    "SleepTalk": {
        "2line": '    "Usa um dos seus outros\\n"\n    "golpes enquanto dorme."',
        "4line": '"Enquanto dorme, escolhe\\num dos seus outros três\\ngolpes aleatoriamente\\npara atacar."'
    },
    # 215: Heal Bell
    "HealBell": {
        "2line": '    "Badala um sino que cura os\\n"\n    "status de toda a equipe."',
        "4line": '"Toca um sino relaxante\\ne harmonioso que cura\\ntodos os problemas de\\nstatus da sua equipe."'
    },
    # 216: Return
    "Return": {
        "2line": '    "Causa mais dano quanto maior\\n"\n    "for a amizade com você."',
        "4line": '"Um ataque cheio de afeto\\nque fica mais poderoso\\nquanto maior for o elo de\\namizade com o treinador."'
    },
    # 217: Present
    "Present": {
        "2line": '    "Dá uma caixa de presente\\n"\n    "que pode ferir ou curar."',
        "4line": '"Entrega uma caixa de\\npresente surpresa. Pode\\ncausar grande dano ou\\ncurar o HP do alvo."'
    },
    # 218: Frustration
    "Frustration": {
        "2line": '    "Causa mais dano quanto menor\\n"\n    "for a amizade com você."',
        "4line": '"Descarrega frustração.\\nFica mais poderoso quanto\\nmenor for o nível de\\namizade com o treinador."'
    },
    # 219: Safeguard
    "Safeguard": {
        "2line": '    "Cria um escudo que previne\\n"\n    "problemas de status."',
        "4line": '"Ergue um campo místico\\nprotetor que protege toda\\na equipe contra problemas\\nde status por 5 turnos."'
    },
    # 220: Pain Split
    "PainSplit": {
        "2line": '    "Soma o HP de ambos e divide\\n"\n    "igualmente entre os dois."',
        "4line": '"Soma a vida atual do\\nusuário e do alvo e\\nreparte o total de forma\\nigual para os dois."'
    },
    # 221: Sacred Fire
    "SacredFire": {
        "2line": '    "Fogo sagrado e místico que\\n"\n    "tem 50% de chance de queimar."',
        "4line": '"Chamas sagradas de poder\\nmístico envolvem o alvo.\\nPossui 50% de chance de\\ncausar queimadura."'
    },
    # 222: Magnitude
    "Magnitude": {
        "2line": '    "Terremoto com poder sísmico\\n"\n    "sorteado de 4 a 10."',
        "4line": '"Um abalo sísmico sacode\\na terra com intensidade\\naleatória, variando da\\nmagnitude 4 até 10."'
    },
    # 223: Dynamic Punch
    "DynamicPunch": {
        "2line": '    "Soco potente e impreciso\\n"\n    "que sempre confunde."',
        "4line": '"Um soco com tremendo\\npoder concentrado. Erra\\ncom facilidade, mas\\nsempre deixa confuso."'
    },
    # 224: Megahorn
    "Megahorn": {
        "2line": '    "Investida brutal e violenta\\n"\n    "com um chifre enorme."',
        "4line": '"Avança com um chifre\\ntitânico e resistente\\ncontra o alvo com força\\ncolossal."'
    },
    # 225: Dragon Breath
    "DragonBreath": {
        "2line": '    "Sopro dracônico forte que\\n"\n    "pode paralisar o alvo."',
        "4line": '"Exala um sopro de fogo\\ndracônico potente sobre o\\nalvo. Pode deixar o alvo\\nparalisado."'
    },
    # 226: Baton Pass
    "BatonPass": {
        "2line": '    "Troca de Pokémon mantendo\\n"\n    "todos os bônus de status."',
        "4line": '"Troca de lugar com um\\ncolega da equipe, passando\\ntodas as alterações de\\natributos adiante."'
    },
    # 227: Encore
    "Encore": {
        "2line": '    "Força o alvo a repetir o seu\\n"\n    "último golpe por turnos."',
        "4line": '"Aplaude o oponente e o\\nforça a usar somente o\\nseu último golpe pelos\\npróximos turnos."'
    },
    # 228: Pursuit
    "Pursuit": {
        "2line": '    "Causa dano dobrado se o\\n"\n    "alvo tentar ser trocado."',
        "4line": '"Ataca o oponente. Se ele\\ntentar trocar de lugar na\\nmesma rodada, o ataque\\ncausa dano dobrado."'
    },
    # 229: Rapid Spin
    "RapidSpin": {
        "2line": '    "Giro rápido que livra de\\n"\n    "teias, espinhos e cipós."',
        "4line": '"Gira velozmente feito\\npião para atacar e se\\nlivrar de amarras, teias\\ne espinhos no campo."'
    },
    # 230: Sweet Scent
    "SweetScent": {
        "2line": '    "Aroma doce que baixa evasão\\n"\n    "e atrai Pokémon fora."',
        "4line": '"Libera um aroma doce que\\nreduz a evasão do alvo.\\nFora da luta, atrai\\nPokémon selvagens."'
    },
    # 231: Iron Tail
    "IronTail": {
        "2line": '    "Bate com cauda de metal.\\n"\n    "Pode reduzir a Defesa."',
        "4line": '"Endurece a cauda como\\naço e bate com força no\\nalvo. Pode reduzir o seu\\natributo de Defesa."'
    },
    # 232: Metal Claw
    "MetalClaw": {
        "2line": '    "Corte com garras de aço.\\n"\n    "Pode aumentar o Ataque."',
        "4line": '"Retalha o oponente com\\ngarras endurecidas como\\naço. Pode aumentar o seu\\npróprio Ataque."'
    },
    # 233: Vital Throw
    "VitalThrow": {
        "2line": '    "Ataca por último, mas nunca\\n"\n    "erra o arremesso."',
        "4line": '"Aguarda a investida do\\noponente e o arremessa.\\nAtaca por último, mas\\nnunca erra o golpe."'
    },
    # 234: Morning Sun
    "MorningSun": {
        "2line": '    "Restaura HP com a luz do sol.\\n"\n    "Cura varia com o clima."',
        "4line": '"Banhado pela luz matinal,\\nregenera o HP do usuário.\\nA quantidade curada varia\\nconforme o clima."'
    },
    # 235: Synthesis
    "Synthesis": {
        "2line": '    "Sintetiza luz para curar HP.\\n"\n    "Cura varia com o clima."',
        "4line": '"Absorve a luz ambiente\\npara curar o seu próprio\\nHP. O poder de cura varia\\nconforme o clima."'
    },
    # 236: Moonlight
    "Moonlight": {
        "2line": '    "Restaura HP com a luz da lua.\\n"\n    "Cura varia com o clima."',
        "4line": '"Banhado pela luz da lua,\\nregenera o HP do usuário.\\nA quantidade curada varia\\nconforme o clima."'
    },
    # 237: Hidden Power
    "HiddenPower": {
        "2line": '    "Poder e tipo elemental que\\n"\n    "variam com o Pokémon."',
        "4line": '"Um ataque misterioso cujo\\ntipo elemental e força\\ndependem das características\\núnicas do Pokémon."'
    },
    # 238: Cross Chop
    "CrossChop": {
        "2line": '    "Golpe duplo cruzado com as\\n"\n    "mãos. Alta chance crítica."',
        "4line": '"Cruza os dois braços em\\nX e golpeia com força.\\nPossui alta chance de\\nacertos críticos."'
    },
    # 239: Twister
    "Twister": {
        "2line": '    "Cria um tornado violento.\\n"\n    "Pode fazer o alvo hesitar."',
        "4line": '"Gera um tornado feroz\\nque atinge os oponentes.\\nPode fazer os alvos\\nhesitarem na luta."'
    },
    # 240: Rain Dance
    "RainDance": {
        "2line": '    "Dança que invoca chuva forte\\n"\n    "durante 5 turnos."',
        "4line": '"Uma dança mística que\\ninvoca chuva torrencial\\npor cinco turnos, subindo\\ngolpes de Água."'
    },
    # 241: Sunny Day
    "SunnyDay": {
        "2line": '    "Intensifica o sol brilhante\\n"\n    "durante 5 turnos."',
        "4line": '"Faz o sol brilhar com\\ncalor intenso por cinco\\nturnos, fortalecendo\\ngolpes de Fogo."'
    },
    # 242: Crunch
    "Crunch": {
        "2line": '    "Tritura com presas escuras.\\n"\n    "Pode reduzir a Def. Esp."',
        "4line": '"Morde e tritura o alvo\\ncom presas afiadas. Pode\\nreduzir a Defesa Especial\\ndo oponente."'
    },
    # 243: Mirror Coat
    "MirrorCoat": {
        "2line": '    "Retalia ataques especiais com\\n"\n    "o dobro do dano sofrido."',
        "4line": '"Contra-ataca qualquer\\ngolpe especial sofrido\\nno mesmo turno com o\\ndobro de força."'
    },
    # 244: Psych Up
    "PsychUp": {
        "2line": '    "Sintoniza a mente para copiar\\n"\n    "os bônus de status do alvo."',
        "4line": '"Hipnotiza a si mesmo\\ne copia fielmente todas\\nas mudanças de atributos\\ndo oponente."'
    },
    # 245: Extreme Speed
    "ExtremeSpeed": {
        "2line": '    "Investida em velocidade cega\\n"\n    "que sempre ataca primeiro."',
        "4line": '"Uma investida a uma\\nvelocidade ofuscante e\\ncega. Sempre ataca antes\\nde qualquer outro golpe."'
    },
    # 246: Ancient Power
    "AncientPower": {
        "2line": '    "Poder ancestral que pode\\n"\n    "elevar todos os atributos."',
        "4line": '"Ataca com poder fóssil\\ne primitivo. Pode elevar\\ntodos os atributos do\\nusuário de uma vez."'
    },
    # 247: Shadow Ball
    "ShadowBall": {
        "2line": '    "Atira uma esfera sombria que\\n"\n    "pode reduzir a Def. Esp."',
        "4line": '"Uma esfera sombria de\\nenergia espectral atinge\\no alvo. Pode reduzir a sua\\nDefesa Especial."'
    },
    # 248: Future Sight
    "FutureSight": {
        "2line": '    "Concentra energia psíquica\\n"\n    "para atacar após 2 turnos."',
        "4line": '"Envia feixes psíquicos ao\\nespaço que caem sobre o\\nalvo dois turnos após o\\ngolpe ser usado."'
    },
    # 249: Rock Smash
    "RockSmash": {
        "2line": '    "Golpe que quebra pedras no\\n"\n    "mapa e pode baixar Defesa."',
        "4line": '"Golpe demolidor que pode\\nbaixar a Defesa do alvo.\\nFora da luta, quebra\\nrochas rachadas."'
    },
    # 251: Beat Up
    "BeatUp": {
        "2line": '    "Toda a equipe ataca junta.\\n"\n    "Dano sobe com mais aliados."',
        "4line": '"Todos os Pokémon da sua\\nequipe atacam em bando.\\nQuanto mais companheiros,\\nmaior será o dano."'
    }
}

with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8') as f:
    code = f.read()

count_2l = 0
count_4l = 0

# Whirlpool 2-line
orig_whirlpool_2l = """static const u8 sWhirlpoolDescription[] = _(
    "Traps and hurts the foe in\\n"
#if B_BINDING_TURNS >= GEN_5
    "a whirlpool for 4 or 5 turns.");
#else
    "a whirlpool for 2 to 5 turns.");
#endif"""

new_whirlpool_2l = """static const u8 sWhirlpoolDescription[] = _(
    "Prende e fere o alvo em\\n"
#if B_BINDING_TURNS >= GEN_5
    "redemoinho de 4 a 5 turnos.");
#else
    "redemoinho de 2 a 5 turnos.");
#endif"""

if orig_whirlpool_2l in code:
    code = code.replace(orig_whirlpool_2l, new_whirlpool_2l)
    count_2l += 1
else:
    print("WARN: orig_whirlpool_2l not found")

# Whirlpool 4-line
orig_whirlpool_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Whirlpool[] = _("The foe is trapped\\nin a fast, vicious\\nwhirlpool for four\\nor five turns.");
#else
static const u8 sMoveFourLineDescription_Whirlpool[] = _("The foe is trapped\\nin a fast, vicious\\nwhirlpool for two\\nto five turns.");
#endif"""

new_whirlpool_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Whirlpool[] = _("O alvo é preso em\\num redemoinho forte\\npor quatro ou cinco\\nturnos seguidos.");
#else
static const u8 sMoveFourLineDescription_Whirlpool[] = _("O alvo é preso em\\num redemoinho forte\\npor dois a cinco\\nturnos seguidos.");
#endif"""

if orig_whirlpool_4l in code:
    code = code.replace(orig_whirlpool_4l, new_whirlpool_4l)
    count_4l += 1
else:
    print("WARN: orig_whirlpool_4l not found")

for name, trans in moves_gen2.items():
    var_2l = f"s{name}Description"
    pattern_2l = rf'(static const u8 {var_2l}\[\] = _\(\s*\n)(.*?)(?=\);)'
    m2 = re.search(pattern_2l, code, re.DOTALL)
    if m2:
        code = code[:m2.start(2)] + trans["2line"] + "\n" + code[m2.end(2):]
        count_2l += 1
    else:
        print(f"WARN: 2-line not found for {var_2l}")

    var_4l = f"sMoveFourLineDescription_{name}"
    # check special cases
    if name == "Conversion2":
        var_4l = "sMoveFourLineDescription_Conversion2"
    elif name == "FeintAttack":
        var_4l = "sMoveFourLineDescription_FaintAttack"
    
    pattern_4l = rf'(static const u8 {var_4l}\[\] = _\()(.*?)(\);)'
    matches_4l = list(re.finditer(pattern_4l, code))
    if matches_4l:
        for m4 in reversed(matches_4l):
            code = code[:m4.start(2)] + trans["4line"] + code[m4.end(2):]
            count_4l += 1
    else:
        # Tenta com nome original se FeintAttack
        pattern_fallback = rf'(static const u8 sMoveFourLineDescription_{name}\[\] = _\()(.*?)(\);)'
        fb_matches = list(re.finditer(pattern_fallback, code))
        if fb_matches:
            for mfb in reversed(fb_matches):
                code = code[:mfb.start(2)] + trans["4line"] + code[mfb.end(2):]
                count_4l += 1
        else:
            print(f"WARN: 4-line not found for {var_4l}")

with open('src/data/text/move_descriptions.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(code)

print(f"Sucesso! Gen 2: {count_2l} descrições 2-line e {count_4l} descrições 4-line atualizadas.")
