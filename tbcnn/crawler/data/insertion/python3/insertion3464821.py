N = int(input())
A = input().strip().split()
A = [int(i) for i in A]
for i in range(N):
    if i == N-1:
        print(A[i])
    else:
        print(A[i],end=' ')


for i in range(N-1):
    j = i
    while True:
        if j == -1:
            break
        if A[j]>A[j+1]:
            v = A[j]
            A[j] = A[j+1]
            A[j+1] = v
        j += -1
        
    for x in range(N):
        if x == N-1:
            print(A[x])
        else:
            print(A[x],end=' ')
