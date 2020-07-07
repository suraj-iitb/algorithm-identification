#from enum import Enum
#from queue import Queue
#import collections

#import sys
#import math

BIG_NUM = 2000000000
#MOD = 1000000007
#EPS = 0.000000001


count = 0
def merge(A, left, mid, right):
    global count
#    n1 = mid - left
#    n2 = right - mid
#    L = list(range(n1+1))
#    R = list(range(n2+1))
#    for i in range(n1):
#        L[i] = A[left + i]
#    for i in range(n2):
#        R[i] = A[mid + i]
#    L[n1] = BIG_NUM
#    R[n2] = BIG_NUM
    L = A[left:mid] + [BIG_NUM]
    R = A[mid:right] + [BIG_NUM]
    i = 0
    j = 0
    for k in range(left,right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
S = list(map(int,input().split()))

mergeSort(S,0,n)
#for i in range(n-1):
#    print("%d"%(S[i]),end=" ")
#print("%d"%(S[n-1]))
print(*S)
print(count)

