def CountingSort(A, B, k):
    C = [0] * (k + 1)
    for a in A: C[a] += 1
    for i in range(1, k+1): C[i] = C[i] + C[i - 1]
    for j in range(n-1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] += -1
    
n = int(input())
A=[int(i) for i in input().split()]
B = [None] * n
CountingSort(A, B, max(A))
print(' '.join(map(str,B)))
