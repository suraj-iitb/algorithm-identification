# 挿入ソート

N = int(input())
A = list(map(int, input().split()))


def insertionSort(A, N):
    print(' '.join([str(i) for i in A]))
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j+1] = v
        print(' '.join([str(i) for i in A]))


insertionSort(A, N)

