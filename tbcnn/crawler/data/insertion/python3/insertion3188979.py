N= int(input())
nums= list(map(int,input().split(" ")))
for x in range(N):
        if(x!=N-1):
            print(nums[x],end=" ")
        else:
            print(nums[x])
for i in range(1,N):
    a= nums[i]
    j=i-1
    while nums[j]>a and j>=0:
        nums[j+1]=nums[j]
        j-=1
    nums[j+1]=a
    for x in range(N):
        if(x!=N-1):
            print(nums[x],end=" ")
        else:
            print(nums[x])
        
        

