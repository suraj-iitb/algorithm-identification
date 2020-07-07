#まともに挙動追うと相当大変だがちゃんとやる。
#特にループ、forのインデント
N=int(input())
L=input().split( )
A=[int(L[i]) for i in range(N)]
c=0
for i in range(N):
    minj=i
    j=i
    while j<N:
        if A[j]<A[minj]:
            minj=j
        j+=1
    temp=A[i]
    A[i]=A[minj]
    A[minj]=temp
    #print(A)
    #print(A[minj])
    if i!=minj:
        c+=1
for j in range(N):
    if j<N-1:
        print(A[j],end=" ")
    else:
        print(A[j])
print(c)

