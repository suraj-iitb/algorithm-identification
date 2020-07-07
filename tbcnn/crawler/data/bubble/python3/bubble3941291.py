import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop

BIG_NUM = 2000000000
MOD = 1000000007
EPS = 0.000000001


N = int(input())

table = list(map(int,input().split()))

swap_count = 0

for i in range(len(table)-1):
    for k in range(len(table)-1,i,-1):
        if table[k] < table[k-1]:
            table[k],table[k-1] = table[k-1],table[k]
            swap_count += 1

print(' '.join(map(str,table)))
print("%d"%(swap_count))

