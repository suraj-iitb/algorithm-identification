N=int(input())
A=list(map(int,input().split()))


for i in range(1,N):
    v = A[i]
    j = i - 1
    for k in range(N-1):
        print(A[k], end=" ")
    print(A[N-1])
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j=j-1
    A[j+1] = v
for j in range(N-1):
    print(A[j], end=" ")
print(A[N-1])


