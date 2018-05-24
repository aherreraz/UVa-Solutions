import sys

def calcFib(n):
    global fib
    fib = [1] * n
    fib[1] = 2
    for i in range(2, n):
        fib[i] = fib[i - 1] + fib[i - 2]

def getFibBase(n):
    fibi = ''
    for f in fib[::-1]:
        if f <= n:
            fibi += '1'
            n -= f
        else:
            fibi += '0'
    return int(fibi)

calcFib(40)
t = int(sys.stdin.readline())
for i in range(0, t):
    n = int(sys.stdin.readline())
    print('%d = %d (fib)' % (n, getFibBase(n)))