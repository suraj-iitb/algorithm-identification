def BubbleSort1(A):
    ans=0
    for i in range(len(A)):
        for j in range(len(A)-1,i,-1):
            if A[j-1]>A[j]:
                A[j],A[j-1]=A[j-1],A[j]
                ans+=1
    
    return ans

    
cnt=int(input())
a=[int(x) for x in input().split()]


ans=BubbleSort1(a)

for i in range(len(a)):
    if i:
        print(" ",end="")
    print(a[i],end="")
print()
print(ans)
