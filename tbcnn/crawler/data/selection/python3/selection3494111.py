def show(nums):
    for i in range(len(nums)):
        if i != len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])

N = int(input())
A = list(map(int,input().split()))
count = 0

for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    tmp = A[i]
    A[i] = A[minj]
    A[minj] = tmp
    if i != minj:
        count += 1

show(A)
print(count)

