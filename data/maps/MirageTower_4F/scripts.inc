# 1 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_MapScripts::
# 2 "data/maps/MirageTower_4F/scripts.pory"
	.byte 0
# 3 "data/maps/MirageTower_4F/scripts.pory"

# 4 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_RootFossil::
# 5 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 6 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 7 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
# 8 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
# 9 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 10 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 11 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 12 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 13 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 14 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_MIRAGE_ROOT_FOSSIL
# 15 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 16 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_ROOT_FOSSIL
# 17 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 18 "data/maps/MirageTower_4F/scripts.pory"
	end
# 19 "data/maps/MirageTower_4F/scripts.pory"

# 20 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveRootFossil::
# 21 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
# 22 "data/maps/MirageTower_4F/scripts.pory"
	release
# 23 "data/maps/MirageTower_4F/scripts.pory"
	end
# 24 "data/maps/MirageTower_4F/scripts.pory"

# 25 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_ClawFossil::
# 26 "data/maps/MirageTower_4F/scripts.pory"
	lock
# 27 "data/maps/MirageTower_4F/scripts.pory"
	faceplayer
# 28 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
# 29 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
# 30 "data/maps/MirageTower_4F/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 31 "data/maps/MirageTower_4F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 32 "data/maps/MirageTower_4F/scripts.pory"
	closemessage
# 33 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 34 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 35 "data/maps/MirageTower_4F/scripts.pory"
	removeobject LOCALID_MIRAGE_CLAW_FOSSIL
# 36 "data/maps/MirageTower_4F/scripts.pory"
	delay 30
# 37 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_CLAW_FOSSIL
# 38 "data/maps/MirageTower_4F/scripts.pory"
	goto MirageTower_4F_EventScript_CollapseMirageTower
# 39 "data/maps/MirageTower_4F/scripts.pory"
	end
# 40 "data/maps/MirageTower_4F/scripts.pory"

# 41 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_LeaveClawFossil::
# 42 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
# 43 "data/maps/MirageTower_4F/scripts.pory"
	release
# 44 "data/maps/MirageTower_4F/scripts.pory"
	end
# 45 "data/maps/MirageTower_4F/scripts.pory"

# 46 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_EventScript_CollapseMirageTower::
# 47 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 48 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 49 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8006, 32  @ num shakes
# 50 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8007, 2   @ shake delay
# 51 "data/maps/MirageTower_4F/scripts.pory"
	special ShakeCamera
# 52 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 53 "data/maps/MirageTower_4F/scripts.pory"
	special DoMirageTowerCeilingCrumble
# 54 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 55 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 1
# 56 "data/maps/MirageTower_4F/scripts.pory"
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
# 57 "data/maps/MirageTower_4F/scripts.pory"
	warp MAP_ROUTE111, 19, 59
# 58 "data/maps/MirageTower_4F/scripts.pory"
	waitstate
# 59 "data/maps/MirageTower_4F/scripts.pory"
	release
# 60 "data/maps/MirageTower_4F/scripts.pory"
	end
# 61 "data/maps/MirageTower_4F/scripts.pory"

# 62 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeRootFossil:
# 63 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the ROOT FOSSIL.\p"
# 64 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 65 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 66 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the ROOT FOSSIL anyway?$"
# 67 "data/maps/MirageTower_4F/scripts.pory"

# 68 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeftRootFossilAlone:
# 69 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the ROOT FOSSIL alone.$"
# 70 "data/maps/MirageTower_4F/scripts.pory"

# 71 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_TakeClawFossil:
# 72 "data/maps/MirageTower_4F/scripts.pory"
	.string "You found the CLAW FOSSIL.\p"
# 73 "data/maps/MirageTower_4F/scripts.pory"
	.string "If this FOSSIL is taken, the ground\n"
# 74 "data/maps/MirageTower_4F/scripts.pory"
	.string "around it will likely crumble away…\p"
# 75 "data/maps/MirageTower_4F/scripts.pory"
	.string "Take the CLAW FOSSIL anyway?$"
