def SelectionSort(A):
    swapCount=0
    # sort
    for i in range(len(A)):
        mini=i
        for j in range(i,len(A)):
            if A[j]<A[mini]:
                mini=j
        if mini!=i:
            tmp=A[i]
            A[i]=A[mini]
            A[mini]=tmp
            swapCount+=1
    return swapCount
    

# input
n=int(input())
nums=list(map(int, input().split()))
count=SelectionSort(nums)
maplist=map(str, nums)
print(' '.join(maplist))
print(count)
