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
   - Binário `pokeClassic.gba` e `Pokemon_Kanto_Johto.gba` compilados sem erros e 100% estáveis.
5. **Correção do Centro Pokémon de Pewter City e Escada Rolante:**
   - Adicionados warps em todas as posições do tapete de entrada (`x: 6, 7, 8`) e corrigido `allow_cycling: false`.
   - Corrigido recolhimento seguro do seguidor (`HideFollowerForFieldEffect`) antes de congelar objetos na escada rolante.
6. **Auditoria e Correções Preventivas Globais (Centros Pokémon, Marts e Ginásios):**
   - **Solução Universal no Motor C (`GetWarpEventAtPosition`):** Todos os Centros Pokémon de Kanto e Johto (Viridian, Cerulean, Vermilion, Celadon, Fuchsia, Saffron, Cinnabar, etc.) agora permitem sair pisando em qualquer um dos 3 blocos do tapete vermelho (`x: 6, 7, 8`), evitando que o jogador fique travado em qualquer cidade futura.
   - **Ginásio de Pewter City:** Adicionado warp no bloco esquerdo do tapete de saída (`x: 5, y: 14`), permitindo sair por ambos os blocos.
   - **Interiores de Pewter City:** Corrigido `allow_cycling: false` e `allow_escaping: false` no Mart, Casas e Museu (1F e 2F).
   - **ROM Sincronizada:** Binário `Pokemon_Kanto_Johto.gba` atualizado no Google Drive.
7. **Clímax do Monte Silver e Batalha contra o Campeão Red:**
   - Configurado o mapa do cume do Monte Silver (`MAP_MT_PYRE_SUMMIT`) com clima de neve constante (`WEATHER_SNOW`), música épica e banner pop-up oficial "Monte Silver".
   - Red posicionado no cume (`x: 23, y: 5`) com sprite oficial `OBJ_EVENT_GFX_RED` e ampla área aberta ao redor para segurança total do Pokémon Companheiro (*Follower*).
   - Clima de neve em batalha dispara Granizo (*Hail*) automaticamente como nos jogos originais HGSS.
   - Diálogo icônico de silêncio (`"..."`), tema oficial de Campeão (`MUS_RG_VS_CHAMPION`), e equipe lendária de nível 96 a 100 liderada por Pikachu com Light Ball e Volt Tackle.
   - Recompensa épica pós-vitória: Cinza Sagrada (`ITEM_SACRED_ASH`) e Master Ball (`ITEM_MASTER_BALL`), com suporte a revanche contínua.
   - Conexão e retorno seguros: adicionado "Monte Silver" nas opções do navio S.S. Aqua (Vermilion e Costa de Johto) e Marinheiro de retorno na base da montanha (`x: 21, y: 28`) além de escadarias de saída automáticas.

---

## 🚀 2. Próximas Etapas de Desenvolvimento

### Frente A: Mapas, Eventos e Pós-Game de Johto
1. **Posicionar os 8 Líderes de Johto nos Mapas:**
   - Os dados e equipes de alto nível (Lv 58 a 83) já estão criados em `src/data/trainers.h` e `src/data/trainer_parties.h` (`TRAINER_LEADER_FALKNER` até `TRAINER_LEADER_CLAIR`).
   - **Objetivo:** Adicionar os eventos/NPCs nos mapas do hub de Johto (acessado pelo navio S.S. Aqua em Vermilion) para que o jogador possa desafiar cada um deles.
2. **Eventos dos Lendários:**
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
