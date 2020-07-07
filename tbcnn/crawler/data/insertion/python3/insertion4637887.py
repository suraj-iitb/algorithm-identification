n = int(input())
nums = list(map(int, input().split()))

for idx1 in range(len(nums)):
    num  = nums[idx1]
    idx2 = idx1 - 1
    while idx2 >= 0 and nums[idx2] > num:
        nums[idx2 + 1] = nums[idx2]
        idx2 -= 1
    nums[idx2+1] = num
    print(" ".join(map(str, nums)))
