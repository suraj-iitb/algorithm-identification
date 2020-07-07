import sys

SENTINEL = 10 ** 9 + 1
cnt = 0


def merge(A, left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid] + [SENTINEL]
    R = A[mid:right] + [SENTINEL]

    i, j = 0, 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1


def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)


n = int(input())
A = list(map(int, sys.stdin.readline().split()))
merge_sort(A, 0, n)
print(*A)
print(cnt)

