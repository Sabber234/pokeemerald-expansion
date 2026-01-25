# 1 "data/maps/Route111/scripts.pory"
Route111_MapScripts::
# 2 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
# 3 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
# 4 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
# 5 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
# 6 "data/maps/Route111/scripts.pory"
	.byte 0
# 7 "data/maps/Route111/scripts.pory"

# 8 "data/maps/Route111/scripts.pory"
Route111_OnLoad:
# 9 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
# 10 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
# 11 "data/maps/Route111/scripts.pory"
	end
# 12 "data/maps/Route111/scripts.pory"

# 13 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseDesertRuins::
# 14 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
# 15 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
# 16 "data/maps/Route111/scripts.pory"
	return
# 17 "data/maps/Route111/scripts.pory"

# 18 "data/maps/Route111/scripts.pory"
@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
# 19 "data/maps/Route111/scripts.pory"
Route111_EventScript_ShowTemporaryMirageTower::
# 20 "data/maps/Route111/scripts.pory"
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
# 21 "data/maps/Route111/scripts.pory"
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
# 22 "data/maps/Route111/scripts.pory"
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
# 23 "data/maps/Route111/scripts.pory"
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
# 24 "data/maps/Route111/scripts.pory"
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
# 25 "data/maps/Route111/scripts.pory"
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
# 26 "data/maps/Route111/scripts.pory"
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
# 27 "data/maps/Route111/scripts.pory"
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
# 28 "data/maps/Route111/scripts.pory"
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
# 29 "data/maps/Route111/scripts.pory"
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
# 30 "data/maps/Route111/scripts.pory"
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
# 31 "data/maps/Route111/scripts.pory"
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
# 32 "data/maps/Route111/scripts.pory"
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
# 33 "data/maps/Route111/scripts.pory"
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
# 34 "data/maps/Route111/scripts.pory"
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
# 35 "data/maps/Route111/scripts.pory"
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
# 36 "data/maps/Route111/scripts.pory"
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
# 37 "data/maps/Route111/scripts.pory"
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
# 38 "data/maps/Route111/scripts.pory"
	return
# 39 "data/maps/Route111/scripts.pory"

# 40 "data/maps/Route111/scripts.pory"
Route111_OnTransition:
# 41 "data/maps/Route111/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 42 "data/maps/Route111/scripts.pory"
	special SetMirageTowerVisibility
# 43 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
# 44 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
# 45 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
# 46 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CheckSetSandstorm
# 47 "data/maps/Route111/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 48 "data/maps/Route111/scripts.pory"
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
# 49 "data/maps/Route111/scripts.pory"
	end
# 50 "data/maps/Route111/scripts.pory"

# 51 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfx::
# 52 "data/maps/Route111/scripts.pory"
	checkplayergender
# 53 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
# 54 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
# 55 "data/maps/Route111/scripts.pory"
	return
# 56 "data/maps/Route111/scripts.pory"

# 57 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxMale::
# 58 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 59 "data/maps/Route111/scripts.pory"
	return
# 60 "data/maps/Route111/scripts.pory"

# 61 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxFemale::
# 62 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 63 "data/maps/Route111/scripts.pory"
	return
# 64 "data/maps/Route111/scripts.pory"

# 65 "data/maps/Route111/scripts.pory"
Route111_EventScript_CheckSetSandstorm::
# 66 "data/maps/Route111/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 67 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
# 68 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
# 69 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
# 70 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
# 71 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
# 72 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetSandstorm::
# 73 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 74 "data/maps/Route111/scripts.pory"
Route111_EventScript_EndCheckSetSandstorm::
# 75 "data/maps/Route111/scripts.pory"
	return
# 76 "data/maps/Route111/scripts.pory"

# 77 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetWinstratesNotDefeated::
# 78 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
# 79 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
# 80 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
# 81 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
# 82 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTOR
# 83 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTORIA
# 84 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VIVI
# 85 "data/maps/Route111/scripts.pory"
	end
# 86 "data/maps/Route111/scripts.pory"

# 87 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetLayoutNoMirageTower::
# 88 "data/maps/Route111/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
# 89 "data/maps/Route111/scripts.pory"
	return
# 90 "data/maps/Route111/scripts.pory"

# 91 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetMirageTowerGone::
# 92 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 3
# 93 "data/maps/Route111/scripts.pory"
	return
