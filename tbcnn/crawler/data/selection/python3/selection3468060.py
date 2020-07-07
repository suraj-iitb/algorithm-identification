N = int(input())
A = list(map(int,input().split()))
change_A = 0

for i in range(N):
    mini = i
    for j in range(i+1,N):
        if A[j] < A[mini]:
            mini = j
    
    if mini != i:
        v = A[i]
        A[i] = A[mini]
        A[mini] = v
        change_A += 1

for i in range(N):
    if i == N-1:
        print(A[i])
    else:
        print(A[i],end=' ')
        
print(change_A)
        
        
