# 🔴⚪ Projeto Pokémon Kanto & Johto (Ordem Cronológica)

Projeto personalizado para Game Boy Advance baseado no motor decompilado do Pokémon Emerald / PokéClassic.

---

## 🧭 Visão do Projeto
* **História Contínua**: O jogador vivencia a saga completa de Kanto e Johto em ordem cronológica direta.
* **Foco Puro na Gen 1 e Gen 2**: Exatamente os **251 Pokémon canônicos**, sem as gerações posteriores.
* **Qualidade de Vida (QoL)**:
  * Sistema de Pokémon companheiro seguindo fora da Pokébola.
  * Divisão Físico / Especial nos golpes.
  * Tipo Fada integrado de forma equilibrada.
  * Tênis de corrida (Running Shoes) automáticos e ciclo dinâmico de dia/noite.

---

## 📈 Progressão de Nível Escolhida (Opção A: Escala Épica 1 a 100)

| Região / Etapa | Faixa de Nível | Eventos Principais |
| :--- | :--- | :--- |
| **Kanto** | Nível 5 a 55 | Jornada clássica de Pallet Town até a derrota de Giovanni e consagração na Liga Pokémon (Indigo Plateau). |
| **A Transição** | Nível 55 | Desbloqueio da fronteira oeste com rotas terrestres, marítimas e ferroviárias autorizadas pelo Prof. Carvalho. |
| **Johto** | Nível 55 a 90 | Ginásios de Johto em modo avançado/desafio (Falkner Lv 58+, Whitney Lv 66+, Clair Lv 85+). |
| **O Clímax** | Nível 95 a 100 | Cume do **Mt. Silver** com batalha final lendária. |

---

## 🗺️ Conexões Geográficas Planejadas

1. **Terrestre / Aquática**:
   * `Route 22` ➡️ `Route 26` & `Route 27` (com a passagem pelas cavernas de **Tohjo Falls**) conectando ao leste de New Bark Town.
2. **Ferroviária**:
   * O **Magnet Train** ligando diretamente Saffron City à metrópole de Goldenrod City.
3. **Marítima**:
   * O navio de passageiros **S.S. Aqua** fazendo a travessia entre Vermilion City e o porto de Olivine City.

---

## 💻 Como dar continuidade em outro computador

1. **Clonar o Repositório:**
   ```bash
   git clone https://github.com/guuhferiani/kanto-johto.git
   cd kanto-johto
   ```

2. **Edição Visual de Mapas:**
   * Baixar o executável do **Porymap** e abrir a pasta raiz do projeto.
   * Não é necessário carregar nenhuma ROM no Porymap (ele lê direto os arquivos `.json`, `.png` e `.inc`).

3. **Compilação do Jogo (`pokeclassic.gba`):**
   * Configurar o ambiente com devkitPro / WSL.
   * Rodar o comando:
     ```bash
     make
     ```
   * O arquivo `pokeclassic.gba` será gerado pronto para jogar no emulador **mGBA**.
