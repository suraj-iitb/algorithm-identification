def merge(A, left, mid, right):
    L = A[left:mid] + [2147483648]
    R = A[mid:right] + [2147483648]
    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    global c
    c += right - left


def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)


c = 0
n = int(input())
A = list(map(int, input().split()))
mergeSort(A, 0, n)
print(" ".join(map(str, A)))
print(c)

