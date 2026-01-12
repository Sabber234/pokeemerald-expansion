# 1 "data/maps/SlateportCity/scripts.pory"
SlateportCity_MapScripts::
# 2 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
# 3 "data/maps/SlateportCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
# 4 "data/maps/SlateportCity/scripts.pory"
	.byte 0
# 5 "data/maps/SlateportCity/scripts.pory"

# 6 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnTransition:
# 7 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
# 8 "data/maps/SlateportCity/scripts.pory"
	call SlateportCity_EventScript_EnterSlateport
# 9 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
# 10 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
# 11 "data/maps/SlateportCity/scripts.pory"
	end
# 12 "data/maps/SlateportCity/scripts.pory"

# 13 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnterSlateport::
# 14 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_VISITED_SLATEPORT_CITY
# 15 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 16 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
# 17 "data/maps/SlateportCity/scripts.pory"
	return
# 18 "data/maps/SlateportCity/scripts.pory"

# 19 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MovePeopleForSternInterview::
# 20 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
# 21 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
# 22 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
# 23 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
# 24 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
# 25 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
# 26 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
# 27 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
# 28 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 29 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
# 30 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
# 31 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
# 32 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
# 33 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
# 34 "data/maps/SlateportCity/scripts.pory"
	return
# 35 "data/maps/SlateportCity/scripts.pory"

# 36 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SetReadyForScottScene::
# 37 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 38 "data/maps/SlateportCity/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 39 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
# 40 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
# 41 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 42 "data/maps/SlateportCity/scripts.pory"
	return
# 43 "data/maps/SlateportCity/scripts.pory"

# 44 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MoveScottLeft::
# 45 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
# 46 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
# 47 "data/maps/SlateportCity/scripts.pory"
	return
# 48 "data/maps/SlateportCity/scripts.pory"

# 49 "data/maps/SlateportCity/scripts.pory"
SlateportCity_OnFrame:
# 50 "data/maps/SlateportCity/scripts.pory"
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
# 51 "data/maps/SlateportCity/scripts.pory"
	.2byte 0
# 52 "data/maps/SlateportCity/scripts.pory"

# 53 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottScene::
# 54 "data/maps/SlateportCity/scripts.pory"
	lockall
# 55 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SLATEPORT_SCOTT
# 56 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
# 57 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
# 58 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 59 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
# 60 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 61 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
# 62 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 63 "data/maps/SlateportCity/scripts.pory"
	delay 60
# 64 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
# 65 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
# 66 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 67 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
# 68 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 69 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 70 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 71 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
# 72 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 73 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 74 "data/maps/SlateportCity/scripts.pory"
	delay 30
# 75 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
# 76 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
# 77 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 78 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
# 79 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 80 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_SCOTT
# 81 "data/maps/SlateportCity/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
# 82 "data/maps/SlateportCity/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
# 83 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 84 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
# 85 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 86 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 87 "data/maps/SlateportCity/scripts.pory"
	end
# 88 "data/maps/SlateportCity/scripts.pory"

# 89 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceScott:
# 90 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 91 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 92 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 93 "data/maps/SlateportCity/scripts.pory"
	step_end
# 94 "data/maps/SlateportCity/scripts.pory"

# 95 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottApproachPlayer:
# 96 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 97 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 98 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 99 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 100 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 101 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 102 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 103 "data/maps/SlateportCity/scripts.pory"
	step_end
# 104 "data/maps/SlateportCity/scripts.pory"

# 105 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExit:
# 106 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 107 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 108 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 109 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 110 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 111 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 112 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 113 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 114 "data/maps/SlateportCity/scripts.pory"
	step_end
# 115 "data/maps/SlateportCity/scripts.pory"

# 116 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyGuru::
# 117 "data/maps/SlateportCity/scripts.pory"
	lock
# 118 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 119 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
# 120 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 121 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EnergyGuru
# 122 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 123 "data/maps/SlateportCity/scripts.pory"
	release
# 124 "data/maps/SlateportCity/scripts.pory"
	end
# 125 "data/maps/SlateportCity/scripts.pory"

# 126 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 127 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EnergyGuru:
# 128 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTEIN
# 129 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_IRON
# 130 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CARBOS
# 131 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ZINC
# 132 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CALCIUM
# 133 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_HP_UP
# 134 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 135 "data/maps/SlateportCity/scripts.pory"

# 136 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EffortRibbonWoman::
# 137 "data/maps/SlateportCity/scripts.pory"
	lock
# 138 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 139 "data/maps/SlateportCity/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 140 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
# 141 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
# 142 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
# 143 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
# 144 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
# 145 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
# 146 "data/maps/SlateportCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 147 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ReceivedEffortRibbon
# 148 "data/maps/SlateportCity/scripts.pory"
	waitfanfare
# 149 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
# 150 "data/maps/SlateportCity/scripts.pory"
	special GiveLeadMonEffortRibbon
# 151 "data/maps/SlateportCity/scripts.pory"
	release
# 152 "data/maps/SlateportCity/scripts.pory"
	end
# 153 "data/maps/SlateportCity/scripts.pory"

# 154 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonEVsNotMaxed::
# 155 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
# 156 "data/maps/SlateportCity/scripts.pory"
	release
# 157 "data/maps/SlateportCity/scripts.pory"
	end
# 158 "data/maps/SlateportCity/scripts.pory"

# 159 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MonHasEffortRibbon::
# 160 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
# 161 "data/maps/SlateportCity/scripts.pory"
	release
# 162 "data/maps/SlateportCity/scripts.pory"
	end
# 163 "data/maps/SlateportCity/scripts.pory"

# 164 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Cook::
# 165 "data/maps/SlateportCity/scripts.pory"
	lock
# 166 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 167 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
# 168 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
# 169 "data/maps/SlateportCity/scripts.pory"
	release
# 170 "data/maps/SlateportCity/scripts.pory"
	end
# 171 "data/maps/SlateportCity/scripts.pory"

# 172 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CookSternInterview::
# 173 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
# 174 "data/maps/SlateportCity/scripts.pory"
	release
# 175 "data/maps/SlateportCity/scripts.pory"
	end
# 176 "data/maps/SlateportCity/scripts.pory"

# 177 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWoman::
# 178 "data/maps/SlateportCity/scripts.pory"
	lock
# 179 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 180 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
# 181 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
# 182 "data/maps/SlateportCity/scripts.pory"
	release
# 183 "data/maps/SlateportCity/scripts.pory"
	end
# 184 "data/maps/SlateportCity/scripts.pory"

# 185 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OldWomanSternInterview::
# 186 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
# 187 "data/maps/SlateportCity/scripts.pory"
	release
# 188 "data/maps/SlateportCity/scripts.pory"
	end
# 189 "data/maps/SlateportCity/scripts.pory"

# 190 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Girl::
# 191 "data/maps/SlateportCity/scripts.pory"
	lock
# 192 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 193 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
# 194 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
# 195 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
# 196 "data/maps/SlateportCity/scripts.pory"
	release
# 197 "data/maps/SlateportCity/scripts.pory"
	end
# 198 "data/maps/SlateportCity/scripts.pory"

# 199 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSternInterview::
# 200 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
# 201 "data/maps/SlateportCity/scripts.pory"
	release
# 202 "data/maps/SlateportCity/scripts.pory"
	end
# 203 "data/maps/SlateportCity/scripts.pory"

# 204 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_GirlSecretBase::
# 205 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
# 206 "data/maps/SlateportCity/scripts.pory"
	release
# 207 "data/maps/SlateportCity/scripts.pory"
	end
# 208 "data/maps/SlateportCity/scripts.pory"

# 209 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoy::
# 210 "data/maps/SlateportCity/scripts.pory"
	lock
# 211 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 212 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
# 213 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
# 214 "data/maps/SlateportCity/scripts.pory"
	release
# 215 "data/maps/SlateportCity/scripts.pory"
	end
# 216 "data/maps/SlateportCity/scripts.pory"

# 217 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RichBoySternInterview::
# 218 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
# 219 "data/maps/SlateportCity/scripts.pory"
	release
# 220 "data/maps/SlateportCity/scripts.pory"
	end
# 221 "data/maps/SlateportCity/scripts.pory"

# 222 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatMan::
# 223 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
# 224 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
# 225 "data/maps/SlateportCity/scripts.pory"
	end
# 226 "data/maps/SlateportCity/scripts.pory"

# 227 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_FatManSternInterview::
# 228 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
# 229 "data/maps/SlateportCity/scripts.pory"
	end
# 230 "data/maps/SlateportCity/scripts.pory"

# 231 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1::
# 232 "data/maps/SlateportCity/scripts.pory"
	lock
# 233 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 234 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
# 235 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
# 236 "data/maps/SlateportCity/scripts.pory"
	release
# 237 "data/maps/SlateportCity/scripts.pory"
	end
# 238 "data/maps/SlateportCity/scripts.pory"

# 239 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man1SternInterview::
# 240 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
# 241 "data/maps/SlateportCity/scripts.pory"
	release
# 242 "data/maps/SlateportCity/scripts.pory"
	end
# 243 "data/maps/SlateportCity/scripts.pory"

# 244 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1::
# 245 "data/maps/SlateportCity/scripts.pory"
	lock
# 246 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 247 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
# 248 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
# 249 "data/maps/SlateportCity/scripts.pory"
	release
# 250 "data/maps/SlateportCity/scripts.pory"
	end
# 251 "data/maps/SlateportCity/scripts.pory"

# 252 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman1AquaGone::
# 253 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
# 254 "data/maps/SlateportCity/scripts.pory"
	release
