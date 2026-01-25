# 1 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_MapScripts::
# 2 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.byte 0
# 3 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 4 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
# 5 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 6 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
# 7 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitmovement 0
# 8 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 9 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
# 10 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_TEMP_1
# 11 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 12 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 13 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 14 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
# 15 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 16 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 17 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
# 18 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 19 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 20 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 21 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 22 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 23 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
# 24 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
# 25 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ChooseMonForMoveRelearner
# 26 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 27 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 28 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special IsSelectedMonEgg
# 29 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
# 30 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
# 31 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
# 32 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 33 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 34 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
# 35 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
# 36 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special TeachMoveRelearnerMove
# 37 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 38 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 39 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
# 40 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	removeitem ITEM_HEART_SCALE
# 41 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 42 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 43 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 44 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
# 45 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
# 46 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 47 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 48 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 49 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
# 50 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
# 51 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 52 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 53 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 54 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
# 55 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
# 56 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 57 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 58 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 59 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
# 60 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm the MOVE TUTOR.\p"
# 61 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I know all the moves that POKéMON\n"
# 62 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "learn--every one of them--and I can\l"
# 63 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "teach POKéMON those moves.\p"
# 64 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach a move to a POKéMON\n"
# 65 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "of yours if you'd like.\p"
# 66 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'll do it for a HEART SCALE.\n"
# 67 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm collecting those now.$"
# 68 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 69 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
# 70 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh! That's it! That's an honest to\n"
# 71 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "goodness HEART SCALE!\p"
# 72 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Let me guess, you want me to teach\n"
# 73 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "a move?$"
# 74 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 75 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
# 76 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which POKéMON needs tutoring?$"
# 77 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 78 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
# 79 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which move should I teach?$"
# 80 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 81 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
# 82 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Sorry…\p"
# 83 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It doesn't appear as if I have any move\n"
# 84 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach that POKéMON.$"
# 85 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 86 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
# 87 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
# 88 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "in exchange.$"
# 89 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 90 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
# 91 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If your POKéMON need to learn a move,\n"
# 92 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "come back with a HEART SCALE.$"
# 93 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 94 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
# 95 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hunh? There isn't a single move that\n"
# 96 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach an EGG.$"

FallarborTown_AnabelsHouse_EventScript_Anabel::
# 101 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 102 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	faceplayer
# 103 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANABEL_1, FallarborTown_AnabelsHouse_EventScript_Anabel_3
FallarborTown_AnabelsHouse_EventScript_Anabel_1:
# 106 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANABEL_2, FallarborTown_AnabelsHouse_EventScript_Anabel_7
FallarborTown_AnabelsHouse_EventScript_Anabel_6:
# 116 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_UNLOCKED_ANABEL_2, FallarborTown_AnabelsHouse_EventScript_Anabel_10
# 129 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_5
# 130 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_ZINNIA_EVENTS > 1, 0
	goto_if_ne FallarborTown_AnabelsHouse_EventScript_Anabel_19
# 144 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_11, MSGBOX_DEFAULT
FallarborTown_AnabelsHouse_EventScript_Anabel_9:
# 147 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	return

FallarborTown_AnabelsHouse_EventScript_Anabel_2:
# 104 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_1

FallarborTown_AnabelsHouse_EventScript_Anabel_3:
# 103 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ANABEL_2, FallarborTown_AnabelsHouse_EventScript_Anabel_2
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_1

FallarborTown_AnabelsHouse_EventScript_Anabel_7:
# 107 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_0
# 108 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	multichoicedefault 0, 0, MULTI_ANABEL_COLLECTIONS, 0, 0
# 109 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_Anabel_14
FallarborTown_AnabelsHouse_EventScript_Anabel_13:
# 112 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_Anabel_22
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_6

FallarborTown_AnabelsHouse_EventScript_Anabel_10:
# 117 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_1, MSGBOX_YESNO
# 118 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_Anabel_17
FallarborTown_AnabelsHouse_EventScript_Anabel_16:
# 124 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_Anabel_24
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_9

FallarborTown_AnabelsHouse_EventScript_Anabel_14:
# 110 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_13

FallarborTown_AnabelsHouse_EventScript_Anabel_17:
# 119 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_2
# 120 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	trainerbattle_no_intro TRAINER_ANABEL_FALLARBOR_2, Anabel_PostBattle2
# 121 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_3
# 122 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_DEFEATED_ANABEL_2
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_16

FallarborTown_AnabelsHouse_EventScript_Anabel_19:
# 131 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_6, MSGBOX_YESNO
# 132 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_Anabel_27
FallarborTown_AnabelsHouse_EventScript_Anabel_26:
# 139 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_Anabel_29
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_9

FallarborTown_AnabelsHouse_EventScript_Anabel_22:
# 113 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_GMegaBattles
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_6

FallarborTown_AnabelsHouse_EventScript_Anabel_24:
# 125 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_4
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_9

