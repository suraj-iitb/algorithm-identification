def counting_sort(MAX):
    C = [0 for _ in range(MAX+1)]

    for i in range(N):
        C[A[i]] += 1

    for i in range(1, MAX+1):
        C[i] = C[i] + C[i-1]

    for i in range(N-1, -1, -1):
        C[A[i]] -= 1
        B[C[A[i]]] = A[i]

N = int(input())
A = list(map(int, input().split()))

MAX = 10001

B = [0 for _ in range(N)]
counting_sort(MAX)
print(" ".join(map(str, B)))
