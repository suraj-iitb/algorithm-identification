n = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(n):
    minj = i
    for j in range(i, n):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        cnt += 1
    tmp = A[i]
    A[i] = A[minj]
    A[minj] = tmp
    
for k in range(n-1):
    print(A[k], end=' ')
print(A[n-1])
print(cnt)
    
