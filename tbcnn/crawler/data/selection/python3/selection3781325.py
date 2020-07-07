n = int(input())
nums = list(map(int, input().split()))

count = 0
for i in range(n):
    min_j = i
    for j in range(i, n):
        if nums[j] < nums[min_j]:
            min_j = j
    if min_j != i:
        nums[i], nums[min_j] = nums[min_j], nums[i]
        count += 1

print(' '.join(map(str, nums)))
print(count)

