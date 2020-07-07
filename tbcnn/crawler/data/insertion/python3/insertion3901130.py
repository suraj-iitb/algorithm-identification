n = int(input())
nums = list(map(int, input().split()))
print(" ".join(list(map(str, nums))))
for i in range(1, n):
    for j in range(i):
        if nums[j] > nums[i]:
            nums.insert(j, nums.pop(i))
    print(" ".join(list(map(str, nums))))
