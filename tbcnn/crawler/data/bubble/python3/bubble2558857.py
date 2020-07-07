# coding:utf-8
n = int(input())
nums = [int(x) for x in input().split(" ")]
flag = True
count = 0
while flag:
    flag = False
    for i in range(n - 1, 0, -1):
        if nums[i] < nums[i - 1]:
            nums[i], nums[i - 1] = nums[i - 1], nums[i]
            flag = True
            count += 1
print(" ".join([str(i) for i in nums]))
print(count)
