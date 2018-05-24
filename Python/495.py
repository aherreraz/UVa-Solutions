import sys

def calcFib(n):
    global fib
    fib = [0] * n
    fib[1] = 1
    for i in range(2, n):
        fib[i] = fib[i - 1] + fib[i - 2]
        
calcFib(5050)
for line in sys.stdin:
    n = int(line)
    print('The Fibonacci number for %d is %d' % (n, fib[n]))