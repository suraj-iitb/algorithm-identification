def merge(A, left, mid, right):
    global cnt
    L = A[left:mid] + [1000000001]
    R = A[mid:right] + [1000000001]
    i = j = 0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        cnt += 1


def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (right + left) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)


if __name__ == '__main__':
    n = int(input())
    S = list(map(int, input().split()))
    cnt = 0
    mergeSort(S, 0, n)
    print(*S)
    print(cnt)