FallarborTown_AnabelsHouse_EventScript_Anabel_27:
# 133 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_7
# 134 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	trainerbattle_no_intro TRAINER_ANABEL_FALLARBOR_1, Anabel_PostBattle
# 135 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_8, MSGBOX_DEFAULT
# 136 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_DEFEATED_ANABEL_1
# 137 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_9, MSGBOX_DEFAULT
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_26

FallarborTown_AnabelsHouse_EventScript_Anabel_29:
# 140 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_Anabel_Text_10
	goto FallarborTown_AnabelsHouse_EventScript_Anabel_9


	.align 2
# 158 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
Anabel_MegaStones:
# 159 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_VENUSAURITE
# 160 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 161 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 162 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_BLASTOISINITE
# 163 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_BEEDRILLITE
# 164 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_PIDGEOTITE
# 165 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 166 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SLOWBRONITE
# 167 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GENGARITE
# 168 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_KANGASKHANITE
# 169 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_PINSIRITE
# 170 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GYARADOSITE
# 171 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_AERODACTYLITE
# 172 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_AMPHAROSITE
# 173 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_STEELIXITE
# 174 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SCIZORITE
# 175 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_HERACRONITE
# 176 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 177 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 178 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SCEPTILITE
# 179 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_BLAZIKENITE
# 180 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SWAMPERTITE
# 181 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GARDEVOIRITE
# 182 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SABLENITE
# 183 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_MAWILITE
# 184 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_AGGRONITE
# 185 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_MEDICHAMITE
# 186 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_MANECTITE
# 187 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SHARPEDONITE
# 188 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CAMERUPTITE
# 189 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ALTARIANITE
# 190 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_BANETTITE
# 191 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ABSOLITE
# 192 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GLALITITE
# 193 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SALAMENCITE
# 194 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_METAGROSSITE
# 195 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_LOPUNNITE
# 196 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GARCHOMPITE
# 197 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 198 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ABOMASITE
# 199 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GALLADITE
# 200 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_AUDINITE
	.2byte ITEM_NONE

	.align 2
# 203 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
Anabel_GMaxStones:
# 204 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CORVIKNITE_G
# 205 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ORBEETLITE_G
# 206 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_DREDNAWITE_G
# 207 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_COALOSSALITE_G
# 208 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_APPLETITE_G
# 209 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SANDACONDITE_G
# 210 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_TOXTRICITITE_G
# 211 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CENTISKORCHITE_G
# 212 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_HATTERENITE_G
# 213 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GRIMMSNARLITE_G
# 214 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ALCREMITE_G
# 215 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_COPPERAJITE_G
# 216 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_ARCHALUDONITE_G
# 217 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_VENUSAURITE_G
# 218 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_CHARIZARDITE_G
# 219 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_BLASTOISINITE_G
# 220 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_BUTTERFREENITE_G
# 221 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_PIKACHUITE_G
# 222 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_MEOWTHITE_G
# 223 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_MACHAMPITE_G
# 224 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GENGARITE_G
# 225 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_KINGLERITE_G
# 226 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_LAPRASITE_G
# 227 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_EEVEENITE_G
# 228 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_SNORLAXITE_G
# 229 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.2byte ITEM_GARBODORITE_G
	.2byte ITEM_NONE

FallarborTown_AnabelsHouse_EventScript_MegaBattles::
# 238 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_0, MSGBOX_DEFAULT
# 239 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8009, 0
# 240 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_ANABEL_MEGAS
# 241 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special ShowScrollableMultichoice
# 242 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 243 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_2
# 265 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_5
# 287 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_11
# 309 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_17
# 331 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_23
# 353 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_29
# 375 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_35
# 397 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_40
# 420 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_2:
# 244 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_VENUSAUR, OPEN_PARTY_SCREEN
# 245 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_7
# 252 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 253 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 254 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 255 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_VENUSAUR_MEGA, 50
# 256 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 257 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 258 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 259 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 260 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_VENUSAURITE
# 261 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_5:
# 266 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_CHARIZARD, OPEN_PARTY_SCREEN
# 267 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_13
# 274 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 275 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 276 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 277 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_CHARIZARD_MEGA_X, 50
# 278 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 279 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 280 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 281 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 282 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_CHARIZARDITE_X
# 283 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_7:
# 246 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_1, MSGBOX_DEFAULT
# 247 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 248 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_11:
# 288 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_CHARIZARD, OPEN_PARTY_SCREEN
# 289 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_19
# 296 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 297 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 298 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 299 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_CHARIZARD_MEGA_Y, 50
# 300 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 301 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 302 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 303 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 304 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_CHARIZARDITE_Y
# 305 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_13:
# 268 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_3, MSGBOX_DEFAULT
# 269 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 270 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_17:
# 310 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_BLASTOISE, OPEN_PARTY_SCREEN
# 311 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_25
# 318 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 319 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 320 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 321 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_BLASTOISE_MEGA, 50
# 322 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 323 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 324 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 325 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 326 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_BLASTOISINITE
# 327 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_19:
# 290 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_3, MSGBOX_DEFAULT
# 291 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 292 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_23:
# 332 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_BEEDRILL, OPEN_PARTY_SCREEN
# 333 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_31
# 340 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 341 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 342 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 343 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_BEEDRILL_MEGA, 50
# 344 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 345 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 346 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 347 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 348 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_BEEDRILLITE
# 349 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_25:
# 312 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_4, MSGBOX_DEFAULT
# 313 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 314 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_29:
# 354 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_PIDGEOT, OPEN_PARTY_SCREEN
# 355 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_37
# 362 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 363 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 364 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 365 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_PIDGEOT_MEGA, 50
# 366 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 367 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 368 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 369 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 370 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_PIDGEOTITE
# 371 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_31:
# 334 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_5, MSGBOX_DEFAULT
# 335 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 336 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_35:
# 376 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_ALAKAZAM, OPEN_PARTY_SCREEN
# 377 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_43
# 384 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 385 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 386 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 387 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_ALAKAZAM_MEGA, 50
# 388 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 389 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 390 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 391 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 392 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_ALAKAZITE
# 393 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_37:
# 356 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_6, MSGBOX_DEFAULT
# 357 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 358 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_40:
# 398 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkspecies SPECIES_SLOWBRO, OPEN_PARTY_SCREEN
# 399 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_AnabelsHouse_EventScript_MegaBattles_46
# 406 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_CATCHING_DISABLED
# 407 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_RUNNING_DISABLED
# 408 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_SMART_WILDS
# 409 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setwildbattle SPECIES_SLOWBRO_MEGA, 50
# 410 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dowildbattle
# 411 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_CATCHING_DISABLED
# 412 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 413 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2, MSGBOX_DEFAULT
# 414 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	giveitem ITEM_SLOWBRONITE
# 415 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_43:
# 378 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_7, MSGBOX_DEFAULT
# 379 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 380 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end

