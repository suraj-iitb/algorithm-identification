n = int(input())
S = [int(i) for i in input().split()]

def merge(A, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]
    i = 0
    j = 0
    L.append(1000000000)
    R.append(1000000000)
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return A

def mergeSort(A, left, right, cnt):
    if left+1 < right:
        mid = (left + right)//2
        A, cnt = mergeSort(A, left, mid, cnt)
        A, cnt = mergeSort(A, mid, right, cnt)
        A = merge(A, left, mid, right)
        cnt += right - left
    return A, cnt

S, comp_cnt = mergeSort(S, 0, n, 0)
print(*S)
print(comp_cnt)

