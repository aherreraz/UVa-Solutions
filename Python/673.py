import sys

t = int(sys.stdin.readline())
for z in range(0, t):
    s = sys.stdin.readline()
    stack = []
    for i in range(0, len(s) - 1):
        if s[i] == '(' or s[i] == '[' or (len(stack) == 0 and (s[i] == ')' or s[i] == ']')):
            stack.append(s[i])
        elif (s[i] == ')' and stack[len(stack) - 1] == '(')  or (s[i] == ']' and stack[len(stack) - 1] == '['):
            stack.pop()
    if len(stack) == 0:
        print('Yes')
    else:
        print('No')