# 255 "data/maps/SlateportCity/scripts.pory"
	end
# 256 "data/maps/SlateportCity/scripts.pory"

# 257 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BattleTentSign::
# 258 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
# 259 "data/maps/SlateportCity/scripts.pory"
	end
# 260 "data/maps/SlateportCity/scripts.pory"

# 261 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardSign::
# 262 "data/maps/SlateportCity/scripts.pory"
	lockall
# 263 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
# 264 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
# 265 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
# 266 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 267 "data/maps/SlateportCity/scripts.pory"
	end
# 268 "data/maps/SlateportCity/scripts.pory"

# 269 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardNearsCompletion::
# 270 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
# 271 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 272 "data/maps/SlateportCity/scripts.pory"
	end
# 273 "data/maps/SlateportCity/scripts.pory"

# 274 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_SternsShipyardFerryComplete::
# 275 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
# 276 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 277 "data/maps/SlateportCity/scripts.pory"
	end
# 278 "data/maps/SlateportCity/scripts.pory"

# 279 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokemonFanClubSign::
# 280 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 281 "data/maps/SlateportCity/scripts.pory"
	end
# 282 "data/maps/SlateportCity/scripts.pory"

# 283 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_OceanicMuseumSign::
# 284 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
# 285 "data/maps/SlateportCity/scripts.pory"
	end
# 286 "data/maps/SlateportCity/scripts.pory"

# 287 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CitySign::
# 288 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
# 289 "data/maps/SlateportCity/scripts.pory"
	end
# 290 "data/maps/SlateportCity/scripts.pory"

# 291 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_MarketSign::
# 292 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
# 293 "data/maps/SlateportCity/scripts.pory"
	end
# 294 "data/maps/SlateportCity/scripts.pory"

# 295 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSign::
# 296 "data/maps/SlateportCity/scripts.pory"
	lockall
# 297 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
# 298 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
# 299 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 300 "data/maps/SlateportCity/scripts.pory"
	end
# 301 "data/maps/SlateportCity/scripts.pory"

# 302 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HarborSignFerryComplete::
# 303 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
# 304 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 305 "data/maps/SlateportCity/scripts.pory"
	end
# 306 "data/maps/SlateportCity/scripts.pory"

# 307 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NameRatersHouseSign::
# 308 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
# 309 "data/maps/SlateportCity/scripts.pory"
	end
# 310 "data/maps/SlateportCity/scripts.pory"

# 311 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Maniac::
# 312 "data/maps/SlateportCity/scripts.pory"
	lock
# 313 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 314 "data/maps/SlateportCity/scripts.pory"
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
# 315 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 316 "data/maps/SlateportCity/scripts.pory"
	release
# 317 "data/maps/SlateportCity/scripts.pory"
	end
# 318 "data/maps/SlateportCity/scripts.pory"

# 319 "data/maps/SlateportCity/scripts.pory"
@ Unclear if the text here was meant to be different, but its not
# 320 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ManiacSternInterview::
# 321 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
# 322 "data/maps/SlateportCity/scripts.pory"
	release
# 323 "data/maps/SlateportCity/scripts.pory"
	end
# 324 "data/maps/SlateportCity/scripts.pory"

# 325 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Woman2::
# 326 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
# 327 "data/maps/SlateportCity/scripts.pory"
	end
# 328 "data/maps/SlateportCity/scripts.pory"

# 329 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor1::
# 330 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
# 331 "data/maps/SlateportCity/scripts.pory"
	end
# 332 "data/maps/SlateportCity/scripts.pory"

# 333 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Sailor2::
# 334 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
# 335 "data/maps/SlateportCity/scripts.pory"
	end
# 336 "data/maps/SlateportCity/scripts.pory"

# 337 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PokefanF::
# 338 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
# 339 "data/maps/SlateportCity/scripts.pory"
	end
# 340 "data/maps/SlateportCity/scripts.pory"

# 341 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man2::
# 342 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
# 343 "data/maps/SlateportCity/scripts.pory"
	end
# 344 "data/maps/SlateportCity/scripts.pory"

# 345 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt1::
# 346 "data/maps/SlateportCity/scripts.pory"
	lock
# 347 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 348 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
# 349 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 350 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
# 351 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 352 "data/maps/SlateportCity/scripts.pory"
	release
# 353 "data/maps/SlateportCity/scripts.pory"
	end
# 354 "data/maps/SlateportCity/scripts.pory"

# 355 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt2::
# 356 "data/maps/SlateportCity/scripts.pory"
	lock
# 357 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 358 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
# 359 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 360 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
# 361 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 362 "data/maps/SlateportCity/scripts.pory"
	release
# 363 "data/maps/SlateportCity/scripts.pory"
	end
# 364 "data/maps/SlateportCity/scripts.pory"

# 365 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt3::
# 366 "data/maps/SlateportCity/scripts.pory"
	lock
# 367 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 368 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
# 369 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 370 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
# 371 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 372 "data/maps/SlateportCity/scripts.pory"
	release
# 373 "data/maps/SlateportCity/scripts.pory"
	end
# 374 "data/maps/SlateportCity/scripts.pory"

# 375 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt4::
# 376 "data/maps/SlateportCity/scripts.pory"
	lock
# 377 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 378 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
# 379 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 380 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
# 381 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 382 "data/maps/SlateportCity/scripts.pory"
	release
# 383 "data/maps/SlateportCity/scripts.pory"
	end
# 384 "data/maps/SlateportCity/scripts.pory"

# 385 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt5::
# 386 "data/maps/SlateportCity/scripts.pory"
	lock
# 387 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 388 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
# 389 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 390 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
# 391 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 392 "data/maps/SlateportCity/scripts.pory"
	release
# 393 "data/maps/SlateportCity/scripts.pory"
	end
# 394 "data/maps/SlateportCity/scripts.pory"

# 395 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt6::
# 396 "data/maps/SlateportCity/scripts.pory"
	lock
# 397 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 398 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
# 399 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 400 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
# 401 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 402 "data/maps/SlateportCity/scripts.pory"
	release
# 403 "data/maps/SlateportCity/scripts.pory"
	end
# 404 "data/maps/SlateportCity/scripts.pory"

# 405 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt7::
# 406 "data/maps/SlateportCity/scripts.pory"
	lock
# 407 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 408 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
# 409 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 410 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
# 411 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 412 "data/maps/SlateportCity/scripts.pory"
	release
# 413 "data/maps/SlateportCity/scripts.pory"
	end
# 414 "data/maps/SlateportCity/scripts.pory"

# 415 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt8::
# 416 "data/maps/SlateportCity/scripts.pory"
	lock
# 417 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 418 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
# 419 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 420 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
# 421 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 422 "data/maps/SlateportCity/scripts.pory"
	release
# 423 "data/maps/SlateportCity/scripts.pory"
	end
# 424 "data/maps/SlateportCity/scripts.pory"

# 425 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt9::
# 426 "data/maps/SlateportCity/scripts.pory"
	lock
# 427 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 428 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 429 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
# 430 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 431 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
# 432 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 433 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
# 434 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 435 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 436 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 437 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 438 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 439 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
# 440 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 441 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
# 442 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 443 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 444 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 445 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 446 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 447 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
# 448 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 449 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
# 450 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 451 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
# 452 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 453 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
# 454 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 455 "data/maps/SlateportCity/scripts.pory"
	release
# 456 "data/maps/SlateportCity/scripts.pory"
	end
# 457 "data/maps/SlateportCity/scripts.pory"

# 458 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_DelayAquaGrunt:
# 459 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 460 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 461 "data/maps/SlateportCity/scripts.pory"
	step_end
# 462 "data/maps/SlateportCity/scripts.pory"

# 463 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt10::
# 464 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
# 465 "data/maps/SlateportCity/scripts.pory"
	end
# 466 "data/maps/SlateportCity/scripts.pory"

# 467 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_AquaGrunt11::
# 468 "data/maps/SlateportCity/scripts.pory"
	lock
# 469 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 470 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
# 471 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 472 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
# 473 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 474 "data/maps/SlateportCity/scripts.pory"
	release
# 475 "data/maps/SlateportCity/scripts.pory"
	end
# 476 "data/maps/SlateportCity/scripts.pory"

# 477 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EvoClerk::
# 478 "data/maps/SlateportCity/scripts.pory"
	lock
# 479 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 480 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, SlateportCity_EventScript_ComeBackWithBadge3
# 481 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 482 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 483 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_EvoItems
# 484 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 485 "data/maps/SlateportCity/scripts.pory"
	release
# 486 "data/maps/SlateportCity/scripts.pory"
	end
# 487 "data/maps/SlateportCity/scripts.pory"

# 488 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 489 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_EvoItems:
# 490 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 491 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_WATER_STONE
# 492 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 493 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 494 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ICE_STONE
# 495 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_SUN_STONE
# 496 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_MOON_STONE
# 497 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 498 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 499 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 500 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 501 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_METAL_COAT
# 502 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 503 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_METAL_ALLOY
# 504 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PROTECTOR
# 505 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 506 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 507 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 508 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 509 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_WHIPPED_DREAM
# 510 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_SACHET
# 511 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 512 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 513 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_UPGRADE
# 514 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 515 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_DEEP_SEA_SCALE
# 516 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_DEEP_SEA_TOOTH
# 517 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 518 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_RAZOR_FANG
# 519 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_SWEET_APPLE
# 520 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TART_APPLE
# 521 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_SYRUPY_APPLE
# 522 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CRACKED_POT
# 523 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_CHIPPED_POT
# 524 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
# 525 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_MASTERPIECE_TEACUP
# 526 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_BLACK_AUGURITE
# 527 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_PEAT_BLOCK
# 528 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 529 "data/maps/SlateportCity/scripts.pory"

