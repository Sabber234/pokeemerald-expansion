# 1 "data/maps/DesertRuins/scripts.pory"
DesertRuins_MapScripts::
# 2 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_OnResume
# 3 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_OnLoad
# 4 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
# 5 "data/maps/DesertRuins/scripts.pory"
	.byte 0
# 6 "data/maps/DesertRuins/scripts.pory"

# 7 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnResume:
# 8 "data/maps/DesertRuins/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_TryRemoveRegirock
# 9 "data/maps/DesertRuins/scripts.pory"
	end
# 10 "data/maps/DesertRuins/scripts.pory"

# 11 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_TryRemoveRegirock::
# 12 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/DesertRuins/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 14 "data/maps/DesertRuins/scripts.pory"
	removeobject VAR_LAST_TALKED
# 15 "data/maps/DesertRuins/scripts.pory"
	return
# 16 "data/maps/DesertRuins/scripts.pory"

# 17 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnLoad:
# 18 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
# 19 "data/maps/DesertRuins/scripts.pory"
	end
# 20 "data/maps/DesertRuins/scripts.pory"

# 21 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_HideRegiEntrance::
# 22 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
# 23 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
# 24 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
# 25 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 26 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 27 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
# 28 "data/maps/DesertRuins/scripts.pory"
	return
# 29 "data/maps/DesertRuins/scripts.pory"

# 30 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnTransition:
# 31 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_RUINS
# 32 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_ShowRegirock
# 33 "data/maps/DesertRuins/scripts.pory"
	end
# 34 "data/maps/DesertRuins/scripts.pory"

# 35 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_ShowRegirock::
# 36 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_HIDE_REGIROCK
# 37 "data/maps/DesertRuins/scripts.pory"
	return
# 38 "data/maps/DesertRuins/scripts.pory"

# 39 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceMiddle::
# 40 "data/maps/DesertRuins/scripts.pory"
	lockall
# 41 "data/maps/DesertRuins/scripts.pory"
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
# 42 "data/maps/DesertRuins/scripts.pory"
	braillemsgbox DesertRuins_Braille_UseRockSmash
# 43 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 44 "data/maps/DesertRuins/scripts.pory"
	end
# 45 "data/maps/DesertRuins/scripts.pory"

# 46 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_BigHoleInWall::
# 47 "data/maps/DesertRuins/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 48 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 49 "data/maps/DesertRuins/scripts.pory"
	end
# 50 "data/maps/DesertRuins/scripts.pory"

# 51 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceSide::
# 52 "data/maps/DesertRuins/scripts.pory"
	lockall
# 53 "data/maps/DesertRuins/scripts.pory"
	braillemsgbox DesertRuins_Braille_UseRockSmash
# 54 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 55 "data/maps/DesertRuins/scripts.pory"
	end
# 56 "data/maps/DesertRuins/scripts.pory"

# 57 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_Regirock::
# 58 "data/maps/DesertRuins/scripts.pory"
	lock
# 59 "data/maps/DesertRuins/scripts.pory"
	faceplayer
# 60 "data/maps/DesertRuins/scripts.pory"
	waitse
# 61 "data/maps/DesertRuins/scripts.pory"
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
# 62 "data/maps/DesertRuins/scripts.pory"
	delay 40
# 63 "data/maps/DesertRuins/scripts.pory"
	waitmoncry
# 64 "data/maps/DesertRuins/scripts.pory"
	setwildbattle SPECIES_REGIROCK, 40
# 65 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 66 "data/maps/DesertRuins/scripts.pory"
	special StartRegiBattle
# 67 "data/maps/DesertRuins/scripts.pory"
	waitstate
# 68 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 69 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 70 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DesertRuins_EventScript_DefeatedRegirock
# 71 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DesertRuins_EventScript_RanFromRegirock
# 72 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DesertRuins_EventScript_RanFromRegirock
# 73 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 74 "data/maps/DesertRuins/scripts.pory"
	release
