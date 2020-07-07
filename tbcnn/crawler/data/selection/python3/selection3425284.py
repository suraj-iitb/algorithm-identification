n = int(input())
nums = [int(num) for num in input().split(" ")]
result_string = ""
change_times = 0

for i in range(n):
    minj = i
    for j in range(i, n):
        if nums[j] < nums[minj]:
            minj = j
    if minj != i:
        tmp = nums[minj]
        nums[minj] = nums[i]
        nums[i] = tmp
        change_times += 1
    if result_string == "":
        result_string += str(nums[i])
    else:
        result_string += " "
        result_string += str(nums[i])
            
print(result_string)
print(change_times)
