# coding: utf-8
import sys

def merge(A, left, mid, right):
    global count
    L = A[left:mid]
    R = A[mid:right]
    L.append(sys.maxsize)
    R.append(sys.maxsize)
    i = 0
    j = 0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        count += 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = int((left + right)/2);
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input().rstrip())
A = list(map(int,input().rstrip().split()))
count = 0
mergeSort(A, 0, n)
print(" ".join(map(str,A)))
print(count)

