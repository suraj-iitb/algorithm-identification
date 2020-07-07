n = int(input())
nums = list(map(int, input().split()))

print(' '.join(map(str, nums)))
for i in range(1, n):
    v = nums[i]
    j = i - 1
    while j >= 0 and nums[j] > v:
        nums[j+1] = nums[j]
        j -= 1
    nums[j+1] = v
    print(' '.join(map(str, nums)))
