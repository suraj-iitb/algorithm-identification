def bubbleSort(N, A):
    flag = 1
    count = 0
    while flag != 0:
        flag = 0
        for i in range(N - 1, 0, -1):
            if A[i] < A[i - 1]:
                k = A[i]
                A[i] = A[i - 1]
                A[i - 1] = k
                flag = 1
                count += 1
    print(" ".join(map(str, A)))
    print(count)


n = int(input())
a = list(map(int, input().split()))
bubbleSort(n, a)