# 76 "data/maps/MirageTower_4F/scripts.pory"

# 77 "data/maps/MirageTower_4F/scripts.pory"
MirageTower_4F_Text_LeaveClawFossilAlone:
# 78 "data/maps/MirageTower_4F/scripts.pory"
	.string "{PLAYER} left the CLAW FOSSIL alone.$"

MirageTower_4F_EventScript_ParadoxPast::
# 83 "data/maps/MirageTower_4F/scripts.pory"
	lockall
# 84 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_EventScript_ParadoxPast_Text_0, MSGBOX_YESNO
# 85 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MirageTower_4F_EventScript_ParadoxPast_2
MirageTower_4F_EventScript_ParadoxPast_1:
# 126 "data/maps/MirageTower_4F/scripts.pory"
	releaseall
	end

MirageTower_4F_EventScript_ParadoxPast_2:
# 87 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
# 88 "data/maps/MirageTower_4F/scripts.pory"
	removeobject 4
# 89 "data/maps/MirageTower_4F/scripts.pory"
	playse SE_CLICK
# 90 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_EventScript_ParadoxPast_Text_1, MSGBOX_DEFAULT
# 91 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8004, 0
# 92 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8005, 2
# 93 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8006, 50
# 94 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8007, 2
# 95 "data/maps/MirageTower_4F/scripts.pory"
	special ShakeCamera
# 96 "data/maps/MirageTower_4F/scripts.pory"
	delay 60
# 97 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_EventScript_ParadoxPast_Text_2, MSGBOX_DEFAULT
# 98 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_SMART_WILDS
# 99 "data/maps/MirageTower_4F/scripts.pory"
	randomelement 1, 2, 3, 4, 5, 6
# 100 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MirageTower_4F_EventScript_ParadoxPast_6
# 103 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq MirageTower_4F_EventScript_ParadoxPast_7
# 106 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq MirageTower_4F_EventScript_ParadoxPast_8
# 109 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq MirageTower_4F_EventScript_ParadoxPast_9
# 112 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq MirageTower_4F_EventScript_ParadoxPast_10
# 116 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_SANDY_SHOCKS, 50
MirageTower_4F_EventScript_ParadoxPast_5:
# 118 "data/maps/MirageTower_4F/scripts.pory"
	dowildbattle
# 119 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_ROOT_FOSSIL
# 120 "data/maps/MirageTower_4F/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 121 "data/maps/MirageTower_4F/scripts.pory"
	call MirageTower_4F_EventScript_CollapseMirageTower
	goto MirageTower_4F_EventScript_ParadoxPast_1

MirageTower_4F_EventScript_ParadoxPast_6:
# 101 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_GREAT_TUSK, 50
	goto MirageTower_4F_EventScript_ParadoxPast_5

MirageTower_4F_EventScript_ParadoxPast_7:
# 104 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_SCREAM_TAIL, 50
	goto MirageTower_4F_EventScript_ParadoxPast_5

MirageTower_4F_EventScript_ParadoxPast_8:
# 107 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_BRUTE_BONNET, 50
	goto MirageTower_4F_EventScript_ParadoxPast_5

MirageTower_4F_EventScript_ParadoxPast_9:
# 110 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_FLUTTER_MANE, 50
	goto MirageTower_4F_EventScript_ParadoxPast_5

MirageTower_4F_EventScript_ParadoxPast_10:
# 113 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_SLITHER_WING, 50
	goto MirageTower_4F_EventScript_ParadoxPast_5


MirageTower_4F_EventScript_ParadoxFuture::
# 131 "data/maps/MirageTower_4F/scripts.pory"
	lockall
# 132 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_EventScript_ParadoxFuture_Text_0, MSGBOX_YESNO
# 133 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MirageTower_4F_EventScript_ParadoxFuture_2
MirageTower_4F_EventScript_ParadoxFuture_1:
# 174 "data/maps/MirageTower_4F/scripts.pory"
	releaseall
	end

