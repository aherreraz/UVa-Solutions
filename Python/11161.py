import sys

def calcFib(n):
    global fib
    fib = [1] * n
    fib[1] = 2
    for i in range(2, n):
        fib[i] = fib[i - 1] + fib[i - 2]
     
def calcMedian(n):
    global med
    med = [0] * n
    med[1] = 1
    med[2] = 2
    for i in range(3, n):
        med[i] = fib[i] + med[i - 3]

t = 0
calcFib(2000)
calcMedian(2000)
for line in sys.stdin:
    n = int(line)
    t += 1
    if n == 0:
        break
    print('Set %d:' % t)    
    print(med[n - 1])