# 530 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithBadge3::
# 531 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackWithBadge3, MSGBOX_DEFAULT
# 532 "data/maps/SlateportCity/scripts.pory"
	release
# 533 "data/maps/SlateportCity/scripts.pory"
	end
# 534 "data/maps/SlateportCity/scripts.pory"

# 535 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ComeBackWithSecretPower::
# 536 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
# 537 "data/maps/SlateportCity/scripts.pory"
	release
# 538 "data/maps/SlateportCity/scripts.pory"
	end
# 539 "data/maps/SlateportCity/scripts.pory"

# 540 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_DecorClerk::
# 541 "data/maps/SlateportCity/scripts.pory"
	lock
# 542 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 543 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
# 544 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 545 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 546 "data/maps/SlateportCity/scripts.pory"
	pokemartdecoration SlateportCity_PokemartDecor
# 547 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 548 "data/maps/SlateportCity/scripts.pory"
	release
# 549 "data/maps/SlateportCity/scripts.pory"
	end
# 550 "data/maps/SlateportCity/scripts.pory"

# 551 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 552 "data/maps/SlateportCity/scripts.pory"
SlateportCity_PokemartDecor:
# 553 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BRICK
# 554 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BRICK
# 555 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BRICK
# 556 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_RED_BALLOON
# 557 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_BLUE_BALLOON
# 558 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_YELLOW_BALLOON
# 559 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_LOW_NOTE_MAT
# 560 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_D_NOTE_MAT
# 561 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_E_NOTE_MAT
# 562 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_F_NOTE_MAT
# 563 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_G_NOTE_MAT
# 564 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_A_NOTE_MAT
# 565 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_B_NOTE_MAT
# 566 "data/maps/SlateportCity/scripts.pory"
	.2byte DECOR_C_HIGH_NOTE_MAT
# 567 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 568 "data/maps/SlateportCity/scripts.pory"

# 569 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PowerTMClerk::
# 570 "data/maps/SlateportCity/scripts.pory"
	lock
# 571 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 572 "data/maps/SlateportCity/scripts.pory"
	message gText_HowMayIServeYou
# 573 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 574 "data/maps/SlateportCity/scripts.pory"
	pokemart SlateportCity_Pokemart_PowerTMs
# 575 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 576 "data/maps/SlateportCity/scripts.pory"
	release
# 577 "data/maps/SlateportCity/scripts.pory"
	end
# 578 "data/maps/SlateportCity/scripts.pory"

# 579 "data/maps/SlateportCity/scripts.pory"
	.align 2
# 580 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Pokemart_PowerTMs:
# 581 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_HIDDEN_POWER
# 582 "data/maps/SlateportCity/scripts.pory"
	.2byte ITEM_TM_SECRET_POWER
# 583 "data/maps/SlateportCity/scripts.pory"
	pokemartlistend
# 584 "data/maps/SlateportCity/scripts.pory"

# 585 "data/maps/SlateportCity/scripts.pory"
@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
# 586 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CaptStern::
# 587 "data/maps/SlateportCity/scripts.pory"
	lockall
# 588 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
# 589 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
# 590 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 591 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
# 592 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 593 "data/maps/SlateportCity/scripts.pory"
	delay 10
# 594 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
# 595 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 596 "data/maps/SlateportCity/scripts.pory"
	delay 25
# 597 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
# 598 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
# 599 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
# 600 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
# 601 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 602 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_GABBY
# 603 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_TY
# 604 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
# 605 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 606 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 607 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
# 608 "data/maps/SlateportCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 609 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
# 610 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
# 611 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
# 612 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
# 613 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
# 614 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
# 615 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 616 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
# 617 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 618 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
# 619 "data/maps/SlateportCity/scripts.pory"
	playse SE_PIN
# 620 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
# 621 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 622 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
# 623 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 624 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
# 625 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 626 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
# 627 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 628 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 629 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
# 630 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
# 631 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 632 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_CAPT_STERN
# 633 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
# 634 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
# 635 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
# 636 "data/maps/SlateportCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
# 637 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 2
# 638 "data/maps/SlateportCity/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
# 639 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 640 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 641 "data/maps/SlateportCity/scripts.pory"
	end
# 642 "data/maps/SlateportCity/scripts.pory"

# 643 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_OldWomanConcern:
# 644 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 645 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 646 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 647 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 648 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 649 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 650 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 651 "data/maps/SlateportCity/scripts.pory"
	step_end
# 652 "data/maps/SlateportCity/scripts.pory"

# 653 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ManConcern:
# 654 "data/maps/SlateportCity/scripts.pory"
	emote_question_mark
# 655 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 656 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 657 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 658 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 659 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 660 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_left
# 661 "data/maps/SlateportCity/scripts.pory"
	step_end
# 662 "data/maps/SlateportCity/scripts.pory"

# 663 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_GabbyExit:
# 664 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 665 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 666 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 667 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 668 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 669 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 670 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 671 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 672 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 673 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 674 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 675 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 676 "data/maps/SlateportCity/scripts.pory"
	step_end
# 677 "data/maps/SlateportCity/scripts.pory"

# 678 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_TyExit:
# 679 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 680 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 681 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 682 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 683 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 684 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 685 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 686 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 687 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 688 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 689 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 690 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 691 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 692 "data/maps/SlateportCity/scripts.pory"
	step_end
# 693 "data/maps/SlateportCity/scripts.pory"

# 694 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_Unused:
# 695 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 696 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_up
# 697 "data/maps/SlateportCity/scripts.pory"
	step_end
# 698 "data/maps/SlateportCity/scripts.pory"

# 699 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternEnterHarbor:
# 700 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 701 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 702 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 703 "data/maps/SlateportCity/scripts.pory"
	set_invisible
# 704 "data/maps/SlateportCity/scripts.pory"
	step_end
# 705 "data/maps/SlateportCity/scripts.pory"

# 706 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_SternWatchGabbyAndTyExit:
# 707 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 708 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 709 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 710 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 711 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 712 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 713 "data/maps/SlateportCity/scripts.pory"
	walk_left
# 714 "data/maps/SlateportCity/scripts.pory"
	step_end
# 715 "data/maps/SlateportCity/scripts.pory"

# 716 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerEnterHarbor:
# 717 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 718 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 719 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 720 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 721 "data/maps/SlateportCity/scripts.pory"
	walk_up
# 722 "data/maps/SlateportCity/scripts.pory"
	step_end
# 723 "data/maps/SlateportCity/scripts.pory"

# 724 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerFaceStern:
# 725 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 726 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 727 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 728 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 729 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 730 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 731 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 732 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_down
# 733 "data/maps/SlateportCity/scripts.pory"
	step_end
# 734 "data/maps/SlateportCity/scripts.pory"

# 735 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Ty::
# 736 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
# 737 "data/maps/SlateportCity/scripts.pory"
	end
# 738 "data/maps/SlateportCity/scripts.pory"

# 739 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Gabby::
# 740 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
# 741 "data/maps/SlateportCity/scripts.pory"
	end
# 742 "data/maps/SlateportCity/scripts.pory"

# 743 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Man3::
# 744 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
# 745 "data/maps/SlateportCity/scripts.pory"
	end
# 746 "data/maps/SlateportCity/scripts.pory"

# 747 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryPowderClerk::
# 748 "data/maps/SlateportCity/scripts.pory"
	lock
# 749 "data/maps/SlateportCity/scripts.pory"
	faceplayer
# 750 "data/maps/SlateportCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
# 751 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
# 752 "data/maps/SlateportCity/scripts.pory"
	giveitem ITEM_POWDER_JAR
# 753 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_POWDER_JAR
# 754 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 755 "data/maps/SlateportCity/scripts.pory"
	release
# 756 "data/maps/SlateportCity/scripts.pory"
	end
# 757 "data/maps/SlateportCity/scripts.pory"

# 758 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ReceivedPowderJar::
# 759 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, 1
# 760 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 761 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
# 762 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
# 763 "data/maps/SlateportCity/scripts.pory"
	special DisplayBerryPowderVendorMenu
# 764 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 765 "data/maps/SlateportCity/scripts.pory"
	end
# 766 "data/maps/SlateportCity/scripts.pory"

# 767 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ExplainBerryPowder::
# 768 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
# 769 "data/maps/SlateportCity/scripts.pory"
	release
# 770 "data/maps/SlateportCity/scripts.pory"
	end
# 771 "data/maps/SlateportCity/scripts.pory"

# 772 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ChooseBerryPowderItem::
# 773 "data/maps/SlateportCity/scripts.pory"
	message SlateportCity_Text_ExchangeWhatWithIt
# 774 "data/maps/SlateportCity/scripts.pory"
	waitmessage
# 775 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
# 776 "data/maps/SlateportCity/scripts.pory"
	special ShowScrollableMultichoice
# 777 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 778 "data/maps/SlateportCity/scripts.pory"
	switch VAR_RESULT
# 779 "data/maps/SlateportCity/scripts.pory"
	case 0, SlateportCity_EventScript_EnergyPowder
# 780 "data/maps/SlateportCity/scripts.pory"
	case 1, SlateportCity_EventScript_EnergyRoot
# 781 "data/maps/SlateportCity/scripts.pory"
	case 2, SlateportCity_EventScript_HealPowder
# 782 "data/maps/SlateportCity/scripts.pory"
	case 3, SlateportCity_EventScript_RevivalHerb
# 783 "data/maps/SlateportCity/scripts.pory"
	case 4, SlateportCity_EventScript_Protein
