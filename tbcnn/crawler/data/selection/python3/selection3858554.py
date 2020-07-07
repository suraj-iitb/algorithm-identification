N=int(input())
A=list(map(int,input().split()))
count=0
for i in range(N-1):
    minj=i
    for j in range(i+1,N):
        if A[minj]>A[j]:
            minj=j
    if i<minj:
        A[minj],A[i]=A[i],A[minj]
        count+=1
for i in range(N):
    if i<N-1:
        print(A[i],end=' ')
    else:
        print(A[i])
print(count)
