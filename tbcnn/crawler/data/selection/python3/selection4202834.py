N = int(input()) 
A = list(map(int, input().split())) 
cnt = 0
for j in range(N-1):
    min_i = j
    for i in range(j, N):
        if A[i] < A[min_i]:
            min_i = i
    if A[j] > A[min_i]:
        v = A[j]
        A[j] = A[min_i]
        A[min_i] = v
        cnt += 1
print(*A)
print(cnt)