# 94 "data/maps/Route111/scripts.pory"

# 95 "data/maps/Route111/scripts.pory"
Route111_OnWarp:
# 96 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
# 97 "data/maps/Route111/scripts.pory"
	.2byte 0
# 98 "data/maps/Route111/scripts.pory"

# 99 "data/maps/Route111/scripts.pory"
Route111_EventScript_HidePlayerForMirageTower::
# 100 "data/maps/Route111/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
# 101 "data/maps/Route111/scripts.pory"
	end
# 102 "data/maps/Route111/scripts.pory"

# 103 "data/maps/Route111/scripts.pory"
Route111_OnFrame:
# 104 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
# 105 "data/maps/Route111/scripts.pory"
	.2byte 0
# 106 "data/maps/Route111/scripts.pory"

# 107 "data/maps/Route111/scripts.pory"
Route111_EventScript_MirageTowerDisappear::
# 108 "data/maps/Route111/scripts.pory"
	lockall
# 109 "data/maps/Route111/scripts.pory"
	special StartMirageTowerShake
# 110 "data/maps/Route111/scripts.pory"
	waitstate
# 111 "data/maps/Route111/scripts.pory"
	delay 24
# 112 "data/maps/Route111/scripts.pory"
	playse SE_FALL
# 113 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_PLAYER_FALLING
# 114 "data/maps/Route111/scripts.pory"
	special StartPlayerDescendMirageTower
# 115 "data/maps/Route111/scripts.pory"
	waitstate
# 116 "data/maps/Route111/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
# 117 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
# 118 "data/maps/Route111/scripts.pory"
	delay 16
# 119 "data/maps/Route111/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 120 "data/maps/Route111/scripts.pory"
	delay 16
# 121 "data/maps/Route111/scripts.pory"
	special StartMirageTowerDisintegration
# 122 "data/maps/Route111/scripts.pory"
	waitstate
# 123 "data/maps/Route111/scripts.pory"
	special StartMirageTowerFossilFallAndSink
# 124 "data/maps/Route111/scripts.pory"
	waitstate
# 125 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 2
# 126 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 127 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
# 128 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
# 129 "data/maps/Route111/scripts.pory"
	releaseall
# 130 "data/maps/Route111/scripts.pory"
	end
# 131 "data/maps/Route111/scripts.pory"

# 132 "data/maps/Route111/scripts.pory"
Route111_EventScript_RootFossilDisappeared::
# 133 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
# 134 "data/maps/Route111/scripts.pory"
	releaseall
# 135 "data/maps/Route111/scripts.pory"
	end
# 136 "data/maps/Route111/scripts.pory"

# 137 "data/maps/Route111/scripts.pory"
@ Unused
# 138 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall::
# 139 "data/maps/Route111/scripts.pory"
	lock_anim
# 140 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 141 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 142 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 143 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 145 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 146 "data/maps/Route111/scripts.pory"
	step_end
# 147 "data/maps/Route111/scripts.pory"

# 148 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl::
# 149 "data/maps/Route111/scripts.pory"
	lock
# 150 "data/maps/Route111/scripts.pory"
	faceplayer
# 151 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 152 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 153 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 154 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 155 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 156 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 157 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 158 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 159 "data/maps/Route111/scripts.pory"
	release
# 160 "data/maps/Route111/scripts.pory"
	end
# 161 "data/maps/Route111/scripts.pory"

# 162 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry::
# 163 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 164 "data/maps/Route111/scripts.pory"
	release
# 165 "data/maps/Route111/scripts.pory"
	end
# 166 "data/maps/Route111/scripts.pory"

# 167 "data/maps/Route111/scripts.pory"
@ Unused
# 168 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp::
# 169 "data/maps/Route111/scripts.pory"
	lockall
# 170 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 171 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 172 "data/maps/Route111/scripts.pory"
	end
# 173 "data/maps/Route111/scripts.pory"

# 174 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown::
# 175 "data/maps/Route111/scripts.pory"
	lockall
# 176 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 177 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 178 "data/maps/Route111/scripts.pory"
	end
# 179 "data/maps/Route111/scripts.pory"

# 180 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft::
# 181 "data/maps/Route111/scripts.pory"
	lockall
# 182 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 183 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 184 "data/maps/Route111/scripts.pory"
	end
# 185 "data/maps/Route111/scripts.pory"

