# 1 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_MapScripts::
# 2 "data/maps/VerdanturfTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
# 3 "data/maps/VerdanturfTown/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown/scripts.pory"

# 5 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_OnTransition:
# 6 "data/maps/VerdanturfTown/scripts.pory"
	setflag FLAG_VISITED_VERDANTURF_TOWN
# 7 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 8 "data/maps/VerdanturfTown/scripts.pory"
	end
# 9 "data/maps/VerdanturfTown/scripts.pory"

# 10 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Twin::
# 11 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 12 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 13 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
# 14 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
# 15 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
# 16 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 17 "data/maps/VerdanturfTown/scripts.pory"
	release
# 18 "data/maps/VerdanturfTown/scripts.pory"
	end
# 19 "data/maps/VerdanturfTown/scripts.pory"

# 20 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TwinTunnelOpen::
# 21 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
# 22 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
# 23 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 24 "data/maps/VerdanturfTown/scripts.pory"
	release
# 25 "data/maps/VerdanturfTown/scripts.pory"
	end
# 26 "data/maps/VerdanturfTown/scripts.pory"

# 27 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Man::
# 28 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
# 29 "data/maps/VerdanturfTown/scripts.pory"
	end
# 30 "data/maps/VerdanturfTown/scripts.pory"

# 31 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Camper::
# 32 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
# 33 "data/maps/VerdanturfTown/scripts.pory"
	end
# 34 "data/maps/VerdanturfTown/scripts.pory"

# 35 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Boy::
# 36 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 37 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 38 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
# 39 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
# 40 "data/maps/VerdanturfTown/scripts.pory"
	release
# 41 "data/maps/VerdanturfTown/scripts.pory"
	end
# 42 "data/maps/VerdanturfTown/scripts.pory"

# 43 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BoyTunnelOpen::
# 44 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
# 45 "data/maps/VerdanturfTown/scripts.pory"
	release
# 46 "data/maps/VerdanturfTown/scripts.pory"
	end
# 47 "data/maps/VerdanturfTown/scripts.pory"

# 48 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TownSign::
# 49 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
# 50 "data/maps/VerdanturfTown/scripts.pory"
	end
# 51 "data/maps/VerdanturfTown/scripts.pory"

# 52 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_WandasHouseSign::
# 53 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
# 54 "data/maps/VerdanturfTown/scripts.pory"
	end
# 55 "data/maps/VerdanturfTown/scripts.pory"

# 56 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BattleTentSign::
# 57 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
# 58 "data/maps/VerdanturfTown/scripts.pory"
	end
# 59 "data/maps/VerdanturfTown/scripts.pory"

# 60 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_RusturfTunnelSign::
# 61 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
# 62 "data/maps/VerdanturfTown/scripts.pory"
	end
# 63 "data/maps/VerdanturfTown/scripts.pory"

# 64 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManTryingToDigTunnel:
# 65 "data/maps/VerdanturfTown/scripts.pory"
	.string "My papa told me.\p"
# 66 "data/maps/VerdanturfTown/scripts.pory"
	.string "He says this tunnel is full of\n"
# 67 "data/maps/VerdanturfTown/scripts.pory"
	.string "timid POKéMON.\p"
# 68 "data/maps/VerdanturfTown/scripts.pory"
	.string "They get all scared of loud noise and\n"
# 69 "data/maps/VerdanturfTown/scripts.pory"
	.string "make a big uproar.\p"
# 70 "data/maps/VerdanturfTown/scripts.pory"
	.string "So they had to stop the big tunnel\n"
# 71 "data/maps/VerdanturfTown/scripts.pory"
	.string "project.\p"
# 72 "data/maps/VerdanturfTown/scripts.pory"
	.string "But there's one man. He's trying to dig\n"
# 73 "data/maps/VerdanturfTown/scripts.pory"
	.string "the tunnel by himself!$"
# 74 "data/maps/VerdanturfTown/scripts.pory"

# 75 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManDugTunnelForLove:
# 76 "data/maps/VerdanturfTown/scripts.pory"
	.string "There was a man who dug a tunnel for\n"
# 77 "data/maps/VerdanturfTown/scripts.pory"
	.string "a lady he loved.\p"
# 78 "data/maps/VerdanturfTown/scripts.pory"
	.string "I don't really get it, but hey!$"
# 79 "data/maps/VerdanturfTown/scripts.pory"

