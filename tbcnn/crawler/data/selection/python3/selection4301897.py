N=int(input())
A=[int(i) for i in input().split()]
count=0
for i in range(N):
    min=i
    for j in range(i,N):
        if A[j] < A[min]:
            min=j
    if i<min:
        count+=1
        A[i],A[min]=A[min],A[i]
for k in range(N):print(A[k],end=' \n'[k+1==N])
print(count)
