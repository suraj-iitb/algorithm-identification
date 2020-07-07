def counting_sort(A, n, k):
    C = [0 for _ in range(k)]
    B = [None] * n
    for j in range(n):
        C[A[j]] += 1

    for i in range(1, k):
        C[i] = C[i] + C[i - 1]

    for a in A[::-1]:
        B[C[a] - 1] = a
        C[a] -= 1

    return B


k = 10 ** 4 + 1
n = int(input())
A = list(map(int, input().split()))
B = counting_sort(A, n, k)
print(*B[:n])

