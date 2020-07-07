def countingsort(A, n, k):
    B = [None for _ in range(n+1)]
    C = [0 for _ in range(k+1)]

    for j in range(0, n):
        C[A[j]] += 1

    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]

    for j in range(n-1, -1, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

    return B

if __name__ == "__main__":
    n = int(input())
    A = list(map(int, input().split()))
    k = max(A)

    print(' '.join(map(str, countingsort(A, n, k)[1:])))

