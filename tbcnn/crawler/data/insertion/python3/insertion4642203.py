n = int(input())
A = list(map(int,input().split()))

print(' '.join([str(i) for i in A]))
for i in range(1,n):
    j = i - 1
    while j>=0 and A[j+1]<A[j]:
        A[j],A[j+1] = A[j+1],A[j]
        j -= 1
    print(' '.join([str(i) for i in A]))
        
        
