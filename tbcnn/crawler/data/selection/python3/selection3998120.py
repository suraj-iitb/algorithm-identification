N = int(input())
A = list(map(int,input().split()))
cnt = 0
for i in range(N-1):
    minj = i
    for j in range(i+1,N):
        if A[j] < A[minj]:
            minj = j
    if A[i] != A[minj]:
        cnt +=1
    temp = A[i]
    A[i] = A[minj]
    A[minj] = temp

print(*A)
print(cnt)
