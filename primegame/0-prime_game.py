#!/usr/bin/python3
"""Prime game"""


def is_prime(n):
    """checks if a number is prime"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def count_primes(n):
    """Returns the count of prime numbers up to n"""
    sieve = [True] * (n + 1)
    sieve[0:2] = [False, False]
    count = 0
    for i in range(2, n + 1):
        if sieve[i]:
            count += 1
            for j in range(i * 2, n + 1, i):
                sieve[j] = False
    return count


def isWinner(x, nums):
    """Determin the winner of the prime game"""
    if not nums or x < 1:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        prime_count = count_primes(n)
        if prime_count % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1
        if maria_wins > ben_wins:
            return "Maria"
        elif ben_wins > maria_wins:
            return "Ben"
        return None
