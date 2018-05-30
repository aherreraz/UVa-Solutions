import sys

def calcRes(n, m):
    global c
    global h
    c = 0
    t = 1
    h = n ** m
    for i in range(0, m):
        c += t
        h +=  t * ((n + 1) ** (m - i))
        t *= n

def f(n, m):
    return n ** m, (n + 1) ** m

def findN(m, b):
    lo = 1
    root = b ** (1 / m)
    hi = int(root) + 5
    while lo < hi:
        mid = lo + (hi - lo) // 2
        r = mid ** m
        if r == b:
            return mid
        elif r < b:
            lo = mid + 1
        else:
            hi = mid
    return 0

for line in sys.stdin:
    a, b = map(int, line.split())
    if a == 0 and b == 0:
        break
    if a == 1 and b == 1:
        print(0, 1)
        continue
    for m in range(1, 65):
        n = findN(m, b)
        c, d = f(n, m)
        if (c == b) and (d == a):
            calcRes(n, m)
            break
    print(c, h)