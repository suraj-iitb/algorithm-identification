N=int(input())
A=list(map(int,input().split()))
# A = [int(i) for i in input().split()]
# for i in range(N):print(A[i],end='')
# print(end='\n')
for i in range(N):
    v=A[i]
    j=i-1
    while(j>=0 and A[j]>v):
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    for i in range(N):print(A[i],end=' \n'[i+1==N])
    # print(end='\n')
