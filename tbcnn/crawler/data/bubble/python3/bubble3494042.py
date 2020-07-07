def show(nums):
    for i in range(len(nums)):
        if i != len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])

N = int(input())
A = list(map(int,input().split()))

count = 0
flag = 1

for i in range(N):
    while flag:
        flag = 0
        for j in range(N-1,i,-1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                count += 1
                flag = 1

show(A)
print(count)