# 186 "data/maps/Route111/scripts.pory"
@ Unused
# 187 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight::
# 188 "data/maps/Route111/scripts.pory"
	lockall
# 189 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 190 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 191 "data/maps/Route111/scripts.pory"
	end
# 192 "data/maps/Route111/scripts.pory"

# 193 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger::
# 194 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES
# 195 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
# 196 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 197 "data/maps/Route111/scripts.pory"
	releaseall
# 198 "data/maps/Route111/scripts.pory"
	end
# 199 "data/maps/Route111/scripts.pory"

# 200 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess::
# 201 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 202 "data/maps/Route111/scripts.pory"
	closemessage
# 203 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
# 204 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
# 205 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
# 206 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
# 207 "data/maps/Route111/scripts.pory"
	releaseall
# 208 "data/maps/Route111/scripts.pory"
	end
# 209 "data/maps/Route111/scripts.pory"

# 210 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute::
# 211 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute
# 212 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 213 "data/maps/Route111/scripts.pory"
	return
# 214 "data/maps/Route111/scripts.pory"

# 215 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute::
# 216 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushDownFromRoute
# 217 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 218 "data/maps/Route111/scripts.pory"
	return
# 219 "data/maps/Route111/scripts.pory"

# 220 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute::
# 221 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushLeftFromRoute
# 222 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 223 "data/maps/Route111/scripts.pory"
	return
# 224 "data/maps/Route111/scripts.pory"

# 225 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute::
# 226 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushRightFromRoute
# 227 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 228 "data/maps/Route111/scripts.pory"
	return
# 229 "data/maps/Route111/scripts.pory"

# 230 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute:
# 231 "data/maps/Route111/scripts.pory"
	walk_up
# 232 "data/maps/Route111/scripts.pory"
	step_end
# 233 "data/maps/Route111/scripts.pory"

# 234 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute:
# 235 "data/maps/Route111/scripts.pory"
	walk_down
# 236 "data/maps/Route111/scripts.pory"
	step_end
# 237 "data/maps/Route111/scripts.pory"

# 238 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute:
# 239 "data/maps/Route111/scripts.pory"
	walk_left
# 240 "data/maps/Route111/scripts.pory"
	step_end
# 241 "data/maps/Route111/scripts.pory"

# 242 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute:
# 243 "data/maps/Route111/scripts.pory"
	walk_right
# 244 "data/maps/Route111/scripts.pory"
	step_end
# 245 "data/maps/Route111/scripts.pory"

# 246 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger::
# 247 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 248 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 249 "data/maps/Route111/scripts.pory"
	doweather
# 250 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 251 "data/maps/Route111/scripts.pory"
	end
# 252 "data/maps/Route111/scripts.pory"

# 253 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger::
# 254 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 255 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_DESERT
# 256 "data/maps/Route111/scripts.pory"
	doweather
# 257 "data/maps/Route111/scripts.pory"
	end
# 258 "data/maps/Route111/scripts.pory"

# 259 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor::
# 260 "data/maps/Route111/scripts.pory"
	lock
# 261 "data/maps/Route111/scripts.pory"
	faceplayer
# 262 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 263 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 264 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
# 265 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 266 "data/maps/Route111/scripts.pory"
	release
# 267 "data/maps/Route111/scripts.pory"
	end
# 268 "data/maps/Route111/scripts.pory"

# 269 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates::
# 270 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 271 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 272 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTOR, Common_Movement_WalkInPlaceFasterUp
# 273 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 274 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 275 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 276 "data/maps/Route111/scripts.pory"
	closemessage
# 277 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTOR, Route111_Movement_WinstrateEnterHouse
# 278 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 279 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICTOR
# 280 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 281 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 282 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 283 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 284 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VICTORIA
# 285 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateExitHouse
# 286 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 287 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 288 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 289 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 290 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Common_Movement_WalkInPlaceFasterUp
# 291 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 292 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 293 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 294 "data/maps/Route111/scripts.pory"
	closemessage
# 295 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 296 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 297 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICTORIA
# 298 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 299 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 300 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 301 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 302 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VIVI
# 303 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateExitHouse
# 304 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 305 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 306 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 307 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 308 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Common_Movement_WalkInPlaceFasterUp
# 309 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 310 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 311 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 312 "data/maps/Route111/scripts.pory"
	closemessage
