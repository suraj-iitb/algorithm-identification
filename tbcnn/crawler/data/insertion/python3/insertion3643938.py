n=input()
N=int(n)
L=input().split()

A=[int(L[i]) for i in range(N)]

#for i in range(N):#入力をそのまま返す
#    if i<N-1:
#        print(A[i],end=" ")
#    else:
#        print(A[i])

for i in range(N):
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]#==になってた
        j=j-1
    A[j+1]=v

    for k in range(N):
        if k<N-1:
            print(A[k],end=" ")
        else:
            print(A[k])

