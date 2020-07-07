def bubbleSort(A, N):
    s = 0
    flag = 0
    while flag == 0:
        flag = 1
        for j in range(N - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = 0
                s += 1
    t = str(A[0])
    for i in range(1,N):
        t = t + " " + str(A[i])
    print(t)
    print(s)

n = int(input())
a = [int(i) for i in input().split()]

bubbleSort(a, n)