# 313 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateEnterHouse
# 314 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 315 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VIVI
# 316 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 317 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 318 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 319 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 320 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VICKY
# 321 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateExitHouse
# 322 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 323 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 324 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 325 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 326 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 327 "data/maps/Route111/scripts.pory"
	closemessage
# 328 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Common_Movement_WalkInPlaceFasterUp
# 329 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 330 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 331 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateEnterHouse
# 332 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 333 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICKY
# 334 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 335 "data/maps/Route111/scripts.pory"
	release
# 336 "data/maps/Route111/scripts.pory"
	end
# 337 "data/maps/Route111/scripts.pory"

# 338 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor::
# 339 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 340 "data/maps/Route111/scripts.pory"
	waitdooranim
# 341 "data/maps/Route111/scripts.pory"
	return
# 342 "data/maps/Route111/scripts.pory"

# 343 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor::
# 344 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 345 "data/maps/Route111/scripts.pory"
	waitdooranim
# 346 "data/maps/Route111/scripts.pory"
	return
# 347 "data/maps/Route111/scripts.pory"

# 348 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse:
# 349 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 350 "data/maps/Route111/scripts.pory"
	walk_up
# 351 "data/maps/Route111/scripts.pory"
	step_end
# 352 "data/maps/Route111/scripts.pory"

# 353 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse:
# 354 "data/maps/Route111/scripts.pory"
	walk_down
# 355 "data/maps/Route111/scripts.pory"
	step_end
# 356 "data/maps/Route111/scripts.pory"

# 357 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate:
# 358 "data/maps/Route111/scripts.pory"
	delay_16
# 359 "data/maps/Route111/scripts.pory"
	delay_16
# 360 "data/maps/Route111/scripts.pory"
	delay_16
# 361 "data/maps/Route111/scripts.pory"
	step_end
# 362 "data/maps/Route111/scripts.pory"

# 363 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville::
# 364 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 365 "data/maps/Route111/scripts.pory"
	end
# 366 "data/maps/Route111/scripts.pory"

# 367 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign::
# 368 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 369 "data/maps/Route111/scripts.pory"
	end
# 370 "data/maps/Route111/scripts.pory"

# 371 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112::
# 372 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 373 "data/maps/Route111/scripts.pory"
	end
# 374 "data/maps/Route111/scripts.pory"

# 375 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113::
# 376 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 377 "data/maps/Route111/scripts.pory"
	end
# 378 "data/maps/Route111/scripts.pory"

# 379 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign::
# 380 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 381 "data/maps/Route111/scripts.pory"
	end
# 382 "data/maps/Route111/scripts.pory"

# 383 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef::
# 384 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 385 "data/maps/Route111/scripts.pory"
	end
# 386 "data/maps/Route111/scripts.pory"

# 387 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1::
# 388 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 389 "data/maps/Route111/scripts.pory"
	end
# 390 "data/maps/Route111/scripts.pory"

# 391 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2::
# 392 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 393 "data/maps/Route111/scripts.pory"
	end
# 394 "data/maps/Route111/scripts.pory"

# 395 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker::
# 396 "data/maps/Route111/scripts.pory"
	lock
# 397 "data/maps/Route111/scripts.pory"
	faceplayer
# 398 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
# 399 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
# 400 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 401 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 402 "data/maps/Route111/scripts.pory"
	release
# 403 "data/maps/Route111/scripts.pory"
	end
# 404 "data/maps/Route111/scripts.pory"

# 405 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone::
# 406 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 407 "data/maps/Route111/scripts.pory"
	release
# 408 "data/maps/Route111/scripts.pory"
	end
# 409 "data/maps/Route111/scripts.pory"

# 410 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated::
# 411 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 412 "data/maps/Route111/scripts.pory"
	release
# 413 "data/maps/Route111/scripts.pory"
	end
# 414 "data/maps/Route111/scripts.pory"

# 415 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible::
# 416 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 417 "data/maps/Route111/scripts.pory"
	release
# 418 "data/maps/Route111/scripts.pory"
	end
# 419 "data/maps/Route111/scripts.pory"

# 420 "data/maps/Route111/scripts.pory"
Route111_EventScript_RockSmashTipFatMan::
# 421 "data/maps/Route111/scripts.pory"
	lockall
# 422 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FacePlayer
# 423 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 424 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
# 425 "data/maps/Route111/scripts.pory"
	closemessage
