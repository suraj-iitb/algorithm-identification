# inputList = list(map(int, '''6
# 5 2 4 6 1 3'''.split()))
# N = inputList.pop(0)


def formatting(nums):
    for i in range(len(nums)):
        if i != len(nums) - 1:
            print(nums[i], end=' ')
        else:
            print(nums[i])


def insertionSort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]

            j-=1
        A[j+1] = v
        formatting(A)


N = int(input())
inputList = list(map(int, input().split()))

formatting(inputList)
insertionSort(inputList, N)

