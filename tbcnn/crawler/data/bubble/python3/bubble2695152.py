n = int(input())
nums=list(input().split())

def bubbleSort(nums,n):
    flag=True
    count=0
    while flag:
        flag=False
        for j in range(n-1,0,-1):
            if int(nums[j])<int(nums[j-1]):
                tmp=nums[j]
                nums[j]=nums[j-1]
                nums[j-1]=tmp
                flag=True
                count+=1

    print(' '.join(nums))
    print(count)

bubbleSort(nums,n)
