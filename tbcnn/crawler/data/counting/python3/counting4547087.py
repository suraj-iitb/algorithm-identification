# coding: utf-8
# 計数ソート


def countingSort(A, B, k):
    global n

    C = [0] * k

    for i in range(n):
        C[A[i]] += 1

    for j in range(1, k):
        C[j] = C[j] + C[j - 1]

    for l in reversed(A):
        B[C[l] - 1] = l
        C[l] -= 1


if __name__ == "__main__":
    n = int(input())
    A = [int(i) for i in input().split()]

    B = [0] * n

    countingSort(A, B, max(A) + 1)
    print(' '.join(map(str, B)))

