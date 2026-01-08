HealParty::
# 2 "data/scripts/healparty.pory"
	lockall
# 3 "data/scripts/healparty.pory"
	msgbox HealParty_Text_0, MSGBOX_YESNO
# 4 "data/scripts/healparty.pory"
	compare VAR_RESULT, 1
	goto_if_eq HealParty_2
HealParty_1:
# 10 "data/scripts/healparty.pory"
	compare VAR_RESULT, 0
	goto_if_eq HealParty_5
HealParty_4:
# 13 "data/scripts/healparty.pory"
	releaseall
	return

HealParty_2:
# 5 "data/scripts/healparty.pory"
	special HealPlayerParty
# 6 "data/scripts/healparty.pory"
	playfanfare MUS_HEAL
# 7 "data/scripts/healparty.pory"
	msgbox HealParty_Text_1, MSGBOX_DEFAULT
# 8 "data/scripts/healparty.pory"
	waitfanfare
	goto HealParty_1

HealParty_5:
	goto HealParty_4


HealParty_Text_0:
# 3 "data/scripts/healparty.pory"
	.string "Would you like to heal your party?$"

HealParty_Text_1:
# 7 "data/scripts/healparty.pory"
	.string "Your party has been fully healed.$"
