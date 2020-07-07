import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy
import bisect
import functools

def InsertionSort(A):
    for i in range(1,len(A)):
        key = A[i]
        j = i - 1
        while j>=0 and A[j]>key:
            A[j+1] = A[j]
            j-=1
        A[j+1] = key
        print(*A)
n = int(input())
A = list(map(int,input().split()))
print(*A)
InsertionSort(A)

