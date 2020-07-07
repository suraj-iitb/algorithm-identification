n=int(input())
A=list(map(int,input().split()))
flag=1
count=0
while flag==1:
    flag=0
    for i in range(n-1,0,-1):
        if A[i]<A[i-1]:
            A[i],A[i-1]=A[i-1],A[i]
            flag=1
            count+=1
for i in range(n-1):
    print(A[i],end=" ")
print(A[n-1])
print(count)
