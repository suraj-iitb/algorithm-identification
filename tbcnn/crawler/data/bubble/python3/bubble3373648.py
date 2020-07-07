def show (nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else :
            print(nums[i])

n = int(input())
A = list(map(int,input().split()))

flag = 1
counter = 0

while(flag):
    flag = 0
    for j in range(1,n)[::-1]:
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            flag = 1
            counter += 1

show(A)
print(counter)
