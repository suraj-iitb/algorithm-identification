def merge(A, n ,left, mid, right):
    cnt = 0
    L = A[left:mid] + [float("inf")]
    R = A[mid:right] + [float("inf")]
    i, j = 0, 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return cnt

def mergeSort(A, n, left, right):
    if left+1 < right:
        mid = (left + right)//2
        return mergeSort(A, n, left, mid) + mergeSort(A, n, mid, right)\
        + merge(A, n, left, mid, right)    
    return 0

n = int(input())

A = list(map(int, input().split()))

cnt = mergeSort(A, n, 0, n)

print(*A)
print(cnt)