# 426 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
# 427 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 428 "data/maps/Route111/scripts.pory"
	releaseall
# 429 "data/maps/Route111/scripts.pory"
	end
# 430 "data/maps/Route111/scripts.pory"

# 431 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew::
# 432 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 433 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 434 "data/maps/Route111/scripts.pory"
	end
# 435 "data/maps/Route111/scripts.pory"

# 436 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi::
# 437 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 438 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 439 "data/maps/Route111/scripts.pory"
	end
# 440 "data/maps/Route111/scripts.pory"

# 441 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau::
# 442 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 443 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 444 "data/maps/Route111/scripts.pory"
	end
# 445 "data/maps/Route111/scripts.pory"

# 446 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky::
# 447 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 448 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 449 "data/maps/Route111/scripts.pory"
	end
# 450 "data/maps/Route111/scripts.pory"

# 451 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty::
# 452 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 453 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 454 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
# 455 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 456 "data/maps/Route111/scripts.pory"
	release
# 457 "data/maps/Route111/scripts.pory"
	end
# 458 "data/maps/Route111/scripts.pory"

# 459 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty::
# 460 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 461 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 462 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 463 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 464 "data/maps/Route111/scripts.pory"
	release
# 465 "data/maps/Route111/scripts.pory"
	end
# 466 "data/maps/Route111/scripts.pory"

# 467 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty::
# 468 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 469 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 470 "data/maps/Route111/scripts.pory"
	end
# 471 "data/maps/Route111/scripts.pory"

# 472 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis::
# 473 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 474 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 475 "data/maps/Route111/scripts.pory"
	end
# 476 "data/maps/Route111/scripts.pory"

# 477 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene::
# 478 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 479 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 480 "data/maps/Route111/scripts.pory"
	end
# 481 "data/maps/Route111/scripts.pory"

# 482 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke::
# 483 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 484 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 485 "data/maps/Route111/scripts.pory"
	end
# 486 "data/maps/Route111/scripts.pory"

# 487 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton::
# 488 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 489 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 490 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
# 491 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 492 "data/maps/Route111/scripts.pory"
	release
# 493 "data/maps/Route111/scripts.pory"
	end
# 494 "data/maps/Route111/scripts.pory"

# 495 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton::
# 496 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 497 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 498 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 499 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 500 "data/maps/Route111/scripts.pory"
	release
# 501 "data/maps/Route111/scripts.pory"
	end
# 502 "data/maps/Route111/scripts.pory"

# 503 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton::
# 504 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 505 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 506 "data/maps/Route111/scripts.pory"
	end
# 507 "data/maps/Route111/scripts.pory"

# 508 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke::
# 509 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 510 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 511 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
# 512 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 513 "data/maps/Route111/scripts.pory"
	release
# 514 "data/maps/Route111/scripts.pory"
	end
# 515 "data/maps/Route111/scripts.pory"

# 516 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke::
# 517 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 518 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 519 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 520 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 521 "data/maps/Route111/scripts.pory"
	release
# 522 "data/maps/Route111/scripts.pory"
	end
# 523 "data/maps/Route111/scripts.pory"

# 524 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke::
# 525 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 526 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 527 "data/maps/Route111/scripts.pory"
	end
# 528 "data/maps/Route111/scripts.pory"

# 529 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden::
# 530 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 531 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 532 "data/maps/Route111/scripts.pory"
	end
# 533 "data/maps/Route111/scripts.pory"

# 534 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca::
# 535 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 536 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 537 "data/maps/Route111/scripts.pory"
	end
# 538 "data/maps/Route111/scripts.pory"

# 539 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron::
# 540 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 541 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 542 "data/maps/Route111/scripts.pory"
	end
# 543 "data/maps/Route111/scripts.pory"

# 544 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina::
# 545 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 546 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 547 "data/maps/Route111/scripts.pory"
	end
# 548 "data/maps/Route111/scripts.pory"

# 549 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia::
# 550 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 551 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 552 "data/maps/Route111/scripts.pory"
	end
# 553 "data/maps/Route111/scripts.pory"

# 554 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan::
# 555 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 556 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 557 "data/maps/Route111/scripts.pory"
	end
# 558 "data/maps/Route111/scripts.pory"

# 559 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden::
# 560 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 561 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 562 "data/maps/Route111/scripts.pory"
	end
