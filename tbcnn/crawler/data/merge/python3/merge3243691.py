def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    INF = 1000000001

    L = A[left:left + n1] + [INF]
    R = A[mid:mid + n2] + [INF]

    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return right - left
            
def mergeSort(A, left, right):
    cnt = 0
    if left+1 < right:
        mid = (left + right) // 2
        cnt += mergeSort(A, left, mid)
        cnt += mergeSort(A, mid, right)
        cnt += merge(A, left, mid, right)
    return cnt

n = int(input())
A = list(map(int, input().split()))
left = 0
right = n
cnt = mergeSort(A, left, right)
print(' '.join(map(str, A)))
print(cnt)
