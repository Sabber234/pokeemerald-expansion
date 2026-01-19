# 1 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_MapScripts::
# 2 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.byte 0
# 3 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 4 "data/maps/MauvilleCity_GameCorner/scripts.pory"
    @ Game Corner prices
# 5 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_DOUBLE_TEAM_COINS, 1500
# 6 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_PSYCHIC_COINS, 3500
# 7 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_FLAMETHROWER_COINS, 4000
# 8 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_THUNDERBOLT_COINS, 4000
# 9 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_ICE_BEAM_COINS, 4000
# 10 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set DOLL_COINS, 1000
# 11 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 12 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_50,  1000
# 13 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_500, 10000
# 14 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 15 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CoinsClerk::
# 16 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 17 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 18 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
# 19 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 20 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
# 21 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
# 22 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 23 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmoneybox 0, 0
# 24 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 6
# 25 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50
# 26 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 27 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
# 28 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
# 29 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 30 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 31 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 32 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 33 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 34 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 35 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 36 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
# 37 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
# 38 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 39 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
# 40 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
# 41 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
# 42 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 43 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 44 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy50Coins::
# 45 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 46 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 47 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_50
# 48 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 49 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 50
# 50 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_50
# 51 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 52 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 53 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 54 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 55 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 56 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 57 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 58 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 59 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 60 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Buy500Coins::
# 61 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 62 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
# 63 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkmoney COINS_PRICE_500
# 64 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
# 65 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 500
# 66 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removemoney COINS_PRICE_500
# 67 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatemoneybox
# 68 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 6
# 69 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 70 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
# 71 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 72 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 73 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 74 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 75 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 76 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NeedCoinCase::
# 77 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
# 78 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 79 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 80 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 81 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
# 82 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
# 83 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 84 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 85 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 86 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 87 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 88 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
# 89 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
# 90 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 91 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 92 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 93 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 94 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 95 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
# 96 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
# 97 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemoneybox
# 98 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 5
# 99 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 100 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 101 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 102 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
# 103 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 104 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 105 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 106 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 107 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage
# 108 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 109 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 110 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrizeMessage::
# 112 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 113 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 114 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 115 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 116 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 117 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 118 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize::
# 119 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 120 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 121 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseDollPrize
# 122 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 123 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseDollPrize::
# 124 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
# 125 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 126 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TreeckoDoll
# 127 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TorchicDoll
# 128 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_MudkipDoll
# 129 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 130 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 131 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 132 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 133 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TreeckoDoll::
# 134 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 135 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
# 136 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 137 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 138 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TorchicDoll::
# 139 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 140 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
# 141 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 142 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 143 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_MudkipDoll::
# 144 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 145 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
# 146 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmDollPrize
# 147 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 148 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmDollPrize::
# 149 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
# 150 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelDollSelect
# 151 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 152 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll
# 153 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTorchicDoll
# 154 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyMudkipDoll
# 155 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 156 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 157 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTreeckoDoll::
# 158 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 159 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 160 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 161 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 162 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 163 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 164 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TREECKO_DOLL
# 165 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 166 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 167 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 168 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 169 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 170 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 171 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTorchicDoll::
# 172 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 173 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 174 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 175 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 176 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 177 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 178 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_TORCHIC_DOLL
# 179 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 180 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 181 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 182 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 183 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 184 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 185 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyMudkipDoll::
# 186 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 187 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, DOLL_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll
# 188 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 189 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 190 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForDoll
# 191 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins DOLL_COINS
# 192 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	adddecoration DECOR_MUDKIP_DOLL
# 193 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 194 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 195 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
# 196 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 197 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 198 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 199 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
# 200 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 201 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 202 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 203 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 204 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForDoll::
# 205 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 206 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseDollPrize
# 207 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 208 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 209 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelDollSelect::
# 210 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 211 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 212 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 213 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 214 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 215 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
# 216 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 217 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 218 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
# 219 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 220 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage
# 221 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 222 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 223 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 224 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrizeMessage::
# 225 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 226 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 227 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 0
# 228 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showcoinsbox 1, 1
# 229 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 230 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 231 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize::
# 232 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	message MauvilleCity_GameCorner_Text_WhichPrize
# 233 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmessage
# 234 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ChooseTMPrize
# 235 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 236 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ChooseTMPrize::
# 237 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
# 238 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_RESULT
# 239 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_TMDoubleTeam
# 240 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_TMPsychic
# 241 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_TMFlamethrower
# 242 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_TMThunderbolt
# 243 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_TMIceBeam
# 244 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 245 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 246 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 247 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 248 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMDoubleTeam::
# 249 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 1
# 250 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
# 251 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
# 252 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 253 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 254 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMPsychic::
# 255 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 2
# 256 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
# 257 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
# 258 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 259 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 260 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMFlamethrower::
# 261 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 3
# 262 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
# 263 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
# 264 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 265 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 266 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMThunderbolt::
# 267 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 4
# 268 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
# 269 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
# 270 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 271 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 272 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TMIceBeam::
# 273 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_TEMP_1, 5
# 274 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
# 275 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
# 276 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ConfirmTMPrize
# 277 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 278 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ConfirmTMPrize::
# 279 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	special BufferTMHMMoveName
# 280 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
# 281 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_CancelTMSelect
# 282 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_TEMP_1
# 283 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam
# 284 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_BuyTMPsychic
# 285 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 3, MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower
# 286 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 4, MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt
# 287 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 5, MauvilleCity_GameCorner_EventScript_BuyTMIceBeam
# 288 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 289 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 290 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMDoubleTeam::
# 291 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 292 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 293 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_DOUBLE_TEAM
# 294 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 295 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_DOUBLE_TEAM_COINS
# 296 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_DOUBLE_TEAM
# 297 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 298 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 299 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 300 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 301 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 302 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 303 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMPsychic::
# 304 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 305 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 306 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_PSYCHIC
# 307 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 308 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_PSYCHIC_COINS
# 309 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_PSYCHIC
# 310 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 311 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 312 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 313 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 314 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 315 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 316 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMFlamethrower::
# 317 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 318 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 319 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_FLAMETHROWER
# 320 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 321 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_FLAMETHROWER_COINS
# 322 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_FLAMETHROWER
# 323 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 324 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 325 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 326 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 327 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 328 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 329 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMThunderbolt::
# 330 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 331 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 332 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_THUNDERBOLT
# 333 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 334 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_THUNDERBOLT_COINS
# 335 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_THUNDERBOLT
# 336 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 337 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 338 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 339 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 340 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 341 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 342 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_BuyTMIceBeam::
# 343 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_2
# 344 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM
# 345 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitemspace ITEM_TM_ICE_BEAM
# 346 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForTM
# 347 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	removecoins TM_ICE_BEAM_COINS
# 348 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	additem ITEM_TM_ICE_BEAM
# 349 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	updatecoinsbox 1, 1
# 350 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 351 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
# 352 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 353 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 354 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 355 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForTM::
# 356 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
# 357 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 358 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 359 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 360 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForTM::
# 361 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_BagIsFull
# 362 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseTMPrize
# 363 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 364 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 365 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_CancelTMSelect::
# 366 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
# 367 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidecoinsbox 0, 0
# 368 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 369 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 370 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 371 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman2::
# 372 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
# 373 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 374 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 375 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Gentleman::
# 376 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
# 377 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 378 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 379 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Girl::
# 380 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 381 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 382 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 383 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
# 384 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
# 385 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	switch VAR_STARTER_MON
# 386 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
# 387 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
# 388 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
# 389 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 390 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 391 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
# 392 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
# 393 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TREECKO_DOLL
# 394 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 395 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 396 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TREECKO_DOLL
# 397 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 398 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 399 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 400 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 401 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
# 402 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
# 403 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_TORCHIC_DOLL
# 404 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 405 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 406 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_TORCHIC_DOLL
# 407 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 408 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 409 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 410 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 411 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
# 412 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
# 413 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkdecorspace DECOR_MUDKIP_DOLL
# 414 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
# 415 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
# 416 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givedecoration DECOR_MUDKIP_DOLL
# 417 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_STARTER_DOLL
# 418 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
# 419 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 420 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 421 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
# 422 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 423 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
# 424 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 425 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 426 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 427 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
# 428 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
# 429 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 430 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 431 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 432 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
# 433 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
# 434 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 435 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 436 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 437 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanM::
# 438 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 439 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 440 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 441 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
# 442 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
# 443 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 444 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 445 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 446 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_TryGive20Coins::
# 447 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 448 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkcoins VAR_TEMP_1
# 449 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
# 450 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_RECEIVED_20_COINS
# 451 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	addcoins 20
# 452 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
# 453 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playse SE_SHOP
# 454 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
# 455 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 456 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 457 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_PokefanMNormal::
# 458 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
# 459 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 460 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 461 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 462 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_OldMan::
# 463 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 464 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 465 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
# 466 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 467 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 468 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 469 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Cook::
# 470 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 471 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 472 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
# 473 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 474 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 475 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 476 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Man::
# 477 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 478 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 479 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
# 480 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 481 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 482 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 483 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
# 484 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	closemessage
# 485 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 486 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitmovement 0
# 487 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	release
# 488 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 489 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 490 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Maniac::
# 491 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 492 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 493 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
# 494 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 495 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 496 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 497 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_Woman::
# 498 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lock
# 499 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 500 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
# 501 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
# 502 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 503 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 504 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine0::
# 505 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 506 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 507 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 508 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 0
# 509 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 510 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 511 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 512 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 513 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 514 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine1::
# 515 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 516 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 517 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 518 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 1
# 519 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 520 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 521 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 522 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 523 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 524 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine2::
# 525 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 526 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 527 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 528 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 2
# 529 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 530 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 531 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 532 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 533 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 534 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine3::
# 535 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 536 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 537 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 538 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 3
# 539 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 540 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 541 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 542 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 543 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 544 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine4::
# 545 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 546 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 547 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 548 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 4
# 549 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 550 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 551 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 552 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 553 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 554 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine5::
# 555 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 556 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 557 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 558 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 5
# 559 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 560 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 561 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 562 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 563 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 564 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine6::
# 565 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 566 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 567 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 568 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 6
# 569 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 570 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 571 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 572 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 573 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 574 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine7::
# 575 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 576 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 577 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 578 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 7
# 579 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 580 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 581 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 582 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 583 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 584 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine8::
# 585 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 586 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 587 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 588 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 8
# 589 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 590 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 591 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 592 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 593 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 594 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine9::
# 595 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 596 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 597 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 598 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 9
# 599 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 600 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 601 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 602 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 603 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 604 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine10::
# 605 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 606 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 607 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 608 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 10
# 609 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 610 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 611 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 612 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 613 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 614 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_SlotMachine11::
# 615 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 616 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	checkitem ITEM_COIN_CASE
# 617 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
# 618 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setvar VAR_0x8004, 11
# 619 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	specialvar VAR_RESULT, GetSlotMachineId
# 620 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playslotmachine VAR_RESULT
# 621 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 622 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 623 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 624 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_EventScript_NoCoinCase::
# 625 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
# 626 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
# 627 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	end
# 628 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 629 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
# 630 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is MAUVILLE GAME CORNER.$"
# 631 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 632 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
# 633 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Okay, you wanted some COINS for\n"
# 634 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the games?\p"
# 635 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "But you don't have a COIN CASE for\n"
# 636 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "stowing the COINS.$"
# 637 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 638 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
# 639 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Were you looking for COINS?\p"
# 640 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's ¥1000 for 50 COINS.\n"
# 641 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like some?$"
# 642 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 643 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
# 644 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you very much!\n"
# 645 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here are your COINS!$"
# 646 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 647 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
# 648 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Um… You don't appear to have\n"
# 649 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "enough money…$"
# 650 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 651 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinCaseIsFull:
# 652 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh?\n"
# 653 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Your COIN CASE is full.$"
# 654 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 655 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
# 656 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh… You don't need COINS, then?\n"
# 657 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Good luck on your adventure!$"
# 658 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 659 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
# 660 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
# 661 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can exchange your COINS for\n"
# 662 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "prizes here.$"
# 663 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 664 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_WhichPrize:
# 665 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which prize would you like?$"
# 666 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 667 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
# 668 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is\n"
# 669 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"
# 670 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 671 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SendToYourHomePC:
# 672 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you!\n"
# 673 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 674 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 675 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NotEnoughCoins:
# 676 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS.$"
# 677 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 678 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 679 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
# 680 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There isn't any room available for\n"
# 681 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "placing {STR_VAR_1}.$"
# 682 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 683 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_OhIsThatSo:
# 684 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, is that so? \n"
# 685 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You need to save some COINS before\l"
# 686 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "coming back here.$"
# 687 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 688 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
# 689 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"
# 690 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 691 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo:
# 692 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 693 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 694 "data/maps/MauvilleCity_GameCorner/scripts.pory"
@ Unused
# 695 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
# 696 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, you can't carry any more than that.$"
# 697 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 698 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
# 699 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I made a mistake and got two of\n"
# 700 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the same DOLLS.\p"
# 701 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Would you like one of them?$"
# 702 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 703 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HereYouGo2:
# 704 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"
# 705 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 706 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_YouWantItButNotNow:
# 707 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh?\n"
# 708 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You want it, but not right now?$"
# 709 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 710 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DontBeNegative:
# 711 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, don't be so negative!\n"
# 712 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can have this!$"
# 713 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 714 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantWinJackpot:
# 715 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
# 716 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the jackpot.$"
# 717 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 718 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
# 719 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hey, kid, if you want to play here,\n"
# 720 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "you need a COIN CASE.\p"
# 721 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I think the young lady next door\n"
# 722 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "had one. Go see her!$"
# 723 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 724 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
# 725 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "My luck can only last so long.\n"
# 726 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is too much for me.\l"
# 727 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here, take some COINS!$"
# 728 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 729 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
# 730 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "MAUVILLE has something for\n"
# 731 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "everyone.\p"
# 732 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "For me, it's the GAME CORNER.$"
# 733 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 734 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
# 735 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The ROULETTE tables have different\n"
# 736 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "rates.\p"
# 737 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Check your COINS if you're going to\n"
# 738 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "pick a table.$"
# 739 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 740 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
# 741 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's easy to lose track of time in here. \n"
# 742 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I should get back to work.$"
# 743 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 744 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
# 745 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "COINS are needed to play here\n"
# 746 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "in the GAME CORNER.$"
# 747 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 748 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
# 749 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This ROULETTE thing…\n"
# 750 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's rather demanding.\p"
# 751 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Win or lose, it's only by luck.$"
# 752 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 753 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
# 754 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Up to three COINS can be used to play\n"
# 755 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the SLOTS.$"
# 756 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 757 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_DifficultToStopOn7:
# 758 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's very difficult to make it stop\n"
# 759 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "right on “7.”\p"
# 760 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "If it stops on “7” during the REEL TIME\n"
# 761 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonus game, you'll receive extra COINS.$"
# 762 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 763 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
# 764 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here's some information for you\n"
# 765 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "about the SLOTS.\p"
# 766 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The more lightning bolts you stock,\n"
# 767 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "the more REEL TIME chances you get.\p"
# 768 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "In a game with the maximum five\n"
# 769 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "REEL TIME chances…\p"
# 770 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It is possible to receive four regular\n"
# 771 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "bonuses, then a big bonus.\p"
# 772 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "That would total 660 COINS, but it's\n"
# 773 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "very difficult to get.$"
# 774 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 775 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
# 776 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can't play if you don't have\n"
# 777 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "a COIN CASE.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk::
# 782 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	lockall
# 783 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	faceplayer
# 784 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_unset FLAG_GAME_CORNER_PKMN_RECEIVED, MauvilleCity_GameCorner_EventScript_PkmnClerk_2
MauvilleCity_GameCorner_EventScript_PkmnClerk_1:
# 1115 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_GAME_CORNER_PKMN_RECEIVED, MauvilleCity_GameCorner_EventScript_PkmnClerk_5
MauvilleCity_GameCorner_EventScript_PkmnClerk_4:
# 1118 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	return

