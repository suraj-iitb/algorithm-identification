def bubbleSort(A, n):
    flag = True
    cnt = 0
    while flag:
        flag = False
        for j in range(n - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = True
                cnt += 1
    print(*A)
    print(cnt)

n = int(input())
A = list(map(int, input().split()))
bubbleSort(A, n)