# 784 "data/maps/SlateportCity/scripts.pory"
	case 5, SlateportCity_EventScript_Iron
# 785 "data/maps/SlateportCity/scripts.pory"
	case 6, SlateportCity_EventScript_Carbos
# 786 "data/maps/SlateportCity/scripts.pory"
	case 7, SlateportCity_EventScript_Calcium
# 787 "data/maps/SlateportCity/scripts.pory"
	case 8, SlateportCity_EventScript_Zinc
# 788 "data/maps/SlateportCity/scripts.pory"
	case 9, SlateportCity_EventScript_HPUp
# 789 "data/maps/SlateportCity/scripts.pory"
	case 10, SlateportCity_EventScript_PPUp
# 790 "data/maps/SlateportCity/scripts.pory"
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
# 791 "data/maps/SlateportCity/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
# 792 "data/maps/SlateportCity/scripts.pory"
	end
# 793 "data/maps/SlateportCity/scripts.pory"

# 794 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyPowder::
# 795 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
# 796 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
# 797 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 798 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 799 "data/maps/SlateportCity/scripts.pory"
	end
# 800 "data/maps/SlateportCity/scripts.pory"

# 801 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_EnergyRoot::
# 802 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
# 803 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
# 804 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 80
# 805 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 806 "data/maps/SlateportCity/scripts.pory"
	end
# 807 "data/maps/SlateportCity/scripts.pory"

# 808 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HealPowder::
# 809 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
# 810 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HEAL_POWDER
# 811 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 50
# 812 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 813 "data/maps/SlateportCity/scripts.pory"
	end
# 814 "data/maps/SlateportCity/scripts.pory"

# 815 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_RevivalHerb::
# 816 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
# 817 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
# 818 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 300
# 819 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 820 "data/maps/SlateportCity/scripts.pory"
	end
# 821 "data/maps/SlateportCity/scripts.pory"

# 822 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Protein::
# 823 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PROTEIN
# 824 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PROTEIN
# 825 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 826 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 827 "data/maps/SlateportCity/scripts.pory"
	end
# 828 "data/maps/SlateportCity/scripts.pory"

# 829 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Iron::
# 830 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_IRON
# 831 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_IRON
# 832 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 833 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 834 "data/maps/SlateportCity/scripts.pory"
	end
# 835 "data/maps/SlateportCity/scripts.pory"

# 836 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Carbos::
# 837 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CARBOS
# 838 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CARBOS
# 839 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 840 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 841 "data/maps/SlateportCity/scripts.pory"
	end
# 842 "data/maps/SlateportCity/scripts.pory"

# 843 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Calcium::
# 844 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CALCIUM
# 845 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_CALCIUM
# 846 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 847 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 848 "data/maps/SlateportCity/scripts.pory"
	end
# 849 "data/maps/SlateportCity/scripts.pory"

# 850 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_Zinc::
# 851 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ZINC
# 852 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_ZINC
# 853 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 854 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 855 "data/maps/SlateportCity/scripts.pory"
	end
# 856 "data/maps/SlateportCity/scripts.pory"

# 857 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_HPUp::
# 858 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_HP_UP
# 859 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_HP_UP
# 860 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 1000
# 861 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 862 "data/maps/SlateportCity/scripts.pory"
	end
# 863 "data/maps/SlateportCity/scripts.pory"

# 864 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_PPUp::
# 865 "data/maps/SlateportCity/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_PP_UP
# 866 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8008, ITEM_PP_UP
# 867 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_0x8009, 3000
# 868 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
# 869 "data/maps/SlateportCity/scripts.pory"
	end
# 870 "data/maps/SlateportCity/scripts.pory"

# 871 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_CancelPowderItemSelect::
# 872 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
# 873 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 874 "data/maps/SlateportCity/scripts.pory"
	release
# 875 "data/maps/SlateportCity/scripts.pory"
	end
# 876 "data/maps/SlateportCity/scripts.pory"

# 877 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_TryBuyBerryPowderItem::
# 878 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
# 879 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
# 880 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 881 "data/maps/SlateportCity/scripts.pory"
	specialvar VAR_RESULT, HasEnoughBerryPowder
# 882 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
# 883 "data/maps/SlateportCity/scripts.pory"
	giveitem VAR_0x8008
# 884 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
# 885 "data/maps/SlateportCity/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 886 "data/maps/SlateportCity/scripts.pory"
	special TakeBerryPowder
# 887 "data/maps/SlateportCity/scripts.pory"
	special PrintPlayerBerryPowderAmount
# 888 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
# 889 "data/maps/SlateportCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
# 890 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
# 891 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 892 "data/maps/SlateportCity/scripts.pory"
	release
# 893 "data/maps/SlateportCity/scripts.pory"
	end
# 894 "data/maps/SlateportCity/scripts.pory"

# 895 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NoRoomForBerryPowderItem::
# 896 "data/maps/SlateportCity/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 897 "data/maps/SlateportCity/scripts.pory"
	special RemoveBerryPowderVendorMenu
# 898 "data/maps/SlateportCity/scripts.pory"
	release
# 899 "data/maps/SlateportCity/scripts.pory"
	end
# 900 "data/maps/SlateportCity/scripts.pory"

# 901 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_NotEnoughBerryPowder::
# 902 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
# 903 "data/maps/SlateportCity/scripts.pory"
	goto SlateportCity_EventScript_ChooseBerryPowderItem
# 904 "data/maps/SlateportCity/scripts.pory"
	end
# 905 "data/maps/SlateportCity/scripts.pory"

# 906 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_ScottBattleTentScene::
# 907 "data/maps/SlateportCity/scripts.pory"
	lockall
# 908 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 909 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 910 "data/maps/SlateportCity/scripts.pory"
	opendoor 10, 12
# 911 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 912 "data/maps/SlateportCity/scripts.pory"
	addobject LOCALID_SLATEPORT_SCOTT
# 913 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
# 914 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
# 915 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 916 "data/maps/SlateportCity/scripts.pory"
	closedoor 10, 12
# 917 "data/maps/SlateportCity/scripts.pory"
	waitdooranim
# 918 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
# 919 "data/maps/SlateportCity/scripts.pory"
	closemessage
# 920 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
# 921 "data/maps/SlateportCity/scripts.pory"
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
# 922 "data/maps/SlateportCity/scripts.pory"
	waitmovement 0
# 923 "data/maps/SlateportCity/scripts.pory"
	removeobject LOCALID_SLATEPORT_SCOTT
# 924 "data/maps/SlateportCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 925 "data/maps/SlateportCity/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 926 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 927 "data/maps/SlateportCity/scripts.pory"
	end
# 928 "data/maps/SlateportCity/scripts.pory"

# 929 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PushPlayerDown:
# 930 "data/maps/SlateportCity/scripts.pory"
	lock_facing_direction
# 931 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 932 "data/maps/SlateportCity/scripts.pory"
	unlock_facing_direction
# 933 "data/maps/SlateportCity/scripts.pory"
	step_end
# 934 "data/maps/SlateportCity/scripts.pory"

# 935 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_PlayerWatchScottExit:
# 936 "data/maps/SlateportCity/scripts.pory"
	delay_16
# 937 "data/maps/SlateportCity/scripts.pory"
	walk_in_place_faster_right
# 938 "data/maps/SlateportCity/scripts.pory"
	step_end
# 939 "data/maps/SlateportCity/scripts.pory"

# 940 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitBattleTent:
# 941 "data/maps/SlateportCity/scripts.pory"
	delay_8
# 942 "data/maps/SlateportCity/scripts.pory"
	walk_down
# 943 "data/maps/SlateportCity/scripts.pory"
	step_end
# 944 "data/maps/SlateportCity/scripts.pory"

# 945 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Movement_ScottExitAfterBattleTent:
# 946 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 947 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 948 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 949 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 950 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 951 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 952 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 953 "data/maps/SlateportCity/scripts.pory"
	walk_right
# 954 "data/maps/SlateportCity/scripts.pory"
	step_end
# 955 "data/maps/SlateportCity/scripts.pory"

# 956 "data/maps/SlateportCity/scripts.pory"
SlateportCity_EventScript_BerryCrushRankingsSign::
# 957 "data/maps/SlateportCity/scripts.pory"
	lockall
# 958 "data/maps/SlateportCity/scripts.pory"
	special ShowBerryCrushRankings
# 959 "data/maps/SlateportCity/scripts.pory"
	waitstate
# 960 "data/maps/SlateportCity/scripts.pory"
	releaseall
# 961 "data/maps/SlateportCity/scripts.pory"
	end
# 962 "data/maps/SlateportCity/scripts.pory"

# 963 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EnergyGuruSellWhatYouNeed:
# 964 "data/maps/SlateportCity/scripts.pory"
	.string "I'm the ENERGY GURU! I'll go for it and\n"
# 965 "data/maps/SlateportCity/scripts.pory"
	.string "sell you what you need!$"
# 966 "data/maps/SlateportCity/scripts.pory"

# 967 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhYourPokemon:
# 968 "data/maps/SlateportCity/scripts.pory"
	.string "Oh?\n"
# 969 "data/maps/SlateportCity/scripts.pory"
	.string "Your {STR_VAR_1}…$"
# 970 "data/maps/SlateportCity/scripts.pory"

# 971 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseGiveItThisEffortRibbon:
# 972 "data/maps/SlateportCity/scripts.pory"
	.string "Went for it stupendously!\p"
# 973 "data/maps/SlateportCity/scripts.pory"
	.string "As its reward, please give it this\n"
