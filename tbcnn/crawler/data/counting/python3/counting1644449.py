"""Counting Sort."""

def countingSort(A, n):
    """Sort the elements of list A with Counting Sort algorithm.

    n is the length of A.
    The elements of A are intergers between 0 and 10000, inclusive.
    B is the output list where the sorted elements will be arranged.
    
    Print the elements of B in a line separated by a space character.
    """

    C = [0 for i in range(10001)]

    for i in A:
        C[i] += 1

    for i in range(1, 10001):
        C[i] += C[i - 1]

    B = [0 for i in range(n + 1)]
    
    for i in reversed(A):
        B[C[i]] = i
        C[i] -= 1

    print(*B[1:])


import sys

n = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split()))

countingSort(A, n)
