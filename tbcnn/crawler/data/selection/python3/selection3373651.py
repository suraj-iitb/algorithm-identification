def show (nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else :
            print(nums[i])

n = int(input())
A = list(map(int,input().split()))

counter = 0

for i in range(0,n):
    minj = i
    for j in range(i+1,n):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
        counter += 1

show(A)
print(counter)
