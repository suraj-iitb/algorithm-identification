from enum import Enum
from queue import Queue
import collections

import sys
import math

BIG_NUM = 2000000000
MOD = 1000000007
EPS = 0.000000001

def countingSort(A,k):
    for i in range(k+1):
        C=[0]*(k+1)
        n = len(A)
    for a in A:
        C[a] += 1
    for i in range(1,k+1):
        C[i] += C[i-1]
    B = [0]*n
    for i in reversed(range(n)):
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1
    return B

n = int(input())
A = list(map(int,input().split()))
B = countingSort(A,max(A))
print(*B)

