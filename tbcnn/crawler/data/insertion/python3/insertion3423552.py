import sys

n = int(input())
nums = [int(num) for num in input().split(" ")]

if n == 1:
    print(nums[0])
else:
    for i in range(0, n):
        v = nums[i]
        j = i - 1
        while j >= 0 and v < nums[j]:
            nums[j+1] = nums[j]
            j -= 1
        nums[j+1] = v

        result = ""
        for k in range(0, n - 1):
            result += str(nums[k])
            result += " "
        result += str(nums[n - 1])
        print(result)
