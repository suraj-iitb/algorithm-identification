n=int(input())
A = list(map(int,input().split()))
sA=[str(i) for i in A]
pA = ' '.join(sA)
print(pA)
for i in range(1,n):
    v = A[i]
    j = i-1
    while (j>=0 and A[j]>v):
        A[j+1] = A[j]
        j =j-1
    A[j+1] = v
    #print(A)
    sA=[str(i) for i in A]
    pA = ' '.join(sA)
    print(pA)

