# 1 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 2 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 3 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 4 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 5 "data/maps/LavaridgeTown/scripts.pory"

# 6 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 7 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 8 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 9 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 10 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 12 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 14 "data/maps/LavaridgeTown/scripts.pory"
	end
# 15 "data/maps/LavaridgeTown/scripts.pory"

# 16 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 17 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 18 "data/maps/LavaridgeTown/scripts.pory"
	return
# 19 "data/maps/LavaridgeTown/scripts.pory"

# 20 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 21 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 22 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
# 23 "data/maps/LavaridgeTown/scripts.pory"
	return
# 24 "data/maps/LavaridgeTown/scripts.pory"

# 25 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 26 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
# 27 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
# 28 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 29 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 30 "data/maps/LavaridgeTown/scripts.pory"
	return
# 31 "data/maps/LavaridgeTown/scripts.pory"

# 32 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 33 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 34 "data/maps/LavaridgeTown/scripts.pory"
	return
# 35 "data/maps/LavaridgeTown/scripts.pory"

# 36 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 37 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 38 "data/maps/LavaridgeTown/scripts.pory"
	return
# 39 "data/maps/LavaridgeTown/scripts.pory"

# 40 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 41 "data/maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 42 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 43 "data/maps/LavaridgeTown/scripts.pory"

# 44 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 45 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 46 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 47 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
# 48 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
# 49 "data/maps/LavaridgeTown/scripts.pory"
	delay 20
# 50 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 51 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 52 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 53 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
# 54 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
# 55 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 56 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 57 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 58 "data/maps/LavaridgeTown/scripts.pory"
	end
# 59 "data/maps/LavaridgeTown/scripts.pory"

# 60 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 61 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 62 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 63 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 64 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 65 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 66 "data/maps/LavaridgeTown/scripts.pory"
	end
# 67 "data/maps/LavaridgeTown/scripts.pory"

# 68 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 69 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 70 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 71 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 72 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 73 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 74 "data/maps/LavaridgeTown/scripts.pory"
	end
# 75 "data/maps/LavaridgeTown/scripts.pory"

# 76 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 77 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 78 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL
# 79 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 80 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 81 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
# 82 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
# 83 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 84 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 85 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_DEFEATED_ANABEL_1, LavaridgeTown_EventScript_CallFromAnabel
# 86 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 87 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 88 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 89 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 90 "data/maps/LavaridgeTown/scripts.pory"
	end
# 91 "data/maps/LavaridgeTown/scripts.pory"

# 92 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CallFromAnabel::
# 93 "data/maps/LavaridgeTown/scripts.pory"
	pokenavcall LavaridgeTown_Text_CallFromAnabel
# 94 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_UNLOCKED_ANABEL_2
# 95 "data/maps/LavaridgeTown/scripts.pory"
	return
# 96 "data/maps/LavaridgeTown/scripts.pory"

# 97 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 98 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 99 "data/maps/LavaridgeTown/scripts.pory"
	return
# 100 "data/maps/LavaridgeTown/scripts.pory"

# 101 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 102 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 103 "data/maps/LavaridgeTown/scripts.pory"
	return
# 104 "data/maps/LavaridgeTown/scripts.pory"

# 105 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 106 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 107 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 108 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 109 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 110 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 111 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 112 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 113 "data/maps/LavaridgeTown/scripts.pory"
	return
# 114 "data/maps/LavaridgeTown/scripts.pory"

# 115 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 116 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 117 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 118 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL
# 119 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 120 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 121 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 122 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 123 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 124 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 125 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 126 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 127 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 128 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 129 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 130 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 131 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/LavaridgeTown/scripts.pory"
	return
# 133 "data/maps/LavaridgeTown/scripts.pory"

# 134 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 135 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 136 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 137 "data/maps/LavaridgeTown/scripts.pory"
	return
# 138 "data/maps/LavaridgeTown/scripts.pory"

# 139 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 140 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 141 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 142 "data/maps/LavaridgeTown/scripts.pory"
	return
# 143 "data/maps/LavaridgeTown/scripts.pory"

# 144 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 145 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 146 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 147 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/LavaridgeTown/scripts.pory"
	return
# 149 "data/maps/LavaridgeTown/scripts.pory"

# 150 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 151 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 152 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/LavaridgeTown/scripts.pory"
	return
