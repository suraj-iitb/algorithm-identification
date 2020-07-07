# coding: utf-8
# Your code here!

def CountingSort(A):
    MAX = 10000
    B = [0 for e in range(n)]
    C = [0 for e in range(MAX)]
    
    for j in range(n):
        C[A[j]] += 1
    
    for i in range(1,MAX):
        C[i] += C[i-1]

    for j in range(n-1,-1,-1):
        B[C[A[j]]-1] = A[j]
        C[A[j]]-=1
        
    return B
n = int(input())
A = [int(e) for e in input().split()]
print(*CountingSort(A))