# 974 "data/maps/SlateportCity/scripts.pory"
	.string "EFFORT RIBBON.$"
# 975 "data/maps/SlateportCity/scripts.pory"

# 976 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ReceivedEffortRibbon:
# 977 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} received the EFFORT RIBBON.$"
# 978 "data/maps/SlateportCity/scripts.pory"

# 979 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PutEffortRibbonOnMon:
# 980 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER} put the EFFORT RIBBON\n"
# 981 "data/maps/SlateportCity/scripts.pory"
	.string "on {STR_VAR_1}.$"
# 982 "data/maps/SlateportCity/scripts.pory"

# 983 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoForItLittleHarder:
# 984 "data/maps/SlateportCity/scripts.pory"
	.string "You have to go for it a little harder.\p"
# 985 "data/maps/SlateportCity/scripts.pory"
	.string "If you do, I'll give your POKéMON\n"
# 986 "data/maps/SlateportCity/scripts.pory"
	.string "something nice.$"
# 987 "data/maps/SlateportCity/scripts.pory"

# 988 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EffortRibbonLooksGoodOnIt:
# 989 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
# 990 "data/maps/SlateportCity/scripts.pory"
	.string "RIBBON looks good on it!$"
# 991 "data/maps/SlateportCity/scripts.pory"

# 992 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
# 993 "data/maps/SlateportCity/scripts.pory"
	.string "The light of the lighthouse reaches\n"
# 994 "data/maps/SlateportCity/scripts.pory"
	.string "dozens of miles away.\p"
# 995 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder if it doesn't startle POKéMON\n"
# 996 "data/maps/SlateportCity/scripts.pory"
	.string "in the sea.$"
# 997 "data/maps/SlateportCity/scripts.pory"

# 998 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaweedFullOfLife:
# 999 "data/maps/SlateportCity/scripts.pory"
	.string "Ooh, look at this!\p"
# 1000 "data/maps/SlateportCity/scripts.pory"
	.string "The seaweed you can get around these\n"
# 1001 "data/maps/SlateportCity/scripts.pory"
	.string "parts is fresh and full of life.\p"
# 1002 "data/maps/SlateportCity/scripts.pory"
	.string "Why, it looks like it can even rear up\n"
# 1003 "data/maps/SlateportCity/scripts.pory"
	.string "and attack!$"
# 1004 "data/maps/SlateportCity/scripts.pory"

# 1005 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HowTownIsBornAndGrows:
# 1006 "data/maps/SlateportCity/scripts.pory"
	.string "Where the water is clean, the fruits\n"
# 1007 "data/maps/SlateportCity/scripts.pory"
	.string "of bountiful harvest gather.\p"
# 1008 "data/maps/SlateportCity/scripts.pory"
	.string "And where people gather, a market\n"
# 1009 "data/maps/SlateportCity/scripts.pory"
	.string "soon starts.\p"
# 1010 "data/maps/SlateportCity/scripts.pory"
	.string "That is how a town is born and grows.$"
# 1011 "data/maps/SlateportCity/scripts.pory"

# 1012 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SlateportWonderfulPlace:
# 1013 "data/maps/SlateportCity/scripts.pory"
	.string "Shopping where you can breathe the\n"
# 1014 "data/maps/SlateportCity/scripts.pory"
	.string "scent of the ocean…\p"
# 1015 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT is such a wonderful place!$"
# 1016 "data/maps/SlateportCity/scripts.pory"

# 1017 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
# 1018 "data/maps/SlateportCity/scripts.pory"
	.string "If you put DOLLS or CUSHIONS on\n"
# 1019 "data/maps/SlateportCity/scripts.pory"
	.string "the floor, they'll get dirty.\p"
# 1020 "data/maps/SlateportCity/scripts.pory"
	.string "I'm going to buy some BRICKS so my\n"
# 1021 "data/maps/SlateportCity/scripts.pory"
	.string "DOLLS and CUSHIONS won't get dirty\l"
# 1022 "data/maps/SlateportCity/scripts.pory"
	.string "when I leave them out.$"
# 1023 "data/maps/SlateportCity/scripts.pory"

# 1024 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GoingToCompeteInBattleTent:
# 1025 "data/maps/SlateportCity/scripts.pory"
	.string "Wroooar! I'm going to compete in\n"
# 1026 "data/maps/SlateportCity/scripts.pory"
	.string "the BATTLE TENT, too!\p"
# 1027 "data/maps/SlateportCity/scripts.pory"
	.string "But before that, I need to catch\n"
# 1028 "data/maps/SlateportCity/scripts.pory"
	.string "some POKéMON!$"
# 1029 "data/maps/SlateportCity/scripts.pory"

# 1030 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BushedHikingFromMauville:
# 1031 "data/maps/SlateportCity/scripts.pory"
	.string "Whew… I'm just bushed…\p"
# 1032 "data/maps/SlateportCity/scripts.pory"
	.string "I hiked over from MAUVILLE CITY.\n"
# 1033 "data/maps/SlateportCity/scripts.pory"
	.string "But, boy, this city's huge.\p"
# 1034 "data/maps/SlateportCity/scripts.pory"
	.string "If I'd known this, I would've ridden\n"
# 1035 "data/maps/SlateportCity/scripts.pory"
	.string "my BIKE here.$"
# 1036 "data/maps/SlateportCity/scripts.pory"

# 1037 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_EveryoneCallsHimCaptStern:
# 1038 "data/maps/SlateportCity/scripts.pory"
	.string "STERN, the fellow who built the\n"
# 1039 "data/maps/SlateportCity/scripts.pory"
	.string "MUSEUM, also happens to be the leader\l"
# 1040 "data/maps/SlateportCity/scripts.pory"
	.string "of an undersea exploration team.\p"
# 1041 "data/maps/SlateportCity/scripts.pory"
	.string "So, everyone calls him CAPT. STERN.$"
# 1042 "data/maps/SlateportCity/scripts.pory"

# 1043 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsLongLineOverThere:
# 1044 "data/maps/SlateportCity/scripts.pory"
	.string "What is that over there?\n"
# 1045 "data/maps/SlateportCity/scripts.pory"
	.string "That long line…$"
# 1046 "data/maps/SlateportCity/scripts.pory"

# 1047 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_VisitedMuseumOften:
# 1048 "data/maps/SlateportCity/scripts.pory"
	.string "When I was a child, I visited\n"
# 1049 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM often.\p"
# 1050 "data/maps/SlateportCity/scripts.pory"
	.string "I used to dream about the mysteries of\n"
# 1051 "data/maps/SlateportCity/scripts.pory"
	.string "the sea after seeing the exhibits.$"
# 1052 "data/maps/SlateportCity/scripts.pory"

# 1053 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_QuitPushing:
# 1054 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, there! Quit pushing!\n"
# 1055 "data/maps/SlateportCity/scripts.pory"
	.string "This is the line, can't you see?$"
# 1056 "data/maps/SlateportCity/scripts.pory"

# 1057 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaHasPolicy:
# 1058 "data/maps/SlateportCity/scripts.pory"
	.string "TEAM AQUA has a policy of\n"
# 1059 "data/maps/SlateportCity/scripts.pory"
	.string "assembling and dispersing at\l"
# 1060 "data/maps/SlateportCity/scripts.pory"
	.string "the operation site.$"
# 1061 "data/maps/SlateportCity/scripts.pory"

# 1062 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BossIsBrilliant:
# 1063 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is brilliant.\p"
# 1064 "data/maps/SlateportCity/scripts.pory"
	.string "What would he want to do with\n"
# 1065 "data/maps/SlateportCity/scripts.pory"
	.string "a MUSEUM now?$"
# 1066 "data/maps/SlateportCity/scripts.pory"

# 1067 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatsNewSchemeIWonder:
# 1068 "data/maps/SlateportCity/scripts.pory"
	.string "What's the new scheme, I wonder?\p"
# 1069 "data/maps/SlateportCity/scripts.pory"
	.string "Our BOSS is scary when he's mad, so\n"
# 1070 "data/maps/SlateportCity/scripts.pory"
	.string "I'd better not screw things up…$"
# 1071 "data/maps/SlateportCity/scripts.pory"

# 1072 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldTakeItAll:
# 1073 "data/maps/SlateportCity/scripts.pory"
	.string "If there's something we need in\n"
# 1074 "data/maps/SlateportCity/scripts.pory"
	.string "the MUSEUM, we should take it all!$"
# 1075 "data/maps/SlateportCity/scripts.pory"

# 1076 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontButtIn:
# 1077 "data/maps/SlateportCity/scripts.pory"
	.string "Hey, you there!\n"
# 1078 "data/maps/SlateportCity/scripts.pory"
	.string "Don't butt in!$"
# 1079 "data/maps/SlateportCity/scripts.pory"

# 1080 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RemindsMeOfLongLineForGames:
# 1081 "data/maps/SlateportCity/scripts.pory"
	.string "A long line, huh?\p"
# 1082 "data/maps/SlateportCity/scripts.pory"
	.string "It reminds me of the times I lined up to\n"
# 1083 "data/maps/SlateportCity/scripts.pory"
	.string "buy smash-hit games…$"
# 1084 "data/maps/SlateportCity/scripts.pory"

# 1085 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhyAreWeLiningUp:
# 1086 "data/maps/SlateportCity/scripts.pory"
	.string "Why are we even lining up and paying?\n"
# 1087 "data/maps/SlateportCity/scripts.pory"
	.string "We should just march in!$"
# 1088 "data/maps/SlateportCity/scripts.pory"

# 1089 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhatDoYouWant:
# 1090 "data/maps/SlateportCity/scripts.pory"
	.string "What?\n"
