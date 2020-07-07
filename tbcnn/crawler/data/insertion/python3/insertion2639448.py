n = int(input())
line = input()
arr = line.split(" ")
nums = []
for c in range(n):
    nums.append(int(arr[c]))

def trace(n_list):
    n_list_str = ""
    for num in n_list:
        n_list_str += str(num)
        n_list_str += " "
    print(n_list_str.rstrip(" "))
            
print(line)
for i in range(1, n):
    v = nums[i]
    j = i-1
    while j >= 0 and nums[j] > v:
        nums[j+1] = nums[j]
        j -= 1
    nums[j+1] = v
    trace(nums)
