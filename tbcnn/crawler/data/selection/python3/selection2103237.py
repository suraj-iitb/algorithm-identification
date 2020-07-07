#! /usr/bin/env python
# -*- coding: utf-8 -*-

''' ??????????????? '''

# ????????????????????°?????????N(N-1)/2????????§???
# ?¨???????:O(n^2)


def selection_sort(A, N):
    swap_num = 0  # ???????????°

    for i in range(N):
        minj = i
        for j in range(i, N, 1):
            if A[j] < A[minj]:
                minj = j
        # swap
        if i != minj:
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            swap_num += 1

    return (A, swap_num)


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    # A = [5, 2, 4, 6, 1, 3]
    # N = len(A)
    array_sorted, swap_num = selection_sort(A, N)
    print(' '.join(map(str, array_sorted)))
    print(swap_num)
