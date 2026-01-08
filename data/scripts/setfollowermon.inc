SetFollowerMon::
# 2 "data/scripts/setfollowermon.pory"
	lockall
# 3 "data/scripts/setfollowermon.pory"
	msgbox SetFollowerMon_Text_0, MSGBOX_YESNO
# 4 "data/scripts/setfollowermon.pory"
	compare VAR_RESULT, 1
	goto_if_eq SetFollowerMon_2
SetFollowerMon_1:
# 9 "data/scripts/setfollowermon.pory"
	compare VAR_RESULT, 0
	goto_if_eq SetFollowerMon_5
SetFollowerMon_4:
# 15 "data/scripts/setfollowermon.pory"
	callnative UpdateFollowingPokemon
# 16 "data/scripts/setfollowermon.pory"
	releaseall
	return

SetFollowerMon_2:
# 5 "data/scripts/setfollowermon.pory"
	clearflag FLAG_FOLLOWERS_DISABLED
# 6 "data/scripts/setfollowermon.pory"
	playse SE_BALL_OPEN
# 7 "data/scripts/setfollowermon.pory"
	msgbox SetFollowerMon_Text_1
	goto SetFollowerMon_1

SetFollowerMon_5:
# 10 "data/scripts/setfollowermon.pory"
	setflag FLAG_FOLLOWERS_DISABLED
# 11 "data/scripts/setfollowermon.pory"
	callnative PlayFollowerReturnAnimationNative
# 12 "data/scripts/setfollowermon.pory"
	playse SE_BALL_OPEN
# 13 "data/scripts/setfollowermon.pory"
	msgbox SetFollowerMon_Text_2
	goto SetFollowerMon_4


SetFollowerMon_Text_0:
# 3 "data/scripts/setfollowermon.pory"
	.string "Will you walk with your POKéMON?$"

SetFollowerMon_Text_1:
# 7 "data/scripts/setfollowermon.pory"
	.string "Your POKèMON is now following you!$"

SetFollowerMon_Text_2:
# 13 "data/scripts/setfollowermon.pory"
	.string "Your POKéMON returned to its ball.$"
