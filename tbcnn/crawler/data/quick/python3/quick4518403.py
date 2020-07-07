n=int(input())
nums=[input().split() for i in range(n)]
for j in range(n):
    nums[j][1]=int(nums[j][1])
    nums[j].append(int(j))


def quick_sort(nums,p,r):
    if p<r:
        q=partition(nums,p,r)
        quick_sort(nums,p,q-1)
        quick_sort(nums,q+1,r)

def partition(nums,p,r):
    i=p-1
    x=nums[r][1]
    for j in range(p,r):
        if nums[j][1]<=x:
            i+=1
            nums[i],nums[j]=nums[j],nums[i]
    nums[r],nums[i+1]=nums[i+1],nums[r]
    return i+1

quick_sort(nums,0,n-1)

key=1

for i in range(n):
    if i!=n-1:
        if nums[i][1]==nums[i+1][1]:
            if nums[i][2]>nums[i+1][2]:
                key=0

if key:
    print("Stable")

else:
    print("Not stable")

for i in range(n):
    print(nums[i][0],nums[i][1])


