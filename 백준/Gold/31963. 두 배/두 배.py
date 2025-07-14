import sys
import math
input = sys.stdin.readline

n = int(input())
list1 = list(map(int, input().split()))

cnt = 0
cntlist = [0]*n
for i in range(1, n):
    ratio = math.ceil(math.log2(list1[i - 1] / list1[i])) + cntlist[i - 1]
    if ratio > 0:
        cntlist[i] = max(0, ratio)
        cnt += cntlist[i]
    
print(cnt)