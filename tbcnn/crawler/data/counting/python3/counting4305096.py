# Counting sort 計数ソート


def countingsort(A, B, k):
    n = len(A)
    C = [0 for i in range(0, k + 1)]
    for i in range(0, n):
        C[A[i]] += 1
    for i in range(0, k + 1):
        C[i] += C[i - 1]
    for i in range(n - 1, -1, -1):
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1


n = int(input())
A = [int(i) for i in input().split()]
B = [None for i in range(n)]
countingsort(A, B, 10000)
for i in range(0, n - 1):
    print(B[i], end=" ")
print(B[n - 1])