# 1091 "data/maps/SlateportCity/scripts.pory"
	.string "What do you want?$"
# 1092 "data/maps/SlateportCity/scripts.pory"

# 1093 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_IllReadSignForYou:
# 1094 "data/maps/SlateportCity/scripts.pory"
	.string "You want to read this sign?\n"
# 1095 "data/maps/SlateportCity/scripts.pory"
	.string "I'll read it for you!$"
# 1096 "data/maps/SlateportCity/scripts.pory"

# 1097 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
# 1098 "data/maps/SlateportCity/scripts.pory"
	.string "Let's see…\p"
# 1099 "data/maps/SlateportCity/scripts.pory"
	.string "Um… I think it says something like\n"
# 1100 "data/maps/SlateportCity/scripts.pory"
	.string "“the life in the sea is endless.”\p"
# 1101 "data/maps/SlateportCity/scripts.pory"
	.string "Yup, I'm pretty sure that's what\n"
# 1102 "data/maps/SlateportCity/scripts.pory"
	.string "it says.$"
# 1103 "data/maps/SlateportCity/scripts.pory"

# 1104 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ShouldveBroughtMyGameBoy:
# 1105 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…\p"
# 1106 "data/maps/SlateportCity/scripts.pory"
	.string "I should've brought my Game Boy\n"
# 1107 "data/maps/SlateportCity/scripts.pory"
	.string "Advance so I wouldn't get bored in line…\p"
# 1108 "data/maps/SlateportCity/scripts.pory"
	.string "Grumble…$"
# 1109 "data/maps/SlateportCity/scripts.pory"

# 1110 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HotSpringsAfterOperation:
# 1111 "data/maps/SlateportCity/scripts.pory"
	.string "When this operation's over, I'll take\n"
# 1112 "data/maps/SlateportCity/scripts.pory"
	.string "you to a hot spring spa!\p"
# 1113 "data/maps/SlateportCity/scripts.pory"
	.string "That's what our leader said.\n"
# 1114 "data/maps/SlateportCity/scripts.pory"
	.string "I can't wait!$"
# 1115 "data/maps/SlateportCity/scripts.pory"

# 1116 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SeaIsSoWet:
# 1117 "data/maps/SlateportCity/scripts.pory"
	.string "The sea is just so vast…\p"
# 1118 "data/maps/SlateportCity/scripts.pory"
	.string "Could the sea have been made by\n"
# 1119 "data/maps/SlateportCity/scripts.pory"
	.string "the tears shed by POKéMON?$"
# 1120 "data/maps/SlateportCity/scripts.pory"

# 1121 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SinkOldBoats:
# 1122 "data/maps/SlateportCity/scripts.pory"
	.string "Do you know what they do with old\n"
# 1123 "data/maps/SlateportCity/scripts.pory"
	.string "ships that become too creaky to sail?\p"
# 1124 "data/maps/SlateportCity/scripts.pory"
	.string "They sink them in the sea so they\n"
# 1125 "data/maps/SlateportCity/scripts.pory"
	.string "become habitats for POKéMON.$"
# 1126 "data/maps/SlateportCity/scripts.pory"

# 1127 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BuyTooMuch:
# 1128 "data/maps/SlateportCity/scripts.pory"
	.string "Whenever I visit here, I get carried\n"
# 1129 "data/maps/SlateportCity/scripts.pory"
	.string "away and buy too much.$"
# 1130 "data/maps/SlateportCity/scripts.pory"

# 1131 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GetNameRaterToHelpYou:
# 1132 "data/maps/SlateportCity/scripts.pory"
	.string "If you want to change your POKéMON's\n"
# 1133 "data/maps/SlateportCity/scripts.pory"
	.string "nickname, you'll have to get the NAME\l"
# 1134 "data/maps/SlateportCity/scripts.pory"
	.string "RATER to help you.$"
# 1135 "data/maps/SlateportCity/scripts.pory"

# 1136 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CantChangeTradeMonName:
# 1137 "data/maps/SlateportCity/scripts.pory"
	.string "Any POKéMON you get in a trade,\n"
# 1138 "data/maps/SlateportCity/scripts.pory"
	.string "you can't change its nickname.\p"
# 1139 "data/maps/SlateportCity/scripts.pory"
	.string "The original TRAINER's love for that\n"
# 1140 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON is in the nickname.$"
# 1141 "data/maps/SlateportCity/scripts.pory"

# 1142 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentBuiltRecently:
# 1143 "data/maps/SlateportCity/scripts.pory"
	.string "Recently, a BATTLE TENT was built\n"
# 1144 "data/maps/SlateportCity/scripts.pory"
	.string "in SLATEPORT.\p"
# 1145 "data/maps/SlateportCity/scripts.pory"
	.string "GYMS are fun, but the BATTLE TENT's\n"
# 1146 "data/maps/SlateportCity/scripts.pory"
	.string "awesome in its own way.\p"
# 1147 "data/maps/SlateportCity/scripts.pory"
	.string "You should go find tough POKéMON\n"
# 1148 "data/maps/SlateportCity/scripts.pory"
	.string "for the BATTLE TENT!$"
# 1149 "data/maps/SlateportCity/scripts.pory"

# 1150 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptSternBeingInterviewed:
# 1151 "data/maps/SlateportCity/scripts.pory"
	.string "I was hoping that it was a famous star\n"
# 1152 "data/maps/SlateportCity/scripts.pory"
	.string "so I could get an autograph.\p"
# 1153 "data/maps/SlateportCity/scripts.pory"
	.string "But who's that being interviewed?\n"
# 1154 "data/maps/SlateportCity/scripts.pory"
	.string "Isn't that CAPT. STERN?$"
# 1155 "data/maps/SlateportCity/scripts.pory"

# 1156 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_InterviewerSoCool:
# 1157 "data/maps/SlateportCity/scripts.pory"
	.string "That lady interviewer is so cool\n"
# 1158 "data/maps/SlateportCity/scripts.pory"
	.string "and pretty.\p"
# 1159 "data/maps/SlateportCity/scripts.pory"
	.string "When I grow up, I'm going to be\n"
# 1160 "data/maps/SlateportCity/scripts.pory"
	.string "an international journalist!$"
# 1161 "data/maps/SlateportCity/scripts.pory"

# 1162 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternSaysDiscoveredSomething:
# 1163 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN says they discovered\n"
# 1164 "data/maps/SlateportCity/scripts.pory"
	.string "something at the bottom of the sea.\p"
# 1165 "data/maps/SlateportCity/scripts.pory"
	.string "I wonder what it is?\n"
# 1166 "data/maps/SlateportCity/scripts.pory"
	.string "What could it be?$"
# 1167 "data/maps/SlateportCity/scripts.pory"

# 1168 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainComeBackWithBigFish:
# 1169 "data/maps/SlateportCity/scripts.pory"
	.string "What's going on here?\p"
# 1170 "data/maps/SlateportCity/scripts.pory"
	.string "Did the good CAPTAIN come back with\n"
# 1171 "data/maps/SlateportCity/scripts.pory"
	.string "a big fish from the ocean floor?$"
# 1172 "data/maps/SlateportCity/scripts.pory"

# 1173 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AmIOnTV:
# 1174 "data/maps/SlateportCity/scripts.pory"
	.string "Hey! Are you watching?\n"
# 1175 "data/maps/SlateportCity/scripts.pory"
	.string "Am I on TV?$"
# 1176 "data/maps/SlateportCity/scripts.pory"

# 1177 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CaptainsACelebrity:
# 1178 "data/maps/SlateportCity/scripts.pory"
	.string "A TV interview! Here!\n"
# 1179 "data/maps/SlateportCity/scripts.pory"
	.string "The CAPTAIN's a celebrity!$"
# 1180 "data/maps/SlateportCity/scripts.pory"

# 1181 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BigSmileForCamera:
# 1182 "data/maps/SlateportCity/scripts.pory"
	.string "TY: Okay, CAPT. STERN, a big smile\n"
# 1183 "data/maps/SlateportCity/scripts.pory"
	.string "for the camera!$"
# 1184 "data/maps/SlateportCity/scripts.pory"

# 1185 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MostInvaluableExperience:
# 1186 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: I see, I see. You've had a most\n"
# 1187 "data/maps/SlateportCity/scripts.pory"
	.string "invaluable experience…$"
# 1188 "data/maps/SlateportCity/scripts.pory"

# 1189 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternMoveAheadWithExploration:
# 1190 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Yes, indeed. We intend to\n"
# 1191 "data/maps/SlateportCity/scripts.pory"
	.string "move ahead with our exploration.$"
# 1192 "data/maps/SlateportCity/scripts.pory"

# 1193 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_GabbyWonderfulThanksForInterview:
# 1194 "data/maps/SlateportCity/scripts.pory"
	.string "GABBY: That's wonderful, CAPT. STERN!\n"
# 1195 "data/maps/SlateportCity/scripts.pory"
	.string "Thank you for taking the time from\l"
# 1196 "data/maps/SlateportCity/scripts.pory"
	.string "your busy schedule to talk to us.\p"
# 1197 "data/maps/SlateportCity/scripts.pory"
	.string "We hope we can interview you again\n"
# 1198 "data/maps/SlateportCity/scripts.pory"
	.string "with news of more discoveries!$"
# 1199 "data/maps/SlateportCity/scripts.pory"

# 1200 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhewFirstInterview:
# 1201 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: Whew…\p"
# 1202 "data/maps/SlateportCity/scripts.pory"
	.string "That was my first time to be filmed for\n"
