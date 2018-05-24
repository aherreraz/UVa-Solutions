import sys

def printif(condition, text):
    global g
    if condition:
        print(text)
        g += 1
        
def isleap(n):
    if n % 4 == 0:
        if n % 100 == 0:
            if n % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False
    
i = int(0)
for line in sys.stdin:
    n = int(line)
    
    if (n != 0):
        if i > 0:
            print()
        i += 1
        print(n)        
        n -= 2148
        if n < 0:
            print ('No ghost will come in this year')
        else:
            g = int(0)
            printif(n % 2 == 0, 'Ghost of Tanveer Ahsan!!!')
            printif(n % 5 == 0, 'Ghost of Shahriar Manzoor!!!')
            printif(n % 7 == 0, 'Ghost of Adrian Kugel!!!')
            printif(n % 11 == 0, 'Ghost of Anton Maydell!!!')
            printif(n % 15 == 0, 'Ghost of Derek Kisman!!!')
            printif(n % 20 == 0, 'Ghost of Rezaul Alam Chowdhury!!!')
            printif(n % 28 == 0, 'Ghost of Jimmy Mardell!!!')
            printif(n % 36 == 0, 'Ghost of Monirul Hasan!!!')
            printif(isleap(n + 2148), 'Ghost of K. M. Iftekhar!!!')
            printif(g == 0, 'No ghost will come in this year')