MauvilleCity_GameCorner_EventScript_PkmnClerk_2:
# 785 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_0, MSGBOX_DEFAULT
# 786 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_1
# 787 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	multichoicedefault 0, 0, MULTI_GAME_CORNER_PKMN, 0, 0
# 788 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_9
MauvilleCity_GameCorner_EventScript_PkmnClerk_7:
# 818 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_14
MauvilleCity_GameCorner_EventScript_PkmnClerk_12:
# 848 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_22
MauvilleCity_GameCorner_EventScript_PkmnClerk_20:
# 878 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_36
MauvilleCity_GameCorner_EventScript_PkmnClerk_34:
# 908 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_53
MauvilleCity_GameCorner_EventScript_PkmnClerk_51:
# 958 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_70
MauvilleCity_GameCorner_EventScript_PkmnClerk_68:
# 1008 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_87
MauvilleCity_GameCorner_EventScript_PkmnClerk_85:
# 1058 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_104
MauvilleCity_GameCorner_EventScript_PkmnClerk_102:
# 1108 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_122
# 1111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_lt MauvilleCity_GameCorner_EventScript_PkmnClerk_123
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_1

MauvilleCity_GameCorner_EventScript_PkmnClerk_5:
# 1116 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_4

MauvilleCity_GameCorner_EventScript_PkmnClerk_8:
# 789 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_MAGBY, 10, 3
# 790 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_2, MSGBOX_DEFAULT
# 791 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 792 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_ELEKID, 10, 3
# 793 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_3, MSGBOX_DEFAULT
# 794 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 795 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 796 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_18
MauvilleCity_GameCorner_EventScript_PkmnClerk_17:
# 812 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_29
MauvilleCity_GameCorner_EventScript_PkmnClerk_28:
# 815 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_9:
# 788 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_8
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_7

