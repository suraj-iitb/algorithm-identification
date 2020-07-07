def counting_sort(A, k):
    C = [0] * (k + 1)
    for a in A:
        C[a] += 1
    j = 0
    for i, c in enumerate(C):
        for k in range(c):
            A[j + k] = i
        j += c


K = 10_000
N = int(input())
A = list(map(int, input().split()))
counting_sort(A, K)
print(*A)

