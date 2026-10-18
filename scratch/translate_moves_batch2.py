# -*- coding: utf-8 -*-
import re

moves_51_to_100 = {
    # 51: Acid
    "Acid": {
        "2line": '    "Espalha um ácido que pode\\n"\n    "reduzir a Def. Esp. do alvo.");',
        "4line": '"O alvo é borrifado\\ncom um forte ácido.\\nPode reduzir a Def.\\nEsp. do oponente."'
    },
    # 52: Ember
    "Ember": {
        "2line": '    "Ataque fraco de fogo que\\n"\n    "pode queimar o alvo.");',
        "4line": '"Pequenas chamas são\\natiradas no alvo.\\nPode deixar o alvo\\ncom queimadura."'
    },
    # 53: Flamethrower
    "Flamethrower": {
        "2line": '    "Ataque poderoso de fogo que\\n"\n    "pode queimar o alvo.");',
        "4line": '"Uma forte torrente\\nde chamas atinge\\no alvo. Pode causar\\nqueimadura."'
    },
    # 54: Mist
    "Mist": {
        "2line": '    "Cria uma névoa que impede\\n"\n    "a redução de atributos.");',
        "4line": '"Uma névoa branca e\\nprotetora impede a\\nredução de atributos\\nda equipe."'
    },
    # 55: Water Gun
    "WaterGun": {
        "2line": '    "Dispara um jato de água\\n"\n    "contra o alvo.");',
        "4line": '"Um jato forte de\\nágua é disparado\\ncontra o corpo do\\noponente."'
    },
    # 56: Hydro Pump
    "HydroPump": {
        "2line": '    "Dispara um enorme volume\\n"\n    "de água com alta pressão.");',
        "4line": '"Uma enorme torrente\\nde água em alta\\npressão é lançada\\nno alvo."'
    },
    # 57: Surf
    "Surf": {
        "2line": '    "Cria uma onda gigante que\\n"\n    "atinge todos na batalha.");',
        "4line": '"Uma onda enorme cai\\nsobre os alvos.\\nPermite navegar pela\\nágua fora da luta."'
    },
    # 58: Ice Beam
    "IceBeam": {
        "2line": '    "Dispara um raio gélido que\\n"\n    "pode congelar o alvo.");',
        "4line": '"Um feixe de energia\\ngélida atinge o alvo.\\nPode deixar o alvo\\ncongelado."'
    },
    # 59: Blizzard
    "Blizzard": {
        "2line": '    "Uma feroz nevasca que\\n"\n    "pode congelar o alvo.");',
        "4line": '"Uma nevasca violenta\\ne congelante cai no\\noponente. Pode\\ncongelá-lo."'
    },
    # 60: Psybeam
    "Psybeam": {
        "2line": '    "Dispara um raio peculiar\\n"\n    "que pode confundir o alvo.");',
        "4line": '"Um raio de luz\\npsíquica atinge o\\nalvo. Pode deixá-lo\\nconfuso."'
    },
    # 61: Bubble Beam
    "BubbleBeam": {
        "2line": '    "Dispara bolhas que podem\\n"\n    "reduzir a Velocidade.");',
        "4line": '"Bolhas vigorosas são\\ndisparadas no alvo.\\nPode reduzir sua\\nVelocidade."'
    },
    # 62: Aurora Beam
    "AuroraBeam": {
        "2line": '    "Dispara um raio colorido que\\n"\n    "pode reduzir o Ataque.");',
        "4line": '"Um raio com as cores\\nda aurora atinge o\\nalvo. Pode reduzir o\\nAtaque dele."'
    },
    # 63: Hyper Beam
    "HyperBeam": {
        "2line": '    "Poderoso, mas precisa de\\n"\n    "um turno para recarregar.");',
        "4line": '"Um feixe de poder\\ndestrutivo atinge o\\nalvo. O atacante fica\\nimóvel no 2º turno."'
    },
    # 64: Peck
    "Peck": {
        "2line": '    "Bica o alvo com um bico\\n"\n    "ou chifre afiado.");',
        "4line": '"O alvo é perfurado\\npor um bico pontudo\\nou por um chifre\\nafiado."'
    },
    # 65: Drill Peck
    "DrillPeck": {
        "2line": '    "Ataque giratório em espiral\\n"\n    "com o bico feito broca.");',
        "4line": '"Um ataque giratório\\nonde o bico pontudo\\nage feito uma broca\\npoderosa."'
    },
    # 66: Submission
    "Submission": {
        "2line": '    "Arremesso imprudente que\\n"\n    "também fere o usuário.");',
        "4line": '"Arremesso corporal\\nimprudente que causa\\ndano e fere um pouco\\no próprio atacante."'
    },
    # 67: Low Kick
    "LowKick": {
        "2line": '    "Uma rasteira que causa mais\\n"\n    "dano em alvos pesados.");',
        "4line": '"Uma rasteira que\\ncausa mais dano\\nquanto mais pesado\\nfor o oponente."'
    },
    # 68: Counter
    "Counter": {
        "2line": '    "Retalia ataques físicos com\\n"\n    "o dobro do dano sofrido.");',
        "4line": '"Contra-ataca qualquer\\ngolpe físico sofrido\\nno mesmo turno com o\\ndobro de força."'
    },
    # 69: Seismic Toss
    "SeismicToss": {
        "2line": '    "Arremesso que causa dano\\n"\n    "igual ao nível do usuário.");',
        "4line": '"Um arremesso usando\\na gravidade que tira\\nHP igual ao nível\\ndo atacante."'
    },
    # 70: Strength
    "Strength": {
        "2line": '    "Acumula força e golpeia.\\n"\n    "Pode mover rochas no mapa.");',
        "4line": '"O alvo é esmagado\\ncom força máxima.\\nPermite empurrar\\nrochas fora da luta."'
    },
    # 71: Absorb
    "Absorb": {
        "2line": '    "Absorve metade do dano\\n"\n    "causado para curar HP.");',
        "4line": '"Um ataque que suga\\nmetade do dano que\\ncausou para curar o\\npróprio HP."'
    },
    # 72: Mega Drain
    "MegaDrain": {
        "2line": '    "Drena metade do dano\\n"\n    "causado para curar HP.");',
        "4line": '"Um forte ataque que\\ndrena metade do dano\\ncausado para curar o\\nusuário."'
    },
    # 73: Leech Seed
    "LeechSeed": {
        "2line": '    "Planta uma semente no alvo\\n"\n    "para sugar HP a cada turno.");',
        "4line": '"Uma semente é posta\\nno alvo para roubar\\num pouco de seu HP\\na cada rodada."'
    },
    # 74: Growth
    "Growth": {
        "2line": '    "Faz o corpo crescer,\\n"\n    "elevando Atq. e Atq. Esp.");',
        "4line": '"O corpo cresce em\\num instante, subindo\\nos atributos Ataque\\ne Ataque Especial."'
    },
    # 75: Razor Leaf
    "RazorLeaf": {
        "2line": '    "Corta com folhas afiadas.\\n"\n    "Alta chance crítica.");',
        "4line": '"Folhas afiadas cortam\\no alvo com precisão.\\nPossui alta taxa de\\nacertos críticos."'
    },
    # 76: Solar Beam
    "SolarBeam": {
        "2line": '    "Absorve luz no 1º turno\\n"\n    "e dispara no 2º turno.");',
        "4line": '"Acumula energia da\\nluz no 1º turno e\\ndispara um feixe no\\n2º turno."'
    },
    # 77: Poison Powder
    "PoisonPowder": {
        "2line": '    "Espalha um pó tóxico que\\n"\n    "pode envenenar o alvo.");',
        "4line": '"Uma nuvem de pó\\ntóxico é espalhada.\\nPode deixar o alvo\\nenvenenado."'
    },
    # 78: Stun Spore
    "StunSpore": {
        "2line": '    "Espalha esporos que podem\\n"\n    "paralisar o alvo.");',
        "4line": '"Esporos paralisantes\\nsão espalhados no\\nar. Podem paralisar\\no oponente."'
    },
    # 79: Sleep Powder
    "SleepPowder": {
        "2line": '    "Espalha um pó indutor que\\n"\n    "faz o alvo adormecer.");',
        "4line": '"Um pó que induz ao\\nsono é espalhado em\\ngrande quantidade,\\nfazendo dormir."'
    },
    # 80: Petal Dance
    "PetalDance": {
        "2line": '    "Ataca com pétalas por 2 a 3\\n"\n    "turnos, mas fica confuso.");',
        "4line": '"O usuário ataca com\\npétalas por 2 a 3\\nturnos e depois fica\\nconfuso."'
    },
    # 81: String Shot
    "StringShot": {
        "2line": '    "Dispara fios de seda que\\n"\n    "reduzem a Velocidade.");',
        "4line": '"Fios de seda saem da\\nboca e prendem o\\nalvo, reduzindo sua\\nVelocidade."'
    },
    # 82: Dragon Rage
    "DragonRage": {
        "2line": '    "Dispara ondas de choque que\\n"\n    "causam sempre 40 de dano.");',
        "4line": '"Uma onda de choque\\ndracônica atinge o\\nalvo, causando sempre\\n40 de dano."'
    },
    # 84: Thunder Shock
    "ThunderShock": {
        "2line": '    "Choque elétrico que pode\\n"\n    "paralisar o alvo.");',
        "4line": '"Um pequeno choque\\nelétrico atinge o\\nalvo. Pode deixá-lo\\nparalisado."'
    },
    # 85: Thunderbolt
    "Thunderbolt": {
        "2line": '    "Forte ataque elétrico que\\n"\n    "pode paralisar o alvo.");',
        "4line": '"Um raio elétrico de\\ngrande poder atinge o\\nalvo. Pode deixá-lo\\nparalisado."'
    },
    # 86: Thunder Wave
    "ThunderWave": {
        "2line": '    "Onda elétrica fraca que\\n"\n    "sempre paralisa o alvo.");',
        "4line": '"Uma onda elétrica\\nfraca que certamente\\nparalisa o alvo caso\\nacerte."'
    },
    # 87: Thunder
    "Thunder": {
        "2line": '    "Trovão brutal que pode\\n"\n    "paralisar o alvo.");',
        "4line": '"Um raio brutal cai\\ndo céu sobre o alvo.\\nPode deixá-lo\\nparalisado."'
    },
    # 88: Rock Throw
    "RockThrow": {
        "2line": '    "Arremessa pequenas pedras\\n"\n    "contra o alvo.");',
        "4line": '"O alvo é atacado\\npor uma chuva de\\npedras atiradas com\\nforça."'
    },
    # 89: Earthquake
    "Earthquake": {
        "2line": '    "Terremoto que atinge todos\\n"\n    "os Pokémon na arena.");',
        "4line": '"Um terremoto que\\natinge todos os\\nPokémon na arena,\\nexceto o atacante."'
    },
    # 90: Fissure
    "Fissure": {
        "2line": '    "Abre uma fenda no chão.\\n"\n    "Desmaia o alvo ao acertar.");',
        "4line": '"O chão se abre sob\\no alvo. Causa nocaute\\nimediato caso consiga\\nacertar."'
    },
    # 91: Dig
    "Dig": {
        "2line": '    "Cava no 1º turno e ataca no\\n"\n    "2º. Permite sair de cavernas.");',
        "4line": '"Cava no 1º turno e\\nataca no 2º. Também\\npode ser usado para\\nsair de cavernas."'
    },
    # 92: Toxic
    "Toxic": {
        "2line": '    "Envenena gravemente o alvo.\\n"\n    "O dano piora a cada turno.");',
        "4line": '"Envenena gravemente\\no alvo. O dano da\\ntoxina aumenta a cada\\nrodada."'
    },
    # 93: Confusion
    "Confusion": {
        "2line": '    "Ataque telecinético que\\n"\n    "pode confundir o alvo.");',
        "4line": '"Ataque telecinético\\nsuave que atinge o\\nalvo. Pode deixá-lo\\nconfuso."'
    },
    # 94: Psychic
    "Psychic": {
        "2line": '    "Forte poder psíquico que\\n"\n    "pode reduzir a Def. Esp.");',
        "4line": '"Um poderoso ataque\\npsíquico. Pode também\\nreduzir a Defesa\\nEspecial do alvo."'
    },
    # 95: Hypnosis
    "Hypnosis": {
        "2line": '    "Sugestão hipnótica que faz\\n"\n    "o alvo dormir profundamente.");',
        "4line": '"Sugestão hipnótica é\\nusada para fazer o\\nalvo cair em sono\\nprofundo."'
    },
    # 96: Meditate
    "Meditate": {
        "2line": '    "Medita em paz para elevar\\n"\n    "o atributo de Ataque.");',
        "4line": '"O usuário medita para\\ndespertar seu poder,\\naumentando o seu\\nAtaque."'
    },
    # 97: Agility
    "Agility": {
        "2line": '    "Relaxa o corpo para elevar\\n"\n    "muito a Velocidade.");',
        "4line": '"O usuário relaxa e\\nalivia o corpo para\\naumentar bastante a\\nsua Velocidade."'
    },
    # 98: Quick Attack
    "QuickAttack": {
        "2line": '    "Investida quase invisível\\n"\n    "que sempre ataca primeiro.");',
        "4line": '"Um ataque veloz feito\\nnum piscar de olhos\\nque certamente ataca\\nprimeiro."'
    },
    # 99: Rage
    "Rage": {
        "2line": '    "Fica mais forte toda vez que\\n"\n    "é atingido na batalha.");',
        "4line": '"Um ataque que fica\\nmais forte cada vez\\nque o usuário leva\\num golpe na luta."'
    },
    # 100: Teleport
    "Teleport": {
        "2line": '    "Foge de batalhas selvagens.\\n"\n    "Retorna ao Centro Pokémon.");',
        "4line": '"Permite fugir de uma\\nluta selvagem. Fora\\nda luta, viaja ao\\núltimo Centro Pkmn."'
    }
}

