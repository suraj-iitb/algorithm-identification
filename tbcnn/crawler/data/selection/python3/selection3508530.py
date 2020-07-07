# -*- coding: utf 8 -*-
# Selection Sort
# 2019. 4/22

def selectionSort(A, N):
    sw = 0
    for i in range(0, int(N) - 1):
        minj = i
        for j in range(i, int(N)):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if minj != i:
            sw = sw + 1

    return A, sw

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))

    A_sorted, sw = selectionSort(A, N)

    for i in range(0, N - 1):
        print(A[i], end=" ")
    print(A[N - 1])
    print(sw)

