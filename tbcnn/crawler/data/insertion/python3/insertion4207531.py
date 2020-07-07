N = int(input())

nums = list(map(int, input().split()))

for i in range(len(nums)):
    num = nums[i]
    j = i - 1
    while j >= 0 and nums[j] > num:
        nums[j + 1] = nums[j]
        j -= 1
    nums[j + 1] = num

    print(*nums)
