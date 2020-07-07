import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy
import bisect
import functools

def BubbleSort(A):
    cnt = 0
    for i in range(len(A)):
        for j in range(len(A)-1,i,-1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                cnt += 1
    return cnt
n = int(input())
A = list(map(int,input().split()))
cnt = BubbleSort(A)
print(*A)
print(cnt)