MauvilleCity_GameCorner_EventScript_PkmnClerk_13:
# 819 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_ZANGOOSE, 10, 3
# 820 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_8, MSGBOX_DEFAULT
# 821 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 822 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_SEVIPER, 10, 3
# 823 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_9, MSGBOX_DEFAULT
# 824 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 825 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 826 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_26
MauvilleCity_GameCorner_EventScript_PkmnClerk_25:
# 842 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_43
MauvilleCity_GameCorner_EventScript_PkmnClerk_42:
# 845 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_14:
# 818 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_13
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_12

MauvilleCity_GameCorner_EventScript_PkmnClerk_18:
# 797 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 798 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 799 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_32
MauvilleCity_GameCorner_EventScript_PkmnClerk_31:
# 803 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_49
MauvilleCity_GameCorner_EventScript_PkmnClerk_48:
# 807 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 808 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 809 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 810 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_17

MauvilleCity_GameCorner_EventScript_PkmnClerk_21:
# 849 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_MISDREAVUS, 10, 3
# 850 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_12, MSGBOX_DEFAULT
# 851 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 852 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_MURKROW, 10, 3
# 853 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_13, MSGBOX_DEFAULT
# 854 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 855 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 856 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_40
MauvilleCity_GameCorner_EventScript_PkmnClerk_39:
# 872 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_60
MauvilleCity_GameCorner_EventScript_PkmnClerk_59:
# 875 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_22:
# 848 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_21
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_20

