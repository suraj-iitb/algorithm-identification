N = int(input()) 
A = list(map(int, input().split())) 
cnt = 0

for j in range(N): 
    for i in range(N-1,j,-1): 
        v = A[i] 
        if A[i-1] > A[i]: 
            A[i] = A[i-1] 
            A[i-1] = v 
            cnt += 1
        else:
            continue

print(*A)
print(cnt)
