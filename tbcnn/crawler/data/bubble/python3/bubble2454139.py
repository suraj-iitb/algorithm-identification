n=int(input())
nums=list(map(int,input().split()))

k=0
for i in range(len(nums)-1):
    for j in range(len(nums)-1,i,-1):
        if nums[j]<nums[j-1]:
            nums[j],nums[j-1]=nums[j-1],nums[j]
            k+=1

print(*nums)
print(k)
