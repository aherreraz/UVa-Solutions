import sys

for line in sys.stdin:
    n, k = map(int, line.split())
    if n == 0 and k == 0:
        break
    r = 1
    if n - k < k:
        k = n - k
    while k > 0:
        r *= n / k
        k -= 1
        n -= 1
    print('%.0f' % r)