data_num = int(input())
nums = list(map(int, input().split(" ")))
cnt = 0
for i in range(data_num):
    for j in range(data_num-1, i,-1):
        if nums[j]<nums[j-1]:
            nums[j], nums[j-1] = nums[j-1], nums[j]
            cnt = cnt + 1

print(" ".join(map(str,nums)) + "\n" + str(cnt))