MauvilleCity_GameCorner_EventScript_PkmnClerk_26:
# 827 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 828 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 829 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_46
MauvilleCity_GameCorner_EventScript_PkmnClerk_45:
# 833 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_66
MauvilleCity_GameCorner_EventScript_PkmnClerk_65:
# 837 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 838 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 839 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 840 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_25

MauvilleCity_GameCorner_EventScript_PkmnClerk_29:
# 813 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_28

MauvilleCity_GameCorner_EventScript_PkmnClerk_32:
# 800 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_MAGBY, 20
# 801 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_5
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_31

MauvilleCity_GameCorner_EventScript_PkmnClerk_35:
# 879 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_TURTONATOR, 10, 3
# 880 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_16, MSGBOX_DEFAULT
# 881 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 882 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_DRAMPA, 10, 3
# 883 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_17, MSGBOX_DEFAULT
# 884 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 885 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 886 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_57
MauvilleCity_GameCorner_EventScript_PkmnClerk_56:
# 902 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_77
MauvilleCity_GameCorner_EventScript_PkmnClerk_76:
# 905 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_36:
# 878 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_35
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_34

MauvilleCity_GameCorner_EventScript_PkmnClerk_40:
# 857 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 858 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 859 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_63
MauvilleCity_GameCorner_EventScript_PkmnClerk_62:
# 863 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_83
MauvilleCity_GameCorner_EventScript_PkmnClerk_82:
# 867 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 868 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 869 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 870 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_39

