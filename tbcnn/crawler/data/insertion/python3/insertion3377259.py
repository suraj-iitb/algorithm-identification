def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])
N = int(input())
A = list(map(int,input().split()))
show(A)
for i in range(1,N):
    v = A[i]
    while i - 1 >= 0 and A[i-1] > v:
        A[i] = A[i-1]
        i -= 1
    A[i] = v
    show(A)
