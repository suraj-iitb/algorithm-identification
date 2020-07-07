# inputList = list(map(int, '''5
# 5 3 2 4 1'''.split()))
# N = inputList.pop(0)


def formatting(nums):
    for i in range(len(nums)):
        if i != len(nums) - 1:
            print(nums[i], end=' ')
        else:
            print(nums[i])


def bubbleSort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0

        for j in range(N - 1, 0, -1):
            if A[j] < A[j-1]:
                temp = A[j]
                A[j] = A[j-1]
                A[j-1] = temp
                count += 1
                flag = 1
    formatting(A)
    print(count)




N = int(input())
inputList = list(map(int, input().split()))

bubbleSort(inputList, N)

