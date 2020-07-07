N = int(input())
A = list(map(int,input().split()))
for k in range(N-1):
    print(f"{A[k]} ",end="")
print(f"{A[N-1]}")
for i in range(1,N):
    v = A[i]
    j = i-1
    while (j>=0)*(A[j]>v):
        A[j+1]=A[j]
        j-=1
        A[j+1]=v
    for k in range(N-1):
        print(f"{A[k]} ",end="")
    print(f"{A[N-1]}")
