import sys

for line in sys.stdin:
    n = int(line)
    n2 = n ** 2
    d = len(line)
    d2 = len(str(n2))
    if d2 > d and str(n2).endswith(line):
        print ('Automorphic number of %d-digit.' % d)
    else:
        print ('Not an Automorphic number.')