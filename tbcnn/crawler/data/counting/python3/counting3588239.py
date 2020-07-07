if __name__ == '__main__':
    import sys
    input = sys.stdin.readline

    n = int(input())

    A = [None] + list(map(int, input().split()))
    B = [None]*(n+1)

    C = [0]*10001

    k = 10000

    for j in range(n):
        C[A[j+1]] += 1

    for i in range(1, k+1):
        C[i] += C[i-1]


    for j in range(1, n+1):
        B[C[A[j]]] = A[j]
        C[A[j]] -= 1

    print(' '.join(map(str, B[1:])))

