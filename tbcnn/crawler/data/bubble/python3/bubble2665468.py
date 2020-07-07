def bubbleSort(A, N):
    flag = True
    count = 0
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                count += 1
    print(*A)
    print(count)


arr_length = int(input())
arr_num = [int(i) for i in input().split(" ")]

bubbleSort(arr_num, arr_length)
