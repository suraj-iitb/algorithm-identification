def merge(A, left, mid, right):
    global cnt
    inf = 1000000001
    L = A[left:mid] + [inf]
    R = A[mid:right] + [inf]
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        cnt += 1


def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)


cnt = 0
input()
A = list(map(int, input().split()))
merge_sort(A, 0, len(A))
print(*A)
print(cnt)
