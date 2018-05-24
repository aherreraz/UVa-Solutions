def comb(n, k):
    global C
    if k == 0 or k == n:
        C[n][k] = int(1)
    elif C[n][k] == 0:
        C[n][k] = comb(n - 1, k - 1) + comb(n - 1, k)
    return C[n][k]
    
C = [[0 for i in range(1000)] for j in range(0, 1000)]
keepPrinting = True

i = 0
while keepPrinting:
    j = 0
    while j <= i:
        s = comb(i, j)
        if len(str(s)) == 61:
            keepPrinting = False
        if (j > 0):
            print (' ', end='')
        print (s, end='')
        j += 1
    print()
    i += 1