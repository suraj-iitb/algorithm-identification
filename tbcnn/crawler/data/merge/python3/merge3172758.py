import sys

def Merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    L = A[left:left+n1]+[SENTINEL]
    R = A[mid:mid+n2]+[SENTINEL]
    i = 0
    j = 0

    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def MergeSort(A, left, right):
    global ncomp
    if left+1 < right:
        mid = (left + right)//2
        MergeSort(A, left, mid)
        MergeSort(A, mid, right)
        Merge(A, left, mid, right)
        ncomp += right-left
ncomp=0
n = int(sys.stdin.readline())
s = list(map(int, sys.stdin.readline().split()))
SENTINEL = max(s)+1
MergeSort(s, 0, n)
print(' '.join(map(str,s)))
print(ncomp)
