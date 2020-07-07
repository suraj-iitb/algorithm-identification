n = int(input())
nums = list(map(int, input().split()))
count = 0
for i in range(n):
    mini = i
    for j in range(i, n):
        if nums[j] < nums[mini]:
            mini = j
    if mini != i:
        count += 1
        nums[i], nums[mini] = nums[mini], nums[i]
for i in range(n-1):
    print(nums[i], end = ' ')
print(nums[n-1])
print(count)        
