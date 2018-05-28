import sys

for line in sys.stdin:
    v = list(map(int, line.split()))
    s = sum(v)
    r = [s] * 6
    r[0] -= (v[0] + v[5] + v[7])
    r[1] -= (v[0] + v[4] + v[8])
    r[2] -= (v[2] + v[3] + v[7])
    r[3] -= (v[2] + v[4] + v[6])
    r[4] -= (v[1] + v[3] + v[8])
    r[5] -= (v[1] + v[5] + v[6])
    m = min(r)
    for i in range(0, len(r)):
        if r[i] == m:
            if i == 0:
                print("BCG", m)
            elif i == 1:
                print("BGC", m)
            elif i == 2:
                print("CBG", m)
            elif i == 3:
                print("CGB", m)
            elif i == 4:
                print("GBC", m)
            elif i == 5:
                print("GCB", m)
            break