# 75 "data/maps/DesertRuins/scripts.pory"
	end
# 76 "data/maps/DesertRuins/scripts.pory"

# 77 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_DefeatedRegirock::
# 78 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 79 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 80 "data/maps/DesertRuins/scripts.pory"
	end
# 81 "data/maps/DesertRuins/scripts.pory"

# 82 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_RanFromRegirock::
# 83 "data/maps/DesertRuins/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIROCK
# 84 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 85 "data/maps/DesertRuins/scripts.pory"
	end

DesertRuins_EventScript_ZinniaBattle::
# 89 "data/maps/DesertRuins/scripts.pory"
	lockall
# 90 "data/maps/DesertRuins/scripts.pory"
	faceplayer
# 91 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaBattle_Text_0, MSGBOX_YESNO
# 92 "data/maps/DesertRuins/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DesertRuins_EventScript_ZinniaBattle_2
# 119 "data/maps/DesertRuins/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DesertRuins_EventScript_ZinniaBattle_3
DesertRuins_EventScript_ZinniaBattle_1:
# 122 "data/maps/DesertRuins/scripts.pory"
	releaseall
	end

DesertRuins_EventScript_ZinniaBattle_2:
# 93 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaBattle_Text_1, MSGBOX_DEFAULT
# 94 "data/maps/DesertRuins/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 95 "data/maps/DesertRuins/scripts.pory"
	waitmoncry
# 96 "data/maps/DesertRuins/scripts.pory"
	trainerbattle_no_intro TRAINER_ZINNIA_DESERTRUINS, ZinniaDesertRuinsPostBattle
# 97 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaBattle_Text_2
# 98 "data/maps/DesertRuins/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 99 "data/maps/DesertRuins/scripts.pory"
	applymovement 3, DesertRuins_Movement_WhismurBounce
# 100 "data/maps/DesertRuins/scripts.pory"
	waitmoncry
# 101 "data/maps/DesertRuins/scripts.pory"
	waitmovement
# 102 "data/maps/DesertRuins/scripts.pory"
	applymovement 2, DesertRuins_Movement_TurnRight
# 103 "data/maps/DesertRuins/scripts.pory"
	waitmovement
# 104 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaBattle_Text_3, MSGBOX_DEFAULT
# 105 "data/maps/DesertRuins/scripts.pory"
	faceplayer
# 106 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaBattle_Text_4, MSGBOX_DEFAULT
# 107 "data/maps/DesertRuins/scripts.pory"
	applymovement 2, DesertRuins_Movement_ZinniaLeave
# 108 "data/maps/DesertRuins/scripts.pory"
	applymovement 3, DesertRuins_Movement_WhismurLeave
# 109 "data/maps/DesertRuins/scripts.pory"
	waitmovement
# 110 "data/maps/DesertRuins/scripts.pory"
	removeobject 2
# 111 "data/maps/DesertRuins/scripts.pory"
	playse SE_DOOR
# 112 "data/maps/DesertRuins/scripts.pory"
	waitse
# 113 "data/maps/DesertRuins/scripts.pory"
	removeobject 3
# 114 "data/maps/DesertRuins/scripts.pory"
	playse SE_DOOR
# 115 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_ZINNIA_1
# 116 "data/maps/DesertRuins/scripts.pory"
	setvar VAR_ZINNIA_EVENTS, 4
# 117 "data/maps/DesertRuins/scripts.pory"
	call lvlcapmsg
	goto DesertRuins_EventScript_ZinniaBattle_1

DesertRuins_EventScript_ZinniaBattle_3:
# 120 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaBattle_Text_5, MSGBOX_DEFAULT
	goto DesertRuins_EventScript_ZinniaBattle_1


# 130 "data/maps/DesertRuins/scripts.pory"
DesertRuins_Movement_WhismurBounce:
# 131 "data/maps/DesertRuins/scripts.pory"
	emote_double_exclamation_mark
