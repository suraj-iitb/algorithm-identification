N=int(input())
A=[int(i) for i in input().split()]
C=0
for i in range(N):
    minj=i
    for j in range(i,N):
        if A[j]<A[minj]:
            minj=j
    if i!=minj:
        t=A[i]
        A[i]=A[minj]
        A[minj]=t
        C+=1
 #   print(minj)
for i in range(N):
    A[i]=str(A[i])
print(" ".join(A))
print(C)
