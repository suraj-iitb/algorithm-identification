n = int(input())
nums=list(input().split())
    


def selectionSort(nums):
    count=0
    for i in range(len(nums)):
        minj=i
        for j in range(i,len(nums)):
            if int(nums[j])<int(nums[minj]):
                minj=j
        if i!=minj:          
            tmp=nums[minj]
            nums[minj]=nums[i]
            nums[i]=tmp
            count+=1
    print(' '.join(nums))
    print(count)


selectionSort(nums)

