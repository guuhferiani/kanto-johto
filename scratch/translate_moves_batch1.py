# -*- coding: utf-8 -*-
import re

# Dicionário com traduções dos golpes 1 a 50 (2 linhas e 4 linhas)
moves_1_to_50 = {
    # 1: Pound
    "Pound": {
        "2line": '    "Golpeia o alvo com as\\n"\n    "patas ou com a cauda.");',
        "4line": '"Um ataque físico\\nfeito com uma\\ncauda longa ou\\ncom as patas."'
    },
    # 2: Karate Chop
    "KarateChop": {
        "2line": '    "Ataque cortante com alta\\n"\n    "chance de acerto crítico.");',
        "4line": '"O alvo é atacado\\ncom um golpe rápido.\\nTem alta chance de\\nacerto crítico."'
    },
    # 3: Double Slap
    "DoubleSlap": {
        "2line": '    "Dá tapas repetidos no alvo\\n"\n    "de 2 a 5 vezes.");',
        "4line": '"O alvo recebe tapas\\nrepetidos, de um lado\\npara o outro, de 2\\na 5 vezes seguidas."'
    },
    # 4: Comet Punch
    "CometPunch": {
        "2line": '    "Dá socos repetidos no alvo\\n"\n    "de 2 a 5 vezes.");',
        "4line": '"O alvo é atingido\\npor uma sequência de\\nsocos rápidos que\\nacertam de 2 a 5 vezes."'
    },
    # 5: Mega Punch
    "MegaPunch": {
        "2line": '    "Um soco forte desferido com\\n"\n    "incrível poder.");',
        "4line": '"O alvo é atingido\\npor um soco lançado\\ncom incrível força\\nmuscular."'
    },
    # 6: Pay Day
    "PayDay": {
        "2line": '    "Atira moedas no alvo.\\n"\n    "O dinheiro é pego depois.");',
        "4line": '"Moedas são lançadas\\nno alvo. Dinheiro\\né recolhido após\\na batalha."'
    },
    # 7: Fire Punch
    "FirePunch": {
        "2line": '    "Soco flamejante que pode\\n"\n    "queimar o alvo.");',
        "4line": '"O alvo é socado com\\num punho de fogo.\\nPode deixar o alvo\\ncom queimadura."'
    },
    # 8: Ice Punch
    "IcePunch": {
        "2line": '    "Soco congelante que pode\\n"\n    "congelar o alvo.");',
        "4line": '"O alvo é socado com\\num punho de gelo.\\nPode deixar o alvo\\ncongelado."'
    },
    # 9: Thunder Punch
    "ThunderPunch": {
        "2line": '    "Soco elétrico que pode\\n"\n    "paralisar o alvo.");',
        "4line": '"O alvo é socado com\\num punho elétrico.\\nPode deixar o alvo\\nparalisado."'
    },
    # 10: Scratch
    "Scratch": {
        "2line": '    "Arranha o alvo com garras\\n"\n    "afiadas.");',
        "4line": '"Garras pontiagudas\\ne afiadas arranham\\no alvo com força."'
    },
    # 11: Vise Grip
    "ViseGrip": {
        "2line": '    "Prende o alvo com grandes\\n"\n    "e poderosas pinças.");',
        "4line": '"Pinças enormes e\\nimpressionantes\\nprendem e apertam\\no alvo."'
    },
    # 12: Guillotine
    "Guillotine": {
        "2line": '    "Ataque cruel com pinças.\\n"\n    "Pode desmaiar em um golpe.");',
        "4line": '"Um golpe feroz com\\npinças afiadas.\\nO alvo desmaiará\\nse for atingido."'
    },
    # 13: Razor Wind
    "RazorWind": {
        "2line": '    "Golpe de 2 turnos que ataca\\n"\n    "no 2º turno com corte.");',
        "4line": '"Lâminas de vento\\natingem o alvo no\\n2º turno. Tem alta\\nchance crítica."'
    },
    # 14: Swords Dance
    "SwordsDance": {
        "2line": '    "Dança de combate que amplia\\n"\n    "muito o Ataque.");',
        "4line": '"Uma dança frenética\\nde combate. Amplia\\nbastante o atributo\\nde Ataque."'
    },
    # 15: Cut
    "Cut": {
        "2line": '    "Corta o alvo com garras\\n"\n    "ou lâminas afiadas.");',
        "4line": '"Um ataque básico.\\nPode ser usado para\\ncortar arbustos e\\ngramas finas."'
    },
    # 16: Gust
    "Gust": {
        "2line": '    "Atinge o alvo com rajadas\\n"\n    "de vento com as asas.");',
        "4line": '"Atinge o alvo com\\numa forte rajada de\\nvento criada pelas\\nasas."'
    },
    # 17: Wing Attack
    "WingAttack": {
        "2line": '    "Golpeia o alvo com asas\\n"\n    "abertas amplamente.");',
        "4line": '"O alvo é golpeado\\ncom grandes asas\\nabertas com força."'
    },
    # 18: Whirlwind
    "Whirlwind": {
        "2line": '    "Afasta o alvo com vento\\n"\n    "e encerra a batalha.");',
        "4line": '"Faz o oponente ser\\ntrocado por outro.\\nNa natureza, encerra\\na batalha."'
    },
    # 19: Fly
    "Fly": {
        "2line": '    "Voa no 1º turno e desce\\n"\n    "atacando no 2º turno.");',
        "4line": '"Voa alto no 1º turno\\ne ataca no 2º.\\nPermite voar para\\ncidades conhecidas."'
    },
    # 21: Slam
    "Slam": {
        "2line": '    "Esmaga o alvo com uma cauda\\n"\n    "longa, cipós, etc.");',
        "4line": '"O alvo é chicoteado\\ncom uma cauda longa,\\ncipós ou tentáculos."'
    },
    # 22: Vine Whip
    "VineWhip": {
        "2line": '    "Golpeia o alvo com cipós\\n"\n    "delgados como chicotes.");',
        "4line": '"O alvo é golpeado\\ncom cipós esguios\\ncomo chicotes."'
    },
    # 23: Stomp
    "Stomp": {
        "2line": '    "Pisoteia o alvo com força.\\n"\n    "Pode fazê-lo hesitar.");',
        "4line": '"O alvo é pisoteado\\ncom pés pesados.\\nPode fazer o alvo\\nhesitar."'
    },
    # 24: Double Kick
    "DoubleKick": {
        "2line": '    "Dois chutes rápidos dados\\n"\n    "no mesmo turno.");',
        "4line": '"Duas pernas chutam\\no alvo em sucessão\\nrápida no mesmo\\nturno."'
    },
    # 25: Mega Kick
    "MegaKick": {
        "2line": '    "Um chute extremamente forte\\n"\n    "com poder muscular.");',
        "4line": '"O alvo é atacado\\npor um chute forte\\nlançado com poder\\nmuscular extremo."'
    },
    # 26: Jump Kick
    "JumpKick": {
        "2line": '    "Chute com salto. Se errar,\\n"\n    "o usuário se machuca.");',
        "4line": '"O usuário salta alto\\ne chuta. Se errar,\\nele mesmo se fere\\ncom a queda."'
    },
    # 27: Rolling Kick
    "RollingKick": {
        "2line": '    "Chute rápido giratório.\\n"\n    "Pode fazer hesitar.");',
        "4line": '"Chute rápido vindo\\nde um giro veloz.\\nPode fazer o alvo\\nhesitar."'
    },
    # 28: Sand Attack
    "SandAttack": {
        "2line": '    "Joga areia no rosto do\\n"\n    "alvo para baixar precisão.");',
        "4line": '"Muita areia é jogada\\nno rosto do alvo,\\nreduzindo sua taxa\\nde precisão."'
    },
    # 29: Headbutt
    "Headbutt": {
        "2line": '    "Uma cabeçada que pode\\n"\n    "fazer o alvo hesitar.");',
        "4line": '"O usuário avança com\\na cabeça baixa.\\nPode fazer o alvo\\nhesitar na luta."'
    },
    # 30: Horn Attack
    "HornAttack": {
        "2line": '    "Perfura o alvo com um ou\\n"\n    "mais chifres afiados.");',
        "4line": '"O alvo é golpeado\\ncom um chifre afiado\\ne pontiagudo."'
    },
    # 31: Fury Attack
    "FuryAttack": {
        "2line": '    "Perfura o alvo de 2 a 5\\n"\n    "vezes com chifres/bico.");',
        "4line": '"O alvo é perfurado\\nde 2 a 5 vezes com\\num chifre ou bico\\nafiado."'
    },
    # 32: Horn Drill
    "HornDrill": {
        "2line": '    "Ataque giratório com chifre.\\n"\n    "Desmaia o alvo ao acertar.");',
        "4line": '"O chifre gira feito\\numa broca potente.\\nO alvo desmaiará\\nse for acertado."'
    },
    # 33: Tackle
    "Tackle": {
        "2line": '    "Investe contra o alvo com\\n"\n    "o corpo todo.");',
        "4line": '"Um ataque físico de\\ncorpo inteiro onde\\no usuário avança e\\nesbarra no alvo."'
    },
    # 34: Body Slam
    "BodySlam": {
        "2line": '    "Pancada de corpo inteiro\\n"\n    "que pode paralisar.");',
        "4line": '"O usuário se joga\\ncom todo o peso.\\nPode deixar o alvo\\nparalisado."'
    },
    # 36: Take Down
    "TakeDown": {
        "2line": '    "Investida imprudente que\\n"\n    "também fere o usuário.");',
        "4line": '"Investida violenta\\ne descuidada que\\ntambém causa dano\\nao atacante."'
    },
    # 37: Thrash
    "Thrash": {
        "2line": '    "Ataca por 2 ou 3 turnos,\\n"\n    "mas fica confuso.");',
        "4line": '"O usuário se agita e\\nataca por 2 ou 3\\nturnos, ficando\\nconfuso ao final."'
    },
    # 38: Double-Edge
    "DoubleEdge": {
        "2line": '    "Golpe com risco de vida que\\n"\n    "também fere o atacante.");',
        "4line": '"Uma investida perigosa\\ncom toda a força,\\nque causa recuo ao\\nusuário."'
    },
    # 39: Tail Whip
    "TailWhip": {
        "2line": '    "Abana a cauda para reduzir\\n"\n    "a Defesa do alvo.");',
        "4line": '"Abana a cauda com\\ncharme, distraindo o\\nalvo e reduzindo sua\\nDefesa."'
    },
    # 40: Poison Sting
    "PoisonSting": {
        "2line": '    "Picada venenosa que pode\\n"\n    "envenenar o alvo.");',
        "4line": '"O alvo é espetado por\\num ferrão tóxico.\\nPode deixar o alvo\\nenvenenado."'
    },
    # 41: Twineedle
    "Twineedle": {
        "2line": '    "Dispara ferrões duas vezes.\\n"\n    "Pode envenenar.");',
        "4line": '"Ferrões nos braços\\natingem o alvo duas\\nvezes. Pode deixar\\no alvo envenenado."'
    },
    # 42: Pin Missile
    "PinMissile": {
        "2line": '    "Dispara espinhos afiados\\n"\n    "de 2 a 5 vezes.");',
        "4line": '"Espinhos afiados são\\ndisparados no alvo,\\nacertando de 2 a 5\\nvezes no turno."'
    },
    # 43: Leer
    "Leer": {
        "2line": '    "Encarada intimidadora que\\n"\n    "reduz a Defesa do alvo.");',
        "4line": '"O usuário encara o\\nalvo de modo hostil,\\nreduzindo o atributo\\nde Defesa dele."'
    },
    # 44: Bite
    "Bite": {
        "2line": '    "Mordida com dentes afiados.\\n"\n    "Pode fazer hesitar.");',
        "4line": '"Morde o inimigo com\\ndentes afiados.\\nPode fazer o alvo\\nhesitar na luta."'
    },
    # 45: Growl
    "Growl": {
        "2line": '    "Rosna docemente para reduzir\\n"\n    "o Ataque do alvo.");',
        "4line": '"Rosna com doçura\\npara cativar o alvo,\\nreduzindo o Ataque\\ndele."'
    },
    # 46: Roar
    "Roar": {
        "2line": '    "Assusta o alvo com rugido\\n"\n    "e encerra a batalha.");',
        "4line": '"O alvo foge com medo.\\nNa natureza, encerra\\na luta; com treinador,\\nforça uma troca."'
    },
    # 47: Sing
    "Sing": {
        "2line": '    "Canção suave que faz o alvo\\n"\n    "cair no sono.");',
        "4line": '"Uma canção suave e\\nrelaxante faz o alvo\\ncair num sono\\nprofundo."'
    },
    # 48: Supersonic
    "Supersonic": {
        "2line": '    "Ondas sonoras bizarras que\\n"\n    "confundem o alvo.");',
        "4line": '"Ondas sonoras em\\nalta frequência são\\ngeradas, deixando\\no alvo confuso."'
    },
    # 49: Sonic Boom
    "SonicBoom": {
        "2line": '    "Onda de choque que causa\\n"\n    "sempre 20 de dano.");',
        "4line": '"Ondas de choque\\nsônicas atingem o\\nalvo, causando sempre\\n20 pontos de dano."'
    },
    # 50: Disable
    "Disable": {
        "2line": '    "Bloqueia o último golpe\\n"\n    "usado pelo alvo.");',
        "4line": '"Por meio de poderes\\npsíquicos, bloqueia\\no último golpe usado\\npelo oponente."'
    }
}

