INF = 10000000000


def merge(A, left, mid, right):
    global count
    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]
    i, j = 0, 0
    for k in range(left, right):
        count += 1
        if L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1


def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)


if __name__ == "__main__":
    global count
    count = 0
    input()
    A = [int(x) for x in input().split()]
    mergeSort(A, 0, len(A))
    print(' '.join(map(str, A)))
    print(count)

