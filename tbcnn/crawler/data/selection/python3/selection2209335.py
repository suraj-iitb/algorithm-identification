data_num = int(input())
nums = list(map(int, input().split(" ")))
cnt = 0
for i in range(data_num):
    min_idx = i
    for j in range(i, data_num):
        if nums[j] < nums[min_idx]:
            min_idx = j

    if i != min_idx:
        nums[i], nums[min_idx] = nums[min_idx], nums[i]
        cnt += 1

print(" ".join(map(str,nums)) + "\n" + str(cnt))