# 80 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_AirCleanHere:
# 81 "data/maps/VerdanturfTown/scripts.pory"
	.string "The way the winds blow, volcanic ash\n"
# 82 "data/maps/VerdanturfTown/scripts.pory"
	.string "is never blown in this direction.\p"
# 83 "data/maps/VerdanturfTown/scripts.pory"
	.string "The air is clean and delicious here.\n"
# 84 "data/maps/VerdanturfTown/scripts.pory"
	.string "Living here should do wonders for even\l"
# 85 "data/maps/VerdanturfTown/scripts.pory"
	.string "frail and sickly people.$"
# 86 "data/maps/VerdanturfTown/scripts.pory"

# 87 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_MakeBattleTentDebut:
# 88 "data/maps/VerdanturfTown/scripts.pory"
	.string "My POKéMON and I, we've been riding\n"
# 89 "data/maps/VerdanturfTown/scripts.pory"
	.string "a hot winning streak.\p"
# 90 "data/maps/VerdanturfTown/scripts.pory"
	.string "So I decided to make my BATTLE TENT\n"
# 91 "data/maps/VerdanturfTown/scripts.pory"
	.string "debut in this town.$"
# 92 "data/maps/VerdanturfTown/scripts.pory"

# 93 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_GuyTryingToBustThroughCave:
# 94 "data/maps/VerdanturfTown/scripts.pory"
	.string "Did you see the cave next to the\n"
# 95 "data/maps/VerdanturfTown/scripts.pory"
	.string "POKéMON MART?\p"
# 96 "data/maps/VerdanturfTown/scripts.pory"
	.string "There's a guy in there who's trying to\n"
# 97 "data/maps/VerdanturfTown/scripts.pory"
	.string "bust up boulders so he can bust out\l"
# 98 "data/maps/VerdanturfTown/scripts.pory"
	.string "through to the other side.\p"
# 99 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'd be great if we could go through…\n"
# 100 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'll make it easy to visit RUSTBORO.$"
# 101 "data/maps/VerdanturfTown/scripts.pory"

# 102 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_EasyToGetToRustboroNow:
# 103 "data/maps/VerdanturfTown/scripts.pory"
	.string "That cave next to the POKéMON MART\n"
# 104 "data/maps/VerdanturfTown/scripts.pory"
	.string "is now a tunnel to the other side.\p"
# 105 "data/maps/VerdanturfTown/scripts.pory"
	.string "It's great--it's easy to go shop for\n"
# 106 "data/maps/VerdanturfTown/scripts.pory"
	.string "new DEVON products in RUSTBORO now.$"
# 107 "data/maps/VerdanturfTown/scripts.pory"

# 108 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_TownSign:
# 109 "data/maps/VerdanturfTown/scripts.pory"
	.string "VERDANTURF TOWN\p"
# 110 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The windswept highlands with the\n"
# 111 "data/maps/VerdanturfTown/scripts.pory"
	.string "sweet fragrance of grass.”$"
# 112 "data/maps/VerdanturfTown/scripts.pory"

# 113 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_WandasHouse:
# 114 "data/maps/VerdanturfTown/scripts.pory"
	.string "WANDA'S HOUSE$"
# 115 "data/maps/VerdanturfTown/scripts.pory"

# 116 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_BattleTentSign:
# 117 "data/maps/VerdanturfTown/scripts.pory"
	.string "BATTLE TENT VERDANTURF SITE\n"
# 118 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Feast Your Eyes on Battles!”$"
# 119 "data/maps/VerdanturfTown/scripts.pory"

# 120 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_RusturfTunnelSign:
# 121 "data/maps/VerdanturfTown/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 122 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 123 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The tunnel project has been\n"
# 124 "data/maps/VerdanturfTown/scripts.pory"
	.string "canceled.”$"

VerdanturfTown_EventScript_Trigger1::
# 129 "data/maps/VerdanturfTown/scripts.pory"
	lockall
# 130 "data/maps/VerdanturfTown/scripts.pory"
	addobject 6
# 131 "data/maps/VerdanturfTown/scripts.pory"
	addobject 5
# 132 "data/maps/VerdanturfTown/scripts.pory"
	addobject 7
# 133 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_VerdanturfTown_Trigger1
# 134 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 135 "data/maps/VerdanturfTown/scripts.pory"
	call VerdanturfTown_EventScript_ZinniaGrunt
	return


VerdanturfTown_EventScript_Trigger2::
# 139 "data/maps/VerdanturfTown/scripts.pory"
	lockall
