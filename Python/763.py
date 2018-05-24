import sys

def calcFib(n):
    global fib
    fib = [1] * n
    fib[1] = 2
    for i in range(2, n):
        fib[i] = fib[i - 1] + fib[i - 2]

def getNumber(fibinary):
    s = int(0)
    i = 0
    for f in fibinary:
        s += int(f) * fib[i]
        i += 1
    return s

def getFibinary(n):
    fibi = ''
    for f in fib[::-1]:
        if f <= n:
            fibi += '1'
            n -= f
        else:
            fibi += '0'
    return fibi

calcFib(150)
t = int(0)
while True:
    line = sys.stdin.readline()
    if not line:
        break
    a = int(line)
    b = int(sys.stdin.readline())
    sys.stdin.readline()
    c = str(a + b)[::-1]
    
    s = getNumber(c)
    if t > 0:
        print()
    t += 1
    print(int(getFibinary(s)))