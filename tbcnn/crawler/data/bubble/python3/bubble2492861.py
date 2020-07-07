#bubble
N=int(input())
A=[int(i) for i in input().split()]
fl=1
C=0
while fl==1:
    fl=0
    for j in range(N-1):
        if A[N-1-j]<A[N-2-j]:
            t=A[N-1-j]
            A[N-1-j]=A[N-2-j]
            A[N-2-j]=t
            C+=1
            fl=1
for j in range(N):
    A[j]=str(A[j])
print(" ".join(A))
print(C)
