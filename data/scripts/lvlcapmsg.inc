lvlcapmsg::
# 2 "data/scripts/lvlcapmsg.pory"
	lockall
# 3 "data/scripts/lvlcapmsg.pory"
	playfanfare MUS_LEVEL_UP
# 4 "data/scripts/lvlcapmsg.pory"
	msgbox lvlcapmsg_Text_0
# 5 "data/scripts/lvlcapmsg.pory"
	waitfanfare
# 6 "data/scripts/lvlcapmsg.pory"
	releaseall
	return


lvlcapmsg_Text_0:
# 4 "data/scripts/lvlcapmsg.pory"
	.string "{COLOR RED}YOUR LEVEL CAP HAS INCREASED!$"
