n = int(input())
A = list(map(int, input().split()))

def CountingSort(A, B, k):
    C = [0] * k

    for j in range(n):
        C[A[j]] += 1

    for i in range(1, k):
        C[i] = C[i] + C[i-1]

    for j in range(n-1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1

B = [0] * n
CountingSort(A, B, 10000)

print(' '.join(map(str, B)))

