# -*- coding: utf-8 -*-
import re

# Nomes refinados para o padrão do Anime (até 16 caracteres)
anime_move_names_gen1 = {
    "MOVE_VINE_WHIP": "Chicote de Vinha",     # 16 letras
    "MOVE_WATER_GUN": "Revólver d'Água",      # 15 letras
    "MOVE_RAZOR_LEAF": "Folha Navalha",       # 13 letras
    "MOVE_NIGHT_SHADE": "Sombra Noturna",     # 14 letras
    "MOVE_SELF_DESTRUCT": "Autodestruição",   # 14 letras
    "MOVE_SKULL_BASH": "Quebra-Crânio",       # 13 letras
    "MOVE_SPIKE_CANNON": "Canhão Espinhos",   # 15 letras
    "MOVE_HIGH_JUMP_KICK": "Super Voadora",   # 13 letras
    "MOVE_DREAM_EATER": "Devorador Sonho",    # 15 letras
    "MOVE_FIRE_BLAST": "Explosão de Fogo",    # 16 letras
    "MOVE_WATERFALL": "Cascata",              # 7 letras
    "MOVE_SLASH": "Golpe Cortante",           # 14 letras
    "MOVE_SOFT_BOILED": "Ovo Fresco",         # 10 letras
    "MOVE_ROCK_SLIDE": "Deslize de Rocha",    # 16 letras
    "MOVE_CRABHAMMER": "Martelo Carang.",     # 16 letras
    "MOVE_DOUBLE_EDGE": "Gume Duplo",         # 10 letras
    "MOVE_LEECH_LIFE": "Suga-Vidas",          # 10 letras
    "MOVE_STRUGGLE": "Debater-se",            # 10 letras
}

with open('src/data/text/move_names.h', 'r', encoding='utf-8') as f:
    names_code = f.read()

names_count = 0
for const, name in anime_move_names_gen1.items():
    pattern = rf'(\[{const}\]\s*=\s*_\(")[^"]*("\),)'
    if re.search(pattern, names_code):
        names_code = re.sub(pattern, rf'\g<1>{name}\g<2>', names_code)
        names_count += 1
    else:
        print(f"WARN: Move name const {const} not found in move_names.h")

with open('src/data/text/move_names.h', 'w', encoding='utf-8', newline='\n') as f:
    f.write(names_code)

print(f"Sucesso! {names_count} nomes de golpes atualizados para o padrão do Anime.")

