static const u8 sCharacteristic00[] = _("Adora comer.");
static const u8 sCharacteristic01[] = _("Orgulhoso de sua força.");
static const u8 sCharacteristic02[] = _("Corpo resistente.");
static const u8 sCharacteristic03[] = _("Gosta de correr.");
static const u8 sCharacteristic04[] = _("Muito curioso.");
static const u8 sCharacteristic05[] = _("Determinado.");
static const u8 sCharacteristic06[] = _("Cochila com frequência.");
static const u8 sCharacteristic07[] = _("Gosta de se agitar.");
static const u8 sCharacteristic08[] = _("Aguenta muitos golpes.");
static const u8 sCharacteristic09[] = _("Atento a sons.");
static const u8 sCharacteristic10[] = _("Travesso.");
static const u8 sCharacteristic11[] = _("Um pouco vaidoso.");
static const u8 sCharacteristic12[] = _("Adormece fácil.");
static const u8 sCharacteristic13[] = _("Pavio um pouco curto.");
static const u8 sCharacteristic14[] = _("Muito persistente.");
static const u8 sCharacteristic15[] = _("Impulsivo e bobo.");
static const u8 sCharacteristic16[] = _("Totalmente astuto.");
static const u8 sCharacteristic17[] = _("Muito desafiador.");
static const u8 sCharacteristic18[] = _("Espalha coisas sempre.");
static const u8 sCharacteristic19[] = _("Gosta de lutar.");
static const u8 sCharacteristic20[] = _("Boa resistência.");
static const u8 sCharacteristic21[] = _("Meio palhaço.");
static const u8 sCharacteristic22[] = _("Vive pensativo.");
static const u8 sCharacteristic23[] = _("Odeia perder.");
static const u8 sCharacteristic24[] = _("Gosta de relaxar.");
static const u8 sCharacteristic25[] = _("Pavio curto.");
static const u8 sCharacteristic26[] = _("Muita perseverança.");
static const u8 sCharacteristic27[] = _("Rápido para fugir.");
static const u8 sCharacteristic28[] = _("Muito exigente.");
static const u8 sCharacteristic29[] = _("Meio teimoso.");

static const u8 sFlavorSpicy[] = _("Gosta de comida {COLOR 5}{SHADOW 6}apimentada{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorDry[] = _("Gosta de comida {COLOR 5}{SHADOW 6}seca{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorSweet[] = _("Gosta de comida {COLOR 5}{SHADOW 6}doce{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorBitter[] = _("Gosta de comida {COLOR 5}{SHADOW 6}amarga{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorSour[] = _("Gosta de comida {COLOR 5}{SHADOW 6}azeda{COLOR 7}{SHADOW 8}.");
static const u8 sFlavorNeutral[] = _("Come qualquer coisa feliz.");

const u8 *const gCharacteristicPointers[30] = 
{
    sCharacteristic00,
	sCharacteristic01,
    sCharacteristic02,
	sCharacteristic03,
    sCharacteristic04,
	sCharacteristic05,
    sCharacteristic06,
	sCharacteristic07,
    sCharacteristic08,
	sCharacteristic09,
    sCharacteristic10,
	sCharacteristic11,
    sCharacteristic12,
	sCharacteristic13,
    sCharacteristic14,
	sCharacteristic15,
    sCharacteristic16,
	sCharacteristic17,
    sCharacteristic18,
	sCharacteristic19,
    sCharacteristic20,
	sCharacteristic21,
    sCharacteristic22,
	sCharacteristic23,
    sCharacteristic24,
	sCharacteristic25,
    sCharacteristic26,
	sCharacteristic27,
    sCharacteristic28,
	sCharacteristic29,
};

const u8 *const gNatureFlavorPointers[25] =
{
	[NATURE_HARDY]   = sFlavorNeutral,
	[NATURE_LONELY]  = sFlavorSpicy,
	[NATURE_BRAVE]   = sFlavorSpicy,
	[NATURE_ADAMANT] = sFlavorSpicy,
	[NATURE_NAUGHTY] = sFlavorSpicy,
	[NATURE_BOLD]    = sFlavorSour,
	[NATURE_DOCILE]  = sFlavorNeutral,
	[NATURE_RELAXED] = sFlavorSour,
	[NATURE_IMPISH]  = sFlavorSour,
	[NATURE_LAX]     = sFlavorSour,
	[NATURE_TIMID]   = sFlavorSweet,
	[NATURE_HASTY]   = sFlavorSweet,
	[NATURE_SERIOUS] = sFlavorNeutral,
	[NATURE_JOLLY]   = sFlavorSweet,
	[NATURE_NAIVE]   = sFlavorSweet,
	[NATURE_MODEST]  = sFlavorDry,
	[NATURE_MILD]    = sFlavorDry,
	[NATURE_QUIET]   = sFlavorDry,
	[NATURE_BASHFUL] = sFlavorNeutral,
	[NATURE_RASH]    = sFlavorDry,
	[NATURE_CALM]    = sFlavorBitter,
	[NATURE_GENTLE]  = sFlavorBitter,
	[NATURE_SASSY]   = sFlavorBitter,
	[NATURE_CAREFUL] = sFlavorBitter,
	[NATURE_QUIRKY]  = sFlavorNeutral,
};
