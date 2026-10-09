# Pokémon Kanto & Johto (PokéClassic)

<div align="center">

![GBA](https://img.shields.io/badge/Platform-GBA-red?style=for-the-badge&logo=nintendo)
![Engine](https://img.shields.io/badge/Engine-pokeemerald-green?style=for-the-badge)
![Language](https://img.shields.io/badge/Idioma-Portugu%C3%AAs%20(PT--BR)-blue?style=for-the-badge)
![Build](https://img.shields.io/github/actions/workflow/status/guuhferiani/kanto-johto/build.yml?branch=main&style=for-the-badge)

**Uma jornada épica contínua do Nível 1 ao 100 unindo Kanto e Johto, recriando os eventos de Pokémon Yellow sobre a engine de Pokémon Emerald (`pokeemerald`) para o Game Boy Advance, com mecânicas modernas de qualidade de vida e localização completa em Português do Brasil!**

</div>

---

## 🌟 Destaques & Recursos Exclusivos

* **Direção & Escalonamento Contínuo (Nível 1 ao 100):**
  * **Kanto Completo:** Jornada calibrada dos níveis 12 aos 60, culminando na vitória sobre a Liga Pokémon no Planalto Índigo.
  * **Johto Expandido:** Continuação da jornada enfrentando todos os 8 Líderes de Johto (Falkner até Clair) dos níveis 58 aos 83 com equipes desafiadoras.
  * **Batalha Suprema no Monte Silver:** Enfrente o lendário Campeão **Red** no topo da montanha mais alta, liderado pelo seu **Pikachu Nível 100**!
* **Qualidade de Vida (QoL) no Core da Engine:**
  * **Exp. Share Moderno Nativo:** Distribuição de experiência da Gen 6+ ativa desde o início (`expShare = 1`), proporcionando evolução fluida e equilibrada sem necessidade de grinding cansativo.
  * **Fluxo de Captura Otimizado:** Ritmo de jogo ágil sem interrupções desnecessárias.
* **Nova Identidade Visual & Arte de Abertura:**
  * Tela de título exclusiva com o logotipo customizado **"KANTO & JOHTO"**.
  * Arte de fundo temática unindo **Charizard & Lugia**.
  * Créditos oficiais da tela de início com `©2026 Gu Feriani`.
* **Enredo Fiel ao Pokémon Yellow:**
  * Início em Pallet Town recebendo o **Pikachu parceiro** do Professor Carvalho.
  * Rival Blue com **Eevee** como inicial.
  * A icônica dupla **Jessie e James** (Equipe Rocket) com Meowth, Arbok e Weezing em batalhas exclusivas (Torre Pokémon, Esconderijo de Celadon e Silph Co.).
  * Os três iniciais de Kanto (**Bulbasaur**, **Charmander** e **Squirtle**) acessíveis gratuitamente através de eventos clássicos com NPCs.
* **Sistema de Pokémon Companheiro (*Follower Pokémon*):**
  * O Pikachu (ou qualquer outro Pokémon da sua equipe) anda fora da Pokébola acompanhando seus passos no mapa, com interações e reações emocionais.
* **Recursos Avançados da Geração 3:**
  * Batalhas dinâmicas com Habilidades (*Abilities*), 25 Naturezas, sistema avançado de IVs/EVs.
  * Ciclo dinâmico de **Dia e Noite**.
  * Sistema de rastreamento **DexNav**.
  * **Mega Evoluções** e pedras evolutivas espalhadas pelo mapa.

---

## 🇧🇷 Projeto de Tradução (PT-BR)

Localização profunda e nativa no código-fonte GBA para Português do Brasil:

* **Batalha & Combate:** 100% traduzido (*Lutar, Mochila, Pokémon, Fugir*, golpes, efetividade, acertos críticos, status, ganho de EXP e captura).
* **Mochila & Bolsos:** Bolsos em português (*Itens, Remédios, Poké Bolas, Itens Batalha, Frutas, Tesouros, TMs & HMs, Itens-Chave*) com nomes dos itens e ações traduzidas.
* **Menus do Sistema:** Menu Iniciar (Start), Salvar/Continuar, Menu de Opções completo e opções de compra/venda do Poké Mart (*Comprar, Vender*).
* **Equipe & Sumário:** Abas e estatísticas traduzidas com todas as 25 naturezas em português (*Firme, Modesta, Tímida, Alegre, etc.*).
* **Interações de Campo:** Falas completas de uso de HMs (*Corte, Quebra-Pedra, Força, Surfe, Cachoeira, Mergulho*), avisos de Repelente e envio de Pokémon ao PC.
* **Diálogos de NPCs:** Tradução em progressão contínua mapa a mapa.

---

## 🛠️ Como Compilar o Projeto

O projeto utiliza o toolchain bare-metal **devkitARM** e a ferramenta **agbcc**:

### Pré-requisitos (Linux ou Windows com WSL2 - Ubuntu)
1. Instale as dependências essenciais:
   ```bash
   sudo apt update
   sudo apt install build-essential gcc-arm-none-eabi binutils-arm-none-eabi libpng-dev
   ```
2. Instale o compilador C compatível com GBA (`agbcc`):
   ```bash
   git clone https://github.com/pret/agbcc.git
   cd agbcc
   ./build.sh
   ./install.sh /caminho/para/kanto-johto
   cd ..
   ```

### Compilando a ROM
No diretório raiz do projeto:
```bash
make -j$(nproc)
```
O processo compilará os binários oficiais:
* `Pokemon_Kanto_Johto.gba`
* `pokeClassic.gba`

---

## 👥 Equipe & Créditos

* **Lead Developer & Direção Geral (Kanto & Johto):** Gustavo Feriani
  * *Game design, balanceamento e escalonamento contínuo das duas regiões (Lv. 1 ao 100)*
  * *Nova identidade visual, logotipo customizado e arte de abertura com Charizard e Lugia*
  * *Implementação das mecânicas de qualidade de vida (QoL) e Exp. Share moderno nativo*
  * *Engenharia de compilação dual, esteira de CI/CD e localização completa em PT-BR*
* **Desenvolvedores da Base Original (PokéClassic / pokeemerald):** 
  * *danenders / LazyDev* (Desenvolvedor original)
  * *DaniRainbow* (Desenvolvedor das versões 1.4 / 1.5)
  * *Headlocker03 & Liquid Justice* (Designers originais)
* **Comunidade & Ferramentas:** PRET, Rom Hacking Hideout (RHH), Team Aqua's Hideout e Comunidade Antigravity.
* **Agradecimentos Especiais:** Hyo Oppa, Wolf, Solo993, Bushbugger, PokeMerp, Lunos, TheXaman, Ghoulslash, citrusbolt, asparaguseduardo, exposeed, surskitty, GriffinR, ShadowXeen, Jaizu, Dani96sp, MrMazzone, Rorydaredking, khurram1192, Bamboozaler, voloved, Eduardo Quezada D'Ottone, Fyreire, Hiroshi Sotomura, Lil Dill, InfiniteBacon42 (indicador Shiny).