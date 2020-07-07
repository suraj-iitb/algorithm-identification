n = int(input())
A = input().split()

print(' '.join(A))
for i in range(1,n):
    for j in range(i,0,-1):
        if int(A[j]) < int(A[j-1]):
            A[j], A[j-1] = A[j-1], A[j]
    print(' '.join(A))

