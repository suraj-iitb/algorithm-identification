INF = 10 ** 10


def merge(A, left, mid, right):
    count = 0
    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]

    i, j = 0, 0
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return count


def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        countL = merge_sort(A, left, mid)
        countR = merge_sort(A, mid, right)
        return merge(A, left, mid, right) + countL + countR
    return 0


N = int(input())
A = list(map(int, input().split()))
count = merge_sort(A, 0, N)
A = list(map(str, A))
print(' '.join(A))
print(count)
