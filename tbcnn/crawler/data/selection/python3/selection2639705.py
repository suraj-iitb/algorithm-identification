n = int(input())
line = input()
arr= line.split(" ")
nums = []
for c in range(n):
    nums.append(int(arr[c]))

convert_n = 0
for i in range(len(nums)):
    minj = i
    for j in range(i, len(nums)):
        if nums[j] < nums[minj]:
            minj = j
    tmp = nums[i]
    nums[i] = nums[minj]
    nums[minj] = tmp
    if i != minj:
        convert_n += 1

n_list_str = ""
for num in nums:
    n_list_str += str(num)
    n_list_str += " "
print(n_list_str.rstrip(" "))
print(convert_n)
