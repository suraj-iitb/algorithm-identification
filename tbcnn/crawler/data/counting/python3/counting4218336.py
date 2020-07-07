def counting_sort(A):
    n = len(A)
    C = [0] * 10000
    B = [0] * n
    for i in range(n):
        C[A[i]] += 1

    for i in range(1, 10000):
        C[i] = C[i] + C[i-1]

    for i in reversed(range(n)):
        # print('len B {}, i, {} A[i] {}'.format(len(B), i, A[i]))
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1

    return B


if __name__ == "__main__":
    input()
    A = list(map(int, input().split()))

    A = counting_sort(A)

    print(' '.join(map(str, A)))

