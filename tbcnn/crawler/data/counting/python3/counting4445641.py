def CountingSort(A, k):
    n = len(A)
    B = [0]*n
    C = [0]*(k+1)

    for j in range(n):
        C[A[j]] += 1

    for i in range(1,k):
        C[i] = C[i] + C[i-1]

    for j in range(n-1,-1,-1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
            
    return B

n = int(input())
*A, = map(int,input().split())

k = 10000
out = CountingSort(A,k)

print(*out, sep=" ")


