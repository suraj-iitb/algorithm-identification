n = input()
nums = input()
nums = nums.split()
nums = list(map(int, nums))
print(' '.join(map(str, nums)))

for idx in range(1, int(n)):
    v = nums[idx]
    j = idx - 1
    while j >= 0 and nums[j] > v:
        nums[j+1] = nums[j]
        j -= 1
    nums[j+1] = v
    print(' '.join(map(str, nums)))


