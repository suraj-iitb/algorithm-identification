n=int(input())
nums=list(map(int,input().split()))

def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')

        else:
            print(nums[i])

def bubble_sort(nums,n):
    count=0
    flag=1
    while flag:
        flag=0
        for j in range(n-1,0,-1):
            
            if nums[j-1]>nums[j]:
                flag=1
                nums[j-1],nums[j]=nums[j],nums[j-1]
                count+=1
            

    return count,nums

count,nums=bubble_sort(nums,n)
show(nums)
print(count)
