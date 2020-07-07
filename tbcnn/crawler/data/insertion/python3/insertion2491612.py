# your code goes here
N=int(input())
A=[int(i) for i in input().split()]
B=""
for k in range(N-1):
    B+=str(A[k])+" "
B+=str(A[N-1])
print(B)
for i in range(1,N):
    j=i-1
    v=A[i]
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    B=""
    for k in range(N-1):
        B+=str(A[k])+" "
    B+=str(A[N-1])
    print(B)
