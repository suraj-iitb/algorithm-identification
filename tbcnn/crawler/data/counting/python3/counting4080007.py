def CountingSort(A, B, k):
    C = [ 0 for i in range(0, k+1)]
    for j in range(0, len(A)):
        C[A[j]] = C[A[j]] + 1
    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
    for j in range(n-1, -1, -1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] = C[A[j]] - 1
        
n = int(input())
A = list(map(int, input().split()))

B = [0 for i in range(n)]
k = max(A)
CountingSort(A, B, k)

print(*B)
