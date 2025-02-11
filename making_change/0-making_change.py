#!/usr/bin/python3
"""module change"""


def makeChange(coins, total):
    """function to determine the minimum number
    of coins to make change for a given total
    """
    coins.sort(reverse=True)
    count = 0

    for coin in coins:
        if total == 0:
            break
        num_coins = total // coin
        count += num_coins
        total -= num_coins * coin

    return count if total == 0 else - 1