with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8') as f:
    code = f.read()

count_2l = 0
count_4l = 0

# Substituir Bind (2-line e 4-line)
orig_bind_2l = """static const u8 sBindDescription[] = _(
    "Binds and squeezes the foe\\n"
#if B_BINDING_TURNS >= GEN_5
    "for 4 or 5 turns.");
#else
    "for 2 to 5 turns.");
#endif"""

new_bind_2l = """static const u8 sBindDescription[] = _(
    "Prende e espreme o alvo\\n"
#if B_BINDING_TURNS >= GEN_5
    "de 4 a 5 turnos.");
#else
    "de 2 a 5 turnos.");
#endif"""

if orig_bind_2l in code:
    code = code.replace(orig_bind_2l, new_bind_2l)
    count_2l += 1
else:
    print("WARN: orig_bind_2l not found")

# Substituir Wrap (2-line)
orig_wrap_2l = """static const u8 sWrapDescription[] = _(
    "Wraps and squeezes the foe\\n"
#if B_BINDING_TURNS >= GEN_5
    "for 4 or 5 turns.");
#else
    "for 2 to 5 turns.");
#endif"""

new_wrap_2l = """static const u8 sWrapDescription[] = _(
    "Envolve e aperta o alvo\\n"
#if B_BINDING_TURNS >= GEN_5
    "de 4 a 5 turnos.");
#else
    "de 2 a 5 turnos.");
#endif"""

