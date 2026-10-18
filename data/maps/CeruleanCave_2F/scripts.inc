CeruleanCave_2F_MapScripts::
	.byte 0

CeruleanCave_2F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE, 1
	release
	end

CeruleanCave_2F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL, 1
	release
	end

CeruleanCave_2F_EventScript_ItemPPUp::
	finditem ITEM_PP_UP, 1
	release
	end

CeruleanCave_2F_EventScript_MewtoniteY::
	finditem ITEM_MAX_ELIXIR, 1
	setflag FLAG_GOT_MEWTWONITE_Y
	release
	end

CeruleanCave_2F_EventScript_MewtoniteX::
	finditem ITEM_PP_MAX, 1
	setflag FLAG_GOT_MEWTWONITE_X
	release
	end
