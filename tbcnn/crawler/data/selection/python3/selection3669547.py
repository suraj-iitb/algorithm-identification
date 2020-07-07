# -*- coding: utf-8 -*-
#ALDS1_2_B

def selectionSort(A):
    count = 0
    swap = False
    for i in range(len(A)):
        minj = i
        for j in range(i+1, len(A)):
            if A[j] < A[minj]:
                minj = j
                swap = True
        if swap:
            A[i], A[minj] = A[minj], A[i]
            count += 1
            swap = False
    
    print(" ".join(list(map(str, A))))
    print(count)

n = int(input())
A = list(map(int, input().split()))

selectionSort(A)
