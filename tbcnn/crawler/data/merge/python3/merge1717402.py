def merge(A, left, mid, right):
    global count
    banpei = 1000000001
    L = A[left:mid] + [banpei]
    R = A[mid:right] + [banpei]

    i, j = 0, 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    count += right - left


def merge_Sort(A, left, right):
    if 1 < right - left:
        mid = (left + right) // 2
        merge_Sort(A, left, mid)
        merge_Sort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
A = list(map(int, input().split()))
count = 0
merge_Sort(A, 0, n)
print(*A)
print(count)
