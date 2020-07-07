def BubbleSort(A):
    swapCount=0
    # sort
    for i in range(len(A)):
        for j in reversed(range(i+1,len(A))):
            if A[j] < A[j-1]:
                tmp=A[j]
                A[j]=A[j-1]
                A[j-1]=tmp
                swapCount+=1
    return swapCount
    

# input
n=int(input())
nums=list(map(int, input().split()))
count=BubbleSort(nums)
maplist=map(str, nums)
print(' '.join(maplist))
print(count)