MauvilleCity_GameCorner_EventScript_PkmnClerk_43:
# 843 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_42

MauvilleCity_GameCorner_EventScript_PkmnClerk_46:
# 830 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_ZANGOOSE, 20
# 831 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_10
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_45

MauvilleCity_GameCorner_EventScript_PkmnClerk_49:
# 804 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_ELEKID, 20
# 805 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_6
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_48

MauvilleCity_GameCorner_EventScript_PkmnClerk_52:
# 909 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_BELDUM, 10, 3
# 910 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_20, MSGBOX_DEFAULT
# 911 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 912 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_FRIGIBAX, 10, 3
# 913 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_21, MSGBOX_DEFAULT
# 914 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 915 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_GOOMY, 10, 3
# 916 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_22, MSGBOX_DEFAULT
# 917 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 918 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_DREEPY, 10, 3
# 919 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_23, MSGBOX_DEFAULT
# 920 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 921 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 922 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_74
MauvilleCity_GameCorner_EventScript_PkmnClerk_73:
# 952 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_94
MauvilleCity_GameCorner_EventScript_PkmnClerk_93:
# 955 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_53:
# 908 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_52
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_51

MauvilleCity_GameCorner_EventScript_PkmnClerk_57:
# 887 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 888 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 889 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_80
MauvilleCity_GameCorner_EventScript_PkmnClerk_79:
# 893 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_100
MauvilleCity_GameCorner_EventScript_PkmnClerk_99:
# 897 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 898 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 899 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 900 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_56

MauvilleCity_GameCorner_EventScript_PkmnClerk_60:
# 873 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_59

