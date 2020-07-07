# バブルソート

N = int(input())
A = list(map(int, input().split()))


def bubbleSort(A, N):
    isExist = True
    cnt = 0
    while isExist:
        isExist = False
        for i in range(1, N):
            j = N - i
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                isExist = True
                cnt += 1
    print(' '.join([str(i) for i in A]))
    print(cnt)


bubbleSort(A, N)

