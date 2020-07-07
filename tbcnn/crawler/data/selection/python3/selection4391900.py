n=int(input())
nums=list(map(int,input().split()))
count=0
for i in range(n):
    
    minj=i
    minv=nums[minj:].index(min(nums[minj:]))+minj
    if minv!=minj:
        count+=1

    nums[minj],nums[minv]=nums[minv],nums[minj]
    

def show(nums):
    for j in range(len(nums)):
        if j!=len(nums)-1:
            print(nums[j],end=' ')

        else:
            print(nums[j])

show(nums)
print(count)
