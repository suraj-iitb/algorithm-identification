cnt = 0

def merge(A, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]
    L.append(float('inf'))
    R.append(float('inf'))
    i = 0
    j = 0
    global cnt
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        cnt += 1
    return A

def merge_sort(A, left, right):
    if left+1 < right:
        mid = (left + right) >> 1
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        return merge(A, left, mid, right)

n = int(input())
A = [int(i) for i in input().split()]
print(*merge_sort(A, 0, n), sep=" ")
print(cnt)