# Descrições dos golpes 101 a 165 (2 linhas e 4 linhas)
moves_101_to_165 = {
    # 101: Night Shade
    "NightShade": {
        "2line": '    "Miragem sombria que causa\\n"\n    "dano igual ao nível."',
        "4line": '"Uma miragem aterradora\\né projetada, causando\\ndano igual ao nível\\ndo atacante."'
    },
    # 102: Mimic
    "Mimic": {
        "2line": '    "Copia o último golpe usado\\n"\n    "pelo alvo na batalha."',
        "4line": '"O atacante copia o\\núltimo golpe usado\\npelo oponente durante\\ntoda a batalha."'
    },
    # 103: Screech
    "Screech": {
        "2line": '    "Guincho estridente que\\n"\n    "reduz muito a Defesa."',
        "4line": '"Um ruído estridente e\\nensurdecedor reduz\\nbastante o atributo\\nde Defesa do alvo."'
    },
    # 104: Double Team
    "DoubleTeam": {
        "2line": '    "Cria cópias ilusórias para\\n"\n    "aumentar a evasão."',
        "4line": '"Cria cópias velozes\\nde si mesmo por\\nilusão de ótica,\\nelevando a evasão."'
    },
    # 105: Recover
    "Recover": {
        "2line": '    "Restaura até metade do HP\\n"\n    "máximo do usuário."',
        "4line": '"Um golpe de autocura\\nque regenera o HP\\nem até metade da sua\\nvida máxima."'
    },
    # 106: Harden
    "Harden": {
        "2line": '    "Enrijece o corpo para\\n"\n    "aumentar a sua Defesa."',
        "4line": '"Endurece todos os\\nmúsculos do corpo\\npara aumentar a sua\\nDefesa."'
    },
    # 107: Minimize
    "Minimize": {
        "2line": '    "Comprime o corpo para\\n"\n    "aumentar muito a evasão."',
        "4line": '"Comprime as células\\ndo próprio corpo,\\nficando minúsculo e\\naumentando a evasão."'
    },
    # 108: Smokescreen
    "Smokescreen": {
        "2line": '    "Cortina de fumaça ou tinta\\n"\n    "que baixa a precisão."',
        "4line": '"Uma nuvem densa de\\nfumaça ou tinta cega\\no oponente, baixando\\nsua precisão."'
    },
    # 109: Confuse Ray
    "ConfuseRay": {
        "2line": '    "Raio sinistro que deixa\\n"\n    "o alvo confuso."',
        "4line": '"Um facho de luz\\nsinistro e espectral\\natinge o alvo,\\ndeixando-o confuso."'
    },
    # 110: Withdraw
    "Withdraw": {
        "2line": '    "Recolhe-se na carapaça\\n"\n    "para elevar a Defesa."',
        "4line": '"O usuário recolhe o\\ncorpo na sua dura\\nconcha para elevar\\na sua Defesa."'
    },
    # 111: Defense Curl
    "DefenseCurl": {
        "2line": '    "Enrola o corpo como bola\\n"\n    "para elevar a Defesa."',
        "4line": '"O usuário se enrola\\nfeito uma bola para\\nocultar fraquezas e\\nelevar a Defesa."'
    },
    # 112: Barrier
    "Barrier": {
        "2line": '    "Cria uma barreira mágica\\n"\n    "que amplia muito a Defesa."',
        "4line": '"Cria uma barreira\\nespectral resistente\\nque eleva bastante\\no atributo Defesa."'
    },
    # 113: Light Screen
    "LightScreen": {
        "2line": '    "Parede de luz que reduz o\\n"\n    "dano de ataques especiais."',
        "4line": '"Cria uma parede de\\nluz que reduz pela\\nmetade o dano de\\nataques especiais."'
    },
    # 114: Haze
    "Haze": {
        "2line": '    "Nuvem negra que anula todas\\n"\n    "as mudanças de status."',
        "4line": '"Uma névoa negra cobre\\na arena, anulando\\ntodas as alterações\\nde atributos."'
    },
    # 115: Reflect
    "Reflect": {
        "2line": '    "Escudo reflexivo que reduz\\n"\n    "o dano de ataques físicos."',
        "4line": '"Um escudo de energia\\nreflexivo é erguido,\\nreduzindo o dano de\\ngolpes físicos."'
    },
    # 116: Focus Energy
    "FocusEnergy": {
        "2line": '    "Concentra energia para ter\\n"\n    "mais chances críticas."',
        "4line": '"O usuário respira\\nfundo e foca o poder\\npara conseguir mais\\nacertos críticos."'
    },
    # 117: Bide
    "Bide": {
        "2line": '    "Aguenta dano por 2 turnos\\n"\n    "e devolve em dobro."',
        "4line": '"Aguenta golpes por\\ndois turnos seguidos\\ne devolve o dobro\\ndo dano recebido."'
    },
    # 118: Metronome
    "Metronome": {
        "2line": '    "Move o dedo no ritmo para\\n"\n    "usar um golpe aleatório."',
        "4line": '"Abana o dedo em um\\nritmo mágico para\\ndesferir qualquer\\ngolpe ao acaso."'
    },
    # 119: Mirror Move
    "MirrorMove": {
        "2line": '    "Copia o golpe usado pelo\\n"\n    "alvo com perfeição."',
        "4line": '"O atacante imita e\\ncontra-ataca com o\\nmesmo golpe que o\\nalvo acabou de usar."'
    },
    # 120: Self-Destruct
    "SelfDestruct": {
        "2line": '    "Explosão potente que desmaia\\n"\n    "o próprio atacante."',
        "4line": '"Uma explosão brutal\\nque atinge a todos na\\narena, desmaiando o\\npróprio atacante."'
    },
    # 121: Egg Bomb
    "EggBomb": {
        "2line": '    "Arremessa um grande ovo\\n"\n    "explosivo contra o alvo."',
        "4line": '"Um ovo enorme e duro\\né arremessado contra\\no oponente com força\\nexplosiva."'
    },
    # 122: Lick
    "Lick": {
        "2line": '    "Lambida com língua longa\\n"\n    "que pode paralisar."',
        "4line": '"Lambe o alvo com uma\\nlíngua longa e fria.\\nPode deixar o alvo\\nparalisado."'
    },
    # 123: Smog
    "Smog": {
        "2line": '    "Fumaça de gases poluentes\\n"\n    "que pode envenenar."',
        "4line": '"Gases sujos e tóxicos\\nsão soprados no alvo.\\nPodem deixar o alvo\\nenvenenado."'
    },
    # 124: Sludge
    "Sludge": {
        "2line": '    "Arremessa lodo tóxico que\\n"\n    "pode envenenar o alvo."',
        "4line": '"Lodo tóxico e imundo\\né lançado no alvo.\\nPode deixá-lo\\nenvenenado."'
    },
    # 125: Bone Club
    "BoneClub": {
        "2line": '    "Golpeia com um osso duro.\\n"\n    "Pode fazer o alvo hesitar."',
        "4line": '"O alvo é golpeado\\ncom um osso pesado.\\nPode fazer o alvo\\nhesitar na luta."'
    },
    # 126: Fire Blast
    "FireBlast": {
        "2line": '    "Chamas em formato de kanji\\n"\n    "que podem queimar o alvo."',
        "4line": '"Uma estrela de fogo\\nintensa explode no\\nalvo. Pode causar\\nqueimadura grave."'
    },
    # 127: Waterfall
    "Waterfall": {
        "2line": '    "Investida aquática potente.\\n"\n    "Permite subir cachoeiras."',
        "4line": '"Uma investida veloz\\nde água. Permite ao\\ntreinador subir por\\ncachoeiras no mapa."'
    },
    # 129: Swift
    "Swift": {
        "2line": '    "Dispara estrelas de luz\\n"\n    "que nunca erram o alvo."',
        "4line": '"Raios em formato de\\nestrelas mágicas são\\ndisparados e nunca\\nerram o alvo."'
    },
    # 130: Skull Bash
    "SkullBash": {
        "2line": '    "Recolhe a cabeça no 1º turno\\n"\n    "e ataca forte no 2º turno."',
        "4line": '"Ergue a Defesa no 1º\\nturno e ataca com uma\\ncabeçada demolidora\\nno 2º turno."'
    },
    # 131: Spike Cannon
    "SpikeCannon": {
        "2line": '    "Dispara espinhos afiados\\n"\n    "de 2 a 5 vezes seguidas."',
        "4line": '"Espinhos afiados são\\natirados feito canhão,\\nacertando de duas a\\ncinco vezes seguidas."'
    },
    # 132: Constrict
    "Constrict": {
        "2line": '    "Aperta com tentáculos e\\n"\n    "pode baixar Velocidade."',
        "4line": '"O alvo é agarrado e\\napertado por vinhas\\nou tentáculos. Pode\\nbaixar a Velocidade."'
    },
    # 133: Amnesia
    "Amnesia": {
        "2line": '    "Esquece preocupações para\\n"\n    "elevar muito a Def. Esp."',
        "4line": '"Esquece algo da mente\\ne relaxa, ampliando\\nbastante a sua Defesa\\nEspecial."'
    },
    # 134: Kinesis
    "Kinesis": {
        "2line": '    "Entorta uma colher para\\n"\n    "reduzir a precisão do alvo."',
        "4line": '"Distrai o oponente\\nentortando colheres\\ncom a mente, baixando\\na precisão dele."'
    },
    # 135: Soft-Boiled
    "SoftBoiled": {
        "2line": '    "Restaura até metade do HP.\\n"\n    "Pode curar aliados fora."',
        "4line": '"Cura até metade do HP\\nmáximo do usuário.\\nPode curar aliados da\\nequipe fora da luta."'
    },
    # 136: High Jump Kick
    "HighJumpKick": {
        "2line": '    "Voadora potente. Se errar,\\n"\n    "causa dano a si mesmo."',
        "4line": '"Um salto com joelhada\\npotente. Se errar o\\ngolpe, o atacante se\\nmachuca com a queda."'
    },
    # 137: Glare
    "Glare": {
        "2line": '    "Olhar intimidador que\\n"\n    "paralisa de pavor o alvo."',
        "4line": '"Intimida o alvo com o\\npadrão da barriga ou\\nolhar, paralisando-o\\nde pavor."'
    },
    # 138: Dream Eater
    "DreamEater": {
        "2line": '    "Devora o sonho de quem dorme\\n"\n    "para recuperar metade em HP."',
        "4line": '"Devora os sonhos de\\num oponente que está\\nadormecido, sugando\\nmetade do dano em HP."'
    },
    # 139: Poison Gas
    "PoisonGas": {
        "2line": '    "Gás venenoso soprado que\\n"\n    "pode envenenar o alvo."',
        "4line": '"Uma nuvem sufocante\\nde gás tóxico envolve\\no oponente, podendo\\nenvenená-lo."'
    },
    # 140: Barrage
    "Barrage": {
        "2line": '    "Arremessa objetos redondos\\n"\n    "de 2 a 5 vezes seguidas."',
        "4line": '"Projéteis redondos\\nsão lançados contra o\\nalvo de 2 a 5 vezes\\nnum único turno."'
    },
    # 141: Leech Life
    "LeechLife": {
        "2line": '    "Suga a energia vital para\\n"\n    "recuperar metade do dano."',
        "4line": '"Uma picada que suga\\na energia vital do\\nalvo, curando metade\\ndo dano causado."'
    },
    # 142: Lovely Kiss
    "LovelyKiss": {
        "2line": '    "Beijo com cara assustadora\\n"\n    "que induz ao sono."',
        "4line": '"O usuário força um\\nbeijo com uma cara\\nassustadora, fazendo\\no alvo adormecer."'
    },
    # 143: Sky Attack
    "SkyAttack": {
        "2line": '    "Brilha no 1º turno e desce\\n"\n    "com golpe aéreo crítico."',
        "4line": '"Brilha de energia no\\n1º turno e desfere um\\ngolpe aéreo devastador\\nno 2º turno."'
    },
    # 144: Transform
    "Transform": {
        "2line": '    "Copia a forma e os golpes\\n"\n    "do oponente na batalha."',
        "4line": '"O atacante se molda e\\nvira uma cópia exata\\ndo alvo, com os mesmos\\ngolpes e atributos."'
    },
    # 145: Bubble
    "Bubble": {
        "2line": '    "Dispara bolhas que podem\\n"\n    "reduzir a Velocidade."',
        "4line": '"Uma rajada suave de\\nbolhas atinge o alvo.\\nPode reduzir a sua\\nVelocidade."'
    },
    # 146: Dizzy Punch
    "DizzyPunch": {
        "2line": '    "Soco ritmado e cômico que\\n"\n    "pode deixar confuso."',
        "4line": '"Um soco rítmico que\\natinge o oponente\\nde surpresa. Pode\\ndeixá-lo confuso."'
    },
    # 147: Spore
    "Spore": {
        "2line": '    "Espalha esporos que sempre\\n"\n    "fazem o alvo adormecer."',
        "4line": '"Espalha esporos de\\nsono potentes que\\nsempre colocam o\\nalvo para dormir."'
    },
    # 148: Flash
    "Flash": {
        "2line": '    "Clarão que reduz precisão.\\n"\n    "Ilumina cavernas escuras."',
        "4line": '"Um clarão ofuscante\\nreduz a precisão do\\nalvo. Fora da luta,\\nilumina cavernas."'
    },
    # 149: Psywave
    "Psywave": {
        "2line": '    "Onda de calor psíquico com\\n"\n    "poder imprevisível."',
        "4line": '"O alvo é atacado por\\numa onda de energia\\npsíquica quente e\\nde poder variável."'
    },
    # 150: Splash
    "Splash": {
        "2line": '    "Apenas salpica e pula.\\n"\n    "Não causa efeito algum."',
        "4line": '"Apenas salpica água\\ne pula desajeitado.\\nNão tem efeito algum\\nna batalha."'
    },
    # 151: Acid Armor
    "AcidArmor": {
        "2line": '    "Liquefaz o próprio corpo\\n"\n    "para ampliar muito Defesa."',
        "4line": '"Derrete o corpo até\\num estado quase líquido\\npara aumentar muito\\na sua Defesa."'
    },
    # 152: Crabhammer
    "Crabhammer": {
        "2line": '    "Martelada com pinça grande.\\n"\n    "Alta chance crítica."',
        "4line": '"Martela o alvo com\\numa pinça pesada.\\nPossui alta taxa de\\nacertos críticos."'
    },
    # 153: Explosion
    "Explosion": {
        "2line": '    "Explosão devastadora que\\n"\n    "desmaia o usuário."',
        "4line": '"Gera uma explosão de\\npoder catastrófico,\\ndesmaiando o próprio\\natacante na luta."'
    },
    # 154: Fury Swipes
    "FurySwipes": {
        "2line": '    "Unhadas velozes que acertam\\n"\n    "de 2 a 5 vezes seguidas."',
        "4line": '"Unhadas ferozes são\\ndesferidas no alvo de\\nduas a cinco vezes no\\nmesmo turno."'
    },
    # 155: Bonemerang
    "Bonemerang": {
        "2line": '    "Lança um bumerangue de osso\\n"\n    "que atinge 2 vezes."',
        "4line": '"Lança um osso feito\\nbumerangue que vai e\\nvolta, acertando o\\nalvo duas vezes."'
    },
    # 156: Rest
    "Rest": {
        "2line": '    "Dorme por 2 turnos para se\\n"\n    "curar de tudo e encher HP."',
        "4line": '"Dorme por 2 turnos,\\nrecuperando todo o seu\\nHP e curando qualquer\\nproblema de status."'
    },
    # 157: Rock Slide
    "RockSlide": {
        "2line": '    "Derruba pedras gigantes.\\n"\n    "Pode fazer hesitar."',
        "4line": '"Rochas enormes caem\\nsobre os alvos.\\nPode fazer o oponente\\nhesitar na luta."'
    },
    # 158: Hyper Fang
    "HyperFang": {
        "2line": '    "Mordida com presas afiadas.\\n"\n    "Pode fazer o alvo hesitar."',
        "4line": '"Morde ferozmente com\\ndentes pontiagudos.\\nPode fazer o oponente\\nhesitar."'
    },
    # 159: Sharpen
    "Sharpen": {
        "2line": '    "Reduz bordas poligonais\\n"\n    "para aumentar o Ataque."',
        "4line": '"Afia os ângulos do\\npróprio corpo para\\naumentar o atributo\\nde Ataque."'
    },
    # 160: Conversion
    "Conversion": {
        "2line": '    "Muda o tipo do Pokémon para\\n"\n    "o tipo de um dos seus golpes."',
        "4line": '"Muda o tipo elemental\\ndo usuário para o\\nmesmo tipo de um dos\\nseus próprios golpes."'
    },
    # 161: Tri Attack
    "TriAttack": {
        "2line": '    "Dispara 3 feixes de energia.\\n"\n    "Pode queimar, gelar ou par."',
        "4line": '"Três raios de energia\\nsão disparados juntos.\\nPodem queimar, gelar\\nou paralisar."'
    },
    # 162: Super Fang
    "SuperFang": {
        "2line": '    "Mordida com dentes afiados\\n"\n    "que corta metade do HP."',
        "4line": '"Morde o oponente com\\npresas enormes, tirando\\nexatamente metade da\\nvida atual dele."'
    },
    # 163: Slash
    "Slash": {
        "2line": '    "Golpe cortante com garras.\\n"\n    "Alta chance crítica."',
        "4line": '"Retalha o oponente com\\ngarras afiadas.\\nPossui alta taxa de\\nacertos críticos."'
    },
    # 164: Substitute
    "Substitute": {
        "2line": '    "Usa 1/4 do HP para criar\\n"\n    "um boneco de isca."',
        "4line": '"Usa um quarto do HP\\nmáximo para criar uma\\nisca que absorve todo\\no dano por ele."'
    },
    # 165: Struggle
    "Struggle": {
        "2line": '    "Usado sem PP. Causa dano,\\n"\n    "mas fere o usuário."',
        "4line": '"Usado apenas quando\\nse esgotam todos os\\nPPs. Causa dano mas\\nfere o atacante."'
    }
}

