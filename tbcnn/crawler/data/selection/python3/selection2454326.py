def selectionSort(nums,n):
    k=0
    for i in range(n):
        minj=i
        for j in range(i,n):
            if nums[j]<nums[minj]:
                minj=j
        if nums[i]!=nums[minj]:
            nums[i],nums[minj]=nums[minj],nums[i]
            #print(nums)
            k+=1
    return nums,k
    
n=int(input())
nums=list(map(int,input().split()))

nums,k=selectionSort(nums,n)
print(*nums)
print(k)