# 563 "data/maps/Route111/scripts.pory"

# 564 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign::
# 565 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 566 "data/maps/Route111/scripts.pory"
	end
# 567 "data/maps/Route111/scripts.pory"

# 568 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily:
# 569 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 570 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 571 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 572 "data/maps/Route111/scripts.pory"
	.string "POKéMON battles?$"
# 573 "data/maps/Route111/scripts.pory"

# 574 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo:
# 575 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 576 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 577 "data/maps/Route111/scripts.pory"

# 578 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro:
# 579 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 580 "data/maps/Route111/scripts.pory"

# 581 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat:
# 582 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 583 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 584 "data/maps/Route111/scripts.pory"

# 585 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle:
# 586 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 587 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong TRAINER!$"
# 588 "data/maps/Route111/scripts.pory"

# 589 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro:
# 590 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 591 "data/maps/Route111/scripts.pory"
	.string "You must be quite the TRAINER to beat\n"
# 592 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 593 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 594 "data/maps/Route111/scripts.pory"

# 595 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat:
# 596 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 597 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 598 "data/maps/Route111/scripts.pory"

# 599 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle:
# 600 "data/maps/Route111/scripts.pory"
	.string "There's a strong TRAINER here!\n"
# 601 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 602 "data/maps/Route111/scripts.pory"

# 603 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro:
# 604 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 605 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 606 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 607 "data/maps/Route111/scripts.pory"

# 608 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat:
# 609 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 610 "data/maps/Route111/scripts.pory"

# 611 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle:
# 612 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 613 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 614 "data/maps/Route111/scripts.pory"

# 615 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro:
# 616 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 617 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 618 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 619 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 620 "data/maps/Route111/scripts.pory"

# 621 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat:
# 622 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 623 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 624 "data/maps/Route111/scripts.pory"

# 625 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle:
# 626 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 627 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 628 "data/maps/Route111/scripts.pory"

# 629 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks:
# 630 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your POKéMON some\n"
# 631 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 632 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 633 "data/maps/Route111/scripts.pory"
	.string "I've heard the POKéMON LEAGUE's\n"
# 634 "data/maps/Route111/scripts.pory"
	.string "ELITE FOUR are far stronger than\l"
# 635 "data/maps/Route111/scripts.pory"
	.string "any GYM LEADER.$"
# 636 "data/maps/Route111/scripts.pory"

# 637 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe:
# 638 "data/maps/Route111/scripts.pory"
	.string "I challenged the WINSTRATE family,\n"
# 639 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 640 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 641 "data/maps/Route111/scripts.pory"

# 642 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville:
# 643 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 644 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} MAUVILLE CITY$"
# 645 "data/maps/Route111/scripts.pory"

# 646 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign:
# 647 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 648 "data/maps/Route111/scripts.pory"
	.string "THE WINSTRATE'S HOUSE$"
# 649 "data/maps/Route111/scripts.pory"

# 650 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112:
# 651 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 652 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 112$"
# 653 "data/maps/Route111/scripts.pory"

# 654 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113:
# 655 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 656 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 113$"
# 657 "data/maps/Route111/scripts.pory"

# 658 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign:
# 659 "data/maps/Route111/scripts.pory"
	.string "OLD LADY'S REST STOP\n"
# 660 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 661 "data/maps/Route111/scripts.pory"

# 662 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef:
# 663 "data/maps/Route111/scripts.pory"
	.string "TRAINER TIPS\p"
# 664 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a POKéMON's\n"
# 665 "data/maps/Route111/scripts.pory"
	.string "powerfulness is SP. ATK. It stands for\l"
# 666 "data/maps/Route111/scripts.pory"
	.string "“SPECIAL ATTACK.”\p"
# 667 "data/maps/Route111/scripts.pory"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
# 668 "data/maps/Route111/scripts.pory"
	.string "DEFENSE.”$"
# 669 "data/maps/Route111/scripts.pory"

# 670 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere:
# 671 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 672 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 673 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 674 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 675 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the MIRAGE TOWER.$"
# 676 "data/maps/Route111/scripts.pory"

# 677 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible:
# 678 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 679 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 680 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 681 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 682 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 683 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 684 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 685 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 686 "data/maps/Route111/scripts.pory"

