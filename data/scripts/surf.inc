EventScript_UseSurf::
	goto_if_set FLAG_BADGE05_GET, EventScript_HasSurfBadge
	goto_if_set FLAG_DEFEATED_LEADER_MORTY, EventScript_HasSurfBadge
	goto EventScript_ScarySeas

EventScript_HasSurfBadge::
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

EventScript_ScarySeas::
	msgbox EventScript_ScarySeasText, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

EventScript_ScarySeasText:
	.string "A água à sua frente parece convidativa.\p"
	.string "Talvez você possa surfar no futuro.$"

