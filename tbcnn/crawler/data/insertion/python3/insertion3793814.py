num = int(input())
num_list = input().split(" ")

nums = []

for n in num_list:
    nums.append(int(n))
    
for m in range(num):
    i = nums[m]
    j = m - 1
    while j >= 0 and nums[j] > i:
        nums[j+1] = nums[j]
        j -= 1
    nums[j+1] = i
    
    for n in range(num):
        if n == len(nums)-1:
            print(int(nums[n]), end = "")
            print("")
        else:
            print(int(nums[n]), end = " ")