# 687 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown:
# 688 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 689 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 690 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 691 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 692 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 693 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 694 "data/maps/Route111/scripts.pory"

# 695 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince:
# 696 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 697 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 698 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 699 "data/maps/Route111/scripts.pory"
	.string "the MIRAGE TOWER…$"
# 700 "data/maps/Route111/scripts.pory"

# 701 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared:
# 702 "data/maps/Route111/scripts.pory"
	.string "The CLAW FOSSIL disappeared into\n"
# 703 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 704 "data/maps/Route111/scripts.pory"

# 705 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared:
# 706 "data/maps/Route111/scripts.pory"
	.string "The ROOT FOSSIL disappeared into\n"
# 707 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 708 "data/maps/Route111/scripts.pory"

# 709 "data/maps/Route111/scripts.pory"
Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
# 710 "data/maps/Route111/scripts.pory"
	.string "Oh, no!\p"
# 711 "data/maps/Route111/scripts.pory"
	.string "My uncle in MAUVILLE told me to take\n"
# 712 "data/maps/Route111/scripts.pory"
	.string "ROCK SMASH with me if I was going to\l"
# 713 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111!\p"
# 714 "data/maps/Route111/scripts.pory"
	.string "My uncle? He lives across from\n"
# 715 "data/maps/Route111/scripts.pory"
	.string "the bike shop in MAUVILLE.$"
# 716 "data/maps/Route111/scripts.pory"

# 717 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign:
# 718 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
# 719 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 720 "data/maps/Route111/scripts.pory"
	.string "TRAINERS!”$"

Route111_EventScript_WhismurCry1::
# 724 "data/maps/Route111/scripts.pory"
	compare VAR_WHISMUR_CRIES, 0
	goto_if_eq Route111_EventScript_WhismurCry1_1
	return

Route111_EventScript_WhismurCry1_1:
# 725 "data/maps/Route111/scripts.pory"
	lockall
# 726 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_EmoteSurprised
# 727 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 728 "data/maps/Route111/scripts.pory"
	waitmoncry
# 729 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_WhismurCry1_Text_0
# 730 "data/maps/Route111/scripts.pory"
	setvar VAR_WHISMUR_CRIES, 1
# 731 "data/maps/Route111/scripts.pory"
	releaseall
	end


Route111_EventScript_WhismurCry2::
# 737 "data/maps/Route111/scripts.pory"
	compare VAR_WHISMUR_CRIES, 1
	goto_if_eq Route111_EventScript_WhismurCry2_1
	return

Route111_EventScript_WhismurCry2_1:
# 738 "data/maps/Route111/scripts.pory"
	lockall
# 739 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 740 "data/maps/Route111/scripts.pory"
	waitmoncry
# 741 "data/maps/Route111/scripts.pory"
	setvar VAR_WHISMUR_CRIES, 2
# 742 "data/maps/Route111/scripts.pory"
	releaseall
	end


Route111_EventScript_WhismurCry3::
# 748 "data/maps/Route111/scripts.pory"
	compare VAR_WHISMUR_CRIES, 2
	goto_if_eq Route111_EventScript_WhismurCry3_1
	return

Route111_EventScript_WhismurCry3_1:
# 749 "data/maps/Route111/scripts.pory"
	lockall
# 750 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 751 "data/maps/Route111/scripts.pory"
	waitmoncry
# 752 "data/maps/Route111/scripts.pory"
	setvar VAR_WHISMUR_CRIES, 3
# 753 "data/maps/Route111/scripts.pory"
	releaseall
	end


# 758 "data/maps/Route111/scripts.pory"
Route111_Movement_EmoteSurprised:
# 759 "data/maps/Route111/scripts.pory"
	emote_exclamation_mark
	step_end

# 762 "data/maps/Route111/scripts.pory"
Route111_Movement_MoveDown:
# 763 "data/maps/Route111/scripts.pory"
	walk_down
# 764 "data/maps/Route111/scripts.pory"
	face_up
	step_end

# 767 "data/maps/Route111/scripts.pory"
Route111_Movement_MoveUp1:
# 768 "data/maps/Route111/scripts.pory"
	walk_up
# 768 "data/maps/Route111/scripts.pory"
	walk_up
	step_end

# 771 "data/maps/Route111/scripts.pory"
Route111_Movement_MoveUp2:
# 772 "data/maps/Route111/scripts.pory"
	walk_left
