n = int(input())
nums = []
nums = input().split()
intNums = list(map(int,nums))

def insertationSort(nums,intNums):
    print(' '.join(nums))
    for i in range(1,len(nums)):
        v = intNums[i]
        j = i - 1
        while j>=0 and intNums[j]>v:
            intNums[j+1] = intNums[j]
            j = j - 1
        intNums[j+1] = v
        nums = list(map(str,intNums))
        print(' '.join(nums))

insertationSort(nums,intNums)
