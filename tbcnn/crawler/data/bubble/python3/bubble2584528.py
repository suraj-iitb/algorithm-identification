def bubbleSort(A, N):
    flag = 1
    count = 0
    while flag == 1:
        flag = 0
        for i in range(1, N)[::-1]:
            if A[i] < A[i - 1]:
                tmp = A[i]
                A[i] = A[i - 1]
                A[i - 1] = tmp
                flag = 1
                count += 1

    print(" ".join(map(str, A)))
    print(count)

n = int(input())
A = list(map(int, input().split()))

bubbleSort(A, n)