# 154 "data/maps/LavaridgeTown/scripts.pory"

# 155 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 156 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 157 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 158 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 159 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 160 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 161 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 162 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 163 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 164 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 165 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 166 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 167 "data/maps/LavaridgeTown/scripts.pory"

# 168 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 169 "data/maps/LavaridgeTown/scripts.pory"
	delay_16
# 170 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 171 "data/maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 172 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 173 "data/maps/LavaridgeTown/scripts.pory"

# 174 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 175 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 176 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 177 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 178 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 179 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 180 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 181 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 182 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 183 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 184 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 185 "data/maps/LavaridgeTown/scripts.pory"

# 186 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 187 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 188 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 189 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 190 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 191 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 192 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 193 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 194 "data/maps/LavaridgeTown/scripts.pory"

# 195 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 196 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 197 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 198 "data/maps/LavaridgeTown/scripts.pory"
	walk_up
# 199 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 200 "data/maps/LavaridgeTown/scripts.pory"

# 201 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 202 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 203 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 204 "data/maps/LavaridgeTown/scripts.pory"

# 205 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 206 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 207 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 208 "data/maps/LavaridgeTown/scripts.pory"
	end
# 209 "data/maps/LavaridgeTown/scripts.pory"

# 210 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 211 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 212 "data/maps/LavaridgeTown/scripts.pory"
	end
# 213 "data/maps/LavaridgeTown/scripts.pory"

# 214 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 215 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 216 "data/maps/LavaridgeTown/scripts.pory"
	end
# 217 "data/maps/LavaridgeTown/scripts.pory"

# 218 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 219 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 220 "data/maps/LavaridgeTown/scripts.pory"
	end
# 221 "data/maps/LavaridgeTown/scripts.pory"

# 222 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 223 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 224 "data/maps/LavaridgeTown/scripts.pory"
	end
# 225 "data/maps/LavaridgeTown/scripts.pory"

# 226 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 227 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 228 "data/maps/LavaridgeTown/scripts.pory"
	end
# 229 "data/maps/LavaridgeTown/scripts.pory"

# 230 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 231 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 232 "data/maps/LavaridgeTown/scripts.pory"
	end
# 233 "data/maps/LavaridgeTown/scripts.pory"

# 234 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 235 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 236 "data/maps/LavaridgeTown/scripts.pory"
	end
# 237 "data/maps/LavaridgeTown/scripts.pory"

# 238 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 239 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 240 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 241 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 242 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 243 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 244 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 245 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 246 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 247 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 248 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 249 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 250 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 251 "data/maps/LavaridgeTown/scripts.pory"
	call LavaridgeTown_EventScript_RandomEgg
# 252 "data/maps/LavaridgeTown/scripts.pory"
	release
# 253 "data/maps/LavaridgeTown/scripts.pory"
	end 
# 254 "data/maps/LavaridgeTown/scripts.pory"

# 255 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 256 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_EventScript_EggMegaStone
# 257 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 258 "data/maps/LavaridgeTown/scripts.pory"
	release
# 259 "data/maps/LavaridgeTown/scripts.pory"
	end
# 260 "data/maps/LavaridgeTown/scripts.pory"

# 261 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggMegaStone::
# 262 "data/maps/LavaridgeTown/scripts.pory"
	call LavaridgeTown_EventScript_EggGiveMegaStone
# 263 "data/maps/LavaridgeTown/scripts.pory"
	end
# 264 "data/maps/LavaridgeTown/scripts.pory"

# 265 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 266 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 267 "data/maps/LavaridgeTown/scripts.pory"
	release
# 268 "data/maps/LavaridgeTown/scripts.pory"
	end
# 269 "data/maps/LavaridgeTown/scripts.pory"

# 270 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 271 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 272 "data/maps/LavaridgeTown/scripts.pory"
	release
# 273 "data/maps/LavaridgeTown/scripts.pory"
	end
# 274 "data/maps/LavaridgeTown/scripts.pory"

# 275 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 276 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 277 "data/maps/LavaridgeTown/scripts.pory"
	end
# 278 "data/maps/LavaridgeTown/scripts.pory"

# 279 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 280 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 281 "data/maps/LavaridgeTown/scripts.pory"
	end
# 282 "data/maps/LavaridgeTown/scripts.pory"

# 283 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 284 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 285 "data/maps/LavaridgeTown/scripts.pory"
	end
