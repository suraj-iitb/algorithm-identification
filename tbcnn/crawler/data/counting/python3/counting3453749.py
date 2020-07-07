n = int(input())
A = list(map(int, input().split()))


def CountingSort(A, B, k):
    C = [0] * (k+1)

    for j in range(n):
        C[A[j]] += 1

    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
        # 累積和
    for j in range(n-1, -1, -1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1
    return B


k = max(A)
B = [0] * n
B = CountingSort(A, B, k)
print(*B)

