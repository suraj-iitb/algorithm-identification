N=int(input())
A=list(map(int,input().split()))[::-1]
flag=1
count=0
while flag:
    flag=0
    for i in range(N-1):
        if A[i]<A[i+1]:
            A[i],A[i+1]=A[i+1],A[i]
            flag=1
            count+=1

print(*A[::-1])
print(count)
