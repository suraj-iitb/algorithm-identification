def bubbleSort(A, N):
    cnt = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = 1
                cnt += 1
    print(' '.join(map(str,A)))
    print(cnt)


x =int(input())
y = list(map(int,input().split(' ')))
bubbleSort(y,x)
