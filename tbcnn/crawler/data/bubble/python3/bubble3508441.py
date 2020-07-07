# -*- coding: utf 8 -*-
# Bubble Sort
# 2019. 4/22

def bubbleSort(A, N):
    sw = 0
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in range(int(N) - 1, i, -1):
            if A[j - 1] > A[j]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = 1
                sw = sw + 1
        i = i + 1
    return A, sw

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))

    A_sorted, num_sw = bubbleSort(A, N)

    for i in range(N-1):
        print(A[i], end=" ")
    print(A[N-1])
    print(num_sw)

