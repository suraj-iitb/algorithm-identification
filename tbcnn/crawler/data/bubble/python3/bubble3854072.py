def show(A):
    for i in range(N):
        if i<N-1:
            print(A[i],end=' ')
        else:
            print(A[i])

N=int(input())
A=list(map(int,input().split()))
count=0
flag=True
while flag:
    flag=False
    for j in reversed(range(1,N)):
        if A[j-1]>A[j]:
            A[j-1],A[j]=A[j],A[j-1]
            count+=1
            flag=True
show(A)
print(count)
