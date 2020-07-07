# inputList = list(map(int, '''6
# 5 6 4 2 1 3'''.split()))
# N = inputList.pop(0)


def formatting(nums):
    for i in range(len(nums)):
        if i != len(nums) - 1:
            print(nums[i], end=' ')
        else:
            print(nums[i])


def selectionSort(A, N):
    count = 0
    for i in range(N - 1):
        minJ = i
        for j in range(i, N):
            if A[j] < A[minJ]:
                minJ = j

        if i != minJ:
            A[i], A[minJ] = A[minJ], A[i]
            count += 1

    formatting(A)
    print(count)



N = int(input())
inputList = list(map(int, input().split()))

selectionSort(inputList, N)

