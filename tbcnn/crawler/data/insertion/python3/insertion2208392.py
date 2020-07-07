num_cnt = int(input().rstrip())

nums = list(map(int, input().rstrip().split(" ")))

for i in range(num_cnt):
    tmpNum = nums[i]
    j = i -1 
    
    while j >=0:
        if nums[j] <= tmpNum:
            break
        nums[j+1] = nums[j]
        j = j-1
    nums[j+1] = tmpNum
    print (" ".join(map(str,nums)))
