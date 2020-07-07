def show(nums):
    print(' '.join(map(str, nums)))    


def selection_sort(nums, n):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if nums[j] < nums[minj]:
                minj = j
        v = nums[i]
        nums[i] = nums[minj]
        nums[minj] = v
        if i != minj:
            count += 1
    show(nums)
    print(count)

    
n = int(input())
nums = list(map(int, input().split()))
selection_sort(nums, n)
