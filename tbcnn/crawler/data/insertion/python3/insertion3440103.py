N = int(input())
nums = list(map(int, input().split()))

for i in range(N):
    if i!=N-1:
        print(nums[i],end=' ')
    else:
        print(nums[i])
    
for i in range(1,N):
    key = nums[i]
    j =i-1
    while j >= 0 and nums[j] > key:
        nums[j+1] = nums[j]
        j-=1
    nums[j+1] = key
    
    for i in range(N):
        if i!=N-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])