if orig_wrap_2l in code:
    code = code.replace(orig_wrap_2l, new_wrap_2l)
    count_2l += 1
else:
    print("WARN: orig_wrap_2l not found")

# 4-line Bind
orig_bind_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Bind[] = _("A long body or\\ntentacles are used\\nto bind the foe for\\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_Bind[] = _("A long body or\\ntentacles are used\\nto bind the foe for\\ntwo to five turns.");
#endif"""

new_bind_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Bind[] = _("Corpo comprido ou\\ntentáculos prendem\\no alvo por quatro\\nou cinco turnos.");
#else
static const u8 sMoveFourLineDescription_Bind[] = _("Corpo comprido ou\\ntentáculos prendem\\no alvo por dois a\\ncinco turnos.");
#endif"""

if orig_bind_4l in code:
    code = code.replace(orig_bind_4l, new_bind_4l)
    count_4l += 1
else:
    print("WARN: orig_bind_4l not found")

# 4-line Wrap
orig_wrap_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Wrap[] = _("A long body or\\nvines are used to\\nwrap the foe for\\nfour or five turns.");
#else
static const u8 sMoveFourLineDescription_Wrap[] = _("A long body or\\nvines are used to\\nwrap the foe for\\ntwo to five turns.");
#endif"""

new_wrap_4l = """#if defined(BATTLE_ENGINE) && B_BINDING_TURNS >= GEN_5
static const u8 sMoveFourLineDescription_Wrap[] = _("O corpo ou cipós\\nenvolvem o alvo por\\nquatro ou cinco\\nturnos seguidos.");
#else
static const u8 sMoveFourLineDescription_Wrap[] = _("O corpo ou cipós\\nenvolvem o alvo por\\ndois a cinco turnos\\nseguidos.");
#endif"""

if orig_wrap_4l in code:
    code = code.replace(orig_wrap_4l, new_wrap_4l)
    count_4l += 1
else:
    print("WARN: orig_wrap_4l not found")

for name, trans in moves_1_to_50.items():
    var_2l = f"s{name}Description"
    pattern_2l = rf'(static const u8 {var_2l}\[\] = _\(\s*\n)(.*?)(?=\);)'
    m2 = re.search(pattern_2l, code, re.DOTALL)
    if m2:
        code = code[:m2.start(2)] + trans["2line"] + "\n" + code[m2.end(2) + 2:]
        count_2l += 1
    else:
        print(f"WARN: 2-line not found for {var_2l}")

    var_4l = f"sMoveFourLineDescription_{name}"
    if name == "ViseGrip":
        var_4l = "sMoveFourLineDescription_ViceGrip"
    
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

print(f"Sucesso! Total atualizado: {count_2l} 2-line e {count_4l} 4-line.")
