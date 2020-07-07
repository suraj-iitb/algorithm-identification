import math
sentinel = 1e9 + 1
counter = 0
def merge(a, left, mid, right):
    global counter
    L = a[left:mid] + [sentinel]
    R = a[mid:right] + [sentinel]
    i,j = 0,0
    for k in range(left, right):
        if(L[i] <= R[j]):
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1
    counter += right - left
def mergeSort(a, left, right):
    if left+1 < right:
        mid = (left + right) // 2
        mergeSort(a, left, mid)
        mergeSort(a, mid, right)
        merge(a, left, mid, right)


n = int(input())
a = list(map(int, input().split()))
mergeSort(a, 0, n)
print(*a)
print(counter)

