N = int(input())
A = list(map(int,input().split()))

def show(nums):
    for i in range(len(nums)):
        if i != len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])
show(A)
for i in range(1,N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    show(A)
