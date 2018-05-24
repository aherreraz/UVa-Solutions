import sys

def sieve(size):
    global bs
    global sieve_size
    global primes
    sieve_size = size
    bs = [True] * sieve_size
    primes = []
    bs[0] = bs[1] = False
    for i in range(2, size):
        if bs[i]:
            for j in range(i * i, size, i):
                bs[j] = False
            primes.append(i)

def isPrime(n):
    if n <= sieve_size:
        return bs[n]
    for p in primes:
        if n % p == 0:
            return False
        if p * p > n:
            return True

def square (n):
    return n * n

def modPow(base, exp, mod):
    if exp == 0:
        return 1
    if exp % 2 == 0:
        return square(modPow(base, exp // 2, mod)) % mod
    else:
        return (base * modPow(base, exp - 1, mod)) % mod

sieve(40000)
for line in sys.stdin:
    p, a = map(int, line.split())
    if p == 0 and a == 0:
        break
    r = modPow(a, p, p)
    if isPrime(p):
        print('no')
    elif a == r:
        print('yes')
    else:
        print('no')
    