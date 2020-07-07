def bubbleSort(A, N):
    flag = True
    cnt = 0
    while flag:
        flag = False
        for j in reversed(range(1, N)):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                cnt += 1
    print(*A)
    print(cnt)


N = int(input())
A = list(map(int, input().split()))

bubbleSort(A, N)