# 132 "data/maps/DesertRuins/scripts.pory"
	jump_in_place_right
# 133 "data/maps/DesertRuins/scripts.pory"
	jump_in_place_right
	step_end

# 136 "data/maps/DesertRuins/scripts.pory"
DesertRuins_Movement_TurnRight:
# 137 "data/maps/DesertRuins/scripts.pory"
	face_right
	step_end

# 140 "data/maps/DesertRuins/scripts.pory"
DesertRuins_Movement_ZinniaLeave:
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 141 "data/maps/DesertRuins/scripts.pory"
	walk_down
	step_end

# 144 "data/maps/DesertRuins/scripts.pory"
DesertRuins_Movement_WhismurLeave:
# 145 "data/maps/DesertRuins/scripts.pory"
	walk_left
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
# 146 "data/maps/DesertRuins/scripts.pory"
	walk_down
	step_end

DesertRuins_EventScript_ZinniaStop::
# 150 "data/maps/DesertRuins/scripts.pory"
	lockall
# 151 "data/maps/DesertRuins/scripts.pory"
	msgbox DesertRuins_EventScript_ZinniaStop_Text_0, MSGBOX_DEFAULT
# 152 "data/maps/DesertRuins/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DesertRuins_Movement_MoveUp
# 153 "data/maps/DesertRuins/scripts.pory"
	waitmovement
# 154 "data/maps/DesertRuins/scripts.pory"
	releaseall
	end


# 158 "data/maps/DesertRuins/scripts.pory"
DesertRuins_Movement_MoveUp:
# 159 "data/maps/DesertRuins/scripts.pory"
	walk_up
	step_end

DesertRuins_EventScript_ZinniaBattle_Text_0:
# 91 "data/maps/DesertRuins/scripts.pory"
	.string "Well, it doesn't seem like there's\nanything in there.\lOnly some weird dots on the wall.\pBut since I have you here,\n{PLAYER}, how about a battle?$"

DesertRuins_EventScript_ZinniaBattle_Text_1:
# 93 "data/maps/DesertRuins/scripts.pory"
	.string "Great! I've been hoping for a\nchance to battle you!\pDon't hold anything back!$"

DesertRuins_EventScript_ZinniaBattle_Text_2:
# 97 "data/maps/DesertRuins/scripts.pory"
	.string "Niiice, real nice, {PLAYER}!\nOhhh,  I really felt that one!\lFull points to you!\p...\p... ...\pHey, {PLAYER}...\pThe actions that you're taking\nnow...\pAre they based on ideals you\ncling to?\pOr are they based on actual\ntruths?\lAnd if they are...\pHow much of the truth do you\nthink you know?$"

DesertRuins_EventScript_ZinniaBattle_Text_3:
# 104 "data/maps/DesertRuins/scripts.pory"
	.string "Yes Ma'am! Moving out!$"

DesertRuins_EventScript_ZinniaBattle_Text_4:
# 106 "data/maps/DesertRuins/scripts.pory"
	.string "Thanks for battling me, {PLAYER}.\pIf it isn't too much trouble, I\nhope I can borrow your strength in\lthe near future.\pDon't worry, when that time comes\nI'll tell you everything.$"

DesertRuins_EventScript_ZinniaBattle_Text_5:
# 120 "data/maps/DesertRuins/scripts.pory"
	.string "Fine, fine, I ge-e-et it, you\nneed to prepare first.\pJust give me the word whenever\nyou're ready, yeah?$"

DesertRuins_EventScript_ZinniaStop_Text_0:
# 151 "data/maps/DesertRuins/scripts.pory"
	.string "ZINNIA: Hey, where are you going?$"

ZinniaDesertRuinsPostBattle::
# 126 "data/maps/DesertRuins/scripts.pory"
	.string "Yes! That's it! That's just\nwhat I was looking for!$"
