n = input()
nums = input()
nums = nums.split()
nums = list(map(int, nums))

cnt = 0
for i in range(int(n)):
    mink = i
    for v in range(i, int(n)):
        if nums[v] < nums[mink]:
            mink = v
    if mink != i:
        nums[i], nums[mink] = nums[mink], nums[i]
        cnt += 1

print(' '.join(map(str, nums)))
print(cnt)

