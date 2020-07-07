def bubbleSort(A, N):
    cnt = 0
    flg = True
    while flg:
        flg = False
        for i in range(N - 1):
            if A[i] > A[i + 1]:
                tmp = A[i]
                A[i] = A[i + 1]
                A[i + 1] = tmp
                flg = True
                cnt += 1
    return A, cnt


def resolve():
    N = int(input())
    A = [int(i) for i in input().split()]
    ans, cnt = bubbleSort(A, N)
    print(*ans)
    print(cnt)


resolve()

