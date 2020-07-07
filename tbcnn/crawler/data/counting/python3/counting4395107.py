n = int(input())
A = list(map(int, input().split()))
C = [0 for _ in range(10000)]


def counting_sort(A, n, k):
    B = [0 for _ in range(n)]
    for i in range(n):
        C[A[i]] += 1

    for i in range(1, k):
        C[i] += C[i - 1]

    for i in range(n)[::-1]:
        C[A[i]] -= 1
        B[C[A[i]]] = A[i]

    return B


print(*counting_sort(A, n, 10000))

