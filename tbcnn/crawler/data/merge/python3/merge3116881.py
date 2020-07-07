cnt = 0
def merge(A, left, mid, right):
    global cnt
    L = A[left:mid] + [10 ** 10]
    R = A[mid:right] + [10 ** 10]
    i = j = 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
def merge_sort(A, left, right):
    if left + 1 < right:  # 1 < right - left
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)
    return A

n = int(input())
A = list(map(int, input().split()))
print(*merge_sort(A, 0, n))
print(cnt)
