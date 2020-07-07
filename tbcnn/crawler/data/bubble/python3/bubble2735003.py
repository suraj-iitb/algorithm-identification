n = input()
nums = input()
nums = nums.split()
nums = list(map(int, nums))

cnt = 0
for i in range(int(n)-1):
    for j in range(int(n)-1):
        if nums[j] > nums[j+1]:
            tmp = nums[j+1]
            nums[j+1] = nums[j]
            nums[j] = tmp
            cnt += 1

print(' '.join(map(str, nums)))
print(cnt)
