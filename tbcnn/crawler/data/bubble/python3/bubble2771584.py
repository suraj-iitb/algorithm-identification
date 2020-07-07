def bubbleSort(A):
    steps = 0
    flag = 1
    completed_idx = 0
    while flag:
        flag = 0
        for i in range(len(A) - 1, completed_idx, -1):
            if A[i - 1] > A[i]:
                A[i - 1], A[i] = A[i], A[i - 1]
                steps += 1
                flag = 1
        completed_idx += 1

    for e in A[:-1]:
        print(e, end=' ')
    print(A[-1])
    print(steps)

N = int(input())
A = [int(elem) for elem in input().split()]
bubbleSort(A)
