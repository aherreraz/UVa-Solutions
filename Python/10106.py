import sys

while True:
    line = sys.stdin.readline()
    if not line:
        break
    a = int(line)
    b = int(sys.stdin.readline())
    print (a * b)