# Aizu Problem ALDS_1_1_A: Insertion Sort
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input2.txt", "rt")


def printA(A):
    print(' '.join([str(a) for a in A]))

def insertion_sort(A):
    for i in range(1, len(A)):
        key = A[i]
        # insert A[i] into the sorted sequence A[0,...,j-1] 
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
        printA(A)

        
N = int(input())
A = [int(_) for _ in input().split()]
printA(A)
insertion_sort(A)