FallarborTown_AnabelsHouse_EventScript_MegaBattles_46:
# 400 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_8, MSGBOX_DEFAULT
# 401 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_AnabelsHouse_EventScript_MegaBattles
# 402 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
	end


FallarborTown_AnabelsHouse_EventScript_GMegaBattles::
	return


FallarborTown_AnabelsHouse_EventScript_Anabel_Text_0:
# 107 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hi, {PLAYER}! Which collection would\n"
	.string "you like to see?$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_1:
# 117 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: Greetings, {PLAYER}, I'm glad\nyou came.\pIt's been a while since our battle and\n I can tell you've gotten stronger.\pI'll fight you with a bit more\nfirepower this time, and if you beat\nme, I promise I'll make it worth your\nwhile.\pSo, what do you say?$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_2:
# 119 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Fufufu... Well, let's begin, shall we?$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_3:
# 121 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: Fufu, as expected, you\n"
	.string "did not disappoint.\p"
	.string "Perhaps in our next battle I can\n"
	.string "finally go all out...\p"
	.string "Well, I promised you a reward\n"
	.string "didn't I?\p"
	.string "By now I trust you enough to give\n"
	.string "you access to my 'expanded' collection\n"
	.string "of MEGA STONES.\p"
	.string "One could even call this a\n"
	.string "Gigantic opportunity for you.\p"
	.string "Come see me when you want to take\n"
	.string "your POKéMON even further.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_4:
# 125 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I see... very disappointing.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_5:
# 129 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hm? Who might you be?$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_6:
# 131 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hold on, is that a MEGA RING?\pHm, how peculiar, you don't look\nfamiliar.\p...My name is ANABEL. I'd like to\nbattle you, if you're up for it.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_7:
# 133 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Fufufu... Well, then...\pShow me what you're made of.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_8:
# 135 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: It's been a while since\nsomeone has defeated me.\pMaybe one day you'll be strong enough\nto take me on at my full power...\pBut thank you for the match. Tell\nyou what, your MEGA RING looks\lawfully dormant.\pYou don't have any MEGA STONES,\ndo you?\pSince you beat me, I'll do you\na favor.\pIf you can beat my mega\nevolved POKéMON, I'll give you\ltheir MEGA STONES.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_9:
# 137 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Come see me when you want to draw\nout your POKéMON's full potential.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_10:
# 140 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "How disappointing.$"

FallarborTown_AnabelsHouse_EventScript_Anabel_Text_11:
# 144 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If you have no business with me I'd\nlike you to leave.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_0:
# 238 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: So, which MEGA STONE are you\ninterested in?$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_1:
# 246 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "VENUSAUR with one of your own.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_2:
# 259 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: Well done, you've earned\n"
	.string "this.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_3:
# 268 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "CHARIZARD with one of your own.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_4:
# 312 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "BLASTOISE with one of your own.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_5:
# 334 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "BEEDRILL with one of your own.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_6:
# 356 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "PIDGEOT with one of your own.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_7:
# 378 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "ALAKAZAM with one of your own.$"

FallarborTown_AnabelsHouse_EventScript_MegaBattles_Text_8:
# 400 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: I'd like you to defeat my\n"
	.string "SLOWBRO with one of your own.$"

Anabel_PostBattle::
# 150 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: Fufu... I like you.$"

Anabel_PostBattle2::
# 154 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "ANABEL: Maybe... Just maybe...$"
