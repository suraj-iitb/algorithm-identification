n = int(input())
line = input()
arr= line.split(" ")
nums = []
for c in range(n):
    nums.append(int(arr[c]))

flag = "true"
convert_n = 0
while flag == "true":
    flag = "false"
    for i in range(len(nums)-1, 0, -1):
        if nums[i] < nums[i-1]:
            tmp = nums[i]
            nums[i] = nums[i-1]
            nums[i-1] = tmp
            flag = "true"
            convert_n += 1
            
n_list_str = ""
for num in nums:
    n_list_str += str(num)
    n_list_str += " "
print(n_list_str.rstrip(" "))
print(convert_n)