MauvilleCity_GameCorner_EventScript_PkmnClerk_63:
# 860 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_MISDREAVUS, 20
# 861 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_14
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_62

MauvilleCity_GameCorner_EventScript_PkmnClerk_66:
# 834 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_SEVIPER, 20
# 835 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_11
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_65

MauvilleCity_GameCorner_EventScript_PkmnClerk_69:
# 959 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_SLITHER_WING, 10, 3
# 960 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_28, MSGBOX_DEFAULT
# 961 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 962 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_IRON_MOTH, 10, 3
# 963 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_29, MSGBOX_DEFAULT
# 964 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 965 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_ROARING_MOON, 10, 3
# 966 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_30, MSGBOX_DEFAULT
# 967 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 968 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_IRON_VALIANT, 10, 3
# 969 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_31, MSGBOX_DEFAULT
# 970 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 971 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 972 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_91
MauvilleCity_GameCorner_EventScript_PkmnClerk_90:
# 1002 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_111
MauvilleCity_GameCorner_EventScript_PkmnClerk_110:
# 1005 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_70:
# 958 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_69
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_68

MauvilleCity_GameCorner_EventScript_PkmnClerk_74:
# 923 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 924 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 925 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_97
MauvilleCity_GameCorner_EventScript_PkmnClerk_96:
# 936 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_117
MauvilleCity_GameCorner_EventScript_PkmnClerk_116:
# 947 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 948 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 949 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 950 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_73

MauvilleCity_GameCorner_EventScript_PkmnClerk_77:
# 903 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_76

MauvilleCity_GameCorner_EventScript_PkmnClerk_80:
# 890 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_TURTONATOR, 20
# 891 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_18
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_79

MauvilleCity_GameCorner_EventScript_PkmnClerk_83:
# 864 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_MURKROW, 20
# 865 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_15
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_82

MauvilleCity_GameCorner_EventScript_PkmnClerk_86:
# 1009 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_WALKING_WAKE, 10, 3
# 1010 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_36, MSGBOX_DEFAULT
# 1011 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1012 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_IRON_LEAVES, 10, 3
# 1013 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_37, MSGBOX_DEFAULT
# 1014 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1015 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_GOUGING_FIRE, 10, 3
# 1016 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_38, MSGBOX_DEFAULT
# 1017 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1018 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_IRON_CROWN, 10, 3
# 1019 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_39, MSGBOX_DEFAULT
# 1020 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1021 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 1022 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_108
MauvilleCity_GameCorner_EventScript_PkmnClerk_107:
# 1052 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_130
MauvilleCity_GameCorner_EventScript_PkmnClerk_129:
# 1055 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_87:
# 1008 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_86
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_85

MauvilleCity_GameCorner_EventScript_PkmnClerk_91:
# 973 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 974 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 975 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_114
MauvilleCity_GameCorner_EventScript_PkmnClerk_113:
# 986 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_136
MauvilleCity_GameCorner_EventScript_PkmnClerk_135:
# 997 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 998 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 999 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 1000 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_90

MauvilleCity_GameCorner_EventScript_PkmnClerk_94:
# 953 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_93

MauvilleCity_GameCorner_EventScript_PkmnClerk_97:
# 926 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 927 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_120
MauvilleCity_GameCorner_EventScript_PkmnClerk_119:
# 931 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_144
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_96

MauvilleCity_GameCorner_EventScript_PkmnClerk_100:
# 894 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_DRAMPA, 20
# 895 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_19
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_99

MauvilleCity_GameCorner_EventScript_PkmnClerk_103:
# 1059 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_MARSHADOW, 10, 3
# 1060 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_44, MSGBOX_DEFAULT
# 1061 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1062 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_ZERAORA, 10, 3
# 1063 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_45, MSGBOX_DEFAULT
# 1064 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1065 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_MELOETTA, 10, 3
# 1066 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_46, MSGBOX_DEFAULT
# 1067 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1068 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	showmonpic SPECIES_PECHARUNT, 10, 3
# 1069 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_47, MSGBOX_DEFAULT
# 1070 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1071 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4, MSGBOX_YESNO
# 1072 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_127
MauvilleCity_GameCorner_EventScript_PkmnClerk_126:
# 1102 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_147
MauvilleCity_GameCorner_EventScript_PkmnClerk_146:
# 1105 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	releaseall
	end

MauvilleCity_GameCorner_EventScript_PkmnClerk_104:
# 1058 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, MauvilleCity_GameCorner_EventScript_PkmnClerk_103
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_102

