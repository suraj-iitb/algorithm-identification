# coding: utf-8
# マージソート
INFTY = int(1E20)
count = 0


def merge(A, left, mid, right):
    global INFTY
    global count

    L = [i for i in A[left:mid]]
    R = [i for i in A[mid:right]]

    L.append(INFTY)
    R.append(INFTY)

    idx_L = 0
    idx_R = 0
    for idx in range(left, right):
        count += 1
        if L[idx_L] <= R[idx_R]:
            A[idx] = L[idx_L]
            idx_L += 1
        else:
            A[idx] = R[idx_R]
            idx_R += 1


def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)
    else:
        return


if __name__ == "__main__":
    n = int(input())
    A = [int(i) for i in input().split()]

    mergeSort(A, 0, n)

    print(' '.join([str(i) for i in A]))

    print(count)