# 1203 "data/maps/SlateportCity/scripts.pory"
	.string "TV. That was nerve-wracking.$"
# 1204 "data/maps/SlateportCity/scripts.pory"

# 1205 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OhPlayerWeMadeDiscovery:
# 1206 "data/maps/SlateportCity/scripts.pory"
	.string "Oh! {PLAYER}{KUN}!\n"
# 1207 "data/maps/SlateportCity/scripts.pory"
	.string "You're looking great!\p"
# 1208 "data/maps/SlateportCity/scripts.pory"
	.string "We made a huge discovery on our last\n"
# 1209 "data/maps/SlateportCity/scripts.pory"
	.string "seafloor exploration.\p"
# 1210 "data/maps/SlateportCity/scripts.pory"
	.string "We found an underwater cavern on\n"
# 1211 "data/maps/SlateportCity/scripts.pory"
	.string "ROUTE 128.\p"
# 1212 "data/maps/SlateportCity/scripts.pory"
	.string "We think it's the habitat of a POKéMON\n"
# 1213 "data/maps/SlateportCity/scripts.pory"
	.string "that's said to have been long extinct.$"
# 1214 "data/maps/SlateportCity/scripts.pory"

# 1215 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
# 1216 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1217 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN, I presume.\p"
# 1218 "data/maps/SlateportCity/scripts.pory"
	.string "We of TEAM AQUA will assume\n"
# 1219 "data/maps/SlateportCity/scripts.pory"
	.string "control of your submarine!\p"
# 1220 "data/maps/SlateportCity/scripts.pory"
	.string "Your objections are meaningless!\n"
# 1221 "data/maps/SlateportCity/scripts.pory"
	.string "We expect your total cooperation!\p"
# 1222 "data/maps/SlateportCity/scripts.pory"
	.string "Fufufu…\n"
# 1223 "data/maps/SlateportCity/scripts.pory"
	.string "Just watch and learn what TEAM\l"
# 1224 "data/maps/SlateportCity/scripts.pory"
	.string "AQUA has planned!$"
# 1225 "data/maps/SlateportCity/scripts.pory"

# 1226 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternWhatWasAllThat:
# 1227 "data/maps/SlateportCity/scripts.pory"
	.string "CAPT. STERN: What was that all about?\p"
# 1228 "data/maps/SlateportCity/scripts.pory"
	.string "It sounded like someone using\n"
# 1229 "data/maps/SlateportCity/scripts.pory"
	.string "a megaphone…\p"
# 1230 "data/maps/SlateportCity/scripts.pory"
	.string "Where did it come from?$"
# 1231 "data/maps/SlateportCity/scripts.pory"

# 1232 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FromHarborTryingToTakeSub:
# 1233 "data/maps/SlateportCity/scripts.pory"
	.string "It's from the HARBOR!\p"
# 1234 "data/maps/SlateportCity/scripts.pory"
	.string "The submarine!\n"
# 1235 "data/maps/SlateportCity/scripts.pory"
	.string "They're trying to take it!$"
# 1236 "data/maps/SlateportCity/scripts.pory"

# 1237 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PleaseComeWithMe:
# 1238 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 1239 "data/maps/SlateportCity/scripts.pory"
	.string "Please, come with me!$"
# 1240 "data/maps/SlateportCity/scripts.pory"

# 1241 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BattleTentSign:
# 1242 "data/maps/SlateportCity/scripts.pory"
	.string "BATTLE TENT SLATEPORT SITE\n"
# 1243 "data/maps/SlateportCity/scripts.pory"
	.string "“Find it! The ultimate POKéMON!”$"
# 1244 "data/maps/SlateportCity/scripts.pory"

# 1245 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardWantedSign:
# 1246 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1247 "data/maps/SlateportCity/scripts.pory"
	.string "“Wanted: A sailor capable of sailing\n"
# 1248 "data/maps/SlateportCity/scripts.pory"
	.string "in all currents.”$"
# 1249 "data/maps/SlateportCity/scripts.pory"

# 1250 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardNearsCompletion:
# 1251 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1252 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL nears\n"
# 1253 "data/maps/SlateportCity/scripts.pory"
	.string "completion for serving the ports of\l"
# 1254 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT and LILYCOVE.”$"
# 1255 "data/maps/SlateportCity/scripts.pory"

# 1256 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_SternsShipyardFerryComplete:
# 1257 "data/maps/SlateportCity/scripts.pory"
	.string "STERN'S SHIPYARD\p"
# 1258 "data/maps/SlateportCity/scripts.pory"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
# 1259 "data/maps/SlateportCity/scripts.pory"
	.string "ferry S.S. TIDAL is handled at the\l"
# 1260 "data/maps/SlateportCity/scripts.pory"
	.string "HARBOR.”$"
# 1261 "data/maps/SlateportCity/scripts.pory"

# 1262 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_PokemonFanClubSign:
# 1263 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON FAN CLUB\n"
# 1264 "data/maps/SlateportCity/scripts.pory"
	.string "“Calling all fans of POKéMON!”$"
# 1265 "data/maps/SlateportCity/scripts.pory"

# 1266 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_OceanicMuseumSign:
# 1267 "data/maps/SlateportCity/scripts.pory"
	.string "“The endless sea sustains\n"
# 1268 "data/maps/SlateportCity/scripts.pory"
	.string "all life.”\p"
# 1269 "data/maps/SlateportCity/scripts.pory"
	.string "OCEANIC MUSEUM$"
# 1270 "data/maps/SlateportCity/scripts.pory"

# 1271 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_CitySign:
# 1272 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT CITY\p"
# 1273 "data/maps/SlateportCity/scripts.pory"
	.string "“The port where people and POKéMON\n"
# 1274 "data/maps/SlateportCity/scripts.pory"
	.string "cross paths.”$"
# 1275 "data/maps/SlateportCity/scripts.pory"

# 1276 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MarketSign:
# 1277 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT MARKET\n"
# 1278 "data/maps/SlateportCity/scripts.pory"
	.string "“Unique items found nowhere else!”$"
# 1279 "data/maps/SlateportCity/scripts.pory"

# 1280 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborFerryUnderConstruction:
# 1281 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1282 "data/maps/SlateportCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 1283 "data/maps/SlateportCity/scripts.pory"
	.string "construction in the SHIPYARD.\p"
# 1284 "data/maps/SlateportCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 1285 "data/maps/SlateportCity/scripts.pory"
	.string "shortly.”$"
# 1286 "data/maps/SlateportCity/scripts.pory"

# 1287 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_HarborSign:
# 1288 "data/maps/SlateportCity/scripts.pory"
	.string "SLATEPORT HARBOR\p"
# 1289 "data/maps/SlateportCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 1290 "data/maps/SlateportCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 1291 "data/maps/SlateportCity/scripts.pory"

# 1292 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_NameRatersHouseSign:
# 1293 "data/maps/SlateportCity/scripts.pory"
	.string "NAME RATER'S HOUSE\n"
# 1294 "data/maps/SlateportCity/scripts.pory"
	.string "“POKéMON nicknames rated.”$"
# 1295 "data/maps/SlateportCity/scripts.pory"

# 1296 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerries:
# 1297 "data/maps/SlateportCity/scripts.pory"
	.string "If a wild POKéMON gets hurt, it heals\n"
# 1298 "data/maps/SlateportCity/scripts.pory"
	.string "itself by chewing on BERRIES.\p"
# 1299 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1300 "data/maps/SlateportCity/scripts.pory"
	.string "Somebody saw that and got the idea\n"
# 1301 "data/maps/SlateportCity/scripts.pory"
	.string "of making medicine from BERRIES.\p"
# 1302 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1303 "data/maps/SlateportCity/scripts.pory"
	.string "To turn BERRIES into medicine,\n"
# 1304 "data/maps/SlateportCity/scripts.pory"
	.string "they must be crushed into powder.\p"
# 1305 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know that?\p"
# 1306 "data/maps/SlateportCity/scripts.pory"
	.string "You seem to have an interest\n"
# 1307 "data/maps/SlateportCity/scripts.pory"
	.string "in BERRIES!\p"
# 1308 "data/maps/SlateportCity/scripts.pory"
	.string "I've got something good for someone\n"
# 1309 "data/maps/SlateportCity/scripts.pory"
	.string "like you.$"
# 1310 "data/maps/SlateportCity/scripts.pory"

# 1311 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExplainBerryPowder:
# 1312 "data/maps/SlateportCity/scripts.pory"
	.string "I recently had machines installed at\n"
# 1313 "data/maps/SlateportCity/scripts.pory"
	.string "POKéMON CENTERS for crushing BERRIES.\p"
# 1314 "data/maps/SlateportCity/scripts.pory"
	.string "The BERRY CRUSH machines are at\n"
# 1315 "data/maps/SlateportCity/scripts.pory"
	.string "the DIRECT CORNER upstairs.\p"
# 1316 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?\p"
# 1317 "data/maps/SlateportCity/scripts.pory"
	.string "Could you make BERRY POWDER for\n"
# 1318 "data/maps/SlateportCity/scripts.pory"
	.string "me using those machines?\p"
# 1319 "data/maps/SlateportCity/scripts.pory"
	.string "I can make you all sorts of medicine\n"
# 1320 "data/maps/SlateportCity/scripts.pory"
	.string "if you bring me lots of BERRY POWDER.$"
# 1321 "data/maps/SlateportCity/scripts.pory"

# 1322 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_BroughtMeSomeBerryPowder:
# 1323 "data/maps/SlateportCity/scripts.pory"
	.string "Have you brought me some\n"
# 1324 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER?$"
# 1325 "data/maps/SlateportCity/scripts.pory"

