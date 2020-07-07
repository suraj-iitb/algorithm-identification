n=int(input())
A=list(map(int, input().split()))

def selectsort(A,n):
    count=0
    for i in range(len(A)):
        minj=i
        flag=0
        for j in range(i,len(A)):
            if A[j]<A[minj]:
                minj=j
                flag=1
        if flag==1:
            tmp=A[minj]
            A[minj]=A[i]
            A[i]=tmp
            count+=1
    return(A,count)

result,count=selectsort(A,n)
print(" ".join([str(i) for i in result]))
print(count)