MirageTower_4F_EventScript_ParadoxFuture_2:
# 135 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
# 136 "data/maps/MirageTower_4F/scripts.pory"
	removeobject 5
# 137 "data/maps/MirageTower_4F/scripts.pory"
	playse SE_CLICK
# 138 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_EventScript_ParadoxPast_Text_1, MSGBOX_DEFAULT
# 139 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8004, 0
# 140 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8005, 2
# 141 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8006, 50
# 142 "data/maps/MirageTower_4F/scripts.pory"
	setvar VAR_0x8007, 2
# 143 "data/maps/MirageTower_4F/scripts.pory"
	special ShakeCamera
# 144 "data/maps/MirageTower_4F/scripts.pory"
	delay 60
# 145 "data/maps/MirageTower_4F/scripts.pory"
	msgbox MirageTower_4F_EventScript_ParadoxPast_Text_2, MSGBOX_DEFAULT
# 146 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_SMART_WILDS
# 147 "data/maps/MirageTower_4F/scripts.pory"
	randomelement 1, 2, 3, 4, 5, 6
# 148 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MirageTower_4F_EventScript_ParadoxFuture_6
# 151 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq MirageTower_4F_EventScript_ParadoxFuture_7
# 154 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq MirageTower_4F_EventScript_ParadoxFuture_8
# 157 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq MirageTower_4F_EventScript_ParadoxFuture_9
# 160 "data/maps/MirageTower_4F/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq MirageTower_4F_EventScript_ParadoxFuture_10
# 164 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_IRON_THORNS, 50
MirageTower_4F_EventScript_ParadoxFuture_5:
# 166 "data/maps/MirageTower_4F/scripts.pory"
	dowildbattle
# 167 "data/maps/MirageTower_4F/scripts.pory"
	setflag FLAG_CHOSE_CLAW_FOSSIL
# 168 "data/maps/MirageTower_4F/scripts.pory"
	clearflag FLAG_SMART_WILDS
# 169 "data/maps/MirageTower_4F/scripts.pory"
	call MirageTower_4F_EventScript_CollapseMirageTower
	goto MirageTower_4F_EventScript_ParadoxFuture_1

MirageTower_4F_EventScript_ParadoxFuture_6:
# 149 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_IRON_TREADS, 50
	goto MirageTower_4F_EventScript_ParadoxFuture_5

MirageTower_4F_EventScript_ParadoxFuture_7:
# 152 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_IRON_BUNDLE, 50
	goto MirageTower_4F_EventScript_ParadoxFuture_5

MirageTower_4F_EventScript_ParadoxFuture_8:
# 155 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_IRON_HANDS, 50
	goto MirageTower_4F_EventScript_ParadoxFuture_5

MirageTower_4F_EventScript_ParadoxFuture_9:
# 158 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_IRON_JUGULIS, 50
	goto MirageTower_4F_EventScript_ParadoxFuture_5

MirageTower_4F_EventScript_ParadoxFuture_10:
# 161 "data/maps/MirageTower_4F/scripts.pory"
	setwildbattle SPECIES_IRON_MOTH, 50
	goto MirageTower_4F_EventScript_ParadoxFuture_5


MirageTower_4F_EventScript_ParadoxPast_Text_0:
# 84 "data/maps/MirageTower_4F/scripts.pory"
	.string "A scarlet rock sits atop the sand.\nThere's something off about it...\pMove the rock?$"

MirageTower_4F_EventScript_ParadoxPast_Text_1:
# 90 "data/maps/MirageTower_4F/scripts.pory"
	.string "You push the rock aside.$"

MirageTower_4F_EventScript_ParadoxPast_Text_2:
# 97 "data/maps/MirageTower_4F/scripts.pory"
	.string "The floor trembles and the sand\nshifts!\pA creature lunges out from beneath\nthe sand!$"

MirageTower_4F_EventScript_ParadoxFuture_Text_0:
# 132 "data/maps/MirageTower_4F/scripts.pory"
	.string "A violet rock sits atop the sand.\nThere's something off about it...\pMove the rock?$"