# 140 "data/maps/VerdanturfTown/scripts.pory"
	addobject 6
# 141 "data/maps/VerdanturfTown/scripts.pory"
	addobject 5
# 142 "data/maps/VerdanturfTown/scripts.pory"
	addobject 7
# 143 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_VerdanturfTown_Trigger2
# 144 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 145 "data/maps/VerdanturfTown/scripts.pory"
	call VerdanturfTown_EventScript_ZinniaGrunt
	return


VerdanturfTown_EventScript_Trigger3::
# 149 "data/maps/VerdanturfTown/scripts.pory"
	lockall
# 150 "data/maps/VerdanturfTown/scripts.pory"
	addobject 6
# 151 "data/maps/VerdanturfTown/scripts.pory"
	addobject 5
# 152 "data/maps/VerdanturfTown/scripts.pory"
	addobject 7
# 153 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_VerdanturfTown_Trigger3
# 154 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 155 "data/maps/VerdanturfTown/scripts.pory"
	call VerdanturfTown_EventScript_ZinniaGrunt
	return


VerdanturfTown_EventScript_Trigger4::
# 159 "data/maps/VerdanturfTown/scripts.pory"
	lockall
# 160 "data/maps/VerdanturfTown/scripts.pory"
	addobject 6
# 161 "data/maps/VerdanturfTown/scripts.pory"
	addobject 5
# 162 "data/maps/VerdanturfTown/scripts.pory"
	addobject 7
# 163 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_VerdanturfTown_Trigger4
# 164 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 165 "data/maps/VerdanturfTown/scripts.pory"
	call VerdanturfTown_EventScript_ZinniaGrunt
	return


VerdanturfTown_EventScript_Trigger5::
# 169 "data/maps/VerdanturfTown/scripts.pory"
	lockall
# 170 "data/maps/VerdanturfTown/scripts.pory"
	addobject 6
# 171 "data/maps/VerdanturfTown/scripts.pory"
	addobject 5
# 172 "data/maps/VerdanturfTown/scripts.pory"
	addobject 7
# 173 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_VerdanturfTown_Trigger5
# 174 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 175 "data/maps/VerdanturfTown/scripts.pory"
	call VerdanturfTown_EventScript_ZinniaGrunt
	return


# 178 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_Trigger1:
# 179 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 180 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 180 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
	step_end

# 183 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_Trigger2:
# 184 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 184 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
	step_end

# 187 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_Trigger3:
# 188 "data/maps/VerdanturfTown/scripts.pory"
	walk_up
# 189 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 189 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
	step_end

# 192 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_Trigger4:
# 193 "data/maps/VerdanturfTown/scripts.pory"
	walk_up
# 193 "data/maps/VerdanturfTown/scripts.pory"
	walk_up
# 194 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 194 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
	step_end

# 197 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_Trigger5:
# 198 "data/maps/VerdanturfTown/scripts.pory"
	walk_up
# 198 "data/maps/VerdanturfTown/scripts.pory"
	walk_up
# 198 "data/maps/VerdanturfTown/scripts.pory"
	walk_up
# 199 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 199 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
	step_end

# 202 "data/maps/VerdanturfTown/scripts.pory"
Movement_Verdanturf_Camera:
# 203 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 203 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
# 203 "data/maps/VerdanturfTown/scripts.pory"
	walk_left
	step_end

# 206 "data/maps/VerdanturfTown/scripts.pory"
Movement_Verdantuf_ResetCamera:
# 207 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 207 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 207 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
	step_end

VerdanturfTown_EventScript_ZinniaGrunt::
# 211 "data/maps/VerdanturfTown/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 212 "data/maps/VerdanturfTown/scripts.pory"
	special SpawnCameraObject
# 213 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Movement_Verdanturf_Camera
# 214 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 215 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 6, Movement_Verdanturf_Jump
# 216 "data/maps/VerdanturfTown/scripts.pory"
	playse SE_LEDGE
# 217 "data/maps/VerdanturfTown/scripts.pory"
	waitse
# 218 "data/maps/VerdanturfTown/scripts.pory"
	playse SE_LEDGE
# 219 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 220 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_0
# 221 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_1
# 222 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_2
# 223 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_3
# 224 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_4
# 225 "data/maps/VerdanturfTown/scripts.pory"
	playse SE_PIN
# 226 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 6, Movement_MauvilleCity_Exclamation
# 227 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 228 "data/maps/VerdanturfTown/scripts.pory"
	turnobject 6, DIR_EAST
