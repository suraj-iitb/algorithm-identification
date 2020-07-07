def selectionSort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            count += 1
            A[i], A[minj] = A[minj], A[i]

    print(*A)
    print(count)

arr_length = int(input())
arr_num = [int(i) for i in input().split(" ")]

selectionSort(arr_num, arr_length)