MauvilleCity_GameCorner_EventScript_PkmnClerk_108:
# 1023 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 1024 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 1025 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_133
MauvilleCity_GameCorner_EventScript_PkmnClerk_132:
# 1036 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_153
MauvilleCity_GameCorner_EventScript_PkmnClerk_152:
# 1047 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 1048 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1049 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 1050 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_107

MauvilleCity_GameCorner_EventScript_PkmnClerk_111:
# 1003 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_110

MauvilleCity_GameCorner_EventScript_PkmnClerk_114:
# 976 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 977 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_139
MauvilleCity_GameCorner_EventScript_PkmnClerk_138:
# 981 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_161
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_113

MauvilleCity_GameCorner_EventScript_PkmnClerk_117:
# 937 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 938 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_142
MauvilleCity_GameCorner_EventScript_PkmnClerk_141:
# 942 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_163
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_116

MauvilleCity_GameCorner_EventScript_PkmnClerk_120:
# 928 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_BELDUM, 20
# 929 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_24
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_119

MauvilleCity_GameCorner_EventScript_PkmnClerk_122:
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_1

MauvilleCity_GameCorner_EventScript_PkmnClerk_123:
# 1112 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_52
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_1

MauvilleCity_GameCorner_EventScript_PkmnClerk_127:
# 1073 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
# 1074 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 1075 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_150
MauvilleCity_GameCorner_EventScript_PkmnClerk_149:
# 1086 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_166
MauvilleCity_GameCorner_EventScript_PkmnClerk_165:
# 1097 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	waitfanfare
# 1098 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
# 1099 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	setflag FLAG_GAME_CORNER_PKMN_RECEIVED
# 1100 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_126

MauvilleCity_GameCorner_EventScript_PkmnClerk_130:
# 1053 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_129

MauvilleCity_GameCorner_EventScript_PkmnClerk_133:
# 1026 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 1027 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_156
MauvilleCity_GameCorner_EventScript_PkmnClerk_155:
# 1031 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_174
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_132

MauvilleCity_GameCorner_EventScript_PkmnClerk_136:
# 987 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 988 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_159
MauvilleCity_GameCorner_EventScript_PkmnClerk_158:
# 992 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_176
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_135

MauvilleCity_GameCorner_EventScript_PkmnClerk_139:
# 978 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_SLITHER_WING, 20
# 979 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_32
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_138

MauvilleCity_GameCorner_EventScript_PkmnClerk_142:
# 939 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_GOOMY, 20
# 940 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_26
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_141

MauvilleCity_GameCorner_EventScript_PkmnClerk_144:
# 932 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_FRIGIBAX, 20
# 933 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_25
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_96

MauvilleCity_GameCorner_EventScript_PkmnClerk_147:
# 1103 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	hidemonpic
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_146

MauvilleCity_GameCorner_EventScript_PkmnClerk_150:
# 1076 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 1077 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_169
MauvilleCity_GameCorner_EventScript_PkmnClerk_168:
# 1081 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_181
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_149

MauvilleCity_GameCorner_EventScript_PkmnClerk_153:
# 1037 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 1038 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_172
MauvilleCity_GameCorner_EventScript_PkmnClerk_171:
# 1042 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_183
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_152

MauvilleCity_GameCorner_EventScript_PkmnClerk_156:
# 1028 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_WALKING_WAKE, 20, ITEM_BOOSTER_ENERGY
# 1029 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_40
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_155

MauvilleCity_GameCorner_EventScript_PkmnClerk_159:
# 989 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_ROARING_MOON, 20
# 990 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_34
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_158

MauvilleCity_GameCorner_EventScript_PkmnClerk_161:
# 982 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_IRON_MOTH, 20
# 983 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_33
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_113

MauvilleCity_GameCorner_EventScript_PkmnClerk_163:
# 943 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_DREEPY, 20
# 944 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_27
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_116

MauvilleCity_GameCorner_EventScript_PkmnClerk_166:
# 1087 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	randompercentage 50
# 1088 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_179
MauvilleCity_GameCorner_EventScript_PkmnClerk_178:
# 1092 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_PkmnClerk_185
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_165

MauvilleCity_GameCorner_EventScript_PkmnClerk_169:
# 1078 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_MARSHADOW, 20
# 1079 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_48
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_168

MauvilleCity_GameCorner_EventScript_PkmnClerk_172:
# 1039 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_GOUGING_FIRE, 20, ITEM_BOOSTER_ENERGY
# 1040 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_42
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_171

