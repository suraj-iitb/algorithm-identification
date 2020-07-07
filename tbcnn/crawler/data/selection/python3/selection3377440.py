def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])
def selectionSort(A,N):
    count=0
    for i in range(N):
        minj = i
        for j in range(i+1,N):
            if A[j] < A[minj]:
                minj = j
        if A[i]>A[minj]:
            A[i],A[minj]=A[minj],A[i]
            count+=1
    show(A)
    print(count)
N = int(input())
A = list(map(int,input().split()))
selectionSort(A,N)
