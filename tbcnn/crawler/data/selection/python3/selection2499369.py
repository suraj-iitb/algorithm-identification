# Aizu Problem ALDS_1_2_C: Selection Sort
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def printA(A):
    print(' '.join([str(a) for a in A]))

def selection_sort(A):
    swaps = 0
    for i in range(len(A)):
        mini = i
        for j in range(i, len(A)):
            if A[j] < A[mini]:
                mini = j
        if mini != i:
            swaps += 1
            A[i], A[mini] = A[mini], A[i]
    return A, swaps

        
N = int(input())
A = [int(_) for _ in input().split()]
A, swaps = selection_sort(A)
printA(A)
print(swaps)
