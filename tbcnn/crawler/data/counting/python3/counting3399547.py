# coding: utf-8

def countingSort(A, B, k):
    C = [0 for i in range(k+1)]

    for i in range(n):
        C[A[i]] += 1
    
    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]
    
    for i in range(n-1, -1,-1):
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1

n = int(input().rstrip())
A = [int(i) for i in input().rstrip().split()]
B = [0 for i in range(n)]
countingSort(A, B, 10000)
print(" ".join([str(i) for i in B]))