# 229 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_5
# 230 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 5, Movement_VerdanturfTown_ZinniaEscape
# 231 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 7, Movement_VerdanturfTown_WhismurEscape
# 232 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_6
# 233 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 234 "data/maps/VerdanturfTown/scripts.pory"
	playse SE_PIN
# 235 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 6, Movement_MauvilleCity_Exclamation
# 236 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 237 "data/maps/VerdanturfTown/scripts.pory"
	turnobject 6, DIR_WEST
# 238 "data/maps/VerdanturfTown/scripts.pory"
	delay 30
# 239 "data/maps/VerdanturfTown/scripts.pory"
	turnobject 6, DIR_NORTH
# 240 "data/maps/VerdanturfTown/scripts.pory"
	delay 30
# 241 "data/maps/VerdanturfTown/scripts.pory"
	turnobject 6, DIR_SOUTH
# 242 "data/maps/VerdanturfTown/scripts.pory"
	delay 30
# 243 "data/maps/VerdanturfTown/scripts.pory"
	turnobject 6, DIR_WEST
# 244 "data/maps/VerdanturfTown/scripts.pory"
	delay 30
# 245 "data/maps/VerdanturfTown/scripts.pory"
	turnobject 6, DIR_EAST
# 246 "data/maps/VerdanturfTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Movement_Verdantuf_ResetCamera
# 247 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_7
# 248 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 249 "data/maps/VerdanturfTown/scripts.pory"
	special RemoveCameraObject
# 250 "data/maps/VerdanturfTown/scripts.pory"
	trainerbattle_no_intro TRAINER_AQUA_GRUNT_VERDANTURF, GruntVerdanturfPostBattle
# 251 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaGrunt_Text_8
# 252 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 6, Movement_VerdanturfTown_AquaEscape
# 253 "data/maps/VerdanturfTown/scripts.pory"
	fadedefaultbgm
# 254 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 255 "data/maps/VerdanturfTown/scripts.pory"
	removeobject 6
# 256 "data/maps/VerdanturfTown/scripts.pory"
	call VerdanturfTown_EventScript_ZinniaMeeting
	return


# 259 "data/maps/VerdanturfTown/scripts.pory"
Movement_Verdanturf_Jump:
# 260 "data/maps/VerdanturfTown/scripts.pory"
	jump_in_place_left
# 261 "data/maps/VerdanturfTown/scripts.pory"
	jump_in_place_left
	step_end

# 264 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_ZinniaEscape:
# 265 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 265 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 265 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 265 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 265 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 266 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 266 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 266 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 266 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 266 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 266 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
	step_end

# 269 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_WhismurEscape:
# 270 "data/maps/VerdanturfTown/scripts.pory"
	walk_in_place_fast_right
# 270 "data/maps/VerdanturfTown/scripts.pory"
	walk_in_place_fast_right
# 271 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 271 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 271 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 271 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_left
# 272 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 272 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 272 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 272 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 272 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
# 272 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_up
	step_end

# 275 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_AquaEscape:
# 276 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 277 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_down
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
# 278 "data/maps/VerdanturfTown/scripts.pory"
	walk_fast_right
	step_end

# 281 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_ZinniaReturn:
# 282 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 282 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 282 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 282 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 282 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 282 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 283 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
	step_end

# 286 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_WhismurReturn:
# 287 "data/maps/VerdanturfTown/scripts.pory"
	walk_in_place_down
# 288 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 288 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 288 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 288 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 288 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 288 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 289 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
	step_end

VerdanturfTown_EventScript_ZinniaMeeting::
# 297 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 7, Movement_VerdanturfTown_WhismurReturn
# 298 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 5, Movement_VerdanturfTown_ZinniaReturn
# 299 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 300 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaMeeting_Text_0
# 301 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 7, Movement_VerdanturfTown_WhismurEmote
# 302 "data/maps/VerdanturfTown/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 303 "data/maps/VerdanturfTown/scripts.pory"
	waitmoncry
# 304 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaMeeting_Text_1
# 305 "data/maps/VerdanturfTown/scripts.pory"
	playse SE_CLICK
# 306 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaMeeting_Text_2
# 307 "data/maps/VerdanturfTown/scripts.pory"
	giveitem ITEM_MEGA_RING
# 308 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_EventScript_ZinniaMeeting_Text_3
# 309 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 5, Movement_VerdanturfTown_ZinniaLeave
# 310 "data/maps/VerdanturfTown/scripts.pory"
	applymovement 7, Movement_VerdanturfTown_WhismurLeave
