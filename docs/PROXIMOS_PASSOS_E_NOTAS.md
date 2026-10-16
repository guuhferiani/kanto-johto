# 📋 Próximos Passos e Notas do Projeto (PokéClassic: Kanto & Johto)

*Data da última atualização: 16 de Outubro de 2026*

---

## ✅ 1. O que foi Concluído e Validado Hoje
1. **Menu Start com Rolagem (7 itens por vez):**
   - Janela enquadrada e centralizada para até 7 opções visíveis por vez.
   - Setinhas animadas (▲ e ▼) indicando rolagem para itens extras ("Sair", etc.).
   - **Status:** Testado e aprovado no Pizza Boy GBA.
2. **Pokémon Selvagens Visíveis no Mapa (DexNav):**
   - Corrigido o bug que travava a aproximação e disparava a batalha no frame 0.
   - Agora o Pokémon surge a 3-6 passos de distância, anda pela grama e inicia a batalha somente com o contato físico do jogador.
   - **Status:** Testado e aprovado no Pizza Boy GBA.
3. **Follower Pokémon (Companheiro que Segue):**
   - Corrigido o mapeamento de gráficos dos sprites de Pikachu Parceiro, Eevee do Rival, evoluções de Eevee, Riolu, Lucario e Megas.
   - Liberada a opção *"Companheiro: Qualquer"* no Menu de Opções para permitir que qualquer Pokémon vivo da equipe siga o jogador desde o início do jogo.
4. **Build e ROM:**
   - Binário `pokeClassic.gba` compilado sem erros e 100% estável.

---

## 🚀 2. Próximas Etapas de Desenvolvimento

### Frente A: Mapas, Eventos e Pós-Game de Johto
1. **Posicionar os 8 Líderes de Johto nos Mapas:**
   - Os dados e equipes de alto nível (Lv 58 a 83) já estão criados em `src/data/trainers.h` e `src/data/trainer_parties.h` (`TRAINER_LEADER_FALKNER` até `TRAINER_LEADER_CLAIR`).
   - **Objetivo:** Adicionar os eventos/NPCs nos mapas do hub de Johto (acessado pelo navio S.S. Aqua em Vermilion) para que o jogador possa desafiar cada um deles.
2. **O Clímax do Monte Silver (Campeão Red):**
   - A equipe do Red já está programada com seu lendário Pikachu Lv 100 (Light Ball + Volt Tackle).
   - **Objetivo:** Criar a arena no cume da montanha, com diálogo icônico (`"..."`), clima dramático e a música tema oficial.
3. **Eventos dos Lendários:**
   - Conferir o evento de **Mew** na Ilha Distante (*Faraway Island*), já conectada ao S.S. Aqua.
   - Configurar o acesso a **Navel Rock** (Lugia e Ho-Oh) e **Cerulean Cave** (Mewtwo).

---

## 📱 3. Projeto Especial: App Nativo Android (`PokemonKantoJohto.apk`)

### Proposta
Transformar o jogo em um **aplicativo Android independente e instalável**, sem necessidade de abrir emuladores externos ou carregar arquivos `.gba` manualmente.

### Recursos Planejados para o APK
- **Ícone próprio** na tela inicial do celular com o logotipo oficial do projeto.
- **Boot direto** na tela de título personalizada (Charizard & Lugia).
- **Controles Touchscreen estilizados:** D-pad moderno, botões temáticos e feedback de vibração tátil (*haptics*).
- **Suporte automático a controles físicos:** Gamepads Bluetooth e USB (Xbox, PlayStation, Razer Kishi, Backbone).
- **Saves protegidos:** Memória privada do app sem risco de corrupção ou perda.
- **Arquitetura recomendada:** Standalone wrapper em C++/NDK (usando o core embutido do mGBA ou SDL2) empacotando o binário `pokeClassic.gba` nos assets do app.

---

## 💻 4. Como Retomar os Trabalhos na Próxima Sessão
* **Repositório:** `kanto-johto`
* **Compilação padrão:**
  ```bash
  wsl -e make -j4
  ```
* **ROM gerada:** `pokeClassic.gba`
