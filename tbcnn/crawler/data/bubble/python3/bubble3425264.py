n = int(input())
nums = [int(num) for num in input().split(" ")]
flag = 1
exchange_num = 0
result_string = ""        

while flag:
    flag = 0
    for j in range(n-1, 0, -1):
        if nums[j] < nums[j-1]:
            tmp = nums[j]
            nums[j] = nums[j-1]
            nums[j-1] = tmp
            flag = 1
            exchange_num += 1

for i in range(n):
    if result_string == "":
        result_string += str(nums[i])
    else:
        result_string += " "
        result_string += str(nums[i])

print(result_string)
print(exchange_num)