# 1326 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeWhatWithIt:
# 1327 "data/maps/SlateportCity/scripts.pory"
	.string "What would you like to exchange\n"
# 1328 "data/maps/SlateportCity/scripts.pory"
	.string "it with?$"
# 1329 "data/maps/SlateportCity/scripts.pory"

# 1330 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ExchangeBerryPowderForItem:
# 1331 "data/maps/SlateportCity/scripts.pory"
	.string "Okay, you want to exchange your\n"
# 1332 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for one {STR_VAR_1}?$"
# 1333 "data/maps/SlateportCity/scripts.pory"

# 1334 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_DontHaveEnoughBerryPowder:
# 1335 "data/maps/SlateportCity/scripts.pory"
	.string "Oh, dear. You don't have enough\n"
# 1336 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER.$"
# 1337 "data/maps/SlateportCity/scripts.pory"

# 1338 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_FineBerryPowderTradeSomethingElse:
# 1339 "data/maps/SlateportCity/scripts.pory"
	.string "This is fine BERRY POWDER.\n"
# 1340 "data/maps/SlateportCity/scripts.pory"
	.string "It will make excellent medicine.\p"
# 1341 "data/maps/SlateportCity/scripts.pory"
	.string "Would you like to trade more of your\n"
# 1342 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for something else?$"
# 1343 "data/maps/SlateportCity/scripts.pory"

# 1344 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_WhenYouGetMoreBringItToMe:
# 1345 "data/maps/SlateportCity/scripts.pory"
	.string "Okay! When you get some more\n"
# 1346 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER, bring it to me, please!$"
# 1347 "data/maps/SlateportCity/scripts.pory"

# 1348 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackToTradeBerryPowder:
# 1349 "data/maps/SlateportCity/scripts.pory"
	.string "Come back if you'd like to trade your\n"
# 1350 "data/maps/SlateportCity/scripts.pory"
	.string "BERRY POWDER for some medicine.\p"
# 1351 "data/maps/SlateportCity/scripts.pory"
	.string "I'm always running a bazaar here.\p"
# 1352 "data/maps/SlateportCity/scripts.pory"
	.string "Did you know?$"
# 1353 "data/maps/SlateportCity/scripts.pory"

# 1354 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_YouDroveTeamAquaAway:
# 1355 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Huh?\n"
# 1356 "data/maps/SlateportCity/scripts.pory"
	.string "I'm sure I met you somewhere before.\p"
# 1357 "data/maps/SlateportCity/scripts.pory"
	.string "Have I introduced myself to you?\n"
# 1358 "data/maps/SlateportCity/scripts.pory"
	.string "If not, my name's SCOTT.\p"
# 1359 "data/maps/SlateportCity/scripts.pory"
	.string "I just saw TEAM AQUA run away from\n"
# 1360 "data/maps/SlateportCity/scripts.pory"
	.string "here like they were stung.\p"
# 1361 "data/maps/SlateportCity/scripts.pory"
	.string "Let me guess--you drove them away?$"
# 1362 "data/maps/SlateportCity/scripts.pory"

# 1363 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_MaybeThisTrainer:
# 1364 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Hmm…\n"
# 1365 "data/maps/SlateportCity/scripts.pory"
	.string "Maybe, just maybe, this TRAINER…$"
# 1366 "data/maps/SlateportCity/scripts.pory"

# 1367 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_LetsRegisterEachOther:
# 1368 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: All right! I think you're going\n"
# 1369 "data/maps/SlateportCity/scripts.pory"
	.string "to become a good friend.\p"
# 1370 "data/maps/SlateportCity/scripts.pory"
	.string "So, let's register each other in our\n"
# 1371 "data/maps/SlateportCity/scripts.pory"
	.string "POKéNAVS.\p"
# 1372 "data/maps/SlateportCity/scripts.pory"
	.string "… … … … … …$"
# 1373 "data/maps/SlateportCity/scripts.pory"

# 1374 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_RegisteredScott:
# 1375 "data/maps/SlateportCity/scripts.pory"
	.string "Registered this SCOTT person\n"
# 1376 "data/maps/SlateportCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1377 "data/maps/SlateportCity/scripts.pory"

# 1378 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
# 1379 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: What I'd like to do is tag along\n"
# 1380 "data/maps/SlateportCity/scripts.pory"
	.string "with you, but I do want to keep an eye\l"
# 1381 "data/maps/SlateportCity/scripts.pory"
	.string "on the talents of other people, too.\p"
# 1382 "data/maps/SlateportCity/scripts.pory"
	.string "So, I'll be off to roam other towns\n"
# 1383 "data/maps/SlateportCity/scripts.pory"
	.string "a bit more.\p"
# 1384 "data/maps/SlateportCity/scripts.pory"
	.string "Be seeing you, {PLAYER}{KUN}!$"
# 1385 "data/maps/SlateportCity/scripts.pory"

# 1386 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_TakingBattleTentChallenge:
# 1387 "data/maps/SlateportCity/scripts.pory"
	.string "SCOTT: Oh, hey!\n"
# 1388 "data/maps/SlateportCity/scripts.pory"
	.string "If it isn't {PLAYER}{KUN}!\p"
# 1389 "data/maps/SlateportCity/scripts.pory"
	.string "{PLAYER}{KUN}, let me guess--you're going\n"
# 1390 "data/maps/SlateportCity/scripts.pory"
	.string "to take the BATTLE TENT challenge?\p"
# 1391 "data/maps/SlateportCity/scripts.pory"
	.string "Yeah! That's a good idea!\n"
# 1392 "data/maps/SlateportCity/scripts.pory"
	.string "That's a really great idea!\p"
# 1393 "data/maps/SlateportCity/scripts.pory"
	.string "After all, a tough TRAINER is\n"
# 1394 "data/maps/SlateportCity/scripts.pory"
	.string "the perfect fit for the BATTLE TENT!\p"
# 1395 "data/maps/SlateportCity/scripts.pory"
	.string "Give it your best effort!$"
# 1396 "data/maps/SlateportCity/scripts.pory"

# 1397 "data/maps/SlateportCity/scripts.pory"
SlateportCity_Text_ComeBackWithBadge3:
# 1398 "data/maps/SlateportCity/scripts.pory"
	.string "Sorry, you'll need at least 3 badges\n"
# 1399 "data/maps/SlateportCity/scripts.pory"
	.string "to access my goods.$"

SlateportCity_EventScript_Lighthouse::
# 1403 "data/maps/SlateportCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_SLATEPORT_EGG, SlateportCity_EventScript_Lighthouse_2
SlateportCity_EventScript_Lighthouse_1:
	end

SlateportCity_EventScript_Lighthouse_2:
# 1404 "data/maps/SlateportCity/scripts.pory"
	lockall
# 1405 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_EventScript_Lighthouse_Text_0
# 1406 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_EventScript_Lighthouse_Text_1
# 1407 "data/maps/SlateportCity/scripts.pory"
	playse MUS_OBTAIN_ITEM
# 1408 "data/maps/SlateportCity/scripts.pory"
	msgbox SlateportCity_EventScript_Lighthouse_Text_2
# 1409 "data/maps/SlateportCity/scripts.pory"
	randomelement 1, 2, 3, 4, 5, 6, 7, 8, 9
# 1410 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_EventScript_Lighthouse_5
# 1414 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SlateportCity_EventScript_Lighthouse_6
# 1418 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq SlateportCity_EventScript_Lighthouse_7
# 1422 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq SlateportCity_EventScript_Lighthouse_8
# 1426 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq SlateportCity_EventScript_Lighthouse_9
# 1430 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq SlateportCity_EventScript_Lighthouse_10
# 1434 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq SlateportCity_EventScript_Lighthouse_11
# 1438 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq SlateportCity_EventScript_Lighthouse_12
# 1442 "data/maps/SlateportCity/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq SlateportCity_EventScript_Lighthouse_13
SlateportCity_EventScript_Lighthouse_4:
# 1446 "data/maps/SlateportCity/scripts.pory"
	waitse
# 1447 "data/maps/SlateportCity/scripts.pory"
	releaseall
	goto SlateportCity_EventScript_Lighthouse_1

SlateportCity_EventScript_Lighthouse_5:
# 1411 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_CHESPIN
# 1412 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_6:
# 1415 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_FENNEKIN
# 1416 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_7:
# 1419 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_FROAKIE
# 1420 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_8:
# 1423 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_ROWLET
# 1424 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_9:
# 1427 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_LITTEN
# 1428 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_10:
# 1431 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_POPPLIO
# 1432 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_11:
# 1435 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_GROOKEY
# 1436 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_12:
# 1439 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_SCORBUNNY
# 1440 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4

SlateportCity_EventScript_Lighthouse_13:
# 1443 "data/maps/SlateportCity/scripts.pory"
	giveegg SPECIES_SOBBLE
# 1444 "data/maps/SlateportCity/scripts.pory"
	setflag FLAG_RECEIVED_SLATEPORT_EGG
	goto SlateportCity_EventScript_Lighthouse_4


SlateportCity_EventScript_Lighthouse_Text_0:
# 1405 "data/maps/SlateportCity/scripts.pory"
	.string "There's something tucked away\nnext to the lighthouse...$"

SlateportCity_EventScript_Lighthouse_Text_1:
# 1406 "data/maps/SlateportCity/scripts.pory"
	.string "It's an EGG!$"

SlateportCity_EventScript_Lighthouse_Text_2:
# 1408 "data/maps/SlateportCity/scripts.pory"
	.string "YOU TOOK THE EGG WITH YOU.$"