MauvilleCity_GameCorner_EventScript_PkmnClerk_174:
# 1032 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_IRON_LEAVES, 20, ITEM_BOOSTER_ENERGY
# 1033 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_41
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_132

MauvilleCity_GameCorner_EventScript_PkmnClerk_176:
# 993 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_IRON_VALIANT, 20, ITEM_BOOSTER_ENERGY
# 994 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_35
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_135

MauvilleCity_GameCorner_EventScript_PkmnClerk_179:
# 1089 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_MELOETTA, 20
# 1090 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_50
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_178

MauvilleCity_GameCorner_EventScript_PkmnClerk_181:
# 1082 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_ZERAORA, 20
# 1083 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_49
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_149

MauvilleCity_GameCorner_EventScript_PkmnClerk_183:
# 1043 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_IRON_CROWN, 20, ITEM_BOOSTER_ENERGY
# 1044 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_43
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_152

MauvilleCity_GameCorner_EventScript_PkmnClerk_185:
# 1093 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	givemon SPECIES_PECHARUNT, 20
# 1094 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	msgbox MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_51
	goto MauvilleCity_GameCorner_EventScript_PkmnClerk_165


MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_0:
# 785 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Are you taking on HOENN's gyms? If so,\nyou're elligible for a prize!\pThe GAME CORNER is holding a limited\nevent for trainers like you right now!\pIf you show us a GYM BADGE you've won,\nyou can receive a special POKéMON\pdepending on the BADGE!\pBut be aware, the selected POKéMON is\nrandom, and you can only do this once.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_1:
# 786 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So, will you look at the available\n"
	.string "POKéMON?$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_2:
# 790 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The STONE BADGE randomly gives you\neither MAGBY,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_3:
# 793 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or ELEKID.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_4:
# 795 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Will you take this chance?$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_5:
# 801 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED MAGBY!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_6:
# 805 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED ELEKID!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_7:
# 810 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Take good care of your new POKéMON.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_8:
# 820 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The KNUCKLE BADGE randomly gives you\neither ZANGOOSE,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_9:
# 823 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or SEVIPER.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_10:
# 831 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED ZANGOOSE!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_11:
# 835 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED SEVIPER!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_12:
# 850 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The DYNAMO BADGE randomly gives you\neither MISDREAVUS,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_13:
# 853 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or MURKROW.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_14:
# 861 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED MISDREAVUS!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_15:
# 865 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED MURKROW!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_16:
# 880 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The HEAT BADGE randomly gives you\neither TURTONATOR,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_17:
# 883 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or DRAMPA.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_18:
# 891 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED TURTONATOR!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_19:
# 895 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED DRAMPA!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_20:
# 910 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The BALANCE BADGE randomly gives you\neither BELDUM,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_21:
# 913 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "FRIGIBAX,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_22:
# 916 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "GOOMY,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_23:
# 919 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or DREEPY.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_24:
# 929 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED BELDUM!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_25:
# 933 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED FRIGIBAX!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_26:
# 940 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED GOOMY!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_27:
# 944 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED DREEPY!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_28:
# 960 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The FEATHER BADGE randomly gives you\neither SLITHER WING,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_29:
# 963 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "IRON MOTH,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_30:
# 966 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "ROARING_MOON,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_31:
# 969 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or IRON_VALIANT.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_32:
# 979 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED SLITHER WING!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_33:
# 983 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED IRON MOTH!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_34:
# 990 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED ROARING MOON!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_35:
# 994 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED IRON VALIANT!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_36:
# 1010 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The MIND BADGE randomly gives you\neither WALKING WAKE,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_37:
# 1013 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "IRON LEAVES,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_38:
# 1016 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "GOUGING FIRE,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_39:
# 1019 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or IRON CROWN.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_40:
# 1029 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED WALKING WAKE!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_41:
# 1033 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED IRON LEAVES!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_42:
# 1040 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED GOUGING FIRE!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_43:
# 1044 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED IRON CROWN!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_44:
# 1060 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The BALANCE BADGE randomly gives you\neither MARSHADOW,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_45:
# 1063 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "ZERAORA,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_46:
# 1066 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "MELOETTA,$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_47:
# 1069 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "or PECHARUNT.$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_48:
# 1079 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED MARSHADOW!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_49:
# 1083 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED ZERAORA!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_50:
# 1090 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED MELOETTA!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_51:
# 1094 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "RECEIVED PECHARUNT!$"

MauvilleCity_GameCorner_EventScript_PkmnClerk_Text_52:
# 1112 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I'm sorry, it seems you don't have that\n"
	.string "badge yet.$"
