N = int(input())
nums = list(map(int, input().split()))

count = 0
flag = True
while flag:
    flag = False
    for j in [N-i for i in range(1, N)]:
        if nums[j] < nums[j-1]:
            nums[j], nums[j-1] = nums[j-1], nums[j]
            flag=True
            count += 1


nums = [str(num) for num in nums]
print(" ".join(nums))
print(count)

