#疑似コード読み違えた
N=int(input())
L=input().split( )
A=[int(L[i]) for i in range(N)]
c=0
j=N-1
flag=1
while flag:
    flag=0
    for j in range(N-1):
        if A[j+1]<A[j]:
            temp=A[j]
            A[j]=A[j+1]
            A[j+1]=temp
            c+=1
            flag=1
for j in range(N):
    if j<N-1:
        print(A[j],end=" ")
    else:
        print(A[j])
print(c)

