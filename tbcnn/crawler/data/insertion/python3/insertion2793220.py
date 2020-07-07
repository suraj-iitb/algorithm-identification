def pr(A,n):
    for i in range(n):
        if i!=n-1:
            print(A[i],end=" ")
        else:
            print(A[i])

def insertionSort(A,N):
    for i in range(1,N):
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j-=1
        A[j+1]=v
        pr(A,n)

n=int(input())
A=input().split()
A=[int(i)for i in A]
pr(A,n)
insertionSort(A,n)