# 311 "data/maps/VerdanturfTown/scripts.pory"
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
# 312 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement
# 313 "data/maps/VerdanturfTown/scripts.pory"
	removeobject 5
# 314 "data/maps/VerdanturfTown/scripts.pory"
	removeobject 7
# 315 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_ZINNIA_EVENTS, 3
# 316 "data/maps/VerdanturfTown/scripts.pory"
	releaseall
	end


# 320 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_WhismurEmote:
# 321 "data/maps/VerdanturfTown/scripts.pory"
	emote_heart
	step_end

# 324 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_ZinniaLeave:
# 325 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 326 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
	step_end

# 329 "data/maps/VerdanturfTown/scripts.pory"
Movement_VerdanturfTown_WhismurLeave:
# 330 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 331 "data/maps/VerdanturfTown/scripts.pory"
	walk_down
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
# 332 "data/maps/VerdanturfTown/scripts.pory"
	walk_right
	step_end

VerdanturfTown_EventScript_ZinniaGrunt_Text_0:
# 220 "data/maps/VerdanturfTown/scripts.pory"
	.string "AQUA GRUNT: Lady! Your Whismur stole my\n"
	.string "stone!$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_1:
# 221 "data/maps/VerdanturfTown/scripts.pory"
	.string "???: My little Aster? She would never do\n"
	.string "such a thing!$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_2:
# 222 "data/maps/VerdanturfTown/scripts.pory"
	.string "AQUA GRUNT: Don't mess with TEAM AQUA!\n"
	.string "If I don't get that stone back...$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_3:
# 223 "data/maps/VerdanturfTown/scripts.pory"
	.string "???: Sounds like a you problem. And I\n"
	.string "don't like the way you called me 'lady'\l"
	.string "before...$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_4:
# 224 "data/maps/VerdanturfTown/scripts.pory"
	.string "AQUA GRUNT: What then, Mister?! Just\n"
	.string "gimme the--$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_5:
# 229 "data/maps/VerdanturfTown/scripts.pory"
	.string "Hey, you! This is a private matter.$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_6:
# 232 "data/maps/VerdanturfTown/scripts.pory"
	.string "You better scram if you--$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_7:
# 247 "data/maps/VerdanturfTown/scripts.pory"
	.string "AQUA GRUNT: YOU--!!!$"

VerdanturfTown_EventScript_ZinniaGrunt_Text_8:
# 251 "data/maps/VerdanturfTown/scripts.pory"
	.string "AQUA GRUNT: Tch, you get away this time,\n"
	.string "but when HOENN's underwater you'll wish\l"
	.string "you didn't cross TEAM AQUA.$"

VerdanturfTown_EventScript_ZinniaMeeting_Text_0:
# 300 "data/maps/VerdanturfTown/scripts.pory"
	.string "???: Hey, you, thanks for distracting\nthat guy for me.\pYou didn't get hurt or anything?\pYou're pretty strong, you know.\nI saw you in Petalburg Woods.\pMy name is Zinnia. This is my\nsweet and adorable Whismur Aster.$"

VerdanturfTown_EventScript_ZinniaMeeting_Text_1:
# 304 "data/maps/VerdanturfTown/scripts.pory"
	.string "ZINNIA: Actually, if you don't mind,\nI could use your help.\pThat stone he was talking about...\nI was looking for it in METEOR FALLS\lwhen TEAM AQUA got to it before me.\pCould you do me a favor and take it\nwith you?\pI need it at full power, and to get\nit there, it needs to be used.\pI have an extra armband, so if\nI just...$"

VerdanturfTown_EventScript_ZinniaMeeting_Text_2:
# 306 "data/maps/VerdanturfTown/scripts.pory"
	.string "--CLICK--\pZINNIA: There we go. Here, I'm sure\nit'll come in handy for you.$"

VerdanturfTown_EventScript_ZinniaMeeting_Text_3:
# 308 "data/maps/VerdanturfTown/scripts.pory"
	.string "ZINNIA: This will let you unleash\nyour POKéMON's full potential.\pI hope you'll find it useful. I'll\nseek you out again in the near future.\pSo, until next time!$"

GruntVerdanturfPostBattle::
# 292 "data/maps/VerdanturfTown/scripts.pory"
	.string "AQUA GRUNT: Archie's gonna\nkill me...$"
