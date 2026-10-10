extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} começou a cutucar a sua\nbarriga.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} está feliz, mas tímido.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} está te acompanhando alegremente.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} está sereno.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} parece estar adorando\ncaminhar com você!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} está radiante de saúde.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} parece muito feliz.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} se esforçou ao máximo.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} está cheirando os aromas\ndo ar ao redor.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} está pulando de alegria!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} ainda está se sentindo ótimo!");
static const u8 sHappyMsg11[] = _("Seu Pokémon sentiu o cheiro de\nfumaça.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} está cutucando a sua barriga.");
static const u8 sHappyMsg13[] = _("Seu Pokémon se espreguiçou e está\nrelaxando.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} parece querer ir na frente!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} está dando o melhor de si\npara te acompanhar.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} está se aconchegando a você\ncom muito carinho!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} está cheio de energia!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} parece estar muito feliz!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} está tão feliz que não para\nquieto!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} assentiu lentamente.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} está muito animado!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} está andando ao redor,\nouvindo os diferentes sons.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} parece muito interessado.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} está se esforçando para\ncontinuar em frente.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} olhou para você com um\nolhar radiante!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} te deu um olhar feliz e um\nsorriso.");
static const u8 sHappyMsg27[] = _("Seu Pokémon está sentindo o cheiro\ndas flores.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} parece muito feliz em ver\nvocê!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} olhou para cá e deu um\nsorriso maroto.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} se aconchegou a você com\nmuito carinho!");
  // Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Seu Pokémon parece feliz com o\ntempo agradável.");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} está cutucando o chão com\ninsistência.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} está de guarda.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} está encarando o nada com\npaciência.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} está vagando por aí.");
static const u8 sNeutralMsg04[] = _("Seu Pokémon deu um bocejo alto!");
static const u8 sNeutralMsg05[] = _("Seu Pokémon está olhando ao redor,\ninquieto.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} está olhando para cá e\nsorrindo.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} está observando os arredores\ncom curiosidade.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} soltou um brado de batalha.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} dançou uma dança incrível!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} está bem atento.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} está olhando fixamente para\no horizonte.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} está em alerta!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} olhou para longe e latiu!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} está tonto.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} está pisando nos seus pés!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} parece um pouco cansado.");
  // Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} não está feliz.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} vai acabar caindo!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} parece estar prestes a tombar!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} está se esforçando muito para\nte acompanhar...");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} parece chateado por algum\nmotivo...");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} está fazendo uma cara\nemburrada.");
static const u8 sUpsetMsg02[] = _(".....Seu Pokémon parece estar com\num pouco de frio.");
  // Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} está se abrigando na grama\npara fugir da chuva.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} soltou um rugido!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} está fazendo uma cara de\nbravo!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} parece irritado por algum\nmotivo.");
static const u8 sAngryMsg03[] = _("Seu Pokémon virou de costas com uma\nexpressão desafiadora.\p");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} soltou um grito.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} está olhando para baixo\nfixamente.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} está inspecionando a área.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} está espiando para baixo.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} está lutando contra o\nsono...");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} parece estar vagando sem\nrumo.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} está olhando ao redor\ndistraidamente.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} bocejou bem alto!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} está relaxando confortavelmente.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} está te encarando fixamente.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} está olhando atentamente para\no seu rosto.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} está focando a atenção\nem você.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} está encarando a profundeza.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} está farejando o chão.");
static const u8 sPensiveMsg13[] = _("Seu Pokémon está encarando o nada com\natenção.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} focou com um olhar afiado!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} está concentrado.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} virou para cá e assentiu.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} parece um pouco nervoso...");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} está olhando para as suas\npegadas.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} está olhando direto nos seus\nolhos.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} de repente começou a se\naproximar de você!");
static const u8 sLoveMsg01[] = _("As bochechas de {STR_VAR_1} estão\nficando rosadas!");
static const u8 sLoveMsg02[] = _("Uau! {STR_VAR_1} de repente te abraçou!");
static const u8 sLoveMsg03[] = _("Nossa! {STR_VAR_1} de repente quer\nbrincar!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} está se esfregando nas suas\npernas!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} corou de vergonha.");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} se aninhou em você!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} está te olhando com pura\nadmiração!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} se aproximou de você.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} não desgruda dos seus pés.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} está quase caindo!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} esbarrou em você!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} ainda não parece acostumado\ncom o próprio nome.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} está espiando para baixo.");
static const u8 sSurpriseMsg04[] = _("Seu Pokémon tropeçou e quase\ncaiu!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} pressentiu algo e está\nuivando!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} parece revigorado!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} virou-se de repente e começou\na latir!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} virou-se de repente!");
static const u8 sSurpriseMsg09[] = _("Seu Pokémon se assustou quando você\nfalou com ele de surpresa!");
static const u8 sSurpriseMsg10[] = _("Fung, fung... Tem um cheiro muito bom\npor aqui!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} sente-se revigorado.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} está bamboleando e parece\nprestes a cair.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} está em perigo de cair.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} está caminhando com\ncautela.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} está tenso e cheio de\nenergia.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} sentiu algo estranho e levou\num susto!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} ficou com medo e se aninhou\nem você!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} está sentindo uma presença\nincomum...");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} está ficando tenso de tanta\nagitação.");
  // Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} parece surpreso por estar\nchovendo!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Seu Pokémon está procurando algo ao\nredor inquietamente.");
static const u8 sCuriousMsg01[] = _("Seu Pokémon não estava olhando para onde\nia e bateu em você!");
static const u8 sCuriousMsg02[] = _("Fung, fung! Tem alguma coisa por\naqui?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} está rolando uma pedrinha de\nforma divertida.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} está andando por aí em busca\nde algo.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} está te cheirando.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} parece um pouco hesitante...");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} está exibindo a sua\nagilidade!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} está se mexendo\nalegremente!");
static const u8 sMusicMsg02[] = _("Uau! {STR_VAR_1} de repente começou a\ndançar de felicidade!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} está te acompanhando com\nfirmeza!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} parece querer brincar com\nvocê.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} está saltitando alegremente.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} está cantando e cantarolando.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} está mordiscando os seus pés!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} vira-se e olha para você.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} está exibindo com orgulho o seu\ngrande poder!");
static const u8 sMusicMsg10[] = _("Uau! {STR_VAR_1} começou a dançar de\nalegria de repente!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} está super animado!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} está saltando por aí de forma\ndespreocupada!");
static const u8 sMusicMsg13[] = _("Seu Pokémon parece estar sentindo um cheiro\nnostálgico e familiar...");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} está muito feliz com a\nchuva.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} está tremendo com os\nefeitos do envenenamento.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
