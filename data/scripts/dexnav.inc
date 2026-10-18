EventScript_StartDexNavBattle::
	lockall
	playse 0x15
	callnative StartDexNavBattlePreparation
	dowildbattle    
	releaseall
	end



EventScript_NotFoundNearby::
    msgbox sText_NotFoundNearby, MSGBOX_SIGN
    end

sText_NotFoundNearby:
    .string "Não foi encontrado por perto.\n"
    .string "Tente procurar em outra área!$"


EventScript_MovedTooFast::
    msgbox sText_TryMovingSlower, MSGBOX_SIGN
    end

sText_TryMovingSlower:
    .string "O Pokémon fugiu!\n"
    .string "Tente se mover mais devagar.\p"
    .string "Segure A para andar na ponta\n"
    .string "dos pés com os Tênis de Corrida!$"


EventScript_PokemonGotAway::
    msgbox sText_PokemonGotAway, MSGBOX_SIGN
    end
	
sText_PokemonGotAway:
    .string "O Pokémon fugiu!$"

EventScript_LostSignal::
    msgbox sText_LostSignal, MSGBOX_SIGN
    end

sText_LostSignal:
    .string "Não há nenhuma reação.\n"
    .string "O sinal foi perdido!$"

EventScript_TooDark::
    msgbox sText_TooDark, MSGBOX_SIGN
    end

sText_TooDark:
    .string "Está escuro demais para\n"
	.string "procurar um Pokémon!$"
