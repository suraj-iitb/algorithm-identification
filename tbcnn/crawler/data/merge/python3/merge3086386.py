import sys
import math

f = sys.stdin
n = int(f.readline().split()[0])
A = list(map(int, f.readline().split()[:n]))

COUNT = 0

def Merge(A, left, mid, right):
    global COUNT
    if left == right:
        return
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid]
    R = A[mid:right]

    L.append(10**9 + 1)
    R.append(10**9 + 1)
    i = 0
    j = 0
    for k in range(left, right):
        COUNT += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1


def Merge_Sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        Merge_Sort(A, left, mid)
        Merge_Sort(A, mid, right)
        Merge(A, left, mid, right)

Merge_Sort(A, 0, len(A))
print(" ".join(map(str, A)))
print(COUNT)

