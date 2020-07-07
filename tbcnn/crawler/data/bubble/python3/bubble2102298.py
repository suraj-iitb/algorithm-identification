#! /usr/bin/env python
#-*- coding: utf-8 -*-

''' ?????????????????? '''

# O(n^2)


def bubble_sort(A, N):
    swap_num = 0  # ?????????????????°

    for i in range(N - 1):
        for j in range(N - 1, i, -1):
            if A[j] < A[j - 1]:
                # swap
                temp = A[j]
                A[j] = A[j - 1]
                A[j - 1] = temp
                swap_num += 1

    return (A, swap_num)


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    # A = [5, 2, 4, 6, 1, 3]
    # N = len(A)
    array_sorted, swap_num = bubble_sort(A, N)
    print(' '.join(map(str, array_sorted)))
    print(swap_num)
