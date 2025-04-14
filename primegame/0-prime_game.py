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
    """Determine the winner of the Prime Game."""
    if not nums or x < 1:
        return None

    # Precompute primes up to the max number in nums
    max_n = max(nums)
    sieve = [True] * (max_n + 1)
    sieve[0:2] = [False, False]

    for i in range(2, int(max_n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, max_n + 1, i):
                sieve[j] = False

    # Build prefix sum of prime counts
    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if sieve[i] else 0)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_count[n] % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None
