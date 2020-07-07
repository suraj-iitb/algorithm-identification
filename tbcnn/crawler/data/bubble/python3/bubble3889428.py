nums_count = int(input())
nums = list(map(int, input().split()))
swap_count = 0

for i in range(nums_count):
    for j in range(nums_count-1, i, -1):
        if nums[j-1] > nums[j]:
            nums[j-1], nums[j] = nums[j], nums[j-1]
            swap_count += 1

for num in nums[:-1]:
    print(num, end=' ')
print(nums[-1])

print(swap_count)
