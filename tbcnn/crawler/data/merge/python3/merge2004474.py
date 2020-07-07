import sys
n = int(input())
SENTINEL = 10000000000
COMPAR = 0

A = list(map(int, sys.stdin.readline().split()))

def merge(A, left, mid, right):
    global COMPAR
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid]
    R = A[mid:right]
    L.append(SENTINEL)
    R.append(SENTINEL)

    j = 0
    i = 0
    for k in range(left, right):
        COMPAR += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

merge_sort(A, 0, n)
print(' '.join(map(str, A)))
print(COMPAR)
