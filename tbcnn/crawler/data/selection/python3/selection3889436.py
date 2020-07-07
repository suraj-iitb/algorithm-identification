num_counts = int(input())
nums = list(map(int, input().split()))
swap_counts = 0

for i in range(num_counts):
    mini = i
    for j in range(i, num_counts):
        if nums[j] < nums[mini]:
            mini = j
    if i == mini:
        continue
    nums[i], nums[mini] = nums[mini], nums[i]
    swap_counts += 1
    
for num in nums[:-1]:
    print(num, end=' ')
print(nums[-1])
print(swap_counts)