# 773 "data/maps/Route111/scripts.pory"
	walk_up
# 773 "data/maps/Route111/scripts.pory"
	walk_up
	step_end

Route111_EventScript_ZinniaDesertMeeting::
# 778 "data/maps/Route111/scripts.pory"
	lockall
# 779 "data/maps/Route111/scripts.pory"
	compare VAR_ZINNIA_EVENTS, 3
	goto_if_eq Route111_EventScript_ZinniaDesertMeeting_2
# 820 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_ZinniaDesertMeeting_Text_3, MSGBOX_DEFAULT
# 822 "data/maps/Route111/scripts.pory"
	releaseall
	end

Route111_EventScript_ZinniaDesertMeeting_2:
# 780 "data/maps/Route111/scripts.pory"
	applymovement 47, Route111_Movement_EmoteSurprised
# 781 "data/maps/Route111/scripts.pory"
	waitmovement
# 782 "data/maps/Route111/scripts.pory"
	faceplayer
# 783 "data/maps/Route111/scripts.pory"
	delay 30
# 784 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_ZinniaDesertMeeting_Text_0, MSGBOX_DEFAULT
# 785 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 786 "data/maps/Route111/scripts.pory"
	waitmoncry
# 787 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_ZinniaDesertMeeting_Text_1
# 788 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_MoveDown
# 789 "data/maps/Route111/scripts.pory"
	applymovement 47, Route111_Movement_MoveDown
# 790 "data/maps/Route111/scripts.pory"
	applymovement 48, Route111_Movement_MoveDown
# 791 "data/maps/Route111/scripts.pory"
	waitmovement
# 792 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 793 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8005, 2
# 794 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8006, 8
# 795 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8007, 5
# 796 "data/maps/Route111/scripts.pory"
	special ShakeCamera
# 797 "data/maps/Route111/scripts.pory"
	waitstate
# 798 "data/maps/Route111/scripts.pory"
	playse SE_SLIDING_DOOR
# 799 "data/maps/Route111/scripts.pory"
	waitse
# 800 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_CaveEntrance_Bottom, FALSE
# 801 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_CaveEntrance_Top, FALSE
# 802 "data/maps/Route111/scripts.pory"
	special DrawWholeMapView
# 803 "data/maps/Route111/scripts.pory"
	delay 30
# 804 "data/maps/Route111/scripts.pory"
	faceplayer
# 805 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_ZinniaDesertMeeting_Text_2, MSGBOX_DEFAULT
# 806 "data/maps/Route111/scripts.pory"
	applymovement 47, Route111_Movement_MoveUp1
# 807 "data/maps/Route111/scripts.pory"
	waitmovement
# 808 "data/maps/Route111/scripts.pory"
	removeobject 47
# 809 "data/maps/Route111/scripts.pory"
	playse SE_DOOR
# 810 "data/maps/Route111/scripts.pory"
	applymovement 48, Route111_Movement_MoveUp2
# 811 "data/maps/Route111/scripts.pory"
	waitmovement
# 812 "data/maps/Route111/scripts.pory"
	removeobject 48
# 813 "data/maps/Route111/scripts.pory"
	playse SE_DOOR
# 814 "data/maps/Route111/scripts.pory"
	special DrawWholeMapView
# 815 "data/maps/Route111/scripts.pory"
	releaseall
	end


Route111_EventScript_WhismurCry1_Text_0:
# 729 "data/maps/Route111/scripts.pory"
	.string "You hear the familiar sound of a\ncertain WHISMUR deep in the desert...\pIt seems to be coming from the south.$"

Route111_EventScript_ZinniaDesertMeeting_Text_0:
# 784 "data/maps/Route111/scripts.pory"
	.string "ZINNIA: Oh, hey! It's you!\p.........\pI just realized I never asked for\nfor your name...\p...{PLAYER}, huh?$"

Route111_EventScript_ZinniaDesertMeeting_Text_1:
# 787 "data/maps/Route111/scripts.pory"
	.string "ZINNIA: Well, {PLAYER}, you came at\nthe perfect time!$"

Route111_EventScript_ZinniaDesertMeeting_Text_2:
# 805 "data/maps/Route111/scripts.pory"
	.string "What do you think? Pretty cool\nright? Come on in!$"

Route111_EventScript_ZinniaDesertMeeting_Text_3:
# 820 "data/maps/Route111/scripts.pory"
	.string ".........$"
