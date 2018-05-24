import sys

n = int(sys.stdin.readline())
for i in range(0, n):
    line = sys.stdin.readline()
    a, b = line.split()
    a = int(a[::-1])
    b = int(b[::-1])
    r = a + b
    r = int(str(r)[::-1])
    print(r)