import sys

def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

n = int(sys.stdin.readline())
sys.stdin.readline()
for i in range(0,n):
    a = int(sys.stdin.readline())
    sys.stdin.readline()
    if i > 0:
        print()
    print(isqrt(a))