with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8') as f:
    code = f.read()

count_2l = 0
count_4l = 0

# FireSpin 2-line
orig_firespin_2l = """static const u8 sFireSpinDescription[] = _(
    "Traps the foe in a ring of\\n"
#if B_BINDING_TURNS >= GEN_5
    "fire for 4 or 5 turns.");
#else
    "fire for 2 to 5 turns.");
#endif"""

new_firespin_2l = """static const u8 sFireSpinDescription[] = _(
    "Prende o alvo em um aro\\n"
#if B_BINDING_TURNS >= GEN_5
    "de fogo de 4 a 5 turnos.");
#else
    "de fogo de 2 a 5 turnos.");
#endif"""

if orig_firespin_2l in code:
    code = code.replace(orig_firespin_2l, new_firespin_2l)
    count_2l += 1
else:
    print("WARN: orig_firespin_2l not found")

# FireSpin 4-line
orig_firespin_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_FireSpin[] = _("The foe is trapped\\nin an intense spiral\\nof fire that rages\\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_FireSpin[] = _("The foe is trapped\\nin an intense spiral\\nof fire that rages\\ntwo to five turns.");
#endif"""

new_firespin_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_FireSpin[] = _("O alvo é preso em\\numa espiral de fogo\\nintensa que dura de\\nquatro a cinco turnos.");
#else
static const u8 sMoveFourLineDescription_FireSpin[] = _("O alvo é preso em\\numa espiral de fogo\\nintensa que dura de\\ndois a cinco turnos.");
#endif"""

if orig_firespin_4l in code:
    code = code.replace(orig_firespin_4l, new_firespin_4l)
    count_4l += 1
else:
    print("WARN: orig_firespin_4l not found")

for name, trans in moves_51_to_100.items():
    var_2l = f"s{name}Description"
    pattern_2l = rf'(static const u8 {var_2l}\[\] = _\(\s*\n)(.*?)(?=\);)'
    m2 = re.search(pattern_2l, code, re.DOTALL)
    if m2:
        code = code[:m2.start(2)] + trans["2line"] + "\n" + code[m2.end(2) + 2:]
        count_2l += 1
    else:
        print(f"WARN: 2-line not found for {var_2l}")

    var_4l = f"sMoveFourLineDescription_{name}"
    pattern_4l = rf'(static const u8 {var_4l}\[\] = _\()(.*?)(\);)'
    matches_4l = list(re.finditer(pattern_4l, code))
    if matches_4l:
        for m4 in reversed(matches_4l):
            code = code[:m4.start(2)] + trans["4line"] + code[m4.end(2):]
            count_4l += 1
    else:
        print(f"WARN: 4-line not found for {var_4l}")

with open('src/data/text/move_descriptions.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(code)

print(f"Sucesso! Total atualizado no Lote 2: {count_2l} 2-line e {count_4l} 4-line.")
