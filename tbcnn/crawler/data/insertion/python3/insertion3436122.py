def solution(count,nums):
    for i in range(count):
        objNum = nums[i]
        j = i - 1
        while j >= 0 and nums[j] > objNum:
            nums[j+1] = nums[j]
            j -= 1
        nums[j+1] = objNum
        print(' '.join(map(str,nums)))



count = int(input())
tmp = input().split(" ")
nums = []
for i in tmp:
    nums.append(int(i))
solution(count,nums)

