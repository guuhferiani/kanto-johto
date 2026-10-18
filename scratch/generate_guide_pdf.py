# -*- coding: utf-8 -*-
import os
from PIL import Image
from reportlab.lib.pagesizes import letter
from reportlab.lib import colors
from reportlab.platypus import (
    SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, Image as RLImage, PageBreak, KeepTogether, HRFlowable
)
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.pdfgen import canvas

os.makedirs("scratch/guide_sprites", exist_ok=True)

def get_sprite(species_dir, size=(52, 52)):
    out_file = f"scratch/guide_sprites/{species_dir}.png"
    src_file = f"graphics/pokemon/{species_dir}/front.png"
    if not os.path.exists(out_file):
        if os.path.exists(src_file):
            im = Image.open(src_file).convert("RGBA")
            im_resized = im.resize(size, Image.Resampling.NEAREST)
            im_resized.save(out_file, format="PNG")
        else:
            return None
    return RLImage(out_file, width=size[0], height=size[1])

class NumberedCanvas(canvas.Canvas):
    def __init__(self, *args, **kwargs):
        super(NumberedCanvas, self).__init__(*args, **kwargs)
        self._saved_page_states = []

    def showPage(self):
        self._saved_page_states.append(dict(self.__dict__))
        self._startPage()

    def save(self):
        num_pages = len(self._saved_page_states)
        for state in self._saved_page_states:
            self.__dict__.update(state)
            self.draw_page_decorations(num_pages)
            super(NumberedCanvas, self).showPage()
        super(NumberedCanvas, self).save()

    def draw_page_decorations(self, page_count):
        if self._pageNumber > 1:
            self.saveState()
            self.setFont("Helvetica-Bold", 8)
            self.setFillColor(colors.HexColor("#7f8c8d"))
            # Header
            self.drawString(54, 755, "POKÉMON KANTO & JOHTO — GUIA OFICIAL DO TREINADOR")
            self.setStrokeColor(colors.HexColor("#bdc3c7"))
            self.setLineWidth(0.5)
            self.line(54, 748, 558, 748)
            # Footer
            self.line(54, 45, 558, 45)
            self.setFont("Helvetica", 8)
            self.drawString(54, 32, "Edição Especial Kanto + Johto Integrado")
            page_text = f"Página {self._pageNumber} de {page_count}"
            self.drawRightString(558, 32, page_text)
            self.restoreState()

