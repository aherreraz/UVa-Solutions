import sys

def checkInt(n):
    return bool(n > 2 ** 31 - 1)

print(2 ** 31 - 1)
for line in sys.stdin:
    a, sign, b = line.split()
    a, b = map(int, [a, b])
    if sign == '+':
        t = a + b
    else:
        t = a * b
    sys.stdout.write(line)
    if (checkInt(a)):
        print('first number too big')
    if (checkInt(b)):
        print('second number too big')
    if (checkInt(t)):
        print('result too big')