N = int(input())
*A, = map(int,input().split())
count = 0
for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if not minj == i:
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
        count += 1
    
print(*A)
print(count)
