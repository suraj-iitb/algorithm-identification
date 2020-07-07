def show (nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else :
            print(nums[i])

n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    for j in range(i):
        if a[j] > a[i]:
            a.insert(j, a[i])
            a.pop(i+1)
            break
    show(a)

