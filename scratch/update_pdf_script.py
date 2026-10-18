with open('scratch/generate_guide_pdf.py', 'r', encoding='utf-8') as f:
    c = f.read()

# 1. Rota 22 com Eevee
old_r22 = """            Paragraph("<b>Rota 22</b><br/>(Oeste de Viridian)", bold_body),
            Table([[get_sprite("marill", (36, 36)), Paragraph("<b>Marill</b>", bold_body)],
                   [get_sprite("hoppip", (36, 36)), Paragraph("<b>Hoppip</b>", bold_body)],
                   [get_sprite("wooper", (36, 36)), Paragraph("<b>Wooper</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Hoppip / Marill:</b> De Dia<br/><b>Wooper:</b> À Noite", body_style),
            Paragraph("Marill e Wooper trazem tipos Água e Terrestre muito cedo, essenciais contra o ginásio de Pewter!", body_style)"""

new_r22 = """            Paragraph("<b>Rota 22</b><br/>(Oeste de Viridian)", bold_body),
            Table([[get_sprite("eevee", (36, 36)), Paragraph("<b>Eevee</b>", bold_body)],
                   [get_sprite("marill", (36, 36)), Paragraph("<b>Marill</b>", bold_body)],
                   [get_sprite("wooper", (36, 36)), Paragraph("<b>Wooper</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Eevee:</b> Dia e Noite (Raro &amp; DexNav)<br/><b>Hoppip/Marill:</b> De Dia<br/><b>Wooper:</b> À Noite", body_style),
            Paragraph("<b>OPORTUNIDADE:</b> Capture múltiplos Eevees selvagens para montar todas as evoluções!", body_style)"""

# 2. Mt Moon com Riolu
old_moon = """            Paragraph("<b>Mt. Moon</b><br/>(Caverna)", bold_body),
            Table([[get_sprite("dunsparce", (40, 40)), Paragraph("<b>Dunsparce</b>", bold_body)]], colWidths=[42, 60]),
            Paragraph("<b>Dunsparce:</b> Todos os andares subterrâneos (Raro)", body_style),
            Paragraph("Encontro especial de caverna com altos pontos de vida (HP) e golpes normais/terrestres.", body_style)"""

new_moon = """            Paragraph("<b>Mt. Moon</b><br/>(Caverna)", bold_body),
            Table([[get_sprite("riolu", (36, 36)), Paragraph("<b>Riolu</b>", bold_body)],
                   [get_sprite("dunsparce", (36, 36)), Paragraph("<b>Dunsparce</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Riolu:</b> Caverna &amp; DexNav (Raro)<br/><b>Dunsparce:</b> Subterrâneo", body_style),
            Paragraph("<b>NOVIDADE:</b> Riolu pode ser capturado logo cedo! Evolui para Lucario por Amizade de dia ou Nv. 30.", body_style)"""

# 3. Specials com Mew e Lucario
old_specials_end = """        [
            get_sprite("lugia", (36, 36)),
            Paragraph("<b>Lugia &amp; Ho-Oh</b><br/>Psí./Voador &amp; Fogo/Voador", body_style),
            Paragraph("<b>Navel Rock / Ilhas Sevii</b><br/>Eventos de Johto pós-game", body_style),
            Paragraph("Os grandes guardiões de Johto nos pontos mais altos e profundos.", body_style)
        ],"""

new_specials_end = """        [
            get_sprite("mew", (36, 36)),
            Paragraph("<b>Mew</b><br/>Psíquico", body_style),
            Paragraph("<b>Faraway Island (Ilha Distante)</b><br/>Nv. 30", body_style),
            Paragraph("Pegue o <b>Old Sea Map</b> no subsolo da Mansão de Cinnabar e viaje no barco do Capitão!", body_style)
        ],
        [
            get_sprite("lucario", (36, 36)),
            Paragraph("<b>Lucario</b><br/>Lutador / Aço", body_style),
            Paragraph("<b>Caverna de Cerulean</b> (Nv. 50+)<br/>ou evoluindo Riolu", body_style),
            Paragraph("O mestre da Aura! Aprende Close Combat, Aura Sphere e Extreme Speed!", body_style)
        ],
        [
            get_sprite("lugia", (36, 36)),
            Paragraph("<b>Lugia &amp; Ho-Oh</b><br/>Psí./Voador &amp; Fogo/Voador", body_style),
            Paragraph("<b>Navel Rock / Ilhas Sevii</b><br/>Eventos de Johto pós-game", body_style),
            Paragraph("Os grandes guardiões de Johto nos pontos mais altos e profundos.", body_style)
        ],"""

# 4. Evolutions com Eeveelutions e Riolu
old_evos_end = """        [
            Table([[get_sprite("porygon", (32, 32)), Paragraph("Porygon", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("porygon2", (32, 32)), Paragraph("<b>Porygon2</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Up-Grade</b> como Pedra", bold_body),
            Paragraph("Direto pela mochila como uma pedra evolutiva.", body_style)
        ],"""

new_evos_end = """        [
            Table([[get_sprite("porygon", (32, 32)), Paragraph("Porygon", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("porygon2", (32, 32)), Paragraph("<b>Porygon2</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Up-Grade</b> como Pedra", bold_body),
            Paragraph("Direto pela mochila como uma pedra evolutiva.", body_style)
        ],
        [
            Table([[get_sprite("eevee", (32, 32)), Paragraph("Eevee", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("espeon", (32, 32)), Paragraph("<b>Espeon</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Amizade de <b>Dia</b>", bold_body),
            Paragraph("Ou usar <b>Sun Stone (Pedra do Sol)</b> da Bolsa!", body_style)
        ],
        [
            Table([[get_sprite("eevee", (32, 32)), Paragraph("Eevee", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("umbreon", (32, 32)), Paragraph("<b>Umbreon</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Amizade de <b>Noite</b>", bold_body),
            Paragraph("Ou usar <b>Moon Stone (Pedra da Lua)</b> da Bolsa!", body_style)
        ],
        [
            Table([[get_sprite("riolu", (32, 32)), Paragraph("Riolu", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("lucario", (32, 32)), Paragraph("<b>Lucario</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Amizade de <b>Dia</b>", bold_body),
            Paragraph("Ou subir para o <b>Nível 30</b>!", body_style)
        ],"""

c = c.replace(old_r22, new_r22, 1)
c = c.replace(old_moon, new_moon, 1)
c = c.replace(old_specials_end, new_specials_end, 1)
c = c.replace(old_evos_end, new_evos_end, 1)

with open('scratch/generate_guide_pdf.py', 'w', encoding='utf-8') as f:
    f.write(c)

print('generate_guide_pdf.py atualizado com sucesso!')
