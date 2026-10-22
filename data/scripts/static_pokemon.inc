EventScript_ShowStaticIfNatDex::
	goto_if_set VAR_0x8005, EventScript_HideStaticMon
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, FALSE, EventScript_HideStaticMon
	clearflag VAR_0x8004
	return

EventScript_HideStaticMon::
	setflag VAR_0x8004
	return

EventScript_StaticLegendaryTryRemove::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

EventScript_NicknameGiftMon::
	goto_if_eq VAR_RESULT, 0, EventScript_NicknameGiftMonParty
	goto_if_eq VAR_RESULT, 1, EventScript_NicknameGiftMonPC
	return

EventScript_NicknameGiftMonParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message Text_ReceivedGiftMon
	waitmessage
	waitfanfare
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NicknameGiftMonEnd
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto EventScript_NicknameGiftMonEnd

EventScript_NicknameGiftMonPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message Text_ReceivedGiftMon
	waitmessage
	waitfanfare
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NicknameGiftMonSentToPC
	call EventScript_NameReceivedBoxMon
	goto EventScript_NicknameGiftMonSentToPC

EventScript_NicknameGiftMonSentToPC::
	call EventScript_TransferredToPC
	goto EventScript_NicknameGiftMonEnd

EventScript_NicknameGiftMonEnd::
	return

Text_StaticLegendAppeared::
	.string "{STR_VAR_1}!$"

Text_ReceivedGiftMon::
	.string "Received the {STR_VAR_1}!$"

EventScript_RemoveStaticMon::
    fadescreen FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreen FADE_FROM_BLACK
    release
    end

EventScript_MonFlewAway::
    fadescreen FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreen FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway
    release
    end

EventScript_AwakenSnorlax::
    message Text_PlayedPokeFlute
    waitmessage
    playfanfare MUS_POKE_FLUTE
    waitfanfare
    msgbox Text_SnorlaxWokeUp
    return