with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8') as f:
    code = f.read()

count_2l = 0
count_4l = 0

# Clamp 2-line
orig_clamp_2l = """static const u8 sClampDescription[] = _(
    "Traps and squeezes the\\n"
#if B_BINDING_TURNS >= GEN_5
    "foe for 4 or 5 turns.");
#else
    "foe for 2 to 5 turns.");
#endif"""

new_clamp_2l = """static const u8 sClampDescription[] = _(
    "Prende e aperta o alvo\\n"
#if B_BINDING_TURNS >= GEN_5
    "de 4 a 5 turnos.");
#else
    "de 2 a 5 turnos.");
#endif"""

if orig_clamp_2l in code:
    code = code.replace(orig_clamp_2l, new_clamp_2l)
    count_2l += 1
else:
    print("WARN: orig_clamp_2l not found")

# Clamp 4-line
orig_clamp_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Clamp[] = _("The foe is clamped\\nand squeezed by\\nthe user's shell for\\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_Clamp[] = _("The foe is clamped\\nand squeezed by\\nthe user's shell for\\ntwo to five turns.");
#endif"""

new_clamp_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Clamp[] = _("O alvo é prensado e\\napertado pela concha\\npor quatro ou cinco\\nturnos seguidos.");
#else
static const u8 sMoveFourLineDescription_Clamp[] = _("O alvo é prensado e\\napertado pela concha\\npor dois a cinco\\nturnos seguidos.");
#endif"""

if orig_clamp_4l in code:
    code = code.replace(orig_clamp_4l, new_clamp_4l)
    count_4l += 1
else:
    print("WARN: orig_clamp_4l not found")

for name, trans in moves_101_to_165.items():
    var_2l = f"s{name}Description"
    pattern_2l = rf'(static const u8 {var_2l}\[\] = _\(\s*\n)(.*?)(?=\);)'
    m2 = re.search(pattern_2l, code, re.DOTALL)
    if m2:
        code = code[:m2.start(2)] + trans["2line"] + "\n" + code[m2.end(2):]
        count_2l += 1
    else:
        print(f"WARN: 2-line not found for {var_2l}")

    var_4l = f"sMoveFourLineDescription_{name}"
    if name == "HighJumpKick":
        var_4l = "sMoveFourLineDescription_HiJumpKick"
    
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

print(f"Sucesso! Lote 3: {count_2l} descrições 2-line e {count_4l} descrições 4-line atualizadas.")