def build_pdf(filename="Guia_Pokemon_Kanto_Johto.pdf"):
    doc = SimpleDocTemplate(
        filename,
        pagesize=letter,
        leftMargin=40,
        rightMargin=40,
        topMargin=50,
        bottomMargin=50
    )

    styles = getSampleStyleSheet()
    
    title_style = ParagraphStyle(
        'CoverTitle',
        parent=styles['Normal'],
        fontName='Helvetica-Bold',
        fontSize=28,
        leading=34,
        textColor=colors.HexColor('#1b3a4b'),
        alignment=1
    )
    subtitle_style = ParagraphStyle(
        'CoverSub',
        parent=styles['Normal'],
        fontName='Helvetica-Bold',
        fontSize=14,
        leading=18,
        textColor=colors.HexColor('#e63946'),
        alignment=1
    )
    desc_style = ParagraphStyle(
        'CoverDesc',
        parent=styles['Normal'],
        fontName='Helvetica',
        fontSize=10,
        leading=14,
        textColor=colors.HexColor('#2c3e50'),
        alignment=1
    )
    h1_style = ParagraphStyle(
        'Header1',
        parent=styles['Normal'],
        fontName='Helvetica-Bold',
        fontSize=16,
        leading=20,
        textColor=colors.HexColor('#1b3a4b'),
        spaceAfter=6
    )
    h2_style = ParagraphStyle(
        'Header2',
        parent=styles['Normal'],
        fontName='Helvetica-Bold',
        fontSize=12,
        leading=16,
        textColor=colors.HexColor('#e63946'),
        spaceBefore=8,
        spaceAfter=4
    )
    body_style = ParagraphStyle(
        'BodyDark',
        parent=styles['Normal'],
        fontName='Helvetica',
        fontSize=9,
        leading=13,
        textColor=colors.HexColor('#2c3e50')
    )
    bold_body = ParagraphStyle(
        'BoldBody',
        parent=styles['Normal'],
        fontName='Helvetica-Bold',
        fontSize=9,
        leading=13,
        textColor=colors.HexColor('#1b3a4b')
    )
    tip_box = ParagraphStyle(
        'TipText',
        parent=styles['Normal'],
        fontName='Helvetica-Oblique',
        fontSize=8.5,
        leading=12,
        textColor=colors.HexColor('#2c3e50')
    )

    story = []

    # ==========================
    # CAPA
    # ==========================
    story.append(Spacer(1, 40))
    story.append(Paragraph("POKÉMON KANTO &amp; JOHTO", title_style))
    story.append(Spacer(1, 8))
    story.append(Paragraph("GUIA OFICIAL DE CAPTURA &amp; AVENTURA", subtitle_style))
    story.append(Spacer(1, 15))
    story.append(HRFlowable(width="60%", thickness=2, color=colors.HexColor('#e63946'), spaceAfter=20, spaceBefore=5))

    # Imagem destaque dos Mascotes
    pika = get_sprite("pikachu", size=(72, 72))
    chikorita = get_sprite("chikorita", size=(72, 72))
    cyndaquil = get_sprite("cyndaquil", size=(72, 72))
    totodile = get_sprite("totodile", size=(72, 72))
    
    mascots_table = Table([[chikorita, cyndaquil, pika, totodile]], colWidths=[100, 100, 100, 100])
    mascots_table.setStyle(TableStyle([
        ('ALIGN', (0,0), (-1,-1), 'CENTER'),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
    ]))
    story.append(mascots_table)
    story.append(Spacer(1, 25))

    intro_p = Paragraph(
        "<b>Bem-vindo à maior jornada Pokémon já criada!</b><br/>"
        "Este guia reúne todas as informações cruciais para novos treinadores: os novos Pokémon de Johto "
        "integrados desde as primeiras rotas de Kanto, localizações secretas de espécies raras, "
        "métodos de evolução especiais sem necessidade de trocas e as melhorias modernas de qualidade de vida (QoL).",
        desc_style
    )
    story.append(intro_p)
    story.append(Spacer(1, 30))

    # Box com Destaques
    features_data = [
        [Paragraph("<b>Pokédex Nacional Desbloqueada</b>", bold_body), Paragraph("Catalogação oficial de todos os #251 Pokémon desde a entrega em Pallet Town.", body_style)],
        [Paragraph("<b>Ciclo Dia &amp; Noite Dinâmico</b>", bold_body), Paragraph("Espécies diferentes aparecem nos períodos matutino e noturno nas rotas.", body_style)],
        [Paragraph("<b>Evoluções Sem Troca</b>", bold_body), Paragraph("Kadabra, Machoke, Haunter, Golem e espécies com itens evoluem sozinhos.", body_style)],
        [Paragraph("<b>HMs e TMs Modernos</b>", bold_body), Paragraph("HMs não ocupam golpe e ativam no mapa; TMs de uso infinito e reutilizável.", body_style)],
    ]
    feat_table = Table(features_data, colWidths=[180, 330])
    feat_table.setStyle(TableStyle([
        ('BACKGROUND', (0,0), (-1,-1), colors.HexColor('#edf2f7')),
        ('PADDING', (0,0), (-1,-1), 8),
        ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#cbd5e0')),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
    ]))
    story.append(feat_table)
    story.append(PageBreak())

    # ==========================
    # SEÇÃO 1: ROTAS INICIAIS (KANTO + JOHTO)
    # ==========================
    story.append(Paragraph("1. NOVOS ENCONTROS NAS ROTAS INICIAIS", h1_style))
    story.append(Paragraph(
        "Para criar uma experiência mais viva e dinâmica, os Pokémon mais amados de Johto foram introduzidos "
        "nas primeiras rotas de Kanto de acordo com o ciclo de <b>Dia e Noite</b>. Veja onde encontrar cada um:",
        body_style
    ))
    story.append(Spacer(1, 10))

    routes_data = [
        [
            Paragraph("<b>Local</b>", bold_body),
            Paragraph("<b>Pokémon de Johto</b>", bold_body),
            Paragraph("<b>Período / Condição</b>", bold_body),
            Paragraph("<b>Destaques &amp; Dicas</b>", bold_body)
        ],
        [
            Paragraph("<b>Rota 1</b><br/>(Pallet ➔ Viridian)", bold_body),
            Table([[get_sprite("sentret", (36, 36)), Paragraph("<b>Sentret</b>", bold_body)],
                   [get_sprite("ledyba", (36, 36)), Paragraph("<b>Ledyba</b>", bold_body)],
                   [get_sprite("hoothoot", (36, 36)), Paragraph("<b>Hoothoot</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Sentret:</b> Dia e Noite (comum)<br/><b>Ledyba:</b> De Dia<br/><b>Hoothoot:</b> À Noite", body_style),
            Paragraph("Ótima alternativa aos clássicos Pidgey e Rattata logo no primeiro passo da jornada.", body_style)
        ],
        [
            Paragraph("<b>Floresta de Viridian</b>", bold_body),
            Table([[get_sprite("pineco", (36, 36)), Paragraph("<b>Pineco</b>", bold_body)],
                   [get_sprite("spinarak", (36, 36)), Paragraph("<b>Spinarak</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Ledyba / Pineco:</b> De Dia<br/><b>Spinarak / Hoothoot:</b> À Noite", body_style),
            Paragraph("Pineco é resistente e aprende Autodestruição; Spinarak é perfeito para ataques venenosos noturnos.", body_style)
        ],
        [
            Paragraph("<b>Rota 22</b><br/>(Oeste de Viridian)", bold_body),
            Table([[get_sprite("eevee", (36, 36)), Paragraph("<b>Eevee</b>", bold_body)],
                   [get_sprite("marill", (36, 36)), Paragraph("<b>Marill</b>", bold_body)],
                   [get_sprite("wooper", (36, 36)), Paragraph("<b>Wooper</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Eevee:</b> Dia e Noite (Raro &amp; DexNav)<br/><b>Hoppip/Marill:</b> De Dia<br/><b>Wooper:</b> À Noite", body_style),
            Paragraph("<b>OPORTUNIDADE:</b> Capture múltiplos Eevees selvagens para montar todas as evoluções!", body_style)
        ],
        [
            Paragraph("<b>Rota 2</b><br/>(Viridian ➔ Pewter)", bold_body),
            Table([[get_sprite("mareep", (40, 40)), Paragraph("<b>Mareep</b>", bold_body)]], colWidths=[42, 60]),
            Paragraph("<b>Mareep:</b> Dia e Noite<br/><b>Hoothoot:</b> À Noite", body_style),
            Paragraph("<b>OPÇÃO DE OURO:</b> A ovelhinha elétrica evolui para Flaaffy (Nv.15) e Ampharos (Nv.30). Excelente contra Misty!", body_style)
        ],
        [
            Paragraph("<b>Rotas 3 &amp; 4</b><br/>(Pewter ➔ Mt. Moon)", bold_body),
            Table([[get_sprite("phanpy", (36, 36)), Paragraph("<b>Phanpy</b>", bold_body)],
                   [get_sprite("snubbull", (36, 36)), Paragraph("<b>Snubbull</b>", bold_body)],
                   [get_sprite("teddiursa", (36, 36)), Paragraph("<b>Teddiursa</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Phanpy / Snubbull:</b> De Dia<br/><b>Teddiursa:</b> À Noite", body_style),
            Paragraph("Phanpy evolui para o poderoso Donphan (Nv.25). Teddiursa evolui para Ursaring (Nv.30).", body_style)
        ],
        [
            Paragraph("<b>Mt. Moon</b><br/>(Caverna)", bold_body),
            Table([[get_sprite("riolu", (36, 36)), Paragraph("<b>Riolu</b>", bold_body)],
                   [get_sprite("dunsparce", (36, 36)), Paragraph("<b>Dunsparce</b>", bold_body)]], colWidths=[40, 60]),
            Paragraph("<b>Riolu:</b> Caverna &amp; DexNav (Raro)<br/><b>Dunsparce:</b> Subterrâneo", body_style),
            Paragraph("<b>NOVIDADE:</b> Riolu pode ser capturado logo cedo! Evolui para Lucario por Amizade de dia ou Nv. 30.", body_style)
        ],
    ]

    t_routes = Table(routes_data, colWidths=[90, 110, 150, 180])
    t_routes.setStyle(TableStyle([
        ('BACKGROUND', (0,0), (-1,0), colors.HexColor('#1b3a4b')),
        ('TEXTCOLOR', (0,0), (-1,0), colors.white),
        ('ALIGN', (0,0), (-1,-1), 'LEFT'),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
        ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#cbd5e0')),
        ('PADDING', (0,0), (-1,-1), 4),
        ('ROWBACKGROUNDS', (0,1), (-1,-1), [colors.white, colors.HexColor('#f8fafc')])
    ]))
    story.append(t_routes)
    story.append(PageBreak())

    # ==========================
    # SEÇÃO 2: POKÉMON ESPECIAIS, RAROS E LENDÁRIOS
    # ==========================
    story.append(Paragraph("2. GUIA DE CAPTURA: ESPECIAIS &amp; LENDÁRIOS", h1_style))
    story.append(Paragraph(
        "Localização das espécies únicas, fósseis revividos, presentes de NPCs e os lendários das duas regiões:",
        body_style
    ))
    story.append(Spacer(1, 8))

    specials_data = [
        [
            Paragraph("<b>Pokémon</b>", bold_body),
            Paragraph("<b>Espécie &amp; Tipo</b>", bold_body),
            Paragraph("<b>Onde e Como Obter</b>", bold_body),
            Paragraph("<b>Instruções / Dicas</b>", bold_body)
        ],
        [
            get_sprite("bulbasaur", (36, 36)),
            Paragraph("<b>Bulbasaur</b><br/>Grama / Veneno", body_style),
            Paragraph("<b>Floresta de Viridian</b> (Selvagem raro)<br/>ou Casa em Cerulean / Inicial", body_style),
            Paragraph("Pode ser capturado na grama alta da floresta (Nv. 4-8) ou recebido em Cerulean!", body_style)
        ],
        [
            get_sprite("charmander", (36, 36)),
            Paragraph("<b>Charmander</b><br/>Fogo", body_style),
            Paragraph("<b>Rota 24 (Ponte Pepita)</b><br/>Resgatado com o Treinador", body_style),
            Paragraph("Evento do Anime: no cume ao norte da Ponte Pepita, Damian te entrega Charmander (Nv. 7)!", body_style)
        ],
        [
            get_sprite("squirtle", (36, 36)),
            Paragraph("<b>Squirtle</b><br/>Água", body_style),
            Paragraph("<b>Vermilion City</b><br/>Policial Jenny (com Óculos Escuros!)", body_style),
            Paragraph("Entregue pela Policial Jenny (Nv. 10). Vem equipado com Black Glasses (Esquadrão Squirtle)!", body_style)
        ],
        [
            get_sprite("eevee", (36, 36)),
            Paragraph("<b>Eevee</b><br/>Normal", body_style),
            Paragraph("<b>Cidade de Celadon</b><br/>Mansão de Celadon (Entrada Traseira)", body_style),
            Paragraph("No telhado da mansão, dentro de uma Poké Bola sobre a mesa.", body_style)
        ],
        [
            get_sprite("lapras", (36, 36)),
            Paragraph("<b>Lapras</b><br/>Água / Gelo", body_style),
            Paragraph("<b>Silph Co. (7º Andar)</b><br/>Dado por funcionário salvo", body_style),
            Paragraph("Excelente para Surfar e usar golpes de Gelo contra Lance e o rival.", body_style)
        ],
        [
            get_sprite("snorlax", (36, 36)),
            Paragraph("<b>Snorlax</b><br/>Normal", body_style),
            Paragraph("<b>Rotas 12 e 16</b><br/>(Bloqueando o caminho)", body_style),
            Paragraph("Use a <b>Poké Flute</b> obtida com Sr. Fuji em Lavender para acordá-lo e batalhar.", body_style)
        ],
        [
            get_sprite("aerodactyl", (36, 36)),
            Paragraph("<b>Aerodactyl</b><br/>Pedra / Voador", body_style),
            Paragraph("<b>Museu de Pewter</b> (Old Amber)<br/>Revivido em Cinnabar", body_style),
            Paragraph("Corte a árvore lateral do museu para entrar pela porta dos fundos.", body_style)
        ],
        [
            get_sprite("articuno", (36, 36)),
            Paragraph("<b>Articuno</b><br/>Gelo / Voador", body_style),
            Paragraph("<b>Ilhas Seafoam (B4F)</b><br/>Lendário das Cavernas de Gelo", body_style),
            Paragraph("Empurre as pedras com Força (Strength) para desacelerar as correntezas.", body_style)
        ],
        [
            get_sprite("zapdos", (36, 36)),
            Paragraph("<b>Zapdos</b><br/>Elétrico / Voador", body_style),
            Paragraph("<b>Usina Elétrica (Power Plant)</b><br/>Fim do corredor da usina", body_style),
            Paragraph("Acessível pela Rota 10 surfando pelo canal de água ao norte.", body_style)
        ],
        [
            get_sprite("moltres", (36, 36)),
            Paragraph("<b>Moltres</b><br/>Fogo / Voador", body_style),
            Paragraph("<b>Mt. Ember (Ilha 1)</b><br/>ou Estrada da Vitória", body_style),
            Paragraph("Ave lendária de fogo no cume vulcânico.", body_style)
        ],
        [
            get_sprite("mewtwo", (36, 36)),
            Paragraph("<b>Mewtwo</b><br/>Psíquico", body_style),
            Paragraph("<b>Caverna de Cerulean (B1F)</b><br/>Pós-Liga Pokémon", body_style),
            Paragraph("O Pokémon supremo! Guarde a sua <b>Master Ball</b> para ele no Nível 70.", body_style)
        ],
        [
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
        ],
    ]

    t_specials = Table(specials_data, colWidths=[45, 115, 180, 190])
    t_specials.setStyle(TableStyle([
        ('BACKGROUND', (0,0), (-1,0), colors.HexColor('#1b3a4b')),
        ('TEXTCOLOR', (0,0), (-1,0), colors.white),
        ('ALIGN', (0,0), (-1,-1), 'LEFT'),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
        ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#cbd5e0')),
        ('PADDING', (0,0), (-1,-1), 3),
        ('ROWBACKGROUNDS', (0,1), (-1,-1), [colors.white, colors.HexColor('#f8fafc')])
    ]))
    story.append(t_specials)
    story.append(Spacer(1, 14))

    # ==========================
    # SUBSEÇÃO: FAMÍLIA EEVEE SELVAGEM
    # ==========================
    story.append(Paragraph("2.1 FAMÍLIA EEVEE: TODAS AS EVOLUÇÕES SELVAGENS", h1_style))
    story.append(Paragraph(
        "Agora você não precisa escolher apenas uma evolução! O <b>Eevee</b> e todas as suas formas evolutivas "
        "podem ser encontrados e capturados diretamente na natureza em locais temáticos de Kanto:",
        body_style
    ))
    story.append(Spacer(1, 8))

    eevee_family_data = [
        [
            Paragraph("<b>Pokémon</b>", bold_body),
            Paragraph("<b>Tipo</b>", bold_body),
            Paragraph("<b>Local Selvagem</b>", bold_body),
            Paragraph("<b>Condição &amp; Dica</b>", bold_body)
        ],
        [
            get_sprite("eevee", (36, 36)),
            Paragraph("<b>Eevee</b><br/>Normal", body_style),
            Paragraph("<b>Rotas 22, 7, 8, 25</b><br/>e Safari Zone", body_style),
            Paragraph("Disponível logo no início na Rota 22 (dia e noite) e no DexNav!", body_style)
        ],
        [
            get_sprite("vaporeon", (36, 36)),
            Paragraph("<b>Vaporeon</b><br/>Água", body_style),
            Paragraph("<b>Ilhas Seafoam (B3F)</b><br/>e Safari Zone (Água)", body_style),
            Paragraph("Surfando pelas águas geladas das Seafoam Islands com Lapras ou no Safari.", body_style)
        ],
        [
            get_sprite("jolteon", (36, 36)),
            Paragraph("<b>Jolteon</b><br/>Elétrico", body_style),
            Paragraph("<b>Usina Elétrica</b><br/>(Power Plant)", body_style),
            Paragraph("No chão da usina abandonada e via DexNav. Rápido e devastador!", body_style)
        ],
        [
            get_sprite("flareon", (36, 36)),
            Paragraph("<b>Flareon</b><br/>Fogo", body_style),
            Paragraph("<b>Mansão Pokémon (1F)</b><br/>Ilha de Cinnabar", body_style),
            Paragraph("Entre os escombros da mansão vulcânica de Cinnabar e via DexNav.", body_style)
        ],
        [
            get_sprite("espeon", (36, 36)),
            Paragraph("<b>Espeon</b><br/>Psíquico", body_style),
            Paragraph("<b>Rota 25 (Cabo Cerulean)</b><br/>e Rota 8 (a leste de Saffron)", body_style),
            Paragraph("Aparece exclusivamente durante o <b>DIA</b>! Poder psíquico solar.", body_style)
        ],
        [
            get_sprite("umbreon", (36, 36)),
            Paragraph("<b>Umbreon</b><br/>Noturno", body_style),
            Paragraph("<b>Rota 25 &amp; Rota 8</b> (Noite)<br/>e Torre Pokémon (3F)", body_style),
            Paragraph("Aparece à <b>NOITE</b> e nas sombras da Torre de Lavender. Tanque supremo!", body_style)
        ],
        [
            get_sprite("leafeon", (36, 36)),
            Paragraph("<b>Leafeon</b><br/>Grama", body_style),
            Paragraph("<b>Floresta de Viridian</b> (Dia)<br/>e Rota 25", body_style),
            Paragraph("Na grama densa da Floresta de Viridian e via DexNav. Rápido e cortante!", body_style)
        ],
        [
            get_sprite("glaceon", (36, 36)),
            Paragraph("<b>Glaceon</b><br/>Gelo", body_style),
            Paragraph("<b>Ilhas Seafoam (B4F)</b><br/>Caverna de Gelo do Articuno", body_style),
            Paragraph("No andar mais profundo de Seafoam e via DexNav. Ataque especial devastador!", body_style)
        ],
        [
            get_sprite("sylveon", (36, 36)),
            Paragraph("<b>Sylveon</b><br/>Fada", body_style),
            Paragraph("<b>Rota 25 (Cabo Cerulean)</b><br/>e Safari Zone (Centro)", body_style),
            Paragraph("No Cabo Cerulean de Dia e no Safari. Encanto e poder mágico de Fada!", body_style)
        ],
    ]

    t_eevee = Table(eevee_family_data, colWidths=[45, 115, 180, 190])
    t_eevee.setStyle(TableStyle([
        ('BACKGROUND', (0,0), (-1,0), colors.HexColor('#1b3a4b')),
        ('TEXTCOLOR', (0,0), (-1,0), colors.white),
        ('ALIGN', (0,0), (-1,-1), 'LEFT'),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
        ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#cbd5e0')),
        ('PADDING', (0,0), (-1,-1), 3),
        ('ROWBACKGROUNDS', (0,1), (-1,-1), [colors.white, colors.HexColor('#f8fafc')])
    ]))
    story.append(t_eevee)
    story.append(PageBreak())

    # ==========================
    # SEÇÃO 3: EVOLUÇÕES ESPECIAIS (SEM TROCAS)
    # ==========================
    story.append(Paragraph("3. GUIA DE EVOLUÇÃO: JOGUE 100% SOZINHO", h1_style))
    story.append(Paragraph(
        "Nesta ROM hack, você <b>não precisa de outro Game Boy nem de cabos</b> para completar a sua Pokédex! "
        "Todas as espécies que antes dependiam de troca agora evoluem de forma simples e direta:",
        body_style
    ))
    story.append(Spacer(1, 8))

    evos_data = [
        [
            Paragraph("<b>Pokémon Base</b>", bold_body),
            Paragraph("<b>Evolução</b>", bold_body),
            Paragraph("<b>Método Principal</b>", bold_body),
            Paragraph("<b>Método Alternativo</b>", bold_body)
        ],
        [
            Table([[get_sprite("kadabra", (32, 32)), Paragraph("Kadabra", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("alakazam", (32, 32)), Paragraph("<b>Alakazam</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("<b>Subir para o Nível 37</b>", bold_body),
            Paragraph("Usar o item <b>Cabo Link</b> da Mochila.", body_style)
        ],
        [
            Table([[get_sprite("machoke", (32, 32)), Paragraph("Machoke", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("machamp", (32, 32)), Paragraph("<b>Machamp</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("<b>Subir para o Nível 37</b>", bold_body),
            Paragraph("Usar o item <b>Cabo Link</b> da Mochila.", body_style)
        ],
        [
            Table([[get_sprite("graveler", (32, 32)), Paragraph("Graveler", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("golem", (32, 32)), Paragraph("<b>Golem</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("<b>Subir para o Nível 37</b>", bold_body),
            Paragraph("Usar o item <b>Cabo Link</b> da Mochila.", body_style)
        ],
        [
            Table([[get_sprite("haunter", (32, 32)), Paragraph("Haunter", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("gengar", (32, 32)), Paragraph("<b>Gengar</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("<b>Subir para o Nível 37</b>", bold_body),
            Paragraph("Usar o item <b>Cabo Link</b> da Mochila.", body_style)
        ],
        [
            Table([[get_sprite("onix", (32, 32)), Paragraph("Onix", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("steelix", (32, 32)), Paragraph("<b>Steelix</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Metal Coat</b> como Pedra", bold_body),
            Paragraph("Direto pela mochila como uma pedra evolutiva.", body_style)
        ],
        [
            Table([[get_sprite("scyther", (32, 32)), Paragraph("Scyther", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("scizor", (32, 32)), Paragraph("<b>Scizor</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Metal Coat</b> como Pedra", bold_body),
            Paragraph("Direto pela mochila como uma pedra evolutiva.", body_style)
        ],
        [
            Table([[get_sprite("seadra", (32, 32)), Paragraph("Seadra", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("kingdra", (32, 32)), Paragraph("<b>Kingdra</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Dragon Scale</b> como Pedra", bold_body),
            Paragraph("Direto pela mochila como uma pedra evolutiva.", body_style)
        ],
        [
            Table([[get_sprite("poliwhirl", (32, 32)), Paragraph("Poliwhirl", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("politoed", (32, 32)), Paragraph("<b>Politoed</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>King's Rock</b> como Pedra", bold_body),
            Paragraph("Pedra da Água ainda evolui para Poliwrath.", body_style)
        ],
        [
            Table([[get_sprite("slowpoke", (32, 32)), Paragraph("Slowpoke", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("slowking", (32, 32)), Paragraph("<b>Slowking</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>King's Rock</b> como Pedra", bold_body),
            Paragraph("Slowpoke também evolui para Slowbro no Nv. 37.", body_style)
        ],
        [
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
        ],
        [
            Table([[get_sprite("eevee", (32, 32)), Paragraph("Eevee", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("leafeon", (32, 32)), Paragraph("<b>Leafeon</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Leaf Stone (Pedra Folha)</b>", bold_body),
            Paragraph("Direto pela mochila no Eevee.", body_style)
        ],
        [
            Table([[get_sprite("eevee", (32, 32)), Paragraph("Eevee", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("glaceon", (32, 32)), Paragraph("<b>Glaceon</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Usar <b>Gelo Eterno</b> da Bolsa", bold_body),
            Paragraph("Funciona como pedra evolutiva de gelo!", body_style)
        ],
        [
            Table([[get_sprite("eevee", (32, 32)), Paragraph("Eevee", body_style)]], colWidths=[36, 60]),
            Table([[get_sprite("sylveon", (32, 32)), Paragraph("<b>Sylveon</b>", bold_body)]], colWidths=[36, 65]),
            Paragraph("Subir Nível com <b>Golpe Fada</b>", bold_body),
            Paragraph("Eevee aprende <i>Charm / Baby-Doll Eyes</i> por nível!", body_style)
        ],
    ]

    t_evos = Table(evos_data, colWidths=[100, 110, 150, 170])
    t_evos.setStyle(TableStyle([
        ('BACKGROUND', (0,0), (-1,0), colors.HexColor('#1b3a4b')),
        ('TEXTCOLOR', (0,0), (-1,0), colors.white),
        ('ALIGN', (0,0), (-1,-1), 'LEFT'),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
        ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#cbd5e0')),
        ('PADDING', (0,0), (-1,-1), 3),
        ('ROWBACKGROUNDS', (0,1), (-1,-1), [colors.white, colors.HexColor('#f8fafc')])
    ]))
    story.append(t_evos)
    story.append(Spacer(1, 15))

    # ==========================
    # SEÇÃO 4: DICAS DE OURO E QOL
    # ==========================
    story.append(Paragraph("4. DICAS DE OURO &amp; QUALIDADE DE VIDA", h1_style))
    
    qol_cards = [
        [
            Paragraph("<b>Flash Automático em Cavernas</b><br/>Ao entrar no Rock Tunnel ou cavernas escuras, se você tiver o <b>HM05 Flash</b> e um Pokémon compatível na equipe, a caverna se ilumina 100% sozinha instantaneamente!", tip_box),
            Paragraph("<b>Obstáculos Sem Ensinar Golpes</b><br/>Árvores de Cortar (Cut) e Pedras de Quebrar (Rock Smash) são removidas apertando o botão A se sua equipe tiver alguém compatível e o item na bolsa.", tip_box)
        ],
        [
            Paragraph("<b>TMs Infinitos e Reutilizáveis</b><br/>Máquinas Técnicas não se quebram após o uso! Ensine seus golpes favoritos (Bola Sombria, Terremoto, Raio de Gelo) para quantos Pokémon quiser.", tip_box),
            Paragraph("<b>Exp. Share com Chave Geral</b><br/>Você pode ligar ou desligar a divisão de experiência para toda a equipe a qualquer momento direto pelo menu de itens chave.", tip_box)
        ],
        [
            Paragraph("<b>DexNav &amp; Encontros Visíveis</b><br/>Recebido do Prof. Carvalho junto com a Pokédex! Conforme caminha pela grama, água ou cavernas, Pokémon visíveis surgem sacudindo o mapa com som e exclamação! Acesse pelo Menu Start para rastrear Pokémon por rota.", tip_box),
            Paragraph("<b>Dica Anti-Repetição (Repel + Radar)</b><br/>Para caçar apenas os Pokémon especiais que surgem visivelmente no mapa sem ser interrompido por encontros cegos na grama, use um <b>Repel</b>! Ele bloqueia encontros aleatórios mas mantém os visíveis ativos!", tip_box)
        ]
    ]
    t_qol = Table(qol_cards, colWidths=[260, 260])
    t_qol.setStyle(TableStyle([
        ('BACKGROUND', (0,0), (-1,-1), colors.HexColor('#edf2f7')),
        ('PADDING', (0,0), (-1,-1), 8),
        ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#cbd5e0')),
        ('VALIGN', (0,0), (-1,-1), 'TOP'),
    ]))
    story.append(t_qol)

    doc.build(story, canvasmaker=NumberedCanvas)
    print(f"Guia PDF gerado com sucesso em: {filename}")

if __name__ == "__main__":
    build_pdf("Guia_Pokemon_Kanto_Johto.pdf")
