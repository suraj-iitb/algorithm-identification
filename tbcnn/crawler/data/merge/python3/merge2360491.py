# coding=utf-8

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

def merge(A, left, mid, right):
    global counter
    L = A[left:mid] + [inf]
    R = A[mid:right] + [inf]
    i = j = 0
    for k in range(left, right):
        if L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        counter += 1


n = int(input())
A = list(map(int, input().split()))
counter = 0
inf = float("inf")

mergeSort(A, 0, n)
print(*A)
print(counter)