# 286 "data/maps/LavaridgeTown/scripts.pory"

# 287 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 288 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 289 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 290 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 291 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 292 "data/maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 293 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 294 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 295 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 296 "data/maps/LavaridgeTown/scripts.pory"

# 297 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 298 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 299 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 300 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 301 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 302 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 303 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 304 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 305 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 306 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 307 "data/maps/LavaridgeTown/scripts.pory"
	.string "You should do so too after checking\n"
# 308 "data/maps/LavaridgeTown/scripts.pory"
	.string "out the desert. See you again!$"
# 309 "data/maps/LavaridgeTown/scripts.pory"

# 310 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 313 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 314 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 317 "data/maps/LavaridgeTown/scripts.pory"

# 318 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 319 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 320 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 321 "data/maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 323 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 324 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 326 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 327 "data/maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 328 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 329 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 330 "data/maps/LavaridgeTown/scripts.pory"
	.string "Maybe you should challenge him too after\n"
# 331 "data/maps/LavaridgeTown/scripts.pory"
	.string "checking out the desert. See you around!$"
# 332 "data/maps/LavaridgeTown/scripts.pory"

# 333 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_CallFromAnabel:
# 334 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hey, {PLAYER}, it's ANABEL.\n"
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "This is your number, yes?\p"
# 336 "data/maps/LavaridgeTown/scripts.pory"
	.string "Never mind how I got it. If you ever\n"
# 337 "data/maps/LavaridgeTown/scripts.pory"
	.string "feel like battling me again in\l"
# 338 "data/maps/LavaridgeTown/scripts.pory"
	.string "Fallarbor I might have a new\l" 
# 339 "data/maps/LavaridgeTown/scripts.pory"
	.string "collection of stones for you.\p"
# 340 "data/maps/LavaridgeTown/scripts.pory"
	.string "Feel free to stop by whenever.$"
# 341 "data/maps/LavaridgeTown/scripts.pory"

# 342 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 343 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 344 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 345 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 347 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 348 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 349 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 350 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 351 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 352 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 353 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 354 "data/maps/LavaridgeTown/scripts.pory"

# 355 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 356 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 357 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 358 "data/maps/LavaridgeTown/scripts.pory"

# 359 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 361 "data/maps/LavaridgeTown/scripts.pory"

# 362 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 363 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 364 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 365 "data/maps/LavaridgeTown/scripts.pory"

# 366 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 367 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 368 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 369 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 370 "data/maps/LavaridgeTown/scripts.pory"

# 371 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 372 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 373 "data/maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 374 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 375 "data/maps/LavaridgeTown/scripts.pory"

# 376 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 377 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 378 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 379 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 380 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 381 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 382 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 383 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 384 "data/maps/LavaridgeTown/scripts.pory"

# 385 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 386 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 387 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 389 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 390 "data/maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 391 "data/maps/LavaridgeTown/scripts.pory"

# 392 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 393 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 394 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 395 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 396 "data/maps/LavaridgeTown/scripts.pory"

# 397 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 398 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 399 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 400 "data/maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 401 "data/maps/LavaridgeTown/scripts.pory"

# 402 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 403 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 404 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 405 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 406 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 407 "data/maps/LavaridgeTown/scripts.pory"

# 408 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 409 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 410 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 411 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 412 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 413 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 414 "data/maps/LavaridgeTown/scripts.pory"

# 415 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 416 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 417 "data/maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 418 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 419 "data/maps/LavaridgeTown/scripts.pory"

# 420 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 421 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 422 "data/maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 423 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 424 "data/maps/LavaridgeTown/scripts.pory"

# 425 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 426 "data/maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 427 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"

LavaridgeTown_EventScript_RandomEgg::
# 431 "data/maps/LavaridgeTown/scripts.pory"
	randomelement 1, 2, 3
# 432 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_EventScript_RandomEgg_2
# 436 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq LavaridgeTown_EventScript_RandomEgg_3
# 440 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq LavaridgeTown_EventScript_RandomEgg_4
LavaridgeTown_EventScript_RandomEgg_1:
# 444 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
	end

LavaridgeTown_EventScript_RandomEgg_2:
# 433 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_GROOKEY
# 434 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_GROOKEY_EGG
	goto LavaridgeTown_EventScript_RandomEgg_1

