#!/usr/bin/python3
"""module change"""


def makeChange(coins, total):
    """function to determine the minimum number
    of coins to make change for a given total
    """
    coins.sort(reverse=True)
    count = 0

    for coin in coins:
        if total <= 0:
            return 0
        li = [total + 1] * (total + 1)
        li[0] = 0
        for coin in coins:
            for amount in range(coin, total + 1):
                li[amount] = min(li[amount], li[amount - coin] + 1)
        if li[total] != total + 1:
            return li[total]
        else:
            return -1
