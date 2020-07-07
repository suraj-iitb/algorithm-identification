def selectionSort(A, N):
    cnt = 0
    for i in range(N):
        minJ = i
        for j in range(i, N):
            if A[minJ] > A[j]:
                minJ = j
        if A[i] != A[minJ]:
            tmp = A[i]
            A[i] = A[minJ]
            A[minJ] = tmp
            cnt += 1
    return A, cnt


def resolve():
    N = int(input())
    A = [int(i) for i in input().split()]
    ans, cnt = selectionSort(A, N)
    print(*ans)
    print(cnt)


resolve()

