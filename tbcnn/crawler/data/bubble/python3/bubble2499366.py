# Aizu Problem ALDS_1_2_A: Bubble Sort
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input2.txt", "rt")


def printA(A):
    print(' '.join([str(a) for a in A]))

def bubble_sort(A):
    swaps = 0
    for i in range(len(A) - 1):
        for j in range(len(A) - 1, i, -1):
            if A[j] < A[j - 1]:
                swaps += 1
                A[j], A[j - 1] = A[j - 1], A[j]
    return A, swaps

        
N = int(input())
A = [int(_) for _ in input().split()]
A, swaps = bubble_sort(A)
printA(A)
print(swaps)
