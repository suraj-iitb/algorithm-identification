n=int(input())
A=list(map(int, input().split()))

def bubblesort(A,n):
    count=0
    flag=1
    while flag:
        flag=0
        for j in reversed(range(1,len(A))):
            if A[j]<A[j-1]:
                tmp=A[j-1]
                A[j-1]=A[j]
                A[j]=tmp
                flag=1
                count+=1
    return(A,count)

result,count=bubblesort(A,n)
print(" ".join([str(i) for i in result]))
print(count)

