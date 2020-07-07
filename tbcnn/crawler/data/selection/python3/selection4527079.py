import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy
import bisect
import functools

def SelectionSort(A):
    cnt = 0
    for i in range(len(A)):
        mini = i
        for j in range(i,len(A)):
            if A[j] < A[mini]:
                mini = j
        if mini != i:
            tmp = A[i]
            A[i] = A[mini]
            A[mini] = tmp
            cnt += 1
    return cnt
n = int(input())
A = list(map(int,input().split()))
cnt = SelectionSort(A)
print(*A)
print(cnt)

