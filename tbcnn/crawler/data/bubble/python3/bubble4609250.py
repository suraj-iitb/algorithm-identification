def bubbleSort(A,N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in reversed(range(1, N)):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                count += 1

                flag = 1
    print(*A)
    print(count)

N = int(input())
nums = list(map(int, input().split()))
bubbleSort(nums, N)
