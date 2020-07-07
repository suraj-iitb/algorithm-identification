# -*- coding:utf-8 -*-

import sys

def insertionSort(A,N):
    for i in range(N):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
    return A

n = int(input())
A = input()
A = A.split()
A = [int(i) for i in A]

for i in range(1,n+1):
    A = insertionSort(A,i)
    for l in range(len(A)):
        if l == len(A)-1:
            print(A[l])
            break
        print(A[l], end=' ')
        