LavaridgeTown_EventScript_RandomEgg_3:
# 437 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SCORBUNNY
# 438 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_SCORBUNNY_EGG
	goto LavaridgeTown_EventScript_RandomEgg_1

LavaridgeTown_EventScript_RandomEgg_4:
# 441 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_SOBBLE
# 442 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_SOBBLE_EGG
	goto LavaridgeTown_EventScript_RandomEgg_1


LavaridgeTown_EventScript_AuspiciousOrMalicious::
# 449 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 450 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 451 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_unset FLAG_LAVARIDGE_OBTAINED_ARMOR, LavaridgeTown_EventScript_AuspiciousOrMalicious_2
# 465 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_3, MSGBOX_DEFAULT
LavaridgeTown_EventScript_AuspiciousOrMalicious_1:
# 467 "data/maps/LavaridgeTown/scripts.pory"
	release
	return

LavaridgeTown_EventScript_AuspiciousOrMalicious_2:
# 452 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_0, MSGBOX_DEFAULT
# 453 "data/maps/LavaridgeTown/scripts.pory"
	multichoice 20, 8, MULTI_LAVARIDGE_CHARCADET, 1
# 454 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq LavaridgeTown_EventScript_AuspiciousOrMalicious_6
# 458 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_EventScript_AuspiciousOrMalicious_7
LavaridgeTown_EventScript_AuspiciousOrMalicious_5:
# 462 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_LAVARIDGE_OBTAINED_ARMOR
	goto LavaridgeTown_EventScript_AuspiciousOrMalicious_1

LavaridgeTown_EventScript_AuspiciousOrMalicious_6:
# 455 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_1, MSGBOX_DEFAULT
# 456 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_AUSPICIOUS_ARMOR
	goto LavaridgeTown_EventScript_AuspiciousOrMalicious_5

LavaridgeTown_EventScript_AuspiciousOrMalicious_7:
# 459 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_2, MSGBOX_DEFAULT
# 460 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_MALICIOUS_ARMOR
	goto LavaridgeTown_EventScript_AuspiciousOrMalicious_5


LavaridgeTown_EventScript_EggGiveMegaStone::
# 471 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_unset FLAG_EGG_MEGA_STONE, LavaridgeTown_EventScript_EggGiveMegaStone_2
# 485 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
LavaridgeTown_EventScript_EggGiveMegaStone_1:
# 487 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
	end

LavaridgeTown_EventScript_EggGiveMegaStone_2:
# 472 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_EventScript_EggGiveMegaStone_Text_0, MSGBOX_DEFAULT
# 473 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_GROOKEY_EGG, LavaridgeTown_EventScript_EggGiveMegaStone_6
# 476 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_SCORBUNNY_EGG, LavaridgeTown_EventScript_EggGiveMegaStone_7
# 479 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_SOBBLE_EGG, LavaridgeTown_EventScript_EggGiveMegaStone_8
LavaridgeTown_EventScript_EggGiveMegaStone_5:
# 482 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_EGG_MEGA_STONE
	goto LavaridgeTown_EventScript_EggGiveMegaStone_1

LavaridgeTown_EventScript_EggGiveMegaStone_6:
# 474 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_RILLABOOMITE_G
	goto LavaridgeTown_EventScript_EggGiveMegaStone_5

LavaridgeTown_EventScript_EggGiveMegaStone_7:
# 477 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_CINDERACITE_G
	goto LavaridgeTown_EventScript_EggGiveMegaStone_5

LavaridgeTown_EventScript_EggGiveMegaStone_8:
# 480 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_INTELEONITE_G
	goto LavaridgeTown_EventScript_EggGiveMegaStone_5


LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_0:
# 452 "data/maps/LavaridgeTown/scripts.pory"
	.string "Do you see yourself as auspicious?\pOr maybe you're more... malicious.$"

LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_1:
# 455 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hehe... I see... Here.$"

LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_2:
# 459 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hehe... You're like me...$"

LavaridgeTown_EventScript_AuspiciousOrMalicious_Text_3:
# 465 "data/maps/LavaridgeTown/scripts.pory"
	.string "Stick to your ideals...\nAlways... Heh...$"

LavaridgeTown_EventScript_EggGiveMegaStone_Text_0:
# 472 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh my, you really\ndefeated FLANNERY?\pThe egg I gave you...\nI want you to have this.$"
