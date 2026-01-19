Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_MACHO_BRACE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MELTAN
	givemon SPECIES_MELTAN, 5, ITEM_IRON_BALL
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route111_WinstrateFamilysHouse_EventScript_ReceiveMeltanParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route111_WinstrateFamilysHouse_EventScript_ReceiveMeltanPC
	goto Common_EventScript_NoMoreRoomForPokemon
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceiveMeltanParty::
	call Route111_WinstrateFamilysHouse_EventScript_ReceivedMeltanFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	end

Route111_WinstrateFamilysHouse_EventScript_ReceiveMeltanPC::
	call Route111_WinstrateFamilysHouse_EventScript_ReceivedMeltanFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route111_WinstrateFamilysHouse_EventScript_SendMeltanToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route111_WinstrateFamilysHouse_EventScript_SendMeltanToPC
	end

Route111_WinstrateFamilysHouse_EventScript_SendMeltanToPC::
	call Common_EventScript_TransferredToPC
	goto Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMeltanFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route111_WinstrateFamilysHouse_Text_PlayerReceivedMeltan
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MELTAN
	return

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "You're the first TRAINER I've seen who\n"
	.string "deploys POKéMON so masterfully.\p"
	.string "But, I should tell you--my son is\n"
	.string "stronger than you.\p"
	.string "He even took the POKéMON LEAGUE\n"
	.string "challenge, I'll have you know.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "My son is quite fond of STEEL-TYPE\n"
	.string "POKéMON. He actually found this little\l"
	.string "fella in METEOR FALLS hurt and helpless.\p"
	.string "Since you've beaten all of us here,\n"
	.string "I think you'd make the perfect trainer\l"
	.string "to take care of the little one.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "When it comes to POKéMON battles,\n"
	.string "we tend to be pretty passionate.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mommy is stronger than Daddy.\p"
	.string "I'm stronger than Mommy.\p"
	.string "And Grandma's stronger than me!\p"
	.string "But my big brother is even stronger\n"
	.string "than Grandma.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "There's no question that you're strong.\p"
	.string "But if you were to battle my grandson,\n"
	.string "you'd end up crying in frustration.\p"
	.string "He's much stronger than any TRAINER\n"
	.string "our family knows.\p"
	.string "He must be challenging the POKéMON\n"
	.string "LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "My grandson must be challenging the\n"
	.string "POKéMON LEAGUE CHAMPION by now.\p"
	.string "Knowing my grandson, he could be the\n"
	.string "CHAMPION already!$"

Route111_WinstrateFamilysHouse_Text_PlayerReceivedMeltan:
	.string "{PLAYER} received MELTAN!$"

