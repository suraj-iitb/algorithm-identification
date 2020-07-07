def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])
def bubbleSort(A,N):
    count = 0
    flag = True
    while flag:
        flag = False
        for i in range(1,N):
            if A[i-1] > A[i]:
                A[i-1],A[i]=A[i],A[i-1]
                count+=1
                flag = True
    show(A)
    print(count)
X = int(input())
Y = list(map(int,input().split()))
bubbleSort(Y,X)
