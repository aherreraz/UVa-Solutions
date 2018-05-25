import sys

def calcCata(n):
    global cata
    cata = [1 for i in range(0, n)]
    for i in range(2, n):
        j = i - 1
        cata[i] = cata[j] * (4 * j + 2) // (j + 2)
    
calcCata(1010)
for line in sys.stdin:
    n = int(line)
    print(cata[n])