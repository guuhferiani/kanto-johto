# Pokémon Kanto & Johto (PokéClassic)

<div align="center">

![GBA](https://img.shields.io/badge/Platform-GBA-red?style=for-the-badge&logo=nintendo)
![Engine](https://img.shields.io/badge/Engine-pokeemerald-green?style=for-the-badge)
![Language](https://img.shields.io/badge/Idioma-Portugu%C3%AAs%20(PT--BR)-blue?style=for-the-badge)
![Build](https://img.shields.io/github/actions/workflow/status/guuhferiani/kanto-johto/build.yml?branch=main&style=for-the-badge)

**Uma recriação fiel da jornada de Pokémon Yellow construída sobre a avançada engine de Pokémon Emerald (`pokeemerald`) para o Game Boy Advance, com tradução completa em Português do Brasil e novos recursos!**

</div>

---

## 📖 Sobre o Jogo

**Pokémon Kanto & Johto (PokéClassic)** une a nostalgia e os eventos inesquecíveis da clássica versão **Amarela (Pokémon Yellow)** com toda a robustez, física de batalha e gráficos da 3ª geração do GBA:

* **Enredo Fiel ao Pokémon Yellow:**
  * Início em Pallet Town recebendo o **Pikachu** especial do Professor Carvalho.
  * O rival Blue assume o **Eevee** como seu Pokémon inicial.
  * Presença da dupla **Jessie e James** (Equipe Rocket) com Meowth, Arbok e Weezing em batalhas exclusivas (Torre Pokémon, Esconderijo de Celadon e Silph Co.).
  * Os três iniciais de Kanto (**Bulbasaur**, **Charmander** e **Squirtle**) podem ser recebidos gratuitamente por NPCs de eventos clássicos.
* **Sistema de Pokémon Companheiro (*Follower Pokémon*):**
  * O Pikachu (ou qualquer outro membro da sua equipe) anda fora da Pokébola acompanhando seus passos no mapa, com direito a interações e expressões de humor.
* **Mecânicas da Geração 3 & Modernizações:**
  * Sistema de combate de *Pokémon Emerald* com Habilidades (*Abilities*), 25 Naturezas, sistema avançado de IVs/EVs.
  * Ciclo de **Dia e Noite**.
  * Ferramenta de busca **DexNav**.
  * Sistema de **Mega Evoluções** e pedras evolutivas espalhadas pelo mapa.
  * Novos recursos de pós-jogo e missões secundárias.

---

## 🇧🇷 Projeto de Tradução (PT-BR)

Este repositório conta com um projeto ativo de localização para o **Português do Brasil**:

* **Menus de Batalha & Combate:** 100% traduzidos (*Lutar, Mochila, Pokémon, Fugir*, mensagens de golpes, super efetivo, acertos críticos, status, EXP e captura).
* **Mochila & Bolsos:** Bolsos organizados em PT-BR (*Itens, Remédios, Poké Bolas, Itens Batalha, Frutas, Tesouros, TMs & HMs, Itens-Chave*) com nomes dos itens traduzidos.
* **Menu da Equipe & Sumário:** Abas e estatísticas traduzidas com todas as 25 naturezas em português (*Firme, Modesta, Tímida, Alegre, etc.*).
* **Sistema de Salvar & Menu de Opções:** Mensagens de gravação e todas as configurações traduzidas.
* **Serviços Essenciais:** Diálogos da Enfermeira Joy, Atendentes do Poké Mart e PC do Bill em português.
* **Diálogos de NPCs:** Tradução em progressão contínua mapa a mapa (Pallet Town, Rota 1 e Viridian City concluídas).

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
O arquivo binário executável será gerado na raiz:
* `Pokemon_Kanto_Johto.gba` / `pokeClassic.gba`

---

## 👥 Créditos & Agradecimentos

* **Desenvolvedor Original:** danenders / LazyDev
* **Desenvolvedor da v1.4 / v1.5 & Playtester:** DaniRainbow
* **Designers:** Headlocker03, Liquid Justice
* **Localização PT-BR:** Gustavo Feriani & Comunidade Antigravity
* **Equipe PRET & RHH:** Pret Discord, Rom Hacking Hideout (RHH) e Team Aqua's Hideout por fornecerem a base de descompilação `pokeemerald` e bibliotecas de expansão.
* **Agradecimentos Especiais:** Hyo Oppa, Wolf, Solo993, Bushbugger, PokeMerp, Lunos, TheXaman, Ghoulslash, citrusbolt, asparaguseduardo, exposeed, surskitty, GriffinR, ShadowXeen, Jaizu, Dani96sp, MrMazzone, Rorydaredking, khurram1192, Bamboozaler, voloved, Eduardo Quezada D'Ottone, Fyreire, Hiroshi Sotomura, Lil Dill, InfiniteBacon42 (indicador Shiny).