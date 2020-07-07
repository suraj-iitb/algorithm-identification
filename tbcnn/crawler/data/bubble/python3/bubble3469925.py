n = int(input())
nums = list(map(int, input().split()))
count = 0
for i in range(n):
    for j in range(n-1, i, -1):
        if nums[j] < nums[j-1]:
            count += 1
            nums[j], nums[j-1] = nums[j-1], nums[j]
for i in range(n-1):
    print(nums[i], end = ' ')
print(nums[n-1])
print(count)
