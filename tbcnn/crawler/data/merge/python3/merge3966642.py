import sys
sys.setrecursionlimit(10000)
num = int(input())
cnt = 0
def merge(A, left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid]  + [ 1e10 ]
    R = A[mid:right] + [ 1e10 ]
    i = j = 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left+right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

L = [int(x) for x in input().split()]
c = mergeSort(L, 0, len(L))
print(" ".join(map(str,L)))
print(cnt)

