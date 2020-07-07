def CountingSort(A, B, k):
    C = [0]*(k+2)
    for i in range(n):
        C[A[i]] += 1
    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]
    x = list(range(n))
    x.reverse()
    for i in x:
        B[C[A[i]]] = A[i]
        C[A[i]] -= 1
    return B
n = int(input())
A = list(map(int,input().split()))
B = [0]*(n+1)
k = max(A)
res = CountingSort(A, B, k)
print(*res[1:])
