"""Merge Sort."""

def merge(A, left, mid, right):
    """Merge the two sorted partial sequences A[left:mid] and A[mid:right].

    To count the number of comparisons,
    make a global declaration for the variable cnt.
    """
    L = A[left:mid]
    L.append(10**9 + 1)
    R = A[mid:right]
    R.append(10**9 + 1)
    i = 0
    j = 0
    global cnt
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    """Sort elements in list A using Merge Sort algorithm.

    left is the starting index, initially 0.
    right is the value added 1 to the last index, initially the length of A.
    """
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)


n = int(input())
S = list(map(int, input().split()))

cnt = 0

mergeSort(S, 0, n)

print(*S)
print(cnt)
