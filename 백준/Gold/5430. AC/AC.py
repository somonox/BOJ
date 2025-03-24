from sys import stdin
from collections import deque

a = int(input())
wdkjn = ""

for i in range(a):
    hehe = deque(stdin.readline().strip())
    lenn = int(stdin.readline().strip())

    if lenn == 0:
        stdin.readline()
        s = deque()
    else:
        s = deque(stdin.readline().strip()[1:-1].split(','))

    ek = True
    rf = False;

    for j in hehe:
        if j == 'R':
            rf = not rf
        elif j == 'D':
            if not s:
                wdkjn += "error\n"
                ek = False;
                break;
            if rf:
                s.pop()
            else:
                s.popleft()
    if ek:
        if rf:
            wdkjn += '[' + ','.join(reversed(s)) + ']' + '\n'
        else:
            wdkjn += '[' + ','.join(s) + ']' + '\n'
print(wdkjn)