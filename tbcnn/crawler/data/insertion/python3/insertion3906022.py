def insertion_sort(A,N):
    for i in range(N):
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j=j-1
        A[j+1]=v
        print(*A,sep=" ")
N=int(input())
A=list(map(int,input().split()))

insertion_sort(A,N)

