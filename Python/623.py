import sys

def calcFact(n):
    global fact
    fact = [1 for i in range(0, n)]
    for i in range(2, n):
        fact[i] = fact[i - 1] * i

calcFact(1010)

for line in sys.stdin:
    n = int(line)
    print("%d!" % n)
    print(fact[n])